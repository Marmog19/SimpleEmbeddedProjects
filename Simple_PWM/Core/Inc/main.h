#ifndef __MAIN_H
#define __MAIN_H

#include <stdint.h>
#include <stm32f4xx.h>

// GPIOB
#define LED_RED 10 // channel 3
#define LED_GREEN 9 // channel 2
#define LED_BLUE 8 // channel 1

// Timer Number
#define TIM_LED 2


void GPIO_init(void);

#endif /* __MAIN_H */
