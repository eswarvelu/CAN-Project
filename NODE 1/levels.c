#include<lpc21xx.h>
#include "header.h"
#include "types.h"


void SPI_INIT()
{
PINSEL0|=0x1500;
S0SPCCR=SPI_RATE;
S0SPCR=((1<<MSTR)|MODE3);
IODIR0|=1<<CS;
}

u8 SPIO(u8 data)
{
	u8 stat;
	stat=S0SPSR;
	S0SPDR=data;
	while(READBIT(S0SPSR,SPIF)==0);
	return S0SPDR;
}




f32 read_value(u8 channel_no)
{
u32 adc;//12 bit code
u8 lower,higher;   
CLRBIT(IOPIN0,CS);
SPIO(0x06);
higher=SPIO(channel_no<<6);
lower=SPIO(0x00);
SETBIT(IOPIN0,CS);
adc=((higher & 0x0f)<<8) | lower;
return ((adc*3.3)/4096);  //normal voltage.
}