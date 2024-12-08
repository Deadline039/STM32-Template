/**
 * @file    FreeRTOSConfig.h
 * @author  Deadline039
 * @brief   FreeRTOS 配置项
 * @version 1.0
 * @date    2024-08-04
 */

#ifndef __FREERTOS_CONFIG_H
#define __FREERTOS_CONFIG_H

extern uint32_t SystemCoreClock;

/* 定义CPU主频, 单位: Hz, 无默认需定义 */
#define configCPU_CLOCK_HZ                        (SystemCoreClock)
/* 定义 SysTick 时钟频率. 当SysTick时钟频率与内核时钟频率不同时才可以定义.
 * 单位: Hz. 默认: 不定义 */
#define configSYSTICK_CLOCK_HZ                    (configCPU_CLOCK_HZ / 8)

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

// <h>基础配置项
// =============================================================================

//  <q>使用抢占式调度
//  <i> 如果不使用抢占式调度, 将使用协程式调度. 建议使用抢占式调度
#define configUSE_PREEMPTION                      1

//  <q>使用硬件计算下一个要运行的任务
//  <i> 默认: 0
#define configUSE_PORT_OPTIMISED_TASK_SELECTION   1

//  <q>启用tickless低功耗模式
//  <i> 如果启用tickless模式, 当在Idle时停止tick周期中断.
//  <i> 如果禁用, 将会一直产生tick周期中断
//  <i> 默认: 0
#define configUSE_TICKLESS_IDLE                   0

//  <o>系统时钟节拍频率 [Hz] <0-0xFFFFFFFF>
#define configTICK_RATE_HZ                        ((TickType_t)1000)

//  <o>最大优先级
#define configMAX_PRIORITIES                      32

//  <o>空闲任务的栈空间大小 [words] <0-65535>
#define configMINIMAL_STACK_SIZE                  ((uint16_t)(128))

//  <o>任务名最大长度 [bytes]
//  <i> 默认: 16
#define configMAX_TASK_NAME_LEN                   16

//  <q>定义系统时钟节拍计数器的数据类型为uint16
#define configUSE_16_BIT_TICKS                    0

//  <q>Idle可以被抢占
//  <i> 在抢占式调度下, 同优先级的任务可以抢占Idle任务.
//  <i> 默认: 1
#define configIDLE_SHOULD_YIELD                   1

//  <q>启用任务间直接的消息传递
//  <i> 如果禁用, 信号量, 事件标记组, 消息邮箱都无法使用
//  <i> 默认: 1
#define configUSE_TASK_NOTIFICATIONS              1

//  <o>定义任务通知数组的大小
//  <i> 默认: 1
#define configTASK_NOTIFICATION_ARRAY_ENTRIES     1

//  <q>启用互斥信号量
//  <i> 默认: 0
#define configUSE_MUTEXES                         1

//  <q>启用递归互斥信号量
//  <i> 默认: 0
#define configUSE_RECURSIVE_MUTEXES               1

//  <q>启用计数信号量
//  <i> 默认: 0
#define configUSE_COUNTING_SEMAPHORES             1

//  <o>可以注册的信号量和消息队列的个数
//  <i> 默认: 0
#define configQUEUE_REGISTRY_SIZE                 8

//  <q>启用队列集
//  <i> 默认: 0
#define configUSE_QUEUE_SETS                      1

//  <q>启用时间片调度
//  <i> 默认: 1
#define configUSE_TIME_SLICING                    1

//  <q>任务创建时分配Newlib的重入结构体
//  <i> 默认: 0
#define configUSE_NEWLIB_REENTRANT                0

//  <q>兼容旧版
//  <i> 默认: 1
#define configENABLE_BACKWARD_COMPATIBILITY       0

//  <o>定义线程本地存储指针的个数
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS   0

// </h>

/* 定义任务堆栈深度的数据类型, 默认: uint16_t */
#define configSTACK_DEPTH_TYPE                    uint16_t
/* 定义消息缓冲区中消息长度的数据类型, 默认: size_t */
#define configMESSAGE_BUFFER_LENGTH_TYPE          size_t

// <h>内存分配相关
// =============================================================================

//  <q>支持静态申请内存
//  <i> 默认: 0
#define configSUPPORT_STATIC_ALLOCATION           0

//  <q>支持动态申请内存
//  <i> 默认: 1
#define configSUPPORT_DYNAMIC_ALLOCATION          1

//  <o>堆内存总大小 [byte] <0-65535>
#define configTOTAL_HEAP_SIZE                     ((size_t)8192)

//  <q>用户手动分配FreeRTOS内存堆
//  <i> 默认: 0
#define configAPPLICATION_ALLOCATED_HEAP          0

//  <q>用户自行实现任务创建时使用的内存申请与释放函数
//  <i> 默认: 0
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP 0

// </h>

// <h>钩子函数相关
// =============================================================================

//  <q>使用Idle钩子函数
//  <i> 在空闲时调用vApplicationIdleHook钩子函数
#define configUSE_IDLE_HOOK                       0

//  <q>使用Tick钩子函数
//  <i> 在每个tick中断发生时调用vApplicationTickHook钩子函数
#define configUSE_TICK_HOOK                       0

