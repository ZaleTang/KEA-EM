#ifndef _MOTOR_H
#define _MOTOR_H



/**************�����ֵ****************************************************/
//����
#define MAX_L -40

//����
#define MAX_R 40

//��ֵ
#define MID 295

/**************���ƺ���****************/

void car_direct(int Angle);

void Motor_speedL(int speed);
void Motor_speedR(int speed);

void Motor_spd(int spdl, int spdr);	//MotorB MotorA


#endif