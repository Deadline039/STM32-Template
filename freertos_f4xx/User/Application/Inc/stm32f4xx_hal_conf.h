/**
  ******************************************************************************
  * @file    stm32f4xx_hal_conf_template.h
  * @author  MCD Application Team
  * @brief   HAL configuration template file. 
  *          This file should be copied to the application folder and renamed
  *          to stm32f4xx_hal_conf.h.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_HAL_CONF_H
#define __STM32F4xx_HAL_CONF_H

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

// <c> 启用 CAN (Controller area network)
#define HAL_CAN_MODULE_ENABLED
// </c>

// <c> 启用旧版 CAN (Controller area network)
// #define HAL_CAN_LEGACY_MODULE_ENABLED
// </c>

// <c> 启用 CEC (Consumer electronic controller)
#define HAL_CEC_MODULE_ENABLED
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

// <c> 启用 DMA (Direct memory access)
#define HAL_DMA_MODULE_ENABLED
// </c>

// <c> 启用 DMA2D
#define HAL_DMA2D_MODULE_ENABLED
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

// <c> 启用 FLASH (Flash memory)
#define HAL_FLASH_MODULE_ENABLED
// </c>

// <c> 启用 NAND (NAND Flash memory)
#define HAL_NAND_MODULE_ENABLED
// </c>

// <c> 启用 NOR (NOR Flash memory)
#define HAL_NOR_MODULE_ENABLED
// </c>

// <c> 启用 PCCARD (PC Card interface)
#define HAL_PCD_MODULE_ENABLED
// </c>

// <c> 启用 SRAM (SRAM external memory)
#define HAL_SRAM_MODULE_ENABLED
// </c>

// <c> 启用 SDRAM (Synchronous dynamic RAM)
#define HAL_SDRAM_MODULE_ENABLED
// </c>

// <c> 启用 GPIO (General purpose I/Os)
#define HAL_GPIO_MODULE_ENABLED
// </c>

// <c> 启用 HASH (Hash processor)
#define HAL_HASH_MODULE_ENABLED
// </c>

// <c> 启用 I2C (Inter-integrated circuit)
#define HAL_I2C_MODULE_ENABLED
// </c>

// <c> 启用 I2S (Inter-integrated sound)
#define HAL_I2S_MODULE_ENABLED
// </c>

// <c> 启用 SMBUS (System management bus)
#define HAL_SMBUS_MODULE_ENABLED
// </c>

// <c> 启用 IWDG (Independent watchdog)
#define HAL_IWDG_MODULE_ENABLED
// </c>

// <c> 启用 LTDC (LCD TFT display controller)
#define HAL_LTDC_MODULE_ENABLED
// </c>

// <c> 启用 DSI (Display serial interface)
#define HAL_DSI_MODULE_ENABLED
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

// <c> 启用 SD (Secure digital)
#define HAL_SD_MODULE_ENABLED
// </c>

// <c> 启用 SPI (Serial peripheral interface)
#define HAL_SPI_MODULE_ENABLED
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

// <c> 启用 IRDA (Infrared data association)
#define HAL_IRDA_MODULE_ENABLED
// </c>

// <c> 启用 SMARTCARD (Smartcard IC)
#define HAL_SMARTCARD_MODULE_ENABLED
// </c>

// <c> 启用 WWDG (Window watchdog)
#define HAL_WWDG_MODULE_ENABLED
// </c>

// <c> 启用 PCD (USB peripheral controller driver)
#define HAL_PCD_MODULE_ENABLED
// </c>

// <c> 启用 HCD (USB host controller driver)
#define HAL_HCD_MODULE_ENABLED
// </c>

// <c> 启用 FMPI2C (Fast-mode Plus Inter-integrated circuit)
#define HAL_FMPI2C_MODULE_ENABLED
// </c>

// <c> 启用 FMPSMBUS (Fast-mode Plus System Management Bus)
#define HAL_FMPSMBUS_MODULE_ENABLED
// </c>

// <c> 启用 SPDIFRX (SPDIF-RX Receiver interface)
#define HAL_SPDIFRX_MODULE_ENABLED
// </c>

// <c> 启用 DFSDM (Digital filter sigma delta modulator)
#define HAL_DFSDM_MODULE_ENABLED
// </c>

// <c> 启用 LPTIM (Low-power timer)
#define HAL_LPTIM_MODULE_ENABLED
// </c>

// <c> 启用 MMC (MultiMediaCard)
#define HAL_MMC_MODULE_ENABLED
// </c>

// </h>

/* ########################## HSE/HSI Values adaptation ##################### */

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

