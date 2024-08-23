/**
 * @file    uart.h
 * @author  Deadline039
 * @brief   STM32F429 串口驱动
 * @version 1.1
 * @date    2024-07-31
 * @note    串口7和串口8的DMA会与其他串口的DMA冲突, 根据需要选择是否使用
 */

#ifndef __UART_H
#define __UART_H

#include "stm32f4xx_hal.h"

// <<< Use Configuration Wizard in Context Menu >>>

// <e> 启用串口1
// ==================

#define USART1_ENABLE 1

#if (USART1_ENABLE == 1)

extern UART_HandleTypeDef usart1_handle;

//  <e> 发送DMA
#define USART1_USE_DMA_TX 0

#if (USART1_USE_DMA_TX == 1)

//  <o> 发送缓冲区大小
#define USART1_TX_BUF_SIZE       256

//  <o USART1_DMA_TX_PRIORITY> 串口1 DMA发送优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define USART1_DMA_TX_PRIORITY   DMA_PRIORITY_MEDIUM
//  <o> 串口1 DMA发送中断抢占优先级
#define USART1_DMA_TX_IT_PREEMPT 0
//  <o> 串口1 DMA发送中断子优先级
#define USART1_DMA_TX_IT_SUB     1

#endif /* USART1_USE_DMA_TX == 1 */

//  </e>

//  <e> 接收DMA
#define USART1_USE_DMA_RX 0

#if (USART1_USE_DMA_RX == 1)

//  <o> 接收缓冲区大小
#define USART1_RX_BUF_SIZE       256
//  <o> 接收fifo大小(必须为2的幂次方)
#define USART1_RX_FIFO_SZIE      2048

//  <o USART1_DMA_RX_PRIORITY> 串口1 DMA接收优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define USART1_DMA_RX_PRIORITY   DMA_PRIORITY_HIGH
//  <o> 串口1 DMA接收中断抢占优先级
#define USART1_DMA_RX_IT_PREEMPT 0
//  <o> 串口1 DMA接收中断子优先级
#define USART1_DMA_RX_IT_SUB     0

//  <q> 启用空闲中断
//  <i> 串口空闲时自动将数据拷贝到fifo中
#define USART1_USE_IDLE_IT       1

#endif /* USART1_USE_DMA_RX == 1 */

//  </e>

//  <o> 串口1中断抢占优先级
#define USART1_IT_PREEMPT        2
//  <o> 串口1子优先级
#define USART1_IT_SUB            3

/* 串口1 发送GPIO */
#define USART1_TX_GPIO_PORT      GPIOA
#define USART1_TX_GPIO_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define USART1_TX_GPIO_PIN       GPIO_PIN_9
/* 串口1 接收GPIO */
#define USART1_RX_GPIO_PORT      GPIOA
#define USART1_RX_GPIO_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define USART1_RX_GPIO_PIN       GPIO_PIN_10

/* 串口1 CTS GPIO */
#define USART1_CTS_GPIO_PORT     GPIOA
#define USART1_CTS_GPIO_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define USART1_CTS_GPIO_PIN      GPIO_PIN_11
/* 串口1 RTS GPIO */
#define USART1_RTS_GPIO_PORT     GPIOA
#define USART1_RTS_GPIO_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define USART1_RTS_GPIO_PIN      GPIO_PIN_12

#endif /* USART1_ENABLE == 1 */

// </e>

// <e> 启用串口2
// ==================

#define USART2_ENABLE 0

#if (USART2_ENABLE == 1)

extern UART_HandleTypeDef usart2_handle;

//  <e> 发送DMA
#define USART2_USE_DMA_TX 1

#if (USART2_USE_DMA_TX == 1)

//  <o> 发送缓冲区大小
#define USART2_TX_BUF_SIZE       128

//  <o USART2_DMA_TX_PRIORITY> 串口2 DMA发送优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define USART2_DMA_TX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口2 DMA发送中断抢占优先级
#define USART2_DMA_TX_IT_PREEMPT 2
//  <o> 串口2 DMA发送中断子优先级
#define USART2_DMA_TX_IT_SUB     3

#endif /* USART2_USE_DMA_TX == 1 */

//  </e>

//  <e> 接收DMA
#define USART2_USE_DMA_RX 1

#if (USART2_USE_DMA_RX == 1)

//  <o> 接收缓冲区大小
#define USART2_RX_BUF_SIZE       256
//  <o> 接收fifo大小(必须为2的幂次方)
#define USART2_RX_FIFO_SZIE      2048

