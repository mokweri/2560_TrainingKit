/*
 * LiquidCrystal.h
 *
 * Created: 7/7/2021 20:51:56
 *  Author: Obed
 */ 


#ifndef LIQUIDCRYSTAL_H_
#define LIQUIDCRYSTAL_H_

#include <avr/io.h>
#include <inttypes.h>

//LCD Port
#define LCD_DDR  DDRA
#define LCD_PORT PORTA

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

#define LCD_RS 7
#define LCD_RW 6
#define LCD_EN 5
#define LCD_BL 4 // backlight

#define LCD_D7 0 //d7
#define LCD_D6 1 //d6
#define LCD_D5 2 //d5
#define LCD_D4 3 //d4

#define LCD_D3 0
#define LCD_D2 0
#define LCD_D1 0
#define LCD_D0 0


void lcd_init(void);
void lcd_clear();
void lcd_home();

void lcd_display_on();
void lcd_display_off();
void lcd_noBlink();
void lcd_blink();
void lcd_noCursor();
void lcd_cursor();
void lcd_scrollDisplayLeft();
void lcd_scrollDisplayRight();
void lcd_leftToRight();
void lcd_rightToLeft();
void lcd_autoscroll();
void lcd_noAutoscroll();

void lcd_setRowOffsets(int row1, int row2, int row3, int row4);
void lcd_createChar(uint8_t, uint8_t[]);
void lcd_setCursor(uint8_t, uint8_t);

uint8_t write(uint8_t);
void command(uint8_t);

void lcd_puts(char *string);


#endif /* LIQUIDCRYSTAL_H_ */