/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 31/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/
 
#include <REGX51.H>
#include<intrins.h>
#include"i2c.h"

// Main function
void main()
{	
	unsigned char RxByte = 0;	
init_i2c();					// Initialize i2c pins								
i2c_start();				// Send start bit on i2c
i2c_send_byte(0xD0);		// Send 0xA0 on i2c
//RxByte = i2c_read_byte();	// Read value from i2c. if no slave is attached on the bus, thus RxByte will receive a value of 0xFF
	i2c_stop();					// Send stop bit on i2c

	while(1);
}