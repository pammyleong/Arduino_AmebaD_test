/**************************************************************************//**
 * @file     sys_api_ext.h
 * @brief    System API Extension.
 * @version  v1.00
 * @date     2020/07/15
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#ifndef SYS_API_EXT_H
#define SYS_API_EXT_H

struct sys_stack_reg_t{
    uint32_t R0;
	uint32_t R1;
	uint32_t R2;
	uint32_t R3;
	uint32_t R12;
	uint32_t LR;
	uint32_t PC;
	uint32_t PSR;
};

/** 
 *  @brief Dump register for debug purpose when watchdog interrupt handler triggered.
 *  @details For debug purpose, user may want to dump some registers when watchdog handler triggered.
 *             Please use this api in watchdog handler and get the dumped register with sys_stack_reg_t structure.
 *  @param[in]   data  Dumped register would store in this data variable with sys_stack_reg_t structure.
 *  @return      void
 */
void wdt_debug_reg_dump(struct sys_stack_reg_t *data);
#endif 


