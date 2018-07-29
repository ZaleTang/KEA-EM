/*RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
��dev.env.��IAR7.80.4
��Target  ��S9KEAZ128
��Crystal ��16.000Mhz
��busclock��40.000MHz
��pllclock��40.000MHz
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa*/


/*************************����˵��******************************/
/****************************************************************
  ����ʲô���ܾ�ȥ����Ӧ����ǰ�ġ�//��

  ÿ�����Ժ�����д�� while��1����ͬʱʹ���������Ժ�����ִ�еĺ�����Ч
*******************************************************************/
/******************************************************************
�ӿڶ��壺
-------------------------------------------------------------
LED         ��Ƭ���ӿ�
//���İ���RGB����
LED0           PTC2
LED1           PTB4
LED2           PTE5
//ĸ����LED����
LED3           PTI4
LED4           PTH6
===============================================================
KEY        ��Ƭ���ӿ�
//���İ��ϰ���
KEY0          PTA0
//ĸ�尴��
KEY1          PTB5
KEY2          PTH2
KEY3          PTE6
===============================================================
���뿪��    ��Ƭ���ӿ�
KEY0          PTI2
KEY1          PTI3
KEY2          PTE2
KEY3          PTE3
===============================================================
TSL1401ģ��     ��Ƭ���ӿ�
VCC             5V
GND             GND
SI              I5/D5
SCK             I6/D6
ADC             AD8 C0/AD9 C1
===============================================================
��·���ģ��    ��Ƭ���ӿ�
VCC             5V
GND             GND
ADCͨ��         �ܽŹ�ϵ     
ADC12           F4      
ADC13           F5      
ADC14           F6      
ADC15           F7       
ADC4            B0      
ADC5            B1   
ADC6            B2       
ADC7            B3
-------------------------------------------------------------
��Դ��ػ�������    
ADC11           C3              
-------------------------------------------------------------
MPU6050        ��Ƭ���ӿ�   FLEXCOMM8
VCC             5V
GND             GND
SDA1            H3
SCL1            H4
//////////////////////////////////////////////////////////ͨ�ò��ֹ���//////////
�������        ��Ƭ���ӿ�   
VCC             5V
PWM1            FTM2-CH0  H0
PWM2            FTM2-CH1  H1
PWM3            FTM2-CH2  D0
PWM4            FTM2-CH3  D1
-------------------------------------------------------------
����ӿ�        ��Ƭ���ӿ�
VCC             �ɵ�
GND             GND
PWM1            FTM1-CH1  E7
-------------------------------------------------------------
����512������   ��Ƭ���ӿ�   
VCC             5V
GND             GND      
LSB/A           FTM0 E0    
DIR/B           H7     
LSB/A           FTM1 E7     
DIR/B           H5     
-------------------------------------------------------------
OLEDģ��        ��Ƭ���ӿ�
VCC             5V
GND             GND
SCK             F3
SDA             F2
RST             A7
DC              A6
-------------------------------------------------------------
����/USBTTL    ��Ƭ���ӿ�   FLEXCOMM0
VCC             5V
GND             GND
UART2_RX        I1    
UART2_TX        I0
=============================================================*/

  //TestLED();//����GPIOmini���İ�RGB������ɫ��˸
  //Test_KEY(); //����GPIO��������
  //Test_KEY1(); //����GPIO���뿪�ع���
  //TestADC();//����ADCת����ͨ��OLED��ʾ��UART����
  //TestPIT();//����PIT��ʱ�ж�
  //TestFTM_PWM();//����PWM/OLED��������ƹ���
  //TestUART012();//����UART012���ͼ������ж�
  //TestFTM_InputCapture();//���Ա���������ɼ�����

#include "include.h"
uint8 SR[30]="System is ready to go ",
			SR1[30]="                           ",
			SR2[30]="                           ";

