/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void generate_interrupt()
{
	uint32_t * pSTIR = (uint32_t *);
	uint32_t * pISERO = (uint32_t *);

/* Enable IRQ3 Interrupt*/
		*pISERO |= (1<<3);

/* Generate an interrupt */
		*pSTIR =(3 & 0x1FF);
}

int main(void)
{
	printf("In thread mode: before interrupts \n");
	generate_interrupt();
	printf("In thread mode: after interrupts \n");
    /* Loop forever */
	for(;;);
}
