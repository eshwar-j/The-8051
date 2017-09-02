/*Interrupt arranged according to 8051 interrupt system*/

void enable_interrupts()
{
	EA=1;					//Enable global interrupts
	EX0=1;					//Enable ext int 0 pin
	EX1=1;					//Enable ext int 1 pin
}

void int0_isr() interrupt 0		// INTR0
{
count_up();
}

void int1_isr() interrupt 2		//INTR1
{
count_down();
}
