/* 500.0135 ms delay using timer0
XTAL=12Mhz*/

#include<reg51.h>
void delay()
{
int i;
for(i=0;i<20;i++)
	{
		TMOD=0x07521; //timer0
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
	delay();
}
}