/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 15/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/

#ifndef __keypad_h
#define __keypad_h

#include"connections.h"
#include<softdelay.h>

char Read_Keypad()
{
 C1=C2=C3=C4=1;		//columns will be 1 as we have to detect low on column
	
 R1=0;R2=1;R3=1;R4=1;			//row 1 low for scan
 if(C1==0){delay_ms(100);while(C1==0);return '7';}
 if(C2==0){delay_ms(100);while(C2==0);return '8';}
 if(C3==0){delay_ms(100);while(C3==0);return '9';}
 if(C4==0){delay_ms(100);while(C4==0);return '/';}
 
 R1=1;R2=0;R3=1;R4=1;			//row 2 low for scan
 if(C1==0){delay_ms(100);while(C1==0);return '4';}
 if(C2==0){delay_ms(100);while(C2==0);return '5';}
 if(C3==0){delay_ms(100);while(C3==0);return '6';}
 if(C4==0){delay_ms(100);while(C4==0);return 'X';}

 R1=1;R2=1;R3=0;R4=1;			//row 1 low for scan
 if(C1==0){delay_ms(100);while(C1==0);return '1';}
 if(C2==0){delay_ms(100);while(C2==0);return '2';}
 if(C3==0){delay_ms(100);while(C3==0);return '3';}
 if(C4==0){delay_ms(100);while(C4==0);return '-';}
 
 R1=1;R2=1;R3=1;R4=0;			//row 1 low for scan
 if(C1==0){delay_ms(100);while(C1==0);return 'C';}
 if(C2==0){delay_ms(100);while(C2==0);return '0';}
 if(C3==0){delay_ms(100);while(C3==0);return '=';}
 if(C4==0){delay_ms(100);while(C4==0);return '+';}
 return 0 ;
}
#endif