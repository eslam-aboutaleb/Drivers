#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_register.h"

void AFIO_Map(u8 Pin ,u8 Level)
{
	if (Level ==1)
		SET_BIT(AFIO_MAPR,Pin);
	else
		CLR_BIT(AFIO_MAPR,Pin);
}
