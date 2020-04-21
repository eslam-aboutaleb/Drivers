#ifndef OS_interface_H
#define OS_interface_H

#define NULL 0

void OS_Scheduler(void);
void Start_OS(void);
void  OS_CreateTask(u8 NewPriority, u32 NewPeriodicity , void (*ptr)(void));


#endif
