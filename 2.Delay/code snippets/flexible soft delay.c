/*code produces delay in ms XTAL=12Mhz*/

#include<reg51.h>
void msdelay(unsigned int time)  // Function for creating delay in milliseconds.
{
    unsigned i,j ;
    for(i=0;i<time/2;i++)    
    for(j=0;j<248;j++);
}
void main()
{
    while(1)
    {
     msdelay(900);  
    }
}