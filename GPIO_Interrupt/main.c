#include "main.h"
#include <stm32f4xx.h>
void EXTI5_10_IRQHandler(void)  //Request Handler
{
	GPIOA->ODR ^=0x20;   //ISR Functionality
	for(int i=0; i<3000; i++);  //Delay
	EXTI->PR |=0x2000;  //Return back from ISR to Main program
}


int main()
{
	__disable_irq();  //Disable the IRQ
	RCC->AHB1ENR |=0x5;  //Enable clock for PA & PC
	GPIOA->MODER |=0X400;  //Set output for PA
	SYSCFG->EXTICR[3] |=0X20;  //Enable SYSCFG for Trigger the interrupt
	EXTI->IMR |=0X2000;  //Make mask in set to 1 of corresponding IRQ - PIN
	EXTI->FTSR |=0X2000;  //Trigger the interrupt on Falling edge
	NVIC_EnableIRQ(EXTI15_10_IRQn);  //Generate IRQ
	__enable_irq();  //Enable the Request line
	while(1);
}
