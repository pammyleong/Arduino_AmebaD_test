/********************************************************************************
*
* VoxTypedef.h
* Data type definition
* Update Time: 2021/04/23
*
********************************************************************************/

#ifndef VOX_TYPEDEF_H
#define VOX_TYPEDEF_H

/*--------------------------------------- Include -----------------------------------*/
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif


/*--------------------------------------- Definition -----------------------------------------*/
typedef char               vox_char;
typedef signed short int   vox_int16;
typedef signed int         vox_int32;
typedef unsigned short int vox_uint16;
typedef unsigned int       vox_uint32;
typedef float              vox_float;
typedef void               vox_void;


#define VOX_NULL          NULL



/*--------------------------------------- Enumeration definition ----------------------------------------*/
typedef enum
{
	VOX_SWITCH_OFF = 0,
	VOX_SWITCH_ON
}VOX_SWITCH_FLAG_ENUM;



#ifdef __cplusplus
} 
#endif

#endif