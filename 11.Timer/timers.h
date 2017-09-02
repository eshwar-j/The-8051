
/*Timer functions

init_timer(timer no. , mode,TH value, TL value);
start_timer(timer no.); 
*/

void int0_isr() interrupt 0
{
buzzer0=1;delay(50);buzzer0=0;
}

void timer0_isr() interrupt 1
{
buzzer1=1;delay(50);buzzer1=0;
}

void int1_isr() interrupt 2
{
buzzer2=1;delay(50);buzzer2=0;
}

void timer1_isr() interrupt 3
{
buzzer3=1;delay(50);buzzer3=0;
}

void serial_rx_isr() interrupt 4
{
buzzer4=1;delay(50);buzzer4=0;
}

void serial_tx_isr() interrupt 5
{
buzzer5=1;delay(50);buzzer5=0;
}

void init_timer(unsigned int timer,unsigned int mode,unsigned char hi,unsigned char lo)
{
	EA=1;					//Enable global interrupts
	EX0=1;					//Enable ext int 0 pin
	ET0=1;					//Enable (attach) Timer0 Interrupt	PT0=1; High priority for timer 0
	EX1=1;					//Enable ext int 1 pin
 	ET1=1;					//Enable (attach) Timer1 Interrupt
	ES=1;					//Enable serial interrupt
if(timer==0)
{
TH0=hi;TL0=lo;
switch(mode)
	{
	case 0:TMOD|=0x00;break;
	case 1:TMOD|=0x01;break;
	case 2:TMOD|=0x02;break;
	case 3:TMOD|=0x03;break;
	}
}
if(timer==1)
{
TH1=hi;TL1=lo;
switch(mode)
	{
	case 0:TMOD|=0x00;break;
	case 1:TMOD|=0x10;break;
	case 2:TMOD|=0x20;break;
	case 3:TMOD|=0x30;break;
	}
}
}

void start_timer(unsigned int t)
{
if(t==0)TR0=1;
if(t==1)TR1=1;
}

void stop_timer(unsigned int t)
{
if(t==0)TR0=0;
if(t==1)TR1=0;
}