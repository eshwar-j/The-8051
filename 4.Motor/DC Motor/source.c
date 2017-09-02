/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 03/05/2017
 * Note(s): 

DC Motor control

	pin 1				pin2				action
	
		0						0					stop
		0						1					clockwise
		1						0					anticlockwise
		1						1					stop
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include"softdelay.h"

sbit motor_pin_1 = P2^0;
sbit motor_pin_2 = P2^1;

void clockwise()
{
	 motor_pin_1 = 0;
	 motor_pin_2 = 1; //Rotates Motor Clockwise
}

void anticlockwise()
{
	 motor_pin_1 = 1;
	 motor_pin_2 = 0; //Rotates Motor Anticlockwise
}

void stop()
{
	 motor_pin_1 = 0;
	 motor_pin_2 = 0;
}
		
void main()
{
 while(1)
 {
clockwise();
delay_sec(5);
stop();
delay_sec(5);
anticlockwise();
delay_sec(5);
stop();
delay_sec(5);
 }
}