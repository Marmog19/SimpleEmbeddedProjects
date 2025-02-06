#include <main.h>


int main(void){
	GPIO_init();
	PWM_Init();

    /* Loop forever */
	while(1){}
}

void GPIO_init(void){
	//Enable Clock Peripherals (GPIOB)
	RCC->AHB1ENR |= (1<<1);
	//Enable Timer 2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/// GPIOB Alternate Function
	GPIOB->MODER |= (2<<LED_RED*2) | (2<<LED_GREEN*2) | (2<<LED_BLUE*2);
	GPIOB->AFR[1] |= (1<<0) | (1<<4) | (1<<8);
}
