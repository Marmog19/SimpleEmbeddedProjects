#ifndef __MAIN_H
#define __MAIN_H

#include <stdint.h>
#include <stm32f4xx.h>
#include <SysTickDelay.h>
#include <InterruptHandler.h>


void GPIO_init(void);
void SosSignal(void);

#endif /* __MAIN_H */
