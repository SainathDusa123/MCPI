/*
 * switch.h
 *
 *  Created on: Mar 18, 2026
 *      Author: sainath
 */

#ifndef SWITCH_H_
#define SWITCH_H_
#include<led.h>

#define SWITCH_CLK_EN  0
#define SWITCH_IO GPIOA
#define SWITCH_PIN 0

void switch_init(uint8_t pin);
uint8_t switch_status(uint8_t pin);

#endif /* SWITCH_H_ */
