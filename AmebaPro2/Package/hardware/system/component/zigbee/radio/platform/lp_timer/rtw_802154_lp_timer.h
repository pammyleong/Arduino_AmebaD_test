
/**
 * @brief Module that defines the Low Power Timer Abstraction Layer for the 802.15.4 driver.
 *
 */

#ifndef RTW_802154_LP_TIMER_API_H_
#define RTW_802154_LP_TIMER_API_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup rtw_802154_timer Low Power Timer Abstraction Layer for the 802.15.4 driver
 * @{
 * @ingroup rtw_802154_timer
 * @brief Low Power Timer Abstraction Layer interface for the 802.15.4 driver.
 *
 * The Low Power Timer Abstraction Layer is an abstraction layer of the timer that is meant
 * to be used by the Realtek 802.15.4 driver. This timer is intended to provide low latency
 * (max. 100 microseconds) to allow the implementation of the following features in the driver code:
 * * Timing out when waiting for an ACK frame
 * * SIFS and LIFS
 * * CSMA/CA
 * * CSL
 * * Auto polling by rx-off-when-idle devices
 *
 * @note Most of the Low Power Timer Abstraction Layer API is not intended to be called directly
 *       by the 802.15.4 driver modules. This API is used by the Timer Scheduler module included
 *       in the driver. Other modules should use the Timer Scheduler API. The exception are
 *       initialization and deinitialization functions @ref rtw_802154_lp_timer_init() and
 *       @ref rtw_802154_lp_timer_deinit(), as well as critical section management
 *       @ref rtw_802154_lp_timer_critical_section_enter() and
 *       @ref rtw_802154_lp_timer_critical_section_exit(), as these functions are called from
 *       the rtw_802154_critical_section module and from the global initialization
 *       and deinitialization functions @ref rtw_802154_init() and @ref rtw_802154_deinit().
 */

/**
 * @brief Initializes the Timer.
 */
void rtw_802154_lp_timer_init(void);

/**
 * @brief Deinitializes the Timer.
 */
void rtw_802154_lp_timer_deinit(void);

/**
 * @brief Enters the critical section of the timer.
 *
 * In the critical section, the timer cannot execute the @ref rtw_802154_lp_timer_fired() function.
 *
 * @note The critical section cannot be nested.
 *
 */
void rtw_802154_lp_timer_critical_section_enter(void);

/**
 * @brief Exits the critical section of the timer.
 *
 * In the critical section, the timer cannot execute the @ref rtw_802154_lp_timer_fired() function.
 *
 * @note The critical section cannot be nested.
 */
void rtw_802154_lp_timer_critical_section_exit(void);

/**
 * @brief Gets the current time.
 *
 * @pre Before getting the current time, the timer must be initialized with
 * @ref rtw_802154_lp_timer_init(). This is the only requirement that must be met before using this
 * function.
 *
 * @returns Current time in microseconds.
 */
uint32_t rtw_802154_lp_timer_time_get(void);

/**
 * @brief Gets the granularity of the timer.
 *
 * This function can be used to round up or round down the time calculations.
 *
 * @returns Timer granularity in microseconds.
 */
uint32_t rtw_802154_lp_timer_granularity_get(void);

/**
 * @brief Starts a one-shot timer that expires at the specified time.
 *
 * This function starts a one-shot timer that will expire @p dt microseconds after @p t0 time.
 * If the timer is running when this function is called, the running timer is stopped
 * automatically.
 *
 * On timer expiration, the @ref rtw_802154_lp_timer_fired function will be called.
 * The timer stops automatically after the expiration.
 *
 * @param[in]  t0  Number of microseconds representing timer start time.
 * @param[in]  dt  Time of the timer expiration as time elapsed from @p t0, in microseconds.
 */
void rtw_802154_lp_timer_start(uint32_t t0, uint32_t dt);

/**
 * @brief Stops the currently running timer.
 */
void rtw_802154_lp_timer_stop(void);

/**
 * @brief Checks if the timer is currently running.
 *
 * @retval  true   Timer is running.
 * @retval  false  Timer is not running.
 */
bool rtw_802154_lp_timer_is_running(void);


/**
 * @brief Callback function executed when the timer expires.
 */
extern void rtw_802154_lp_timer_fired(void);


/**
 *@}
 **/

#ifdef __cplusplus
}
#endif

#endif /* RTW_802154_LP_TIMER_API_H_ */
