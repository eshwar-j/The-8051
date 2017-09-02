/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 19/05/2017
 * Note(s): XTAL=11.059Mhz
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include"softdelay.h"
#include"uart.h"
#include"lcd4.h"

void main()
{
init_uart();
uart_tx_string("Enter text to send to LCD\n\r");
init_lcd();
lcd_string(1,1,"Your text:");
	setcursor(2,1);
	while(1)
	{
		uart_rx_char();
		lcd_raw(SBUF);		//write received sbuf to lcd
	}
}