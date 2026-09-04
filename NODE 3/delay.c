#include<LPC21XX.H>

void s_delay(unsigned int second){
	T0PR=15000000-1;
	T0TCR=0X01;
	while(T0TC<second);
	T0TCR|=0x02;
	T0TCR=0x00;
	}

void ms_delay(unsigned int m_second){
	T0PR=60000-1;
	T0TCR=0X01;
	while(T0TC<m_second);
	T0TCR|=0x02;
	T0TCR=0x00;
	}