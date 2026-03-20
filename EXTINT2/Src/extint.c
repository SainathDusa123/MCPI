/*
 * extint.c
 *
 *  Created on: Mar 20, 2026
 *      Author: sainath
 */


#include<extint.h>
#include<led.h>
#include<extint.h>

volatile int flag =0 ;
void extint_init()
{
	RCC->AHB1ENR |= BV(EXT_CLK_EN);
	EXT_IO->MODER &= ~(BV(EXT_PIN*2+1)|BV(EXT_PIN*2));
	EXT_IO->PUPDR &= ~(BV(EXT_PIN*2+1)|BV(EXT_PIN*2));

	SYSCFG->EXTICR[0] &= ~(BV(0)|BV(1)|BV(2)|BV(3));

	EXTI->IMR |= BV(EXT_PIN);

	EXTI->RTSR |= BV(EXT_PIN);
	EXTI->FTSR |= BV(EXT_PIN);

	NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler()
{
	EXTI->PR |= BV(EXT_PIN);
	/*	 This ISR takes delay which is not prefereed for cpu optimization if any other interrupt came during execution delay there is some latency
	 to avoid we write function in main but using volatile key so compiler should not optimise the variable
	led_toggle(LED_RED);
	DelayMs(1000);
	led_toggle(LED_RED);
	*/

	flag = 1;
}
