
#ifndef __keypad_h
#define __keypad_h

#include<softdelay.h>

sbit C1 = P3^4;
sbit C2 = P3^5;

char Read_Keypad()
{
 C1=C2=1;		//columns to detect low
	
 if(C1==0){delay_ms(100);while(C1==0);return 'l';}
 if(C2==0){delay_ms(100);while(C2==0);return 'f';}

 return 0 ;
}
#endif