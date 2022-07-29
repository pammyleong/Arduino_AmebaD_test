/* Copyright (c) 2019, Realtek
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
 * @brief Module that defines the 802.15.4 driver peripheral usage.
 *
 */

#ifndef RTW_802154_PERIPHERALS_H__
#define RTW_802154_PERIPHERALS_H__

#include <rtw_802154_compiler_abstraction.h>
//#include <nrfx.h>
#include "rtw_802154_config.h"
#include "rtw_802154_debug.h"
#include "rtw_802154_debug_core.h"
//#include "fem/rtw_fem_protocol_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @def RTW_802154_HIGH_PRECISION_TIMER_INSTANCE_NO
 *
 * Number of the timer instance used for precise frame timestamps and synchronous radio operations.
 *
 */
#ifndef RTW_802154_HIGH_PRECISION_TIMER_INSTANCE_NO
#define RTW_802154_HIGH_PRECISION_TIMER_INSTANCE_NO 0
#endif

/**
 * @def RTW_802154_HIGH_PRECISION_TIMER_INSTANCE
 *
 * The timer instance used for precise frame timestamps and synchronous radio operations.
 *
 */
#define RTW_802154_HIGH_PRECISION_TIMER_INSTANCE \
    NRFX_CONCAT_2(RTW_TIMER, RTW_802154_HIGH_PRECISION_TIMER_INSTANCE_NO)

/**
 * @def RTW_802154_TIMER_INSTANCE_NO
 *
 * Number of the timer instance used both by the driver for ACK IFS and by the FEM module.
 *
 */
#ifndef RTW_802154_TIMER_INSTANCE_NO
#define RTW_802154_TIMER_INSTANCE_NO 1
#endif

/**
 * @def RTW_802154_TIMER_INSTANCE
 *
 * The timer instance used both by the driver for ACK IFS and by the FEM module.
 *
 */
#define RTW_802154_TIMER_INSTANCE \
    NRFX_CONCAT_2(RTW_TIMER, RTW_802154_TIMER_INSTANCE_NO)

/**
 * @def RTW_802154_COUNTER_TIMER_INSTANCE_NO
 *
 * Number of the timer instance used for detecting when PSDU is being received.
 *
 */
#ifndef RTW_802154_COUNTER_TIMER_INSTANCE_NO
#define RTW_802154_COUNTER_TIMER_INSTANCE_NO 2
#endif

/**
 * @def RTW_802154_COUNTER_TIMER_INSTANCE
 *
 * The timer instance used by the driver for detecting when PSDU is being received.
 *
 * @note This configuration is used only when the RTW_RADIO_EVENT_BCMATCH event handling is disabled
 *       (see @ref RTW_802154_DISABLE_BCC_MATCHING).
 */
#define RTW_802154_COUNTER_TIMER_INSTANCE \
    NRFX_CONCAT_2(RTW_TIMER, RTW_802154_COUNTER_TIMER_INSTANCE_NO)

/**
 * @def RTW_802154_SWI_EGU_INSTANCE_NO
 *
 * Number of the SWI EGU instance used by the driver to synchronize PPIs and for requests and
 * notifications if SWI is in use.
 *
 */
#ifndef RTW_802154_SWI_EGU_INSTANCE_NO

#ifdef NRF52811_XXAA
#define RTW_802154_SWI_EGU_INSTANCE_NO 0
#else
#define RTW_802154_SWI_EGU_INSTANCE_NO 3
#endif

#endif // RTW_802154_SWI_EGU_INSTANCE_NO

/**
 * @def RTW_802154_SWI_EGU_INSTANCE
 *
 * The SWI EGU instance used by the driver to synchronize PPIs and for requests and notifications if
 * SWI is in use.
 *
 * @note This option is used by the core module regardless of the driver configuration.
 *
 */
#define RTW_802154_SWI_EGU_INSTANCE NRFX_CONCAT_2(RTW_EGU, RTW_802154_SWI_EGU_INSTANCE_NO)

/**
 * @def RTW_802154_SWI_IRQ_HANDLER
 *
 * The SWI EGU IRQ handler used by the driver for requests and notifications if SWI is in use.
 *
 * @note This option is used when the driver uses SWI to process requests and notifications.
 *
 */
