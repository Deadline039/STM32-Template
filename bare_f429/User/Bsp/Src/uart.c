/**
 * @file    uart.c
 * @author  Deadline039
 * @brief   STM32F429 串口驱动
 * @version 1.2
 * @date    2023-09-14
 */

#include "uart.h"
#include "bsp.h"

#include <stdarg.h>
#include <string.h>

/* uart_printf函数缓冲区 */
static char print_buffer[256];

extern void uart_dmatx_init(UART_HandleTypeDef *huart);
extern void uart_dmatx_clear_tc_flag(UART_HandleTypeDef *huart);

extern void uart_dmarx_init(UART_HandleTypeDef *huart);
extern void uart_dmarx_idle_callback(UART_HandleTypeDef *huart);
extern void uart_dmarx_halfdone_callback(UART_HandleTypeDef *huart);
extern void uart_dmarx_done_callback(UART_HandleTypeDef *huart);

#if (USART1_ENABLE == 1)
UART_HandleTypeDef usart1_handle = {.Instance = USART1};

/**
 * @brief 串口1中断服务函数
 */
void USART1_IRQHandler(void) {

#if (USART1_USE_IDLE_IT == 1)
    if (__HAL_UART_GET_FLAG(&usart1_handle, UART_FLAG_IDLE)) {
        __HAL_UART_CLEAR_IDLEFLAG(&usart1_handle);
        uart_dmarx_idle_callback(&usart1_handle);
    }
#endif /* USART1_USE_IDLE_IT == 1 */

    HAL_UART_IRQHandler(&usart1_handle); /* 调用HAL库中断处理公用函数 */
}

#endif /* USART1_ENABLE == 1 */

#if (USART2_ENABLE == 1)
UART_HandleTypeDef usart2_handle = {.Instance = USART2};

/**
 * @brief 串口2中断服务函数
 */
void USART2_IRQHandler(void) {

#if (USART2_USE_IDLE_IT == 1)
    if (__HAL_UART_GET_FLAG(&usart2_handle, UART_FLAG_IDLE)) {
        __HAL_UART_CLEAR_IDLEFLAG(&usart2_handle);
        uart_dmarx_idle_callback(&usart2_handle);
    }
#endif /* USART2_USE_IDLE_IT == 1 */

    HAL_UART_IRQHandler(&usart2_handle); /* 调用HAL库中断处理公用函数 */
}

#endif /* USART2_ENABLE == 1 */

#if (USART3_ENABLE == 1)
UART_HandleTypeDef usart3_handle = {.Instance = USART3};

/**
 * @brief 串口3中断服务函数
 */
void USART3_IRQHandler(void) {

#if (USART3_USE_IDLE_IT == 1)
    if (__HAL_UART_GET_FLAG(&usart3_handle, UART_FLAG_IDLE)) {
        __HAL_UART_CLEAR_IDLEFLAG(&usart3_handle);
        uart_dmarx_idle_callback(&usart3_handle);
    }
#endif /* USART3_USE_IDLE_IT == 1 */

    HAL_UART_IRQHandler(&usart3_handle); /* 调用HAL库中断处理公用函数 */
}

#endif /* USART3_ENABLE == 1 */

#if (UART4_ENABLE == 1)
UART_HandleTypeDef uart4_handle = {.Instance = UART4};

/**
 * @brief 串口4中断服务函数
 */
void UART4_IRQHandler(void) {

#if (UART4_USE_IDLE_IT == 1)
    if (__HAL_UART_GET_FLAG(&uart4_handle, UART_FLAG_IDLE)) {
        __HAL_UART_CLEAR_IDLEFLAG(&uart4_handle);
        uart_dmarx_idle_callback(&uart4_handle);
    }
#endif /* UART4_USE_IDLE_IT == 1 */

    HAL_UART_IRQHandler(&uart4_handle); /* 调用HAL库中断处理公用函数 */
}

#endif /* UART4_ENABLE == 1 */

#if (UART5_ENABLE == 1)
UART_HandleTypeDef uart5_handle = {.Instance = UART5};

/**
 * @brief 串口5中断服务函数
 */
void UART5_IRQHandler(void) {

#if (UART5_USE_IDLE_IT == 1)
    if (__HAL_UART_GET_FLAG(&uart5_handle, UART_FLAG_IDLE)) {
        __HAL_UART_CLEAR_IDLEFLAG(&uart5_handle);
        uart_dmarx_idle_callback(&uart5_handle);
    }
#endif /* UART5_USE_IDLE_IT == 1 */

    HAL_UART_IRQHandler(&uart5_handle); /* 调用HAL库中断处理公用函数 */
}

