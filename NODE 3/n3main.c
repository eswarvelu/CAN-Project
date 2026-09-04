#include <lpc21xx.h>
#include "header.h"
#include "types.h"


						

int main()
{

    u32 value;
    CAN2_MSG m1;


	can2_init();
    servo_init();


    while(1)

    {

      can2_rx(&m1);

	  value=m1.byteA;


       if(value == 7500)


        {


          servo_move_to(7500);


        }



        else if(value == 21750)


        {


           servo_move_to(21750);
        }


        else if(value == 36000)


        {
             servo_move_to(36000);
        }


    }


}