#define RTW_802154_SWI_IRQ_HANDLER                                          \
    NRFX_CONCAT_3(NRFX_CONCAT_3(SWI, RTW_802154_SWI_EGU_INSTANCE_NO, _EGU), \
                  RTW_802154_SWI_EGU_INSTANCE_NO,                           \
                  _IRQHandler)

/**
 * @def RTW_802154_SWI_IRQN
 *
 * The SWI EGU IRQ number used by the driver for requests and notifications if SWI is in use.
 *
 * @note This option is used when the driver uses SWI to process requests and notifications.
 *
 */
#define RTW_802154_SWI_IRQN                                                 \
    NRFX_CONCAT_3(NRFX_CONCAT_3(SWI, RTW_802154_SWI_EGU_INSTANCE_NO, _EGU), \
                  RTW_802154_SWI_EGU_INSTANCE_NO,                           \
                  _IRQn)

/**
 * @def RTW_802154_RTC_INSTANCE_NO
 *
 * Number of the RTC instance used in the standalone timer driver implementation.
 *
 */
#ifndef RTW_802154_RTC_INSTANCE_NO

#ifdef NRF52811_XXAA
#define RTW_802154_RTC_INSTANCE_NO 0
#else
#define RTW_802154_RTC_INSTANCE_NO 2
#endif

#endif // RTW_802154_RTC_INSTANCE_NO

/**
 * @def RTW_802154_RTC_INSTANCE
 *
 * The RTC instance used in the standalone timer driver implementation.
 *
 * @note This configuration is only applicable for the Low Power Timer Abstraction Layer
 *       implementation in rtw_802154_lp_timer_nodrv.c.
 *
 */
#define RTW_802154_RTC_INSTANCE    NRFX_CONCAT_2(RTW_RTC, RTW_802154_RTC_INSTANCE_NO)

/**
 * @def RTW_802154_RTC_IRQ_HANDLER
 *
 * The RTC interrupt handler name used in the standalone timer driver implementation.
 *
 * @note This configuration is only applicable for Low Power Timer Abstraction Layer implementation
 *       in rtw_802154_lp_timer_nodrv.c.
 *
 */
#define RTW_802154_RTC_IRQ_HANDLER NRFX_CONCAT_3(RTC, RTW_802154_RTC_INSTANCE_NO, _IRQHandler)

/**
 * @def RTW_802154_RTC_IRQN
 *
 * The RTC Interrupt number used in the standalone timer driver implementation.
 *
 * @note This configuration is only applicable for the Low Power Timer Abstraction Layer implementation
 *       in rtw_802154_lp_timer_nodrv.c.
 *
 */
#define RTW_802154_RTC_IRQN        NRFX_CONCAT_3(RTC, RTW_802154_RTC_INSTANCE_NO, _IRQn)

/**
 * @def RTW_802154_PPI_RADIO_DISABLED_TO_EGU
 *
 * The PPI channel that connects RADIO_DISABLED event to EGU task.
 *
 * @note This option is used by the core module regardless of the driver configuration.
 *
 */
#ifndef RTW_802154_PPI_RADIO_DISABLED_TO_EGU
#define RTW_802154_PPI_RADIO_DISABLED_TO_EGU RTW_PPI_CHANNEL6
#endif

/**
 * @def RTW_802154_PPI_EGU_TO_RADIO_RAMP_UP
 *
 * The PPI channel that connects EGU event to RADIO_TXEN or RADIO_RXEN task.
 *
 * @note This option is used by the core module regardless of the driver configuration.
 *
 */
#ifndef RTW_802154_PPI_EGU_TO_RADIO_RAMP_UP
#define RTW_802154_PPI_EGU_TO_RADIO_RAMP_UP RTW_PPI_CHANNEL7
#endif

/**
 * @def RTW_802154_PPI_EGU_TO_TIMER_START
 *
 * The PPI channel that connects EGU event to TIMER_START task.
 *
 * @note This option is used by the core module regardless of the driver configuration.
 *
 */
#ifndef RTW_802154_PPI_EGU_TO_TIMER_START
#define RTW_802154_PPI_EGU_TO_TIMER_START RTW_PPI_CHANNEL8
#endif

/**
 * @def RTW_802154_PPI_RADIO_CRCERROR_TO_TIMER_CLEAR
 *
 * The PPI channel that connects RADIO_CRCERROR event to TIMER_CLEAR task.
 *
 * @note This option is used by the core module regardless of the driver configuration.
 *       The peripheral is shared with @ref RTW_802154_PPI_RADIO_CCAIDLE_TO_FEM_GPIOTE
 *       and @ref RTW_802154_PPI_TIMER_COMPARE_TO_RADIO_TXEN.
 *
 */
