/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 10/05/2017
 * Note(s):  rw is assumed grounded
 
 LCD functions
 init_lcd();											initialize LCD
 lcd_clear(); 										clears LCD
 setcursor(row,col); 	  					specify row and colomn, Range(1,1) to (4,16)
 lcd_raw('c');										writes character at current cursor position, auto increment cursor
 lcd_raw(data);										writes ascii data to lcd, auto increments cursor
 lcd_string(row,col,"string");		write word or sentence to given row and column
 lcd_shift_right();		 	 				  shift LCD content right
 lcd_shift_left(); 		 	 				  shift LCD content left
 *----------------------------------------------------------------------------*/

#ifndef __lcd8_h
#define __lcd8_h

#include"connections.h"

void lcd_port(char a)
{
	if(a & 1)   D0 = 1;
	else        D0 = 0;
	
	if(a & 2)   D1 = 1;
	else        D1 = 0;
	
	if(a & 4)   D2 = 1;
	else        D2 = 0;
	
	if(a & 8)   D3 = 1;
	else        D3 = 0;
	
	if(a & 16)  D4 = 1;
	else        D4 = 0;

	if(a & 32)  D5 = 1;
	else        D5 = 0;
	
	if(a & 64)  D6 = 1;
	else 	      D6 = 0;
	
	if(a & 128) D7 = 1;
	else        D7 = 0;
}
void lcd_cmd(char a)
{ 
  rs = 0;             // => rs = 0
  lcd_port(a);        //Data transfer
  en  = 1;            // => E = 1
  delay_ms(1);
  en  = 0;            // => E = 0
}

void init_lcd()
{
	lcd_port(0x00);
	rs = 0;
	///////////// Reset process from datasheet /////////
  lcd_cmd(0x30);		//display is set to 8-bit mode
	delay_ms(10); 		//wait for more than 15 ms
  lcd_cmd(0x30);		//display is set to 8-bit mode
	delay_ms(10); 		//wait for more than 4.1ms
  lcd_cmd(0x30); 		//display is set to 8-bit mode
	delay_ms(2);	 		//wait for more than 100us

  lcd_cmd(0x38);    //function set:number of display lines and character font are defined , these values cannot be changed later
  lcd_cmd(0x0C);    //display on,cursor off,blink off
  lcd_cmd(0x01);    //clear display
  lcd_cmd(0x06);    //entry mode set to automatically increment by 1
}

void setcursor(char row, char column)
{
	if(row == 1)
	  lcd_cmd(0x80 + (column-1));		//line 1 address 80...8F
	if(row == 2)
		lcd_cmd(0xC0 + (column-1));		//line 2 address C0...CF
	if(row == 3)
		lcd_cmd(0x90 + (column-1));		//line 3 address 90...CF
	if(row == 4)
		lcd_cmd(0xD0 + (column-1));		//line 4 address D0...CF
}

void lcd_raw(char a)
{
   rs = 1;             // => rs = 1
   lcd_port(a);        //Data transfer
   en  = 1;            // => E = 1
   delay_ms(1);
   en  = 0;            // => E = 04
}
void lcd_string(char row, char column, char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(i==0) setcursor(row,column);
	 lcd_raw(a[i]);
	}
}

void lcd_shift_right()
{
	lcd_cmd(0x1C);
}

void lcd_shift_left()
{
	lcd_cmd(0x18);
}

void lcd_clear()
{
	  lcd_cmd(0x01);
}
#endif