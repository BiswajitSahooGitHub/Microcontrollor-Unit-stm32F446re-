/*
 * Application : Diplay from 0 to 1 in 7 segment Display Common Anode using Register Programming
 * Step 1:Write the function for all 0 to 9
 * Step 2:call them in sequential from 0 to 9
 * Step 3: give some delay
 * Author : Deepak
 * Date : 19/04/23

 */

#include <stdint.h>
#include<stdio.h>

#if !defined(_SOFT_FP) && defined(_ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
void delay(int a)
{
	int i;
	while(a--)
	{
		for(i=0;i<3000;i++);
	}

}

int main(void)
{
    /* Loop forever */

	uint32_t *portcMODER =(uint32_t *)0x40020800;
	uint32_t *portcAHB1ENR =(uint32_t *)0x40023830;
	uint32_t *portcODR =(uint32_t *)0x40020814;
	uint32_t *portcIDR =(uint32_t *)0x40020810;

	uint32_t *portcPUPDR =(uint32_t *)0x4002080c;

	//Enable the peripheral clock for GPIOC

	*portcAHB1ENR |= 0x4;

	//ROW PCO to PC3 -->output

	*portcMODER |= 0x55;

	//Column PC4 to PC7 -->Input

	//*portcMODER &= 0x00000000;


	*portcPUPDR = 0x5500;


	while(1)
	{
		//Make R1 low
		*portcODR |= 0x0f;
		*portcODR &= ~(1<<0);

		if(!((*portcIDR)&(1<<4)))
		{
			delay(100);
			printf("1 Pressed \n");
		}
		if(!((*portcIDR)&(1<<5)))
		{
			delay(100);
			printf("2 Pressed \n");
		}
		if(!((*portcIDR)&(1<<6)))
		{
			delay(100);
			printf("3 Pressed \n");
		}
		if(!((*portcIDR)&(1<<7)))
		{
			delay(100);
			printf("A Pressed \n");
		}

		//Make R2 low
		*portcODR |= 0x0f;
		*portcODR &= ~(1<<1);

		if(!((*portcIDR)&(1<<4)))
		{
			delay(100);
			printf("4 Pressed \n");
		}
		if(!((*portcIDR)&(1<<5)))
		{
			delay(100);
			printf("5 Pressed \n");
		}
		if(!((*portcIDR)&(1<<6)))
		{
			delay(100);
			printf("6 Pressed \n");
		}
		if(!((*portcIDR)&(1<<7)))
		{
			delay(100);
			printf("B Pressed \n");
		}

		//Make R3 low
		*portcODR |= 0x0f;
		*portcODR &= ~(1<<2);

		if(!((*portcIDR)&(1<<4)))
		{
			delay(100);
			printf("7 Pressed \n");
		}
		if(!((*portcIDR)&(1<<5)))
		{
			delay(100);
			printf("8 Pressed \n");
		}
		if(!((*portcIDR)&(1<<6)))
		{
			delay(100);
			printf("9 Pressed \n");
		}
		if(!((*portcIDR)&(1<<7)))
		{
			delay(100);
			printf("C Pressed \n");
		}
		//Make R4 low
		*portcODR |= 0x0f;
		*portcODR &= ~(1<<3);

		if(!((*portcIDR)&(1<<4)))
		{
			delay(100);
			printf("* Pressed \n");
		}
		if(!((*portcIDR)&(1<<5)))
		{
			delay(100);
			printf("0 Pressed \n");
		}
		if(!((*portcIDR)&(1<<6)))
		{
			delay(100);
			printf("# Pressed \n");
		}
		if(!((*portcIDR)&(1<<7)))
		{
			delay(100);
			printf("D Pressed \n");
		}

	}
	for(;;);
}
