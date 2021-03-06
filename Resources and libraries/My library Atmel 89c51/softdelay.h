/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 02/05/2017
 * Note(s): code produces delay in ms for XTAL=11.059Mhz
			small number accuracy = 1ms keep j<111
			large number accuracy keep j<113
 *----------------------------------------------------------------------------*/

#ifndef __softdelay_h
#define __softdelay_h

void delay_ms(unsigned int count)
{
unsigned int i,j;
for(i=0;i<count;i++)
	{
	for(j=0;j<114;j++);
	}
}

void delay_sec(unsigned int count)
{
count=count*1000;
delay_ms(count);
}
#endif