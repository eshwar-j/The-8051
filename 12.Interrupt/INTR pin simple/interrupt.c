/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 20/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/
 
#include <REGX51.H>

sbit buzzer=P2^0;
sbit led1=P2^1;
sbit led2=P2^2;

void delay(unsigned int d)
 {
    int i,j;
      for (i=0;i<d;i++) 
	{
	    for (j=0;j<1275;j++);
	}					
						  
}

void interrupt_0_isr(void) interrupt 0 //"using" keyword specifies which register bank will be used in order to avoid corrupting foreground registers
{
buzzer=1;delay(200);buzzer=0;
}

void main()
{ P2=0x00;		//P0 as output port
 led1=led2=1;
 IE=0x81;
while (1)
	{
	 led1=led2=1;
	 delay(100);
	 led1=led2=0;
	 delay(100);
	 }
}