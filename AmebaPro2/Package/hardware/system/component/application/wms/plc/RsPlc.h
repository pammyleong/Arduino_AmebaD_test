/********************************************************************************
*
* RsPlc.h
*
* Update Time: 2021/12/27
*
********************************************************************************/

#ifndef RS_PLC_H
#define RS_PLC_H

/*--------------------------------------- include -----------------------------------*/
#include <string.h>
#include <stdio.h>
#include "stdlib.h"

#include "VoxTypedef.h"
#include "VoxMem.h"
#include "VoxMath.h"



#ifdef __cplusplus
extern "C" {
#endif


/*--------------------------------------- Definition -----------------------------------------*/
#define PLC_MAX_LOSS_NUM            (2)                       /* max number of loss frames£¬fixed:2 */
#define PLC_MAX_FRM_LEN             (1024)                    /* max frame length£¬fixed:1024 */


/*--------------------------------------- Structure --------------------------------------*/

typedef struct PLCMainStructType
{
	vox_int32                    swShift;
	vox_int32                    swWinLen; 

	vox_float                    *pfWin;
	vox_float                    *pfWpre;
	vox_float                    *pfWpost;
	vox_float                    *pfSigState;

}PLC_MAIN_STRUCT;


/*----------------------------------------- Function  Declaration ---------------------------------------*/
extern void RsPlcInit();
extern void RsPlcDestroy();
extern void RsPlcProcess(vox_int16    *pshwPre,
	                     vox_int16    *pshwPost,
	                     vox_int16    *pshwOut,
	                     vox_int32    swFrmLen,
	                     vox_int32    swLossNum);





#ifdef __cplusplus
} 
#endif

#endif