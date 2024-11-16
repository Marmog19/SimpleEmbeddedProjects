#include <stdint.h>
#include <stm32f4xx.h>
#include <SysTickDelay.h>

void GPIO_init(void);

int main(void){
	GPIO_init();
	SysTick_Init();

    /* Loop forever */
	while(1){
		// check if the toggle (pin 9) is on
		if (GPIOA->IDR & (1 << 9)) {
			// check if the armed signals (buttons on pin 6 and 7) are not pressed (1)
			if ((GPIOA->IDR & (1 << 7)) || (GPIOA->IDR & (1 << 6))) {
				GPIOA->ODR |= (1<<4); // turns on LED
				SysTick_Delay10ms(1); // wait 10ms because of button bounce
			}  else {
				GPIOA->ODR &= ~(1<<4); // turns off LED
				SysTick_Delay10ms(1); // wait 10ms because of button bounce
			}
		} else {
			GPIOA->ODR &= ~(1<<4); // turns off LED
			SysTick_Delay10ms(1); // wait 10ms because of button bounce
		}
	}
}

void GPIO_init(void){
	//Enable Clock Peripherals (GPIOA)
	RCC->AHB1ENR |= (1<<0); //Enables GPIOA peripheral (bit 0)

	/// OUTPUT
	// LED
	//Set GPIOA, PIN 4 as Output (MODER[9:8] = 01)
	GPIOA->MODER &= ~(1<<9); // clear bit 9
	GPIOA->MODER |= (1<<8); // set bit 8
	GPIOA->OTYPER &= ~(1<<4); //Sets GPIOA, PIN 4 as push-pull
	GPIOA->ODR &= ~(1<<4); //Initializes GPIOA, PIN 4 as LOW

	///INPUT
	// Armed Toggle (ON/OFF)
	//Set GPIOA, PIN 9 as Input (MODER[19:18] = 00)
	GPIOA->MODER &= ~(1<<19); // clear bit 19
	GPIOA->MODER &= ~(1<<18); // clear bit 18
	//Set GPIOA, PIN 9 as Pull-up (negative logic) (PUPDR[19:18] = 01)
	GPIOA->PUPDR &= ~(1<<19); // clear bit 19
	GPIOA->PUPDR |= (1<<18); // set bit 18

	// Button 1
	//Set GPIOA, PIN 6 as Input (MODER[13:12] = 00)
	GPIOA->MODER &= ~(1<<13); // clear bit 13
	GPIOA->MODER &= ~(1<<12); // clear bit 12
	//Set GPIOA, PIN 6 as Pull-up (negative logic) (PUPDR[13:12] = 01)
	GPIOA->PUPDR &= ~(1<<13); // clear bit 13
	GPIOA->PUPDR |= (1<<12); // set bit 12

	// Button 2
	//Set GPIOA, PIN 7 as Input (MODER[15:14] = 00)
	GPIOA->MODER &= ~(1<<15); // clear bit 15
	GPIOA->MODER &= ~(1<<14); // clear bit 14
	//Set GPIOA, PIN 7 as Pull-up (negative logic) (PUPDR[15:14] = 01)
	GPIOA->PUPDR &= ~(1<<15); // clear bit 13
	GPIOA->PUPDR |= (1<<14); // set bit 12
}
