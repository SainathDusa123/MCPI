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

	LED_GPIO->PUPDR &= ~(BV(led_pin*2+1)|BV(led_pin));

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

void led_change(uint8_t *led_pin)
{
	switch(*led_pin)
		{
			case 12:    led_toggle(LED_ORANGE);
						DelayMs(2000);
						led_toggle(LED_ORANGE);
						*led_pin = LED_ORANGE;
						break;
			case 13:    led_toggle(LED_RED);
						DelayMs(2000);
						led_toggle(LED_RED);
						*led_pin = LED_RED;
						break;

			case 14:   led_toggle(LED_BLUE);
					   DelayMs(2000);
					   led_toggle(LED_BLUE);
					   *led_pin = LED_BLUE;
					   break;
			case 15: 	led_toggle(LED_GREEN);
						DelayMs(2000);
						led_toggle(LED_GREEN);
						*led_pin = LED_GREEN;
						break;
		}
}




