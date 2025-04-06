/**
  ******************************************************************************
  * @file    stm32h7xx_hal_conf.h
  * @author  MCD Application Team
  * @brief   HAL configuration file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32H7xx_HAL_CONF_H
#define STM32H7xx_HAL_CONF_H

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

// <c> 启用 CEC (Consumer electronic controller)
#define HAL_CEC_MODULE_ENABLED
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

// <c> 启用 DCMI (Digital camera interface)
#define HAL_DCMI_MODULE_ENABLED
// </c>

// <c> 启用 DFSDM (Digital filter sigma delta modulator)
#define HAL_DFSDM_MODULE_ENABLED
// </c>

// <c> 启用 DMA (Digital filter sigma delta modulator)
#define HAL_DMA_MODULE_ENABLED
// </c>

// <c> 启用 DMA2D
#define HAL_DMA2D_MODULE_ENABLED
// </c>

// <c> 启用 DTS (Digital temperature sensor)
#define HAL_DTS_MODULE_ENABLED
// </c>

// <c> 启用 DSI (Display serial interface)
#define HAL_DSI_MODULE_ENABLED
// </c>

// <c> 启用 ETH (Ethernet controller)
#define HAL_ETH_MODULE_ENABLED
// </c>

// <c> 启用旧版 ETH (Ethernet controller)
// #define HAL_ETH_LEGACY_MODULE_ENABLED
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

// <c> 启用 GFXMMU (Chrom-GRC)
#define HAL_GFXMMU_MODULE_ENABLED
// </c>

// <c> 启用 FMAC (Filtering mathematical calculation unit)
#define HAL_FMAC_MODULE_ENABLED
// </c>

// <c> 启用 GPIO (General purpose I/Os)
#define HAL_GPIO_MODULE_ENABLED
// </c>

// <c> 启用 HASH (Hash processor)
#define HAL_HASH_MODULE_ENABLED
// </c>

// <c> 启用 HCD (USB host controller driver)
#define HAL_HCD_MODULE_ENABLED
// </c>

// <c> 启用 HRTIM (High-resolution timer)
#define HAL_HRTIM_MODULE_ENABLED
// </c>

// <c> 启用 HSEM (Hardware semaphore)
#define HAL_HSEM_MODULE_ENABLED
// </c>

// <c> 启用 I2C (Inter-integrated circuit)
#define HAL_I2C_MODULE_ENABLED
// </c>

// <c> 启用 I2S (Inter-integrated sound)
#define HAL_I2S_MODULE_ENABLED
// </c>

// <c> 启用 IRDA (Infrared data association)
#define HAL_IRDA_MODULE_ENABLED
// </c>

// <c> 启用 IWDG (Independent watchdog)
#define HAL_IWDG_MODULE_ENABLED
// </c>

// <c> 启用 JPEG (Joint photographic experts group)
#define HAL_JPEG_MODULE_ENABLED
// </c>

// <c> 启用 LPTIM (Low-power timer)
#define HAL_LPTIM_MODULE_ENABLED
// </c>

// <c> 启用 LTDC (LCD TFT display controller)
#define HAL_LTDC_MODULE_ENABLED
// </c>

// <c> 启用 MDIOS (Management data input/output (MDIO) slave)
#define HAL_MDIOS_MODULE_ENABLED
// </c>

// <c> 启用 MDMA (Master direct memory access)
#define HAL_MDMA_MODULE_ENABLED
// </c>

// <c> 启用 MMC (MultiMediaCard)
#define HAL_MMC_MODULE_ENABLED
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

// <c> 启用 OSPI (Octo-SPI interface)
#define HAL_OSPI_MODULE_ENABLED
// </c>

// <c> 启用 OTFDEC (On-the-fly decryption engine)
#define HAL_OTFDEC_MODULE_ENABLED
// </c>

// <c> 启用 PCD (USB peripheral controller driver)
#define HAL_PCD_MODULE_ENABLED
// </c>

// <c> 启用 PWR (Power controller)
#define HAL_PWR_MODULE_ENABLED
// </c>

// <c> 启用 PSSI (Parallel synchronous slave interface)
#define HAL_PSSI_MODULE_ENABLED
// </c>

// <c> 启用 QSPI (Quad-SPI Flash memory)
#define HAL_QSPI_MODULE_ENABLED
// </c>

// <c> 启用 RAMECC (RAM ECC monitoring)
#define HAL_RAMECC_MODULE_ENABLED
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

// <c> 启用 SD (Secure digital)
#define HAL_SD_MODULE_ENABLED
// </c>

// <c> 启用 SDIO (Secure Digital Input Output)
#define HAL_SDIO_MODULE_ENABLED

// <c> 启用 SDRAM (Synchronous dynamic RAM)
#define HAL_SDRAM_MODULE_ENABLED
// </c>

// <c> 启用 SMARTCARD (Smartcard IC)
#define HAL_SMARTCARD_MODULE_ENABLED
// </c>

// <c> 启用 SMBUS (System management bus)
#define HAL_SMBUS_MODULE_ENABLED
// </c>

// <c> 启用 SPDIFRX (SPDIF-RX Receiver interface)
#define HAL_SPDIFRX_MODULE_ENABLED
// </c>

// <c> 启用 SPI (Serial peripheral interface)
#define HAL_SPI_MODULE_ENABLED
// </c>

// <c> 启用 SRAM (SRAM external memory)
#define HAL_SRAM_MODULE_ENABLED
// </c>

// <c> 启用 SWPMI (Serial wire protocol master interface)
#define HAL_SWPMI_MODULE_ENABLED
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

/**
  * @brief Internal  oscillator (CSI) default value.
  *        This value is the default CSI value after Reset.
  */
