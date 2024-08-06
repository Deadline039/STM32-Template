/**
 * @file    led.c
 * @author  Deadline039
 * @brief   LED驱动代码
 * @version 1.1
 * @date    2023-10-20
 */

#include "led.h"

/**
 * @brief LED初始化
 *
 */
void led_init(void) {
    GPIO_InitTypeDef gpio_initure = {0};

    LED0_GPIO_ENABLE();

    gpio_initure.Pin = LED0_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_initure.Pull = GPIO_PULLUP;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED0_GPIO_PORT, &gpio_initure);

    LED1_GPIO_ENABLE();
    gpio_initure.Pin = LED1_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_initure.Pull = GPIO_PULLUP;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED1_GPIO_PORT, &gpio_initure);

    /* 关闭LED */
    LED0_OFF();
    LED1_OFF();
}
