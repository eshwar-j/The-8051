/*----------------------------------------------------------------------------*/
/* Example  :Program to Display Picture in GLCD 128x64         	      	      */
/*----------------------------------------------------------------------------*/
/* Filename	:GLCD.c						                	Date:10/01/08	  */
/*												                              */
/* Company	:PANTECH SOLUTIONS					                              */
/*----------------------------------------------------------------------------*/
/* Note	    :To display a message in LCD 8 bit mode.					      */
/*----------------------------------------------------------------------------*/

#include <reg51.h>								//Define 8051 Registers
#include <stdio.h>								//Define I/O Functions
#include<intrins.h>
#include"images.h"
#include"softdelay.h"

#define DATA P2									//Define DATA to Port1

//Define control pins
sbit CS1 	= P3^2;								//CS1 select LCD IC1
sbit CS2 	= P3^3; 							//CS2 select LCD IC2

sbit RS	    = P3^4;								//Register Select 
sbit RW 	= P3^5;								//LCD Read/Write
sbit lcd_e 	= P3^6;								//LCD Enable 

sbit RST 	= P3^7;
												
//#define size 1024
void GLCD_PutPicture(const unsigned char *); 
void Select_page(unsigned char);

int i;

//----------------------------------
//          LCD Functions 
//----------------------------------
void GLCD_Init();
void GLCD_Data(unsigned char);
void GLCD_Comd(unsigned char);
void delay_ms(int);

//----------------------------------
//       LCD command Function 
//----------------------------------
void GLCD_Comd(unsigned char cmnd)	
 {
	DATA = cmnd;		//send command to port
	RS = 0;				//make it RS to Low
	RW = 0;				//make it RW to low 
	lcd_e = 1;			//enbale high
	_nop_();
	lcd_e = 0;			//enable low
 }

//----------------------------------
//       LCD Data Function 
//----------------------------------
void GLCD_Data(unsigned char dat)	
 {
	DATA = dat;			//send command to port
	RS = 1;				//make it RS to high
	RW = 0;				//make it RW to low
	lcd_e = 1;			//enbale high
	_nop_();
	lcd_e = 0;			//enbale low
 }

//----------------------------------
//		GLCD Initialization Function 
//----------------------------------
void GLCD_Init()
{
	unsigned char Comd[5]={0xc0,0xb8,0x40,0x3f};//LCD Command list
	Select_page(1);			//send commands to page1
	for(i=0;i<4;i++)
	GLCD_Comd(Comd[i]);		
	Select_page(0);			//send commands to page0
	for(i=0;i<4;i++)
	GLCD_Comd(Comd[i]);
}

//----------------------------------
//		Page Selection 
//----------------------------------
void Select_page(unsigned char Page)
{
	if(Page)
	{
		CS1=0;		//Page 0 LCD IC1
		CS2=1;
	}
	else 
		{
			CS1=1;	//Page 1 LCD IC2	
			CS2=0;
		}
}

//-------------------------------------
//	Display Picture for page0 & page1
//-------------------------------------
void GLCD_PutPicture(const unsigned char *ip) //Change here for method 1,2 and 3
{
  	int Page=0,i=0;
  	int Column=0;
    
  	for (Page = 0; Page < 8; Page++) 		
    {
		Select_page(1);						//Display part of image to Page1
   		GLCD_Comd(0xb8 | Page);
   		GLCD_Comd(0x40);
      		
      for (Column = 0; Column < 128; Column++) 
		{
		  	if (Column == 64)
	        {  
				Select_page(0);					//Display part of image to Page0
				GLCD_Comd(0xb8 | Page);
	   			GLCD_Comd(0x40);  
	        }
			GLCD_Data(*ip++);   						
	    }
    }
}


//------------------------
//	Main Program 
//-----------------------
void main(void)
{
	delay_ms(2);		
	RST = 1;
	delay_ms(5);		
	RST	=	0;
	delay_ms(5);		
	RST =	1;
	delay_ms(5);		
	GLCD_Init();				//Initialize GLCD
	delay_ms(15);		
	GLCD_PutPicture(firplce);//Display Image
	while(1);					//wait forever
} 


