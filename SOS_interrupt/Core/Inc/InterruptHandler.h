#ifndef __INC_INTERRUPTHANDLER_H_
#define __INC_INTERRUPTHANDLER_H_

#include <stm32f4xx.h>


// declare flag variable (extern it)
extern volatile unsigned char led_on;

// Initializes Interrupts
void InterruptInit(void);


// Whenever the button is pressed turn ON / OFF the signal
// using: flag ^= 1 (exclusive OR / XOR)
// main loop works only when flag is true

// Handler name in the startup file
void EXTI4_IRQHandler(void);

#endif /* __INC_INTERRUPTHANDLER_H_ */
