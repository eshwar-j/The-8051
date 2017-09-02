/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 11/05/2017
 * Note(s): 4 bit mode
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include"softdelay.h"
#include"lcd4.h"
#include"connections.h"

void main()
{
	init_lcd();	
  while(1)
  {
		lcd_string(1,1,"lcd 4bit");
		lcd_string(2,1,"improved");
		while(1);
  }
}