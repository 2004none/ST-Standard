#include "stm32f10x.h"                  // Device header

void LED_Init(void){
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
		
		GPIO_InitTypeDef GPIO_InitStruct;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC,&GPIO_InitStruct);
		
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,(BitAction)1);
}
