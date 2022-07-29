/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/


#ifndef __ODM_DBG_H__
#define __ODM_DBG_H__

#define FW_DEBUG_VERSION    "1.0"  /*2015.07 YuChen*/
//-----------------------------------------------------------------------------
//  Define the debug levels
//
//  1.  DBG_TRACE and DBG_LOUD are used for normal cases.
//  So that, they can help SW engineer to develope or trace states changed
//  and also help HW enginner to trace every operation to and from HW,
//  e.g IO, Tx, Rx.
//
//  2.  DBG_WARNNING and DBG_SERIOUS are used for unusual or error cases,
//  which help us to debug SW or HW.
//
//-----------------------------------------------------------------------------
//
//  Never used in a call to ODM_RT_TRACE()!
//
#define ODM_DBG_OFF                                     1

//
//  Fatal bug.
//  For example, Tx/Rx/IO locked up, OS hangs, memory access violation,
//  resource allocation failed, unexpected HW behavior, HW BUG and so on.
//
#define ODM_DBG_SERIOUS                             2

//
//  Abnormal, rare, or unexpeted cases.
//  For example, IRP/Packet/OID canceled, device suprisely unremoved and so on.
//
#define ODM_DBG_WARNING                             3

//
//  Normal case with useful information about current SW or HW state.
//  For example, Tx/Rx descriptor to fill, Tx/Rx descriptor completed status,
//  SW protocol state change, dynamic mechanism state change and so on.
//
#define ODM_DBG_LOUD                                    4

//
//  Normal case with detail execution flow or information.
//
#define ODM_DBG_TRACE                                   5

//-----------------------------------------------------------------------------
// Define the tracing components
//
//-----------------------------------------------------------------------------
//BB Functions
#define PHYDM_COMP_RA_DBG        BIT0
#define PHYDM_COMP_MU            BIT1
#define PHYDM_COMP_PATH_DIV      BIT2
#define PHYDM_COMP_PWR_TRAIN_DBG BIT3
#define PHYDM_COMP_RA_BF_DBG     BIT4
#define DBG_H2C                  BIT5
#define PHYDM_COMP_TXRPT         BIT6
#define PHYDM_COMP_MCCDM         BIT7
#define PHYDM_COMP_MUGROUPING            BIT8

//RA Function
#define PHYDM_COMP_RA_DBG_1      BIT8 //rate decision
#define PHYDM_COMP_RA_DBG_2      BIT9 //rate up
#define PHYDM_COMP_RA_DBG_3      BIT10 //rate down
#define PHYDM_COMP_RA_DBG_4      BIT11 //TBTT interrupt
#define PHYDM_COMP_RA_DBG_5      BIT12 //try result

#define PHYDM_COMP_H2CC2H_DBG    BIT14
#define PHYDM_COMP_ENV_MNTR      BIT15


enum phydm_dbg_comp {
	/*BB Driver Functions*/
	ODM_COMP_DIG                 = BIT(24),
	ODM_COMP_MP                  = BIT(25),
	ODM_COMP_CALIBRATION         = BIT(26),
	ODM_PHY_CONFIG               = BIT(28),
	ODM_COMP_INIT                = BIT(29),
	ODM_COMP_API                 = BIT(31),
};

/*------------------------Export Marco Definition---------------------------*/

#if (CONFIG_RATE_ADAPTIVE)
#define pr_debug(fmt, args...) drvprint(fmt, ## args)

#define PHYDM_DBG(dm, comp, fmt, args...)			\
	do {							\
		if ((comp) & (dm->debug_components)) {          \
			drvprint(fmt, ## args);				\
		}						\
	} while (0)


#define ODM_RT_TRACE(dm, comp, level, fmt)\
    if(((comp) & dm->debug_components) && (level <= dm->debug_level || level == ODM_DBG_SERIOUS))\
    {\
        do { \
            drvprint fmt; \
        }while(0); \
    }

#define ODM_RT_dbg_code(comp, function, sub_1, sub2, val_1, val_2, val_3, val_4)\
            C2H_RA_Dbg_code(comp, function, sub_1, sub2, val_1, val_2, val_3, val_4);

#else
#define pr_debug(fmt, args...)
#define PHYDM_DBG(dm, comp, fmt, args...)
#define ODM_RT_TRACE(pPhydm_comn, comp, level, fmt)
#define ODM_RT_dbg_code(comp, function,sub_1, sub2, val_1, val_2, val_3, val_4)
#endif


VOID
PHYDM_InitDebugSetting(void);

#endif  // __ODM_DBG_H__

