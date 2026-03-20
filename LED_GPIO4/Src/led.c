/*
 * led.c
 *
 *  Created on: Mar 18, 2026
 *      Author: sainath
 */



#include<led.h>


void led_init(uint8_t led_pin)
{
	RCC->AHB1ENR |= BV(GPIO_CLK_EN);

	LED_GPIO->MODER &= ~BV(led_pin*2+1);
	LED_GPIO->MODER |= BV(led_pin*2);

	LED_GPIO->OTYPER &= ~BV(led_pin);

	LED_GPIO->OSPEEDR &= ~(BV(led_pin*2+1) | BV(led_pin*2));

	LED_GPIO->PUPDR &= ~(BV(led_pin*2+1) | BV(led_pin*2));

}

void led_on(uint8_t led_pin)
{
	LED_GPIO->ODR |= BV(led_pin);
}

void led_off(uint8_t led_pin)
{
	LED_GPIO->ODR &= ~BV(led_pin);
}

void led_toggle(uint8_t led_pin)
{
	LED_GPIO->ODR ^= BV(led_pin);
}


