/* ///////////////////////////////////////////////////////////////////////////
 *
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

sint64 PWR(uint16 base,uint16 exp)
{
	sint64 Result=1;
	while (exp != 0)
	{
		Result *= base;
		exp--;
	}
	return Result;
}