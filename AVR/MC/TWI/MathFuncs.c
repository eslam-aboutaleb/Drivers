/* ///////////////////////////////////////////////////////////////////////////
 *
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

float64 PWR(uint16 base,uint16 exp)
{
	float64 Result=1;
	while (exp != 0)
	{
		Result *= base;
		exp--;
	}
	return Result;
}