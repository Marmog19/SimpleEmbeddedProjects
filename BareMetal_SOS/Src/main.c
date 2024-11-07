#include <stdint.h>
#include <stm32f4xx.h>

void GPIO_init(void);
void delay(int);
void SosSignal(void);

int main(void){
	GPIO_init();

    /* Loop forever */
	while(1){
		// To see if the button is pressed block the process in a do while loop
		do {
			GPIOA->ODR &= ~(1<<5); // turns off LED
		} while (GPIOC->IDR & (1 << 13));
		do {
			SosSignal();
		} while(GPIOC->IDR & (1 << 13));
	}
}

void GPIO_init(void){
	//Enable Clock Peripherals (GPIOA, GPIOC)
	RCC->AHB1ENR |= (1<<0); //Enables GPIOA peripheral (bit 0)
	RCC->AHB1ENR |= (1<<2); //Enables GPIOC peripheral (bit 2)

	delay(1); 	// allow time for clock to start

	/// GPIOA
    //Set GPIOA, PIN 5 as Output (MODER[11:10] = 01)
	GPIOA->MODER &= ~(1<<11); // clear bit 11
	GPIOA->MODER |= (1<<10);  // set bit 10

	// LED
	GPIOA->OTYPER &= ~(1<<5); //Sets GPIOA, PIN 5 as push-pull
	GPIOA->ODR |= (1<<5); //Initializes GPIOA, PIN 5 as HIGH

	/// Button
	//Set GPIOC, PIN 13 as Input (MODER[27:26] = 00)
	GPIOC->MODER &= ~(1<<27); // clear bit 27
	GPIOC->MODER &= ~(1<<26); // clear bit 26
}

// Pressing the button starts SOS (Green LED flashes SOS).
//    S: Toggle light 3 times with 1/2 sec gap between ON..1/2sec..OFF
//    O: Toggle light 3 times with 2 sec gap between ON..2sec..OFF
//    S: Toggle light 3 times with 1/2 sec gap between ON..1/2sec..OFF
//    5 second delay between SOS
void SosSignal(void) {
	// S
	GPIOA->ODR |= (1<<5); delay(250);
	GPIOA->ODR &= ~(1<<5); delay(250);
	GPIOA->ODR |= (1<<5); delay(250);
	GPIOA->ODR &= ~(1<<5); delay(250);
	GPIOA->ODR |= (1<<5); delay(250);
	GPIOA->ODR &= ~(1<<5); delay(250);

	// O
	GPIOA->ODR |= (1<<5); delay(1000);
	GPIOA->ODR &= ~(1<<5); delay(1000);
	GPIOA->ODR |= (1<<5); delay(1000);
	GPIOA->ODR &= ~(1<<5); delay(1000);
	GPIOA->ODR |= (1<<5); delay(1000);
	GPIOA->ODR &= ~(1<<5); delay(1000);

	// S
	GPIOA->ODR |= (1<<5); delay(250);
	GPIOA->ODR &= ~(1<<5); delay(250);
	GPIOA->ODR |= (1<<5); delay(250);
	GPIOA->ODR &= ~(1<<5); delay(250);
	GPIOA->ODR |= (1<<5); delay(250);
	GPIOA->ODR &= ~(1<<5); delay(250);

	// 5 sec pause
	delay(2500);
}

// 1000 = 2 seconds
void delay(int d){
	int i;
	for(; d>0 ;d--){
		for(i =0; i<2657;i++);
	}
}