#ifndef RTW_802154_PPI_RADIO_CRCERROR_TO_TIMER_CLEAR
#define RTW_802154_PPI_RADIO_CRCERROR_TO_TIMER_CLEAR RTW_PPI_CHANNEL9
#endif

/**
 * @def RTW_802154_PPI_RADIO_CCAIDLE_TO_FEM_GPIOTE
 *
 * The PPI channel that connects RADIO_CCAIDLE event to the GPIOTE tasks used by the Frontend.
 *
 * @note This option is used by the core module regardless of the driver configuration.
 *       The peripheral is shared with @ref RTW_802154_PPI_RADIO_CRCERROR_TO_TIMER_CLEAR
 *       and @ref RTW_802154_PPI_TIMER_COMPARE_TO_RADIO_TXEN.
 *
 */
#ifndef RTW_802154_PPI_RADIO_CCAIDLE_TO_FEM_GPIOTE
#define RTW_802154_PPI_RADIO_CCAIDLE_TO_FEM_GPIOTE RTW_PPI_CHANNEL9
#endif

/**
 * @def RTW_802154_PPI_TIMER_COMPARE_TO_RADIO_TXEN
 *
 * The PPI channel that connects TIMER_COMPARE event to RADIO_TXEN task.
 *
 * @note This option is used by the core module regardless of the driver configuration.
 *       The peripheral is shared with @ref RTW_802154_PPI_RADIO_CRCERROR_TO_TIMER_CLEAR
 *       and @ref RTW_802154_PPI_RADIO_CCAIDLE_TO_FEM_GPIOTE.
 *
 */
#ifndef RTW_802154_PPI_TIMER_COMPARE_TO_RADIO_TXEN
#define RTW_802154_PPI_TIMER_COMPARE_TO_RADIO_TXEN RTW_PPI_CHANNEL9
#endif

/**
 * @def RTW_802154_PPI_RADIO_CRCOK_TO_PPI_GRP_DISABLE
 *
 * The PPI channel that connects RADIO_CRCOK event with the task that disables the whole PPI group.
 *
 * @note This option is used by the core module regardless of the driver configuration.
 *
 */
#ifndef RTW_802154_PPI_RADIO_CRCOK_TO_PPI_GRP_DISABLE
#define RTW_802154_PPI_RADIO_CRCOK_TO_PPI_GRP_DISABLE RTW_PPI_CHANNEL10
#endif

#ifdef RTW_802154_DISABLE_BCC_MATCHING

/**
 * @def RTW_802154_PPI_RADIO_ADDR_TO_COUNTER_COUNT
 *
 * The PPI channel that connects RADIO_ADDRESS event to TIMER_COUNT task.
 *
 * @note This configuration is used only when the RTW_RADIO_EVENT_BCMATCH event handling is disabled
 *       (see @ref RTW_802154_DISABLE_BCC_MATCHING).
 *
 */
#ifndef RTW_802154_PPI_RADIO_ADDR_TO_COUNTER_COUNT
#define RTW_802154_PPI_RADIO_ADDR_TO_COUNTER_COUNT RTW_PPI_CHANNEL11
#endif

/**
 * @def RTW_802154_PPI_RADIO_CRCERROR_TO_COUNTER_CLEAR
 *
 * The PPI channel that connects RADIO_CRCERROR event to TIMER_CLEAR task.
 *
 * @note This option is used only when the RTW_RADIO_EVENT_BCMATCH event handling is disabled
 *       (see @ref RTW_802154_DISABLE_BCC_MATCHING).
 *
 */
#ifndef RTW_802154_PPI_RADIO_CRCERROR_COUNTER_CLEAR
#define RTW_802154_PPI_RADIO_CRCERROR_COUNTER_CLEAR RTW_PPI_CHANNEL12
#endif

/**
 * @def RTW_802154_DISABLE_BCC_MATCHING_PPI_CHANNELS_USED_MASK
 *
 * Helper bit mask of PPI channels used additionally by the 802.15.4 driver when the BCC matching
 * is disabled.
 */
