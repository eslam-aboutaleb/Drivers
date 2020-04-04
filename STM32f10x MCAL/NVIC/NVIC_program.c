#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_register.h"




void NVIC_EnableInterrupt(u8 IntIndex)
{
	if (IntIndex >=0 && IntIndex <= 31)
	{
	SET_BIT (NVIC_ISER[0], IntIndex);
	}
	else if (IntIndex >=32 && IntIndex <= 63)
	{
		IntIndex -=32;
		SET_BIT (NVIC_ISER[1], IntIndex);
	}
	else if (IntIndex >=64 && IntIndex <= 95)
	{
		IntIndex -=64;
		SET_BIT (NVIC_ISER[2], IntIndex);
	}
}
void NVIC_DisableInterrupt(u8 IntIndex)
{
	if (IntIndex >=0 && IntIndex <= 31)
	{
	SET_BIT (NVIC_ICER[0], IntIndex);
	}
	else if (IntIndex >=32 && IntIndex <= 63)
	{
		IntIndex -=32;
		SET_BIT (NVIC_ICER[1], IntIndex);
	}
	else if (IntIndex >=64 && IntIndex <= 95)
	{
		IntIndex -=64;
		SET_BIT (NVIC_ICER[2], IntIndex);
	}
}
void NVIC_SetPendingFlag(u8 IntIndex)
{
	if (IntIndex >=0 && IntIndex <= 31)
	{
	SET_BIT (NVIC_ISPR[0], IntIndex);
	}
	else if (IntIndex >=32 && IntIndex <= 63)
	{
		IntIndex -=32;
		SET_BIT (NVIC_ISPR[1], IntIndex);
	}
	else if (IntIndex >=64 && IntIndex <= 95)
	{
		IntIndex -=64;
		SET_BIT (NVIC_ISPR[2], IntIndex);
	}
}
void NVIC_ClearPendingFlag(u8 IntIndex)
{
	if (IntIndex >=0 && IntIndex <= 31)
	{
	SET_BIT (NVIC_ICPR[0], IntIndex);
	}
	else if (IntIndex >=32 && IntIndex <= 63)
	{
		IntIndex -=32;
		SET_BIT (NVIC_ICPR[1], IntIndex);
	}
	else if (IntIndex >=64 && IntIndex <= 95)
	{
		IntIndex -=64;
		SET_BIT (NVIC_ICPR[2], IntIndex);
	}
}

void NVIC_init(void)
{
	AIRCR =0x05FA0500; //0x05FA is like passowrd to enable SCB_AIRCR
}

void NVIC_SetPeriority(u8 Interruptindex , u8 Periority)
{
	IPR[Interruptindex]=Periority;
}
