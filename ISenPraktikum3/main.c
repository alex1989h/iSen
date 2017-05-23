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
//I2C
#include "isen_i2c.h"
#include "isen_stm32f4xx_i2c.h"


/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{

    
  Init_TI_Board();
    
  printf("Hallo TI-Labor.\n\r");

  TFT_cls();
  TFT_puts("Hallo TI-Labor");
  TFT_carriage_return();
  TFT_newline();

  return 0;

}




