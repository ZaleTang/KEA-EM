#include "include.h"


/*************************************************************************
*  ��������:getsig
*  ����˵������ȡ��·���ֵ����ȥ��һ�����ֵȥ��һ����Сֵȡƽ��ֵ
*  ����˵��������������Ϊ�������ݽ�������ֱ��д������

*  for example           getsig(a);		//aΪһ����������� int a[5];
*************************************************************************/
void getsig(uint16_t *a)
{
	uint8_t i,j,k;
	uint16_t tmp;
    uint16_t at[6]={0,0,0,0,0};
    uint16_t atmp[6][12];

  	for(j=0;j<12;j++)
  	{
  		atmp[0][j]=AD0;
  	}
  	for(j=0;j<12;j++)
  	{
  		atmp[1][j]=AD1;
  	}
  	for(j=0;j<12;j++)
  	{
  		atmp[2][j]=AD2;
  	}
  	for(j=0;j<12;j++)
  	{
  		atmp[3][j]=AD3;
  	}
  	for(j=0;j<12;j++)
  	{
  		atmp[4][j]=AD4;
  	}
		for(j=0;j<12;j++)
  	{
  		atmp[5][j]=AD4;
  	}

  	for(i=0;i<6;i++)
		for(j=0;j<12;j++)
			for(k=0;k<12-j-1;k++)
                if(atmp[k]>atmp[k+1])
				{
					tmp=atmp[i][k];
					atmp[i][k]=atmp[i][k+1];
					atmp[i][k+1]=tmp;
				}

	for(i=0;i<6;i++)
		for(j=1;j<11;j++)	
			at[i]+=atmp[i][j];

	for(i=0;i<6;i++)
		at[i]=at[i]/10;
	
	for(i=0;i<5;i++)
		*(a+i)=at[i];
}