#if !defined(LSE_STARTUP_TIMEOUT)
#define LSE_STARTUP_TIMEOUT 5000U /*!< Time out for LSE start up, in ms */
#endif                            /* LSE_STARTUP_TIMEOUT */

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
// <q> 启用预读取
#define PREFETCH_ENABLE                      1
// <q> 启用指令 Cache
#define INSTRUCTION_CACHE_ENABLE             1
// <q> 启用数据 Cache
#define DATA_CACHE_ENABLE                    1
// <q> 启用 SPI CRC 校验
#define USE_SPI_CRC                          1

// </h>

/* ########################## Register Callbacks selection ############################## */

// <h> 中断回调配置

//  <q> 启用 ADC (Analog-to-digital convert) 中断注册回调函数
#define USE_HAL_ADC_REGISTER_CALLBACKS       0
//  <q> 启用 CAN (Controller area network) 中断注册回调函数
#define USE_HAL_CAN_REGISTER_CALLBACKS       0
//  <q> 启用 CEC (Consumer electronic controller) 中断注册回调函数
#define USE_HAL_CEC_REGISTER_CALLBACKS       0
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
//  <q> 启用 ETH (Ethernet controller) 中断注册回调函数
#define USE_HAL_ETH_REGISTER_CALLBACKS       0
//  <q> 启用 HASH (Hash processor) 中断注册回调函数
#define USE_HAL_HASH_REGISTER_CALLBACKS      0
//  <q> 启用 HCD (USB host controller driver) 中断注册回调函数
#define USE_HAL_HCD_REGISTER_CALLBACKS       0
//  <q> 启用 I2C (Inter-integrated circuit) 中断注册回调函数
#define USE_HAL_I2C_REGISTER_CALLBACKS       0
//  <q> 启用 FMPI2C (Fast-mode Plus Inter-integrated circuit) 中断注册回调函数
#define USE_HAL_FMPI2C_REGISTER_CALLBACKS    0
//  <q> 启用 FMPSMBUS (Fast-mode System Management Bus) 中断注册回调函数
#define USE_HAL_FMPSMBUS_REGISTER_CALLBACKS  0
//  <q> 启用 I2S (Inter-integrated sound) 中断注册回调函数
#define USE_HAL_I2S_REGISTER_CALLBACKS       0
//  <q> 启用 IRDA (Infrared data association) 中断注册回调函数
#define USE_HAL_IRDA_REGISTER_CALLBACKS      0
//  <q> 启用 LPTIM (Low-power timer) 中断注册回调函数
#define USE_HAL_LPTIM_REGISTER_CALLBACKS     0
//  <q> 启用 LTDC (LCD TFT display controller) 中断注册回调函数
#define USE_HAL_LTDC_REGISTER_CALLBACKS      0
//  <q> 启用 MMC (MultiMediaCard) 中断注册回调函数
#define USE_HAL_MMC_REGISTER_CALLBACKS       0
//  <q> 启用 NAND Flash 中断注册回调函数
#define USE_HAL_NAND_REGISTER_CALLBACKS      0
//  <q> 启用 Nor Flash 中断注册回调函数
#define USE_HAL_NOR_REGISTER_CALLBACKS       0
//  <q> 启用 PC Card 中断注册回调函数
#define USE_HAL_PCCARD_REGISTER_CALLBACKS    0
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
//  <q> 启用 SMARTCARD (Smartcard IC) 中断注册回调函数
#define USE_HAL_SMARTCARD_REGISTER_CALLBACKS 0
//  <q> 启用 SDRAM (Synchronous dynamic RAM) 中断注册回调函数
#define USE_HAL_SDRAM_REGISTER_CALLBACKS     0
//  <q> 启用 SRAM (SRAM external memory) 中断注册回调函数
#define USE_HAL_SRAM_REGISTER_CALLBACKS      0
//  <q> 启用 SPDIFRX (SPDIF-RX Receiver interface) 中断注册回调函数
#define USE_HAL_SPDIFRX_REGISTER_CALLBACKS   0
//  <q> 启用 SMBUS (System management bus) 中断注册回调函数
#define USE_HAL_SMBUS_REGISTER_CALLBACKS     0
//  <q> 启用 SPI (Serial peripheral interface) 中断注册回调函数
#define USE_HAL_SPI_REGISTER_CALLBACKS       0
//  <q> 启用 TIM (Advanced-control, general-purpose or basic timer) 中断注册回调函数
#define USE_HAL_TIM_REGISTER_CALLBACKS       0
//  <q> 启用 UART (Universal asynchronous receiver/transmitter) 中断注册回调函数
#define USE_HAL_UART_REGISTER_CALLBACKS      0
//  <q> 启用 USART (Universal synchronous receiver/transmitter) 中断注册回调函数
#define USE_HAL_USART_REGISTER_CALLBACKS     0
//  <q> 启用 WWDG (Window watchdog) 中断注册回调函数
#define USE_HAL_WWDG_REGISTER_CALLBACKS      0

