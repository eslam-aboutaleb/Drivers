#ifndef NVIC_interface_H
#define NVIC_interface_H

void NVIC_EnableInterrupt (u8 IntIndex);
void NVIC_DisableInterrupt(u8 IntIndex);
void NVIC_SetPendingFlag  (u8 IntIndex);
void NVIC_ClearPendingFlag(u8 IntIndex);
void NVIC_init(void);	
void NVIC_SetPeriority(u8 Interruptindex , u8 Periority);
		
		
		
#endif 