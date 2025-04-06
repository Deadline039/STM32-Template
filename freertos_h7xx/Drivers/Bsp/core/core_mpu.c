/**
 * @file    core_mpu.c
 * @author  Alientek
 * @brief   STM32H7 Memory Protection Unit configuration. 
 * @version 1.0
 * @date    2022-09-06
 */

#include "core_mpu.h"

/**
 * @brief Set memory protection region.
 * 
 * @param address The memory address will be protected.
 * @param region_size The size of memory will be protected. 
 *                    It must be an integer multiple of 32.
 *  @arg This parameter can be a value of @ref CORTEX_MPU_Region_Size
 * @param region_number The protection region number. 
 *  @arg This parameter can be a value of @ref CORTEX_MPU_Region_Number
 * @param disable_exec Specific the instruction access status.
 *  @arg This parameter can be a value of @ref CORTEX_MPU_Instruction_Access
 * @param access_permission Specifies the regioin access permission type. 
 *  @arg This parameter can be a value of @ref CORTEX_MPU_Region_Permission_Attributes
 * @param is_shareable Specifies the shareability status of the protected region.
 *  @arg This parameter can be a value of @ref CORTEX_MPU_Access_Shareable
 * @param is_cacheable pecifies the cacheable status of the region protected.
 *  @arg This parameter can be a value of @ref CORTEX_MPU_Access_Cacheable
 * @param is_bufferable Specifies the bufferable status of the protected region.
 *  @arg This parameter can be a value of @ref CORTEX_MPU_Access_Bufferable
 */
void mpu_set_protection(uint32_t address, uint32_t region_size,
                        uint32_t region_number, uint8_t disable_exec,
                        uint8_t access_permission, uint8_t is_shareable,
                        uint8_t is_cacheable, uint8_t is_bufferable) {
    MPU_Region_InitTypeDef mpu_region_init_handle;

    HAL_MPU_Disable();

    mpu_region_init_handle.Enable = MPU_REGION_ENABLE;
    mpu_region_init_handle.Number = region_number;
    mpu_region_init_handle.BaseAddress = address;
    mpu_region_init_handle.DisableExec = disable_exec;
    mpu_region_init_handle.Size = region_size;
    mpu_region_init_handle.SubRegionDisable = 0x00;
    mpu_region_init_handle.TypeExtField = MPU_TEX_LEVEL0;
    mpu_region_init_handle.AccessPermission = access_permission;
    mpu_region_init_handle.IsShareable = is_shareable;
    mpu_region_init_handle.IsCacheable = is_cacheable;
    mpu_region_init_handle.IsBufferable = is_bufferable;
    HAL_MPU_ConfigRegion(&mpu_region_init_handle);
    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
 * @brief Set up the protection region. For example: NAND Flash, LCD, etc.
 * 
 */
void mpu_memory_protection(void) {
    /* Protect DTCM, 128 KByte. */
    mpu_set_protection(0x20000000, MPU_REGION_SIZE_128KB, MPU_REGION_NUMBER1,
                       MPU_INSTRUCTION_ACCESS_ENABLE, MPU_REGION_FULL_ACCESS,
                       MPU_ACCESS_NOT_SHAREABLE, MPU_ACCESS_CACHEABLE,
                       MPU_ACCESS_BUFFERABLE);

    /* Protect AXI SRAM, 512 KByte. */
    mpu_set_protection(0x24000000, MPU_REGION_SIZE_512KB, MPU_REGION_NUMBER2,
                       MPU_INSTRUCTION_ACCESS_ENABLE, MPU_REGION_FULL_ACCESS,
                       MPU_ACCESS_SHAREABLE, MPU_ACCESS_CACHEABLE,
                       MPU_ACCESS_NOT_BUFFERABLE);

    /* Protect SRAM1 to SRAM3, 512 KByte. */
    mpu_set_protection(0x30000000, MPU_REGION_SIZE_512KB, MPU_REGION_NUMBER3,
                       MPU_INSTRUCTION_ACCESS_ENABLE, MPU_REGION_FULL_ACCESS,
                       MPU_ACCESS_NOT_SHAREABLE, MPU_ACCESS_CACHEABLE,
                       MPU_ACCESS_BUFFERABLE);

    /* Protect SRAM4, 64 KByte. */
    mpu_set_protection(0x38000000, MPU_REGION_SIZE_64KB, MPU_REGION_NUMBER4,
                       MPU_INSTRUCTION_ACCESS_ENABLE, MPU_REGION_FULL_ACCESS,
                       MPU_ACCESS_NOT_SHAREABLE, MPU_ACCESS_CACHEABLE,
                       MPU_ACCESS_BUFFERABLE);

    /* Protect MCU LCD FMC region, 64 MByte. */
    mpu_set_protection(0x60000000, MPU_REGION_SIZE_64MB, MPU_REGION_NUMBER5,
                       MPU_INSTRUCTION_ACCESS_ENABLE, MPU_REGION_FULL_ACCESS,
                       MPU_ACCESS_NOT_SHAREABLE, MPU_ACCESS_NOT_CACHEABLE,
                       MPU_ACCESS_NOT_BUFFERABLE);

    /* Protect SDRAM region, 32 MByte. */
    mpu_set_protection(0xC0000000, MPU_REGION_SIZE_32MB, MPU_REGION_NUMBER6,
                       MPU_INSTRUCTION_ACCESS_ENABLE, MPU_REGION_FULL_ACCESS,
                       MPU_ACCESS_NOT_SHAREABLE, MPU_ACCESS_CACHEABLE,
                       MPU_ACCESS_BUFFERABLE);

    /* Protect NAND FLASH region, 256 MByte. */
    mpu_set_protection(0x80000000, MPU_REGION_SIZE_256MB, MPU_REGION_NUMBER7,
                       MPU_INSTRUCTION_ACCESS_DISABLE, MPU_REGION_FULL_ACCESS,
                       MPU_ACCESS_NOT_SHAREABLE, MPU_ACCESS_NOT_CACHEABLE,
                       MPU_ACCESS_NOT_BUFFERABLE);
}
