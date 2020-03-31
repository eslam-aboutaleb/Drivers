/* ///////////////////////////////////////////////////////////////////////////
 * Keypad.h
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "Keypad_config.h"

/*Functions prototypes*/
void Keypad_Init(void);
uint8 Keypad_GetKey(void);
void Keypad_Update(void);

#endif /* KEYPAD_H_ */