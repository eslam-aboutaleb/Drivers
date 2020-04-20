#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"

void NVIC_Init(void)
{
   /*write 0x5FA to VECTKEY, otherwise the write is ignored*/
	 /*Bit 15 is 0 little indian*/
	 /*Bit 14-11 Reserved*/
	 
	SCB->AIRCR=0x05FA0500;
}

void NVIC_EnableInterrupt(IRQn_Type IntIndex)
{
	if (IntIndex >=0 && IntIndex <= 31)
	{
	SET_BIT (NVIC->ISER[0], IntIndex);
	}
	else if (IntIndex >=32 && IntIndex <= 63)
	{
		IntIndex -=32;
		SET_BIT (NVIC->ISER[1], IntIndex);
	}
	else if (IntIndex >=64 && IntIndex <= 95)
	{
		IntIndex -=64;
		SET_BIT (NVIC->ISER[2], IntIndex);
	}
	else
	{
		/*Do Nothing*/
	}
}

void NVIC_DisableInterrupt(IRQn_Type IntIndex)
{
	if (IntIndex >=0 && IntIndex <= 31)
	{
	SET_BIT (NVIC->ICER[0], IntIndex);
	}
	else if (IntIndex >=32 && IntIndex <= 63)
	{
		IntIndex -=32;
		SET_BIT (NVIC->ICER[1], IntIndex);
	}
	else if (IntIndex >=64 && IntIndex <= 95)
	{
		IntIndex -=64;
		SET_BIT (NVIC->ICER[2], IntIndex);
	}
	else
	{
		/*Do Nothing*/
	}
}


void NVIC_SetPendingFlag(IRQn_Type IntIndex)
{
	if (IntIndex >=0 && IntIndex <= 31)
	{
	SET_BIT (NVIC->ISPR[0], IntIndex);
	}
	else if (IntIndex >=32 && IntIndex <= 63)
	{
		IntIndex -=32;
		SET_BIT (NVIC->ISPR[1], IntIndex);
	}
	else if (IntIndex >=64 && IntIndex <= 95)
	{
		IntIndex -=64;
		SET_BIT (NVIC->ISPR[2], IntIndex);
	}
	else
	{
		/*Do Nothing*/
	}
}


void NVIC_ClearPendingFlag(IRQn_Type IntIndex)
{
	if (IntIndex >=0 && IntIndex <= 31)
	{
	SET_BIT (NVIC->ICPR[0], IntIndex);
	}
	else if (IntIndex >=32 && IntIndex <= 63)
	{
		IntIndex -=32;
		SET_BIT (NVIC->ICPR[1], IntIndex);
	}
	else if (IntIndex >=64 && IntIndex <= 95)
	{
		IntIndex -=64;
		SET_BIT (NVIC->ICPR[2], IntIndex);
	}
	else
	{
		/*Do Nothing*/
	}
}

uint8 NVIC_GetPendingFlag(IRQn_Type IntIndex)
{
	uint8 state=0;
	if (IntIndex >=0 && IntIndex <= 31)
	{
	state = GET_BIT (NVIC->IABR[0], IntIndex);
	}
	else if (IntIndex >=32 && IntIndex <= 63)
	{
		IntIndex -=32;
	state = GET_BIT (NVIC->IABR[1], IntIndex);
	}
	else if (IntIndex >=64 && IntIndex <= 95)
	{
		IntIndex -=64;
	state = GET_BIT (NVIC->IABR[2], IntIndex);
	}
	return state;
}

void NVIC_SetPeriority(IRQn_Type IntIndex , uint8 Periority)
{
	NVIC->IPR[IntIndex]=Periority;
}


void NVIC_GenerateSWI(IRQn_Type IntIndex)
{
	NVIC->STIR=IntIndex;
}

