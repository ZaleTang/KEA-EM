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

float ad04=0,ad13=0;	//初始化差比和
uint16_t AD_sum=0,AD_cha=0,AD_he=0;		//初始化电感值之和

/*************************************************************************
*
* 	函数名称:DirectionControl()
*  	功能说明：略
*
*************************************************************************/
void DirectionControl()
{
	
	
	
	
	//getsig(ADvalue);		//获取电感值，存入ADcalue数组

/*	此处在IAR中没有问题，而在辣鸡MDK中有问题，所以我把声明放在了文件首
	float ad04=0,ad13=0;	
	uint16_t AD_sum=0;		
*/
	
	//计算差比和
	ad04=(float)((ADvalue[0]-ADvalue[4])/(ADvalue[0]+ADvalue[4]));
	ad13=(float)((ADvalue[1]-ADvalue[3])/(ADvalue[1]+ADvalue[3]));
	
	//AD和
	AD_sum=ADvalue[0]+ADvalue[1]+ADvalue[3]+ADvalue[4];

	//计算ferror此处本打算用ferror，由于和MDK底层某文件撞名字了，故删去一个r，改为feror
	
	feror=(float)((ADvalue[4]+ADvalue[3]-ADvalue[1]-ADvalue[0])/AD_sum);

	
	getsig(AD_Data);
	AD_cha=AD_Data[2]-AD_Data[4];
	AD_he=AD_Data[2]+AD_Data[4];
	feror=AD_cha/AD_he;

	

	
	//此处我把if里的条件都用condition，因为不知道具体车跑起来是什么条件
	//所以调车时需要把condition找到，这也是调车的目标之一
	
	if(fg==FP)		//当车位于普通赛道时
	{
		/**************************
		*
		*用于判定即将进入环岛
		*标志位为FCE
		*
		***************************/
		if(condition)
		{
		//此处添加情况判定显示，比如LED灯闪烁之类，以便观察是否进入条件
		
		//此处添加语句，后面都略去说明

			fg=FCE;
		}


		/**************************
		*
		*用于判定进入了环岛
		*标志位为FCD
		*
		***************************/
		else if ( condition )
		{
			/* code */

			fg=FCD;
		}

		/**************************
		*
		*用于判定十字，目测用不到
		*标志位为FCE
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
	*用于判定出环岛
	*标志位从FCE变回FP
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
	*用于判定从十字回到普通道
	*标志位从FCE变回FP
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
	*Led灯每隔20个中断闪烁一次，用于观察程序是否在正常运行
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