/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 08/05/2017
 * Note(s): multiplexing upto 3 digits
 *----------------------------------------------------------------------------*/

#ifndef __seven_seg_multiplexed_h
#define __seven_seg_multiplexed_h

/* 	common cathode				common anode
	E		0					E		1

*/
#define E 1

#include<seven_seg.h>
#include"connections.h"

int ones=0,tens=0,hundreds=0;
extern int count=0;

void current_count()
{
ones=count%10;
tens=(count/10)%10;
hundreds=(count/100);
	
seven_seg(ones);
units_module=E;
delay_ms(20);
units_module=~E;

seven_seg(tens);
tens_module=E;
delay_ms(20);
tens_module=~E;

seven_seg(hundreds);
hundreds_module=E;
delay_ms(20);
hundreds_module=~E;	
}

void count_up()
{
count=count+1;
current_count();	
}

void count_down()
{
count=count-1;
current_count();	
}
#endif