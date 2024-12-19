#include "InterruptHandler.h"


// define flag variable
volatile unsigned char led_on = 0;

void InterruptInit(void) {
	// Enable System Configuration
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	// EXTI listen to GPIOC (0010) pin 13 (EXTI3)
	SYSCFG->EXTICR[3] |= (2<<4);


	// 1. Configure the mask bits, enabling interrupts (EXTI_IMR)
	EXTI->IMR |= (1<<13);

	// 2. Configure the Trigger selection bits (EXTI_RTSR and EXTI_FTSR)
	EXTI->RTSR &= ~(1 << 13); // Disable the 'rising edge' trigger (button release)
	EXTI->FTSR |=  (1 << 13); 	// Enable the 'falling edge' trigger (pull-up: button press)

	// 3. Configure the enable and mask bits that control the NVIC IRQ channel
	NVIC_SetPriority(EXTI4_IRQn, 0x03); // priority = 3
	NVIC_EnableIRQ(EXTI4_IRQn);
}

void EXTI4_IRQHandler(void) {
	if (EXTI->PR & (1 << 13)) {
		// Clear the EXTI status flag (by writing 1)
		EXTI->PR |= (1 << 13);

		// Toggle the global 'led on' variable.
		led_on ^= 1; // alternatively: led_on = !led_on;
	}
}
