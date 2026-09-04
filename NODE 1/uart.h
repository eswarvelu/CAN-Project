#include <LPC21xx.H>

void uart0_init(unsigned int baud){
	PINSEL0|=0x5;
	U0LCR=0x83;
	switch(baud){	
		case 115200:U0DLL=32;	break;//PCLK=60MHz
		case 921600:U0DLL=4;	break;
		default:	U0DLL=32	;	
	}
	U0LCR=0x03;
}

void uart0_tx(unsigned char data){
	U0THR=data;
	while((U0LSR&(1<<5))==0);
}

unsigned char uart0_rx(void){
	while((U0LSR&0x1)==0);
	return U0RBR;
}


void uart0_tx_string(char *ptr){
	while(*ptr!=0){
		U0THR=*ptr;
		while((U0LSR&(1<<5))==0);
		ptr++;
	}
}

#include <stdio.h>
void uart0_tx_integer(int num){
	char buf[10];
	sprintf(buf,"%d",num);
	uart0_tx_string(buf);
}


void uart0_tx_hex(int num){
	char buf[10];
	sprintf(buf,"%X",num);
	uart0_tx_string(buf);
}


void uart0_tx_float(float num)
{
    int integer;
    int decimal;

    integer = (int)num;
    decimal = (int)((num - integer) * 100);

    uart0_tx_integer(integer);
    uart0_tx('.');
    
    if(decimal < 10)
        uart0_tx('0');

    uart0_tx_integer(decimal);
}

void uart0_clear_screen(void)
{
    int i;

    for(i = 0; i < 15; i++)
    {
        uart0_tx_string("\r\n");
    }
}


