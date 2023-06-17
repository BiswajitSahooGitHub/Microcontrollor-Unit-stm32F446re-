/* Application: Block LED On-Button Press
 * LED - PA5
 * Button - PC13
 * PC13 is always on High-State
 */

#include"main.h"
void delay(int T)
{
	int i;
	while(T--)
	{

		for(i=0;i<500;i++);
	}
}
void toggle_pinon()
{
	GPIOA->ODR |= 0x20;

}
void toggle_pinoff()
{
	GPIOA->ODR &= ~(0x20);

}
int main(){
	RCC->AHB1ENR |= 0x5;
	GPIOA->MODER |= 0x400;
	GPIOC->MODER |= 0x0000;
	while(1){
		int a=(GPIOC->IDR |=0x0000);
		if(a==0){
			toggle_pinon();
			delay(100);
		}
		else{
			toggle_pinoff();
			delay(100);
		}
	}
}