// </h>

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the
  *        HAL drivers code
  */

// <c> 启用断言
//#define USE_FULL_ASSERT                      1U
// </c>

/* ################## Ethernet peripheral configuration ##################### */

/* Section 1 : Ethernet peripheral configuration */

// <o> MAC 地址 0
#define ETH_MAC_ADDR0                        0x02UL
// <o> MAC 地址 1
#define ETH_MAC_ADDR1                        0x00UL
// <o> MAC 地址 2
#define ETH_MAC_ADDR2                        0x00UL
// <o> MAC 地址 3
#define ETH_MAC_ADDR3                        0x00UL
// <o> MAC 地址 4
#define ETH_MAC_ADDR4                        0x00UL
// <o> MAC 地址 5
#define ETH_MAC_ADDR5                        0x00UL

// <o> 接收缓冲区大小
#define ETH_RX_BUF_SIZE                      1528U
// <o> 接收缓冲区单个数据大小
#define ETH_RXBUFNB                          4U
// <o> 发送缓冲区大小
#define ETH_TX_BUF_SIZE                      1528U
// <o> 发送缓冲区单个数据大小
#define ETH_TXBUFNB                          4U

// </h>

//------------- <<< end of configuration section >>> ---------------------------

/* clang-format off */

/* Section 2: PHY configuration section */

/* DP83848 PHY Address*/ 
#define DP83848_PHY_ADDRESS             0x01U
/* PHY Reset delay these values are based on a 1 ms Systick interrupt*/ 
#define PHY_RESET_DELAY                 0x000000FFU
/* PHY Configuration delay */
#define PHY_CONFIG_DELAY                0x00000FFFU

#define PHY_READ_TO                     0x0000FFFFU
#define PHY_WRITE_TO                    0x0000FFFFU

/* Section 3: Common PHY Registers */

#define PHY_BCR                         ((uint16_t)0x0000)  /*!< Transceiver Basic Control Register   */
#define PHY_BSR                         ((uint16_t)0x0001)  /*!< Transceiver Basic Status Register    */
 
