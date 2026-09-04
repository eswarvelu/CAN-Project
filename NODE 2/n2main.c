#include <lpc21xx.h>
#include "lcd4bit.h"
#include "header.h"
#include "types.h"


#define l1_led (1<<8)
#define l2_led (1<<9)
#define l3_led (1<<10)
						
int main()
{
    u32 value;
    CAN2_MSG m1;
    IODIR0 |= l1_led | l2_led | l3_led;
    IOSET0 = l1_led | l2_led | l3_led;


	can2_init();
    lcd_init();
	lcd_command(0x01);       // Clear LCD

    lcd_command(0x80);       // Row 1, column 1
    str("CAN Bus Based");

    lcd_command(0xC0);       // Row 2, column 1
    str("Automatic Water-Level");

    lcd_command(0x94);       // Row 3, column 1
    str("Gate Control System");

    ms_delay(5000);          // Display title for 5 seconds

    lcd_command(0x01); 

    while(1)
    {
      can2_rx(&m1);
	  value=m1.byteA;

       if(value == 7500)

        {

            /* Level 1 */

            IOCLR0 = l1_led;
            IOSET0 = l2_led | l3_led;
			lcd_command(0x01);
			str("LEVEL1");

        }


        else if(value == 21750)

        {

            /* Level 2 */
			IOCLR0 = l2_led;
            IOSET0 = l1_led | l3_led;
			lcd_command(0x01);
			str("LEVEL2");
        }

        else if(value == 36000)

        {
            /* Level 3 */
            IOCLR0 = l3_led;
            IOSET0 = l1_led | l2_led;
			lcd_command(0x01);
			str("LEVEL3");

        }

		else
		{
    		lcd_command(0x01);
    		str("ERROR");
		}


    }

}