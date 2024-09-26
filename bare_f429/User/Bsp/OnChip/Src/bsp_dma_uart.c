/**
 * @file    dma_uart.c
 * @author  Deadline039
 * @brief   使用DMA+半满中断+满中断+空闲中断实现高可靠串口数据收发
 * @version 1.1
 * @date    2024-01-18
 * @note    stm32f103串口DMA配置文件
 * @ref     https://github.com/Prry/stm32-uart-dma
 *          https://gitee.com/wei513723/stm32-stable-uart-transmit-receive
 */

#include "bsp_core.h"
#include "bsp_uart.h"
#include "ring_fifo.h"

#include <string.h>

/*****************************************************************************
 * @defgroup 发送函数部分
 * @{
 */
#if (UARTx_USE_DMA_TX == 1)

/**
 * @brief 串口发送缓冲区
 */
static struct {
    uint8_t *send_buf;     /*!< 发送数据缓冲区 */
    uint32_t head_ptr;     /*!< 位置指针, 用来控制DMA传输的长度 */
    size_t send_buf_size;  /*!< 缓冲区大小, 避免溢出 */
    __IO uint32_t tc_flag; /*!< 是否发送完成, 0-未完成; 1-完成 */
} uart_tx_buf;

static DMA_HandleTypeDef uart_dmatx_handle;

/**
 * @brief 串口DMA发送初始化
 *
 */
void uart_dmatx_init(void) {
    HAL_StatusTypeDef res;

    uart_dmatx_handle.Instance = UARTx_DMA_TX_STREAM;
    uart_dmatx_handle.Init.Channel = UARTx_DMA_TX_CHANNEL;
    uart_dmatx_handle.Init.Direction = DMA_MEMORY_TO_PERIPH;
    uart_dmatx_handle.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    uart_dmatx_handle.Init.MemInc = DMA_MINC_ENABLE;
    uart_dmatx_handle.Init.Mode = DMA_NORMAL;
    uart_dmatx_handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    uart_dmatx_handle.Init.PeriphInc = DMA_PINC_DISABLE;
    uart_dmatx_handle.Init.Priority = UARTx_DMA_TX_PRIORITY;

    uart_tx_buf.send_buf =
        (uint8_t *)malloc(sizeof(uint8_t) * UARTx_TX_BUF_SIZE);
    uart_tx_buf.send_buf_size = UARTx_TX_BUF_SIZE;

#ifdef DEBUG
    assert(uart_tx_buf.send_buf != NULL);
#endif /* DEBUG */

    uart_tx_buf.tc_flag = 1;

    UARTx_DMA_TX_CLK_ENABLE();
    res = HAL_DMA_Init(&uart_dmatx_handle);
#ifdef DEBUG
    assert(res == HAL_OK);
#endif /* DEBUG */

    __HAL_LINKDMA(&uart_handle, hdmatx, uart_dmatx_handle);

    HAL_NVIC_SetPriority(UARTx_DMA_TX_IRQn, UARTx_DMA_TX_IT_PREEMPT,
                         UARTx_DMA_TX_IT_SUB);
    HAL_NVIC_EnableIRQ(UARTx_DMA_TX_IRQn);
}

/**
 * @brief 串口DMA发送中断服务函数
 *
 */
void UARTx_DMA_TX_IRQHandler(void) {
    HAL_DMA_IRQHandler(&uart_dmatx_handle);
}

/**
 * @brief 串口DMA发送完成清除标志位
 *
 */
void uart_dmatx_clear_tc_flag(void) {
    uart_tx_buf.tc_flag = 1;
}

/**
 * @brief 向串口发送缓冲区中写入数据
 *
 * @param huart 串口句柄
 * @param data 数据
 * @param len 数据长度
 * @return 成功写入的长度
 */