#define PHY_RESET                       ((uint16_t)0x8000)  /*!< PHY Reset */
#define PHY_LOOPBACK                    ((uint16_t)0x4000)  /*!< Select loop-back mode */
#define PHY_FULLDUPLEX_100M             ((uint16_t)0x2100)  /*!< Set the full-duplex mode at 100 Mb/s */
#define PHY_HALFDUPLEX_100M             ((uint16_t)0x2000)  /*!< Set the half-duplex mode at 100 Mb/s */
#define PHY_FULLDUPLEX_10M              ((uint16_t)0x0100)  /*!< Set the full-duplex mode at 10 Mb/s  */
#define PHY_HALFDUPLEX_10M              ((uint16_t)0x0000)  /*!< Set the half-duplex mode at 10 Mb/s  */
#define PHY_AUTONEGOTIATION             ((uint16_t)0x1000)  /*!< Enable auto-negotiation function     */
#define PHY_RESTART_AUTONEGOTIATION     ((uint16_t)0x0200)  /*!< Restart auto-negotiation function    */
#define PHY_POWERDOWN                   ((uint16_t)0x0800)  /*!< Select the power down mode           */
#define PHY_ISOLATE                     ((uint16_t)0x0400)  /*!< Isolate PHY from MII                 */

#define PHY_AUTONEGO_COMPLETE           ((uint16_t)0x0020)  /*!< Auto-Negotiation process completed   */
#define PHY_LINKED_STATUS               ((uint16_t)0x0004)  /*!< Valid link established               */
#define PHY_JABBER_DETECTION            ((uint16_t)0x0002)  /*!< Jabber condition detected            */
  
/* Section 4: Extended PHY Registers */

#define PHY_SR                          ((uint16_t)0x0010)  /*!< PHY status register Offset                      */
#define PHY_MICR                        ((uint16_t)0x0011)  /*!< MII Interrupt Control Register                  */
#define PHY_MISR                        ((uint16_t)0x0012)  /*!< MII Interrupt Status and Misc. Control Register */
 
#define PHY_LINK_STATUS                 ((uint16_t)0x0001)  /*!< PHY Link mask                                   */
#define PHY_SPEED_STATUS                ((uint16_t)0x0002)  /*!< PHY Speed mask                                  */
#define PHY_DUPLEX_STATUS               ((uint16_t)0x0004)  /*!< PHY Duplex mask                                 */

#define PHY_MICR_INT_EN                 ((uint16_t)0x0002)  /*!< PHY Enable interrupts                           */
#define PHY_MICR_INT_OE                 ((uint16_t)0x0001)  /*!< PHY Enable output interrupt events              */

#define PHY_MISR_LINK_INT_EN            ((uint16_t)0x0020)  /*!< Enable Interrupt on change of link status       */
#define PHY_LINK_INTERRUPT              ((uint16_t)0x2000)  /*!< PHY link status interrupt mask                  */

/* Includes ------------------------------------------------------------------*/
/**
  * @brief Include module's header file 
  */

#ifdef HAL_RCC_MODULE_ENABLED
  #include "stm32f4xx_hal_rcc.h"
#endif /* HAL_RCC_MODULE_ENABLED */

#ifdef HAL_GPIO_MODULE_ENABLED
  #include "stm32f4xx_hal_gpio.h"
#endif /* HAL_GPIO_MODULE_ENABLED */

#ifdef HAL_EXTI_MODULE_ENABLED
  #include "stm32f4xx_hal_exti.h"
#endif /* HAL_EXTI_MODULE_ENABLED */

#ifdef HAL_DMA_MODULE_ENABLED
  #include "stm32f4xx_hal_dma.h"
#endif /* HAL_DMA_MODULE_ENABLED */
   
#ifdef HAL_CORTEX_MODULE_ENABLED
  #include "stm32f4xx_hal_cortex.h"
#endif /* HAL_CORTEX_MODULE_ENABLED */

#ifdef HAL_ADC_MODULE_ENABLED
  #include "stm32f4xx_hal_adc.h"
#endif /* HAL_ADC_MODULE_ENABLED */

#ifdef HAL_CAN_MODULE_ENABLED
  #include "stm32f4xx_hal_can.h"
#endif /* HAL_CAN_MODULE_ENABLED */

#ifdef HAL_CAN_LEGACY_MODULE_ENABLED
  #include "stm32f4xx_hal_can_legacy.h"
