/*
 * extint.h
 *
 *  Created on: Mar 20, 2026
 *      Author: sainath
 */

#ifndef EXTINT_H_
#define EXTINT_H_

#define EXT_CLK_EN 0
#define EXT_IO GPIOA
#define EXT_PIN 0

void extint_init();
void EXTI0_IRQHandler();

#endif /* EXTINT_H_ */
