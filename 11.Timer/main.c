/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 20/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/

#include <REGX51.H>
#include"timers.h"
#include"uart.h"

sbit led=P2^6;

void main()
{
P2=0x00;		//P0 as output port
init_timer(0,2,0x00,0xfd);
start_timer(0);
while (1);
}