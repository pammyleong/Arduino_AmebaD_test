#ifndef __GT911_H
#define __GT911_H	
#include "sys.h"	
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32开发板
//4.3寸电容触摸屏-GT9147 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2015/12/28
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved		 
////////////////////////////////////////////////////////////////////////////////// 


//IO操作函数	 

#define RST_PIN 				_PA_18
#define SCL_PIN				_PB_5
#define SDA_PIN				_PB_6
#define INT_PIN				_PA_17

#define GT911_RST_1()  GPIO_WriteBit(RST_PIN, 1)//PIout(8)=1	/* RST = 1 */ 
#define GT911_RST_0()  GPIO_WriteBit(RST_PIN, 0) //PIout(8)=0	/* RST = 0 */ 

#define GT911_INT_1()  	 GPIO_WriteBit(INT_PIN, 1)//PHin(7)=1/* INT = 1 */ 
#define GT911_INT_0()  	 GPIO_WriteBit(INT_PIN, 0)//PHin(7)=0/* INT = 0 */ 
 
 
 
//I2C读写命令	
#define GT_CMD_WR 		0X28     	//写命令
#define GT_CMD_RD 		0X29		//读命令
  
//GT9147 部分寄存器定义 
#define GT_CTRL_REG 	0X8040   	//GT9147控制寄存器
#define GT_CFGS_REG 	0X8047   	//GT9147配置起始地址寄存器
#define GT_CHECK_REG 	0X80FF   	//GT9147校验和寄存器
#define GT_PID_REG 		0X8140   	//GT9147产品ID寄存器

#define GT_GSTID_REG 	0X814E   	//GT9147当前检测到的触摸情况
#define GT_TP1_REG 		0X8150  	//第一个触摸点数据地址
#define GT_TP2_REG 		0X8158		//第二个触摸点数据地址
#define GT_TP3_REG 		0X8160		//第三个触摸点数据地址
#define GT_TP4_REG 		0X8168		//第四个触摸点数据地址
#define GT_TP5_REG 		0X8170		//第五个触摸点数据地址  
 
 
 //一下未使用
#define GT911_READ_XY_REG 					0x814E	/* 坐标寄存器 */ 
#define GT911_CLEARBUF_REG 					0x814E	/* 清除坐标寄存器 */ 
#define GT911_CONFIG_REG 						0x8047	/* 配置参数寄存器 */ 
#define GT911_COMMAND_REG 					0x8040 	/* 实时命令 */ 
#define GT911_PRODUCT_ID_REG 				0x8140 	/*productid*/ 
#define GT911_VENDOR_ID_REG 				0x814A 	/* 当前模组选项信息 */ 
#define GT911_CONFIG_VERSION_REG 		0x8047 	/* 配置文件版本号 */ 
#define GT911_CONFIG_CHECKSUM_REG 	0x80FF 	/* 配置文件校验码 */ 
#define GT911_FIRMWARE_VERSION_REG	0x8144 	/* 固件版本号 */  


#define TP_PRES_DOWN 0x80  //触屏被按下	  
#define TP_CATH_PRES 0x40  //有按键按下了 
#define CT_MAX_TOUCH  5    //电容屏支持的点数,固定为5点

//触摸屏控制器
typedef struct
{
	
	u16 x[CT_MAX_TOUCH]; 		//当前坐标
	u16 y[CT_MAX_TOUCH];		//电容屏有最多5组坐标,电阻屏则用x[0],y[0]代表:此次扫描时,触屏的坐标,用
								//x[4],y[4]存储第一次按下时的坐标. 
	u8  sta;					//笔的状态 
								//b7:按下1/松开0; 
	                            //b6:0,没有按键按下;1,有按键按下. 
								//b5:保留
								//b4~b0:电容触摸屏按下的点数(0,表示未按下,1表示按下)							
	   
//新增的参数,当触摸屏的左右上下完全颠倒时需要用到.
//b0:0,竖屏(适合左右为X坐标,上下为Y坐标的TP)
//   1,横屏(适合左右为Y坐标,上下为X坐标的TP) 
//b1~6:保留.
//b7:0,电阻屏
//   1,电容屏 
	u8 touchtype;
}_m_tp_dev;

 
 
u8 GT911_Send_Cfg(u8 mode);
u8 GT911_WR_Reg(u16 reg,u8 *buf,u8 len);
void GT911_RD_Reg(u16 reg,u8 *buf,u8 len); 
u8 GT911_Init(void);
u8 GT911_Scan(u8 mode); 


void GT911_Reset_Sequence(uint8_t ucAddr);//未使用
void GT911_Soft_Reset(void);//未使用
#endif













