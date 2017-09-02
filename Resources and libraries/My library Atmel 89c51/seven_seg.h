/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 07/05/2017
 * Note(s): 7seg multipurpose
 
			Common anode display
			module transistor active high
			0=segment on
			1=segment off

			Common cathode display
			module transistor active low
			0=segment off
			1=segment on
 *----------------------------------------------------------------------------*/

#ifndef __seven_seg__h
#define __seven_seg_h

#include"connections.h"

void seven_seg(unsigned int seg)
{
	if(seg & 1) B0=1;
	else B0=0;
	if(seg & 2) B1=1;
	else B1=0;
	if(seg & 4) B2=1;
	else B2=0;
	if(seg & 8) B3=1;
	else B3=0;
}
#endif