#if !defined(CSI_VALUE)
// <o> CSI (内部晶振振荡器) 频率 单位: Hz
#define CSI_VALUE 4000000UL
#endif /* CSI_VALUE */

#if !defined(HSI_VALUE)
// <o> HSI (内部高频振荡器) 频率 单位: Hz
#define HSI_VALUE 64000000UL
#endif /* HSI_VALUE */

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
#define EXTERNAL_CLOCK_VALUE 12288000UL
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
// <q> 启用 SD 收发
#define USE_SD_TRANSCEIVER                   0U
// <q> 启用 SPI CRC 校验
#define USE_SPI_CRC                          1U
// <q> 启用 Flash ECC
#define USE_FLASH_ECC                        0U
// <q> 启用 SDIO 收发
#define USE_SDIO_TRANSCEIVER                 0U
// <o> SDIO 最大 IO 数量
#define SDIO_MAX_IO_NUMBER                   7U

// </h>

// <h> 中断回调配置

//  <q> 启用 ADC (Analog-to-digital convert) 中断注册回调函数
#define USE_HAL_ADC_REGISTER_CALLBACKS       0
//  <q> 启用 CEC (Consumer electronic controller) 中断注册回调函数
#define USE_HAL_CEC_REGISTER_CALLBACKS       0
//  <q> 启用 Comp (Comparator) 中断注册回调函数
#define USE_HAL_COMP_REGISTER_CALLBACKS      0
//  <q> 启用 CORDIC (Trigonometric calculation unit) 中断注册回调函数
#define USE_HAL_CORDIC_REGISTER_CALLBACKS    0
//  <q> 启用 CRYP (Cryptographic processor) 中断注册回调函数
#define USE_HAL_CRYP_REGISTER_CALLBACKS      0
//  <q> 启用 DAC (Digital to analog converter) 中断注册回调函数
#define USE_HAL_DAC_REGISTER_CALLBACKS       0
//  <q> 启用 DCMI (Digital camera interface) 中断注册回调函数
#define USE_HAL_DCMI_REGISTER_CALLBACKS      0
//  <q> 启用 DFSDM (Digital filter sigma delta modulator) 中断注册回调函数
#define USE_HAL_DFSDM_REGISTER_CALLBACKS     0
//  <q> 启用 DMA2D 中断注册回调函数
#define USE_HAL_DMA2D_REGISTER_CALLBACKS     0
//  <q> 启用 DSI (Display serial interface) 中断注册回调函数
#define USE_HAL_DSI_REGISTER_CALLBACKS       0
//  <q> 启用 DTS (Digital temperature sensor) 中断注册回调函数
#define USE_HAL_DTS_REGISTER_CALLBACKS       0
//  <q> 启用 ETH (Ethernet controller) 中断注册回调函数
#define USE_HAL_ETH_REGISTER_CALLBACKS       0
//  <q> 启用 FDCAN (Flexible data-rate controller area network unit) 中断注册回调函数
#define USE_HAL_FDCAN_REGISTER_CALLBACKS     0
//  <q> 启用 FMAC (Filtering mathematical calculation unit) 中断注册回调函数
#define USE_HAL_FMAC_REGISTER_CALLBACKS      0
//  <q> 启用 NAND Flash 中断注册回调函数
#define USE_HAL_NAND_REGISTER_CALLBACKS      0
//  <q> 启用 Nor Flash 中断注册回调函数
#define USE_HAL_NOR_REGISTER_CALLBACKS       0
//  <q> 启用 SDRAM (Synchronous dynamic RAM) 中断注册回调函数
#define USE_HAL_SDRAM_REGISTER_CALLBACKS     0
//  <q> 启用 SRAM (SRAM external memory) 中断注册回调函数
#define USE_HAL_SRAM_REGISTER_CALLBACKS      0
//  <q> 启用 HASH (Hash processor) 中断注册回调函数
#define USE_HAL_HASH_REGISTER_CALLBACKS      0
//  <q> 启用 HCD (USB host controller driver) 中断注册回调函数
#define USE_HAL_HCD_REGISTER_CALLBACKS       0
//  <q> 启用 GFXMMU (Chrom-GRC) 中断注册回调函数
#define USE_HAL_GFXMMU_REGISTER_CALLBACKS    0
//  <q> 启用 HRTIM (High-resolution timer) 中断注册回调函数
#define USE_HAL_HRTIM_REGISTER_CALLBACKS     0
//  <q> 启用 I2C (Inter-integrated circuit) 中断注册回调函数
#define USE_HAL_I2C_REGISTER_CALLBACKS       0
//  <q> 启用 I2S (Inter-integrated sound) 中断注册回调函数
#define USE_HAL_I2S_REGISTER_CALLBACKS       0
//  <q> 启用 IRDA (Infrared data association) 中断注册回调函数
#define USE_HAL_IRDA_REGISTER_CALLBACKS      0
//  <q> 启用 JPEG (Joint photographic experts group) 中断注册回调函数
#define USE_HAL_JPEG_REGISTER_CALLBACKS      0
//  <q> 启用 LPTIM (Low-power timer) 中断注册回调函数
#define USE_HAL_LPTIM_REGISTER_CALLBACKS     0
//  <q> 启用 LTDC (LCD TFT display controller) 中断注册回调函数
#define USE_HAL_LTDC_REGISTER_CALLBACKS      0
//  <q> 启用 MDIOS (Management data input/output (MDIO) slave) 中断注册回调函数
#define USE_HAL_MDIOS_REGISTER_CALLBACKS     0
//  <q> 启用 MMC (MultiMediaCard) 中断注册回调函数
#define USE_HAL_MMC_REGISTER_CALLBACKS       0
//  <q> 启用 OPAMP (Operational amplifier) 中断注册回调函数
#define USE_HAL_OPAMP_REGISTER_CALLBACKS     0
//  <q> 启用 OSPI (Octo-SPI interface) 中断注册回调函数
#define USE_HAL_OSPI_REGISTER_CALLBACKS      0
//  <q> 启用 OTFDEC (On-the-fly decryption engine) 中断注册回调函数
#define USE_HAL_OTFDEC_REGISTER_CALLBACKS    0
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
//  <q> 启用 SD (Secure digital) 中断注册回调函数
#define USE_HAL_SD_REGISTER_CALLBACKS        0
//  <q> 启用 SDIO (Secure Digital Input Output) 中断注册回调函数
#define USE_HAL_SDIO_REGISTER_CALLBACKS      0
//  <q> 启用 SMARTCARD (Smartcard IC) 中断注册回调函数
#define USE_HAL_SMARTCARD_REGISTER_CALLBACKS 0
//  <q> 启用 SPDIFRX (SPDIF-RX Receiver interface) 中断注册回调函数
#define USE_HAL_SPDIFRX_REGISTER_CALLBACKS   0
//  <q> 启用 SMBUS (System management bus) 中断注册回调函数
#define USE_HAL_SMBUS_REGISTER_CALLBACKS     0
//  <q> 启用 SPI (Serial peripheral interface) 中断注册回调函数
#define USE_HAL_SPI_REGISTER_CALLBACKS       0
//  <q> 启用 SWPMI (Serial wire protocol master interface) 中断注册回调函数
#define USE_HAL_SWPMI_REGISTER_CALLBACKS     0
//  <q> 启用 TIM (Advanced-control, general-purpose or basic timer) 中断注册回调函数
#define USE_HAL_TIM_REGISTER_CALLBACKS       0
//  <q> 启用 UART (Universal asynchronous receiver/transmitter) 中断注册回调函数
#define USE_HAL_UART_REGISTER_CALLBACKS      0
//  <q> 启用 USART (Universal synchronous receiver/transmitter) 中断注册回调函数
#define USE_HAL_USART_REGISTER_CALLBACKS     0
//  <q> 启用 WWDG (Window watchdog) 中断注册回调函数
#define USE_HAL_WWDG_REGISTER_CALLBACKS      0

