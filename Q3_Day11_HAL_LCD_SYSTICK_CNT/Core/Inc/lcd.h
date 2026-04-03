/*
 * lcd.h
 *
 *  Created on: Mar 28, 2026
 *      Author: sainath
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
#include<stm32f407xx.h>
#include<string.h>
#include<stdio.h>
#include<main.h>

#define BV(n) 1<<(n)

#define SLAVE_ADDRESS (0x27 <<1)
#define FUNCTION_SET  0x28
#define ENTRY_MODE	  0x06
#define DISPLAY_ON	  0x0C
//#define BUSY_FLAG 	  0x80
#define CLEAR_DISPLAY 0x01
#define LCD_LINE1     0x80
#define LCD_LINE2	  0xC0

#define LCD_CMD		  0
#define LCD_DATA 	  1

#define RS				0
#define RW				1
#define EN				2
#define BL				3
#define D4				4
#define D5				5
#define D6				6
#define D7				7

void lcd_write_nibble(uint8_t rs, uint8_t value );
void lcd_write_byte(uint8_t rs, uint8_t val);
void lcd_put(uint8_t line,  char *count);
void lcd_init();

#endif /* INC_LCD_H_ */
