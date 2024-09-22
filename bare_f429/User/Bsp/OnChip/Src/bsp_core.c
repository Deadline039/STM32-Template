/**
 * @file    bsp_core.c
 * @author  Deadline039
 * @brief   芯片内核与外部资源配置
 * @version 1.0
 * @date    2024-07-29
 */

#include "bsp_core.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "core_delay.h"

/**
 * @brief 系统时钟配置
 *
 */
void system_clock_config(void) {
    HAL_StatusTypeDef res = HAL_OK;

    RCC_OscInitTypeDef rcc_osc_init = {0};
    RCC_ClkInitTypeDef rcc_clk_init = {0};

    __HAL_RCC_PWR_CLK_ENABLE();

    /* 设置调压器输出电压级别, 以便在器件未以最大频率工作 */
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    rcc_osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    rcc_osc_init.HSEState = RCC_HSE_ON;
    rcc_osc_init.PLL.PLLState = RCC_PLL_ON;
    rcc_osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    rcc_osc_init.PLL.PLLN = 360;
    rcc_osc_init.PLL.PLLM = 25;
    rcc_osc_init.PLL.PLLP = RCC_PLLP_DIV2;
    rcc_osc_init.PLL.PLLQ = 8;
    res = HAL_RCC_OscConfig(&rcc_osc_init);
#ifdef DEBUG
    assert(res == HAL_OK);
#endif /* DEBUG */

    res = HAL_PWREx_EnableOverDrive();
#ifdef DEBUG
    assert(res == HAL_OK);
#endif /* DEBUG */

    rcc_clk_init.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                              RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);

    rcc_clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    rcc_clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
    rcc_clk_init.APB1CLKDivider = RCC_HCLK_DIV4;
    rcc_clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
    /*  设置FLASH延时周期为5WS, 也就是6个CPU周期 */
    res = HAL_RCC_ClockConfig(&rcc_clk_init, FLASH_LATENCY_5);
#ifdef DEBUG
    assert(res == HAL_OK);
#endif /* DEBUG */
}

#ifdef USE_FULL_ASSERT

/**
 * @brief 断言失败函数
 *
 * @param file 文件
 * @param line 行数
 */
void assert_failed(uint8_t *file, uint32_t line) {
    fprintf(stderr, "HAL assert failed. In file: %s, line: %d\r\n", file, line);
}

#endif /* USE_FULL_ASSERT */
