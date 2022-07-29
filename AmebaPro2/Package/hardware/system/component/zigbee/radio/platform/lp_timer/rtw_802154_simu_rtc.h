#ifndef RTW_802154_SIMU_RTC_H_
#define RTW_802154_SIMU_RTC_H_

#include <stdbool.h>
#include <stdint.h>
#include "basic_types.h"
#include "osdep_service.h"

#ifdef __cplusplus
extern "C" {
#endif


#define  USE_GTIMER_API  0
#define  USE_GTIMER_CALLBACK_TASK 1
#define  ALARM_MS_USE_GTIMER_INSTEAD_OF_OSTIMER 0
#define  AMEBA_SMART_TEST_CHIP   1
#define  ALARM_TIMER_PROCESS 1 //avoid TaskletScheduler::PostTasklet fail, alarm timer callback will run in thread task instead of irq or gtimer task if define 1
#if USE_GTIMER_API
#ifdef USE_GTIMER_CALLBACK_TASK
#undef USE_GTIMER_CALLBACK_TASK
#endif
/*because gtimer_stop called after callback_handler in gtimer_timeout_handler, but callback_handler will start gtimer, will fail if not stop firstly
so must enable USE_GTIMER_CALLBACK_TASK if enable gtimer api*/
#define  USE_GTIMER_CALLBACK_TASK 1
#endif

#if AMEBA_SMART_TEST_CHIP
//need enable TIM RCC_Config in ameba_bootcfg.c or call TIM enable func
#define  GTIMER_INDEX_SIMU_RTC  (0)   //Testchip TIM0~7 is 32k 
#define  GTIMER_INDEX_LP_TIMER  (1)
#define  GTIMER_INDEX_OT_US_TIMER  (2)
#define  GTIMER_INDEX_OT_MS_TIMER  (3)
#define  RTW_GTIMER_CLK   32768     //  32k 0x8000
#else
#define  GTIMER_INDEX_SIMU_RTC  (10)   //TIM10~13 is 1M 
#define  GTIMER_INDEX_LP_TIMER  (11)
#define  GTIMER_INDEX_OT_US_TIMER  (12)
#define  GTIMER_INDEX_OT_MS_TIMER  (0) //TODO: which TIM to use in normal
#define  RTW_GTIMER_CLK   1048576      //  1M 0x100000
#endif

//TODO: maybe use rtw_802154_utils.h better
#define RTW_802154_GTIMER_DIVIDE_AND_CEIL(A, B)       (((A) + (B)-1) / (B))
#define RTW_802154_GTIMER_TICKS_TO_US(ticks)  RTW_802154_GTIMER_DIVIDE_AND_CEIL((ticks) * 1000000, RTW_GTIMER_CLK)//(ticks * 1000000 / RTW_GTIMER_CLK)
#define RTW_HIGH_GTIMER_US_PER_TICK  RTW_802154_GTIMER_TICKS_TO_US((uint32_t)1)//if 1M clock, need to be 1
#define RTW_802154_GTIMER_US_TO_TICKS(us) RTW_802154_GTIMER_DIVIDE_AND_CEIL((us) * RTW_GTIMER_CLK, 1000000)//(us * RTW_GTIMER_CLK / 1000000)
//#define RTW_HIGH_GTIMER_TICK_PER_US  RTW_GTIMER_CLK / 1000000

#define RTW_SIMU_RTC_MAX_COUNT  (0xEFFFFFFF)//0xEFFFFFFF to avoid overflow if 1M
#if 0
#define TICKS_PER_OVERFLOW     (RTW_SIMU_RTC_MAX_COUNT+1)
#else
#define US_PER_OVERFLOW     RTW_SIMU_RTC_MAX_COUNT
#endif
#define EPOCH_32BIT_US               (1ULL << 32)
#define EPOCH_FROM_TIME(time)        ((time) & ((uint64_t)UINT32_MAX << 32))

//for Simulation RTC
typedef struct {
#if USE_GTIMER_API
	gtimer_t      mTimer;
#else
	uint8_t  m_simu_rtc_tid;
#endif
	volatile uint32_t mOverflowCounter;
} SimuRTCData, *pSimuRTCData;

#if USE_GTIMER_CALLBACK_TASK
typedef enum {
	RTW_GTIMER_LPTIMER = 0,
	RTW_GTIMER_ALARM_US,
	RTW_GTIMER_ALARM_MS,
	RTW_GTIMER_TASK_DEINIT,
} rtw_gtimer_callback_msg_type;

typedef struct {
	rtw_gtimer_callback_msg_type callback_type;
	void (*callback_func)(void *callback_para);
	void *callback_para;
} rtw_gtimer_callback_msg;

typedef struct {
	_xqueue gtimer_queue;
	struct task_struct gtimer_callback_task;
} rtw_gtimer_callback_t;
extern rtw_gtimer_callback_t rtw_gtimer_callback;
#endif

uint32_t rtw_802154_simu_rtc_get_current_tick(void);
uint64_t rtw_802154_simu_rtc_get_us(void);
uint64_t rtw_802154_simu_rtc_get_ms(void);
void rtw_802154_simu_rtc_init(void);
void rtw_802154_simu_rtc_deinit(void);
uint64_t ConvertT0AndDtTo64BitTime(uint32_t aT0, uint32_t aDt, const uint64_t aNow);

#ifdef __cplusplus
}
#endif

#endif /* RTW_802154_SIMU_RTC_H_ */

