/**
 * @file    uart.h
 * @author  Deadline039
 * @brief   STM32F103 单串口驱动
 * @version 1.1
 * @date    2024-07-31
 */

#ifndef __UART_H
#define __UART_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stm32f1xx_hal.h"

extern UART_HandleTypeDef uart_handle;

#define UARTx                     USART1
#define UARTx_CLK_ENABLE()        __HAL_RCC_USART1_CLK_ENABLE()
#define UARTx_IRQn                USART1_IRQn
#define UARTx_IRQHandler          USART1_IRQHandler

/* 未启用DMA可忽略 */
#define UARTx_DMA_TX_CLK_ENABLE() __HAL_RCC_DMA1_CLK_ENABLE()
#define UARTx_DMA_TX_CHANNEL      DMA1_Channel4
#define UARTx_DMA_TX_IRQn         DMA1_Channel4_IRQn
#define UARTx_DMA_TX_IRQHandler   DMA1_Channel4_IRQHandler

#define UARTx_DMA_RX_CLK_ENABLE() __HAL_RCC_DMA1_CLK_ENABLE()
#define UARTx_DMA_RX_CHANNEL      DMA1_Channel5
#define UARTx_DMA_RX_IRQn         DMA1_Channel5_IRQn
#define UARTx_DMA_RX_IRQHandler   DMA1_Channel5_IRQHandler

#define UARTx_TX_GPIO_PORT        GPIOA
#define UARTx_TX_GPIO_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()
#define UARTx_TX_GPIO_PIN         GPIO_PIN_9

#define UARTx_RX_GPIO_PORT        GPIOA
#define UARTx_RX_GPIO_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()
#define UARTx_RX_GPIO_PIN         GPIO_PIN_10

/* 硬件流控IO设置, 如果串口无硬件流控或者未使用可忽略 */
#define UARTx_CTS_GPIO_PORT       GPIOA
#define UARTx_CTS_GPIO_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()
#define UARTx_CTS_GPIO_PIN        GPIO_PIN_11

#define UARTx_RTS_GPIO_PORT       GPIOA
#define UARTx_RTS_GPIO_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()
#define UARTx_RTS_GPIO_PIN        GPIO_PIN_12

// <<< Use Configuration Wizard in Context Menu >>>

//  <o> 串口波特率
#define UARTx_BAND_RATE           115200

//  <o UARTx_HWCONTROL> 串口硬件流控
//      <UUART_HWCONTROL_NONE=>无
//      <UART_HWCONTROL_RTS=>RTS
//      <UART_HWCONTROL_CTS=>CTS
//      <UART_HWCONTROL_RTS_CTS=>RTS+CTS
#define UARTx_HWCONTROL           UART_HWCONTROL_NONE

//  <e> 发送DMA
#define UARTx_USE_DMA_TX          1

#if (UARTx_USE_DMA_TX == 1)
//  <o> 发送缓冲区大小
#define UARTx_TX_BUF_SIZE       256

//  <o UARTx_DMA_TX_PRIORITY> 串口 DMA发送优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define UARTx_DMA_TX_PRIORITY   DMA_PRIORITY_MEDIUM
//  <o> 串口 DMA发送中断抢占优先级
#define UARTx_DMA_TX_IT_PREEMPT 0
//  <o> 串口 DMA发送中断子优先级
#define UARTx_DMA_TX_IT_SUB     1

#endif /* UARTx_USE_DMA_TX == 1 */

//  </e>

//  <e> 接收DMA
#define UARTx_USE_DMA_RX 0

#if (UARTx_USE_DMA_RX == 1)

//  <o> 接收缓冲区大小
#define UARTx_RX_BUF_SIZE       256
//  <o> 接收fifo大小(必须为2的幂次方)
#define UARTx_RX_FIFO_SZIE      2048

//  <o UARTx_DMA_RX_PRIORITY> 串口 DMA接收优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define UARTx_DMA_RX_PRIORITY   DMA_PRIORITY_HIGH
//  <o> 串口 DMA接收中断抢占优先级
#define UARTx_DMA_RX_IT_PREEMPT 0
//  <o> 串口 DMA接收中断子优先级
#define UARTx_DMA_RX_IT_SUB     0

//  <q> 启用空闲中断
//  <i> 串口空闲时自动将数据拷贝到fifo中
#define UARTx_USE_IDLE_IT       1

#endif /* UARTx_USE_DMA_RX == 1 */

//  </e>

//  <o> 串口中断抢占优先级
#define UARTx_IT_PREEMPT 2
//  <o> 串口中断子优先级
#define UARTx_IT_SUB     3

// <<< end of configuration section >>>

void uart_init(void);

int uart_printf(UART_HandleTypeDef *huart, const char *__format, ...);
int uart_scanf(UART_HandleTypeDef *huart, const char *__format, ...);

#if (UARTx_USE_DMA_TX == 1)
uint32_t uart_dmatx_write(const void *data, size_t len);
uint32_t uart_dmatx_send(void);
#endif /* UARTx_USE_DMA_TX == 1 */

#if (UARTx_USE_DMA_RX == 1)
uint32_t uart_dmarx_read(void *buf, size_t buf_size);
#endif /* UARTx_USE_DMA_RX == 1 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __UART_H */
