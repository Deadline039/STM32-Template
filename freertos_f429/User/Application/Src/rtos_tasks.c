/**
 * @file    rtos_tasks.c
 * @author  Deadline039
 * @brief   RTOS任务
 * @version 1.0
 * @date    2024-01-31
 */

#include "includes.h"

static TaskHandle_t start_task_handle;
void start_task(void *pvParameters);

static TaskHandle_t task1_handle;
void task1(void *pvParameters);

static TaskHandle_t task2_handle;
void task2(void *pvParameters);

static TaskHandle_t task3_handle;
void task3(void *pvParameters);

/*****************************************************************************/

/**
 * @brief FreeRTOS启动函数
 *
 */
void freertos_start(void) {
    xTaskCreate(start_task, "start_task", 128, NULL, 2, &start_task_handle);
    vTaskStartScheduler();
}

/**
 * @brief 启动任务
 *
 * @param pvParameters 传入参数(未用到)
 */
void start_task(void *pvParameters) {
    UNUSED(pvParameters);
    taskENTER_CRITICAL();

    xTaskCreate(task1, "task1", 128, NULL, 2, &task1_handle);
    xTaskCreate(task2, "task2", 128, NULL, 2, &task2_handle);
    xTaskCreate(task3, "task3", 128, NULL, 2, &task3_handle);

    vTaskDelete(start_task_handle);
    taskEXIT_CRITICAL();
}

/**
 * @brief 任务1 跑马灯
 *
 * @param pvParameters 传入参数(未用到)
 */
void task1(void *pvParameters) {
    UNUSED(pvParameters);

    LED0_TOGGLE();
    while (1) {
        LED0_TOGGLE();
        LED1_TOGGLE();
        HAL_Delay(1000);
    }
}

/**
 * @brief 任务2, 串口定时发送
 *
 * @param pvParameters 传入参数(未用到)
 */
void task2(void *pvParameters) {
    UNUSED(pvParameters);

    while (1) {
        printf("STM32F429 FreeRTOS project template. Running time: %d ms. \r\n",
               xTaskGetTickCount());
        vTaskDelay(1000);
    }
}

/**
 * @brief 任务3, 按键扫描
 *
 * @param pvParameters 传入参数(未用到)
 */
void task3(void *pvParameters) {
    UNUSED(pvParameters);

    key_press_t key = KEY_NO_PRESS;

    while (1) {
        key = key_scan(0);
        switch (key) {
            case WKUP_PRESS: {
                printf("Wake Up Pressed. \r\n");
            } break;

            case KEY0_PRESS: {
                printf("KEY0 Pressed. \r\n");
            } break;

            case KEY1_PRESS: {
                printf("KEY1 Pressed. \r\n");
            } break;

            default: {
            } break;
        }

        vTaskDelay(10);
    }
}
