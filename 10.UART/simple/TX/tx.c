/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 17/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/

#include <REGX51.H>

void main()
{
 TMOD=0x20; // Timer1 in Mode2. 8-bit auto reload
 TH1=0XFD;  // baud rate=9600
 SCON=0X50; // Asynchronous mode, 8-bit data and 1-stop bitmode 1  REN=1
 TR1=1;		// Timer1 running

/*transmit*/
 SBUF='A';		//char--> Ascii value of the character to be transmitted.
 while(TI==0);
 TI=0;
}			