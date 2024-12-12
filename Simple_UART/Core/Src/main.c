#include <stdint.h>
#include <stdio.h>
#include <stm32f4xx.h>
#include "UART_lib.h"

void GPIO_init(void);

int main(void){
	GPIO_init();
	UART_Init();


	char rxb = '\0';

	while(1){
		// Wait for a byte of data to arrive.
	    while( !( USART2->SR & USART_SR_RXNE ) ) {};
	    rxb = USART2->DR;

	    printf("RX: %c\r\n", rxb); // print the character received
	}
}

void GPIO_init(void){
	//Enable Clock Peripherals (GPIOA)
	RCC->AHB1ENR |= (1<<0);


	// UART TX
    //Set GPIOA PIN 2 and 3 as Alternate function (MODER = 10)
	GPIOA->MODER |= (2<<4) | (2<<6);
	GPIOA->OTYPER &= ~((1<<2) | (1<<3));
	GPIOA->OSPEEDR |= (2<<4) | (2<<6);  // Fast Output Speed
	GPIOA->AFR[0] |= (7 << 8) | (7<<12); // UART 2 Alt funct (AF7)
}

// Override the 'write' clib method to implement 'printf' over UART.
int _write(int handle, char* data, int size) {
  int count = size;

  while( count-- ) {
	  while(!(USART2->SR & USART_SR_TXE)) {};
	  USART2->DR = *data++;
  }
  return size;
}