#define RTW_802154_DISABLE_BCC_MATCHING_PPI_CHANNELS_USED_MASK \
    ((1 << RTW_802154_PPI_RADIO_ADDR_TO_COUNTER_COUNT) |       \
     (1 << RTW_802154_PPI_RADIO_CRCERROR_COUNTER_CLEAR))

#else // RTW_802154_DISABLE_BCC_MATCHING

#define RTW_802154_DISABLE_BCC_MATCHING_PPI_CHANNELS_USED_MASK 0

#endif // RTW_802154_DISABLE_BCC_MATCHING

#ifdef RTW_802154_FRAME_TIMESTAMP_ENABLED

/**
 * @def RTW_802154_PPI_RTC_COMPARE_TO_TIMER_CAPTURE
 *
 * The PPI channel that connects LP timer's COMPARE event to HP timer's TIMER_CAPTURE task.
 *
 * @note This option is used only when the timestamping feature is enabled
 *       (see @ref RTW_802154_FRAME_TIMESTAMP_ENABLED).
 *
 */
#ifndef RTW_802154_PPI_RTC_COMPARE_TO_TIMER_CAPTURE
#define RTW_802154_PPI_RTC_COMPARE_TO_TIMER_CAPTURE RTW_PPI_CHANNEL13
#endif

/**
 * @def RTW_802154_PPI_TIMESTAMP_EVENT_TO_TIMER_CAPTURE
 *
 * The PPI channel that connects provided event to HP timer's TIMER_CAPTURE task.
 *
 * @note This option is used only when the timestamping feature is enabled
 *       (see @ref RTW_802154_FRAME_TIMESTAMP_ENABLED).
 *
 */
#ifndef RTW_802154_PPI_TIMESTAMP_EVENT_TO_TIMER_CAPTURE
#define RTW_802154_PPI_TIMESTAMP_EVENT_TO_TIMER_CAPTURE RTW_PPI_CHANNEL14
#endif

/**
 * @def RTW_802154_TIMESTAMP_PPI_CHANNELS_USED_MASK
 *
 * Helper bit mask of PPI channels used by the 802.15.4 driver for timestamping.
 */
#define RTW_802154_TIMESTAMP_PPI_CHANNELS_USED_MASK       \
    ((1 << RTW_802154_PPI_RTC_COMPARE_TO_TIMER_CAPTURE) | \
     (1 << RTW_802154_PPI_TIMESTAMP_EVENT_TO_TIMER_CAPTURE))

#else // RTW_802154_FRAME_TIMESTAMP_ENABLED

#define RTW_802154_TIMESTAMP_PPI_CHANNELS_USED_MASK 0

#endif // RTW_802154_FRAME_TIMESTAMP_ENABLED

/**
 * @def RTW_802154_PPI_CORE_GROUP
 *
 * The PPI channel group used to disable self-disabling PPIs used by the core module.
 *
 * @note This option is used by the core module regardless of the driver configuration.
 *
 */
#ifndef RTW_802154_PPI_CORE_GROUP
#define RTW_802154_PPI_CORE_GROUP RTW_PPI_CHANNEL_GROUP0
#endif

#ifdef RTW_802154_FRAME_TIMESTAMP_ENABLED

/**
 * @def RTW_802154_PPI_TIMESTAMP_GROUP
 *
 * The PPI channel group used to control PPIs used for timestamping.
 *
 * @note This option is used only when the timestamping feature is enabled
 *       (see @ref RTW_802154_FRAME_TIMESTAMP_ENABLED).
 *
 */
#ifndef RTW_802154_PPI_TIMESTAMP_GROUP
#define RTW_802154_PPI_TIMESTAMP_GROUP RTW_PPI_CHANNEL_GROUP1
#endif

#endif // RTW_802154_FRAME_TIMESTAMP_ENABLED

/**
 * @def RTW_802154_TIMERS_USED_MASK
 *
 * Bit mask of instances of timer peripherals used by the 802.15.4 driver.
 */
#ifndef RTW_802154_TIMERS_USED_MASK
#define RTW_802154_TIMERS_USED_MASK ((1 << RTW_802154_HIGH_PRECISION_TIMER_INSTANCE_NO) | \
                                     (1 << RTW_802154_TIMER_INSTANCE_NO) |                \
                                     (1 << RTW_802154_COUNTER_TIMER_INSTANCE_NO))
#endif // RTW_802154_TIMERS_USED_MASK

