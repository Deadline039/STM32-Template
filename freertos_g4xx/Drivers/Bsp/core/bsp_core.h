/**
 * @file    bsp_core.h
 * @author  Deadline039
 * @brief   System core configuration header file.
 * @version 1.0
 * @date    2024-11-13
 */

#ifndef __BSP_CORE_H
#define __BSP_CORE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <CSP_Config.h>

/* No problem at configuration system clock. */
#define SYSTEM_CORE_CLK_OK         0
/* High speed clock configuration failed. */
#define SYSTEM_CORE_HSC_FAIL       1
/* Low speed clock configuration failed. */
#define SYSTEM_CORE_LSC_FAIL       2
/* Peripherals(AHB, APB) clock configuration failed. */
#define SYSTEM_PERIPH_CLK_FAIL     3
/* Enable over drive mode failed. */
#define SYSTEM_PWR_OVER_DRIVE_FAIL 4

uint8_t system_clock_config(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __BSP_CORE_H */