/**
 * @file    core_delay.h
 * @author  Alientek
 * @brief   Using SysTick to delay.
 * @version 1.1
 * @date    2024-08-05
 */

#ifndef __DELAY_H
#define __DELAY_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <CSP_Config.h>

void delay_init(uint16_t sysclk);
void delay_ms(uint32_t ms);
void delay_us(uint32_t us);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __CORE_DELAY_H */
