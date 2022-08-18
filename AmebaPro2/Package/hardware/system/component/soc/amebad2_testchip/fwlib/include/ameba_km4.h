/**
  ******************************************************************************
  * @file    ameba_km4.h
  * @author
  * @version V1.0.0
  * @date    2016-05-17
  * @brief   This file contains all the functions prototypes for km0 control km4.
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2015, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef _AMEBA_KM4_H_
#define _AMEBA_KM4_H_

/** @addtogroup Ameba_Platform
  * @{
  */

/** @defgroup KM0_CTRL_KM4
  * @brief KM0_CTRL_KM4 driver modules
  * @{
  */

/* Exported Types --------------------------------------------------------*/
/** @addtogroup KM0_CTRL_KM4_Exported_Types KM0_CTRL_KM4 Exported Types
  * @{
  */

/**
  * @brief  km4 sleep parameter structure definition
  */
#ifndef CONFIG_BUILD_ROM

typedef struct {
	u32	sleep_type;
	u32	sleep_time;
	u32	dlps_enable;
	u32	rsvd[5];
} KM4SLEEP_ParamDef;

#endif

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup KM0_CTRL_KM4_Exported_Functions KM0_CTRL_KM4 Exported Functions
  * @{
  */

void np_pm_init(void);
void np_boot_on(void);
u32 np_suspend(u32 type);
void np_resume(void);
u32 np_status_on(void);
void km4_set_wake_event(u32 wevt);
u32 np_get_wake_event(void);
void np_tickless_ipc_int(VOID *Data, u32 IrqStatus, u32 ChanNum);
void ap_tickless_ipc_int(VOID *Data, u32 IrqStatus, u32 ChanNum);
void np_flash_highspeed_resume(u32 Protection);
void np_flash_highspeed_suspend(u32 Protection);
void np_flash_highspeed_init(void);
uint32_t pmu_get_km4sleeptime(void);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/* Other definations --------------------------------------------------------*/

extern u8 np_sleep_type;
extern u32 np_sleep_timeout;

#endif /* _AMEBA_KM4_H_ */
/******************* (C) COPYRIGHT 2016 Realtek Semiconductor *****END OF FILE****/
