/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 30/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/

#include <REGX51.H>

sbit SDA=P2^0;
sbit SCL=P2^1;
 
void i2c_init()
{
	SDA = 1;
	SCL = 1;
}
 
void i2c_start()
{
	SDA = 0;
	SCL = 1;
}
 
void i2c_repeated_start()
{
	SDA = 1;
	SCL = 1;
	SDA = 0;
	SCL = 0;
}
 
void i2c_stop()
{
	SCL = 0;
	SDA = 0;
	SCL = 1;
	SDA = 1;
}
 
void i2c_ack()
{
	SDA = 0;
	SCL = 1;
	SCL = 0;
	SDA = 1;
}
 
void i2c_n_ack()
{
	SDA = 1;
	SCL = 1;
	SCL = 0;
	SDA = 1;
}
 
unsigned char i2c_send(unsigned char Data)
{
	 unsigned char i, ack_bit;
	 for (i = 0; i < 8; i++) {
		if ((Data & 0x80) == 0)
			SDA = 0;
		else
			SDA = 1;
		SCL = 1;
	 	SCL = 0;
		Data<<=1;
	 }
	 SDA = 1;
	 SCL = 1;
	 ack_bit = SDA;
	 SCL = 0;
	 return ack_bit;
}
 
unsigned char i2c_read()
{
	unsigned char i, Data=0;
	for (i = 0; i < 8; i++) {
		SCL = 1;
		if(SDA)
			Data |=1;
		if(i<7)
			Data<<=1;
		SCL = 0;
	}
	return Data;
}

void main()
{
		/* Init i2c ports first */
	i2c_init();
	/* Send start condition */
	i2c_start();
	/* Send slave address */
	ack = i2c_send(0x20);
	/*
	 * ack == 1 => NAK
	 * ack == 0 => ACK
	 */
	ack = i2c_send(0x07);
	/* Send another data */
	ack = i2c_send(0x10);
	/* Send stop condition */
	i2c_stop();
	while(1);

}