#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_private.h"
#include "RCC_interface.h"

/*Function to initialize prephirals clock*/
void RCC_ClockInit(RCC_ClockSrc Clock)
{	
	/*First clear configuration bits*/
	CLEAR_BIT(RCC->CFGR,0);
	CLEAR_BIT(RCC->CFGR,1);
	switch(Clock)
	{ 	
    case HSI:
		SET_BIT(RCC->CR,0);
		while(BIT_IS_CLEAR(RCC->CR,1));
		CLEAR_BIT(RCC->CFGR,0);
		CLEAR_BIT(RCC->CFGR,1);
		break;
		
		case HSE:
		SET_BIT(RCC->CR,16);
		while(BIT_IS_CLEAR(RCC->CR,17));
		SET_BIT(RCC->CFGR,0);
		CLEAR_BIT(RCC->CFGR,1);
		break;
		
		case PLL:
		SET_BIT(RCC->CR,24);
		while(BIT_IS_CLEAR(RCC->CR,25));
		CLEAR_BIT(RCC->CFGR,0);
		SET_BIT(RCC->CFGR,1);
		break;
	}
}

/* Function to enable and disable prephiral clock*/
void RCC_SetCLKprephiral(RCC_BUS Bus,RCC_Peripheral Prephiral,RCC_PeripheralState State)
{
	switch(Bus)
	{
		case RCC_AHB:
			if(State==Enable_Prephiral)
			{
				SET_BIT(RCC->AHB1ENR,Prephiral);
			}
			else
			{
				CLEAR_BIT(RCC->AHB1ENR,Prephiral);
			}
			break;
			
			case RCC_APB1:
			if(State==Enable_Prephiral)
			{
				SET_BIT(RCC->APB1ENR,Prephiral);
			}
			else
			{
				CLEAR_BIT(RCC->APB1ENR,Prephiral);
			}
			break;
			
			case RCC_APB2:
			if(State==Enable_Prephiral)
			{
				SET_BIT(RCC->APB2ENR,Prephiral);
			}
			else
			{
				CLEAR_BIT(RCC->APB2ENR,Prephiral);
			}
			break;
	}

}

