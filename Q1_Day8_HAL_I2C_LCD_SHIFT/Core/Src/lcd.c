							/*
 * lcd.c
 *
 *  Created on: 21-Mar-2026
 *      Author: sunbeam
 */

#include "lcd.h"

extern I2C_HandleTypeDef hi2c1;

void lcd_init(void)
{
	// LCD initialization sequence
	HAL_Delay(20);
	lcd_write_nibble(LCD_CMD, 0x03);
	HAL_Delay(5);
	lcd_write_nibble(LCD_CMD, 0x03);
	HAL_Delay(1);
	lcd_write_nibble(LCD_CMD, 0x03);
	HAL_Delay(1);
	lcd_write_nibble(LCD_CMD, 0x02);
	HAL_Delay(1);

	// LCD initization commands
	lcd_write_byte(LCD_CMD, FUNCTION_SET);
	lcd_write_byte(LCD_CMD, DISPLAY_ON_OFF_CONTROL);
	lcd_write_byte(LCD_CMD, ENTRY_MODE_SET);
	lcd_write_byte(LCD_CMD, LCD_CLEAR);
	HAL_Delay(20);
}

void lcd_write_nibble(uint8_t rs, uint8_t val)
{

	uint8_t rs_flag = (rs == LCD_DATA)? BV(LCD_RS_Pos) : 0;

	uint8_t data = (val << LCD_DB4_Pos) | rs_flag | BV(LCD_BL_Pos) | BV(LCD_EN_Pos);
	HAL_I2C_Master_Transmit(&hi2c1, LCD_SLAVE_ADDR, &data, 1, HAL_MAX_DELAY);

	HAL_Delay(1);

	data = (val << LCD_DB4_Pos) | rs_flag | BV(LCD_BL_Pos);
	HAL_I2C_Master_Transmit(&hi2c1, LCD_SLAVE_ADDR, &data, 1, HAL_MAX_DELAY);
}

void lcd_write_byte(uint8_t rs, uint8_t val)
{
	uint8_t high = val >> 4, low = val & 0x0F;
	lcd_write_nibble(rs, high);
	lcd_write_nibble(rs, low);
	HAL_Delay(3);
}

void lcd_puts(uint8_t line, char str[])
{

	lcd_write_byte(LCD_CMD, line);

	for(int i = 0 ; str[i] != '\0' ; i++)
		lcd_write_byte(LCD_DATA, str[i]);
}

/*void lcd_shift_display(void)
{

	 	lcd_write_byte(LCD_CMD, DISPLAY_LSHIFT);
	 	//lcd_write_byte(LCD_CMD, DISPLAY_RSHIFT);
		lcd_puts(LCD_LINE1, "Dussa Sainath Ramulu");

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);


}
*/
