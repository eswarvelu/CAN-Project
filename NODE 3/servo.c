#include <lpc21xx.h>
#include "header.h"




void servo_init(void)
{
    VPBDIV = 1;              // PCLK = CCLK = 60 MHz
    PINSEL0 = 0x08;          // PWM3 on P0.1
      // PCLK = 60 MHz
       //PWMPR = 3
       //PWM counter clock:
       //60 MHz / (3 + 1)
       //= 15 MHz
        PWMPR = 3;
       //300000 counts at 15 MHz:
       //300000 / 15 MHz
       //= 20 ms
        PWMMR0 = 300000 - 1;
       //Same pulse timings as your old working program
    PWMMR3 = 7500;
    PWMMCR = 0x00000003;
    PWMPCR = 0x00000800;
    PWMTCR = 0x00000009;
    PWMLER = 0x08;
}




void servo_move_to(int target)
{
    static int position = 7500;
    int i;
    /*

       Move servo in positive direction

    */
    if(position < target)
    {
        for(i = position; i <= target; i += 100)
        {
            PWMMR3 = i;
            PWMLER = 0x08;
            ms_delay(10);
        }
    }
    /*

       Move servo in negative direction

    */
    else if(position > target)
    {
        for(i = position; i >= target; i -= 100)
        {
            PWMMR3 = i;
            PWMLER = 0x08;
            ms_delay(10);
        }

    }


    /*

       Save the new servo position

    */
    position = target;

}