/**
 * @file    uart.c
 * @author  Deadline039
 * @brief   STM32F103 单串口驱动
 * @version 1.3
 * @date    2023-09-14
 */

#include "bsp_uart.h"
#include "core_delay.h"

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#if (UARTx_USE_DMA_TX == 1)
extern void uart_dmatx_init(void);
extern void uart_dmatx_clear_tc_flag(void);
#endif /* UARTx_USE_DMA_TX == 1 */

#if (UARTx_USE_DMA_RX == 1)
extern void uart_dmarx_init(void);
extern void uart_dmarx_idle_callback(void);
extern void uart_dmarx_halfdone_callback(void);
extern void uart_dmarx_done_callback(void);
#endif /* UARTx_USE_DMA_RX == 1 */

UART_HandleTypeDef uart_handle;
static char uart_buffer[256];

/**
 * @brief 串口初始化
 *
 */
void uart_init(void) {
    HAL_StatusTypeDef res;

    uart_handle.Instance = UARTx;

    uart_handle.Init.BaudRate = UARTx_BAND_RATE;
    uart_handle.Init.HwFlowCtl = UARTx_HWCONTROL;
    uart_handle.Init.Mode = UART_MODE_TX_RX;
    uart_handle.Init.OverSampling = UART_OVERSAMPLING_16;
    uart_handle.Init.Parity = UART_PARITY_NONE;
    uart_handle.Init.StopBits = UART_STOPBITS_1;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    res = HAL_UART_Init(&uart_handle);

#ifdef DEBUG
    assert(res == HAL_OK);
#endif /* DEBUG */

#if (UARTx_USE_DMA_TX == 1)
    uart_dmatx_init();
#endif /* UARTx_USE_DMA_TX == 1 */

#if (UARTx_USE_DMA_RX == 1)
    uart_dmarx_init();
#endif /* UART_USE_DMA_RX == 1 */
}

/**
 * @brief 串口底层初始化
 *
 * @param huart 串口句柄
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
    GPIO_InitTypeDef gpio_init_struct;
    gpio_init_struct.Pull = GPIO_PULLUP;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    gpio_init_struct.Mode = GPIO_MODE_AF_PP;

    if (huart->Instance == UARTx) {
        UARTx_CLK_ENABLE();
        gpio_init_struct.Alternate = UARTx_GPIO_AF;

        if (huart->Init.Mode & UART_MODE_TX) {
            UARTx_TX_GPIO_ENABLE();
            gpio_init_struct.Pin = UARTx_TX_GPIO_PIN;
            HAL_GPIO_Init(UARTx_TX_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.Mode & UART_MODE_RX) {
            UARTx_RX_GPIO_ENABLE();
            gpio_init_struct.Pin = UARTx_RX_GPIO_PIN;
            HAL_GPIO_Init(UARTx_RX_GPIO_PORT, &gpio_init_struct);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_RTS) {
            UARTx_RTS_GPIO_ENABLE();
            gpio_init_struct.Pin = UARTx_RTS_GPIO_PIN;
            HAL_GPIO_Init(UARTx_RTS_GPIO_PORT, &gpio_init_struct);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_CTS) {
            UARTx_CTS_GPIO_ENABLE();
            gpio_init_struct.Pin = UARTx_CTS_GPIO_PIN;
            HAL_GPIO_Init(UARTx_CTS_GPIO_PORT, &gpio_init_struct);
        }
        HAL_NVIC_SetPriority(UARTx_IRQn, UARTx_IT_PREEMPT, UARTx_IT_SUB);
        HAL_NVIC_EnableIRQ(UARTx_IRQn);
    }
}

/**
 * @brief 串口中断服务函数
 *
 */
void UARTx_IRQHandler(void) {
#if (UARTx_USE_IDLE_IT == 1)
    if (__HAL_UART_GET_FLAG(&uart_handle, UART_FLAG_IDLE)) {
        __HAL_UART_CLEAR_IDLEFLAG(&uart_handle);
        uart_dmarx_idle_callback();
    }
#endif /* UARTx_USE_IDLE_IT == 1 */

    HAL_UART_IRQHandler(&uart_handle);
}

/**
 * @brief 串口格式化输出
 *
 * @param huart 串口句柄
 * @param __format 格式字符串
 * @return 成功填充的变量个数
 */
int uart_printf(UART_HandleTypeDef *huart, const char *__format, ...) {
    int res;
    uint16_t len;
    va_list ap;

    if (huart->Instance != UARTx) {
        return 0;
    }

    while (__HAL_UART_GET_FLAG(huart, UART_FLAG_TC) == RESET) {
        /* 等待发送完毕 */
        delay_ms(1);
    }

    va_start(ap, __format);
    res = vsnprintf(uart_buffer, sizeof(uart_buffer), __format, ap);
    va_end(ap);

    len = strlen(uart_buffer);

    if (huart->hdmatx == NULL) {
        HAL_UART_Transmit(huart, (uint8_t *)uart_buffer, len, 1000);
    } else {
        HAL_UART_Transmit_DMA(huart, (uint8_t *)uart_buffer, len);
    }
 
    return res;
}

/**
 * @brief 等待串口接收到数据并填充
 *
 * @param huart 串口句柄
 * @param __format 格式字符串
 * @return 成功填充的变量个数
 */
int uart_scanf(UART_HandleTypeDef *huart, const char *__format, ...) {
    uint16_t str_len = 0;
    int res;
    va_list ap;

    if (huart->Instance != UARTx) {
        return 0;
    }

#if (UARTx_USE_DMA_RX == 1)
    while (str_len == 0) {
        str_len = uart_dmarx_read(huart, uart_buffer, sizeof(uart_buffer));
        delay_ms(1);
    }
#else  /* UARTx_USE_DMA_RX == 1 */
    HAL_UARTEx_ReceiveToIdle(huart, (uint8_t *)uart_buffer, sizeof(uart_buffer),
                             &str_len, 0xFFFF);
#endif /* UARTx_USE_DMA_RX == 1 */

    va_start(ap, __format);
    res = vsscanf((char *)uart_buffer, __format, ap);
    va_end(ap);

    return res;
}

#if (UARTx_USE_DMA_TX == 1)

/**
 * @brief 串口发送完成回调
 *
 * @param huart 串口句柄
 */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
    if ((huart->Instance == UARTx) && (huart->hdmatx != NULL)) {
        uart_dmatx_clear_tc_flag();
    }
}

#endif /* UARTx_USE_DMA_TX == 1 */

#if (UARTx_USE_DMA_RX == 1)

/**
 * @brief 串口接收完成回调
 *
 * @param huart 串口句柄
 * @note 如果要多个串口使用接收回调, 强烈建议使用函数指针回调
 *       否则该函数结构会变得非常复杂
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if ((huart->Instance == UARTx) && (huart->hdmarx != NULL)) {
        uart_dmarx_done_callback();
    }
}

/**
 * @brief 串口接收半满回调
 *
 * @param huart 串口句柄
 */
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart) {
    if ((huart->Instance == UARTx) && (huart->hdmarx != NULL)) {
        uart_dmarx_halfdone_callback();
    }
}

#endif /* UARTx_USE_DMA_RX == 1 */