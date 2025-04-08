/**
  ******************************************************************************
  * @file    stm32g4xx_hal_conf.h
  * @author  MCD Application Team
  * @brief   HAL configuration template file.
  *          This file should be copied to the application folder and renamed
  *          to stm32g4xx_hal_conf.h.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32G4xx_HAL_CONF_H
#define STM32G4xx_HAL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

/* ########################## Module Selection ############################## */

#define HAL_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED

// <h> HAL 库配置选择

// <c> 启用 ADC (Analog-to-digital convert)
#define HAL_ADC_MODULE_ENABLED
// </c>

// <c> 启用 Comp (Comparator)
#define HAL_COMP_MODULE_ENABLED
// </c>

// <c> 启用 CORDIC (Trigonometric calculation unit)
#define HAL_CORDIC_MODULE_ENABLED
// </c>

// <c> 启用 CRC (CRC calculation unit)
#define HAL_CRC_MODULE_ENABLED
// </c>

// <c> 启用 CRYP (Cryptographic processor)
#define HAL_CRYP_MODULE_ENABLED
// </c>

// <c> 启用 DAC (Digital to analog converter)
#define HAL_DAC_MODULE_ENABLED
// </c>

// <c> 启用 DMA (Direct memory access)
#define HAL_DMA_MODULE_ENABLED
// </c>

// <c> 启用 EXTI (External interrupt/event controller)
#define HAL_EXTI_MODULE_ENABLED
// </c>

// <c> 启用 FDCAN (Flexible data-rate controller area network unit)
#define HAL_FDCAN_MODULE_ENABLED
// </c>

// <c> 启用 FLASH (Flash memory)
#define HAL_FLASH_MODULE_ENABLED
// </c>

// <c> 启用 FMAC (Filtering mathematical calculation unit)
#define HAL_FMAC_MODULE_ENABLED
// </c>

// <c> 启用 GPIO (General purpose I/Os)
#define HAL_GPIO_MODULE_ENABLED
// </c>

// <c> 启用 HRTIM (High-resolution timer)
#define HAL_HRTIM_MODULE_ENABLED
// </c>

// <c> 启用 IRDA (Infrared data association)
#define HAL_IRDA_MODULE_ENABLED
// </c>

// <c> 启用 IWDG (Independent watchdog)
#define HAL_IWDG_MODULE_ENABLED
// </c>

// <c> 启用 I2C (Inter-integrated circuit)
#define HAL_I2C_MODULE_ENABLED
// </c>

// <c> 启用 I2S (Inter-integrated sound)
#define HAL_I2S_MODULE_ENABLED
// </c>

// <c> 启用 LPTIM (Low-power timer)
#define HAL_LPTIM_MODULE_ENABLED
// </c>

// <c> 启用 NAND (NAND Flash memory)
#define HAL_NAND_MODULE_ENABLED
// </c>

// <c> 启用 NOR (NOR Flash memory)
#define HAL_NOR_MODULE_ENABLED
// </c>

// <c> 启用 OPAMP (Operational amplifier)
#define HAL_OPAMP_MODULE_ENABLED
// </c>

// <c> 启用 PCD (USB peripheral controller driver)
#define HAL_PCD_MODULE_ENABLED
// </c>

// <c> 启用 PWR (Power controller)
#define HAL_PWR_MODULE_ENABLED
// </c>

// <c> 启用 QSPI (Quad-SPI Flash memory)
#define HAL_QSPI_MODULE_ENABLED
// </c>

// <c> 启用 RCC (Reset and clock controller)
#define HAL_RCC_MODULE_ENABLED
// </c>

// <c> 启用 RNG (Random number generator)
#define HAL_RNG_MODULE_ENABLED
// </c>

// <c> 启用 RTC (Real-time clock)
#define HAL_RTC_MODULE_ENABLED
// </c>

// <c> 启用 SAI (Serial audio interface)
#define HAL_SAI_MODULE_ENABLED
// </c>

