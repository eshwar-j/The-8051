/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 03/05/2017
 * Note(s): simple relay interfacing
 *---------------------------------------------------------------------------*/

#include<reg51.h>
sbit DIPswitch = P2^0;             // DIP switch input on Port 1 bit 4
sbit relay = P2^1;             	   // green relay output on Port 1 bit 5

void main (void) 
{
	relay=0 ;							// make relay pin initial low, because on reset all pins of 8051 are high

  while (1) 
		{
    if (DIPswitch == 0) 			// check if input P1.4 is low
			{          
      relay =1 ;               		 // set output P1.5 to high
										//P2=0x00; for entire port 2
      }
    else 
			{                          // if input P1.4 is low
      relay = 0;              		  // set output P1.5 to low
      }
    }
}
