/*Timer functions

init_timer(timer X, timer mode, TH value, TL value);
eg:init_timer(   0,      2,       0x00,    0x54)
start_timer(timer X);
*/

#ifndef __timers_h
#define __timers_h

void init_timer(unsigned int timer,unsigned int mode,unsigned char hi,unsigned char lo)
{
if(timer==0)
{
TH0=hi;TL0=lo;
switch(mode)
	{
	case 0:TMOD|=0x00;break;
	case 1:TMOD|=0x01;break;
	case 2:TMOD|=0x02;break;
	case 3:TMOD|=0x03;break;
	}
}
if(timer==1)
{
TH1=hi;TL1=lo;
switch(mode)
	{
	case 0:TMOD|=0x00;break;
	case 1:TMOD|=0x10;break;
	case 2:TMOD|=0x20;break;
	case 3:TMOD|=0x30;break;
	}
}
}

void start_timer(unsigned int t)
{
if(t==0)TR0=1;
if(t==1)TR1=1;
}

void stop_timer(unsigned int t)
{
if(t==0)TR0=0;
if(t==1)TR1=0;
}
#endif