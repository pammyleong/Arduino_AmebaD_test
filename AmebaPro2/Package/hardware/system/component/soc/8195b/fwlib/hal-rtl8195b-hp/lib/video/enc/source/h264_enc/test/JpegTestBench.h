/*------------------------------------------------------------------------------
--                                                                            --
--       This software is confidential and proprietary and may be used        --
--        only as expressly authorized by a licensing agreement from          --
--                                                                            --
--                            Hantro Products Oy.                             --
--                                                                            --
--                   (C) COPYRIGHT 2006 HANTRO PRODUCTS OY                    --
--                            ALL RIGHTS RESERVED                             --
--                                                                            --
--                 The entire notice above must be reproduced                 --
--                  on all copies and should not be removed.                  --
--                                                                            --
--------------------------------------------------------------------------------
--
--  Abstract : Jpeg Encoder testbench
--
------------------------------------------------------------------------------*/
#ifndef _JPEGTESTBENCH_H_
#define _JPEGTESTBENCH_H_

//#include "basetype.h"

/*------------------------------------------------------------------------------
    3. Module defines
------------------------------------------------------------------------------*/

/* Maximum lenght of the file path */
#ifndef MAX_PATH
#define MAX_PATH   256
#endif

#define DEFAULT -255

/* Structure for command line options */
typedef struct
{
    char input[MAX_PATH];
    char output[MAX_PATH];
    char inputThumb[MAX_PATH];
    i32 firstPic;
    i32 lastPic;
    i32 width;
    i32 height;
    i32 lumWidthSrc;
    i32 lumHeightSrc;
    i32 horOffsetSrc;
    i32 verOffsetSrc;
    i32 restartInterval;
    i32 frameType;
    i32 colorConversion;
    i32 rotation;
    i32 partialCoding;
    i32 codingMode;
    i32 markerType;
    i32 qLevel;
    i32 unitsType;
    i32 xdensity;
    i32 ydensity;
    i32 thumbnail;
    i32 widthThumb;
    i32 heightThumb;
    i32 lumWidthSrcThumb;
    i32 lumHeightSrcThumb;
    i32 horOffsetSrcThumb;
    i32 verOffsetSrcThumb;
    i32 write;
    i32 comLength;
    char com[MAX_PATH];
    i32 inputLineBufMode;
    i32 inputLineBufDepth;
}
commandLine_s;

/* struct for input mb line buffer */
typedef struct
{
    u8 *lumSrc;
    u8 *cbSrc;
    u8 *crSrc;

    u8 *buf;
    u32 *reg;
    u8 *lumBuf;
    u8 *cbBuf;
    u8 *crBuf;    

    u32 inputFormat; /* format of input video */
    u32 pixOnRow; /* pixels in one line */
    u32 encWidth;
    u32 encHeight;

    i32 wrCnt;
    u32 depth;       /* number of MB_row lines in the input line buffer */
    u32 loopBackEn;
    u32 hwHandShake;

    void *inst;
}inputLineBufferCfg;

#endif
