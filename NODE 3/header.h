#ifndef __HEADER_H_
#define __HEADER_H_
#include "types.h"

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

void s_delay(unsigned int second);
void ms_delay(unsigned int m_second);

void servo_init(void);
void servo_move_to(int target);

#endif

