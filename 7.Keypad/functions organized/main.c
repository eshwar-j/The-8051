/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 15/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include"softdelay.h"
#include"lcd4.h"
#include"keypad.h"

int main()
{
	char c;
	init_lcd();
	c='_';      	//initial character indicating blank field                                
  while(1)
  {                                   
		lcd_string(1,1,"Keys Pressed:");
		while(c)
		{
			setcursor(1,14);
			lcd_raw(c);
		  delay_ms(50);
	    while(!(c = Read_Keypad()));
   }
	 lcd_clear();
 }
}