// </h>

/* ########################### Ethernet Configuration ######################### */

// <h> 以太网配置

// <o> 发送描述包数量
#define ETH_TX_DESC_CNT                      4 /* number of Ethernet Tx DMA descriptors */
// <o> 接收描述包数量
#define ETH_RX_DESC_CNT                      4 /* number of Ethernet Rx DMA descriptors */

// <o> MAC 地址 0
#define ETH_MAC_ADDR0                        0x02
// <o> MAC 地址 1
#define ETH_MAC_ADDR1                        0x44UL
// <o> MAC 地址 2
#define ETH_MAC_ADDR2                        0x00UL
// <o> MAC 地址 3
#define ETH_MAC_ADDR3                        0x00UL
// <o> MAC 地址 4
#define ETH_MAC_ADDR4                        0x00UL
// <o> MAC 地址 5
#define ETH_MAC_ADDR5                        0x00UL

// </h>

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the
  *        HAL drivers code
  */

// <c> 启用断言
//#define USE_FULL_ASSERT                      1U
// </c>

//------------- <<< end of configuration section >>> ---------------------------

/* Includes ------------------------------------------------------------------*/
/**
  * @brief Include module's header file
  */

#ifdef HAL_RCC_MODULE_ENABLED
#include "stm32h7xx_hal_rcc.h"
#endif /* HAL_RCC_MODULE_ENABLED */

