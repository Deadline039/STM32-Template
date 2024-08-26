/**
 * @file    retarget_io.c
 * @author  Deadline039
 * @brief   重定向C库的底层IO
 * @version 1.1
 * @date    2024-07-29
 * @ref     正点原子, 野火, CMSIS
 * @ref
 * https://developer.arm.com/documentation/100073/0611/the-c-and-c---library-functions-reference
 * https://developer.arm.com/documentation/100073/0622/The-Arm-C-and-C---Libraries/ISO-C-library-implementation-definition
 */

#include "stm32f4xx_hal.h"

#include <stdio.h>

/* stdout串口 */
#define STDOUT_UART USART1
/* stderr串口 */
#define STDERR_UART USART1

/**
 * @defgroup 重定向stdout, stderr
 * @{
 */

#if defined(__ARMCC_VERSION) /* Compiler */

#if (__ARMCC_VERSION >= 6010050) /* 使用AC6编译器时 */

__asm(".global __use_no_semihosting\n\t"); /* 声明不使用半主机模式 */
/* AC6下需要声明main函数为无参数格式，否则部分例程可能出现半主机模式 */
__asm(".global __ARM_use_no_argv \n\t");

#elif ((__ARMCC_VERSION >= 5000000) &&                                         \
       (__ARMCC_VERSION < 6000000)) /* 使用AC5编译器 */
/* 使用AC5编译器时, 要在这里定义__FILE 和 不使用半主机模式 */

/* 关闭多字节警告 */
#pragma diag_suppress 870

#pragma import(__use_no_semihosting)

struct __FILE {
    int handle;
    /* Whatever you require here. If the only file you are using is */
    /* standard output using printf() for debugging, no file handling */
    /* is required. */
};
#endif /* __ARMCC_VERSION */
/**
 * 不使用半主机模式，至少需要重定义_ttywrch, _sys_exit,
 * _sys_command_string函数,以同时兼容AC6和AC5模式
 */

/**
 * @brief 将字符写入控制台, 控制台输出时可从此重定向
 *
 * @param ch 输出的字符
 * @return 字符
 * @note 此函数默认在半主机模式下实现
 */
int _ttywrch(int ch) {
    ch = ch;
    return ch;
}

/**
 * @brief 调用了C库中类似exit的函数时会调用此函数
 *
 * @param x 退出的参数
 * @note 如果使用MicroLib, C库中的所有退出函数都会被移除
 */
void _sys_exit(int x) {
    x = x;
}

/**
 * @brief 此函数负责将argc, argv参数传递main函数. 编译器自动链接
 *
 * @param cmd main参数
 * @param len 参数字符串长度
 * @return main函数参数的字符串
 */
char *_sys_command_string(char *cmd, int len) {
    (void)cmd;
    (void)len;
    return NULL;
}

/* 如果不定义, 在不启用MicroLib的情况下会链接_sys_open */
FILE __stdout;
FILE __stderr;

/**
 * @brief 向文件写入字符
 *
 * @param ch 写入的字符
 * @param file 文件指针
 * @return 写入的字符
 */
int fputc(int ch, FILE *file) {
    if (file == stdout) {
        while ((STDOUT_UART->SR & 0X40) == 0)
            ; /* 等待上一个字符发送完成 */

        STDOUT_UART->DR = (uint8_t)ch; /* 将要发送的字符 ch 写入到DR寄存器 */

    } else if (file == stderr) {
        while ((STDERR_UART->SR & 0X40) == 0)
            ; /* 等待上一个字符发送完成 */

        STDERR_UART->DR = (uint8_t)ch; /* 将要发送的字符 ch 写入到DR寄存器 */
    }

    return ch;
}

#elif (defined(__GNUC__)) /* 使用ARM GCC编译器 */

#pragma import(__use_no_semihosting) /* 不使用半主机模式 */

/**
 * @brief gcc文件写入函数
 *
 * @param file 文件指针
 * @param ptr 字符串
 * @param len 字符串长度
 * @return 字符串长度
 */
int _write(int file, char *ptr, int len) {
    if (file == 1) {
        for (int i = 0; i < len; i++) {
            while ((STDOUT_UART->SR & 0X40) == 0)
                ; /* 等待上一个字符发送完成 */

            STDOUT_UART->DR =
                (uint8_t)ptr[i]; /* 将要发送的字符 ch 写入到DR寄存器 */
        }
    } else if (file == 2) {
        for (int i = 0; i < len; i++) {
            while ((STDERR_UART->SR & 0X40) == 0)
                ; /* 等待上一个字符发送完成 */

            STDERR_UART->DR =
                (uint8_t)ptr[i]; /* 将要发送的字符 ch 写入到DR寄存器 */
        }
    }
    return len;
}

/**
 * @brief 调用了C库中类似exit的函数时会调用此函数
 *
 * @param x 退出的参数
 */
void _sys_exit(int x) {
    x = x;
}

#endif /* Compiler */

/**
 * @}
 */

/**
 * @defgroup 重定向断言
 * @note GCC无需定义
 * @{
 */

#if defined(__ARMCC_VERSION) /* 使用ARM Compiler */

/**
 * @brief 断言失败最终会链接到此函数
 *
 * @param expr 表达式
 * @param file 文件名
 * @param line 行数
 */
void __aeabi_assert(const char *expr, const char *file, int line) {
    fprintf(stderr, "Assertion failed: %s, file: %s, line: %d\r\n", expr, file,
            line);
}

#endif /* __ARMCC_VERSION */

/**
 * @}
 */
