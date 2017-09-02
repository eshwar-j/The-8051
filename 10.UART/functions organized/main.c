/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 18/05/2017
 * Note(s): XTAL=11.059Mhz
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include"uart.h"

void main()
{
init_uart();
uart_tx_string("8051 serial terminal\n\rEcho on\n\r");
uart_rx_string();
while(1);
}