/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 07/05/2017
 * Note(s): 
			Common cathode display
			module transistor active low
			0=segment off
			1=segment on
			
			Common anode display
			module transistor active high
			0=segment on
			1=segment off
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include<seven_seg.h>
#include"connections.h"
#include"softdelay.h"

void main()
{
	P2=0x00;
	while(1)
	{
		seven_seg(0);
		delay_ms(250);
		seven_seg(1);
		delay_ms(250);
		seven_seg(2);
		delay_ms(250);		
	}
}	
			