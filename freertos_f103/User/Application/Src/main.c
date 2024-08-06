/**
 * @file    main.c
 * @author  Deadline039
 * @brief   主函数
 * @version 0.1
 * @date    2024-07-29
 */

#include "includes.h"
#include <stdio.h>

int main(void) {
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    bsp_init();
    freertos_start();
}