// <c> 启用 SMARTCARD (Smartcard IC)
#define HAL_SMARTCARD_MODULE_ENABLED
// </c>

// <c> 启用 SMBUS (System management bus)
#define HAL_SMBUS_MODULE_ENABLED
// </c>

// <c> 启用 SPI (Serial peripheral interface)
#define HAL_SPI_MODULE_ENABLED
// </c>

// <c> 启用 SRAM (SRAM external memory)
#define HAL_SRAM_MODULE_ENABLED
// </c>

// <c> 启用 TIM (Advanced-control, general-purpose or basic timer)
#define HAL_TIM_MODULE_ENABLED
// </c>

// <c> 启用 UART (Universal asynchronous receiver/transmitter)
#define HAL_UART_MODULE_ENABLED
// </c>

// <c> 启用 USART (Universal synchronous receiver/transmitter)
#define HAL_USART_MODULE_ENABLED
// </c>

// <c> 启用 WWDG (Window watchdog)
#define HAL_WWDG_MODULE_ENABLED
// </c>

// </h>

/* ########################## Oscillator Values adaptation ####################*/

// <h> 时钟设置
#if !defined(HSE_VALUE)
// <o> HSE (外部高频振荡器) 频率 单位: Hz
#define HSE_VALUE 25000000UL
#endif /* HSE_VALUE */

#if !defined(HSE_STARTUP_TIMEOUT)
// <o> HSE 启动超时时间 单位: ms
#define HSE_STARTUP_TIMEOUT 100UL
#endif /* HSE_STARTUP_TIMEOUT */

#if !defined(HSI_VALUE)
// <o> HSI (内部高频振荡器) 频率 单位: Hz
#define HSI_VALUE 16000000UL
#endif /* HSI_VALUE */

#if !defined(HSI48_VALUE)
// <o> HSI48 (内部 48 MHz) 时钟频率
// <i> 该时钟主要为 USB 和 RNG 提供一个高精度的时钟频率. 不使用 CRS 时, 该时钟运行在默认频率.
#define HSI48_VALUE 48000000UL
#endif /* HSI48_VALUE */

#if !defined(LSE_VALUE)
// <o> LSE (外部低速振荡器) 频率 单位: Hz
#define LSE_VALUE 32768UL
#endif /* LSE_VALUE */

#if !defined(LSE_STARTUP_TIMEOUT)
// <o> LSE 启动超时时间 单位: ms
#define LSE_STARTUP_TIMEOUT 5000UL
#endif /* LSE_STARTUP_TIMEOUT */

#if !defined(LSI_VALUE)
// <o> LSI (内部低速振荡器) 典型频率 单位: Hz
//  <i> LSI 受温度与电压影响很大
#define LSI_VALUE 32000UL
#endif /* LSI_VALUE */

#if !defined(EXTERNAL_CLOCK_VALUE)
// <o> 外部 I2S 时钟源频率
//  <i> I2S 计算时钟源的频率, 通过 I2S_CKIN 输入
#define EXTERNAL_CLOCK_VALUE 48000UL
#endif /* EXTERNAL_CLOCK_VALUE */

// </h>

/* Tip: To avoid modifying this file each time you need to use different HSE,
   ===  you can define the HSE value in your toolchain compiler preprocessor. */

/* ########################### System Configuration ######################### */

// <h> 系统配置

// <o> VDD 供电电压 单位: mV
#define VDD_VALUE                            3300UL
// <o> SysTick 中断优先级
#define TICK_INT_PRIORITY                    15UL
// <q> 启用 RTOS (此宏不要启用, ST 预留接口)
#define USE_RTOS                             0
// <q> 启用预读取
#define PREFETCH_ENABLE                      1
// <q> 启用指令 Cache
#define INSTRUCTION_CACHE_ENABLE             1
// <q> 启用数据 Cache
#define DATA_CACHE_ENABLE                    1
// <q> 启用 SPI CRC 校验
#define USE_SPI_CRC                          1

