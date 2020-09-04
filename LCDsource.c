/*
 * File:   LCD.c
 * Author: Muhammed
 *
 * Created on September 4, 2020, 2:06 PM
 */

#include "lcd-library.h"

void LCD_Init()         //LCD initialize
{
    LCD_Port = 0;       //PORTB selected as Output 
    __delay_ms(15);     //15ms delay
    LCD_Command(0x02);  //Initializing for 4 bit mode
    LCD_Command(0x28);  //use 2 line and initialize 5*8 matrix in (4-bit mode)*/
	LCD_Command(0x01);  //clear display
    LCD_Command(0x0c);  //hide cursor
	LCD_Command(0x06);  //shift cursor to right
}

void LCD_Command(unsigned char cmd )
{
	ldata = (ldata & 0x0f) |(0xF0 & cmd);  /*Send higher nibble of command first to PORT*/ 
	RS = 0;  /*Command Register is selected i.e.RS=0*/ 
	EN = 1;  /*High-to-low pulse on Enable pin to latch data*/ 
	__delay_us(10);
	EN = 0;
	__delay_ms(1);
    ldata = (ldata & 0x0f) | (cmd<<4);  /*Send lower nibble of command to PORT */
	EN = 1;
	__delay_us(10);
	EN = 0;
	__delay_ms(3);
}

void LCD_Char(unsigned char dat)
{
	ldata = (ldata & 0x0f) | (0xF0 & dat);  /*Send higher nibble of data first to PORT*/
	RS = 1;  /*Data Register is selected*/
	EN = 1;  /*High-to-low pulse on Enable pin to latch data*/
	__delay_us(10);
	EN = 0;
	__delay_ms(1);
    ldata = (ldata & 0x0f) | (dat<<4);  /*Send lower nibble of data to PORT*/
	EN = 1;  /*High-to-low pulse on Enable pin to latch data*/
	__delay_us(10);
	EN = 0;
	__delay_ms(3);
}
void LCD_String(const char *msg)
{
	while((*msg)!=0)
	{		
	  LCD_Char(*msg);
	  msg++;	
    }
}

void LCD_String_xy(char row,char pos,const char *msg)
{
    char location=0;
    if(row<=1)
    {
        location=(0x80) | ((pos) & 0x0f);  /*Print message on 1st row and desired location*/
        LCD_Command(location);
    }
    else
    {
        location=(0xC0) | ((pos) & 0x0f);  /*Print message on 2nd row and desired location*/
        LCD_Command(location);    
    }  
    

    LCD_String(msg);

}
void LCD_Clear()
{
   	LCD_Command(0x01);  /*clear display screen*/
    __delay_ms(3);
}


