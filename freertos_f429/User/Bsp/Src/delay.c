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

    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
    g_fac_us = sysclk;

    reload = sysclk; /* 每秒钟的计数次数 单位为M */
    /* 根据delay_ostickspersec设定溢出时间,reload为24位
     * 寄存器,最大值:16777216,在180M下,约合0.0932s左右
     */
    reload *= 1000000 / configTICK_RATE_HZ;
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk; /* 开启SYSTICK中断 */
    SysTick->LOAD = reload; /* 每1/delay_ostickspersec秒中断一次 */
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; /* 开启SYSTICK */
}

/**
 * @brief 延时n毫秒
 *
 * @param ms 延时的毫秒数
 * @note 如果RTOS开始运行, 使用任务延时.
 *       如果没有开始运行, 阻塞延时
 * @warning 禁止在中断中使用!
 */
void delay_ms(uint32_t ms) {
    if (xTaskGetSchedulerState() != taskSCHEDULER_NOT_STARTED) {
        vTaskDelay(ms);
    } else {
        delay_us((uint32_t)(ms * 1000));
    }
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
    told = SysTick->VAL;             /* 刚进入时的计数器值 */

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
