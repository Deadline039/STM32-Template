/**
 * @file    main.c
 * @author  Deadline039
 * @brief   Main function files.
 * @version 1.0
 * @date    2024-07-29
 */

#include "includes.h"

/**
 * @brief The program entrance.
 *
 * @return Exit code.
 */
int main(void) {
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    bsp_init();
    freertos_start();

    return 0;
}
