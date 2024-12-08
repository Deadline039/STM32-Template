/**
 * @file    delay.c
 * @author  Alientek
 * @brief   Using SysTick to delay.
 * @version 1.1
 * @date    2024-08-05
 */

#include "core_delay.h"

#include "FreeRTOS.h"
#include "task.h"

static uint32_t g_fac_us = 0;

/**
 * @brief Initialize the delay function.
 *
 * @param sysclk System clock frequency(MHz)
 */
void delay_init(uint16_t sysclk) {
    uint32_t reload;

    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
    g_fac_us = sysclk;

    reload = sysclk;

    reload *= 1000000 / configTICK_RATE_HZ;
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
    SysTick->LOAD = reload;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

/**
 * @brief Delay n milliseconds.
 *
 * @param ms The time to delay.
 */
void delay_ms(uint32_t ms) {
    if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) {
        vTaskDelay(ms);
    } else {
        for (uint32_t i = 0; i < ms; ++i) {
            delay_us(1000);
        }
    }
}

/**
 * @brief Delay n microseconds.
 *
 * @param us The time to delay.
 */
void delay_us(uint32_t us) {
    uint32_t ticks;
    uint32_t told, tnow, tcnt = 0;
    uint32_t reload = SysTick->LOAD;
    ticks = us * g_fac_us;
    told = SysTick->VAL;

    while (1) {
        tnow = SysTick->VAL;
        if (tnow != told) {
            if (tnow < told) {
                tcnt += told - tnow;
            } else {
                tcnt += reload - tnow + told;
            }
            told = tnow;
            if (tcnt >= ticks) {
                break;
            }
        }
    }
}
