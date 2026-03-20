/*
 * led.c
 *
 *  Created on: Mar 20, 2026
 *      Author: sainath
 */


#include<led.h>
#include<stm32f407xx.h>

void led_init(uint8_t led_pin)
{
		RCC->AHB1ENR |= BV(GPIO_CLK_EN);

		LED_IO->MODER |= (BV(led_pin*2));
		LED_IO->MODER &= ~BV(led_pin*2+1);

		LED_IO->OTYPER &= ~BV(led_pin);
		LED_IO->OSPEEDR &= ~(BV(led_pin*2+1) | BV(led_pin*2));

		LED_IO->PUPDR &= ~(BV(led_pin*2+1) | BV(led_pin*2));
}

void led_toggle(uint8_t led_pin)
{
	LED_IO->ODR ^= BV(led_pin);
}