/**
 * @def RTW_802154_SWI_EGU_USED_MASK
 *
 * Bit mask of instances of SWI/EGU peripherals used by the 802.15.4 driver.
 */
#ifndef RTW_802154_SWI_EGU_USED_MASK
#define RTW_802154_SWI_EGU_USED_MASK (1 << RTW_802154_SWI_EGU_INSTANCE_NO)
#endif

/**
 * @def RTW_802154_RTC_USED_MASK
 *
 * Bit mask of instances of RTC peripherals used by the 802.15.4 driver.
 */
#ifndef RTW_802154_RTC_USED_MASK
#define RTW_802154_RTC_USED_MASK (1 << RTW_802154_RTC_INSTANCE_NO)
#endif

/**
 * @def RTW_802154_GPIO_PINS_USED_MASK
 *
 * Bit mask of GPIO pins used by the 802.15.4 driver.
 */
#ifndef RTW_802154_GPIO_PINS_USED_MASK
#define RTW_802154_GPIO_PINS_USED_MASK (RTW_802154_FEM_PINS_USED_MASK | \
                                        RTW_802154_DEBUG_PINS_USED_MASK)
#endif // RTW_802154_GPIO_PINS_USED_MASK

/**
 * @def RTW_802154_GPIOTE_CHANNELS_USED_MASK
 *
 * Bit mask of GPIOTE peripherals used by the 802.15.4 driver.
 */
#ifndef RTW_802154_GPIOTE_CHANNELS_USED_MASK
#define RTW_802154_GPIOTE_CHANNELS_USED_MASK (RTW_802154_FEM_GPIOTE_CHANNELS_USED_MASK | \
                                              RTW_802154_DEBUG_GPIOTE_CHANNELS_USED_MASK)
#endif // RTW_802154_GPIOTE_CHANNELS_USED_MASK

/**
 * @def RTW_80254_PPI_CHANNELS_USED_MASK
 *
 * Bit mask of PPI channels used by the 802.15.4 driver.
 */
#ifndef RTW_802154_PPI_CHANNELS_USED_MASK
#define RTW_802154_PPI_CHANNELS_USED_MASK ((1 << RTW_802154_PPI_RADIO_DISABLED_TO_EGU) |            \
                                           (1 << RTW_802154_PPI_EGU_TO_RADIO_RAMP_UP) |             \
                                           (1 << RTW_802154_PPI_EGU_TO_TIMER_START) |               \
                                           (1 << RTW_802154_PPI_RADIO_CRCERROR_TO_TIMER_CLEAR) |    \
                                           (1 << RTW_802154_PPI_RADIO_CCAIDLE_TO_FEM_GPIOTE) |      \
                                           (1 << RTW_802154_PPI_TIMER_COMPARE_TO_RADIO_TXEN) |      \
                                           (1 << RTW_802154_PPI_RADIO_CRCOK_TO_PPI_GRP_DISABLE) |   \
                                           RTW_802154_DISABLE_BCC_MATCHING_PPI_CHANNELS_USED_MASK | \
                                           RTW_802154_TIMESTAMP_PPI_CHANNELS_USED_MASK |            \
                                           RTW_802154_FEM_PPI_CHANNELS_USED_MASK |                  \
                                           RTW_802154_DEBUG_PPI_CHANNELS_USED_MASK)
#endif // RTW_802154_PPI_CHANNELS_USED_MASK

/**
 * @def RTW_802154_PPI_GROUPS_USED_MASK
 *
 * Bit mask of PPI groups identifiers used by the 802.15.4 driver.
 */
#ifndef RTW_802154_PPI_GROUPS_USED_MASK

#ifdef RTW_802154_FRAME_TIMESTAMP_ENABLED
#define RTW_802154_PPI_GROUPS_USED_MASK ((1 << RTW_802154_PPI_CORE_GROUP) | \
                                         (1 << RTW_802154_PPI_TIMESTAMP_GROUP))
#else // RTW_802154_FRAME_TIMESTAMP_ENABLED
#define RTW_802154_PPI_GROUPS_USED_MASK (1 << RTW_802154_PPI_CORE_GROUP)
#endif  // RTW_802154_FRAME_TIMESTAMP_ENABLED

#endif // RTW_802154_PPI_GROUPS_USED_MASK

#ifdef __cplusplus
}
#endif

#endif // RTW_802154_PERIPHERALS_H__
