
/* UART FUNCTIONS

init_uart();
uart_tx_char('');
uart_rx_char();
uart_tx_string(""); transmit the ASCII string through UART.The string_ptr points to the first char of the string.
									And it is incremented each time to traverse till the end(NULL CHAR).
									Each time a char is sent to uart_tx_char() function to transmit it through UART
							 
uart_rx_string(); 1.This function is used to receive a ASCII string through UART
                    till the carriage_return/New_line
                  2.The string_ptr points to the begining of the string and each
                    time uart_rx_char() function is called to receive a char and copy
                    it into the buffer(STRING) and incrment string_ptr.
                  3.Once the carriage_return/New_line is encountered the loop
                    is breaked and the String is NULL terminated.
 
uart_tx_number(number without '');	This function is used to transmit a 5-digit integer(0-65535).
									ex: if the number is 12345 then 12345 is transmitted.
									if the number is 123 then 00123 is transmitted.
 
 
 ----------Take 1 by dividing by 10000 and add 0X30 to obtain the ASCII value,
|          then take the 4-digit remainder(2345).
|
| ---------Take 2 by dividing by 1000  and add 0X30 to obtain the ASCII value,
||         then take the 3-digit remainder(345)
||
|| --------Take 3 by dividing by 100   and add 0X30 to obtain the ASCII value,
|||        then take the 2-digit remainder(45).
|||
||| -------Take 4 by dividing by 10    and add 0X30 to obtain the ASCII value,
|||| ------Take 5 the remainder of 45  and add 0X30 to obtain the ASCII value,.
|||||
12345
*/

void init_uart()
{
      TMOD |=0x20; //Timer1 in Mode2.
      TH1=-3;    // 9600 Baud rate at 11.0592MHz
      SCON=0x50; // Asynchronous mode 8-bit data and 1-stop bit
      TR1=1;     //Turn ON the timer.
}


void uart_tx_char(char ch)
{
    SBUF=ch;       // Load the data to be transmitted
  while(TI==0);    // Wait till the data is trasmitted
     TI=0;         //Clear the flag for next cycle.
}

char uart_rx_char()
{
  while(RI==0);   // Wait till the data is received
     RI=0;        // Clear Receive Interrupt Flag for next cycle
  uart_tx_char(SBUF);     //Echo back the received char, comment this if echo not required
  return(SBUF);   // return the received char
}

void uart_tx_string(char *string_ptr)
 {
   while(*string_ptr)
      uart_tx_char(*string_ptr++);
 }
 
void uart_rx_string(char *string_ptr)
 {
     char ch;
     while(1)
       {
          ch=uart_rx_char();    //Receive a char
          uart_tx_char(ch);     //Echo back the received char, comment this if echo not required
 
         if((ch=='\r') || (ch=='\n')) //read till enter key is pressed
           {                          //once enter key is pressed
              *string_ptr=0;          //null terminate the string
                break;                //and break the loop
             }
         *string_ptr=ch;              //copy the char into string.
         string_ptr++;                //and increment the pointer
      }
 }
  
void uart_tx_number(unsigned int num)
{
 
       uart_tx_char((num/10000)+0x30);
       num=num%10000;
 
       uart_tx_char((num/1000)+0x30);
       num=num%1000;
 
       uart_tx_char((num/100)+0x30);
       num=num%100;
 
       uart_tx_char((num/10)+0x30);
 
       uart_tx_char((num%10)+0x30);
}
