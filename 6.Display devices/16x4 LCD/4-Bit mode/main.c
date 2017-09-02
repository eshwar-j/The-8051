/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 12/05/2017
 * Note(s): functions same as 16x4 4 bit lcd, issues with left/right shift function
 *----------------------------------------------------------------------------*/
 
#include<reg51.h>
#include"softdelay.h"
#include"lcd4.h"

void main()
{
	int i;
	init_lcd();	
  while(1)
  {                                   
	  lcd_string(1,1,"line 1");
	  lcd_string(2,1,"line 2");
	  lcd_string(3,1,"line 3");
	  lcd_string(4,1,"line 4");
  }
}