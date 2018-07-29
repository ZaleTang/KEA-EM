/*RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
【dev.env.】IAR7.80.4
【Target  】S9KEAZ128
【Crystal 】16.000Mhz
【busclock】40.000MHz
【pllclock】40.000MHz
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa*/


#include "include.h"

/*************************************************************************
*  函数名称：PIT_Init
*  功能说明：初始化中断定时器
*  函数返回：无
*  参数说明：u8Channel_No：PIT通道端口号
*           cn  ：定时器时间 单位ms
*  for example     PIT_Init(PIT_CHANNEL0,5);
*************************************************************************/
void PIT_Init(uint8_t u8Channel_No, uint32_t cn)
{  
    SIM->SCGC |= SIM_SCGC_PIT_MASK;     /*!< enable clock to PIT */
    
    PIT->MCR &= ~PIT_MCR_MDIS_MASK;    
    PIT->CHANNEL[u8Channel_No].LDVAL = cn*BUS_CLK_KHZ ;//u32loadvalue;   //初始化时间                                  
    PIT->CHANNEL[u8Channel_No].TCTRL |= PIT_TCTRL_TIE_MASK;  
    PIT->CHANNEL[u8Channel_No].TCTRL |= PIT_TCTRL_TEN_MASK;
    PIT->CHANNEL[u8Channel_No].TFLG  |= PIT_TFLG_TIF_MASK;
    if (u8Channel_No)
    {  
      NVIC_EnableIRQ(PIT_CH1_IRQn);             
    }
    else
    {  
      NVIC_EnableIRQ(PIT_CH0_IRQn);
    }
    
}


void TestPIT(void)
{   

  LED_Init();
  LED_Ctrl(LEDALL, LEDON);
  PIT_Init(PIT_CHANNEL0,5);//定时500MS
	//time_delay_ms(1000);
	LED_Ctrl(LEDALL, LEDOFF);
  while(1)
  {
  }
}


   


