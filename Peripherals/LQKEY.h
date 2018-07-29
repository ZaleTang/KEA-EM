/*RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
【dev.env.】IAR7.80.4
【Target  】S9KEAZ128
【Crystal 】16.000Mhz
【busclock】40.000MHz
【pllclock】40.000MHz
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa*/

#ifndef __KEY_H__
#define __KEY_H__

//定义模块号
typedef enum
{
    KEY0=0,
    KEY1=1,
    KEY2=2,
    KEY3=3,
    KEYALL=4,
} KEYn_e;

typedef enum
{
    KEYLOW=0,  //
    KEYHIGH=1, //   
    KEYFAIL=0xFF,
}KEYs_e;



//函数
extern void   KEY_Init(void);
extern uint8_t KEY_Read(KEYn_e keyno);
extern void Test_KEY(void);
extern void   KEY1_Init(void);
extern uint8_t KEY1_Read(KEYn_e keyno);
extern void Test_KEY1(void);
#endif 
