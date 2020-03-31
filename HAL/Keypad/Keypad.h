/*
 * Keybad.h
 *
 * Created: 3/30/2020 8:06:28 PM
 *  Author: Dell
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Keypad_config.h"

/*Functions prototypes*/
void Keypad_Init(void);
uint8 Keypad_GetKey(void);
uint8 Keypad_Update(void);

#endif /* KEYPAD_H_ */