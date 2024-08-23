/**
 * @file    led.h
 * @author  Deadline039
 * @brief   LED驱动程序
 * @version 1.0
 * @date    2024-07-29
 */

#ifndef __LED_H
#define __LED_H

#include "stm32f4xx_hal.h"

/* LED0定义 */
#define LED0_GPIO_PORT     GPIOB
#define LED0_GPIO_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED0_GPIO_PIN      GPIO_PIN_1

/* LED1定义 */
#define LED1_GPIO_PORT     GPIOB
#define LED1_GPIO_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED1_GPIO_PIN      GPIO_PIN_0

/* LED0 */
#define LED0(x)                                                                \
    x ? HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_SET)         \
      : HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_RESET)
/* 点亮LED0 */
#define LED0_ON()                                                              \
    HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_RESET)
/* 熄灭LED0 */
#define LED0_OFF()                                                             \
    HAL_GPIO_WritePin(LED0_GPIO_PORT, LED0_GPIO_PIN, GPIO_PIN_SET)
/* 翻转LED0 */
#define LED0_TOGGLE() HAL_GPIO_TogglePin(LED0_GPIO_PORT, LED0_GPIO_PIN)

/* LED1 */
#define LED1(x)                                                                \
    x ? HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_SET)         \
      : HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_RESET)
/* 点亮LED1 */
#define LED1_ON()                                                              \
    HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_RESET)
/* 熄灭LED1 */
#define LED1_OFF()                                                             \
    HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_GPIO_PIN, GPIO_PIN_SET)
/* 翻转LED1 */
#define LED1_TOGGLE() HAL_GPIO_TogglePin(LED1_GPIO_PORT, LED1_GPIO_PIN)

void led_init(void);

#endif /* __LED_H */
