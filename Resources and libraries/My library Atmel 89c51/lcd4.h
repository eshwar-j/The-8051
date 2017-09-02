/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 11/05/2017
 * Note(s):  rw is assumed grounded
 
 LCD functions
 init_lcd();											initialize LCD
 lcd_clear(); 										clears LCD
 setcursor(row,col); 	  					specify row and colomn, Range(1,1) to (4,16)
 lcd_raw('c');										writes single character at current cursor position, auto increment
 lcd_raw(data);										writes ascii data to lcd, auto increments cursor
 lcd_string(row,col,"string");		write word or sentence to given row and column
 lcd_shift_right();		 	 				  shift LCD content right
 lcd_shift_left(); 		 	 				  shift LCD content left
 *----------------------------------------------------------------------------*/

#ifndef __lcd4_h
#define __lcd4_h

#include"connections.h"

void lcd_port(char a)
{
	if(a & 1) D4 = 1;
	else      D4 = 0;
	
	if(a & 2) D5 = 1;
	else      D5 = 0;
	
	if(a & 4) D6 = 1;
	else	    D6 = 0;
	
	if(a & 8) D7 = 1;
	else      D7 = 0;
}

void lcd_cmd(char a)
{ 
	rs = 0;             // => RS = 0
	lcd_port(a);
	en  = 1;             // => E = 1
  delay_ms(1);
  en  = 0;             // => E = 0
}

void setcursor(char row, char column)
{
	if(row == 1)  			 //line 1 address 0x80....0x8F
	{
		lcd_cmd(0x8);											//send 0x8
		lcd_cmd((column-1) & 0x0F);						//send 0+0xcol
	}
	if(row == 2) 	 			//line 2 address 0xC0....0xCF
	{
		lcd_cmd(0xC);											//send 0xC
		lcd_cmd((column-1) & 0x0F);						//send 0+0xcol
	}
	if(row == 3)				// line 3 address 90....9F, valid only for 16x4 LCD
	{
		lcd_cmd(0x9);											//send 0x9
		lcd_cmd((column-1) & 0x0F);						//send 0+0xcol
	}
	if(row == 4)				//line 3 address 0xD0....0xDF, valid only for 16x4 LCD
	{
		lcd_cmd(0xD);											//send 0xD
		lcd_cmd((column-1) & 0x0F);						//send 0+0xcol
	}
}

void init_lcd()
{
	lcd_port(0x00);
	delay_ms(5);
	///////////// Reset process from datasheet /////////
  lcd_cmd(0x03);
	delay_ms(10);
  lcd_cmd(0x03);
	delay_ms(2);
  lcd_cmd(0x03);
  /////////////////////////////////////////////////////
  lcd_cmd(0x02);    
	lcd_cmd(0x02);
  lcd_cmd(0x08); 	
	lcd_cmd(0x00); 
	lcd_cmd(0x0C);     
  lcd_cmd(0x00);    
  lcd_cmd(0x06);   
}

void lcd_raw(char a)
{
	 rs = 1;             // => RS = 1
   lcd_port((a&0xF0)>>4);     // transfer higher nibble
	 en = 1;
	 delay_ms(1);
	 en = 0;
	 lcd_port(a&0x0F);     			// transfer lower nibble
	 en = 1;
	 delay_ms(1);
	 en = 0;
}

void lcd_string(char x, char y, char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(i==0) setcursor(x,y);		//set start address for string
	 lcd_raw(a[i]);
	}
}

void lcd_shift_right()
{
	lcd_cmd(0x01);
	lcd_cmd(0x0C);
}

void lcd_shift_left()
{
	lcd_cmd(0x01);
	lcd_cmd(0x08);
}

void lcd_clear()
{
	lcd_cmd(0);
	lcd_cmd(1);
}
#endif