#endif /* HAL_CAN_LEGACY_MODULE_ENABLED */

#ifdef HAL_CRC_MODULE_ENABLED
  #include "stm32f4xx_hal_crc.h"
#endif /* HAL_CRC_MODULE_ENABLED */

#ifdef HAL_CRYP_MODULE_ENABLED
  #include "stm32f4xx_hal_cryp.h" 
#endif /* HAL_CRYP_MODULE_ENABLED */

#ifdef HAL_DMA2D_MODULE_ENABLED
  #include "stm32f4xx_hal_dma2d.h"
#endif /* HAL_DMA2D_MODULE_ENABLED */

#ifdef HAL_DAC_MODULE_ENABLED
  #include "stm32f4xx_hal_dac.h"
#endif /* HAL_DAC_MODULE_ENABLED */

#ifdef HAL_DCMI_MODULE_ENABLED
  #include "stm32f4xx_hal_dcmi.h"
#endif /* HAL_DCMI_MODULE_ENABLED */

#ifdef HAL_ETH_MODULE_ENABLED
  #include "stm32f4xx_hal_eth.h"
#endif /* HAL_ETH_MODULE_ENABLED */

#ifdef HAL_ETH_LEGACY_MODULE_ENABLED
  #include "stm32f4xx_hal_eth_legacy.h"
#endif /* HAL_ETH_LEGACY_MODULE_ENABLED */

#ifdef HAL_FLASH_MODULE_ENABLED
  #include "stm32f4xx_hal_flash.h"
#endif /* HAL_FLASH_MODULE_ENABLED */
 
#ifdef HAL_SRAM_MODULE_ENABLED
  #include "stm32f4xx_hal_sram.h"
#endif /* HAL_SRAM_MODULE_ENABLED */

#ifdef HAL_NOR_MODULE_ENABLED
  #include "stm32f4xx_hal_nor.h"
#endif /* HAL_NOR_MODULE_ENABLED */

#ifdef HAL_NAND_MODULE_ENABLED
  #include "stm32f4xx_hal_nand.h"
#endif /* HAL_NAND_MODULE_ENABLED */

#ifdef HAL_PCCARD_MODULE_ENABLED
  #include "stm32f4xx_hal_pccard.h"
#endif /* HAL_PCCARD_MODULE_ENABLED */ 
  
#ifdef HAL_SDRAM_MODULE_ENABLED
  #include "stm32f4xx_hal_sdram.h"
#endif /* HAL_SDRAM_MODULE_ENABLED */

#ifdef HAL_HASH_MODULE_ENABLED
 #include "stm32f4xx_hal_hash.h"
#endif /* HAL_HASH_MODULE_ENABLED */

#ifdef HAL_I2C_MODULE_ENABLED
 #include "stm32f4xx_hal_i2c.h"
#endif /* HAL_I2C_MODULE_ENABLED */

#ifdef HAL_SMBUS_MODULE_ENABLED
 #include "stm32f4xx_hal_smbus.h"
#endif /* HAL_SMBUS_MODULE_ENABLED */

#ifdef HAL_I2S_MODULE_ENABLED
 #include "stm32f4xx_hal_i2s.h"
#endif /* HAL_I2S_MODULE_ENABLED */

#ifdef HAL_IWDG_MODULE_ENABLED
 #include "stm32f4xx_hal_iwdg.h"
#endif /* HAL_IWDG_MODULE_ENABLED */

#ifdef HAL_LTDC_MODULE_ENABLED
 #include "stm32f4xx_hal_ltdc.h"
#endif /* HAL_LTDC_MODULE_ENABLED */

#ifdef HAL_PWR_MODULE_ENABLED
 #include "stm32f4xx_hal_pwr.h"
#endif /* HAL_PWR_MODULE_ENABLED */

#ifdef HAL_RNG_MODULE_ENABLED
 #include "stm32f4xx_hal_rng.h"
#endif /* HAL_RNG_MODULE_ENABLED */

