/* /////////////////////////////////////////////////////////////////////////////////////////////////
  LCD_pro.c
  /////////
 
  Author: Eslam Aboutaleb
 ////////////////////////////////////////////////////////////////////////////////////////////////// */

#include "LCD_interface.h"
 
#define LCD_CONFIG_WORD             (0x30)

#define LCD_CLR                     (0x01)

#define LCD_CURSOR_HOME             (0x02)

#define LCD_SET_ENTRY_MODE          (0x04)
#define LCD_INCREMENT_CURSOR        (0x02)
#define LCD_DECREMENT_CURSOR        (0x00)
#define LCD_DISPLAY_SHIFT_ON        (0x01)
#define LCD_DISPLAY_SHIFT_OFF       (0x00)

#define LCD_DISPLAY_CONTROL         (0x08)
#define LCD_DISPLAY_ON              (0x04)
#define LCD_DISPLAY_OFF             (0x00)
#define LCD_CURSOR_ON               (0x02)
#define LCD_CURSOR_OFF              (0x00)
#define LCD_CURSOR_BLINK_ON         (0x01)
#define LCD_CURSOR_BLINK_OFF        (0x00)

#define LCD_CURSOR_DISPLAY_CONTROL  (0x10)
#define LCD_SHIFT_CURSOR_LEFT       (0x00)
#define LCD_SHIFT_CURSOR_RIGHT      (0x04)
#define LCD_SHIFT_LEFT              (0x08)
#define LCD_SHIFT_RIGHT             (0x0C)

#define LCD_FUNCTION_SET            (0x20)
#define LCD_DATA_LENGTH_4           (0x00)
#define LCD_DATA_LENGTH_8           (0x10)
#define LCD_ONE_LINE                (0x00)
#define LCD_TWO_LINES               (0x08)
#define LCD_SMALL_FONT              (0x00)
#define LCD_LARGE_FONT              (0x04)

#define LCD_SET_CGRAM_ADDRESS       (0x40)
#define LCD_SET_DDRAM_ADDRESS       (0x80)

#define LCD_LINE_SIZE               (0x28)
#define LCD_LINE_2_ADDRESS          (0x40)


#define DISPLAYSET(x)               ((x==DisplayON)?                        LCD_DISPLAY_ON:LCD_DISPLAY_OFF)
#define CURSOR_SET(x)               ((x==CursorON)?                           LCD_CURSOR_ON:LCD_CURSOR_OFF)
#define CURSOR_BLINK(x)             ((x==CursorBlinkON)?          LCD_CURSOR_BLINK_ON:LCD_CURSOR_BLINK_OFF)
#define LCD_PINS(x)                 ((x==LCD_8_pins)?                  LCD_DATA_LENGTH_8:LCD_DATA_LENGTH_4)
#define LCD_DISPLAY_SHIFT(x)        ((x==LCD_DISPLAY_SHIFT_ON)?       LCD_DISPLAY_SHIFT_ON:LCD_DISPLAY_OFF)
#define CURSOR_SHIFT(x)             ((x==CursorToLeft)?          LCD_DECREMENT_CURSOR:LCD_INCREMENT_CURSOR)
#define DISPLAY_SHIFT(x)            ((x==LCD_DISPLAY_SHIFT_ON)? LCD_DISPLAY_SHIFT_ON:LCD_DISPLAY_SHIFT_OFF)
#define LCD_LINES(x)                ((x==Two_lines)?                            LCD_TWO_LINES:LCD_ONE_LINE) 
#define LCD_FONT(x)                 ((x==Format_5x11)?                       LCD_LARGE_FONT:LCD_SMALL_FONT)

static void LCD_SendCommand(uint8 Command);
static void LCD_SendPulse(void);
static uint8 FOUR_PINS=0;
static uint8 EIGHT_PINS=0;

