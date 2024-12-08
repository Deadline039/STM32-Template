/**
 * @file    bssp_key.c
 * @author  Deadline039
 * @brief   Keys functions.
 * @version 1.0
 * @date    2023-10-20
 */

#include "key.h"

#include "./core/core_delay.h"

/**
 * @brief Keys initialization.
 *
 */
void key_init(void) {
    GPIO_InitTypeDef gpio_initure = {0};

    CSP_GPIO_CLK_ENABLE(KEY0_GPIO_PORT);

    gpio_initure.Pin = KEY0_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_INPUT;
    gpio_initure.Pull = GPIO_PULLUP;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CSP_GPIO_PORT(KEY0_GPIO_PORT), &gpio_initure);

    CSP_GPIO_CLK_ENABLE(KEY1_GPIO_PORT);
    gpio_initure.Pin = KEY1_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_INPUT;
    gpio_initure.Pull = GPIO_PULLUP;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CSP_GPIO_PORT(KEY1_GPIO_PORT), &gpio_initure);

    CSP_GPIO_CLK_ENABLE(KEY2_GPIO_PORT);
    gpio_initure.Pin = KEY2_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_INPUT;
    gpio_initure.Pull = GPIO_PULLUP;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CSP_GPIO_PORT(KEY2_GPIO_PORT), &gpio_initure);

    CSP_GPIO_CLK_ENABLE(WKUP_GPIO_PORT);
    gpio_initure.Pin = WKUP_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_INPUT;
    gpio_initure.Pull = GPIO_PULLDOWN;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CSP_GPIO_PORT(WKUP_GPIO_PORT), &gpio_initure);
}

/* Detect the key Pin status. */
#define KEY0  HAL_GPIO_ReadPin(CSP_GPIO_PORT(KEY0_GPIO_PORT), KEY0_GPIO_PIN)
#define KEY1  HAL_GPIO_ReadPin(CSP_GPIO_PORT(KEY1_GPIO_PORT), KEY1_GPIO_PIN)
#define KEY2  HAL_GPIO_ReadPin(CSP_GPIO_PORT(KEY2_GPIO_PORT), KEY2_GPIO_PIN)
#define WK_UP HAL_GPIO_ReadPin(CSP_GPIO_PORT(WKUP_GPIO_PORT), WKUP_GPIO_PIN)

/**
 * @brief Scan the key.
 *
 * @param scan_continous Detecting consecutive presses.
 * @return The key which be pressed.
 * @note Note that keys have priority,`KEY0 > KEY1 > KEY2 > WK_UP`
 */
key_press_t key_scan(uint8_t scan_continous) {
    static uint8_t key_up = 1; /* The flag of key released. */
    if (scan_continous == 1) {
        key_up = 1; /* Detect consecutive presses. */
    }
    if (key_up && (KEY0 == 0 || KEY1 == 0 || KEY2 == 0 || WK_UP == 1)) {
        delay_ms(10);
        key_up = 0;
        if (KEY0 == 0) {
            return KEY0_PRESS;
        } else if (KEY1 == 0) {
            return KEY1_PRESS;
        } else if (KEY2 == 0) {
            return KEY2_PRESS;
        } else if (WK_UP == 1) {
            return WKUP_PRESS;
        }
    } else if (KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && WK_UP == 0) {
        key_up = 1;
    }
    return KEY_NO_PRESS;
}
