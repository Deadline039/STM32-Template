# Change Log

### [v3.3.2] 2025-5-19

***Fix***

- 某些外设 IO 由于大小写问题导致未能添加

- GCC 编译器下重定向`stdout, stderr`报错

### [v3.3.1] 2025-4-25

***Note***

- 忽略模板中的编译产生的文件与 macOS 的特定文件

***Fix***

- F1 CSP 配置文件外设添加条件编译

- H7 DMA 发送实例错误

- F4 SPI 头文件错误

### [v3.3.0] 2025-4-10

***Note***

- 添加 H7 模板

- HAL 库配置添加 CMSIS Config Wizard

- 添加 QSPI

- G4, H7 I2C 集成时序计算

- I2C 初始化单位改为 kHz

- G4 添加外设时钟配置

- CSP 头文件添加版本号

- 打开编译器 `-Wundef` 警告

- F1 判断外设初始化状态改为`HAL_xxx_GetState`

***Fix***

- I2C deinit 函数没有关闭中断

- G4 FDCAN deinit 函数会被中断宏定义屏蔽

- G4 打开 DMA 编译报错

- 配置文件语法错误导致 Keil 解析错误

- G4 LPUART 没有加 DMA 判断

- F1 去掉 UART5 DMA 判断

- 若干注释错误

- 某些外设初始化状态枚举类型错误

### [v3.2.0] 2025-3-17

***Note***

- 优化 HAL 库断言函数

- 优化 FreeRTOS 断言函数

- 增加 FreeRTOS 堆栈溢出与内存分配失败钩子函数的实现

***Fix***

- CAN 发送函数数据头 bug

- 延长 CAN 发送邮箱等空时间

### [v3.1.6] 2025-3-14

***Fix***

- F4 启用 CAN2 后无法初始化

- F1 启用 UART4 发送 DMA 后丢失中断服务函数

- 单词拼写错误

### [v3.1.5] 2025-2-27

***Fix***

- F4 CAN 中断宏定义名称错误导致中断无法使用

- G4 RTC 配置丢失

### [v3.1.4] 2025-2-23

***Fix***

- F1 启用 SPI1 复用时禁用 JTAG. 

- F4 启用 CAN 外设报错

### [v3.1.3] 2025-2-13

***Note***

- 修改代码风格，禁止自动排序`#include, using`和注释

***Fix***

- HAL 库断言`printf`格式控制符错误

### [v3.1.2] 2025-2-5

***Note***

- 使用 python 解析 STM32F4 datasheet 来生成 CSP 层文件

- 更新 CSP 内存管理宏定义

### [v3.1.1] 2025-1-18

***Note***

- 修改包含括号为尖括号

- 规范注释

### [v3.1.0] 2024-12-8

***Fix***

- STM32F1 CSP Bug:

  - SPI IO 错误

  - I2C IO 错误

- STM32F4 CSP Bug:

  - CAN 函数名错误

***Note***

  - 添加 STM32G4 模板

  - 修改目录结构，将 Bsp 移动到 Drivers 中，移除 Inc, Src 文件夹，采用相对路径定位头文件。

  - 修改 CSP 头文件路径

### [v3.0.1] 2024-11-30

***Fix***

- STM32F1 CSP Bug：
 
  - 串口格式化输入输出
  
  - 启用串口 DMA 后无法接收

  - CAN IO 复用

- STM32F4 CSP Bug：
  
  - 启用其他串口编译报错

  - 串口格式化输入输出
  
  - 启用串口 DMA 后无法接收

  - 启用 SPI5 硬件片选编译报错

  - 启用 CAN1 后 CAN2 无法正常初始化

***Note***

- CSP 添加 Ethernet, RTC 驱动

### [v3.0.0] 2024-11-14

***Note***

- 重构 Bsp，芯片外设驱动使用 CSP 层（即原 `OnChip` 层），并使用 Git 子模块管理，方便更新

- 支持切换同家族系列芯片，不需要额外手动添加文件

- FreeRTOS 升级至 `202406.01-LTS`

- 修复部分注释错误

### [v2.0.3] 2024-9-26

***Note***

- 为了与多串口配置保持兼容，强制串口读写函数传入串口句柄

- 格式化部分文件

***Fix***

- 部分注释错误

- 部分头文件没有 C++ 支持

### [v2.0.2] 2024-9-23

***Note***

- 关闭串口的 DMA

***Fix***

- f429 模板中串口 GPIO 复用不是宏定义

### [v2.0.1] 2024-9-23

***Note***

- 为了兼容多串口配置，`uart_printf` 和 `uart_scanf` 必须传入句柄

***Fix***

- `bare_f103` 中的 `LED1` IO 有误

### [v2.0.0] 2024-9-22

***Note***

- 重构 `Bsp` 层部分代码，细分板上外设与片上外设

- 移除多串口配置，仅保留一个串口. 

- 重新编写 C 库重定向，添加 `stdin` 重定向

- 串口函数添加 `uart_scanf ()` 函数，方便接受字符串

- 考虑到 EIDE 并不会同步 Target 的编译参数与文件，移除模板中的 `Release` Target. 如果需要，新建并删除 `DEBUG` 宏即可

- 添加 `Utils` 文件夹分组，用于存放与芯片无关的工具

- 定义 `version.h` 中的版本号为模板版本号。该文件在 `User/Application/Inc/version.h` 中. 

### [v1.1.2] 2024-8-29

***Note***

- 考虑到 HAL 库可能会使用延时，移除重定义 `HAL_Delay`

- FreeRTOS 模板中 `delay_ms` 会根据操作系统是否运行来决定是否使用阻塞式延时

### [v1.1.1] 2024-8-26

***Fix***

- `stderr` 输出 Bug

### [v1.1.0] 2024-8-23

***Note***

- 添加 F429 模板

- 精简 `retarget_io.c` 文件

- 将所有编译选项 (`.*option.json`) 都合并到 `eide.json`, 文件选项 (`*.files.options.yml`) 都合并到 `files.options.yml`. 参见:[eide/CHANGELOG.md at v3.19.6・github0null/eide](https://github.com/github0null/eide/blob/v3.19.6/CHANGELOG.md)

- 工程的 `User` 分组改名为 `Application`

### [v1.0.0] 2024-8-6

***Note***

- 第一版发布
