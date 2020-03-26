/*
 * LCD_interface.h
 *
 *  Author: Eslam Aboutaleb
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_config.h"

typedef enum
{
	LCD_4_pins=0,
	LCD_8_pins=1
}LCD_Mode;

typedef enum
{
	Format_5x8=0,
	Format_5x11
}LCD_Font;

typedef enum
{
	One_line,
	Two_lines
}LCD_Lines;

typedef enum
{
	DisplayOFF=0,
	DisplayON=1
}LCD_Display;

typedef enum
{
	CursorOFF=0,
	CursorON=1
}CursorState;

typedef enum
{
	CursorToRight,
	CursorToLeft
}CursorShift;

typedef enum
{
    DisplayShiftOFF,
	DisplayShiftON	
}DisplayShift;

typedef enum
{
	CursorBlinkOFF=0,
	CursorBlinkON=1
}CursorBlink;


typedef struct 
{
	LCD_Mode Mode;
	LCD_Lines lines;
	LCD_Font font;
	LCD_Display display;
	CursorBlink cursor_blink;
	CursorState cursor_state;
	CursorShift cursor_shift;
	DisplayShift display_shift;
}LCD_configType;

void LCD_Init(LCD_configType * ConfigTypePtr);
void LCD_Clear(void);
void LCD_SendChar(uint8 Character);
void LCD_SendString(char *String);
void LCD_goToRowColumn(uint8 row,uint8 col);

#endif /* LCD_INTERFACE_H_ */