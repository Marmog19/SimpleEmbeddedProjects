#include "PWM_lib.h"

void PWM_Init(void) {
	// Output mode
	TIM2->CCMR1 &= ~(3<<0); // channel 1
	TIM2->CCMR1 &= ~(3<<8); // channel 2
	TIM2->CCMR2 &= ~(3<<0); // channel 3

	// Polarity (channel starts HIGH)
	// 0 at reset

	// Enable PWM mode 1
	TIM2->CCMR1 |= (6<<4);
	TIM2->CCMR1 |= (6<<12);
	TIM2->CCMR2 |= (6<<4);

	// Prescaler
	TIM2->PSC = (SystemCoreClock / 1000)-1; // runs the counter at 1kHz

	// Period (max count)
	TIM2->ARR = PERIOD;

	// Duty cycle (pulse width)
	TIM2->CCR1 = 999; // Blue
	TIM2->CCR2 = 0; // Green
	TIM2->CCR3 = 999; // Red

	// Preload
	TIM2->CCMR1 |= (1<<3);
	TIM2->CCMR1 |= (1<<11);
	TIM2->CCMR2 |= (1<<3);
	TIM2->CR1 |= (1<<7); // Enables preload

	//Counting mode (Upcounting and center-aligned)
	// 0 at reset

	// Enable
	TIM2->CCER |= (1<<0);
	TIM2->CCER |= (1<<4);
	TIM2->CCER |= (1<<8);
	TIM2->CR1 |= (1<<0);
}
