#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "RCC_interface.h"
#include  "RCC_register.h"

void RCC_ClockInit(void)
{
	RCC_CR   = 0x00010000;
	RCC_CFGR = 0X00000001;
}
void RCC_EnableCLKprephiral(u8 Bus,u8 prephiral)
{
	switch(Bus)
	{
		case 0: SET_BIT(RCC_AHBENR ,prephiral);  break;
		case 1: SET_BIT(RCC_APB1ENR,prephiral);  break;
		case 2: SET_BIT(RCC_APB2ENR,prephiral);  break;
	}
	
}
void RCC_DisableCLKprephiral(u8 Bus,u8 prephiral)
{
	switch(Bus)
	{
		case 0: CLR_BIT(RCC_AHBENR ,prephiral);  break;
		case 1: CLR_BIT(RCC_APB1ENR,prephiral);  break;
		case 2: CLR_BIT(RCC_APB2ENR,prephiral);  break;
	}
	
	
}
