/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 31/05/2017
 * Note(s): 

i2c functions
init_i2c(); 								Sets initial values of SCL and SDA pins
i2c_start(); 								Sends start bit sequence
i2c_rep_start();						Sends start bit sequence again
i2c_stop();									Sends stop bit sequence
i2c_ack();									Sends ACK bit sequence
void i2c_n_ack();						Sends NACK bit sequence
i2c_send_byte(hex value);		Transfers one byte
i2c_read_byte();						Reads one byte and stores in RxByte
 *----------------------------------------------------------------------------*/

#ifndef __i2c_h
#define __i2c_h

#include"connections.h"

void init_i2c(void)
{	
	SDA = 1;
	SCL = 1;
}

void i2c_start(void)
{
	SCL=1;
	SDA=1;
	_nop_();
	SDA=0;
	_nop_();
}

void i2c_rep_start(void)
{
	SCL=0;
	_nop_();
	SDA=1;
	_nop_();
	SCL=1;
	_nop_();
	SDA=0;
	_nop_();
}

void i2c_stop(void)
{
	SCL=0;
	_nop_();
	SDA=0;
	_nop_();
	SCL=1;
	_nop_();
	SDA=1;
	_nop_();
}

void i2c_ack(void)
{
	SCL=0;
	_nop_();
	SDA=0;
	_nop_();
	SCL=1;
	_nop_();
}

void i2c_n_ack(void)
{
	SCL=0;
	_nop_();
	SDA=1;
	_nop_();
	SCL=1;
	_nop_();
}

bit i2c_send_byte(unsigned char Byte)
{
	unsigned char i;		// Variable to be used in for loop
	
	for(i=0;i<8;i++)		// Repeat for every bit
	{
		SCL=0;
		_nop_();
		SDA=(((Byte<<i)&0x80)?1:0);  // Place data bit value on SDA pin depending on 0 or 1 bit
		_nop_();
		SCL=1;		// Toggle SCL pin so that slave can latch data bit
		_nop_();
  }
		
	// Get ACK from slave
	SCL=0;
  SDA=1;
  _nop_();
  SCL=1;
  _nop_();

	return SDA;
}

unsigned char i2c_read_byte(void)
{
	unsigned char i, d, RxData = 0;
	for(i=0;i<8;i++)
	{
		SCL=0;
		SDA=1;
		_nop_();
		SCL=1;
		_nop_();
		d = SDA;					    // Capture Received Bit
		RxData = RxData|(d<<(7-i));   	// Copy it in RxData
		_nop_();
	}
	return RxData;						// Return received byte
}
#endif