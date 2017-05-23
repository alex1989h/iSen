/**
  ******************************************************************************
  * @file    	main.c 
  * @author  	Alfred Lohmann
  *        	  HAW-Hamburg
  *          	Labor für technische Informatik
  *          	Berliner Tor  7
  *          	D-20099 Hamburg
  * @version V1.0
  * @date    23.05.2013
  * @brief   Main program body
  *******************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>
#include <string.h>
#include "TI_Lib.h"
#include "tft.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"


/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void initISR(void);

volatile int a=0;
volatile int b=0;
volatile int call=0;
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	int oldCall = 0;;
	int grad = 0;
  Init_TI_Board();
  printf("Hallo TI-Labor.\n\r");
	char s[20];
	
  TFT_cls();
  TFT_puts("Hallo TI-Labor");
  TFT_carriage_return();
  TFT_newline();
	initISR();
	while(1){
			TFT_gotoxy(1,2);
			sprintf(s,"Ticks: %i      \n",call);
			TFT_puts(s);
			
			grad = (360.0/1200.0)*call;
			TFT_gotoxy(1,3);
			sprintf(s,"Grad: %i      \n",grad);
			TFT_puts(s);
			oldCall = call;
	}
}

void initISR(void){
	////////////////////////////////////////////////////////////////////////////////
   //INIT INTERUPTS
   ////////////////////////////////////////////////////////////////////////////////
	
   RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; //Clock for Syscfg


   // Connect EXTI2 with Pin 2 of GPIO F (MASK0x5)
   SYSCFG->EXTICR[0] &= ~(0xf << (4*2)); //Remove old selection
   SYSCFG->EXTICR[0] |= 0x5 << (4*2); //Select Port F    
   EXTI->RTSR |= (1<<2); //select rising trigger for INT2    
   EXTI->FTSR |= (1<<2); //select falling trigger for INT2    
   EXTI->IMR |= (1<<2);  // Unmask Int2		

   // Connect EXTI3 with Pin 3 of GPIO F (MASK0x5)
   SYSCFG->EXTICR[0] &= ~(0xf << (4*3)); //Remove old selection
   SYSCFG->EXTICR[0] |= 0x5 << (4*3); //Select Port F    
   EXTI->RTSR |= (1<<3); //select rising trigger for INT3    
   EXTI->FTSR |= (1<<3); //select falling trigger for INT3
   EXTI->IMR |= (1<<3);  // Unmask INT3

   // Setup Interrupt Controller
   NVIC_SetPriorityGrouping(2); // Setup priorities and subpriorities

   NVIC_SetPriority(EXTI2_IRQn, 8); // INT2: Set Group Prio = 2, Subprio = 0
   NVIC_EnableIRQ(EXTI2_IRQn);      // Enable IRQ
	
   NVIC_SetPriority(EXTI3_IRQn, 8); // INT3: Set Group Prio = 2, Subprio = 0
   NVIC_EnableIRQ(EXTI3_IRQn);      // Enable IRQ
}

void EXTI2_IRQHandler(void){//A
	EXTI->PR = (1<<2); // Reset INT2
	if(a == 0 && b == 0){
		call++;
		a = 1;
	}else if(a == 1 && b == 1){
		call++;
		a = 0;
	}else if(a == 0 && b == 1){
		call--;
		a = 1;
	} else if( a == 1 && b == 0){
		call--;
		a = 0;
	}
}

void EXTI3_IRQHandler(void){//B
	EXTI->PR = (1<<3); // Reset INT3
	if(a == 1 && b == 0){
		call++;
		b = 1;
	}else if(a == 0 && b == 1){
		call++;
		b = 0;
	} else if( a == 0 && b ==0){
		call--;
		b = 1;
	} else if( a == 1 && b ==1){
		call--;
		b = 0;
	}
}


