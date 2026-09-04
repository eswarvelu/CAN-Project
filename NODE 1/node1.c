 #include<lpc21xx.h>
#include "header.h"
#include "types.h"
#include "uart.h"

int main(){	

	CAN2_MSG m1;
	f32 f;
	can2_init();
	SPI_INIT();
	uart0_init(115200);


		/*sending data frame*/

	m1.id=0x1AF;
	m1.rtr=0;//data frame
	m1.dlc=4;
	SETBIT(IOPIN0, CS);
	while(1){   
	 f = read_value(0);
	 //uart0_clear_screen();
     if(f>=0 && f <1.1)
        {
		    uart0_tx_string("ADC VOLTAGE = ");
            uart0_tx_float(f);
            uart0_tx_string(" V\r\n");
			m1.byteA=7500;
	        m1.byteB=0;
        }

        else if(f>=1.1 && f < 2.2)
        {
		   uart0_tx_string("ADC VOLTAGE = ");
           uart0_tx_float(f);
           uart0_tx_string(" V\r\n");
           m1.byteA=21750;
	       m1.byteB=0;   
        }

        else
        {
		    uart0_tx_string("ADC VOLTAGE = ");
            uart0_tx_float(f);
            uart0_tx_string(" V\r\n");
            m1.byteA=36000;
	        m1.byteB=0;
        }


        can2_tx(m1);//data-frame
		ms_delay(1000);	
	}

}