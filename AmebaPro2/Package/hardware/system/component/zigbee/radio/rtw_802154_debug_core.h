/* Copyright (c) 2017 - 2019, Realtek
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this
 *      list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *
 *   3. Neither the name of Realtek nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * @brief Module that contains debug helpers for the 802.15.4 radio driver for the Realtek SoC devices.
 *
 */

#ifndef RTW_802154_DEBUG_CORE_H_
#define RTW_802154_DEBUG_CORE_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RTW_802154_DEBUG_LOG_BUFFER_LEN 1024

#define EVENT_TRACE_ENTER               0x0001UL
#define EVENT_TRACE_EXIT                0x0002UL

#define PIN_DBG_TIMESLOT_ACTIVE         3
#define PIN_DBG_TIMESLOT_EXTEND_REQ     4
#define PIN_DBG_TIMESLOT_SESSION_IDLE   16
#define PIN_DBG_TIMESLOT_RADIO_IRQ      28
#define PIN_DBG_TIMESLOT_FAILED         29
#define PIN_DBG_TIMESLOT_BLOCKED        30
#define PIN_DBG_RAAL_CRITICAL_SECTION   15

#define PIN_DBG_RTC0_EVT_REM            31

#define RTW_802154_DEBUG_CORE_PINS_USED 0

#ifndef DEBUG_VERBOSITY
#define DEBUG_VERBOSITY 1
#endif

#if ENABLE_DEBUG_LOG
extern volatile uint32_t rtw_802154_debug_log_buffer[
	 RTW_802154_DEBUG_LOG_BUFFER_LEN];
extern volatile uint32_t rtw_802154_debug_log_ptr;

#define rtw_802154_log(EVENT_CODE, EVENT_ARG)                                    \
    do                                                                           \
    {                                                                            \
        uint32_t ptr = rtw_802154_debug_log_ptr;                                 \
                                                                                 \
        rtw_802154_debug_log_buffer[ptr] = ((EVENT_CODE) | ((EVENT_ARG) << 16)); \
        rtw_802154_debug_log_ptr         =                                       \
            ptr < (RTW_802154_DEBUG_LOG_BUFFER_LEN - 1) ? ptr + 1 : 0;           \
    }                                                                            \
    while (0)

#else // ENABLE_DEBUG_LOG

#define rtw_802154_log(EVENT_CODE, EVENT_ARG)
//printf("%x %x\r\n",EVENT_CODE,EVENT_ARG)

#endif // ENABLE_DEBUG_LOG

#define rtw_802154_log_entry(function, verbosity)                     \
    do                                                                \
    {                                                                 \
         {                                                             \
            rtw_802154_log(EVENT_TRACE_ENTER, FUNCTION_ ## function); \
        }                                                             \
    }                                                                 \
    while (0)

#define rtw_802154_log_exit(function, verbosity)                     \
    do                                                               \
    {                                                                \
        {                                                            \
            rtw_802154_log(EVENT_TRACE_EXIT, FUNCTION_ ## function); \
        }                                                            \
    }                                                                \
    while (0)

#define rtw_802154_pin_set(pin)
#define rtw_802154_pin_clr(pin)
#define rtw_802154_pin_tgl(pin)

/**
 * @brief Initializes debug helpers for the Realtek 802.15.4 driver.
 */
void rtw_802154_debug_init(void);

#ifdef __cplusplus
}
#endif

#endif /* RTW_802154_DEBUG_CORE_H_ */
