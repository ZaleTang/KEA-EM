#include <include.h>

/*************************************************************************
*  ��������:car_direct
*  ����˵�������ƶ�����
*  ʹ��˵�������ú�MID��ֵ��ֵ��Ȼ��ƫ�������뺯�������Ʒ���
*  
*************************************************************************/

void car_direct(int Angle)
{
  FTM_PWM_Duty(CFTM1,FTM_CH1,MID+Angle);
}


/*************************************************************************
*  ��������:Motor_speedL (Motor_speedR,�������ֱ����������)
*  ����˵�������������ת��
*  ����˵����speed��ֵ��ת����ֵ��ת
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
*  ��������:Motor_spd
*  ����˵��������������ת��
*  ����˵����spdlΪ������ٶ�ֵ��spdrΪ�Ҳ����ٶ�ֵ
*  
*************************************************************************/
void Motor_spd(int spdl, int spdr)
{
	Motor_speedL(spdl);
	Motor_speedR(spdr);
}
