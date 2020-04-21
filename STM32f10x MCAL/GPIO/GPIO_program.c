#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_register.h"

void DIO_SetPinMode(u8 Port , u8 pin , u8 Mode)
{
	switch (Port)
	{
		case 'A': if (pin <= 7)
		{
			
			//clear bits
			GPIOA_CRL &= ~(0b1111<<pin*4); //*4 because every pin is 3 bits
			//Assign needed mode
			GPIOA_CRL |= (Mode << pin*4);
		}
		else
		{
			//return pin index to be from p0 to p7
			pin = pin - 8;
			//clear bits
			GPIOA_CRH &= ~(0b1111<<pin*4); //*4 because every pin is 3 bits
			//Assign needed mode
			GPIOA_CRH |= (Mode << pin*4);
		}
		break;
		case 'B': if (pin <= 7)
		{
			
			//clear bits
			GPIOA_CRL &= ~(0b1111<<pin*4); //*4 because every pin is 3 bits
			//Assign needed mode
			GPIOA_CRL |= (Mode << pin*4);
		}
		else
		{
			//return pin index to be from p0 to p7
			pin = pin - 8;
			//clear bits
			GPIOB_CRH &= ~(0b1111<<pin*4); //*4 because every pin is 3 bits
			//Assign needed mode
			GPIOB_CRH |= (Mode << pin*4);
		}
		break;
		case 'C':
		if (( pin >= 13) &&( pin <= 15))
		{
			
			//clear bits
			//0b1111 = 2 BITS CNF & 2 BITS MODE 
			GPIOA_CRL &= ~(0b1111<< pin*4); //*4 because every pin is 3 bits
			//Assign needed mode
			GPIOA_CRL |= (Mode << pin*4);
		}
		else
		{
			//return pin index to be from p0 to p7
			pin = pin - 8;
			//clear bits
			GPIOB_CRH &= ~(0b1111<<pin*4); //*4 because every pin is 3 bits
			//Assign needed mode
			GPIOB_CRH |= (Mode << pin*4);
		}
		break;
	}
}

void DIO_SetPinVal(u8 Port , u8 Pin , u8 Value)
{
	switch (Port)
	{
		case 'A': if (Value==1)
		{
			SET_BIT (GPIOA_ODR,Pin);
		}
		else
		{
			CLR_BIT(GPIOA_ODR,Pin);
		}
		break;
		case 'B': if (Value==1)
		{
			SET_BIT (GPIOB_ODR,Pin);
		}
		else
		{
			CLR_BIT(GPIOB_ODR,Pin);
		}
		break;
		case 'C': if (Value==1)
		{
			SET_BIT (GPIOC_ODR,Pin);
		}
		else
		{
			CLR_BIT(GPIOC_ODR,Pin);
		}
		break;
	}
}

u8 DIO_GetPinVal  (u8 Port , u8 Pin)
{
	u8 Result;
	switch(Port)
	{
		case 'A': Result = GET_BIT(GPIOA_IDR,Pin); break;
		
		case 'B': Result = GET_BIT(GPIOB_IDR,Pin); break;
		
		case 'C': Result = GET_BIT(GPIOC_IDR,Pin); break;
	}
		return Result;
}
