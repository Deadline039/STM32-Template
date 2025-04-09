/**
 * @file    bsp_core.c
 * @author  Deadline039
 * @brief   System core configuration.
 * @version 1.0
 * @date    2024-12-03
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
/**
 * @file    bsp_core.c
 * @author  Deadline039
 * @brief   System core configuration.
 * @version 1.0
 * @date    2024-12-03
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
    RCC_OscInitTypeDef rcc_osc_init = {0};
    RCC_ClkInitTypeDef rcc_clk_init = {0};

    /** Configure the main internal regulator output voltage
     */
    HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    rcc_osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    rcc_osc_init.HSEState = RCC_HSE_ON;
    rcc_osc_init.PLL.PLLState = RCC_PLL_ON;
    rcc_osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    rcc_osc_init.PLL.PLLM = RCC_PLLM_DIV5;
    rcc_osc_init.PLL.PLLN = 68;
    rcc_osc_init.PLL.PLLP = RCC_PLLP_DIV2;
    rcc_osc_init.PLL.PLLQ = RCC_PLLQ_DIV4;
    rcc_osc_init.PLL.PLLR = RCC_PLLR_DIV2;
    if (HAL_RCC_OscConfig(&rcc_osc_init) != HAL_OK) {
        return SYSTEM_CORE_HSC_FAIL;
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    rcc_clk_init.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                             RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    rcc_clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    rcc_clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
    rcc_clk_init.APB1CLKDivider = RCC_HCLK_DIV1;
    rcc_clk_init.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&rcc_clk_init, FLASH_LATENCY_4) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }

    RCC_PeriphCLKInitTypeDef periph_clk_init_struct = {0};

#if LPUART1_ENABLE
    /* Use PCLK1 (170 MHz) to LPUART1 clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_LPUART1;
    periph_clk_init_struct.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* LPUART1_ENABLE */

#if USART1_ENABLE 
    /* Use PCLK2 (170 MHz) to USART1 clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    periph_clk_init_struct.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* USART1_ENABLE */

#if USART2_ENABLE 
    /* Use PCLK1 (170 MHz) to USART2 clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_USART2;
    periph_clk_init_struct.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* USART2_ENABLE */

#if USART3_ENABLE 
    /* Use PCLK1 (170 MHz) to USART3 clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_USART3;
    periph_clk_init_struct.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* USART3_ENABLE */

#if UART4_ENABLE
    /* Use PCLK1 (170 MHz) to UART4 clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_UART4;
    periph_clk_init_struct.Uart4ClockSelection = RCC_UART4CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* UART4_ENABLE */

#if UART5_ENABLE
    /* Use PCLK1 (170 MHz) to UART5 clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_UART5;
    periph_clk_init_struct.Uart5ClockSelection = RCC_UART5CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* UART5_ENABLE */

#if I2C1_ENABLE
    /* Use PCLK1 (170 MHz) to I2C1 clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
    periph_clk_init_struct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* I2C1_ENABLE */

#if I2C2_ENABLE
    /* Use PCLK1 (170 MHz) to I2C2 clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_I2C2;
    periph_clk_init_struct.I2c2ClockSelection = RCC_I2C2CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* I2C2_ENABLE */

#if I2C3_ENABLE
    /* Use PCLK1 (170 MHz) to I2C3 clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_I2C3;
    periph_clk_init_struct.I2c3ClockSelection = RCC_I2C3CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* I2C3_ENABLE */

#if I2C4_ENABLE
    /* Use PCLK1 (170 MHz) to I2C4 clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_I2C4;
    periph_clk_init_struct.I2c4ClockSelection = RCC_I2C4CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* I2C4_ENABLE */

#if (FDCAN1_ENABLE || FDCAN2_ENABLE || FDCAN3_ENABLE)
    /* Use PCLK1 (170 MHz) to FDCAN clock source. */
    periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
    periph_clk_init_struct.FdcanClockSelection = RCC_FDCANCLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct) != HAL_OK) {
        return SYSTEM_PERIPH_CLK_FAIL;
    }
#endif /* FDCAN1_ENABLE || FDCAN2_ENABLE || FDCAN3_ENABLE */

    return SYSTEM_CORE_CLK_OK;
}
