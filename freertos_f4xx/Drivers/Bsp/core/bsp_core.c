/**
 * @file    bsp_core.c
 * @author  Deadline039
 * @brief   System core configuration.
 * @version 1.0
 * @date    2024-07-29
 */

#include "bsp_core.h"

/**
 * @brief System clock tree configuration.
 *
 * @return Configuration status.
 * @retval 0-`SYSTEM_CORE_CLK_OK`:      Success.
 * @retval 1-`SYSTEM_CORE_HSC_FAIL`:    High speed clock configuration failed.
 * @retval 2-`SYSTEM_CORE_LSC_FAIL`:    Low speed clock configuration failed.
 * @retval 3-`SYSTEM_PERIPH_CLK_FAIL`:  Peripherals(AHB, APB) clock
 *                                      configuration failed.
 */
uint8_t system_clock_config(void) {
    RCC_OscInitTypeDef rcc_osc_init = {0};
    RCC_ClkInitTypeDef rcc_clk_init = {0};

    __HAL_RCC_PWR_CLK_ENABLE();

    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    rcc_osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    rcc_osc_init.HSEState = RCC_HSE_ON;
    rcc_osc_init.PLL.PLLState = RCC_PLL_ON;
    rcc_osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    rcc_osc_init.PLL.PLLN = 360;
    rcc_osc_init.PLL.PLLM = 25;
    rcc_osc_init.PLL.PLLP = RCC_PLLP_DIV2;
    rcc_osc_init.PLL.PLLQ = 8;
    if (HAL_RCC_OscConfig(&rcc_osc_init) != HAL_OK) {
        return SYSTEM_CORE_HSC_FAIL;
    }

    if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
        return SYSTEM_PWR_OVER_DRIVE_FAIL;
    }

    rcc_clk_init.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                              RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);

    rcc_clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    rcc_clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
    rcc_clk_init.APB1CLKDivider = RCC_HCLK_DIV4;
    rcc_clk_init.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&rcc_clk_init, FLASH_LATENCY_5) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }

    return SYSTEM_CORE_CLK_OK;
}
