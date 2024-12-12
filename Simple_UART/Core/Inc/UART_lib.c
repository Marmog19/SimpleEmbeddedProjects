#include "UART_lib.h"

void UART_Init(void) {
	uint16_t uartdiv = SystemCoreClock / 115200;

	RCC->APB1ENR |= (1<<17); // Clock Enable

	USART2->CR1 |= USART_CR1_UE; // UART Enable
	USART2->CR1 &= ~USART_CR1_M; // 8 bit word length
	USART2->CR2 &= ~USART_CR2_STOP_0; // 1 stop bit
	USART2->BRR = uartdiv;// Baud rate 115200

	USART2->CR1 |= USART_CR1_TE; // Transmission Enable
	USART2->CR1 |= USART_CR1_RE; // Receiver enable
}

void UART_read(void) {
}

void UART_send(uint8_t out) {
	while (!(USART2->SR & USART_SR_TC)); // wait until transmission is complete
	USART2->DR = out; // write
}
