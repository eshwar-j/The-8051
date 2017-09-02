#ifndef __connections_h
#define __connections_h

//LCD connections 4-bit

// rw assumed grounded
sbit rs = P2^0;                                                              
sbit en = P2^1;
sbit D4 = P2^2;
sbit D5 = P2^3;
sbit D6 = P2^4;
sbit D7 = P2^5;

// 7 seg driver

sbit B0=P2^0;
sbit B1=P2^1;
sbit B2=P2^2;
sbit B3=P2^3;

//keypad connections

sbit R1 = P1^0;
sbit R2 = P1^1;
sbit R3 = P1^2;
sbit R4 = P1^3;
sbit C1 = P1^4;
sbit C2 = P1^5;
sbit C3 = P1^6;
sbit C4 = P1^7;

//I2C connections

sbit SDA = P2^0;		// Serial Data
sbit SCL = P2^1;		// Serial Clock

//ADC connections

#define adc in P1
#define digital_out P2

sbit s1=P3^0;		// ADC channel select bits
sbit s2=P3^1;
sbit s3=P3^2;
sbit ale=P3^3;
sbit soc=P3^4;
sbit eoc=P3^5;
sbit oe=P3^6;
sbit adc_clk=P3^7;
#endif