/*
 * led.h
 *
 *  Created on: Mar 18, 2026
 *      Author: sainath
 */

#ifndef LED_H_
#define LED_H_

#include<stm32f407xx.h>
#define LED_GPIO GPIOD
#define GPIO_CLK_EN 3
#define BV(n) (1<<(n))
#define LED_RED 14
#define LED_GREEN 12
#define LED_BLUE 15
#define LED_ORANGE 13

void led_init(uint8_t led_pin);
void led_on(uint8_t led_pin);
void led_off(uint8_t led_pin);
void led_toggle(uint8_t led_pin);

#endif /* LED_H_ */
