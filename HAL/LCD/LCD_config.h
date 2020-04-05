/* ///////////////////////////////////////////////////////////////////////////
 * LCD_config.h
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif  

#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

/*portable macros*/
#define delay_ms _delay_ms
#define delay_us _delay_us


/*Data pins*/
#define LCD_DATA_P0_DR 'B'
#define LCD_DATA_P0_CR 'B'
#define LCD_DATA_P0     0

#define LCD_DATA_P1_DR 'B'
#define LCD_DATA_P1_CR 'B'
#define LCD_DATA_P1     1

#define LCD_DATA_P2_DR 'B'
#define LCD_DATA_P2_CR 'B'
#define LCD_DATA_P2     2

#define LCD_DATA_P3_DR 'B'
#define LCD_DATA_P3_CR 'B'
#define LCD_DATA_P3     3

#define LCD_DATA_P4_DR 'B'
#define LCD_DATA_P4_CR 'B'
#define LCD_DATA_P4     4

#define LCD_DATA_P5_DR 'B'
#define LCD_DATA_P5_CR 'B'
#define LCD_DATA_P5     5

#define LCD_DATA_P6_DR 'B'
#define LCD_DATA_P6_CR 'B'
#define LCD_DATA_P6     6

#define LCD_DATA_P7_DR 'B'
#define LCD_DATA_P7_CR 'B'
#define LCD_DATA_P7     7

/*Control pins*/
#define LCD_E_DR       'A'
#define LCD_E_CR       'A'
#define LCD_E           1

#define LCD_RS_DR      'A'
#define LCD_RS_CR      'A'
#define LCD_RS          2

#define LCD_RW_DR      'A'
#define LCD_RW_CR      'A'
#define LCD_RW          3

#endif /* LCD_CONFIG_H_ */