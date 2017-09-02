/*Interrupt arranged according to 8051 interrupt system*/

#ifndef __interrupts_h
#define __interrupts_h

#include"connections.h"
#include"softdelay.h"

void enable_interrupts()
{
	EA=1;					//Enable global interrupts
	EX0=1;				//Enable ext int 0 pin
	ET0=1;				//Enable (attach) Timer0 overflow Interrupt
	EX1=1;				//Enable ext int 1 pin
 	ET1=1;				//Enable (attach) Timer1 overflow Interrupt
	ES=1;					//Enable serial tx or rx indication interrupt
}

void int0_isr() interrupt 0		// INTR0
{
	buzzer0=1;delay_ms(50);buzzer0=0;
}

void timer0_isr() interrupt 1	//TIMER0
{
	buzzer1=1;delay_ms(50);buzzer1=0;
}

void int1_isr() interrupt 2		//INTR1
{
	buzzer2=1;delay_ms(50);buzzer2=0;
}

void timer1_isr() interrupt 3	//TIMER1
{
	buzzer3=1;delay_ms(50);buzzer3=0;
}

void serial_rx_isr() interrupt 4 //serial RX
{
	buzzer4=1;delay_ms(50);buzzer4=0;
}

void serial_tx_isr() interrupt 5 //serial TX
{
	buzzer5=1;delay_ms(50);buzzer5=0;
}
#endif