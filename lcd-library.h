/* 
 * File:   lcd-library.h
 * Author: Muhammed
 *
 * Created on September 4, 2020, 1:50 PM
 */


#include <xc.h>  //LCD_lib.h 

// Configuration bits:

#pragma config FOSC = XT        // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF         // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

//defining crystal frequance:

#define _XTAL_FREQ 4000000

//defining Pins and Port of LCD:

#define RS RB3  //RB3 pin is connected to RS pin of LCD
#define EN RB2  //RB2 pin is connected to EN pin of LCD
#define ldata PORTB  //PORTB is connected to LCD pins
#define LCD_Port TRISB  //TRISB will use to control which pin will send data


#define sil 1
#define BasaDon 2
#define Solayaz 4
#define Sagayaz 6
#define ImlecGizle 12
#define ImlecAltta 14
#define ImlecYanSon 15
#define ImlecGeri 16
#define KaydirSaga 24
#define KaydirSola 28
#define EkraniKapat 8
#define BirinciSatir 128
#define IkinciSatir 192
#define KarakUretAdres 64
#define CiftSatir 40
#define TekSatir 32


extern void MSdelay(unsigned int );       /*Generate delay in ms*/
extern void LCD_Init();                   /*Initialize LCD*/
extern void LCD_Command(unsigned char );  /*Send command to LCD*/
extern void LCD_Char(unsigned char x);    /*Send data to LCD*/
extern void LCD_String(const char *);     /*Display data string on LCD*/
extern void LCD_String_xy(char, char , const char *);
extern void LCD_Clear();                  /*Clear LCD Screen*/


