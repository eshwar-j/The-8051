/*----------------------------------------------------------------------------
 * Author : Eshwar Jorvekar
 * Date	  : 14/05/2017
 * Note(s): file is a part of glcd.h
 *----------------------------------------------------------------------------*/
 
#ifndef __symbols_h
#define __symbols_h

code unsigned char battery[]={0x00, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x44, 0x38};
code unsigned char signal[]={0x00, 0x60, 0x00, 0x70, 0x00, 0x7C, 0x00, 0x7E};
code unsigned char level[]={0x00, 0x5E, 0x52, 0x7E, 0x00, 0x7E, 0x42, 0x7E};
code unsigned char percent[]={0x00, 0x04, 0x4A, 0x24, 0x18, 0x24, 0x52, 0x20};
#endif