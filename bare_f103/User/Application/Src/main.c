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
    bsp_init();
    LED0_ON();
    LED1_OFF();

    key_press_t key = KEY_NO_PRESS;
    uint8_t count = 0;

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

        if (count == 100) {
            printf("STM32F103 bare project template. Running time: %d ms. \r\n",
                   HAL_GetTick());
            LED0_TOGGLE();
            LED1_TOGGLE();
            count = 0;
        }

        ++count;
        delay_ms(10);
    }
}