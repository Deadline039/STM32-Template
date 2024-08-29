/**
 * @file    delay.c
 * @author  正点原子Alientek
 * @brief   使用SysTick延时函数
 * @version 1.1
 * @date    2024-08-05
 */

#include "delay.h"

/* us延时倍乘数 */
static uint32_t g_fac_us = 0;

/**
 * @brief 初始化延迟函数
 *
 * @param sysclk 系统时钟频率(MHz)
 */
void delay_init(uint16_t sysclk) {
    g_fac_us = sysclk;
}

/**
 * @brief 延时n毫秒
 *
 * @param ms 延时的毫秒数
 */
void delay_ms(uint32_t ms) {
    delay_us((uint32_t)(ms * 1000));
}

/**
 * @brief 延时n微秒
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