#ifdef HAL_GPIO_MODULE_ENABLED
#include "stm32h7xx_hal_gpio.h"
#endif /* HAL_GPIO_MODULE_ENABLED */

#ifdef HAL_DMA_MODULE_ENABLED
#include "stm32h7xx_hal_dma.h"
#endif /* HAL_DMA_MODULE_ENABLED */

#ifdef HAL_MDMA_MODULE_ENABLED
#include "stm32h7xx_hal_mdma.h"
#endif /* HAL_MDMA_MODULE_ENABLED */

#ifdef HAL_HASH_MODULE_ENABLED
#include "stm32h7xx_hal_hash.h"
#endif /* HAL_HASH_MODULE_ENABLED */

#ifdef HAL_DCMI_MODULE_ENABLED
#include "stm32h7xx_hal_dcmi.h"
#endif /* HAL_DCMI_MODULE_ENABLED */

#ifdef HAL_DMA2D_MODULE_ENABLED
#include "stm32h7xx_hal_dma2d.h"
#endif /* HAL_DMA2D_MODULE_ENABLED */

#ifdef HAL_DSI_MODULE_ENABLED
#include "stm32h7xx_hal_dsi.h"
#endif /* HAL_DSI_MODULE_ENABLED */

#ifdef HAL_DFSDM_MODULE_ENABLED
#include "stm32h7xx_hal_dfsdm.h"
#endif /* HAL_DFSDM_MODULE_ENABLED */

#ifdef HAL_DTS_MODULE_ENABLED
#include "stm32h7xx_hal_dts.h"
#endif /* HAL_DTS_MODULE_ENABLED */

#ifdef HAL_ETH_MODULE_ENABLED
#include "stm32h7xx_hal_eth.h"
#endif /* HAL_ETH_MODULE_ENABLED */

#ifdef HAL_EXTI_MODULE_ENABLED
#include "stm32h7xx_hal_exti.h"
#endif /* HAL_EXTI_MODULE_ENABLED */

#ifdef HAL_CORTEX_MODULE_ENABLED
#include "stm32h7xx_hal_cortex.h"
#endif /* HAL_CORTEX_MODULE_ENABLED */

