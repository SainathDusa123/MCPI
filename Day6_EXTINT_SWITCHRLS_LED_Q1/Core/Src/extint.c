/*
 * extint.c
 *
 *  Created on: Mar 22, 2026
 *      Author: sainath
 */

#include<extint.h>
#include<stm32f407xx.h>

void extint_init(uint8_t pin)
{
	RCC->AHB1ENR |= BV(EXTINT_CLK_EN);

	EXTINT_IO->MODER &= ~(BV(pin*2+1) | BV(pin*2));

	EXTINT_IO->PUPDR &= ~(BV(pin*2) | BV(pin*2+1));

	SYSCFG->EXTICR[0] &= ~(BV(0)| BV(1)|BV(2)|BV(3));

	EXTI->IMR |= BV(0);

	EXTI->FTSR |= BV(0);

	NVIC_EnableIRQ(EXTI0_IRQn);

}

void EXTI0_IRQHandler()
{
	EXTI->PR |= BV(0);
	led_toggle(LED_ORANGE);
	DelayMs(100);
}
