/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 20/05/2017
 * Note(s): it is not possible to demonstrate all interrupts because of conflict
			INT0 and INT1 are feasible
 *----------------------------------------------------------------------------*/

#include <REGX51.H>
#include"softdelay.h"
#include"interrupts.h"


void main()
{ 
 P2=0x00;		//P0 as output port
 enable_interrupts();
while (1)
	{
		routine_led=1;
		delay_ms(500);
		routine_led=0;
		delay_ms(500);
	}
}