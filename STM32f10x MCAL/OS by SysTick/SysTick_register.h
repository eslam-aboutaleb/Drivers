#ifndef SYS_TICK_REG_H
#define SYS_TICK_REG_H

#define SysTick_BASE_ADDRESS 0xE000E010

#define SystemTick_CTRL  *((u32*)(SysTick_BASE_ADDRESS + 0X00))
#define SystemTick_LOAD  *((u32*)(SysTick_BASE_ADDRESS + 0X04))
#define SystemTick_VALUE *((u32*)(SysTick_BASE_ADDRESS + 0X08))

#endif
