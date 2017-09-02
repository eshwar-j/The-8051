/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 10/05/2017
 * Note(s): simple 8 bit lcd
 *----------------------------------------------------------------------------*/

#include <REGX51.H>
sbit rs=P1^5;
sbit rw=P1^6;
sbit e=P1^7;

void delay(unsigned int d)
{
	int i,j;
	{
		for(i=0;i<d;i++)
		{
			for(j=0;j<1275;j++);
		}
	}
}

void lcdcmd(char cmd)
{
	P2=cmd;
	rs=0;rw=0;
	e=1;delay(10);e=0;
}

void lcddata(char dat)
{	
	P2=dat;
	rs=1;rw=0;
	e=1;delay(10);e=0;
}

void lcd_init()
{
		lcdcmd(0x38);
		delay(10);
		lcdcmd(0x0E);
		delay(10);
		lcdcmd(0x01);
		delay(10);	
		lcdcmd(0x06);
		delay(10);
	  lcdcmd(0x80);
}

void main()
{
		lcd_init();
		lcddata('1');
		delay(20);
		lcddata('6');
		delay(20);
		lcddata('x');
		delay(20);
		lcddata('2');
		delay(20);
		lcddata('L');
		delay(20);
		lcddata('C');
		delay(20);
		lcddata('D');
while(1);
}