/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 12/07/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/
 
#include <REGX51.H>

sbit lamp=P2^0;


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
lamp=1;delay(700);lamp=0;delay(700);
}

void main()
{ P2=0x00;		//P0 as output port
lamp=0;
 IE=0x81;		//enable interrupts
while (1);
}