/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 02/05/2017
 * Note(s): bipolar.c
 *----------------------------------------------------------------------------*/


#include <REGX51.H>
#include"softdelay.h"

void clockwise(unsigned int c)
{
	int i;
   for(i=0;i<c;i++)
	 {
	 P2=0x01; //0001
   delay_ms(200);
   P2=0x04; //0100
   delay_ms(200);
   P2=0x02; //0010
   delay_ms(200);
   P2=0x08; //1000
   delay_ms(200);
	 }
}

void anticlockwise(unsigned int a)
{
int q;
	for(q=0;q<a;q++)
	 {
   P2=0x08; //1000
   delay_ms(200);
   P2=0x02; //0010
   delay_ms(200);
   P2=0x04; //0100
   delay_ms(200);
   P2=0x01; //0001
   delay_ms(200);
	 }
}

void stop(unsigned int s)
{
int m;
	for(m=0;m<s;m++)
{
P2=0x00;
delay_ms(1000);
}
}

void main()
{
 while(1)
{
	clockwise(10);
		stop(5);
 anticlockwise(10);
		stop(5);	
}
}