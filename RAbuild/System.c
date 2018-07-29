#include <include.h>
uint8 MR1[30]="Motor Initializing...",
			MR2[30]="Motor Initialized     ",
			DR1[30]="Data Initializing...",
			DR2[30]="Data Initialized     ",
			LEDR1[30]="LED Initializing...",
			LEDR2[30]="LED Initialized     ",
			LCDR1[30]="LCD Initializing...",
			LCDR2[30]="LCD Initialized     ",
			PR1[30]="PIT Starting...",
			PR2[30]="PIT Started    ";
/*************************************************************************
*  函数名称:SystermInit
*  功能说明：系统初始化
*  使用说明：将所有的初始化函数写入其中，开机时启动
*  
*************************************************************************/

void SystermInit()
{
	LCD_Init();
	LCD_P6x8Str(0,0,LCDR2);
	time_delay_ms(200);
	LCD_P6x8Str(0,1,MR1);
  FTM_init();
	time_delay_ms(200);
	LCD_P6x8Str(0,1,MR2);
  LCD_P6x8Str(0,2,DR1);
	DATAinit();
	time_delay_ms(200);
	LCD_P6x8Str(0,2,DR2);
	LCD_P6x8Str(0,3,LEDR1);
	LED_Init();
	time_delay_ms(200);
	LCD_P6x8Str(0,3,LEDR2);
	
	LCD_P6x8Str(0,4,PR1);
	PIT_Init(PIT_CHANNEL0,10);
	//time_delay_ms(200);
	
	LCD_P6x8Str(0,4,PR2);
	LED_Ctrl(LEDALL,LEDON);
	//time_delay_ms(200);
	LED_Ctrl(LEDALL,LEDOFF);
	
}

//

/*************************************************************************
*  函数名称：DATAinit
*  功能说明：需被多出调用的参数初始化，亦写进了SystemInit里
*  
*  
*************************************************************************/

void DATAinit()
{
  uint8_t i;
  fg=FP;
  for(i=0;i<5;i++)
	{
    ADvalue[i]=0;
		AD_Data[i]=0;
	}
  for(i=0;i<3;i++)
  {
    kp[i]=0;ki[i]=0;kp[i]=0;
  }
  
  condition=0;
  fvalue=0;
  last_value=0;
  feror=0;
  last_err=0;
	
	AD_cha=0;
	AD_he=0;

}


/*************************************************************************
*  函数名称：FTM_init
*  功能说明：初始化各种PWM外设的引脚，如电机，舵机等
*  
*  
*************************************************************************/


void FTM_init()               
{

    FTM_PWM_init(CFTM1, FTM_CH1,FTM_PTE7, 100, MID);//舵机初始化

    FTM_PWM_init(CFTM2, FTM_CH0,FTM_PTH0, 12500, 200);//PWM2 PTH0
    FTM_PWM_init(CFTM2, FTM_CH1,FTM_PTH1, 12500, 200);//PWM2 PTH1
	
		FTM_PWM_init(CFTM2, FTM_CH2,FTM_PTD0, 12500, 200);
		FTM_PWM_init(CFTM2, FTM_CH3,FTM_PTD1, 12500, 200);
}


//绝对值函数，似乎本来就自带，这里又写了一个
int abs(int number) 
{
  if(number>0)
    return number;
  else return -number;
}

float abs_f(float number)
{
	if(number>0)
		return number;
	else return -number;
}