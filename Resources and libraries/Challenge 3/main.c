/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Created on 23 June, 2017
 * Note(s):
 *----------------------------------------------------------------------------*/
 
#include <reg51.h>								//Define 8051 Registers
#include <stdio.h>								//Define I/O Functions
#include<intrins.h>
#include"softdelay.h"
#include"images.h"
#include"keypad_4x3.h"

#define DATA P2									//Define DATA to Port1

//GLCD control pins-------------------------------------------------------------------------

sbit CS1 	= P3^0;								//CS1 select LCD IC1
sbit CS2 	= P3^1; 							//CS2 select LCD IC2
sbit RS	  = P3^2;								//Register Select 
sbit lcd_e 	= P3^3;								//LCD Enable 
// RW assumed grounded
// RST assumed vcc

// Function declarations---------------------------------------------------------------------

void init_glcd();
void glcd_data(unsigned char);
void glcd_cmd(unsigned char);
void select_page(unsigned char);
void glcd_draw(const unsigned char *); 

int i;		// global variable for all for loops

// Main --------------------------------------------------------------------------------------

void main(void)
{
	char c;
	delay_ms(5);
	init_glcd();				//Initialize GLCD
	delay_ms(15);		
	while(1)
	{
		switch(Read_Keypad())
		{
			case 'f':{glcd_draw(ferrari_text);delay_sec(2);glcd_draw(ferrari_logo);delay_sec(2);break;}
			case 'l':{glcd_draw(lamborghini_text);delay_sec(2);glcd_draw(lamborghini_logo);delay_sec(2);break;}
		}
	}
}

// Function definitions-----------------------------------------------------------------------

void init_glcd()
{
	unsigned char Comd[5]={0xc0,0xb8,0x40,0x3f};//LCD Command list
	select_page(1);			//send commands to page1
	for(i=0;i<4;i++)
	glcd_cmd(Comd[i]);		
	select_page(0);			//send commands to page0
	for(i=0;i<4;i++)
	glcd_cmd(Comd[i]);
}

void glcd_cmd(unsigned char cmnd)	
 {
	DATA = cmnd;		//send command to port
	RS = 0;				//make it RS to Low
	lcd_e = 1;			//enable high
	_nop_();
	lcd_e = 0;			//enable low
 }

void glcd_data(unsigned char dat)	
 {
	DATA = dat;			//send command to port
	RS = 1;				//make it RS to high
	lcd_e = 1;			//enbale high
	_nop_();
	lcd_e = 0;			//enbale low
 }

void select_page(unsigned char Page)
{
	if(Page)
			 { CS1=0;CS2=1; }		//Page 0 LCD IC1
	else 
			 { CS1=1;CS2=0; }	//Page 1 LCD IC2
}

void glcd_draw(const unsigned char *ip) //Change here for method 1,2 and 3
{
  	int Page,Column;
  	for (Page = 0; Page < 8; Page++) 		
    {
		select_page(1);						//Display part of image to Page1
   		glcd_cmd(0xb8 | Page);
      		
      for (Column = 0; Column < 128; Column++) 
		{
		  	if (Column == 64)
				{  
					select_page(0);					//Display part of image to Page0
					glcd_cmd(0xb8 | Page);
				}
		glcd_data(*ip++);   						
		}
    }
}
