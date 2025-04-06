/**
 * @file    core_mpu.h
 * @author  Alientek
 * @brief   STM32H7 Memory Protection Unit configuration. 
 * @version 1.0
 * @date    2022-09-06
 */

#ifndef __CORE_MPU_H
#define __CORE_MPU_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <CSP_Config.h>

void mpu_set_protection(uint32_t address, uint32_t region_size,
                        uint32_t region_number, uint8_t disable_exec,
                        uint8_t access_permission, uint8_t is_shareable,
                        uint8_t is_cacheable, uint8_t is_bufferable);
void mpu_memory_protection(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __CORE_MPU_H */