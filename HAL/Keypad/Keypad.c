/*
 * Keypad.c
 *
 * Created: 3/30/2020 8:06:59 PM
 *  Author: Dell
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "Keypad.h"
#include <string.h>


                                                                /* Keypad layout*/
         ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

		     #define KEY7    '7'   
			 #define KEY8    '8'  
			 #define KEY9    '9'   
			 #define KEYA    'A'   
		 				  	  
		     #define KEY4    '4'
			 #define KEY5    '5'
			 #define KEY6    '6'   
			 #define KEYB    'B'	
		 				  	  
		     #define KEY1    '1'   
			 #define KEY2    '2'  
			 #define KEY3    '3'   
			 #define KEYC    'C' 	
		     					
		     #define KEY_STAR '*'
			 #define KEY0     '0'   
			 #define KEY_HASH '#'
			 #define KEYD     'D'	
		 
		 /* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */
		 
#define ENTER_KEY  '#'

/*Local functions prototypes*/
static uint8 Keypad_Scan(void);

void Keypad_Init(void)
{
	/*Initialize the rows pins*/
	DIO_InitPin(KEYPAD_ROW1_DR,   Keypad_Row1,  INPUT, STD_HIGH);
	DIO_InitPin(KEYPAD_ROW2_DR,   Keypad_Row2,  INPUT, STD_HIGH);
	DIO_InitPin(KEYPAD_ROW3_DR,   Keypad_Row3,  INPUT, STD_HIGH);
	DIO_InitPin(KEYPAD_ROW4_DR,   Keypad_Row4,  INPUT, STD_HIGH);
					   
	/*Initialize the co1umns pins*/
	DIO_InitPin(KEYPAD_COLUMN1_DR,Keypad_Column1,OUTPUT,STD_LOW);
	DIO_InitPin(KEYPAD_COLUMN2_DR,Keypad_Column2,OUTPUT,STD_LOW);
	DIO_InitPin(KEYPAD_COLUMN3_DR,Keypad_Column3,OUTPUT,STD_LOW);
	DIO_InitPin(KEYPAD_COLUMN4_DR,Keypad_Column4,OUTPUT,STD_LOW);
}

static void SetColOne(void)
{
	DIO_SetPinValue(KEYPAD_COLUMN1_DR,Keypad_Column1,STD_LOW);
	DIO_SetPinValue(KEYPAD_COLUMN2_DR,Keypad_Column2,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN3_DR,Keypad_Column3,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN4_DR,Keypad_Column4,STD_HIGH);
}
static void SetColTwo(void)
{
	DIO_SetPinValue(KEYPAD_COLUMN1_DR,Keypad_Column1,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN2_DR,Keypad_Column2,STD_LOW);
	DIO_SetPinValue(KEYPAD_COLUMN3_DR,Keypad_Column3,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN4_DR,Keypad_Column4,STD_HIGH);
}
static void SetColThree(void)
{
	DIO_SetPinValue(KEYPAD_COLUMN1_DR,Keypad_Column1,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN2_DR,Keypad_Column2,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN3_DR,Keypad_Column3,STD_LOW);
	DIO_SetPinValue(KEYPAD_COLUMN4_DR,Keypad_Column4,STD_HIGH);
}
static void SetColFour(void)
{
	DIO_SetPinValue(KEYPAD_COLUMN1_DR,Keypad_Column1,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN2_DR,Keypad_Column2,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN3_DR,Keypad_Column3,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN4_DR,Keypad_Column4,STD_LOW);
}

static void SetCols(void)
{
	DIO_SetPinValue(KEYPAD_COLUMN1_DR,Keypad_Column1,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN2_DR,Keypad_Column2,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN3_DR,Keypad_Column3,STD_HIGH);
	DIO_SetPinValue(KEYPAD_COLUMN4_DR,Keypad_Column4,STD_HIGH);
}

static uint8 Keypad_Scan(void)
{
	SetCols();
	SetColOne();
	if(DIO_ucGetPinValue(KEYPAD_ROW1_CR,Keypad_Row1)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW1_CR,Keypad_Row1)==0);
		return KEY_STAR;
	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW2_CR,Keypad_Row2)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW2_CR,Keypad_Row2)==0);
		return KEY1;
	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW3_CR,Keypad_Row3)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW3_CR,Keypad_Row3)==0);
		return KEY4;

	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW4_CR,Keypad_Row4)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW4_CR,Keypad_Row4)==0);
		return KEY7;
	}
	SetCols();

	SetColTwo();
	if(DIO_ucGetPinValue(KEYPAD_ROW1_CR,Keypad_Row1)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW1_CR,Keypad_Row1)==0);
		return KEY0;
	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW2_CR,Keypad_Row2)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW2_CR,Keypad_Row2)==0);
		return KEY2;
	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW3_CR,Keypad_Row3)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW3_CR,Keypad_Row3)==0);
		return KEY5;

	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW4_CR,Keypad_Row4)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW4_CR,Keypad_Row4)==0);
		return KEY8;
	}
	SetCols();
	SetColThree();
	if(DIO_ucGetPinValue(KEYPAD_ROW1_CR,Keypad_Row1)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW1_CR,Keypad_Row1)==0);
		return KEY_HASH;
	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW2_CR,Keypad_Row2)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW2_CR,Keypad_Row2)==0);
		return KEY3;
	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW3_CR,Keypad_Row3)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW3_CR,Keypad_Row3)==0);
		return KEY6;

	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW4_CR,Keypad_Row4)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW4_CR,Keypad_Row4)==0);
		return KEY9;
	}
	SetCols();
	SetColFour();
	if(DIO_ucGetPinValue(KEYPAD_ROW1_CR,Keypad_Row1)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW1_CR,Keypad_Row1)==0);
		return KEYD;
	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW2_CR,Keypad_Row2)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW2_CR,Keypad_Row2)==0);
		return KEYC;
	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW3_CR,Keypad_Row3)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW3_CR,Keypad_Row3)==0);
		return KEYB;

	}
	else if(DIO_ucGetPinValue(KEYPAD_ROW4_CR,Keypad_Row4)==0)
	{
		while(DIO_ucGetPinValue(KEYPAD_ROW4_CR,Keypad_Row4)==0);
		return KEYA;
	}
return 0;
}

uint8 Keypad_GetKey(void)
{
	static uint8 Character= '\0';
	Character=Keypad_Scan();
	return Character;
}


uint8 Keypad_Update(void)
{
	/* Application */
}

