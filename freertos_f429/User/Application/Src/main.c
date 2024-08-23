/**
 * @file    main.c
 * @author  Deadline039
 * @brief   主函数
 * @version 1.0
 * @date    2024-07-29
 */

#include "includes.h"

/**
 * @brief 主函数
 *
 * @return 退出码
 */
int main(void) {
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    bsp_init();
    freertos_start();

    return 0;
}
