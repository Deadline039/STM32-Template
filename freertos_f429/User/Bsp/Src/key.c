/**
 * @file    key.c
 * @author  Deadline039
 * @brief   按键初始化以及检测代码
 * @version 1.0
 * @date    2023-10-20
 */

#include "key.h"

#include "delay.h"

/**
 * @brief 按键初始化函数
 *
 */
void key_init(void) {
    GPIO_InitTypeDef gpio_initure = {0};

    KEY0_GPIO_ENABLE();
    KEY1_GPIO_ENABLE();
    KEY2_GPIO_ENABLE();
    WKUP_GPIO_ENABLE();

    gpio_initure.Pin = KEY0_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_INPUT;
    gpio_initure.Pull = GPIO_PULLUP;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(KEY0_GPIO_PORT, &gpio_initure);

    gpio_initure.Pin = KEY1_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_INPUT;
    gpio_initure.Pull = GPIO_PULLUP;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(KEY1_GPIO_PORT, &gpio_initure);

    gpio_initure.Pin = KEY2_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_INPUT;
    gpio_initure.Pull = GPIO_PULLUP;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(KEY2_GPIO_PORT, &gpio_initure);

    gpio_initure.Pin = WKUP_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_INPUT;
    gpio_initure.Pull = GPIO_PULLDOWN;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(WKUP_GPIO_PORT, &gpio_initure);
}

/* 检测按键按下 */
#define KEY0  HAL_GPIO_ReadPin(KEY0_GPIO_PORT, KEY0_GPIO_PIN)
#define KEY1  HAL_GPIO_ReadPin(KEY1_GPIO_PORT, KEY1_GPIO_PIN)
#define KEY2  HAL_GPIO_ReadPin(KEY2_GPIO_PORT, KEY2_GPIO_PIN)
#define WK_UP HAL_GPIO_ReadPin(WKUP_GPIO_PORT, WKUP_GPIO_PIN)

/**
 * @brief 按键扫描
 *
 * @param mode 是否支持连按
 *  @arg 0-不支持连按, 1-支持连按
 * @return 按下的按键
 * @note 注意此函数有响应优先级,`KEY0 > KEY1 > KEY2 > WK_UP`
 */
key_press_t key_scan(uint8_t mode) {
    static uint8_t key_up = 1; /* 按键松开标志 */
    if (mode == 1) {
        key_up = 1; /* 支持连按 */
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
    return KEY_NO_PRESS; /* 无按键按下 */
}
