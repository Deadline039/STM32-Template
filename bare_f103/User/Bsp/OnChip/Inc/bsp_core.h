/**
 * @file    bsp_core.h
 * @author  Deadline039
 * @brief   bsp层头文件
 * @version 1.0
 * @date    2024-07-29
 */

#ifndef __BSP_CORE_H
#define __BSP_CORE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stm32f1xx_hal.h"

#include "bsp_uart.h"
#include "core_delay.h"

#include <assert.h>
#include <stdio.h>

void system_clock_config(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __BSP_CORE_H */