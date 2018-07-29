#include "include.h"

FLAG fg;
uint16_t ADvalue[5]={0,0,0,0,0},AD_Data[5]={0,0,0,0,0};
uint8_t condition=0;
int fvalue=0;
int last_value=0;
float feror=0;
float last_err=0; 
float kp[3]={0,0,0},ki[3]={0,0,0},kd[3]={0,0,0};
int Ledcount=0;

float ad04=0,ad13=0;	//��ʼ����Ⱥ�
uint16_t AD_sum=0,AD_cha=0,AD_he=0;		//��ʼ�����ֵ֮��

/*************************************************************************
*
* 	��������:DirectionControl()
*  	����˵������
*
*************************************************************************/
void DirectionControl()
{
	
	
	
	
	//getsig(ADvalue);		//��ȡ���ֵ������ADcalue����

/*	�˴���IAR��û�����⣬��������MDK�������⣬�����Ұ������������ļ���
	float ad04=0,ad13=0;	
	uint16_t AD_sum=0;		
*/
	
	//�����Ⱥ�
	ad04=(float)((ADvalue[0]-ADvalue[4])/(ADvalue[0]+ADvalue[4]));
	ad13=(float)((ADvalue[1]-ADvalue[3])/(ADvalue[1]+ADvalue[3]));
	
	//AD��
	AD_sum=ADvalue[0]+ADvalue[1]+ADvalue[3]+ADvalue[4];

	//����ferror�˴���������ferror�����ں�MDK�ײ�ĳ�ļ�ײ�����ˣ���ɾȥһ��r����Ϊferor
	
	feror=(float)((ADvalue[4]+ADvalue[3]-ADvalue[1]-ADvalue[0])/AD_sum);

	
	getsig(AD_Data);
	AD_cha=AD_Data[2]-AD_Data[4];
	AD_he=AD_Data[2]+AD_Data[4];
	feror=AD_cha/AD_he;

	

	
	//�˴��Ұ�if�����������condition����Ϊ��֪�����峵��������ʲô����
	//���Ե���ʱ��Ҫ��condition�ҵ�����Ҳ�ǵ�����Ŀ��֮һ
	
	if(fg==FP)		//����λ����ͨ����ʱ
	{
		/**************************
		*
		*�����ж��������뻷��
		*��־λΪFCE
		*
		***************************/
		if(condition)
		{
		//�˴��������ж���ʾ������LED����˸֮�࣬�Ա�۲��Ƿ��������
		
		//�˴������䣬���涼��ȥ˵��

			fg=FCE;
		}


		/**************************
		*
		*�����ж������˻���
		*��־λΪFCD
		*
		***************************/
		else if ( condition )
		{
			/* code */

			fg=FCD;
		}

		/**************************
		*
		*�����ж�ʮ�֣�Ŀ���ò���
		*��־λΪFCE
		*
		***************************/
		else if ( condition )
		{
			/* code */
			fg=FT;
		}
	}
		
	/**************************
	*
	*�����ж�������
	*��־λ��FCE���FP
	*
	***************************/
	else if (fg==FCE)
	{
		/* code */
		fg=FP;
		fvalue=(int)(kp[0]*feror+kd[0]*(feror-last_err));
	}

	/**************************
	*
	*�����ж���ʮ�ֻص���ͨ��
	*��־λ��FCE���FP
	*
	***************************/
	else if (fg==FT)
	{
		/* code */
		fg=FP;
		fvalue=(int)(kp[0]*feror+kd[0]*(feror-last_err));
	}

	fvalue=(int)((AD_cha*40)/AD_he);
	
	last_err=feror;
	last_value=fvalue;

	
	if(fvalue>MAX_R)
		fvalue=MAX_R;
	else if(fvalue<MAX_L)
		fvalue=MAX_L;

	/******************
	*
	*Led��ÿ��20���ж���˸һ�Σ����ڹ۲�����Ƿ�����������
	*
	*******************/
	Ledcount++;
	if(Ledcount==20)
	{
		LED_Ctrl(LEDALL,LEDRVS);
		Ledcount=0;
	}
	
	car_direct(fvalue);


}