/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 17/05/2017
 * Note(s): XTAL=11.059Mhz
 *----------------------------------------------------------------------------*/

#include <REGX51.H>

void main()
{
 unsigned char c;
 TMOD=0x20; 		//timer mode 2, 8-bit auto reload
 TH1=0XFD; 			//baud rate=9600
 SCON=0X50;			//serial mode 1  REN=1
 TR1=1; 

/*receive*/
 while(RI==0); 		//check receive interrupt
  c=SBUF;			//move sbuf to temporary variable, c will contain ASCII value of reseived character
  if(c=='a') 			
  P1=~P1;			//toggle port 1 if char 'a' is received
  RI=0;				// reset RI to be set again by next character reception
}