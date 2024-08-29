# Change Log

### [v1.1.2] 2024-8-29

***Note***

- 考虑到HAL库可能会使用延时，移除重定义`HAL_Delay`

- FreeRTOS模板中`delay_ms`会根据操作系统是否运行来决定是否使用阻塞式延时

### [v1.1.1] 2024-8-26

***Fix***

- `stderr`输出Bug

### [v1.1.0] 2024-8-23

***Note***

- 添加F429模板

- 精简`retarget_io.c`文件

- 将所有编译选项(`.*option.json`)都合并到`eide.json`、文件选项(`*.files.options.yml`)都合并到`files.options.yml`。参见：[eide/CHANGELOG.md at v3.19.6 · github0null/eide](https://github.com/github0null/eide/blob/v3.19.6/CHANGELOG.md)

- 工程的`User`分组改名为`Application`

### [v1.0.0] 2024-8-6

***Note***

- 第一版发布
