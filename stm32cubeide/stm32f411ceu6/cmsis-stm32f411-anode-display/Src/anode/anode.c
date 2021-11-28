/*
 * anode.c
 *
 *  Created on: Nov 27, 2021
 *      Author: orlando_floresti
 */

#include "stm32f4xx.h"
#include "anode.h"

#define GPIOAEN		(1U<<0)

void anodeInitPort(){

	// Enable clock for GPIOC
	RCC->AHB1ENR |= GPIOAEN;

	// Mode GPIOA 0-15 as general output
	GPIOA->MODER |= (0x555555U << 0);
}

// Set a number in the display
void setDisplay(int number, int display) {

	// Clean port
	GPIOA->ODR = (0xfffU << 0);

	// Set number in display
	switch(number){
	case 0:
		// Set 0
		GPIOA->ODR = ~(0x3fU << 0);
		break;
	case 1:
		// Set 1
		GPIOA->ODR = ~(0x06U << 0);
		break;
	case 2:
		// Set 2
		GPIOA->ODR = ~(0x5bU << 0);
		break;
	case 3:
		// Set 3
		GPIOA->ODR = ~(0x4fU << 0);
		break;
	case 4:
		// Set 4
		GPIOA->ODR = ~(0x66U << 0);
		break;
	case 5:
		// Set 5
		GPIOA->ODR = ~(0x6dU << 0);
		break;
	case 6:
		// Set 6
		GPIOA->ODR = ~(0x7dU << 0);
		break;
	case 7:
		// Set 7
		GPIOA->ODR = ~(0x07U << 0);
		break;
	case 8:
		// Set 8
		GPIOA->ODR = ~(0x7fU << 0);
		break;
	case 9:
		// Set 9
		GPIOA->ODR = ~(0x6fU << 0);
		break;
	}

	// Enable display
	switch(display){
	case 1:
		GPIOA->BSRR = (1U << 24);
		break;
	case 2:
		GPIOA->BSRR = (1U << 25);
		break;
	case 3:
		GPIOA->BSRR = (1u << 26);
		break;
	case 4:
		GPIOA->BSRR = (1U << 27);
		break;
	}
}
