
/**************************************************************************//**
 * @file     vectors_rtl8195blp.h
 * @brief    This the interrupt handler implementation header file.
 *           
 * @version  V1.00
 * @date     2016-05-17
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2016 Realtek Corporation. All rights reserved.
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
 ******************************************************************************/

#ifndef _RTL8195B_VOE_CC_COMMAND_H_
#define _RTL8195B_VOE_CC_COMMAND_H_

// TM9 <--> KM4 command 30 bit
// command 14 bit 0x3FFF0000
#define FW_INITIAL_ITCM_CMD                 0x1
#define FW_INITIAL_DTCM_CMD                 0x2
#define FW_INITIAL_ERROR_CMD                0x3
#define FW_INITIAL_ITCM_DONE_CMD            0x4
#define FW_INITIAL_DTCM_DONE_CMD            0x5
#define FW_DUMP_ITCM_CMD                    0x6
#define FW_DUMP_DTCM_CMD                    0x7
#define FW_REBOOT_CMD                       0x8
#define FW_DUMP_COMPILE_TIME_CMD            0x9
#define FW_DUMP_COMPILE_TIME_DONE_CMD       0xA
#define FW_DUMP_IMAGE_STATE_CMD             0xB
#define FW_DUMP_IMAGE_STATE_DONE_CMD        0xC
#define FW_REBOOT_DONE_CMD                  0xD
#define FW_VERIFY_DTCM_PATTERN_1_CMD        0xE
#define FW_VERIFY_DTCM_PATTERN_2_CMD        0xF
#define FW_CHECK_PATTERN_1_CMD              0x10
#define FW_CHECK_PATTERN_2_CMD              0x11
#define FW_BOOT_DONE_CMD                    0x12

// ERAC set
#define FW_RET_ERAC_OK                      0x100		// KM --> TM
#define FW_RET_ERAC_ERR                     0x1FF		// KM --> TM

#define FW_ERAC_INIT_CMD                    0x110
#define FW_ERAC_WRITE_CMD                   0x120
#define FW_ERAC_READ_CMD                    0x130


// ISP/H264 set
#define FW_RET_OK                           0x005		// KM --> TM

#define FW_SEND_BUF_CMD						0x210		// Send ISP/H264 buffer address to VOE engine

#define FW_H264_SCH_CMD						0x220		//  VOE Scheduler setting
#define FW_H264_BPS_CMD						0x230		//  Dynamic Bit rate setting


#define FW_H264_READY_OK                    0x245		// KM --> TM
#define FW_H264_IDR_CMD						0x250		// Send IDR header to VOE engine

#define FW_H264_RELEASE_CMD					0x260		// release h264 slot


#define FW_H264_START_CMD					0x2A0		// Start VOE engine encode H264
#define FW_H264_STOP_CMD					0x2B0		// Stop VOE engine encode H264

#define FW_TEST_CMD							0x2c0		// Test command

#define FW_RET_ISR_OK                       0x200		// KM --> TM



#define FW_KM_ISR_H264                      0x3201



#define FW_PROC_ERROR_RET                   0x3FFF



#define FW_CMD_INIT                         0x00
#define FW_CMD_ERAC                         0x01
#define FW_CMD_ISR                          0x02
#define FW_KM_ISR                           0x32    


#define PARSE_TM_CMD(cmd)               ((cmd & 0x3FFF0000)>>16)
#define PARSE_TM_CMD_PAYLOAD(cmd)       (cmd & 0xFFFF)
#define COMBINE_MESSAGE(cmd, payload)   (((cmd&0x3FFF) << 16) | payload)

#define WORK_PATTERN_1                      0x5A5A5A5A
#define WORK_PATTERN_2                      0x11223344




#define VOE_RECEIVE_CMD_BUSY    0x01
#define VOE_SEND_CMD_BUSY       0x02       
#define VOE_CMD_TYPE_UNKNOWN    0x04
#define VOE_H264ISR_BUSY        0x08



#endif