int main()
{
	uint8  txt[30]="X:",adt[30]="0",adt1[30]="0";
	DisableInterrupts ;                  //��ֹ�ж�    
  EnableInterrupts;
	SystermInit();
	
	
	Motor_spd(300,300);
	LCD_P6x8Str(1,0,SR);
	LCD_P6x8Str(1,1,SR1);
	LCD_P6x8Str(1,2,SR1);
  LCD_Fill(0x00);  //��ʼ����
  LCD_Set_Pos(0,0);  
	LCD_P6x8Str(1,0,SR);
}


#if 0		//���ڲ���while(1)��ѭ����֤�㷨��ʵ�����
int main(void)
{  
	
  uint8  txt[30]="X:",adt[30]="0",adt1[30]="0";
  uint16 ad[16] = {0},ADvalue[5]={0};  
	int ia,cv,cv1,he,cha;
	float adca,adtc[5]={0,0,0,0,0};
		int admax[5]={110,110,110,110,110},
			admin[5]={10,10,10,10,10};
	
	//uint8_t cc[350]="aaaaaaaa";
  DisableInterrupts ;                  //��ֹ�ж�    
  EnableInterrupts;    
	
	//SystermInit();
	


	
	FTM_init();
	LCD_Init();
	
	Motor_spd(300,300);

	LED_Init();
	//LED1 blue



	

	uart_init(UARTR2,Remap,9600);
	LED_Ctrl(LED4,LEDON);
	time_delay_ms(500);
	LED_Ctrl(LED4,LEDOFF);
	
	//int ca=0;
		while(1)
		{
			/*
			LED_Ctrl(LED3,LEDON);
			time_delay_ms(500);
			LED_Ctrl(LED3,LEDOFF);
			//ka[0]=0xdd;
			/*
			ca[0]=adc_once(ADC_CHANNEL_AD4,ADC_12BIT);
			ca[1]=adc_once(ADC_CHANNEL_AD6,ADC_12BIT);
			ca[2]=adc_once(ADC_CHANNEL_AD7,ADC_12BIT);
			ca[3]=adc_once(ADC_CHANNEL_AD15,ADC_12BIT);
			ca[4]=adc_once(ADC_CHANNEL_AD14,ADC_12BIT);
			*/
			//ka[6]=0xdd;
			
			//Uart_SendChar(UARTR2,ca[0]);
			getsig(ad);
			for(ia=0;ia<5;ia++)
			{
				if (ad[ia]>admax[ia])
					ad[ia]=admax[ia];
				if (ad[ia]<admin[ia])
					ad[ia]=admin[ia];
				ADvalue[ia]=(float)(400*(ad[ia]-admin[ia])/(admax[ia]-admin[ia]));
				//ADvalue[ia]=(float)(adtc[ia])*400;
			}
			cha=ADvalue[2]+ADvalue[0]-ADvalue[3]-ADvalue[4];
			he=ADvalue[0]+ADvalue[2]+ADvalue[3]+ADvalue[4];
			
			//adca=(float)(cha/he);//0.3
			
			cv1=(int)((cha*40)/he);
			
			cv=(int)(adca*40);
		
			
			
			
			for(ia=0;ia<5;ia++)
			{
				sprintf((char*)txt,"AD%02d:%04d  ",ia,ADvalue[ia]);
				sprintf((char*)adt,"cv=%04d cv1=%04d",cv,cv1);
				sprintf((char*)adt1,"cha=%04d he=%04d",cha,he);
				Uart_SendString(UARTR2,txt);
      if(!(ia%2))
        LCD_P6x8Str((1*(ia%2)),(ia/2),txt);
      else
       LCD_P6x8Str((64*(ia%2)),(ia/2),txt);
			LCD_P6x8Str(0,4,adt1);
			LCD_P6x8Str(3,5,adt);
			}
		/*	
			LED_Ctrl(LEDALL,LEDON);
			time_delay_ms(500);
			LED_Ctrl(LEDALL,LEDOFF);
		*/
				car_direct(-cv1);
		}
  
}


#endif