#endif /* UART5_ENABLE == 1 */

#if (USART6_ENABLE == 1)
UART_HandleTypeDef usart6_handle = {.Instance = USART6};

/**
 * @brief 串口6中断服务函数
 */
void USART6_IRQHandler(void) {

#if (USART6_USE_IDLE_IT == 1)
    if (__HAL_UART_GET_FLAG(&usart6_handle, UART_FLAG_IDLE)) {
        __HAL_UART_CLEAR_IDLEFLAG(&usart6_handle);
        uart_dmarx_idle_callback(&usart6_handle);
    }
#endif /* USART6_USE_IDLE_IT == 1 */

    HAL_UART_IRQHandler(&usart6_handle); /* 调用HAL库中断处理公用函数 */
}

#endif /* USART6_ENABLE == 1 */

#if (UART7_ENABLE == 1)
UART_HandleTypeDef uart7_handle = {.Instance = UART7};

/**
 * @brief 串口7中断服务函数
 */
void UART7_IRQHandler(void) {

#if (UART7_USE_IDLE_IT == 1)
    if (__HAL_UART_GET_FLAG(&uart7_handle, UART_FLAG_IDLE)) {
        __HAL_UART_CLEAR_IDLEFLAG(&uart7_handle);
        uart_dmarx_idle_callback(&uart7_handle);
    }
#endif /* UART7_USE_IDLE_IT == 1 */

    HAL_UART_IRQHandler(&uart7_handle); /* 调用HAL库中断处理公用函数 */
}

#endif /* UART7_ENABLE == 1 */

#if (UART8_ENABLE == 1)
UART_HandleTypeDef uart8_handle = {.Instance = UART8};

/**
 * @brief 串口8中断服务函数
 */
void UART8_IRQHandler(void) {

#if (UART8_USE_IDLE_IT == 1)
    if (__HAL_UART_GET_FLAG(&uart8_handle, UART_FLAG_IDLE)) {
        __HAL_UART_CLEAR_IDLEFLAG(&uart8_handle);
        uart_dmarx_idle_callback(&uart8_handle);
    }
#endif /* UART8_USE_IDLE_IT == 1 */

    HAL_UART_IRQHandler(&uart8_handle); /* 调用HAL库中断处理公用函数 */
}

#endif /* UART8_ENABLE == 1 */

/**
 * @brief 串口初始化
 *
 * @param huart 串口句柄
 * @param baud_rate 波特率
 * @param word_length 字长
 *  @arg `UART_WORDLENGTH_8B` 8bit
 *  @arg `UART_WORDLENGTH_9B` 9bit
 * @param stop_bits 停止位
 *  @arg `UART_STOPBITS_1` 1停止位
 *  @arg `UART_STOPBITS_2` 2停止位
 * @param parity 校验位
 *  @arg `UART_PARITY_NONE` 无校验
 *  @arg `UART_PARITY_EVEN` 偶校验
 *  @arg `UART_PARITY_ODD` 奇校验
 * @param hw_flow_ctrl 硬件流控
 *  @arg `UART_HWCONTROL_NONE` 无硬件流控
 *  @arg `UART_HWCONTROL_RTS` 使用RTS
 *  @arg `UART_HWCONTROL_CTS` 使用CTS
 *  @arg `UART_HWCONTROL_RTS_CTS` 使用RTS和CTS
 * @param mode 串口模式
 *  @arg `UART_MODE_TX_RX` 启用发送和接收
 *  @arg `UART_MODE_TX` 只启用发送
 *  @arg `UART_MODE_RX` 只启用接收
 */
void uart_init(UART_HandleTypeDef *huart, uint32_t baud_rate,
               uint32_t word_length, uint32_t stop_bits, uint32_t parity,
               uint32_t hw_flow_ctrl, uint32_t mode) {
    HAL_StatusTypeDef res = HAL_OK;

    huart->Init.BaudRate = baud_rate;
    huart->Init.WordLength = word_length;
    huart->Init.StopBits = stop_bits;
    huart->Init.Parity = parity;
    huart->Init.HwFlowCtl = hw_flow_ctrl;
    huart->Init.Mode = mode;

    res = HAL_UART_Init(huart);
#ifdef DEBUG
    assert(res == HAL_OK);
#endif /* DEBUG */

    /* 如果没有打开宏, 将直接返回 */
    uart_dmatx_init(huart);
    uart_dmarx_init(huart);
}

