#ifndef _CAMUTIL_H_
#define _CAMUTIL_H_

///////////////////////////////////////////
#include <reg52.h>
#include <absacc.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include<intrins.h>


sbit EPFI = 0xD8^5;
sbit PFI = 0xD8^4;
sfr CKCON  = 0x8E;

typedef  unsigned char			U8;		//  8bit
typedef  unsigned short int		U16;		// 16bit
typedef  unsigned long	int		U32;		// 32bit

typedef  signed char			S8;
typedef  signed short int		S16;
typedef  signed long  int		S32;
typedef  unsigned char            BOOL;

/* boolean definition*/
#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif

#define TRUE  1
#define FALSE 0

#define SWITCH_ON 1
#define SWITCH_OFF 0

#define SNR_PWDN_DRIVE_HIGH	1
#define SNR_PWDN_DRIVE_LOW	0

#define LONG2CHAR(num,i)	(*( (U8 *)&(num) + (3-(i)) ))
#define INT2CHAR(num,i)	(*( (U8 *)&(num) + (1-(i)) ))
#define ASSIGN_INT(num,hbyte,lbyte)	{*( (U8 *)&(num) ) = hbyte; \
											*( (U8 *)&(num)+1 ) = lbyte;}
#define ASSIGN_LONG(num,byte3,byte2,byte1,byte0)	{*( (U8 *)&(num) ) = byte3; \
										*( (U8 *)&(num)+1 ) = byte2; \
										*( (U8 *)&(num)+2 ) = byte1; \
										*( (U8 *)&(num)+3 ) = byte0; }
#define ASSIGN_U32BYTE(num, i,byte) {*( (U8 *)&(num)+(3-(i)) ) = byte;}
#define ASSIGN_U16BYTE(num, i,byte) {*( (U8 *)&(num)+(1-(i)) ) = byte;}

#define CONSTLONG2BYTE(cLong,i)           ((cLong)&(0xff000000>>(24-(i)*8)))>>(8*(i))
#define CONSTSHORT2BYTE(cShort,i)        ((cShort)&(0xff00>>(8-(i)*8)))>>(8*(i))

#define readb(addr) (*(volatile U8 xdata *)(addr))
#define readw(addr) (*(volatile U16 xdata *)(addr))
#define readl(addr) (*(volatile U32 xdata *)(addr))
#define writeb(value, addr) \
	do { *(volatile U8 xdata *)(addr) = (value); } while(0)

#define writew(value, addr) \
	do { *(volatile U16 xdata *)(addr) = (value); } while(0)

#define writel(value, addr) \
	do { *(volatile U32 xdata *)(addr) = (value); } while(0)

U32 read3b(void xdata *addr);
void write3b(U32 value, void xdata *addr);

U16 readw_el(void xdata *addr);
U32 readl_el(void xdata *addr);
U32 read3b_el(void xdata *addr);
void writew_el(U16 value, void xdata *addr);
void writel_el(U32 value, void xdata *addr);
void write3b_el(U32 value, void xdata *addr);
void writew_el_noisr(U16 value, void xdata *addr);
void writel_el_noisr(U32 value, void xdata *addr);

#define ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define EnterCritical()  {EA=0;EPFI=0;}
#define ExitCritical()     {EA=1;EPFI=1;}

#define EPSINON		0.0001	// float compare presion

void rlprintf(const char *, ...);
#define printf rlprintf
#define CONFIG_PRINT_SIZE		64

#define UART_BAUDRATE		57600

//utility functions
void Delay(U16 ms);
void uDelay(U16 w100us);
void usDelay(U8 byus);
bit	WaitTimeOut(U16 wReg, U8 byVal, U8 byPolarity, U8 byMSEC) ;
void WaitTimeOut_Delay(U8 by10MSec);

U16 DiffWord(U16 wA, U16 wB);
U16 ClipWord(U16 wCur, U16 wMin, U16 wMax);
S16 ClipSWord(S16 wCur, S16 wMin, S16 wMax);
float ClipFloat(float fCur, float fMin, float fMax);
U8 LinearIntp_Byte(U8 byX1,U8 byY1, U8 byX2, U8 byY2, U8 byX);
U8 LinearIntp_Byte_Bound(U8 byX1,U8 byY1, U8 byX2, U8 byY2, U8 byX);
U16 LinearIntp_Word(U16 wX1,U16 wY1, U16 wX2, U16 wY2, U16 wX);
U16 LinearIntp_Word_Bound(U16 wX1,U16 wY1, U16 wX2, U16 wY2, U16 wX);
S16 LinearIntp_Word_Signed(S16 wX1,S16 wY1, S16 wX2, S16 wY2, S16 wX);
S16 LinearIntp_Word_Bound_Signed(S16 wX1,S16 wY1, S16 wX2, S16 wY2, S16 wX);
U8 MaxByte(U8 byX1, U8 byX2);
U8 MinByte(U8 byX1, U8 byX2);
float MinFloat(float fX1, float fX2);
U16 MinWord(U16 wX1, U16 wX2);
S16 MinSWord(S16 swX1, S16 swX2);
U8 JudgeDiff(const U8 abys1[25], const U8 abys2[25], U8 byth);
void radix_sort(U8 *array);
void bubble_sort(U8 *array);

#endif // _CAMUTIL_H_