#ifdef HAL_ADC_MODULE_ENABLED
#include "stm32h7xx_hal_adc.h"
#endif /* HAL_ADC_MODULE_ENABLED */

#ifdef HAL_FDCAN_MODULE_ENABLED
#include "stm32h7xx_hal_fdcan.h"
#endif /* HAL_FDCAN_MODULE_ENABLED */

#ifdef HAL_CEC_MODULE_ENABLED
#include "stm32h7xx_hal_cec.h"
#endif /* HAL_CEC_MODULE_ENABLED */

#ifdef HAL_COMP_MODULE_ENABLED
#include "stm32h7xx_hal_comp.h"
#endif /* HAL_COMP_MODULE_ENABLED */

#ifdef HAL_CORDIC_MODULE_ENABLED
#include "stm32h7xx_hal_cordic.h"
#endif /* HAL_CORDIC_MODULE_ENABLED */

#ifdef HAL_CRC_MODULE_ENABLED
#include "stm32h7xx_hal_crc.h"
#endif /* HAL_CRC_MODULE_ENABLED */

#ifdef HAL_CRYP_MODULE_ENABLED
#include "stm32h7xx_hal_cryp.h"
#endif /* HAL_CRYP_MODULE_ENABLED */

#ifdef HAL_DAC_MODULE_ENABLED
#include "stm32h7xx_hal_dac.h"
#endif /* HAL_DAC_MODULE_ENABLED */

#ifdef HAL_FLASH_MODULE_ENABLED
#include "stm32h7xx_hal_flash.h"
#endif /* HAL_FLASH_MODULE_ENABLED */

#ifdef HAL_GFXMMU_MODULE_ENABLED
#include "stm32h7xx_hal_gfxmmu.h"
#endif /* HAL_GFXMMU_MODULE_ENABLED */

#ifdef HAL_FMAC_MODULE_ENABLED
#include "stm32h7xx_hal_fmac.h"
#endif /* HAL_FMAC_MODULE_ENABLED */

#ifdef HAL_HRTIM_MODULE_ENABLED
#include "stm32h7xx_hal_hrtim.h"
#endif /* HAL_HRTIM_MODULE_ENABLED */

#ifdef HAL_HSEM_MODULE_ENABLED
#include "stm32h7xx_hal_hsem.h"
#endif /* HAL_HSEM_MODULE_ENABLED */

#ifdef HAL_SRAM_MODULE_ENABLED
#include "stm32h7xx_hal_sram.h"
#endif /* HAL_SRAM_MODULE_ENABLED */

#ifdef HAL_NOR_MODULE_ENABLED
#include "stm32h7xx_hal_nor.h"
#endif /* HAL_NOR_MODULE_ENABLED */

#ifdef HAL_NAND_MODULE_ENABLED
#include "stm32h7xx_hal_nand.h"
#endif /* HAL_NAND_MODULE_ENABLED */

#ifdef HAL_I2C_MODULE_ENABLED
#include "stm32h7xx_hal_i2c.h"
#endif /* HAL_I2C_MODULE_ENABLED */

#ifdef HAL_I2S_MODULE_ENABLED
#include "stm32h7xx_hal_i2s.h"
#endif /* HAL_I2S_MODULE_ENABLED */

#ifdef HAL_IWDG_MODULE_ENABLED
#include "stm32h7xx_hal_iwdg.h"
#endif /* HAL_IWDG_MODULE_ENABLED */

#ifdef HAL_JPEG_MODULE_ENABLED
#include "stm32h7xx_hal_jpeg.h"
#endif /* HAL_JPEG_MODULE_ENABLED */

#ifdef HAL_MDIOS_MODULE_ENABLED
#include "stm32h7xx_hal_mdios.h"
#endif /* HAL_MDIOS_MODULE_ENABLED */

#ifdef HAL_MMC_MODULE_ENABLED
#include "stm32h7xx_hal_mmc.h"
#endif /* HAL_MMC_MODULE_ENABLED */

#ifdef HAL_LPTIM_MODULE_ENABLED
#include "stm32h7xx_hal_lptim.h"
#endif /* HAL_LPTIM_MODULE_ENABLED */

#ifdef HAL_LTDC_MODULE_ENABLED
#include "stm32h7xx_hal_ltdc.h"
#endif /* HAL_LTDC_MODULE_ENABLED */

