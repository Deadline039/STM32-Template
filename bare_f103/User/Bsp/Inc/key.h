/**
 * @file    key.h
 * @author  Deadline039
 * @brief   按键驱动程序
 * @version 1.0
 * @date    2024-07-29
 */

#ifndef __KEY_H
#define __KEY_H

#include "stm32f1xx_hal.h"

/* KEY0定义 */
#define KEY0_GPIO_PORT     GPIOC
#define KEY0_GPIO_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define KEY0_GPIO_PIN      GPIO_PIN_5

/* KEY1定义 */
#define KEY1_GPIO_PORT     GPIOA
#define KEY1_GPIO_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define KEY1_GPIO_PIN      GPIO_PIN_15

/* WK_UP定义 */
#define WKUP_GPIO_PORT     GPIOA
#define WKUP_GPIO_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define WKUP_GPIO_PIN      GPIO_PIN_0

/**
 * @brief 按下的按键
 */
typedef enum {
    KEY_NO_PRESS = 0U, /* 无按键按下 */
    KEY0_PRESS,        /* KEY0按下 */
    KEY1_PRESS,        /* KEY1按下 */
    WKUP_PRESS         /* WK_UP按下 */
} key_press_t;

void key_init(void);
key_press_t key_scan(uint8_t mode);

#endif /* __KEY_H */
