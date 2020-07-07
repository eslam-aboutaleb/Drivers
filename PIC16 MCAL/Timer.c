/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: Timer.c
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#include "Main.h"
#include "Timer.h"
#include "SW.h"
#include "WH.h"
#include "Display.h"
#include "SSD.h"
#include "Heating_element.h"
#include "Cooling_element.h"
#include "TempSensor.h"

static void WH_ON_TimeLine(void);
static void WH_OFF_TimeLine(void);

/* /////////////////////////////////////////////////////////////////////////////////
Func: TMR_Init
Parameters: void
Return: void
job: Initialize timer0 in PIC MCU at prescaler 256
///////////////////////////////////////////////////////////////////////////////// */
void TMR_Init(void)
{
	TMR_SET_PRESCALER_256;
	TMR_DISABLE_CLOCK;
	/*Dummy pulse to simulate the ZCD module*/
}

/* /////////////////////////////////////////////////////////////////////////////////
Func: TMR_Start
Parameters: void
Return: void
Job: Starts the timer
///////////////////////////////////////////////////////////////////////////////// */
void TMR_Start(void)
{
	TMR_CLEAR_FLAG;
	TMR_ENABLE_INTERRUPT;
	GLOBAL_INTERRUPT_ENABLE;
	TMR_ENABLE_CLOCK;
}

/* /////////////////////////////////////////////////////////////////////////////////
Func: TMR_CheckOverFlow
Parameters: void
Return: tByte
job: checks overflow of the timer
///////////////////////////////////////////////////////////////////////////////// */
tByte TMR_CheckOverFlow(void)
{
	return TMR_GET_FLAG;
}

/* /////////////////////////////////////////////////////////////////////////////////
Func: TMR_Stop
Parameters: void
Return: void
job: Stops the timer
///////////////////////////////////////////////////////////////////////////////// */
void TMR_Stop(void)
{
	TMR_DISABLE_CLOCK;
}

/* /////////////////////////////////////////////////////////////////////////////
Func: TMR_Update
Parameters: void
return: void
Job: Non vectored timer0 interrupt will be called every Timer tick and execute
the included tasks.
////////////////////////////////////////////////////////////////////////////// */
void TMR_Update(void) __interrupt 0
{
    /* Reload timer */
	TMR_CLEAR_FLAG;
	TMR_UPDATE_REGISTER(TMR_TICK_MS);
	/*Check if the Water heater is on*/
	if(WH_GetState()== WH_ON)
    {
        WH_ON_TimeLine();
    }
    else
    {
        WH_OFF_TimeLine();
    }
}
/*Turn on time line*/
static void WH_ON_TimeLine(void)
{
    SSD_Update();
	SW_Update();
	TempS_Update();
	DISP_Update();
	WH_Update();
}
/*Turn off time line */
static void WH_OFF_TimeLine(void)
{
    /*Make LCD_Null & led off*/
    DISP_Init();
    /*Turn off Heater and cooler*/
    Heat_SetState(Heat_Res,HEAT_OFF);
    Cool_SetState(COOL_FAN,COOL_OFF);
    /*Check SW for next updates*/
    SW_Update();
    WH_Update();
}
