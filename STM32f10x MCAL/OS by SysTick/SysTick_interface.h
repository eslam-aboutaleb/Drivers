#ifndef SYS_TICK_Interface_H
#define SYS_TICK_Interface_H

void SystemTick_Init(void);
void SystemTick_Start(u32 Value);
void SystemTick_SetCallBack(void(*ptr)(void));

#endif
