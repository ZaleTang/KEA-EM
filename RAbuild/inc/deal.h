#ifndef _DEAL_H
#define _DEAL_H

#define lostline 0      //�����ٽ���ֵ�������ò���


//��־λö��
typedef enum
{
	FP=0,		//��ͨ����
	FCE=1,		//���뻷����־
	FCD=2,		//�����ڱ�־
	FT=3,		//ʮ�ֱ�־������������
}FLAG;


//extern �����ı�������������ʱֱ�Ӹ�ֵ������extern��û����

//��־λ
extern FLAG fg;

//�洢������ֵ�����ݣ����������0,1,2,3,4����
extern uint16_t ADvalue[5],AD_Data[5],AD_cha,AD_he;

//xjbд�ģ������ڲ�֪������ʱ������򲻱���
extern uint8_t condition;

//������ƴ���
extern int fvalue;
extern int last_value;

//�˴���������ferror�����ں�MDK�ײ�ĳ�ļ�ײ�����ˣ���ɾȥһ��r����Ϊferor
extern float feror;
extern float last_err;

//PID���������ó��˳���Ϊ���Ĳ������������ö��ٶȵ�λ����������ͬ����µ�PIDֵ
extern float kp[3],ki[3],kd[3];			

void DirectionControl(void);	

#endif