/* Initialization function */
void LCD_Init(LCD_configType * ConfigTypePtr)
{
	/*Initialize control pins*/
	DIO_InitPin(LCD_RS_DR,LCD_RS,DIO_OUTPUT,STD_LOW);
	DIO_InitPin(LCD_RW_DR,LCD_RW,DIO_OUTPUT,STD_LOW);
	DIO_InitPin(LCD_E_DR,LCD_E,DIO_OUTPUT,STD_LOW);
	
	/*configure LCD mode */
	if(ConfigTypePtr->Mode==LCD_8_pins)
	{
		FOUR_PINS=0;
		EIGHT_PINS=1;
		DIO_InitPin(LCD_DATA_P0_DR,LCD_DATA_P0,DIO_OUTPUT,STD_LOW);
		DIO_InitPin(LCD_DATA_P1_DR,LCD_DATA_P1,DIO_OUTPUT,STD_LOW);
		DIO_InitPin(LCD_DATA_P2_DR,LCD_DATA_P2,DIO_OUTPUT,STD_LOW);
		DIO_InitPin(LCD_DATA_P3_DR,LCD_DATA_P3,DIO_OUTPUT,STD_LOW);
		
		DIO_InitPin(LCD_DATA_P4_DR,LCD_DATA_P4,DIO_OUTPUT,STD_LOW);
		DIO_InitPin(LCD_DATA_P5_DR,LCD_DATA_P5,DIO_OUTPUT,STD_LOW);
		DIO_InitPin(LCD_DATA_P6_DR,LCD_DATA_P6,DIO_OUTPUT,STD_LOW);
		DIO_InitPin(LCD_DATA_P7_DR,LCD_DATA_P7,DIO_OUTPUT,STD_LOW);
	}
	else
	{
		
		FOUR_PINS=1;
		EIGHT_PINS=0;
		DIO_InitPin(LCD_DATA_P4_DR,LCD_DATA_P4,DIO_OUTPUT,STD_LOW);
		DIO_InitPin(LCD_DATA_P5_DR,LCD_DATA_P5,DIO_OUTPUT,STD_LOW);
		DIO_InitPin(LCD_DATA_P6_DR,LCD_DATA_P6,DIO_OUTPUT,STD_LOW);
		DIO_InitPin(LCD_DATA_P7_DR,LCD_DATA_P7,DIO_OUTPUT,STD_LOW);
	}
	

	
	/* Initialization sequence */
	delay_ms(20);
	LCD_SendCommand(LCD_CONFIG_WORD);//|LCD_CURSOR_HOME|LCD_CLR);
	delay_ms(5);
	LCD_SendCommand(LCD_CONFIG_WORD|LCD_CURSOR_HOME);
    delay_ms(2);
	
    /*Function set*/
	LCD_SendCommand(
	LCD_FUNCTION_SET|
	LCD_PINS  (ConfigTypePtr->Mode)|
	LCD_LINES (ConfigTypePtr->lines)|
	LCD_FONT  (ConfigTypePtr->font)
	);
	
	
	delay_ms(2);
	
	/* Display ON/OFF */
	LCD_SendCommand(
	LCD_DISPLAY_CONTROL
	/*check display state*/
	|DISPLAYSET  (ConfigTypePtr->display)
	/*check Cursor state*/
	|CURSOR_SET  (ConfigTypePtr->cursor_state)
	/*check Cursor blinking state*/
	|CURSOR_BLINK(ConfigTypePtr->cursor_blink)
	);
	
	delay_ms(2);
	
	/* Entry mode*/
	LCD_SendCommand(
	LCD_SET_ENTRY_MODE
	|CURSOR_SHIFT  (ConfigTypePtr->cursor_shift)
	|DISPLAY_SHIFT (ConfigTypePtr->display_shift)
	);
	
	 delay_ms(2);
	 LCD_Clear();
}




void LCD_Clear(void)
{
	LCD_SendCommand(LCD_CLR);
}

static void LCD_SendCommand(uint8 Command)
{
	/*Set RW=0*/
	DIO_SetPinValue(LCD_RW_CR,LCD_RW,STD_LOW);
	/*RS=0 to send commands*/
	DIO_SetPinValue(LCD_RS_CR,LCD_RS,STD_LOW);

   if(FOUR_PINS==1)
   {
	/*Send upper nibble*/
	DIO_SetPinValue(LCD_DATA_P4_CR,LCD_DATA_P4,GET_BIT(Command,4));
	DIO_SetPinValue(LCD_DATA_P5_CR,LCD_DATA_P5,GET_BIT(Command,5));
	DIO_SetPinValue(LCD_DATA_P6_CR,LCD_DATA_P6,GET_BIT(Command,6));
	DIO_SetPinValue(LCD_DATA_P7_CR,LCD_DATA_P7,GET_BIT(Command,7));
	
	LCD_SendPulse();
	/*send lower nibble*/
	DIO_SetPinValue(LCD_DATA_P4_CR,LCD_DATA_P4,GET_BIT(Command,0));
	DIO_SetPinValue(LCD_DATA_P5_CR,LCD_DATA_P5,GET_BIT(Command,1));
	DIO_SetPinValue(LCD_DATA_P6_CR,LCD_DATA_P6,GET_BIT(Command,2));
	DIO_SetPinValue(LCD_DATA_P7_CR,LCD_DATA_P7,GET_BIT(Command,3));
	LCD_SendPulse();
   }
   else
   {
	   /*No Action*/
   }
   
   if(EIGHT_PINS==1)
   {
	DIO_SetPinValue(LCD_DATA_P0_CR,LCD_DATA_P0,GET_BIT(Command,0));
	DIO_SetPinValue(LCD_DATA_P1_CR,LCD_DATA_P1,GET_BIT(Command,1));
	DIO_SetPinValue(LCD_DATA_P2_CR,LCD_DATA_P2,GET_BIT(Command,2));
	DIO_SetPinValue(LCD_DATA_P3_CR,LCD_DATA_P3,GET_BIT(Command,3));
	DIO_SetPinValue(LCD_DATA_P4_CR,LCD_DATA_P4,GET_BIT(Command,4));
	DIO_SetPinValue(LCD_DATA_P5_CR,LCD_DATA_P5,GET_BIT(Command,5));
	DIO_SetPinValue(LCD_DATA_P6_CR,LCD_DATA_P6,GET_BIT(Command,6));
	DIO_SetPinValue(LCD_DATA_P7_CR,LCD_DATA_P7,GET_BIT(Command,7));
	LCD_SendPulse();
   }
   else
   {
	  /*No Action*/   
   }
}

