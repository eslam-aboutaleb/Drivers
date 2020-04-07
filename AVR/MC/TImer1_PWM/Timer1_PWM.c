#include <avr//io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Timer1_PWM.h"

static void PWM_SetMode(PWM_Mode Mode);


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

void PWM_Start(PWM_ClockPrescaler Prescaler)
{
	switch(Prescaler)
	{
		case NO_Clock_Source:
		CLEAR_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case Prescaler_1:
		SET_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case Prescaler_8:
		CLEAR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case Prescaler_64:
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		break;
		case Prescaler_256:
		CLEAR_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
		break;
		case Prescaler_1024:
		SET_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS12);
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