/**
  ******************************************************************************
  * @file    TI_Board.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    30-August-2012
  * @brief   TI Board Utility
	* Note(s):  Alfred Lohmann
	*        	  HAW-Hamburg
	*          	Labor für technische Informatik
	*          	Berliner Tor  7
	*          	D-20099 Hamburg
	* 					version V1.0
	*         	adapted to the HAW TI-Bord
	* Date:   	18.07.2013
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 HAW-Hamburg</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
/* Here are the definition of the ... */
#include "main.h"
#include "usart.h"
#include "TI_Board_IO.h"
#include "tft.h"
	


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;
static __IO uint32_t uptime = 0;
/* Private function prototypes -----------------------------------------------*/
  /**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 1 ms.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
	uptime++;
}

uint32_t get_uptime(void){

		return uptime;
}


/**
  * @brief  Initializes the TI-Board
  * @param  None
  * @retval None
  */
void Init_TI_Board(void){
  
  Init_System_Clock();
  Init_IO();
	Init_SPI();
  USART1_Buffer_Init();                          /* init RX / TX buffers             */
  USART1_Init();
  TFT_Init();
  Delay(1);  
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
