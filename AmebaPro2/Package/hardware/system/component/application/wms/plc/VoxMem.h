/********************************************************************************
*
* VoxMem.h
*
* Update Time: 2021/04/23
*
********************************************************************************/

#ifndef VOX_MEM_H
#define VOX_MEM_H

/*--------------------------------------- include -----------------------------------*/
#include "VoxTypedef.h"


#ifdef __cplusplus
extern "C" {
#endif



/*----------------------------------------- Function  Declaration ---------------------------------------*/
extern vox_void *VoxAlloc (vox_int16 size);
extern vox_void VoxFree (vox_void *ptr);
extern vox_void VoxMemcpy(vox_void *dest, const vox_void *src, vox_int16 size);
extern vox_void VoxMemset(vox_void *dest, vox_int16 c, vox_int16 size);


#ifdef __cplusplus
} 
#endif

#endif