/**
 * @file    delay.h
 * @author  Deadline039
 * @brief   延时函数
 * @version 1.0
 * @date    2024-08-04
 */

#ifndef __DELAY_H
#define __DELAY_H

#include "stm32f1xx_hal.h"

void delay_init(uint16_t sysclk);
void delay_ms(uint32_t ms);
void delay_us(uint32_t us);

#endif /* __DELAY_H */
