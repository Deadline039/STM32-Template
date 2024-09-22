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

/* OnBoard Interface */
#include "key.h"
#include "led.h"

/* OnChip Interface */
#include "bsp_core.h"
#include "bsp_uart.h"
#include "core_delay.h"

/* Export bsp fucntion. */

void bsp_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __BSP_H */