uint32_t uart_dmatx_write(UART_HandleTypeDef *huart, const void *data,
                          size_t len) {
    if (huart->Instance != UARTx) {
        return 0;
    }

    if ((data == NULL) || (len == 0)) {
        return 0;
    }

    /* 计算当前缓冲区剩余长度 */
    uint32_t buf_remain = uart_tx_buf.send_buf_size - uart_tx_buf.head_ptr;

    /* 如果要写入的长度大于剩余长度, 为避免溢出, 只写入剩余的长度 */
    if (buf_remain < len) {
        memcpy(uart_tx_buf.send_buf + uart_tx_buf.head_ptr, data, buf_remain);
        uart_tx_buf.head_ptr += buf_remain;
        return buf_remain;
    } else {
        memcpy(uart_tx_buf.send_buf + uart_tx_buf.head_ptr, data, len);
        uart_tx_buf.head_ptr += len;
        return len;
    }
}

/**
 * @brief 把FIFO中的数据通过DMA发送
 *
 * @param huart 串口句柄
 * @return 成功发送的长度
 * @note 先使用`uart_dmatx_write`写入数据
 */
uint32_t uart_dmatx_send(UART_HandleTypeDef *huart) {
    if (huart->Instance != UARTx) {
        return 0;
    }

    /* 未发送完毕 */
    if (!uart_tx_buf.tc_flag) {
        return 0;
    }

    uint32_t len = uart_tx_buf.head_ptr;
    /* 缓冲区为空 */
    if (!len) {
        return 0;
    }

    uart_tx_buf.tc_flag = 0;
    HAL_UART_Transmit_DMA(&uart_handle, uart_tx_buf.send_buf, (uint16_t)len);
    uart_tx_buf.head_ptr = 0;
    return len;
}

#endif /* UART_USE_DMA_TX == 1 */

/**
 * @}
 */

/*****************************************************************************
 * @defgroup 接收函数部分
 * @{
 */

#if (UARTx_USE_DMA_RX == 1)

/**
 * @brief 串口接收缓冲区
 *
 */
static struct {
    ring_fifo_t *rx_fifo; /*!< 接收FIFO */
    uint8_t *rx_fifo_buf; /*!< FIFO数据存储区 */
    uint8_t *recv_buf;    /*!< DMA接收数据缓冲区 */
    uintptr_t head_ptr;   /*!< 位置指针, 用来控制半满和溢出 */
} uart_rx_fifo;

static DMA_HandleTypeDef uart_dmarx_handle;

/**
 * @brief 串口DMA接收初始化
 *
 */
void uart_dmarx_init(void) {
    HAL_StatusTypeDef res = HAL_OK;

    uart_dmarx_handle.Instance = UARTx_DMA_RX_STREAM;
    uart_dmarx_handle.Init.Channel = UARTx_DMA_RX_CHANNEL;
    uart_dmarx_handle.Init.Direction = DMA_PERIPH_TO_MEMORY;
    uart_dmarx_handle.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    uart_dmarx_handle.Init.MemInc = DMA_MINC_ENABLE;
    uart_dmarx_handle.Init.Mode = DMA_CIRCULAR;
    uart_dmarx_handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    uart_dmarx_handle.Init.PeriphInc = DMA_PINC_DISABLE;
    uart_dmarx_handle.Init.Priority = UARTx_DMA_RX_PRIORITY;

    uart_rx_fifo.head_ptr = 0;
    uart_rx_fifo.recv_buf =
        (uint8_t *)malloc(sizeof(uint8_t) * UARTx_RX_BUF_SIZE);
#ifdef DEBUG
    assert(uart_rx_fifo.recv_buf != NULL);
#endif /* DEBUG */

    uart_rx_fifo.rx_fifo_buf =
        (uint8_t *)malloc(sizeof(uint8_t) * UARTx_RX_FIFO_SZIE);
#ifdef DEBUG
    assert(uart_rx_fifo.rx_fifo_buf != NULL);
#endif /* DEBUG */

    uart_rx_fifo.rx_fifo = ring_fifo_init(uart_rx_fifo.rx_fifo_buf,
                                          UARTx_RX_FIFO_SZIE, RF_TYPE_STREAM);

#ifdef DEBUG
    assert(uart_rx_fifo.rx_fifo != NULL);
#endif /* DEBUG */

    UARTx_DMA_RX_CLK_ENABLE();
    res = HAL_DMA_Init(&uart_dmarx_handle);
#ifdef DEBUG
    assert(res == HAL_OK);
#endif /* DEBUG */

    __HAL_LINKDMA(&uart_handle, hdmarx, uart_dmarx_handle);

    HAL_NVIC_SetPriority(UARTx_DMA_RX_IRQn, UARTx_DMA_RX_IT_PREEMPT,
                         UARTx_DMA_RX_IT_SUB);
    HAL_NVIC_EnableIRQ(UARTx_DMA_RX_IRQn);

#if (UARTx_USE_IDLE_IT == 1)
    __HAL_UART_ENABLE_IT(&uart_handle, UART_IT_IDLE);
    __HAL_UART_CLEAR_IDLEFLAG(&uart_handle);
#endif /* UARTx_USE_IDLE_IT == 1 */
    HAL_UART_Receive_DMA(&uart_handle, uart_rx_fifo.recv_buf,
                         UARTx_RX_BUF_SIZE);
}

