/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 16/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/
 
#ifndef __adc_h
#define __adc_h

#include"connections.h"

void timer0() interrupt 1  // Function to generate clock of frequency 500KHZ using Timer 0 interrupt.
{
 adc_clk=~adc_clk;
}

void init_adc()
{
 soc=oe=ale=0;   					//Initialize all the control lines to zero.
 eoc=1;        		 	 			//Configure the EOC pin as I/P
 TMOD=0x02;								//Configure timer for clock generation to provide to adc IC
 TH0=0xFD;
 IE=0x82;
 TR0=1;
 P1=0xff;									//Configure P2 as I/P
 P2=0x00;									//Configure P3 as O/P
}

void adc_show_ch2()
{
	unsigned char temp;
  s1=0;s2=1;s3=0;					//select adc channel 2
  ale=1;soc=1;        		// Latch the address by making the ALE high and start conversion after latching the channel address
  soc=0;ale=0;      		  //Pull ALE line to zero after starting the conversion and pull Start line to zero after starting conversion
  
  while(eoc==0); 					// Wait till the ADC conversion is completed, EOC will be pulled to HIGH by ADC0809 once conversion is completed.

  oe=1;         				  //Make the Output Enable high to bring the ADC data to port pins
  temp=adc_in; 		//read analog from P2 to temp variable
  oe=0;
	digital_out=temp;	//move data obtained from adc data port to P3
}
#endif