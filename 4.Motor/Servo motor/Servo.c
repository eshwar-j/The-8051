/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 03/05/2017
 * Note(s): Servo.c
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#include<stdio.h>
#include <intrins.h>

sbit motor_pin = P2^0;

void delay(unsigned int ms)
{
  unsigned long int us = ms*1000;
	while(us--)
	{
    _nop_();
  }		
}

void delay_servo(unsigned int us)
{
	while(us--)
	{
    _nop_();
  }		
}

void main()
{
  motor_pin = 0;
while(1)
 {
	 motor_pin = 1;				//Turn to 0 degree
   delay_servo(50);				
   motor_pin = 0;
	 
   delay(1000);
	 
   motor_pin=1;					//Turn to 90 degree
	 delay_servo(82);
   motor_pin=0;
   delay(1000);
	 
   motor_pin=1;					//Turn to 180 degree
   delay_servo(110);
   motor_pin=0;
	 
   delay(1000);
 }
}