/**
 * @file    bsp.h
 * @author  Deadline039
 * @brief   bsp层头文件
 * @version 0.1
 * @date    2024-07-29
 */

#ifndef __BSP_H
#define __BSP_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "delay.h"
#include "key.h"
#include "led.h"
#include "stm32f1xx_hal.h"
#include "uart.h"

void bsp_init(void);

#endif /* __BSP_H */