#ifdef HAL_OPAMP_MODULE_ENABLED
#include "stm32h7xx_hal_opamp.h"
#endif /* HAL_OPAMP_MODULE_ENABLED */

#ifdef HAL_OSPI_MODULE_ENABLED
#include "stm32h7xx_hal_ospi.h"
#endif /* HAL_OSPI_MODULE_ENABLED */

#ifdef HAL_OTFDEC_MODULE_ENABLED
#include "stm32h7xx_hal_otfdec.h"
#endif /* HAL_OTFDEC_MODULE_ENABLED */

#ifdef HAL_PSSI_MODULE_ENABLED
#include "stm32h7xx_hal_pssi.h"
#endif /* HAL_PSSI_MODULE_ENABLED */

#ifdef HAL_PWR_MODULE_ENABLED
#include "stm32h7xx_hal_pwr.h"
#endif /* HAL_PWR_MODULE_ENABLED */

#ifdef HAL_QSPI_MODULE_ENABLED
#include "stm32h7xx_hal_qspi.h"
#endif /* HAL_QSPI_MODULE_ENABLED */

#ifdef HAL_RAMECC_MODULE_ENABLED
#include "stm32h7xx_hal_ramecc.h"
#endif /* HAL_RAMECC_MODULE_ENABLED */

#ifdef HAL_RNG_MODULE_ENABLED
#include "stm32h7xx_hal_rng.h"
#endif /* HAL_RNG_MODULE_ENABLED */

#ifdef HAL_RTC_MODULE_ENABLED
#include "stm32h7xx_hal_rtc.h"
#endif /* HAL_RTC_MODULE_ENABLED */

#ifdef HAL_SAI_MODULE_ENABLED
#include "stm32h7xx_hal_sai.h"
#endif /* HAL_SAI_MODULE_ENABLED */

#ifdef HAL_SD_MODULE_ENABLED
#include "stm32h7xx_hal_sd.h"
#endif /* HAL_SD_MODULE_ENABLED */

#ifdef HAL_SDRAM_MODULE_ENABLED
#include "stm32h7xx_hal_sdram.h"
#endif /* HAL_SDRAM_MODULE_ENABLED */

#ifdef HAL_SPI_MODULE_ENABLED
#include "stm32h7xx_hal_spi.h"
#endif /* HAL_SPI_MODULE_ENABLED */

#ifdef HAL_SPDIFRX_MODULE_ENABLED
#include "stm32h7xx_hal_spdifrx.h"
#endif /* HAL_SPDIFRX_MODULE_ENABLED */

#ifdef HAL_SWPMI_MODULE_ENABLED
#include "stm32h7xx_hal_swpmi.h"
#endif /* HAL_SWPMI_MODULE_ENABLED */

#ifdef HAL_TIM_MODULE_ENABLED
#include "stm32h7xx_hal_tim.h"
#endif /* HAL_TIM_MODULE_ENABLED */

#ifdef HAL_UART_MODULE_ENABLED
#include "stm32h7xx_hal_uart.h"
#endif /* HAL_UART_MODULE_ENABLED */

#ifdef HAL_USART_MODULE_ENABLED
#include "stm32h7xx_hal_usart.h"
#endif /* HAL_USART_MODULE_ENABLED */

#ifdef HAL_IRDA_MODULE_ENABLED
#include "stm32h7xx_hal_irda.h"
#endif /* HAL_IRDA_MODULE_ENABLED */

#ifdef HAL_SMARTCARD_MODULE_ENABLED
#include "stm32h7xx_hal_smartcard.h"
#endif /* HAL_SMARTCARD_MODULE_ENABLED */

#ifdef HAL_SMBUS_MODULE_ENABLED
#include "stm32h7xx_hal_smbus.h"
#endif /* HAL_SMBUS_MODULE_ENABLED */

#ifdef HAL_WWDG_MODULE_ENABLED
#include "stm32h7xx_hal_wwdg.h"
#endif /* HAL_WWDG_MODULE_ENABLED */

#ifdef HAL_PCD_MODULE_ENABLED
#include "stm32h7xx_hal_pcd.h"
#endif /* HAL_PCD_MODULE_ENABLED */

#ifdef HAL_HCD_MODULE_ENABLED
#include "stm32h7xx_hal_hcd.h"
#endif /* HAL_HCD_MODULE_ENABLED */

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

#endif /* STM32H7xx_HAL_CONF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
