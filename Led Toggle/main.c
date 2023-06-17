

/* Application: Led_Toggle
 * GPIO: LED
 * Step1:
 * Step2:
 * Step3:
 * Author: Aparna Maharana
 */




#include "main.h"

void delay(int T)
{
	int i;
	while(T--)
	{
	for(i=0; i<4000; i++);
}
}

int main()

{
	RCC->AHB1ENR |= 0x1;
 	GPIOA->MODER |=0x400;

	while(1)
	{
    //GPIOA->ODR |= 0x20;
	GPIOA->BSRR |= 0x20;
	delay(100);
	//GPIOA ->ODR &= ~(0x20);
	GPIOA->BSRR |= ~(0x20);
	delay(100);
	}

}
