/**
 * @file    key.h
 * @author  Deadline039
 * @brief   按键驱动程序
 * @version 1.0
 * @date    2024-07-29
 */

#ifndef __KEY_H
#define __KEY_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bsp_core.h"

#define KEY0_GPIO_PORT     GPIOH
#define KEY0_GPIO_ENABLE() __HAL_RCC_GPIOH_CLK_ENABLE()
#define KEY0_GPIO_PIN      GPIO_PIN_3

#define KEY1_GPIO_PORT     GPIOH
#define KEY1_GPIO_ENABLE() __HAL_RCC_GPIOH_CLK_ENABLE()
#define KEY1_GPIO_PIN      GPIO_PIN_2

#define KEY2_GPIO_PORT     GPIOC
#define KEY2_GPIO_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define KEY2_GPIO_PIN      GPIO_PIN_13

#define WKUP_GPIO_PORT     GPIOA
#define WKUP_GPIO_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define WKUP_GPIO_PIN      GPIO_PIN_0

/**
 * @brief 按下的按键
 */
typedef enum {
    KEY_NO_PRESS = 0U,
    KEY0_PRESS,
    KEY1_PRESS,
    KEY2_PRESS,
    WKUP_PRESS
} key_press_t;

void key_init(void);
key_press_t key_scan(uint8_t mode);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __KEY_H */
