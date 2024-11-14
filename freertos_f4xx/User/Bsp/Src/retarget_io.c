/**
 * @file    retarget_io.c
 * @author  Deadline039
 * @brief   Retarget C library system I/O interface.
 * @version 1.1
 * @date    2024-07-29
 * @ref
 * https://developer.arm.com/documentation/100073/0611/the-c-and-c---library-functions-reference
 * https://developer.arm.com/documentation/100073/0622/The-Arm-C-and-C---Libraries/ISO-C-library-implementation-definition
 *
 * @warning 1. ARM GCC is not fully supported. There are problems with printf
 *             floating point numbers
 *          2. It is not recommended to use scanf() in the code. If you use the
 *             operating system, it may cause the thread scheduler to not work
 *             properly
 *          3. If you want to easily receive data from the serial port, it is
 *             recommended to use uart_scanf()
 *          4. IAR has not been tested
 *          5. Only support C99 and later.
 */

#include "stm32f4xx_hal.h"

#include <stdio.h>

#define STDOUT_UART USART1
#define STDIN_UART  USART1
#define STDERR_UART USART1

/**
 * @defgroup retarget stdin, stdout, stderr
 * @{
 */

/**
 * @brief Put char into uart.
 *
 * @param uart The uart to send.
 * @param ch The char will be sent.
 */
static void __io_putchar_uart(USART_TypeDef *uart, char ch) {
    while ((uart->SR & UART_FLAG_TC) == 0)
        ;

    uart->DR = (uint8_t)ch;
}

/**
 * @brief Get char from uart.
 *
 * @param uart The uart to receive.
 * @return The char which received.
 */
static char __io_getchar_uart(USART_TypeDef *uart) {
    while ((uart->SR & UART_FLAG_RXNE) == RESET)
        ;
    return (int)uart->DR;
}

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

/* If not defined, linker will link _sys_open when not enable MicroLib */
FILE __stdout;
FILE __stderr;
FILE __stdin;

/**
 * @brief Write a character to file.
 *
 * @param ch The character will be written.
 * @param file File pointer.
 * @return The character which be written.
 */
int fputc(int ch, FILE *file) {
    if (file == stdout) {

#ifdef STDOUT_UART
        __io_putchar_uart(STDOUT_UART, ch);
#else /* STDOUT_UART */
        /* Your implement here. */

#endif /* STDOUT_UART */

    } else if (file == stderr) {

#ifdef STDERR_UART
        __io_putchar_uart(STDERR_UART, ch);
#else /* STDERR_UART */
        /* Your implement here. */

#endif /* STDERR_UART */
    }

    return ch;
}

/**
 * @brief Read character from file.
 *
 * @param file file pointer.
 * @return the next character from the input stream pointed to by stream.
 *         If the stream is at end-of-file, the end-of-file indicator is
 *         set and getc returns EOF. If a read error occurs, the error
 *         indicator is set and getc returns EOF.
 */
int fgetc(FILE *file) {
    if (file == stdin) {
#ifdef STDIN_UART
        return __io_getchar_uart(STDIN_UART);
#else /* STDIN_UART */
        /* Your implement here.  */

#endif /* STDIN_UART */
    }
    return 0;
}

#elif (defined(__GNUC__)) /* Using ARM GCC. */

/**
 * @brief Write a string to file.
 *
 * @param file The file will to write.
 * @param str The string will be written.
 * @param len The length of string.
 * @return The length of string successfully written.
 */
int _write(int file, char *str, int len) {
    if (file == 1) {
#ifdef STDOUT_UART
        for (int i = 0; i < len; ++i) {
            __io_putchar_uart(STDOUT_UART);
#else /* STDOUT_UART */
        /* Your implement here. */

#endif /* STDOUT_UART */
        }
    } else if (file == 2) {
#ifdef STDERR_UART
        for (int i = 0; i < len; ++i) {
            __io_putchar_uart(STDERR_UART);
#else /* STDERR_UART */
    /* Your implement here. */

#endif /* STDERR_UART */
        }
    }
    return len;
}

/**
 * @brief Read string from file.
 *
 * @param file The file will be read.
 * @param str The string buffer will be written.
 * @param len The string length.
 */
int _read(int file, char *str, int len) {

    if (file == 0) {
        for (int i = 0; i < len; ++i) {
#ifdef STDIN_UART
            __io_getchar_uart(STDIN_UART);
#else /* STDIN_UART */
            /* Your implement here. */

#endif /* STDIN_UART */
        }
    }

    return index;
}

#endif /* Compiler */

/**
 * @brief This function will be called when exit main().
 *
 * @param x The exit parameter.
 */
void _sys_exit(int x) {
    HAL_DeInit();

    x = x;
    while (1) {
        /* Exit to endless loop. */
    }
}

/**
 * @}
 */

#if (defined(__ARMCC_VERSION) && defined(__MICROLIB))

/**
 * @brief This function will be called when assert failed.
 *
 * @param expr Expression.
 * @param file File name.
 * @param line Line.
 */
void __aeabi_assert(const char *expr, const char *file, int line) {
    fprintf(stderr, "Assertion failed: %s, file: %s, line: %d\r\n", expr, file,
            line);
    while (1) {
        /* Go to endless loop when assert failed. */
    }
}

#endif /* __ARMCC_VERSION && __MICROLIB */
