/**
 * @file    retarget_io.c
 * @author  Deadline039
 * @brief   重定向C库的底层IO
 * @version 1.1
 * @date    2024-07-29
 * @ref     正点原子, 野火, CMSIS
 * https://developer.arm.com/documentation/100073/0611/the-c-and-c---library-functions-reference
 * https://developer.arm.com/documentation/100073/0622/The-Arm-C-and-C---Libraries/ISO-C-library-implementation-definition
 *
 * @warning 1. 不完全支持ARM GCC. printf浮点数出有问题
 *          2. 不建议在代码中使用scanf, 如果使用操作系统,
 *             可能会导致线程调度器无法正常工作
 *          3. 如果想方便的从串口接受数据, 建议使用uart_scanf()
 *          4. IAR未测试
 */

#include "stm32f1xx_hal.h"

#include "bsp_uart.h"
#include <stdarg.h>
#include <stdio.h>

#define STDOUT_UART USART1
#define STDIN_UART  USART1
#define STDERR_UART USART1

/**
 * @defgroup 重定向stdin, stdout, stderr

* @{
 */

#if defined(__ARMCC_VERSION) /* Compiler */

#if ((__ARMCC_VERSION >= 5000000) &&                                           \
     (__ARMCC_VERSION < 6000000)) /* AC5 Compiler */
struct __FILE {
    int handle;
    /* Whatever you require here. If the only file you are using is
     * standard output using printf() for debugging, no file handling
     * is required. */
};

#endif /* AC5 Compiler */

/* 如果不定义, 在不启用MicroLib的情况下会链接_sys_open */
FILE __stdout;
FILE __stderr;
FILE __stdin;

/**
 * @brief 向文件写入字符
 *
 * @param ch 写入的字符
 * @param file 文件指针
 * @return 写入的字符
 */
int fputc(int ch, FILE *file) {
    if (file == stdout) {

#ifdef STDOUT_UART

        while ((STDOUT_UART->SR & UART_FLAG_TC) == 0)
            ;

        STDOUT_UART->DR = (uint8_t)ch;
#endif /* STDOUT_UART */

    } else if (file == stderr) {

#ifdef STDERR_UART
        while ((STDERR_UART->SR & UART_FLAG_TC) == 0)
            ;

        STDERR_UART->DR = (uint8_t)ch;
#endif /* STDERR_UART */
    }

    return ch;
}

#ifdef STDIN_UART

/**
 * @brief 格式化字符串输入
 *
 * @param __format 格式控制符
 * @return 成功填充的字符个数
 */
_ARMABI int scanf(const char *__format, ...) {
    va_list ap;
    int res;
    static char scanf_buf[50];
    size_t index = -1;

    do {
        ++index;
        scanf_buf[index] = (char)fgetc(stdin);
    } while ((scanf_buf[index] != '\n') && (index < sizeof(scanf_buf)));

    va_start(ap, __format);
    res = vsscanf(scanf_buf, __format, ap);
    va_end(ap);

    return res;
}

/**
 * @brief 从文件读取字符
 *
 * @param file 文件指针
 * @return 读取到的字符
 */
int fgetc(FILE *file) {
    if (file == stdin) {
        while ((STDIN_UART->SR & UART_FLAG_RXNE) == RESET)
            ;
        return (int)STDIN_UART->DR;
    }
    return 0;
}
#endif /* STDIN_UART */

#elif (defined(__GNUC__)) /* 使用ARM GCC编译器 */

/**
 * @brief 向文件写入字符串
 *
 * @param file 文件
 * @param str 字符串
 * @param len 字符串长度
 * @return 写入的长度
 * @bug 目前该函数输入后str里面的内容是乱的, 暂时不知道是什么问题.
 */
int _write(int file, char *str, int len) {
    if (file == 1) {
#ifdef STDOUT_UART
        for (int i = 0; i < len; ++i) {
            while ((STDOUT_UART->SR & UART_FLAG_TC) == 0)
                ;

            STDOUT_UART->DR = (uint8_t)str[i];
        }
#endif /* STDOUT_UART */
    } else if (file == 2) {
#ifdef STDERR_UART
        for (int i = 0; i < len; ++i) {
            while ((STDERR_UART->SR & UART_FLAG_TC) == 0)
                ;

            STDERR_UART->DR = (uint8_t)str[i];
        }
#endif /* STDERR_UART */
    }
    return len;
}

/**
 * @brief 向文件写入字符
 *
 * @param file 文件
 * @param str 字符串
 * @param len 字符串长度
 * @return 写入的长度
 */
int _read(int file, char *str, int len) {
    int index = 0;

    if (file == 0) {
#ifdef STDIN_UART
        do {
            while ((STDIN_UART->SR & UART_FLAG_RXNE) == RESET)
                ;
            str[index] = STDIN_UART->DR;
            ++index;
        } while (str[index] != '\n');
#endif /* STDIN_UART */
    }

    return index;
}

#endif /* Compiler */

/**
 * @brief 调用了C库中类似exit的函数或退出main函数时会调用此函数
 *
 * @param x 退出的参数
 */
void _sys_exit(int x) {
    x = x;
    while (1) {
        /* Exit to endless loop. */
    }
}

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
