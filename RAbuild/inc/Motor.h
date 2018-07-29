#ifndef _MOTOR_H
#define _MOTOR_H



/**************舵机极值****************************************************/
//极左
#define MAX_L -40

//极右
#define MAX_R 40

//中值
#define MID 295

/**************控制函数****************/

void car_direct(int Angle);

void Motor_speedL(int speed);
void Motor_speedR(int speed);

void Motor_spd(int spdl, int spdr);	//MotorB MotorA


#endif