// </h>

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the
  *        HAL drivers code
  */

// <c> 启用断言
//#define USE_FULL_ASSERT                      1U
// </c>

/* ########################## Register Callbacks selection ############################## */

// <h> 中断回调配置

//  <q> 启用 ADC (Analog-to-digital convert) 中断注册回调函数
#define USE_HAL_ADC_REGISTER_CALLBACKS       0
//  <q> 启用 Comp (Comparator) 中断注册回调函数
#define USE_HAL_COMP_REGISTER_CALLBACKS      0
//  <q> 启用 CORDIC (Trigonometric calculation unit) 中断注册回调函数
#define USE_HAL_CORDIC_REGISTER_CALLBACKS    0
//  <q> 启用 CRYP (Cryptographic processor) 中断注册回调函数
#define USE_HAL_CRYP_REGISTER_CALLBACKS      0
//  <q> 启用 DAC (Digital to analog converter) 中断注册回调函数
#define USE_HAL_DAC_REGISTER_CALLBACKS       0
//  <q> 启用 FDCAN (Flexible data-rate controller area network unit) 中断注册回调函数
#define USE_HAL_FDCAN_REGISTER_CALLBACKS     0
//  <q> 启用 FMAC (Filtering mathematical calculation unit) 中断注册回调函数
#define USE_HAL_FMAC_REGISTER_CALLBACKS      0
//  <q> 启用 HRTIM (High-resolution timer) 中断注册回调函数
#define USE_HAL_HRTIM_REGISTER_CALLBACKS     0
//  <q> 启用 I2C (Inter-integrated circuit) 中断注册回调函数
#define USE_HAL_I2C_REGISTER_CALLBACKS       0
//  <q> 启用 I2S (Inter-integrated sound) 中断注册回调函数
#define USE_HAL_I2S_REGISTER_CALLBACKS       0
//  <q> 启用 IRDA (Infrared data association) 中断注册回调函数
#define USE_HAL_IRDA_REGISTER_CALLBACKS      0
//  <q> 启用 LPTIM (Low-power timer) 中断注册回调函数
#define USE_HAL_LPTIM_REGISTER_CALLBACKS     0
//  <q> 启用 NAND Flash 中断注册回调函数
#define USE_HAL_NAND_REGISTER_CALLBACKS      0
//  <q> 启用 Nor Flash 中断注册回调函数
#define USE_HAL_NOR_REGISTER_CALLBACKS       0
//  <q> 启用 OPAMP (Operational amplifier) 中断注册回调函数
#define USE_HAL_OPAMP_REGISTER_CALLBACKS     0
//  <q> 启用 PCD (USB peripheral controller driver) 中断注册回调函数
#define USE_HAL_PCD_REGISTER_CALLBACKS       0
//  <q> 启用 QSPI (Quad-SPI Flash memory) 中断注册回调函数
#define USE_HAL_QSPI_REGISTER_CALLBACKS      0
//  <q> 启用 RNG (Random number generator) 中断注册回调函数
#define USE_HAL_RNG_REGISTER_CALLBACKS       0
//  <q> 启用 RTC (Real-time clock) 中断注册回调函数
#define USE_HAL_RTC_REGISTER_CALLBACKS       0
//  <q> 启用 SAI (Serial audio interface) 中断注册回调函数
#define USE_HAL_SAI_REGISTER_CALLBACKS       0
//  <q> 启用 SMARTCARD (Smartcard IC) 中断注册回调函数
#define USE_HAL_SMARTCARD_REGISTER_CALLBACKS 0
//  <q> 启用 SMBUS (System management bus) 中断注册回调函数
#define USE_HAL_SMBUS_REGISTER_CALLBACKS     0
//  <q> 启用 SPI (Serial peripheral interface) 中断注册回调函数
#define USE_HAL_SPI_REGISTER_CALLBACKS       0
//  <q> 启用 SRAM (SRAM external memory) 中断注册回调函数
#define USE_HAL_SRAM_REGISTER_CALLBACKS      0
//  <q> 启用 TIM (Advanced-control, general-purpose or basic timer) 中断注册回调函数
#define USE_HAL_TIM_REGISTER_CALLBACKS       0
//  <q> 启用 UART (Universal asynchronous receiver/transmitter) 中断注册回调函数
#define USE_HAL_UART_REGISTER_CALLBACKS      0
//  <q> 启用 USART (Universal synchronous receiver/transmitter) 中断注册回调函数
#define USE_HAL_USART_REGISTER_CALLBACKS     0
//  <q> 启用 WWDG (Window watchdog) 中断注册回调函数
#define USE_HAL_WWDG_REGISTER_CALLBACKS      0

