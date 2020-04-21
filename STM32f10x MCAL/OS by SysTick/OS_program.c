#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "OS_config.h"
#include "OS_interface.h"
#include "SysTick_interface.h"



typedef struct
{
	void (*TaskHandler)(void);
	u8 Periodicity;
	
}Task;


Task SysTasks[Task_Number]; //it detemined by user fro config file

u32 TickCounter=0;

void Start_OS(void)
{
	//set timer callback to scheduler
	SystemTick_SetCallBack(OS_Scheduler);
	
	//configure timer with the value of the tick
	SystemTick_Start(2000); //tick time = 2ms
}

void OS_Scheduler(void)
{
	u8 i;

	TickCounter++;
	//loop on all tasks
	for(i=0;i<Task_Number;i++) 
	{
		//check if the task shall run at this tick
		if((TickCounter % SysTasks[i].Periodicity)==0) 
		{

		(SysTasks[i].TaskHandler)();
		}
			
	}		
}

void  OS_CreateTask(u8 NewPriority, u32 NewPeriodicity , void (*ptr)(void))
{
	SysTasks[NewPriority].Periodicity= NewPeriodicity;
	SysTasks[NewPriority].TaskHandler= ptr;
}

void OS_DeleteTask(u8 current_priority){
	SysTasks[current_priority].Periodicity= NULL;
	SysTasks[current_priority].TaskHandler= NULL;
}
