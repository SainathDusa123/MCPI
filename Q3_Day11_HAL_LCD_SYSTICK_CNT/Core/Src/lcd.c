/*
 * lcd.c
 *
 *  Created on: Mar 28, 2026
 *      Author: sainath
 */


#include<lcd.h>


extern I2C_HandleTypeDef hi2c1;

void lcd_init()
{
	HAL_Delay(20);
	lcd_write_byte(LCD_CMD, 0x03);
	HAL_Delay(5);
	lcd_write_byte(LCD_CMD, 0x03);
	HAL_Delay(1);
	lcd_write_byte(LCD_CMD, 0x03);
	HAL_Delay(1);
	lcd_write_byte(LCD_CMD, 0x02);

	lcd_write_byte(LCD_CMD,FUNCTION_SET);
	lcd_write_byte(LCD_CMD,DISPLAY_ON);
	lcd_write_byte(LCD_CMD,ENTRY_MODE);
	lcd_write_byte(LCD_CMD,CLEAR_DISPLAY);
	HAL_Delay(2);

}

void lcd_write_nibble(uint8_t rs, uint8_t value )
{
	uint8_t rsflag = (rs == LCD_DATA) ? 1 : 0;

	uint8_t data = (value << D4) | rsflag | BV(EN) | BV(BL);

	HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS, &data, 1, HAL_MAX_DELAY);
	HAL_Delay(1);
	data = (value << D4) | rsflag | BV(BL);
	HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS, &data, 1, HAL_MAX_DELAY);

	HAL_Delay(1);

}

void lcd_write_byte(uint8_t rs, uint8_t val)
{
		uint8_t high = (val >> 4);
		uint8_t low = (val & 0x0F);
		lcd_write_nibble(rs, high);
		lcd_write_nibble(rs, low);
		HAL_Delay(2);
}

void lcd_put(uint8_t line,  char *count)
{

		    lcd_write_byte(LCD_CMD, line);

		    while(*count)
		    {
		        lcd_write_byte(LCD_DATA, *count++);
		    }


}