// </h>

/* Includes ------------------------------------------------------------------*/
/**
  * @brief Include module's header file
  */

#ifdef HAL_RCC_MODULE_ENABLED
#include "stm32g4xx_hal_rcc.h"
#endif /* HAL_RCC_MODULE_ENABLED */

#ifdef HAL_GPIO_MODULE_ENABLED
#include "stm32g4xx_hal_gpio.h"
#endif /* HAL_GPIO_MODULE_ENABLED */

#ifdef HAL_DMA_MODULE_ENABLED
#include "stm32g4xx_hal_dma.h"
#endif /* HAL_DMA_MODULE_ENABLED */

#ifdef HAL_CORTEX_MODULE_ENABLED
#include "stm32g4xx_hal_cortex.h"
#endif /* HAL_CORTEX_MODULE_ENABLED */

#ifdef HAL_ADC_MODULE_ENABLED
#include "stm32g4xx_hal_adc.h"
#endif /* HAL_ADC_MODULE_ENABLED */

#ifdef HAL_COMP_MODULE_ENABLED
#include "stm32g4xx_hal_comp.h"
#endif /* HAL_COMP_MODULE_ENABLED */

#ifdef HAL_CORDIC_MODULE_ENABLED
#include "stm32g4xx_hal_cordic.h"
#endif /* HAL_CORDIC_MODULE_ENABLED */

#ifdef HAL_CRC_MODULE_ENABLED
#include "stm32g4xx_hal_crc.h"
#endif /* HAL_CRC_MODULE_ENABLED */

#ifdef HAL_CRYP_MODULE_ENABLED
#include "stm32g4xx_hal_cryp.h"
#endif /* HAL_CRYP_MODULE_ENABLED */

#ifdef HAL_DAC_MODULE_ENABLED
#include "stm32g4xx_hal_dac.h"
#endif /* HAL_DAC_MODULE_ENABLED */

#ifdef HAL_EXTI_MODULE_ENABLED
#include "stm32g4xx_hal_exti.h"
#endif /* HAL_EXTI_MODULE_ENABLED */

#ifdef HAL_FDCAN_MODULE_ENABLED
#include "stm32g4xx_hal_fdcan.h"
#endif /* HAL_FDCAN_MODULE_ENABLED */

#ifdef HAL_FLASH_MODULE_ENABLED
#include "stm32g4xx_hal_flash.h"
#endif /* HAL_FLASH_MODULE_ENABLED */

#ifdef HAL_FMAC_MODULE_ENABLED
#include "stm32g4xx_hal_fmac.h"
#endif /* HAL_FMAC_MODULE_ENABLED */

#ifdef HAL_HRTIM_MODULE_ENABLED
#include "stm32g4xx_hal_hrtim.h"
#endif /* HAL_HRTIM_MODULE_ENABLED */

#ifdef HAL_IRDA_MODULE_ENABLED
#include "stm32g4xx_hal_irda.h"
#endif /* HAL_IRDA_MODULE_ENABLED */

#ifdef HAL_IWDG_MODULE_ENABLED
#include "stm32g4xx_hal_iwdg.h"
#endif /* HAL_IWDG_MODULE_ENABLED */

