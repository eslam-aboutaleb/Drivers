#ifndef RCC_interface_H
#define RCC_interface_H

void RCC_ClockInit(void);

void RCC_EnableCLKprephiral(u8 Bus,u8 prephiral);
void RCC_DisableCLKprephiral(u8 Bus,u8 prephiral);

#endif
