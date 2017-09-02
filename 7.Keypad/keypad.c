/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 15/05/2017
 * Note(s): 
 *----------------------------------------------------------------------------*/

#include <REGX51.H>

/*keypad connections*/
sbit R1=P1^0;
sbit R2=P1^1;
sbit R3=P1^2;
sbit R4=P1^3;
sbit C1=P1^4;
sbit C2=P1^5;
sbit C3=P1^6;
sbit C4=P1^7;
/*end keypad connections*/

void main()
{ 
 P2=0xff;
 P2=0x00;
while (1)
	{
C1=C2=C3=C4=1;
R1=R2=R3=R4=0;

R1=0;R2=1;R3=1;R4=1;	//row 1 scan
if(C1==0){while(C1==0);P2=0x5c;}		// display o
if(C2==0){while(C2==0);P2=0x6f;}		// display 9
if(C3==0){while(C3==0);P2=0x7f;}		// display 8
if(C4==0){while(C4==0);P2=0x07;}		// display 7

R1=1;R2=0;R3=1;R4=1;	//row 2 scan
if(C1==0){while(C1==0);P2=0x54;}		// display n
if(C2==0){while(C2==0);P2=0x7d;}		// display 6
if(C3==0){while(C3==0);P2=0x6d;}		// display 5
if(C4==0){while(C4==0);P2=0x66;}		// display 4 

R1=1;R2=1;R3=0;R4=1;	//row 3 scan
if(C1==0){while(C1==0);P2=0x40;}		// display - 
if(C2==0){while(C2==0);P2=0x4f;}		// display 3
if(C3==0){while(C3==0);P2=0x5b;}		// display 2
if(C4==0){while(C4==0);P2=0x06;}		// display 1

R1=1;R2=1;R3=1;R4=0;	//row 4 scan
if(C1==0){while(C1==0);P2=0x77;}		// display A
if(C2==0){while(C2==0);P2=0x48;}		// display =
if(C3==0){while(C3==0);P2=0x3f;}		// display 0
if(C4==0){while(C4==0);P2=0x50;}		// display r
	}
}