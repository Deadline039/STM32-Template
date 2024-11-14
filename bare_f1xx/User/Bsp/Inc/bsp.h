/**
 * @file    bsp.h
 * @author  Deadline039
 * @brief   Bsp layer export interface.
 * @version 1.0
 * @date    2024-09-18
 */

#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "CSP_Config.h"

#include "bsp_core.h"
#include "core_delay.h"
#include "key.h"
#include "led.h"

void bsp_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __BSP_H */