//  <o>检查堆栈溢出
//    <0=>禁用 <1=>方式1 <2=>方式2 <3=>方式3
//  <i> 当堆栈溢出时, 调用vApplicationStackOverflowHook钩子函数
//  <i> 不同方式区别参照FreeRTOS官方文档
//  <i> 默认: 0
#define configCHECK_FOR_STACK_OVERFLOW            0

//  <q>启用定时器服务Startup钩子函数
//  <i> 在定时器服务首次执行前调用vApplicationDaemonTaskStartupHook钩子函数
//  <i> 默认: 0
#define configUSE_DAEMON_TASK_STARTUP_HOOK        0

//  <q>使用动态内存分配失败钩子函数
//  <i> 在动态内存分配失败时调用vApplicationMallocFailedHook钩子函数
//  <i> 默认: 0
#define configUSE_MALLOC_FAILED_HOOK              0

// </h>

// <h>运行时间和任务状态统计相关定义
// =============================================================================

//  <q>启用任务运行时间统计功能
//  <i> 默认: 0
#define configGENERATE_RUN_TIME_STATS             0

#if (configGENERATE_RUN_TIME_STATS == 1)
#include "btim.h"
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() ConfigureTimeForRunTimeStats()
extern uint32_t FreeRTOSRunTimeTicks;
#define portGET_RUN_TIME_COUNTER_VALUE() FreeRTOSRunTimeTicks
#endif /* configGENERATE_RUN_TIME_STATS == 1 */

//  <q>使用可视化跟踪调试
//  <i> 默认: 0
#define configUSE_TRACE_FACILITY             1

//  <q>使用格式化输出函数
//  <i> 启用后, 会编译vTaskList()和vTaskGetRunTimeStats()函数.
//  <i> 默认: 0
#define configUSE_STATS_FORMATTING_FUNCTIONS 1

// </h>

// <h>协程相关定义

//  <q>启用协程
//  <i> 默认: 0
#define configUSE_CO_ROUTINES                0

//  <o>协程最大优先级
//  <i> 启用协程后需定义
#define configMAX_CO_ROUTINE_PRIORITIES      2

// </h>

// <e>启用软件定时器
// =============================================================================
#define configUSE_TIMERS                     1

//  <o>软件定时器任务的栈空间大小 [words] <0-65535>
#define configTIMER_TASK_STACK_DEPTH         256

//  <o>软件定时器任务的优先级 <0-56>
#define configTIMER_TASK_PRIORITY            31

//  <o>软件定时器命令队列长度 <0-1024>
#define configTIMER_QUEUE_LENGTH             5

// </e>

//------------- <<< end of configuration section >>> ---------------------------

/* 可选函数, 1: 启用 */
#define INCLUDE_vTaskPrioritySet             1 /* 设置任务优先级 */
#define INCLUDE_uxTaskPriorityGet            1 /* 获取任务优先级 */
#define INCLUDE_vTaskDelete                  1 /* 删除任务 */
#define INCLUDE_vTaskSuspend                 1 /* 挂起任务 */
#define INCLUDE_xResumeFromISR               1 /* 恢复在中断中挂起的任务 */
#define INCLUDE_vTaskDelayUntil              1 /* 任务绝对延时 */
#define INCLUDE_vTaskDelay                   1 /* 任务延时 */
#define INCLUDE_xTaskGetSchedulerState       1 /* 获取任务调度器状态 */
#define INCLUDE_xTaskGetCurrentTaskHandle    1 /* 获取当前任务的任务句柄 */
#define INCLUDE_uxTaskGetStackHighWaterMark  1 /* 获取任务堆栈历史剩余最小值 */
#define INCLUDE_xTaskGetIdleTaskHandle       1 /* 获取空闲任务的任务句柄 */
#define INCLUDE_eTaskGetState                1 /* 获取任务状态 */
#define INCLUDE_xEventGroupSetBitFromISR     1 /* 在中断中设置事件标志位 */
#define INCLUDE_xTimerPendFunctionCall       1 /* 将函数的执行挂到定时器服务任务 */
#define INCLUDE_xTaskAbortDelay              1 /* 中断任务延时 */
#define INCLUDE_xTaskGetHandle               1 /* 通过任务名获取任务句柄 */
#define INCLUDE_xTaskResumeFromISR           1 /* 恢复在中断中挂起的任务 */

/* 中断嵌套行为配置 */
#ifdef __NVIC_PRIO_BITS
#define configPRIO_BITS __NVIC_PRIO_BITS
#else
#define configPRIO_BITS 4
#endif

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY      15 /* 中断最低优先级 */
/* FreeRTOS可管理的最高中断优先级 */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5
#define configKERNEL_INTERRUPT_PRIORITY                                        \
    (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))
#define configMAX_SYSCALL_INTERRUPT_PRIORITY                                   \
    (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))
#define configMAX_API_CALL_INTERRUPT_PRIORITY                                  \
    configMAX_SYSCALL_INTERRUPT_PRIORITY

/* 断言 */
#include <stdio.h>
#define vAssertCalled(char, int) printf("Error: %s, %d\r\n", char, int)
#define configASSERT(x)                                                        \
    if ((x) == 0)                                                              \
    vAssertCalled(__FILE__, __LINE__)

/* 重定向FreeRTOS中断服务相关函数到系统中断 */
#define xPortPendSVHandler PendSV_Handler
#define vPortSVCHandler    SVC_Handler

#endif /* __FREERTOS_CONFIG_H */
