/**
 * @file    bsp.c
 * @author  Deadline039
 * @brief   bsp层配置程序
 * @version 0.1
 * @date    2024-07-29
 */

#include "bsp.h"

/**
 * @brief 系统时钟配置
 *
 */
static void system_clock_config(void) {
    HAL_StatusTypeDef res = HAL_OK;

    RCC_OscInitTypeDef rcc_osc_init = {0};
    RCC_ClkInitTypeDef rcc_clk_init = {0};

    rcc_osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE; /* 选择要配置HSE */
    rcc_osc_init.HSEState = RCC_HSE_ON;                   /* 打开HSE */
    rcc_osc_init.HSEPredivValue = RCC_HSE_PREDIV_DIV1; /* HSE预分频系数 */
    rcc_osc_init.PLL.PLLState = RCC_PLL_ON;            /* 打开PLL */
    rcc_osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE; /* PLL时钟源选择HSE */
    rcc_osc_init.PLL.PLLMUL = RCC_PLL_MUL9;         /* PLL倍频系数 */
    res = HAL_RCC_OscConfig(&rcc_osc_init);         /* 初始化 */

#ifdef DEBUG
    assert(res == HAL_OK);
#endif /* DEBUG */

    /* 选中PLL作为系统时钟源并且配置HCLK, PCLK1和PCLK2*/
    rcc_clk_init.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                              RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    rcc_clk_init.SYSCLKSource =
        RCC_SYSCLKSOURCE_PLLCLK; /* 设置系统时钟来自PLL */
    rcc_clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1; /* AHB分频系数为1 */
    rcc_clk_init.APB1CLKDivider = RCC_HCLK_DIV2;  /* APB1分频系数为2 */
    rcc_clk_init.APB2CLKDivider = RCC_HCLK_DIV1;  /* APB2分频系数为1 */
    /* 同时设置FLASH延时周期为2WS, 也就是3个CPU周期 */
    res = HAL_RCC_ClockConfig(&rcc_clk_init, FLASH_LATENCY_2);

#ifdef DEBUG
    assert(res == HAL_OK);
#endif /* DEBUG */
}

/**
 * @brief bsp层驱动初始化
 *
 */
void bsp_init(void) {
    HAL_Init();
    system_clock_config();
    delay_init(72);
    uart_init(&usart1_handle, 115200, UART_WORDLENGTH_8B, UART_STOPBITS_1,
              UART_PARITY_NONE, UART_HWCONTROL_NONE, UART_MODE_TX_RX);
    led_init();
    key_init();
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