//  <o USART2_DMA_RX_PRIORITY> 串口2 DMA接收优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define USART2_DMA_RX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口2 DMA接收中断抢占优先级
#define USART2_DMA_RX_IT_PREEMPT 1
//  <o> 串口2 DMA接收中断子优先级
#define USART2_DMA_RX_IT_SUB     2

//  <q> 启用空闲中断
//  <i> 串口空闲时自动将数据拷贝到fifo中
#define USART2_USE_IDLE_IT       1

#endif /* USART2_USE_DMA_RX == 1 */

//  </e>

//  <o> 串口2中断抢占优先级
#define USART2_IT_PREEMPT        2
//  <o> 串口2子优先级
#define USART2_IT_SUB            3

/* 串口2 发送GPIO */
#define USART2_TX_GPIO_PORT      GPIOA
#define USART2_TX_GPIO_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define USART2_TX_GPIO_PIN       GPIO_PIN_2
/* 串口2 接收GPIO */
#define USART2_RX_GPIO_PORT      GPIOA
#define USART2_RX_GPIO_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define USART2_RX_GPIO_PIN       GPIO_PIN_3

/* 串口2 CTS GPIO */
#define USART2_CTS_GPIO_PORT     GPIOD
#define USART2_CTS_GPIO_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()
#define USART2_CTS_GPIO_PIN      GPIO_PIN_3
/* 串口2 RTS GPIO */
#define USART2_RTS_GPIO_PORT     GPIOD
#define USART2_RTS_GPIO_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()
#define USART2_RTS_GPIO_PIN      GPIO_PIN_4

#endif /* USART2_ENABLE == 1 */

// </e>

// <e> 启用串口3
// ==================

#define USART3_ENABLE 0

#if (USART3_ENABLE == 1)

extern UART_HandleTypeDef usart3_handle;

//  <e> 发送DMA
#define USART3_USE_DMA_TX 1

#if (USART3_USE_DMA_TX == 1)

//  <o> 发送缓冲区大小
#define USART3_TX_BUF_SIZE       128

//  <o USART3_DMA_TX_PRIORITY> 串口3 DMA发送优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define USART3_DMA_TX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口3 DMA发送中断抢占优先级
#define USART3_DMA_TX_IT_PREEMPT 2
//  <o> 串口3 DMA发送中断子优先级
#define USART3_DMA_TX_IT_SUB     3

#endif /* USART3_USE_DMA_TX == 1 */

//  </e>

//  <e> 接收DMA
#define USART3_USE_DMA_RX 1

#if (USART3_USE_DMA_RX == 1)

//  <o> 接收缓冲区大小
#define USART3_RX_BUF_SIZE       256
//  <o> 接收fifo大小(必须为2的幂次方)
#define USART3_RX_FIFO_SZIE      2048

//  <o USART3_DMA_RX_PRIORITY> 串口3 DMA接收优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define USART3_DMA_RX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口3 DMA接收中断抢占优先级
#define USART3_DMA_RX_IT_PREEMPT 1
//  <o> 串口3 DMA接收中断子优先级
#define USART3_DMA_RX_IT_SUB     2

//  <q> 启用空闲中断
//  <i> 串口空闲时自动将数据拷贝到fifo中
#define USART3_USE_IDLE_IT       1

#endif /* USART3_USE_DMA_RX == 1 */

//  </e>

//  <o> 串口3中断抢占优先级
#define USART3_IT_PREEMPT        2
//  <o> 串口3子优先级
#define USART3_IT_SUB            3

/* 串口3 发送GPIO */
#define USART3_TX_GPIO_PORT      GPIOB
#define USART3_TX_GPIO_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()
#define USART3_TX_GPIO_PIN       GPIO_PIN_10
/* 串口3 接收GPIO */
#define USART3_RX_GPIO_PORT      GPIOB
#define USART3_RX_GPIO_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE()
#define USART3_RX_GPIO_PIN       GPIO_PIN_11

/* 串口3 CTS GPIO */
#define USART3_CTS_GPIO_PORT     GPIOB
#define USART3_CTS_GPIO_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define USART3_CTS_GPIO_PIN      GPIO_PIN_13
/* 串口3 RTS GPIO */
#define USART3_RTS_GPIO_PORT     GPIOB
#define USART3_RTS_GPIO_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define USART3_RTS_GPIO_PIN      GPIO_PIN_14

#endif /* USART3_ENABLE == 1 */

// </e>

// <e> 启用串口4
// ==================

#define UART4_ENABLE 0

#if (UART4_ENABLE == 1)

extern UART_HandleTypeDef uart4_handle;

//  <e> 发送DMA
#define UART4_USE_DMA_TX 1

#if (UART4_USE_DMA_TX == 1)

