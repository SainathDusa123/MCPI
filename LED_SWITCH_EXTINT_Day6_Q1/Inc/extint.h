/*
 * extint.h
 *
 *  Created on: Mar 22, 2026
 *      Author: sainath
 */

#ifndef EXTINT_H_
#define EXTINT_H_

#include <switch.h>

#define EXTINT_CLK_EN 0
#define EXTINT_PIN 0
#define EXTINT_IO GPIOA

void extint_init(uint8_t pin);
void EXTI0_IRQHandler();

#endif /* EXTINT_H_ */
