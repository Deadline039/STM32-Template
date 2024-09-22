/**
 * @file    key.h
 * @author  Deadline039
 * @brief   On board key function.
 * @version 1.1
 * @date    2024-07-29
 */

#ifndef __KEY_H
#define __KEY_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "bsp_core.h"

#define KEY0_GPIO_PORT     GPIOC
#define KEY0_GPIO_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define KEY0_GPIO_PIN      GPIO_PIN_5

#define KEY1_GPIO_PORT     GPIOA
#define KEY1_GPIO_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
#define KEY1_GPIO_PIN      GPIO_PIN_15

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
    WKUP_PRESS
} key_press_t;

void key_init(void);
key_press_t key_scan(uint8_t mode);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __KEY_H */
