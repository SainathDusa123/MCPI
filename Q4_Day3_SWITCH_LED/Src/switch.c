/*
 * switch.c
 *
 *  Created on: Mar 18, 2026
 *      Author: sainath
 */

#include<switch.h>
#include<stm32f407xx.h>

void switch_init(uint8_t pin)
{
	RCC->AHB1ENR |= BV(SWITCH_CLK_EN);

	SWITCH_IO->MODER &= ~(BV(pin*2+1) | BV(pin*2));

	SWITCH_IO->OTYPER &= ~(BV(pin));

	SWITCH_IO->OSPEEDR |= (BV(pin*2+1));
	SWITCH_IO->OSPEEDR &= ~BV(pin*2);

	SWITCH_IO->PUPDR &= ~(BV(pin*2) | BV(pin*2+1));

}

uint8_t switch_status(uint8_t pin)
{
	return SWITCH_IO->IDR & BV(pin) ? 1 : 0 ;
}
