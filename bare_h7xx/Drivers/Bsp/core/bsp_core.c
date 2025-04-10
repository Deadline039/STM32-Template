/**
 * @file    bsp_core.c
 * @author  Deadline039
 * @brief   System core configuration.
 * @version 1.0
 * @date    2025-03-24
 */

#include "bsp_core.h"

/**
 * @brief System clock tree configuration.
 *
 * @return Configuration status.
 *  @retval - 0: `SYSTEM_CORE_CLK_OK`:      Success.
 *  @retval - 1: `SYSTEM_CORE_HSC_FAIL`:    High speed clock configuration failed.
 *  @retval - 2: `SYSTEM_CORE_LSC_FAIL`:    Low speed clock configuration failed.
 *  @retval - 3: `SYSTEM_PERIPH_CLK_FAIL`:  Peripherals(AHB, APB) clock
 *                                          configuration failed.
 */
uint8_t system_clock_config(void) {
    HAL_StatusTypeDef res = HAL_OK;

    RCC_OscInitTypeDef rcc_osc_init_struct = {0};
    RCC_ClkInitTypeDef rcc_clk_init_struct = {0};
    RCC_PeriphCLKInitTypeDef rcc_periph_init_struct = {0};

    /* Supply configuration update enable.  */
    HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    /* Wait for power supply stability. */
    while (__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY) != SET)
        ;

    /* Enable HSE(25 MHz). Use PLL to system clock source, 480 MHz. 
       Enable Internal USB RC 48 MHz clock. */
    rcc_osc_init_struct.OscillatorType =
        RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI48;
    rcc_osc_init_struct.HSEState = RCC_HSE_ON;
    rcc_osc_init_struct.HSIState = RCC_HSI_OFF;
    rcc_osc_init_struct.CSIState = RCC_CSI_OFF;
    rcc_osc_init_struct.HSI48State = RCC_HSI48_ON;
    rcc_osc_init_struct.PLL.PLLState = RCC_PLL_ON;
    rcc_osc_init_struct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    rcc_osc_init_struct.PLL.PLLM = 5;
    rcc_osc_init_struct.PLL.PLLN = 192;
    rcc_osc_init_struct.PLL.PLLP = 2;
    rcc_osc_init_struct.PLL.PLLQ = 2;
    rcc_osc_init_struct.PLL.PLLR = 2;
    rcc_osc_init_struct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
    rcc_osc_init_struct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
    rcc_osc_init_struct.PLL.PLLFRACN = 0;

    res = HAL_RCC_OscConfig(&rcc_osc_init_struct);
    if (res != HAL_OK) {
        return SYSTEM_CORE_HSC_FAIL;
    }

    rcc_clk_init_struct.ClockType =
        (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 |
         RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_D1PCLK1 | RCC_CLOCKTYPE_D3PCLK1);

    rcc_clk_init_struct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    rcc_clk_init_struct.SYSCLKDivider = RCC_SYSCLK_DIV1;
    rcc_clk_init_struct.AHBCLKDivider = RCC_HCLK_DIV2;
    rcc_clk_init_struct.APB1CLKDivider = RCC_APB1_DIV2;
    rcc_clk_init_struct.APB2CLKDivider = RCC_APB2_DIV2;
    rcc_clk_init_struct.APB3CLKDivider = RCC_APB3_DIV2;
    rcc_clk_init_struct.APB4CLKDivider = RCC_APB4_DIV2;
    res = HAL_RCC_ClockConfig(&rcc_clk_init_struct, FLASH_LATENCY_2);

    if (res != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }

    HAL_PWREx_EnableUSBVoltageDetector();
    __HAL_RCC_CSI_ENABLE();
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    HAL_EnableCompensationCell();

    /* PLL2 Configuration. */
    rcc_periph_init_struct.PLL2.PLL2M = 25;
    rcc_periph_init_struct.PLL2.PLL2N = 200;
    rcc_periph_init_struct.PLL2.PLL2P = 2;
    rcc_periph_init_struct.PLL2.PLL2Q = 2;
    rcc_periph_init_struct.PLL2.PLL2R = 1;
    rcc_periph_init_struct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_2;
    rcc_periph_init_struct.PLL2.PLL2VCOSEL = RCC_PLL2VCOWIDE;
    rcc_periph_init_struct.PLL2.PLL2FRACN = 0;

    /* PLL3 Configuration */
    rcc_periph_init_struct.PLL3.PLL3M = 5;
    rcc_periph_init_struct.PLL3.PLL3N = 80;
    rcc_periph_init_struct.PLL3.PLL3P = 2;
    rcc_periph_init_struct.PLL3.PLL3Q = 2;
    rcc_periph_init_struct.PLL3.PLL3R = 2;
    rcc_periph_init_struct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_2;
    rcc_periph_init_struct.PLL3.PLL3VCOSEL = RCC_PLL3VCOWIDE;
    rcc_periph_init_struct.PLL3.PLL3FRACN = 0;

    /*## U(S)ART clock configuration. #######################################*/
