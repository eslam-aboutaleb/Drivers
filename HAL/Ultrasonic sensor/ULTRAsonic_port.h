/*
 * ULTRAsonic_port.h
 *
 * Created: 2/25/2020 7:15:03 PM
 *  Author: Eslam Aboutaleb
 */ 


#ifndef ULTRASONIC_PORT_H_
#define ULTRASONIC_PORT_H_

/* portable registers files */
#include "avr/io.h"
#include <util/delay.h>
/***************************/

#define SystemClock F_CPU

#define EchoPinPort    'A'
#define TriggerPinPort 'A'
#define EchoPin         PIN0
#define TriggerPin      PIN1
#define TMR_Counter     TCNT1
#define delay10us      _delay_us(10)



#endif /* ULTRASONIC_PORT_H_ */