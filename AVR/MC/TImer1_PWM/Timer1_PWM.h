/* ///////////////////////////////////////////////////////////////////////////
 * Timer1_PWM.h
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#ifndef TIMER1_PWM_H_
#define TIMER1_PWM_H_

#ifndef TIMER1_ENABLED
#define TIMER1_PWM_ENABLED
#endif

#ifndef F_CPU
#define F_CPU 8000000UL
#endif


typedef enum
{
	Normal_Port_Operation,
	Tog_OC1A_CompMatch_OC1B_Disconnected,
	Clr_OC1A_OC1B_CompMatch,
	Set_OC1A_OC1B_CompMatch
}PWM_Com_OutputMode;

typedef enum
{
	OC1A_Pin,
	OC1B_Pin
}PWM_Channels;

typedef enum
{
TIMER1_WGM_PWM_8      ,
TIMER1_WGM_PWM_9      ,
TIMER1_WGM_PWM_10     ,
TIMER1_WGM_FPWM_8     ,
TIMER1_WGM_FPWM_9     ,
TIMER1_WGM_FPWM_10    ,
TIMER1_WGM_PWM_PF_ICR ,
TIMER1_WGM_PWM_PF_OCR ,
TIMER1_WGM_PWM_P_ICR  ,
TIMER1_WGM_PWM_P_OCR  ,
TIMER1_WGM_FPWM_ICR   ,
TIMER1_WGM_FPWM_OCR   

}PWM_Mode;


typedef enum
{
	NO_Clock_Source,
	Prescaler_1,
	Prescaler_8,
	Prescaler_64,
	Prescaler_256,
	Prescaler_1024,
	Preascaler_ExClockT1_Falling,
	Preascaler_ExClockT1_Rising
}PWM_ClockPrescaler;
typedef struct
{
	PWM_Com_OutputMode COM_Mode;
	PWM_Mode Mode;
	PWM_Channels Channel;
	uint16 uiOCR1A;
	uint16 uiOCR1B;
}PWM_Typedef;


void PWM_Init(PWM_Typedef *PWM_ConfigPtr);
void PWM_Stop(void);
void PWM_SetPrescaler(PWM_ClockPrescaler Prescaler);
void PWM_SetChannels(PWM_Com_OutputMode OutputMode,PWM_Channels Channel);
void PWM_Set_OCR1A(uint16 uiOCR1A);
void PWM_Set_OCR1B(uint16 uiOCR1B);
void PWM_SetFPWM_Freq(uint16 Freq);
void PWM_SetPWM_Freq(uint16 Freq);
void PWM_Set_TONus(uint16 Time,PWM_Channels Channel);

#endif /* TIMER1_PWM_H_ */