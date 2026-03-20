/*
 * led.h
 *
 *  Created on: Mar 20, 2026
 *      Author: sainath
 */

#ifndef LED_H_
#define LED_H_
#include<stm32f407xx.h>

#define LED_RED 12
#define LED_IO GPIOD
#define GPIO_CLK_EN 3
#define BV(n) (1<<(n))

void led_init(uint8_t led_pin);
void led_toggle(uint8_t led_pin);

#endif /* LED_H_ */
