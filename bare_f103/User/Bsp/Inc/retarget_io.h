/**
 * @file    retarget_io.h
 * @author  Deadline039
 * @brief   重定向C库的底层IO
 * @version 1.0
 * @date    2024-07-29
 */

#ifndef __RETARGET_IO_H
#define __RETARGET_IO_H

#include "stm32f1xx_hal.h"

// <<< Use Configuration Wizard in Context Menu >>>

// <e> 重定向stdout
#define RETARGET_STDOUT 1

#if (RETARGET_STDOUT == 1)

// <o RE_STDOUT_TARGET> 重定向stdout位置
//  <0=>串口 <1=>ITM
#define RE_STDOUT_TARGET 0

#if (RE_STDOUT_TARGET == 0)

// <o STDOUT_UART> stdout的串口
//  <USART1=> 串口1
//  <USART2=> 串口2
//  <USART3=> 串口3
//  <UART4=> 串口4
//  <UART5=> 串口5
#define STDOUT_UART USART1

#endif /* RE_STDOUT_TARGET == 0 */

#endif /* RETARGET_STDOUT == 1 */

// </e>

// <e> 重定向stderr
#define RETARGET_STDERR 1

#if (RETARGET_STDERR == 1)

// <o RE_STDERR_TARGET> 重定向stderr位置
//  <0=>串口 <1=>ITM
#define RE_STDERR_TARGET 0

#if (RE_STDERR_TARGET == 0)

// <o STDERR_UART> stderr的串口
//  <USART1=> 串口1
//  <USART2=> 串口2
//  <USART3=> 串口3
//  <UART4=> 串口4
//  <UART5=> 串口5
#define STDERR_UART USART1

#endif /* RE_STDERR_TARGET == 0 */

#endif /* RETARGET_STDOUT == 1 */

// </e>

// <<< end of configuration section >>>

#endif /* __RETARGET_IO_H */