#ifdef HAL_RTC_MODULE_ENABLED
 #include "stm32f4xx_hal_rtc.h"
#endif /* HAL_RTC_MODULE_ENABLED */

#ifdef HAL_SAI_MODULE_ENABLED
 #include "stm32f4xx_hal_sai.h"
#endif /* HAL_SAI_MODULE_ENABLED */

#ifdef HAL_SD_MODULE_ENABLED
 #include "stm32f4xx_hal_sd.h"
#endif /* HAL_SD_MODULE_ENABLED */

#ifdef HAL_SPI_MODULE_ENABLED
 #include "stm32f4xx_hal_spi.h"
#endif /* HAL_SPI_MODULE_ENABLED */

#ifdef HAL_TIM_MODULE_ENABLED
 #include "stm32f4xx_hal_tim.h"
#endif /* HAL_TIM_MODULE_ENABLED */

#ifdef HAL_UART_MODULE_ENABLED
 #include "stm32f4xx_hal_uart.h"
#endif /* HAL_UART_MODULE_ENABLED */

#ifdef HAL_USART_MODULE_ENABLED
 #include "stm32f4xx_hal_usart.h"
#endif /* HAL_USART_MODULE_ENABLED */

#ifdef HAL_IRDA_MODULE_ENABLED
 #include "stm32f4xx_hal_irda.h"
#endif /* HAL_IRDA_MODULE_ENABLED */

#ifdef HAL_SMARTCARD_MODULE_ENABLED
 #include "stm32f4xx_hal_smartcard.h"
#endif /* HAL_SMARTCARD_MODULE_ENABLED */

#ifdef HAL_WWDG_MODULE_ENABLED
 #include "stm32f4xx_hal_wwdg.h"
#endif /* HAL_WWDG_MODULE_ENABLED */

#ifdef HAL_PCD_MODULE_ENABLED
 #include "stm32f4xx_hal_pcd.h"
#endif /* HAL_PCD_MODULE_ENABLED */

#ifdef HAL_HCD_MODULE_ENABLED
 #include "stm32f4xx_hal_hcd.h"
#endif /* HAL_HCD_MODULE_ENABLED */
   
#ifdef HAL_DSI_MODULE_ENABLED
 #include "stm32f4xx_hal_dsi.h"
#endif /* HAL_DSI_MODULE_ENABLED */

#ifdef HAL_QSPI_MODULE_ENABLED
 #include "stm32f4xx_hal_qspi.h"
#endif /* HAL_QSPI_MODULE_ENABLED */

#ifdef HAL_CEC_MODULE_ENABLED
 #include "stm32f4xx_hal_cec.h"
#endif /* HAL_CEC_MODULE_ENABLED */

#ifdef HAL_FMPI2C_MODULE_ENABLED
 #include "stm32f4xx_hal_fmpi2c.h"
#endif /* HAL_FMPI2C_MODULE_ENABLED */

#ifdef HAL_FMPSMBUS_MODULE_ENABLED
 #include "stm32f4xx_hal_fmpsmbus.h"
#endif /* HAL_FMPSMBUS_MODULE_ENABLED */

#ifdef HAL_SPDIFRX_MODULE_ENABLED
 #include "stm32f4xx_hal_spdifrx.h"
#endif /* HAL_SPDIFRX_MODULE_ENABLED */

#ifdef HAL_DFSDM_MODULE_ENABLED
 #include "stm32f4xx_hal_dfsdm.h"
#endif /* HAL_DFSDM_MODULE_ENABLED */

#ifdef HAL_LPTIM_MODULE_ENABLED
 #include "stm32f4xx_hal_lptim.h"
#endif /* HAL_LPTIM_MODULE_ENABLED */

#ifdef HAL_MMC_MODULE_ENABLED
 #include "stm32f4xx_hal_mmc.h"
#endif /* HAL_MMC_MODULE_ENABLED */

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr If expr is false, it calls assert_failed function
  *         which reports the name of the source file and the source
  *         line number of the call that failed. 
  *         If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */


#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_CONF_H */
