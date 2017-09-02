/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 08/05/2017
 * Note(s): 3 digit multiplexing
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include"softdelay.h"
#include<seven_seg_multiplexed.h>

void main()
{
unsigned int i;
count_up();
count_up();
for(i=0;i<10;i++)					//hold current value for some time
	{
		current_count();
	}
count_down();
while(1)
	{
		current_count();			//keep shownig current count
	}
}