/*
 * Timer1.c
 *
 * Created: 2/20/2020 2:47:49 PM
 *  Author: Eslam Aboutaleb
 */ 



/*Dummy Timer to count time of Ultrasonic sensor incoming signals*/


#include <avr/io.h>
void TMR_Start(void)
{
	/*normal mode */
	/*prescaler =1 */
	TCCR1B|=(1<<CS10) | (1<<CS00);

}

void TMR_Stop(void)
{
	TCCR1B &=~(1<<CS00);
	TCCR1B &=~(1<<CS01);
	
}