//  <o> 发送缓冲区大小
#define UART4_TX_BUF_SIZE       128

//  <o UART4_DMA_TX_PRIORITY> 串口4 DMA发送优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define UART4_DMA_TX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口4 DMA发送中断抢占优先级
#define UART4_DMA_TX_IT_PREEMPT 2
//  <o> 串口4 DMA发送中断子优先级
#define UART4_DMA_TX_IT_SUB     3

#endif /* UART4_USE_DMA_TX == 1 */

//  </e>

//  <e> 接收DMA
#define UART4_USE_DMA_RX 1

#if (UART4_USE_DMA_RX == 1)

//  <o> 接收缓冲区大小
#define UART4_RX_BUF_SIZE       256
//  <o> 接收fifo大小(必须为2的幂次方)
#define UART4_RX_FIFO_SZIE      2048

//  <o UART4_DMA_RX_PRIORITY> 串口4 DMA接收优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define UART4_DMA_RX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口4 DMA接收中断抢占优先级
#define UART4_DMA_RX_IT_PREEMPT 1
//  <o> 串口4 DMA接收中断子优先级
#define UART4_DMA_RX_IT_SUB     2

//  <q> 启用空闲中断
//  <i> 串口空闲时自动将数据拷贝到fifo中
#define UART4_USE_IDLE_IT       1

#endif /* UART4_USE_DMA_RX == 1 */

//  </e>

//  <o> 串口4中断抢占优先级
#define UART4_IT_PREEMPT       2
//  <o> 串口4子优先级
#define UART4_IT_SUB           3

/* 串口4 发送GPIO */
#define UART4_TX_GPIO_PORT     GPIOC
#define UART4_TX_GPIO_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define UART4_TX_GPIO_PIN      GPIO_PIN_10
/* 串口4 接收GPIO */
#define UART4_RX_GPIO_PORT     GPIOC
#define UART4_RX_GPIO_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define UART4_RX_GPIO_PIN      GPIO_PIN_11

#endif /* UART4_ENABLE == 1 */

// </e>

// <e> 启用串口5
// ==================

#define UART5_ENABLE 0

#if (UART5_ENABLE == 1)

extern UART_HandleTypeDef uart5_handle;

//  <e> 发送DMA
#define UART5_USE_DMA_TX 1

#if (UART5_USE_DMA_TX == 1)

//  <o> 发送缓冲区大小
#define UART5_TX_BUF_SIZE       128

//  <o UART5_DMA_TX_PRIORITY> 串口5 DMA发送优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define UART5_DMA_TX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口5 DMA发送中断抢占优先级
#define UART5_DMA_TX_IT_PREEMPT 2
//  <o> 串口5 DMA发送中断子优先级
#define UART5_DMA_TX_IT_SUB     3

#endif /* UART5_USE_DMA_TX == 1 */

//  </e>

//  <e> 接收DMA
#define UART5_USE_DMA_RX 1

#if (UART5_USE_DMA_RX == 1)

//  <o> 接收缓冲区大小
#define UART5_RX_BUF_SIZE       256
//  <o> 接收fifo大小(必须为2的幂次方)
#define UART5_RX_FIFO_SZIE      2048

//  <o UART5_DMA_RX_PRIORITY> 串口5 DMA接收优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define UART5_DMA_RX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口5 DMA接收中断抢占优先级
#define UART5_DMA_RX_IT_PREEMPT 1
//  <o> 串口5 DMA接收中断子优先级
#define UART5_DMA_RX_IT_SUB     2

//  <q> 启用空闲中断
//  <i> 串口空闲时自动将数据拷贝到fifo中
#define UART5_USE_IDLE_IT       1

#endif /* UART5_USE_DMA_RX == 1 */

//  </e>

//  <o> 串口5中断抢占优先级
#define UART5_IT_PREEMPT       2
//  <o> 串口5子优先级
#define UART5_IT_SUB           3

/* 串口5 发送GPIO */
#define UART5_TX_GPIO_PORT     GPIOC
#define UART5_TX_GPIO_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define UART5_TX_GPIO_PIN      GPIO_PIN_12
/* 串口5 接收GPIO */
#define UART5_RX_GPIO_PORT     GPIOD
#define UART5_RX_GPIO_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE()
#define UART5_RX_GPIO_PIN      GPIO_PIN_2

#endif /* UART5_ENABLE == 1 */

// </e>

// <e> 启用串口6
// ==================

#define USART6_ENABLE 0

#if (USART6_ENABLE == 1)

extern UART_HandleTypeDef usart6_handle;

//  <e> 发送DMA
#define USART6_USE_DMA_TX 1

