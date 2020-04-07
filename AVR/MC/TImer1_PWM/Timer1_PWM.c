/* ///////////////////////////////////////////////////////////////////////////
 * Timer1_PWM.c
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#include <avr//io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer1_PWM.h"
#include "MathFuncs.h"

static void PWM_SetMode(PWM_Mode Mode);

static uint16 Global_Prescaler=1;

PWM_Init(PWM_Typedef *PWM_ConfigPtr)
{
	PWM_SetChannels(PWM_ConfigPtr->COM_Mode,PWM_ConfigPtr->Channel);
	switch(PWM_ConfigPtr->Channel)
	{
		case OC1A_Pin:
		PWM_Set_OCR1A(PWM_ConfigPtr->uiOCR1A);
		break;
		case OC1B_Pin:
		PWM_Set_OCR1A(PWM_ConfigPtr->uiOCR1B);
		break;
		default:
		break;
		
	}
	PWM_SetMode(PWM_ConfigPtr->Mode);
}

void PWM_SetPrescaler(PWM_ClockPrescaler Prescaler)
{
	switch(Prescaler)
	{
		case NO_Clock_Source:
		CLEAR_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		Prescaler=0;
		break;
		case Prescaler_1:
		SET_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		
		Global_Prescaler=1;
		break;
		
		case Prescaler_8:
		CLEAR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		
		Global_Prescaler=8;
		break;
		
		case Prescaler_64:
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		
		Global_Prescaler=64;
		break;
		
		case Prescaler_256:
		CLEAR_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		
		Global_Prescaler=256;
		break;
		
		case Prescaler_1024:
		SET_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		
		Global_Prescaler=1024;
		break;
		
		case Preascaler_ExClockT1_Falling:
		CLEAR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
		case Preascaler_ExClockT1_Rising:
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
		default:
		break;
	}
}

void PWM_Stop(void)
{
	CLEAR_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
}

void PWM_SetChannels(PWM_Com_OutputMode OutputMode,PWM_Channels Channel)
{
	switch(OutputMode)
	{
		case Normal_Port_Operation:
		if (Channel==OC1A_Pin)
		{
			CLEAR_BIT(TCCR1A,COM1A1);
			CLEAR_BIT(TCCR1A,COM1A0);
		}
		else if (Channel==OC1B_Pin)
		{
			CLEAR_BIT(TCCR1A,COM1B1);
			CLEAR_BIT(TCCR1A,COM1B0);
		}
		break;
		
		case Tog_OC1A_CompMatch_OC1B_Disconnected:
		if (Channel==OC1A_Pin)
		{
			CLEAR_BIT(TCCR1A,COM1A1);
			SET_BIT(TCCR1A,COM1A0);
		}
		else if (Channel==OC1B_Pin)
		{
			CLEAR_BIT(TCCR1A,COM1B1);
			SET_BIT(TCCR1A,COM1B0);
		}
		break;
		
		case Clr_OC1A_OC1B_CompMatch:
		if (Channel==OC1A_Pin)
		{
			SET_BIT(TCCR1A,COM1A1);
			CLEAR_BIT(TCCR1A,COM1A0);
		}
		else if (Channel==OC1B_Pin)
		{
			SET_BIT(TCCR1A,COM1B1);
			CLEAR_BIT(TCCR1A,COM1B0);
		}
		break;
		
		case Set_OC1A_OC1B_CompMatch:
		if (Channel==OC1A_Pin)
		{
			SET_BIT(TCCR1A,COM1A1);
			SET_BIT(TCCR1A,COM1A0);
		}
		if (Channel==OC1B_Pin)
		{
			SET_BIT(TCCR1A,COM1B1);
			SET_BIT(TCCR1A,COM1B0);
		}
		break;
		
		default:
		break;
	}
}

static void PWM_SetMode(PWM_Mode Mode)
{
	switch(Mode)
	{
		case TIMER1_WGM_PWM_8     :
		SET_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_PWM_9     :
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_PWM_10	  :
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_FPWM_8	  :
		SET_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_FPWM_9	  :
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_FPWM_10	  :
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_PWM_PF_ICR:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_PWM_PF_OCR:
		SET_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_PWM_P_ICR :
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_PWM_P_OCR :
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_FPWM_ICR  :
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_WGM_FPWM_OCR  :
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1A,WGM12);
		SET_BIT(TCCR1A,WGM13);
		break;
	}
	
}

void PWM_Set_OCR1A(uint16 uiOCR1A)
{
	OCR1A=uiOCR1A;
}
void PWM_Set_OCR1B(uint16 uiOCR1B)
{
	OCR1B=uiOCR1B;
}

void PWM_SetFPWM_Freq(uint16 Freq)
{
	/*The PWM resolution for fast PWM can be fixed to 8-bit, 9-bit, or 10-bit, or defined by either ICR1
	or OCR1A*/
	ICR1=(uint16)(F_CPU/(Freq*Global_Prescaler))-1;
}

void PWM_SetPWM_Freq(uint16 Freq)
{
	/*The PWM resolution for Phase correct PWM can be fixed to 8-bit, 9-bit, or 10-bit, or defined by either ICR1
	or OCR1A*/
	ICR1=(uint16)(F_CPU/(Freq*Global_Prescaler*2));
}

void PWM_Set_TONus(uint16 Time,PWM_Channels Channel)
{
	uint16 Val =(uint16)(Time/((Global_Prescaler/F_CPU)*PWR(10,6)));
	switch(Channel)
	{
		case OC1A_Pin:
		PWM_Set_OCR1A(Val);
		break;
		case OC1B_Pin:
		PWM_Set_OCR1B(Val);
		break;
		default:
		break;
	}
	
}
