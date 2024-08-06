/**
 * @file    delay.c
 * @author  正点原子Alientek
 * @brief   使用SysTick延时函数
 * @version 1.1
 * @date    2024-08-05
 */

#include "delay.h"
#include "FreeRTOS.h"
#include "task.h"

/* us延时倍乘数 */
static uint32_t g_fac_us = 0;

/**
 * @brief 初始化延迟函数
 *
 * @param sysclk 系统时钟频率(MHz)
 */
void delay_init(uint16_t sysclk) {
    uint32_t reload;

    /* 清Systick状态，以便下一步重设，如果这里开了中断会关闭其中断 */
    SysTick->CTRL = 0;

    /* SYSTICK使用内核时钟源8分频,因systick的计数器最大值只有2^24 */
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK_DIV8);

    /* 不论是否使用OS,g_fac_us都需要使用,作为1us的基础时基 */
    g_fac_us = sysclk / 8;

    reload = sysclk / 8; /* 每秒钟的计数次数 单位为M */

    /* 根据delay_ostickspersec设定溢出时间.
     * reload为24位寄存器,最大值:16777216,在9M下,约合1.86s左右
     */
    reload *= 1000000 / configTICK_RATE_HZ;
    SysTick->CTRL |= 1 << 1; /* 开启SYSTICK中断 */
    SysTick->LOAD = reload;  /* 每1/delay_ostickspersec秒中断一次 */
    SysTick->CTRL |= 1 << 0; /* 开启SYSTICK */
}

/**
 * @brief 延时n毫秒(阻塞式)
 *
 * @param ms 延时的毫秒数
 */
void delay_ms(uint32_t ms) {
    delay_us((uint32_t)(ms * 1000));
}

/**
 * @brief 延时n微秒(阻塞式)
 *
 * @param us 延时的微秒数
 */
void delay_us(uint32_t us) {
    uint32_t ticks;
    uint32_t told, tnow, tcnt = 0;
    uint32_t reload = SysTick->LOAD; /* LOAD的值 */
    ticks = us * g_fac_us;           /* 需要的节拍数 */

    told = SysTick->VAL; /* 刚进入时的计数器值 */
    while (1) {
        tnow = SysTick->VAL;
        if (tnow != told) {
            if (tnow < told) {
                /* 这里注意一下SYSTICK是一个递减的计数器就可以了 */
                tcnt += told - tnow;
            } else {
                tcnt += reload - tnow + told;
            }
            told = tnow;
            if (tcnt >= ticks) {
                break; /* 时间超过/等于要延迟的时间,则退出 */
            }
        }
    }
}

/**
 * @brief 重定义HAL库延时
 *
 * @param Delay 延时的毫秒数
 * @note 如果RTOS开始运行, 使用任务延时.
 *       如果没有开始运行, 使用delay_ms(阻塞延时)
 * @warning 禁止在中断中使用!
 */
void HAL_Delay(uint32_t Delay) {
    if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) {
        vTaskDelay(Delay);
    } else {
        delay_ms(Delay);
    }
}
