/* flexible delay in seconds using timer0
XTAL=12Mhz*
for XTAL=24Mhz, count*40     */

#include<reg51.h>
void delay(float count)
{ 
float i;
count=(count*20);
for(i=0;i<count;i++) /*upon execution (1x time), this for loop generates 250 ms delay using TIMER 0*/
	{
		TMOD=0x01; //timer0
		TL0=0xC2;
		TH0=0x3C;
		TR0=1;     //timer0 running
		while(TF0==0);
		TF0=0;
		TR0=0;
  }
}
void main()
{
while(1)
{
	delay(1);
}
}