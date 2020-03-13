#ifndef __LED_H__
#define __LED_H__

#define LED_DELAY_MS (1000)

/* Leds' pins */
#define LED_1_PORT_DR   (GPIO_PORTB_DATA)
#define LED_1_PORT_CR   (GPIO_PORTB_CONTROL)
#define LED_1_PIN       (GPIO_PIN_0)

typedef enum
{
    LED_1,
    LED_2,
    LED_3,
    LED_4
}tLED;

typedef enum
{
   LED_OFF = 0,
   LED_ON  = 1
}tLED_State;


void LED_Init(tLED led, tLED_State state);
void LED_SetState(tLED led, tLED_State state);
tLED_State LED_GetState(tLED led);
void LED_Update(void);
#endif // __LED_H__