#ifdef HAL_I2C_MODULE_ENABLED
#include "stm32g4xx_hal_i2c.h"
#endif /* HAL_I2C_MODULE_ENABLED */

#ifdef HAL_I2S_MODULE_ENABLED
#include "stm32g4xx_hal_i2s.h"
#endif /* HAL_I2S_MODULE_ENABLED */

#ifdef HAL_LPTIM_MODULE_ENABLED
#include "stm32g4xx_hal_lptim.h"
#endif /* HAL_LPTIM_MODULE_ENABLED */

#ifdef HAL_NAND_MODULE_ENABLED
#include "stm32g4xx_hal_nand.h"
#endif /* HAL_NAND_MODULE_ENABLED */

#ifdef HAL_NOR_MODULE_ENABLED
#include "stm32g4xx_hal_nor.h"
#endif /* HAL_NOR_MODULE_ENABLED */

#ifdef HAL_OPAMP_MODULE_ENABLED
#include "stm32g4xx_hal_opamp.h"
#endif /* HAL_OPAMP_MODULE_ENABLED */

#ifdef HAL_PCD_MODULE_ENABLED
#include "stm32g4xx_hal_pcd.h"
#endif /* HAL_PCD_MODULE_ENABLED */

#ifdef HAL_PWR_MODULE_ENABLED
#include "stm32g4xx_hal_pwr.h"
#endif /* HAL_PWR_MODULE_ENABLED */

#ifdef HAL_QSPI_MODULE_ENABLED
#include "stm32g4xx_hal_qspi.h"
#endif /* HAL_QSPI_MODULE_ENABLED */

#ifdef HAL_RNG_MODULE_ENABLED
#include "stm32g4xx_hal_rng.h"
#endif /* HAL_RNG_MODULE_ENABLED */

#ifdef HAL_RTC_MODULE_ENABLED
#include "stm32g4xx_hal_rtc.h"
#endif /* HAL_RTC_MODULE_ENABLED */

#ifdef HAL_SAI_MODULE_ENABLED
#include "stm32g4xx_hal_sai.h"
#endif /* HAL_SAI_MODULE_ENABLED */

#ifdef HAL_SMARTCARD_MODULE_ENABLED
#include "stm32g4xx_hal_smartcard.h"
#endif /* HAL_SMARTCARD_MODULE_ENABLED */

#ifdef HAL_SMBUS_MODULE_ENABLED
#include "stm32g4xx_hal_smbus.h"
#endif /* HAL_SMBUS_MODULE_ENABLED */

#ifdef HAL_SPI_MODULE_ENABLED
#include "stm32g4xx_hal_spi.h"
#endif /* HAL_SPI_MODULE_ENABLED */

#ifdef HAL_SRAM_MODULE_ENABLED
#include "stm32g4xx_hal_sram.h"
#endif /* HAL_SRAM_MODULE_ENABLED */

#ifdef HAL_TIM_MODULE_ENABLED
#include "stm32g4xx_hal_tim.h"
#endif /* HAL_TIM_MODULE_ENABLED */

#ifdef HAL_UART_MODULE_ENABLED
#include "stm32g4xx_hal_uart.h"
#endif /* HAL_UART_MODULE_ENABLED */

#ifdef HAL_USART_MODULE_ENABLED
#include "stm32g4xx_hal_usart.h"
#endif /* HAL_USART_MODULE_ENABLED */

#ifdef HAL_WWDG_MODULE_ENABLED
#include "stm32g4xx_hal_wwdg.h"
#endif /* HAL_WWDG_MODULE_ENABLED */

/* Exported macro ------------------------------------------------------------*/
#ifdef USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *         which reports the name of the source file and the source
  *         line number of the call that failed.
  *         If expr is true, it returns no value.
  * @retval None
  */
#define assert_param(expr)                                                     \
    ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t *file, uint32_t line);
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
}
#endif

#endif /* STM32G4xx_HAL_CONF_H */
