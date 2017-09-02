//*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 16/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*

#include <REGX51.H>

sbit s1=P3^0;
sbit s2=P3^1;
sbit s3=P3^2;
sbit ale=P3^3;
sbit soc=P3^4;
sbit eoc=P3^5;
sbit oe=P3^6;

void main()
{
 soc=oe=ale=0;					//Initialize all the control lines to zero.
 eoc=1;							//Configure the EOC pin as I/P
 P1=0xff;						//Configure P2 as I/P
 P2=0x00;						//Configure P3 as O/P
 while(1)
 {
	unsigned char temp;
  s1=0;s2=1;s3=0;					//select adc channel 2
  ale=1;soc=1;        		// Latch the address by making the ALE high and start conversion after latching the channel address
  soc=0;ale=0;      		  //Pull ALE line to zero after starting the conversion and pull Start line to zero after starting conversion
  
  while(eoc==0); 					// Wait till the ADC conversion is completed, EOC will be pulled to HIGH by ADC0809 once conversion is completed.

  oe=1;         				  //Make the Output Enable high to bring the ADC data to port pins
  temp=P1; 		//read analog from P2 to temp variable
  oe=0;
  P2=temp;	//move data obtained from adc data port to P3
 }
}