/*Interrupt arranged according to 8051 interrupt system*/

void enable_interrupts()
{
	EA=1;					//Enable global interrupts
//	EX0=1;					//Enable ext int 0 pin
	ET0=1;					//Enable (attach) Timer0 Interrupt	PT0=1; High priority for timer 0
//	EX1=1;					//Enable ext int 1 pin
// 	ET1=1;					//Enable (attach) Timer1 Interrupt
//	ES=1;					//Enable serial interrupt
}

void int0_isr() interrupt 0		// INTR0
{}

void timer0_isr() interrupt 1	//TIMER0
{
 adc_clk=~adc_clk;
}

void int1_isr() interrupt 2		//INTR1
{}

void timer1_isr() interrupt 3	//TIMER1
{}

void serial_rx_isr() interrupt 4 //serial RX
{}

void serial_tx_isr() interrupt 5 //serial TX
{}