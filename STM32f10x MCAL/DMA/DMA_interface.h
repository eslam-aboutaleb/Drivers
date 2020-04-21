#ifndef DMA_interface_H
#define DMA_interface_H

void DMA_CH1_Init(void);
void DMA_Start_Transfer_CH1(u32 SourceAddress, u32 DestAddress,u16 count);
#endif