#if (USART6_USE_DMA_TX == 1)

//  <o> 发送缓冲区大小
#define USART6_TX_BUF_SIZE       256

//  <o USART6_DMA_TX_PRIORITY> 串口6 DMA发送优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define USART6_DMA_TX_PRIORITY   DMA_PRIORITY_MEDIUM
//  <o> 串口6 DMA发送中断抢占优先级
#define USART6_DMA_TX_IT_PREEMPT 0
//  <o> 串口6 DMA发送中断子优先级
#define USART6_DMA_TX_IT_SUB     1

#endif /* USART6_USE_DMA_TX == 1 */

//  </e>

//  <e> 接收DMA
#define USART6_USE_DMA_RX 1

#if (USART6_USE_DMA_RX == 1)

//  <o> 接收缓冲区大小
#define USART6_RX_BUF_SIZE       256
//  <o> 接收fifo大小(必须为2的幂次方)
#define USART6_RX_FIFO_SZIE      2048

//  <o USART6_DMA_RX_PRIORITY> 串口6 DMA接收优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define USART6_DMA_RX_PRIORITY   DMA_PRIORITY_HIGH
//  <o> 串口6 DMA接收中断抢占优先级
#define USART6_DMA_RX_IT_PREEMPT 0
//  <o> 串口6 DMA接收中断子优先级
#define USART6_DMA_RX_IT_SUB     0

//  <q> 启用空闲中断
//  <i> 串口空闲时自动将数据拷贝到fifo中
#define USART6_USE_IDLE_IT       1

#endif /* USART6_USE_DMA_RX == 1 */

//  </e>

//  <o> 串口6中断抢占优先级
#define USART6_IT_PREEMPT        2
//  <o> 串口6子优先级
#define USART6_IT_SUB            3

/* 串口6 发送GPIO */
#define USART6_TX_GPIO_PORT      GPIOC
#define USART6_TX_GPIO_ENABLE()  __HAL_RCC_GPIOC_CLK_ENABLE()
#define USART6_TX_GPIO_PIN       GPIO_PIN_6
/* 串口6 接收GPIO */
#define USART6_RX_GPIO_PORT      GPIOC
#define USART6_RX_GPIO_ENABLE()  __HAL_RCC_GPIOC_CLK_ENABLE()
#define USART6_RX_GPIO_PIN       GPIO_PIN_7

/* 串口6 CTS GPIO */
#define USART6_CTS_GPIO_PORT     GPIOG
#define USART6_CTS_GPIO_ENABLE() __HAL_RCC_GPIOG_CLK_ENABLE()
#define USART6_CTS_GPIO_PIN      GPIO_PIN_13
/* 串口6 RTS GPIO */
#define USART6_RTS_GPIO_PORT     GPIOG
#define USART6_RTS_GPIO_ENABLE() __HAL_RCC_GPIOG_CLK_ENABLE()
#define USART6_RTS_GPIO_PIN      GPIO_PIN_12

#endif /* USART6_ENABLE == 1 */

// </e>

// <e> 启用串口7
// ==================

#define UART7_ENABLE 0

#if (UART7_ENABLE == 1)

extern UART_HandleTypeDef uart7_handle;

#if (defined(STM32F429xx) || defined(STM32F439xx))
//  <e> 发送DMA
#define UART7_USE_DMA_TX 0

#if (UART7_USE_DMA_TX == 1)

//  <o> 发送缓冲区大小
#define UART7_TX_BUF_SIZE       128

//  <o UART7_DMA_TX_PRIORITY> 串口7 DMA发送优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define UART7_DMA_TX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口7 DMA发送中断抢占优先级
#define UART7_DMA_TX_IT_PREEMPT 2
//  <o> 串口7 DMA发送中断子优先级
#define UART7_DMA_TX_IT_SUB     3

#endif /* UART7_USE_DMA_TX == 1 */

//  </e>

//  <e> 接收DMA
#define UART7_USE_DMA_RX 0

#if (UART7_USE_DMA_RX == 1)

//  <o> 接收缓冲区大小
#define UART7_RX_BUF_SIZE       256
//  <o> 接收fifo大小(必须为2的幂次方)
#define UART7_RX_FIFO_SZIE      2048

//  <o UART7_DMA_RX_PRIORITY> 串口7 DMA接收优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define UART7_DMA_RX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口7 DMA接收中断抢占优先级
#define UART7_DMA_RX_IT_PREEMPT 1
//  <o> 串口7 DMA接收中断子优先级
#define UART7_DMA_RX_IT_SUB     2

//  <q> 启用空闲中断
//  <i> 串口空闲时自动将数据拷贝到fifo中
#define UART7_USE_IDLE_IT       1

