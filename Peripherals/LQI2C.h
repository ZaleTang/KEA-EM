/*RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
【dev.env.】IAR7.80.4
【Target  】S9KEAZ128
【Crystal 】16.000Mhz
【busclock】40.000MHz
【pllclock】40.000MHz
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa*/


#ifndef _LQI2C_H_
#define _LQI2C_H_

/**********************************  IIC(引脚复用) ***************************************/

//定义读写选项
typedef enum MSmode
{
    write =   0x00,  /* Master write  */
    read =   0x01   /* Master read */
} MSmode;

void  I2C_WriteAddr(uint8 SlaveID, uint8 Addr, uint8 Data);      //读取地址里的内容
uint8  I2C_ReadAddr(uint8 SlaveID, uint8 Addr);                //往地址里写入内容

#endif




