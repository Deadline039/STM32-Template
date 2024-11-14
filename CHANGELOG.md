# Change Log

### [v3.0.0] 2024-11-14

***Note***

- 重构Bsp，芯片外设驱动使用CSP层（即原`OnChip`层），并使用 Git 子模块管理，方便更新

- 支持切换同家族系列芯片，不需要额外手动添加文件

- FreeRTOS 升级至`202406.01-LTS`

- 修复部分注释错误

### [v2.0.3] 2024-9-26

***Note***

- 为了与多串口配置保持兼容，强制串口读写函数传入串口句柄

- 格式化部分文件

***Fix***

- 部分注释错误

- 部分头文件没有C++支持

### [v2.0.2] 2024-9-23

***Note***

- 关闭串口的DMA

***Fix***

- f429模板中串口GPIO复用不是宏定义

### [v2.0.1] 2024-9-23

***Note***

- 为了兼容多串口配置, `uart_printf`和`uart_scanf`必须传入句柄

***Fix***

- `bare_f103`中的`LED1` IO有误

### [v2.0.0] 2024-9-22

***Note***

- 重构`Bsp`层部分代码, 细分板上外设与片上外设

- 移除多串口配置, 仅保留一个串口. 

- 重新编写C库重定向, 添加`stdin`重定向

- 串口函数添加`uart_scanf()`函数, 方便接受字符串

- 考虑到EIDE并不会同步Target的编译参数与文件, 移除模板中的`Release` Target. 如果需要, 新建并删除`DEBUG`宏即可

- 添加`Utils`文件夹分组, 用于存放与芯片无关的工具

- 定义`version.h`中的版本号为模板版本号. 该文件在`User/Application/Inc/version.h`中. 

### [v1.1.2] 2024-8-29

***Note***

- 考虑到HAL库可能会使用延时, 移除重定义`HAL_Delay`

- FreeRTOS模板中`delay_ms`会根据操作系统是否运行来决定是否使用阻塞式延时

### [v1.1.1] 2024-8-26

***Fix***

- `stderr`输出Bug

### [v1.1.0] 2024-8-23

***Note***

- 添加F429模板

- 精简`retarget_io.c`文件

- 将所有编译选项(`.*option.json`)都合并到`eide.json`, 文件选项(`*.files.options.yml`)都合并到`files.options.yml`.参见:[eide/CHANGELOG.md at v3.19.6 · github0null/eide](https://github.com/github0null/eide/blob/v3.19.6/CHANGELOG.md)

- 工程的`User`分组改名为`Application`

### [v1.0.0] 2024-8-6

***Note***

- 第一版发布