#endif /* UART7_USE_DMA_RX == 1 */

//  </e>

#endif /* (defined(STM32F429xx) || defined(STM32F439xx))  */

//  <o> 串口7中断抢占优先级
#define UART7_IT_PREEMPT       2
//  <o> 串口7子优先级
#define UART7_IT_SUB           3

/* 串口7 发送GPIO */
#define UART7_TX_GPIO_PORT     GPIOE
#define UART7_TX_GPIO_ENABLE() __HAL_RCC_GPIOE_CLK_ENABLE()
#define UART7_TX_GPIO_PIN      GPIO_PIN_8
/* 串口7 接收GPIO */
#define UART7_RX_GPIO_PORT     GPIOE
#define UART7_RX_GPIO_ENABLE() __HAL_RCC_GPIOE_CLK_ENABLE()
#define UART7_RX_GPIO_PIN      GPIO_PIN_7

#endif /* UART7_ENABLE == 1 */

// </e>

// <e> 启用串口8
// ==================

#define UART8_ENABLE 0

#if (UART8_ENABLE == 1)

extern UART_HandleTypeDef uart8_handle;

#if (defined(STM32F429xx) || defined(STM32F439xx))

//  <e> 发送DMA
#define UART8_USE_DMA_TX 0

#if (UART8_USE_DMA_TX == 1)

//  <o> 发送缓冲区大小
#define UART8_TX_BUF_SIZE       128

//  <o UART8_DMA_TX_PRIORITY> 串口8 DMA发送优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define UART8_DMA_TX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口8 DMA发送中断抢占优先级
#define UART8_DMA_TX_IT_PREEMPT 2
//  <o> 串口8 DMA发送中断子优先级
#define UART8_DMA_TX_IT_SUB     3

#endif /* UART8_USE_DMA_TX == 1 */

//  </e>

//  <e> 接收DMA
#define UART8_USE_DMA_RX 0

#if (UART8_USE_DMA_RX == 1)

//  <o> 接收缓冲区大小
#define UART8_RX_BUF_SIZE       256
//  <o> 接收fifo大小(必须为2的幂次方)
#define UART8_RX_FIFO_SZIE      2048

//  <o UART8_DMA_RX_PRIORITY> 串口8 DMA接收优先级
//      <DMA_PRIORITY_LOW=>低
//      <DMA_PRIORITY_MEDIUM=>中
//      <DMA_PRIORITY_HIGH=>高
//      <DMA_PRIORITY_VERY_HIGH=>非常高
#define UART8_DMA_RX_PRIORITY   DMA_PRIORITY_LOW
//  <o> 串口8 DMA接收中断抢占优先级
#define UART8_DMA_RX_IT_PREEMPT 1
//  <o> 串口8 DMA接收中断子优先级
#define UART8_DMA_RX_IT_SUB     2

//  <q> 启用空闲中断
//  <i> 串口空闲时自动将数据拷贝到fifo中
#define UART8_USE_IDLE_IT       1

#endif /* UART8_USE_DMA_RX == 1 */

//  </e>

#endif /* (defined(STM32F429xx) || defined(STM32F439xx))  */

//  <o> 串口8中断抢占优先级
#define UART8_IT_PREEMPT       2
//  <o> 串口8子优先级
#define UART8_IT_SUB           3

/* 串口8 发送GPIO */
#define UART8_TX_GPIO_PORT     GPIOE
#define UART8_TX_GPIO_ENABLE() __HAL_RCC_GPIOE_CLK_ENABLE()
#define UART8_TX_GPIO_PIN      GPIO_PIN_0
/* 串口8 接收GPIO */
#define UART8_RX_GPIO_PORT     GPIOE
#define UART8_RX_GPIO_ENABLE() __HAL_RCC_GPIOE_CLK_ENABLE()
#define UART8_RX_GPIO_PIN      GPIO_PIN_1

#endif /* UART8_ENABLE == 1 */

// </e>

// <<< end of configuration section >>>

void uart_init(UART_HandleTypeDef *huart, uint32_t baud_rate,
               uint32_t word_length, uint32_t stop_bits, uint32_t parity,
               uint32_t hw_flow_ctrl, uint32_t mode);

void uart_printf(UART_HandleTypeDef *huart, const char *__format, ...);

uint32_t uart_dmatx_write(UART_HandleTypeDef *huart, const void *data,
                          size_t len);
uint32_t uart_dmatx_send(UART_HandleTypeDef *huart);

uint32_t uart_dmarx_read(UART_HandleTypeDef *huart, void *buf, size_t len);

#endif /* __UART_H */
