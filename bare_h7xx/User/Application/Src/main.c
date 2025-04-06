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
    bsp_init();
    LED0_ON();
    LED1_OFF();

    key_press_t key = KEY_NO_PRESS;
    uint8_t count = 0;

    while (1) {
        key = key_scan(0);
        switch (key) {
            case WKUP_PRESS: {
                printf("Wake Up Pressed. \n");
            } break;

            case KEY0_PRESS: {
                printf("KEY0 Pressed. \n");
            } break;

            case KEY1_PRESS: {
                printf("KEY1 Pressed. \n");
            } break;

            case KEY2_PRESS: {
                printf("KEY2 Pressed. \n");
            } break;

            default: {
            } break;
        }

        if (count == 100) {
            printf("STM32H7xx bare project template. Running time: %u ms. \n",
                   HAL_GetTick());
            LED0_TOGGLE();
            LED1_TOGGLE();
            count = 0;
        }

        ++count;
        delay_ms(10);
    }
}