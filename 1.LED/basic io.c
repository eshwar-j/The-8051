/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 01/05/2017
 * Note(s): to define port pin, syntax is sbit led1=P1^0
			to define whole port, syntax is #define led_port P1*
			to set port as input port, port value=0xff
			to set port as output port, port value=0x00
 *----------------------------------------------------------------------------*/

#include<reg51.h>

sbit DIPswitch = P1^4;             // DIP switch input on Port 1 bit 4
sbit LED = P1^5;             	   // green LED output on Port 1 bit 5

void main (void) 
{
	LED=0 ;												// make led pin initial low, because on reset all pins of 8051 are default input(high)
  while (1) 
		{
    if (DIPswitch == 0) 					// check if input P1.4 is low
			{          
      LED =1 ;               		 // set output P1.5 to high
																//P2=0x00; for entire port 2
      }
    else 
			{                          // if input P1.4 is low
      LED = 0;              		  // set output P1.5 to low
      }
    }
}