/**
 * @brief 串口DMA接收中断服务函数
 *
 */
void UARTx_DMA_RX_IRQHandler(void) {
    HAL_DMA_IRQHandler(&uart_dmarx_handle);
}

/**
 * @brief 串口接收空闲中断回调
 *
 */
void uart_dmarx_idle_callback(void) {
    uint32_t tail_ptr;
    uint32_t copy, offset;

    /**
     * +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
     * |     head_ptr          tail_ptr         |
     * |         |                 |            |
     * |         v                 v            |
     * | --------*******************----------- |
     * +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
     */

    /* 已接收 */
    tail_ptr =
        uart_handle.RxXferSize - __HAL_DMA_GET_COUNTER(uart_handle.hdmarx);

    offset = (uart_rx_fifo.head_ptr) % (uint32_t)(uart_handle.RxXferSize);
    copy = tail_ptr - offset;
    uart_rx_fifo.head_ptr += copy;

    ring_fifo_write(uart_rx_fifo.rx_fifo, uart_handle.pRxBuffPtr + offset,
                    copy);
}

/**
 * @brief 串口接收半满中断回调
 *
 */
void uart_dmarx_halfdone_callback(void) {
    uint32_t tail_ptr;
    uint32_t offset, copy;

    /**
     * +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
     * |                  half                  |
     * |     head_ptr   tail_ptr                |
     * |         |          |                   |
     * |         v          v                   |
     * | --------*******************----------- |
     * +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
     */

    tail_ptr = (uart_handle.RxXferSize >> 1) + (uart_handle.RxXferSize & 1);

    offset = (uart_rx_fifo.head_ptr) % (uint32_t)(uart_handle.RxXferSize);
    copy = tail_ptr - offset;
    uart_rx_fifo.head_ptr += copy;

    ring_fifo_write(uart_rx_fifo.rx_fifo, uart_handle.pRxBuffPtr + offset,
                    copy);
}

/**
 * @brief 串口接收溢满中断回调
 *
 */
void uart_dmarx_done_callback(void) {
    uint32_t tail_ptr;
    uint32_t offset, copy;

    /**
     * +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
     * |                  half                  |
     * |                    | head_ptr tail_ptr |
     * |                    |    |            | |
     * |                    v    v            v |
     * | ------------------------************** |
     * +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
     */

    tail_ptr = uart_handle.RxXferSize;

    offset = (uart_rx_fifo.head_ptr) % (uint32_t)(uart_handle.RxXferSize);
    copy = tail_ptr - offset;
    uart_rx_fifo.head_ptr += copy;

    ring_fifo_write(uart_rx_fifo.rx_fifo, uart_handle.pRxBuffPtr + offset,
                    copy);
}

/**
 * @brief 从接收fifo中读取数据
 *
 * @param huart 串口句柄
 * @param buf 接收数据缓冲区
 * @param buf_size 缓冲区长度
 * @return 缓冲区剩余长度
 */
uint32_t uart_dmarx_read(UART_HandleTypeDef *huart, void *buf,
                         size_t buf_size) {
    if (huart->Instance != UARTx) {
        return 0;
    }

    return ring_fifo_read(uart_rx_fifo.rx_fifo, buf, buf_size);
}

#endif /* UARTx_USE_DMA_RX == 1 */

/**
 * @}
 */
