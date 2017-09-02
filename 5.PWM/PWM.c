/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : //
 * Note(s): work pending
 *----------------------------------------------------------------------------*/

#include< reg51.h>
#include"softdelay.h"
extern int count=0;
#include"interrupts.h"

sbit pwm_pin=P2^3;



void Pwm_Low()
{
pwm_pin=0;
TH0=0xFF;
TL0=0x47;
TR0=1; //Run Timer0
while(!TF0); //Wait for T0 Interrupt Flag
TF0=0; //Clear Interrupt Flag
TR0=0; //Stop Timer‐0
}
void Pwm_High()
{
TR0=1; //Run Timer0
while(!TF0); //Wait for T0 Interrupt Flag
TF0=0; //Clear Interrupt Flag
TR0=0; //Stop Timer‐0
Pwm_Low();
}

void main()
{
pwm_pin=0;
	enable_interrupts();

TMOD=0x01; //Timer‐0, As 16‐bit Timer.
while(1)
 {
	switch(count)
		{
		case 0:pwm_pin=1;TH0=0x00;TL0=0x00; Pwm_High();break; //0
		case 1:pwm_pin=1;TH0=0xFF;TL0=0xDA; Pwm_High();break; //20
		case 2:pwm_pin=1;TH0=0xFF;TL0=0xB5; Pwm_High();break; //40
		case 3:pwm_pin=1;TH0=0xFF;TL0=0x47; Pwm_High();break; //50
		case 4:pwm_pin=1;TH0=0xFE;TL0=0xD8; Pwm_High();break; //60
		case 5:pwm_pin=1;TH0=0xFE;TL0=0xB3; Pwm_High();break; //80
		case 6:pwm_pin=1;TH0=0xFC;TL0=0x65; Pwm_High();break; //500
		case 7:pwm_pin=1;TH0=0xFA;TL0=0x3C; Pwm_High();break; //800
		case 8:pwm_pin=1;TH0=0xF8;TL0=0xCC; Pwm_High();break; //1000
		}
 }
}