/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 09/05/2017
 * Note(s): counts up or down using interrupts and displays on 7seg
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include"softdelay.h"
#include"seven_seg_multiplexed.h"
#include"interrupts.h"

void main()
{
enable_interrupts();
while(1)
	{
		current_count();
	}
}