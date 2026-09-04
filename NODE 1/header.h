/*header.h*/

#ifndef __HEADER_H_
#define __HEADER_H_



#include "types.h"


#define SETBIT(WORD,BITPOS)  (WORD|=(1<<BITPOS))
#define CLRBIT(WORD,BITPOS)  (WORD&=~(1<<BITPOS))
#define CMPBIT(WORD,BITPOS)  (WORD^=(1<<BITPOS))
#define BITWRITE(WORD,BITPOS,BIT)  (BIT ? SETBIT(WORD,BITPOS): CLRBIT(WORD,BITPOS))
#define READBIT(WORD,BITPOS) ((WORD>>BITPOS)&1)





#define CS 7
#define PCLK  60000000
#define SPCCR 240
#define SPI_RATE (u8) (PCLK/SPCCR)

#define MODE0 0x00
#define MODE1 0x08
#define MODE2 0x10
#define MODE3 0x18




#define MSTR 5
#define LSBF 6




#define SPIF 7




typedef struct CAN2

{
	u32 id;
	u32 rtr;
	u32 dlc;
	u32 byteA;
	u32 byteB;

}CAN2_MSG;




void can2_init(void);
void can2_tx(CAN2_MSG m1);
void can2_rx(CAN2_MSG *m1);


f32 read_value(u8 channel_no);


void SPI_INIT(void);
u8 SPIO(u8 data);

void s_delay(unsigned int second);
void ms_delay(unsigned int m_second);


#endif