/**
 * @brief 串口底层初始化
 *
 * @param huart 串口句柄
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
    GPIO_InitTypeDef gpio_init_struct = {.Mode = GPIO_MODE_AF_PP,
                                         .Pull = GPIO_PULLUP,
                                         .Speed = GPIO_SPEED_FREQ_HIGH};

    if (huart->Instance == USART1) {

#if (USART1_ENABLE == 1)
        __HAL_RCC_USART1_CLK_ENABLE();

        gpio_init_struct.Alternate = GPIO_AF7_USART1;

        if (huart->Init.Mode & UART_MODE_TX) {
            USART1_TX_GPIO_ENABLE();
            gpio_init_struct.Pin = USART1_TX_GPIO_PIN;
            HAL_GPIO_Init(USART1_TX_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.Mode & UART_MODE_RX) {
            USART1_RX_GPIO_ENABLE();
            gpio_init_struct.Pin = USART1_RX_GPIO_PIN;
            HAL_GPIO_Init(USART1_RX_GPIO_PORT, &gpio_init_struct);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_RTS) {
            USART1_RTS_GPIO_ENABLE();
            gpio_init_struct.Pin = USART1_RTS_GPIO_PIN;
            HAL_GPIO_Init(USART1_RTS_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.HwFlowCtl & UART_HWCONTROL_CTS) {
            USART1_CTS_GPIO_ENABLE();
            gpio_init_struct.Pin = USART1_CTS_GPIO_PIN;
            HAL_GPIO_Init(USART1_CTS_GPIO_PORT, &gpio_init_struct);
        }

        HAL_NVIC_EnableIRQ(USART1_IRQn);
        HAL_NVIC_SetPriority(USART1_IRQn, USART1_IT_PREEMPT, USART1_IT_SUB);
#endif /* USART1_ENABLE == 1 */

    } else if (huart->Instance == USART2) {

#if (USART2_ENABLE == 1)
        __HAL_RCC_USART2_CLK_ENABLE();

        gpio_init_struct.Alternate = GPIO_AF7_USART2;

        if (huart->Init.Mode & UART_MODE_TX) {
            USART2_TX_GPIO_ENABLE();
            gpio_init_struct.Pin = USART2_TX_GPIO_PIN;
            HAL_GPIO_Init(USART2_TX_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.Mode & UART_MODE_RX) {
            USART2_RX_GPIO_ENABLE();
            gpio_init_struct.Pin = USART2_RX_GPIO_PIN;
            HAL_GPIO_Init(USART2_RX_GPIO_PORT, &gpio_init_struct);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_RTS) {
            USART2_RTS_GPIO_ENABLE();
            gpio_init_struct.Pin = USART2_RTS_GPIO_PIN;
            HAL_GPIO_Init(USART2_RTS_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.HwFlowCtl & UART_HWCONTROL_CTS) {
            USART2_CTS_GPIO_ENABLE();
            gpio_init_struct.Pin = USART2_CTS_GPIO_PIN;
            HAL_GPIO_Init(USART2_CTS_GPIO_PORT, &gpio_init_struct);
        }

        HAL_NVIC_EnableIRQ(USART2_IRQn);
        HAL_NVIC_SetPriority(USART2_IRQn, USART2_IT_PREEMPT, USART2_IT_SUB);
#endif /* USART2_ENABLE == 1 */

    } else if (huart->Instance == USART3) {

#if (USART3_ENABLE == 1)
        __HAL_RCC_USART3_CLK_ENABLE();

        gpio_init_struct.Alternate = GPIO_AF7_USART3;

        if (huart->Init.Mode & UART_MODE_TX) {
            USART3_TX_GPIO_ENABLE();
            gpio_init_struct.Pin = USART3_TX_GPIO_PIN;
            HAL_GPIO_Init(USART3_TX_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.Mode & UART_MODE_RX) {
            USART3_RX_GPIO_ENABLE();
            gpio_init_struct.Pin = USART3_RX_GPIO_PIN;
            HAL_GPIO_Init(USART3_RX_GPIO_PORT, &gpio_init_struct);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_RTS) {
            USART3_RTS_GPIO_ENABLE();
            gpio_init_struct.Pin = USART3_RTS_GPIO_PIN;
            HAL_GPIO_Init(USART3_RTS_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.HwFlowCtl & UART_HWCONTROL_CTS) {
            USART3_CTS_GPIO_ENABLE();
            gpio_init_struct.Pin = USART3_CTS_GPIO_PIN;
            HAL_GPIO_Init(USART3_CTS_GPIO_PORT, &gpio_init_struct);
        }

        HAL_NVIC_EnableIRQ(USART3_IRQn);
        HAL_NVIC_SetPriority(USART3_IRQn, USART3_IT_PREEMPT, USART3_IT_SUB);
#endif /* USART3_ENABLE == 1 */

    } else if (huart->Instance == UART4) {

#if (UART4_ENABLE == 1)
        __HAL_RCC_UART4_CLK_ENABLE();

        gpio_init_struct.Alternate = GPIO_AF8_UART4;

        if (huart->Init.Mode & UART_MODE_TX) {
            UART4_TX_GPIO_ENABLE();
            gpio_init_struct.Pin = UART4_TX_GPIO_PIN;
            HAL_GPIO_Init(UART4_TX_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.Mode & UART_MODE_RX) {
            UART4_RX_GPIO_ENABLE();
            gpio_init_struct.Pin = UART4_RX_GPIO_PIN;
            HAL_GPIO_Init(UART4_RX_GPIO_PORT, &gpio_init_struct);
        }

        HAL_NVIC_EnableIRQ(UART4_IRQn);
        HAL_NVIC_SetPriority(UART4_IRQn, UART4_IT_PREEMPT, UART4_IT_SUB);
#endif /* UART4_ENABLE == 1 */

    } else if (huart->Instance == UART5) {

#if (UART5_ENABLE == 1)
        __HAL_RCC_UART5_CLK_ENABLE();

        gpio_init_struct.Alternate = GPIO_AF8_UART5;

        if (huart->Init.Mode & UART_MODE_TX) {
            UART5_TX_GPIO_ENABLE();
            gpio_init_struct.Pin = UART5_TX_GPIO_PIN;
            HAL_GPIO_Init(UART5_TX_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.Mode & UART_MODE_RX) {
            UART5_RX_GPIO_ENABLE();
            gpio_init_struct.Pin = UART5_RX_GPIO_PIN;
            HAL_GPIO_Init(UART5_RX_GPIO_PORT, &gpio_init_struct);
        }

        HAL_NVIC_EnableIRQ(UART5_IRQn);
        HAL_NVIC_SetPriority(UART5_IRQn, UART5_IT_PREEMPT, UART5_IT_SUB);
#endif /* UART5_ENABLE == 1 */

    } else if (huart->Instance == USART6) {

#if (USART6_ENABLE == 1)
        __HAL_RCC_USART6_CLK_ENABLE();

        gpio_init_struct.Alternate = GPIO_AF8_USART6;

        if (huart->Init.Mode & UART_MODE_TX) {
            USART6_TX_GPIO_ENABLE();
            gpio_init_struct.Pin = USART6_TX_GPIO_PIN;
            HAL_GPIO_Init(USART6_TX_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.Mode & UART_MODE_RX) {
            USART6_RX_GPIO_ENABLE();
            gpio_init_struct.Pin = USART6_RX_GPIO_PIN;
            HAL_GPIO_Init(USART6_RX_GPIO_PORT, &gpio_init_struct);
        }

        if (huart->Init.HwFlowCtl & UART_HWCONTROL_RTS) {
            USART6_RTS_GPIO_ENABLE();
            gpio_init_struct.Pin = USART6_RTS_GPIO_PIN;
            HAL_GPIO_Init(USART6_RTS_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.HwFlowCtl & UART_HWCONTROL_CTS) {
            USART6_CTS_GPIO_ENABLE();
            gpio_init_struct.Pin = USART6_CTS_GPIO_PIN;
            HAL_GPIO_Init(USART6_CTS_GPIO_PORT, &gpio_init_struct);
        }

        HAL_NVIC_EnableIRQ(USART6_IRQn);
        HAL_NVIC_SetPriority(USART6_IRQn, USART6_IT_PREEMPT, USART6_IT_SUB);
#endif /* USART6_ENABLE == 1 */

    } else if (huart->Instance == UART7) {

#if (UART7_ENABLE == 1)
        __HAL_RCC_UART7_CLK_ENABLE();

        gpio_init_struct.Alternate = GPIO_AF8_UART7;

        if (huart->Init.Mode & UART_MODE_TX) {
            UART7_TX_GPIO_ENABLE();
            gpio_init_struct.Pin = UART7_TX_GPIO_PIN;
            HAL_GPIO_Init(UART7_TX_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.Mode & UART_MODE_RX) {
            UART7_RX_GPIO_ENABLE();
            gpio_init_struct.Pin = UART7_RX_GPIO_PIN;
            HAL_GPIO_Init(UART7_RX_GPIO_PORT, &gpio_init_struct);
        }

        HAL_NVIC_EnableIRQ(UART7_IRQn);
        HAL_NVIC_SetPriority(UART7_IRQn, UART7_IT_PREEMPT, UART7_IT_SUB);
#endif /* UART7_ENABLE == 1 */

    } else if (huart->Instance == UART8) {

#if (UART8_ENABLE == 1)
        __HAL_RCC_UART8_CLK_ENABLE();

        gpio_init_struct.Alternate = GPIO_AF8_UART8;

        if (huart->Init.Mode & UART_MODE_TX) {
            UART8_TX_GPIO_ENABLE();
            gpio_init_struct.Pin = UART8_TX_GPIO_PIN;
            HAL_GPIO_Init(UART8_TX_GPIO_PORT, &gpio_init_struct);
        }
        if (huart->Init.Mode & UART_MODE_RX) {
            UART8_RX_GPIO_ENABLE();
            gpio_init_struct.Pin = UART8_RX_GPIO_PIN;
            HAL_GPIO_Init(UART8_RX_GPIO_PORT, &gpio_init_struct);
        }

        HAL_NVIC_EnableIRQ(UART8_IRQn);
        HAL_NVIC_SetPriority(UART8_IRQn, UART8_IT_PREEMPT, UART8_IT_SUB);
#endif /* UART8_ENABLE == 1 */
    }
}

/**
 * @brief 串口格式化输出
 *
 * @param huart 串口句柄
 * @param __format 格式字符串
 */
void uart_printf(UART_HandleTypeDef *huart, const char *__format, ...) {
    va_list ap;
    va_start(ap, __format);

    vsnprintf(print_buffer, sizeof(print_buffer), __format, ap);
    va_end(ap);

    uint16_t len = strlen(print_buffer);

    if (huart->hdmatx == NULL) {
        HAL_UART_Transmit(huart, (uint8_t *)print_buffer, len, 0xFFFF);
    } else {
        HAL_UART_Transmit_DMA(huart, (uint8_t *)print_buffer, len);
    }
}

/**
 * @brief 串口错误回调
 *
 * @param huart 串口句柄
 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart) {
    __IO uint32_t error_code = 0x00U;

    error_code = HAL_UART_GetError(huart);
    if (HAL_UART_ERROR_NONE == error_code) {
        return;
    }

    switch (error_code) {
        case HAL_UART_ERROR_PE: {
            __HAL_UART_CLEAR_PEFLAG(huart);
        } break;

        case HAL_UART_ERROR_NE: {
            __HAL_UART_CLEAR_NEFLAG(huart);
        } break;

        case HAL_UART_ERROR_FE: {
            __HAL_UART_CLEAR_FEFLAG(huart);
        } break;

        case HAL_UART_ERROR_ORE: {
            __HAL_UART_CLEAR_OREFLAG(huart);
        } break;

        case HAL_UART_ERROR_DMA: {
        } break;

        default: {
        } break;
    }

    if (NULL != huart->hdmarx) {
        while (
            HAL_UART_Receive_DMA(huart, huart->pRxBuffPtr, huart->RxXferSize)) {
            __HAL_UNLOCK(huart);
        }
    } else {
        /* 恢复接收地址指针到初始buffer位置, 初始地址 = 当前地址 -
         * 已接收的数据个数, 已接收的数据个数 = 需要接收数 - 还未接收数*/
        while (HAL_UART_Receive_IT(
            huart, huart->pRxBuffPtr - (huart->RxXferSize - huart->RxXferCount),
            huart->RxXferSize)) {
            __HAL_UNLOCK(huart);
        }
    }
}

#if (USE_HAL_UART_REGISTER_CALLBACKS == 0)

/**
 * @brief 串口发送完成回调
 *
 * @param huart 串口句柄
 */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
    uart_dmatx_clear_tc_flag(huart);
}

/**
 * @brief 串口接收完成回调
 *
 * @param huart 串口句柄
 * @note 如果要多个串口使用接收回调, 强烈建议使用函数指针回调
 *       否则该函数结构会变得非常复杂
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->hdmarx == NULL) {
        return;
    }
    uart_dmarx_done_callback(huart);
}

/**
 * @brief 串口接收半满回调
 *
 * @param huart 串口句柄
 */
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart) {
    uart_dmarx_halfdone_callback(huart);
}

#endif /* USE_HAL_UART_REGISTER_CALLBACKS == 0 */
