#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_register.h"

void DMA_CH1_Init(void)
{
	/*
	M2M ,PL=very High , Msize and Psize =32
	MINC=1 , PINC =1 ,no circular ,DIR = P to M2M
	TC Interrupt=1 , Enable =0 */ //dont enable DMA until you load your data into registers
	DMA_CCR1=0x00007AC2;
	
}

void DMA_Start_Transfer_CH1(u32 SourceAddress, u32 DestAddress,u16 count)
{
	//destination based on initalization i made
	DMA_CMAR1 = DestAddress;
	DMA_CPAR1 = SourceAddress;
	DMA_CNDTR1= count;
	
	/* enable DMA */
	SET_BIT(DMA_CCR1,0);

}
