/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 10/05/2017
 * Note(s): simple 8 bit lcd
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include"softdelay.h"
#include"lcd8.h"

void main()
{
	int i;
	init_lcd();	
  while(1)
  {                            
		lcd_string(1,1,"lcd 8 bit");
		lcd_string(2,1,"improved");
		while(1);
  }
}