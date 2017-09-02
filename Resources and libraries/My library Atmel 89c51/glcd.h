/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 14/05/2017
 * Note(s): problem with on off function
			GLCD functions
			ctrloff();
			clrlcd();
			displayon();
			displayoff();
			setline();																			value between 0~7
			setcursor();																		value between 0~127
			glcd_symbol(symbol name);						  				  displays symbol name from file symbol.h 
			glcd_string_font_5x7((line,cursor,"string");		printing string to line,cursor in 5x7
			glcd_string_font_8x8((line,cursor,"string");		printing string to line,cursor in 8x8
 *----------------------------------------------------------------------------*/

Author: Eshwar jorvekar
Date  : 14/05/2017
Note  :
problem with on off function
reference code from engineersgarage.com
GLCD functions
ctrloff();
clrlcd();
displayon();
displayoff();
setline();																			value between 0~7
setcursor();																		value between 0~127
glcd_symbol(symbol name);						  				  displays symbol name from file symbol.h 
glcd_string_font_5x7((line,cursor,"string");		printing string to line,cursor in 5x7
glcd_string_font_8x8((line,cursor,"string");		printing string to line,cursor in 8x8
*/

#ifndef __glcd_h
#define __glcd_h

#include<softdelay.h>

#define GlcdDataBus P2
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
sbit CS1=P1^3;
sbit CS2=P1^4;

unsigned char c;
unsigned char z=0;
void ctrloff()
{
	RS=0;
	RW=0;
	EN=0;
	CS1=0;
	CS2=0;
}

void displayon()
{ 
	ctrloff();
	GlcdDataBus=0x3f;  
	CS1=1;CS2=1;
	RW=0;RS=0;
	EN=1;
	//delay_ms(5);
	EN=0;
}

void displayoff()
{
	ctrloff();
	GlcdDataBus=0x3e;
	CS1=1;CS2=1;
	RS=0;RW=0;
	EN=1;
	//delay_ms(5);
	EN=0;
}


void setline(unsigned char x)		//		setline(i++);	 Function to Scroll Strings			 
{
	ctrloff();
	GlcdDataBus=0xb8|x;	   //0xb8 represents Line 0, line range 0-7
	CS1=1;
	CS2=1;
	RS=0;
	RW=0;
	EN=1;
	//delay_ms(5);
	EN=0;					  
}

void setcursor(unsigned char y)	
{
	if(y<64)
	{
		ctrloff();
		c=y;
		GlcdDataBus=0x40|(y&63);	  //0x40 represents Column 0
		CS1=1;CS2=0;
		RS=0;
		RW=0;
		EN=1;
		//delay_ms(5);
		EN=0;
	}
	else
	{ 
		c=y;
		GlcdDataBus=0x40|((y-64)&63);	  //0x40 represents Column 0
		CS2=1;CS1=0;
		RS=0;
		RW=0;
		EN=1;
		//delay_ms(5);
		EN=0;
	}
}

void glcd_string_data(unsigned char *value,unsigned int limit)
{
	unsigned int i;
	for(i=0;i<limit;i++)
	{
		if(c<64)
		{
			GlcdDataBus=value[i];
			CS1=1;CS2=0;
			RS=1;
			RW=0;
			EN=1;
			//delay_ms(5);
			EN=0	;
			c++;
		}
		else
		{ 
			setcursor(c);
			GlcdDataBus=value[i];
			CS2=1;CS1=0;
			RS=1;
			RW=0;
			EN=1;
			//delay_ms(5);
			EN=0	;
			c++;
		}
		if(c>127)
		   return;
	}
}

void glcd_cmd(char line)
{
    GlcdDataBus = line;   //Send the Command 
    RS = 0;              	// Send LOW pulse on RS pin for selecting Command register
    RW = 0;               // Send LOW pulse on RW pin for Write operation
    EN = 1;               // Generate a High-to-low pulse on EN pin
    //delay_ms(5);
    EN = 0;

}

/* Function to send the data to LCD */
void glcd_symbol_data(char dat)
{
    GlcdDataBus = dat;   //Send the data on DataBus
    RS = 1;              // Send HIGH pulse on RS pin for selecting data register
    RW = 0;              // Send LOW pulse on RW pin for Write operation
    EN = 1;              // Generate a High-to-low pulse on EN pin
		//delay_ms(5);
    EN = 0;

}

void glcd_symbol(char *ptr_array)
{
    int i;
    for(i=0;i<8;i++) // increment i to expand pixel printing
        glcd_symbol_data(ptr_array[i]);
}

void glcd_string_font_8x8(unsigned char x,unsigned char y ,unsigned char *str)
{
	unsigned char i;
	unsigned int a;
	setline(x);
	setcursor(y);
	for(i=0;str[i]!=0;i++)
	{
		a=(*(str+i));
		a*=8;
		glcd_string_data(&Character8x8[a],8);
	}
}

void glcd_string_font_5x7(unsigned char x,unsigned char y ,unsigned char *str)
{
	unsigned char i;
	unsigned int a;
	setline(x);
	setcursor(y);

	for(i=0;str[i]!=0;i++)
	{
		a=(*(str+i)-32);
		a*=5;
		glcd_string_data(&font5x7[a],5);
	}
}
void clrlcd()
{
    unsigned char i,j;
    for (i=0;i < 8;i++)
    {
	setline(0);
	setcursor(0);
        for (j= 0 ;j < 128; j++)
        glcd_string_data(&z,1);
    }
}
#endif