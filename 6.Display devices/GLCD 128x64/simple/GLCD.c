/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : /05/2017
 * Note(s): reference code from github
 *----------------------------------------------------------------------------*/

#include<reg51.h>
#define GlcdDataBus  P2
sbit RS  = P1^0;
sbit RW  = P1^1;
sbit EN  = P1^2;
sbit CS1 = P1^3;
sbit CS2 = P1^4;

/* 5x7 Font including 1 space to display HELLO WORLD */


char H[]={0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00};
char E[]={0x7F, 0x49, 0x49, 0x49, 0x41, 0x00};
char L[]={0x7F, 0x40, 0x40, 0x40, 0x40, 0x00};
char O[]={0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00};

char W[]={0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00};
char R[]={0x7F, 0x09, 0x19, 0x29, 0x46, 0x00};
char D[]={0x7F, 0x41, 0x41, 0x22, 0x1C, 0x00};


/* local function to generate delay */
void delay(int cnt)
{
   int i;
    for(i=0;i<cnt;i++);
}


void Glcd_SelectPage0() // CS1=1, CS2=0
{
    CS1 = 1;
    CS2 = 0;
}

void Glcd_SelectPage1() // CS1=0, CS1=1
{
    CS1 = 0;
    CS2 = 1;
}

/* Function to send the command to LCD */
void Glcd_CmdWrite(char cmd)
{
    GlcdDataBus = cmd;   //Send the Command 
    RS = 0;              // Send LOW pulse on RS pin for selecting Command register
    RW = 0;              // Send LOW pulse on RW pin for Write operation
    EN = 1;              // Generate a High-to-low pulse on EN pin
    delay(100);
    EN = 0;

    delay(1000);
}

/* Function to send the data to LCD */
void Glcd_DataWrite(char dat)
{
    GlcdDataBus = dat;   //Send the data on DataBus
    RS = 1;              // Send HIGH pulse on RS pin for selecting data register
    RW = 0;              // Send LOW pulse on RW pin for Write operation
    EN = 1;              // Generate a High-to-low pulse on EN pin
    delay(100);
    EN = 0;

    delay(1000);
}

void Glcd_DisplayChar(char *ptr_array)
{
    int i;
    for(i=0;i<6;i++) // 5x7 font, 5 chars + 1 blankspace
        Glcd_DataWrite(ptr_array[i]);
}


int main()
{
    /* Select the Page0/Page1 and Turn on the GLCD */
    Glcd_SelectPage0();
    Glcd_CmdWrite(0x3f);
    Glcd_SelectPage1();
    Glcd_CmdWrite(0x3f);
    delay(100);

    /* Select the Page0/Page1 and Enable the GLCD */
    Glcd_SelectPage0();
    Glcd_CmdWrite(0xc0);
    Glcd_SelectPage1();
    Glcd_CmdWrite(0xc0);
    delay(100);

    Glcd_SelectPage0(); // Display HELLO on Page0, Line1
    Glcd_CmdWrite(0xb8);
    Glcd_DisplayChar(H);
    Glcd_DisplayChar(E);
    Glcd_DisplayChar(L);
    Glcd_DisplayChar(L);
    Glcd_DisplayChar(O);

    Glcd_SelectPage1(); // Display WORLD on Page1, Last line
    Glcd_CmdWrite(0xbF);
    Glcd_DisplayChar(W);
    Glcd_DisplayChar(O);
    Glcd_DisplayChar(R);
    Glcd_DisplayChar(L);
    Glcd_DisplayChar(D);

    while(1);
}