#if (USART1_ENABLE || USART6_ENABLE)
    /* Use PCLK2 (120 MHz) to USART1, 6 clock source. */
    rcc_periph_init_struct.PeriphClockSelection = RCC_PERIPHCLK_USART16;
    rcc_periph_init_struct.Usart16ClockSelection = RCC_USART16CLKSOURCE_D2PCLK2;

    res = HAL_RCCEx_PeriphCLKConfig(&rcc_periph_init_struct);
    if (res != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* USART1_ENABLE || USART6_ENABLE */

#if (USART2_ENABLE || USART3_ENABLE || UART4_ENABLE || UART5_ENABLE ||         \
     UART7_ENABLE || UART8_ENABLE)
    /* Use PCLK1 (120 MHz) to U(S)ART2,3,4,5,7,8 clock source. */
    rcc_periph_init_struct.PeriphClockSelection = RCC_PERIPHCLK_USART234578;
    rcc_periph_init_struct.Usart234578ClockSelection =
        RCC_USART234578CLKSOURCE_PCLK1;
    res = HAL_RCCEx_PeriphCLKConfig(&rcc_periph_init_struct);
    if (res != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* USART2_ENABLE || USART3_ENABLE || UART4_ENABLE || UART5_ENABLE || UART7_ENABLE || UART8_ENABLE */

    /*## QUADSPI clock configuration. #######################################*/
#if QUADSPI_ENABLE
    /* Use PLL2R (200 MHz) to QSPI clock source. */
    rcc_periph_init_struct.PeriphClockSelection = RCC_PERIPHCLK_QSPI;
    rcc_periph_init_struct.QspiClockSelection = RCC_QSPICLKSOURCE_PLL2;
    res = HAL_RCCEx_PeriphCLKConfig(&rcc_periph_init_struct);
    if (res != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* QUADSPI_ENABLE */

    /*## SPI clock configuration. ###########################################*/
#if (SPI1_ENABLE || SPI2_ENABLE || SPI3_ENABLE)
    /* Use PLL3P (200 MHz) to SPI1, SPI2 and SPI3 clock source. */
    rcc_periph_init_struct.PeriphClockSelection = RCC_PERIPHCLK_SPI123;
    rcc_periph_init_struct.Spi123ClockSelection = RCC_SPI123CLKSOURCE_PLL3;
    res = HAL_RCCEx_PeriphCLKConfig(&rcc_periph_init_struct);
    if (res != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* SPI1_ENABLE || SPI2_ENABLE || SPI3_ENABLE */

#if (SPI4_ENABLE || SPI5_ENABLE)
    /* Use PLL2Q (100 MHz) to SPI4 and SPI5 clock source. */
    rcc_periph_init_struct.PeriphClockSelection = RCC_PERIPHCLK_SPI45;
    rcc_periph_init_struct.Spi45ClockSelection = RCC_SPI45CLKSOURCE_PLL2;
    res = HAL_RCCEx_PeriphCLKConfig(&rcc_periph_init_struct);
    if (res != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* SPI4_ENABLE || SPI5_ENABLE */

#if SPI6_ENABLE
    /* Use PLL2Q (100 MHz) to SPI6 clock source. */
    rcc_periph_init_struct.PeriphClockSelection = RCC_PERIPHCLK_SPI45;
    rcc_periph_init_struct.Spi45ClockSelection = RCC_SPI6CLKSOURCE_PLL2;
    res = HAL_RCCEx_PeriphCLKConfig(&rcc_periph_init_struct);
    if (res != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* SPI6_ENABLE */

    /*## I2C clock configuration. ###########################################*/
#if (I2C1_ENABLE || I2C2_ENABLE || I2C3_ENABLE)
    /* Use PCLK1 (120 MHz) to I2C1,2,3 clock source. */
    rcc_periph_init_struct.PeriphClockSelection = RCC_PERIPHCLK_I2C123;
    rcc_periph_init_struct.I2c123ClockSelection = RCC_I2C123CLKSOURCE_D2PCLK1;
    res = HAL_RCCEx_PeriphCLKConfig(&rcc_periph_init_struct);
    if (res != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* I2C1_ENABLE || I2C2_ENABLE || I2C3_ENABLE */

#if (I2C4_ENABLE)
    /* Use PCLK4 to I2C4 clock source. */
    rcc_periph_init_struct.PeriphClockSelection = RCC_PERIPHCLK_I2C4;
    rcc_periph_init_struct.I2c4ClockSelection = RCC_I2C4CLKSOURCE_D3PCLK1;
    res = HAL_RCCEx_PeriphCLKConfig(&rcc_periph_init_struct);
    if (res != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* I2C4_ENABLE */

    /*## FDCAN clock configuration. #########################################*/
#if (FDCAN1_ENABLE || FDCAN2_ENABLE)
    /* Use PLL1Q (120 MHz) to FDCAN clock source. */
    rcc_periph_init_struct.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;

    rcc_periph_init_struct.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL;
    res = HAL_RCCEx_PeriphCLKConfig(&rcc_periph_init_struct);
    if (res != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* FDCAN1_ENABLE || FDCAN2_ENABLE */

    /* Enable D2SRAM clock. */
    __HAL_RCC_D2SRAM1_CLK_ENABLE();
    __HAL_RCC_D2SRAM2_CLK_ENABLE();
    __HAL_RCC_D2SRAM3_CLK_ENABLE();

    return SYSTEM_CORE_CLK_OK;
}

/**
 * @brief Enable STM32H7 L1 cache.
 * 
 */
void system_enable_cache(void) {
    SCB_EnableICache();
    SCB_EnableDCache();
    /* Enable force write through. */
    SET_BIT(SCB->CACR, SCB_CACR_FORCEWT_Msk);
}

/**
 * @brief Disable STM32H7 L1 cache.
 * 
 */
void system_disable_cache(void) {
    SCB_DisableICache();
    SCB_DisableDCache();
    /* Disable force write through. */
    CLEAR_BIT(SCB->CACR, SCB_CACR_FORCEWT_Msk);
}