void LCD_SendChar(uint8 Character)
{
	/*Set RW=0*/
	DIO_SetPinValue(LCD_RW_CR,LCD_RW,STD_LOW);
	/*RS=0 to send commands*/
	DIO_SetPinValue(LCD_RS_CR,LCD_RS,STD_HIGH);

   if(FOUR_PINS==1)
   {
	/*Send upper nibble*/
	DIO_SetPinValue(LCD_DATA_P4_CR,LCD_DATA_P4,GET_BIT(Character,4));
	DIO_SetPinValue(LCD_DATA_P5_CR,LCD_DATA_P5,GET_BIT(Character,5));
	DIO_SetPinValue(LCD_DATA_P6_CR,LCD_DATA_P6,GET_BIT(Character,6));
	DIO_SetPinValue(LCD_DATA_P7_CR,LCD_DATA_P7,GET_BIT(Character,7));
	
	LCD_SendPulse();
	/*send lower nibble*/
	DIO_SetPinValue(LCD_DATA_P4_CR,LCD_DATA_P4,GET_BIT(Character,0));
	DIO_SetPinValue(LCD_DATA_P5_CR,LCD_DATA_P5,GET_BIT(Character,1));
	DIO_SetPinValue(LCD_DATA_P6_CR,LCD_DATA_P6,GET_BIT(Character,2));
	DIO_SetPinValue(LCD_DATA_P7_CR,LCD_DATA_P7,GET_BIT(Character,3));
	LCD_SendPulse();
   }
   else
   {
	   /*No Action*/
   }
	
	if (EIGHT_PINS==1)
	{
	DIO_SetPinValue(LCD_DATA_P0_CR,LCD_DATA_P0,GET_BIT(Character,0));
	DIO_SetPinValue(LCD_DATA_P1_CR,LCD_DATA_P1,GET_BIT(Character,1));
	DIO_SetPinValue(LCD_DATA_P2_CR,LCD_DATA_P2,GET_BIT(Character,2));
	DIO_SetPinValue(LCD_DATA_P3_CR,LCD_DATA_P3,GET_BIT(Character,3));
	DIO_SetPinValue(LCD_DATA_P4_CR,LCD_DATA_P4,GET_BIT(Character,4));
	DIO_SetPinValue(LCD_DATA_P5_CR,LCD_DATA_P5,GET_BIT(Character,5));
	DIO_SetPinValue(LCD_DATA_P6_CR,LCD_DATA_P6,GET_BIT(Character,6));
	DIO_SetPinValue(LCD_DATA_P7_CR,LCD_DATA_P7,GET_BIT(Character,7));

	LCD_SendPulse();
	}
	else
	{
		/*No Action*/
	}
}

static void LCD_SendPulse(void)
{
	DIO_SetPinValue(LCD_E_CR,LCD_E,STD_HIGH);
	delay_ms(2);
	DIO_SetPinValue(LCD_E_CR,LCD_E,STD_LOW);

}

void LCD_GoToRowColumn(uint8 row,uint8 col)
{
	uint8 Address=0;
	
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}					
	/* to write to a specific address in the LCD 
	 * we need to apply the corresponding command 0x80+Address */
	LCD_SendCommand(Address | 0x80); 
}

void LCD_SendString(uint8 *Str)
{
	uint8 index=0;
	
	while (Str[index] != '\0')
	{
		LCD_SendChar(Str[index]);
		index++;
	}
}

void LCD_SendString_RowColumn(uint8 Row,uint8 Col,uint8 *Str)
{
	LCD_GoToRowColumn(Row,Col); /* go to to the required LCD position */
	LCD_SendString(Str);        /* display the string */
}
