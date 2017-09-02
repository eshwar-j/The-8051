/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 02/05/2017
 * Note(s): full drive.c
 *----------------------------------------------------------------------------*/

#include <REGX51.H>
#include"softdelay.h"

void clockwise(unsigned int c)
{
	int i;
   for(i=0;i<c;i++)
	 {
	P2 = 0x09; //1001
	delay_ms(200);
	P2 = 0x0C; //1100
	delay_ms(200);
	P2 = 0x06; //0110
	delay_ms(200);
   	P2 = 0x03; //0011
	delay_ms(200);
	 }
}

void anticlockwise(unsigned int a)
{
int q;
	for(q=0;q<a;q++)
	 {
   	P2 = 0x03; //0011
	delay_ms(200);
	P2 = 0x06; //0110
	delay_ms(200);
	P2 = 0x0C; //1100
	delay_ms(200);
	P2 = 0x09; //1001
	delay_ms(200);
	 }
}

void stop(unsigned int s)
{
int m;
	for(m=0;m<s;m++)
{
P2=0x00;
delay_ms(10);
}
}

void main()
{
 while(1)
{
	clockwise(5);
 anticlockwise(5);
	stop(100);
}
}