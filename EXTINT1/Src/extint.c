/*
 * extint.c
 *
 *  Created on: Mar 20, 2026
 *      Author: sainath
 */


#include<switch.h>
#include<extint.h>
#include<stm32f407xx.h>

void extint_init()
{
	RCC->AHB1ENR |= BV(EXT_CLK_EN);

	SWITCH_IO->MODER &= ~(BV(SWITCH_PIN*2+1) | BV(SWITCH_PIN*2));

	//SWITCH_IO->OTYPER &= ~(BV(SWITCH_PIN*2+1) | BV(SWITCH_PIN*2));

	SWITCH_IO->PUPDR &= ~(BV(SWITCH_PIN*2+1) | BV(SWITCH_PIN*2));

	SYSCFG->EXTICR[0] &= ~(BV(0)| BV(1)| BV(2) | BV(3));

	EXTI->IMR |= BV(SWITCH_PIN);

	EXTI->RTSR |= BV(SWITCH_PIN);

	NVIC_EnableIRQ(EXTI0_IRQn);

}

void EXTI0_IRQHandler()
{
	EXTI->PR |= BV(SWITCH_PIN);
	led_toggle(LED_GREEN);
}
