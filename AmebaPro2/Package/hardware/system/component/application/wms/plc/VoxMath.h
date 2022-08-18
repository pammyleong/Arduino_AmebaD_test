/******************************************************************************
*
* VoxMath.h
*
*******************************************
*
* Description: Common math Function£¬simple
* Update Time: 2021/12/24
*
********************************************************************************/

#ifndef VOX_MATH_H
#define VOX_MATH_H

/*--------------------------------------- Include -----------------------------------*/
#include <stdio.h>
#include <math.h>


#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------- Definition -----------------------------------*/
#define VoxAbs(x)                   ((x) < 0 ? (-(x)) : (x))      /**  Absolute 16-bit value.  */
#define VoxMin(a,b)                 ((a) < (b) ? (a) : (b))       /**  Maximum 16-bit value.   */
#define VoxMax(a,b)                 ((a) > (b) ? (a) : (b))       /**  Maximum 16-bit value.   */
#define VoxFloat2Int16(x)           ((x) < -32767.5f ? -32768 : ((x) > 32766.5f ? 32767 : floor(.5+(x))))  

#define VoxPow                      pow
#define VoxLog10                    log10f
#define VoxFloor                    floorf
#define VoxSqrt                     sqrt
#define VoxAcos                     acos
#define VoxExp                      exp
#define VoxCosNorm(x)               (cos((.5f*VOX_M_PI)*(x)))
#define VoxAtan                     atan

#define VOX_FLOAT_ZERO              (0.f)
#define VOX_FLOAT_ONE               (1.f)
#define VOX_FLOAT_TWO               (2.0f)
#define VOX_FLOAT_TEN               (10.0f)
#define VOX_FLOAT_HALF              (0.5f)
#define VOX_M_PI                    (3.14159265358979323846)
#define VOX_PI_2                    (1.5707963268)



#ifdef __cplusplus
} 
#endif


#endif