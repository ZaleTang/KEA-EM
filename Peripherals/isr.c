#include "include.h"


//����0�����жϷ�������
void UART0_IRQHandler(void)
{
  uint8_t ReData;
  uint8_t txt[20];
  
  DisableInterrupts ;//�����ж�
  
  ReData = Uart_GetChar(UARTR0);
  sprintf((char*)txt,"UART0_RX: %c \n",ReData);  
  Uart_SendString(UARTR0,txt);
  
  EnableInterrupts;   //�����ж�
}


//����1�����жϷ�������
void UART1_IRQHandler(void)
{
  uint8_t ReData;
  uint8_t txt[20];
  
  DisableInterrupts ;//�����ж�
  
  ReData = Uart_GetChar(UARTR1);
  sprintf((char*)txt,"UART1_RX: %c \n",ReData);  
  Uart_SendString(UARTR1,txt);
  
  EnableInterrupts;   //�����ж�
}

//����2�����жϷ�������
void UART2_IRQHandler(void)
{
  uint8_t ReData;
  uint8_t txt[20];
  
  DisableInterrupts ;//�����ж�
  
  ReData = Uart_GetChar(UARTR2);
  sprintf((char*)txt,"UART2_RX: %c \n",ReData);  
  Uart_SendString(UARTR2,txt);
  
  EnableInterrupts;   //�����ж�
}

//��ʱ��0�жϺ���
void PIT_CH0_IRQHandler(void)
{


	int feedback=0,ia=0;
	//uint8  txt[30]="X:",adt[30]="0",adt1[30]="0";
	PIT->CHANNEL[0].TFLG |= PIT_TFLG_TIF_MASK;//����жϱ�־λ

	feedback=FTM_count_get(CFTM1);
    
   kp[0]=200+feedback/2.3;
   kd[0]=(float)feedback*3.8;
	DirectionControl();

}

//��ʱ��1�жϺ���
/*
void PIT_CH1_IRQHandler(void)
{
  char  txt[30]="X:";
  int number=0;  
  PIT->CHANNEL[1].TFLG |= PIT_TFLG_TIF_MASK;//����жϱ�־λ
  if(gpio_get(PTH7))
    number=FTM_count_get(CFTM0);
  else
    number=-FTM_count_get(CFTM0);
  sprintf(txt,"FTM0 PTE0: %05d \n",number);
  Uart_SendString(UARTR2,(uint8_t*)txt); 
  LCD_P6x8Str(0,0,txt);
  if(gpio_get(PTH5))
    number=FTM_count_get(CFTM1);
  else
    number=-FTM_count_get(CFTM1);
  sprintf(txt,"FTM1 PTE7: %05d \n",number);
  Uart_SendString(UARTR2,(uint8_t*)txt);
  LCD_P6x8Str(0,2,txt);
  FTM_count_clean(CFTM0); 
  FTM_count_clean(CFTM1);
}

*/



//KBI0�жϺ���
void KBI0_IRQHandler(void)	
{  
	uint16_t n;
  KBI0->SC |= KBI_SC_KBACK_MASK;       /* clear interrupt flag */
  n = PTn(KBI_PTB5) ;   //PTA0���Ŵ����ж� 
  if(KBI0->SP &(1<<n))
  {
    //�û����� 
    LED_Ctrl(LED0, LEDRVS);             
  } 
}

//KBI1�жϺ���
void KBI1_IRQHandler(void)	
{  
	uint16_t n;
  KBI1->SC |= KBI_SC_KBACK_MASK;                /* clear interrupt flag */
  
  n = PTn(KBI_PTH2) ;   //PTH2���Ŵ����ж� 
  if(KBI1->SP &(1<<n))
  {
    //�û����� 
    LED_Ctrl(LED1, LEDRVS);             
  }
}


/*****************************************************************************//*!
*
* @brief  FTM0_Isr interrupt service routine.
*        
* @param  none.
*
* @return none.
*
* @ Pass/ Fail criteria: none.
*
*****************************************************************************/
void FTM0_IRQHandler(void)
{
  /* clear the flag */
  FTMx[CFTM0]->SC &= ~FTM_SC_TOF_MASK;
  
}

/*****************************************************************************//*!
*
* @brief  FTM1_Isr interrupt service routine.
*        
* @param  none. 
*
* @return none.
*
* @ Pass/ Fail criteria: none.
*
*****************************************************************************/
void FTM1_IRQHandler(void)
{
  /* clear the flag */
  FTMx[CFTM1]->SC &= ~FTM_SC_TOF_MASK;
}

/*****************************************************************************//*!
*
* @brief  FTM2_Isr interrupt service routine.
*        
* @param  none. 
*
* @return none.
*
* @ Pass/ Fail criteria: none.
*
*****************************************************************************/

void FTM2_IRQHandler(void)
{
  /* clear the flag */
  FTMx[CFTM2]->SC &= ~FTM_SC_TOF_MASK;
}


uint8_t Sec,Min,Hour;
//RTC�жϺ���
void RTC_IRQHandler(void)
{ 
  uint8_t  txt[30]="X:";
  RTC->SC |= RTC_SC_RTIF_MASK;  /* clear interrupt flag */ 
  Sec++;
  LED_Ctrl(LEDALL, LEDRVS);
  if (Sec>=60)
  {
    Min++;
    Sec=0;
  }
   if (Min>=60)
  {
    Hour++;
    Min=0;
  }
  sprintf((char*)txt,"TIME:%02d:%02d:%02d",Hour,Min,Sec);
  LCD_P6x8Str(0,0,txt);
}


