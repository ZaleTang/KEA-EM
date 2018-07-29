/*RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
【dev.env.】IAR7.80.4
【Target  】S9KEAZ128
【Crystal 】16.000Mhz
【busclock】40.000MHz
【pllclock】40.000MHz
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa*/

#ifndef __LED_H__
#define __LED_H__

//定义模块号
typedef enum
{ 
    LED0=0,
    LED1=1,
    LED2=2,
    LED3=3,
    LED4=4,
    LEDALL=5,//全部  
} LEDn_e;

typedef enum
{
    LEDON=0,  //亮
    LEDOFF=1, //灭
    LEDRVS=2, //反转  
}LEDs_e;

/*********************** UART功能函数 **************************/
//初始化
extern void LED_Init(void);
extern void LED_Ctrl(LEDn_e ledno, LEDs_e sta);
extern void TestLED(void);
/********************************************************************/

#endif 
