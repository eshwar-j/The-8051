/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 14/05/2017
 * Note(s): issues with clr and disp on off function
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include"softdelay.h"
#include"font_8x8.h"
#include"font_5x7.h"
#include"symbols.h"
#include"glcd.h"

void main()
{
//clrlcd();
//displayon();
	while(1)
	{
	setline(0);setcursor(0);glcd_symbol(signal);
						setcursor(103);glcd_symbol(level);
						setcursor(112);glcd_symbol(percent);
						setcursor(120);glcd_symbol(battery);
	glcd_string_font_8x8(5,2,"-SCREEN LOCKED-");   //(line,cursor,string)
 	glcd_string_font_5x7(1,0,"AIRTEL");
  } 
}