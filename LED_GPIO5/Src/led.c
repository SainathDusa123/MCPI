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

	LED_GPIO->OTYPER |= BV(led_pin);

	LED_GPIO->OSPEEDR &= ~(BV(led_pin*2+1) | BV(led_pin*2));

	LED_GPIO->PUPDR &= ~BV(led_pin*2+1);
	LED_GPIO->PUPDR |= BV(led_pin*2);

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

//uint8_t next_state(uint8_t led_pin)
//{
//	switch(led_pin)
//	{
//		case 12:   led_toggle(LED_GREEN);
//					led_toggle(LED_ORANGE);
//					DelayMs(3000);
//					led_pin = LED_ORANGE;
//						break;
//		case 13:   led_toggle(LED_ORANGE);
//					led_toggle(LED_RED);
//					DelayMs(1000);
//					led_pin = LED_RED;
//						break;
//		case 14:   led_toggle(LED_RED);
//						led_toggle(LED_GREEN);
//						DelayMs(3000);
//					led_pin = LED_GREEN;
//						break;
//	}
//
//	return led_pin;
//}
//uint8_t curr_state(uint8_t led_pin)
//{
//		if(led_pin == 12)
//			return LED_GREEN;
//		else if(led_pin == 13)
//			return LED_ORANGE;
//		else if(led_pin == 14)
//			return LED_RED;
//}




