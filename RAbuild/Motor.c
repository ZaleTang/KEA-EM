#include <include.h>

/*************************************************************************
*  函数名称:car_direct
*  功能说明：控制舵机打角
*  使用说明：设置好MID中值的值，然后将偏移量传入函数，控制方向
*  
*************************************************************************/

void car_direct(int Angle)
{
  FTM_PWM_Duty(CFTM1,FTM_CH1,MID+Angle);
}


/*************************************************************************
*  函数名称:Motor_speedL (Motor_speedR,两函数分别控制两侧电机)
*  功能说明：控制左侧电机转速
*  参数说明：speed正值正转，负值反转
*  
*************************************************************************/

void Motor_speedL(int speed)
{
  if(speed>0)
	{
    FTM_PWM_Duty(CFTM2,FTM_CH0,abs(speed));
		FTM_PWM_Duty(CFTM2,FTM_CH1,0);
	}
	else if(speed<0)
	{
		FTM_PWM_Duty(CFTM2,FTM_CH0,0);
		FTM_PWM_Duty(CFTM2,FTM_CH1,abs(speed));
  }
	else
  {
    FTM_PWM_Duty(CFTM2,FTM_CH0,0);
    FTM_PWM_Duty(CFTM2,FTM_CH1,0);
  }
}


void Motor_speedR(int speed)
{
  if (speed>0)
	{
    FTM_PWM_Duty(CFTM2,FTM_CH2,abs(speed));
		FTM_PWM_Duty(CFTM2,FTM_CH3,0);
	}
	else if (speed<0)
	{
		FTM_PWM_Duty(CFTM2,FTM_CH3,abs(speed));
		FTM_PWM_Duty(CFTM2,FTM_CH2,0);
	}
	else
  {
    FTM_PWM_Duty(CFTM2,FTM_CH2,0);
    FTM_PWM_Duty(CFTM2,FTM_CH3,0);
  }
}


/*************************************************************************
*  函数名称:Motor_spd
*  功能说明：控制两侧电机转速
*  参数说明：spdl为左侧电机速度值，spdr为右侧电机速度值
*  
*************************************************************************/
void Motor_spd(int spdl, int spdr)
{
	Motor_speedL(spdl);
	Motor_speedR(spdr);
}
