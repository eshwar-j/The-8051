/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 16/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/

#include <REGX51.H>
#include"timers.h"
#include"adc.h"
#include"interrupts.h"

void main()
{
enable_interrupts();
init_adc();
 while(1)
 {
	adc_show_ch2();
 }
}