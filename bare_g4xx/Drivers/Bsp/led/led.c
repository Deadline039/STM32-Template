/**
 * @file    led.c
 * @author  Deadline039
 * @brief   LEDs function.
 * @version 1.1
 * @date    2023-10-20
 */

#include <CSP_Config.h>

#include "led.h"

/**
 * @brief LEDs initialization.
 *
 */
void led_init(void) {
    GPIO_InitTypeDef gpio_initure = {0};

    CSP_GPIO_CLK_ENABLE(LED0_GPIO_PORT);
    gpio_initure.Pin = LED0_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_initure.Pull = GPIO_PULLUP;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CSP_GPIO_PORT(LED0_GPIO_PORT), &gpio_initure);

    CSP_GPIO_CLK_ENABLE(LED1_GPIO_PORT);
    gpio_initure.Pin = LED1_GPIO_PIN;
    gpio_initure.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_initure.Pull = GPIO_PULLUP;
    gpio_initure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(CSP_GPIO_PORT(LED1_GPIO_PORT), &gpio_initure);

    LED0_OFF();
    LED1_OFF();
}
