/*
 * Copyright (C) 2015-2017 Alibaba Group Holding Limited
 */
#ifndef __AOS_OSDEP_SERVICE_H_
#define __AOS_OSDEP_SERVICE_H_

#include "dlist.h"
#include <kernel.h>
//#include <k_api.h>
// --------------------------------------------
//	Platform dependent include file
// --------------------------------------------
#if defined(CONFIG_PLATFORM_8711B)
#include "platform_stdlib.h"
#elif defined(CONFIG_PLATFORM_8721D)
#include "platform_stdlib.h"
#else
// other MCU may use standard library
#include <string.h>
#endif

#define configTICK_RATE_HZ				( ( uint32_t ) 1000 )


#define pvPortMalloc   _aos_zmalloc
#define vPortFree           _aos_mfree



// os types
typedef char			osdepCHAR;
typedef float			osdepFLOAT;
typedef double			osdepDOUBLE;
typedef long			osdepLONG;
typedef short			osdepSHORT;
typedef unsigned long	osdepSTACK_TYPE;
typedef long			osdepBASE_TYPE;
typedef unsigned long	osdepTickType;
typedef unsigned long long tick_t;
typedef unsigned long long sys_time_t;
typedef unsigned int        systime;


#define  save_and_cli() 	do{ u32 cpsr; cpsr = cpu_intrpt_save()
#define  restore_flags() 	cpu_intrpt_restore(cpsr);} while(0)



#undef _thread_hdl_
typedef struct {
	void *hdl;
} _thread_hdl_;

#undef _timerHandle
typedef struct {
	void *hdl;
} _timer_hdl_;

typedef struct {
	_timer_hdl_  timer;
	char *q_buf;

} timerHandle, *_timerHandle;


typedef aos_sem_t	_sema;
typedef aos_mutex_t	_mutex;
typedef void 	*_lock;
typedef void	*_queueHandle;
typedef void	*_xqueue;

typedef struct timer_list	_timer;

typedef	struct sk_buff		_pkt;
typedef unsigned char		_buffer;

struct	__queue	{
	struct	list_head	queue;
	_lock			lock;
};

typedef struct	__queue		_queue;
typedef struct	list_head	_list;
typedef u32		_irqL;


typedef struct {
#if (RHINO_CONFIG_CPU_NUM > 1)
	volatile uint32_t owner;  /* cpu index of owner */
#endif
	u32        cpsr;   /* the interrupt key for this lock */
} kspinlock_t;

#define krhino_spin_lock_irq_save(lock)      do {                                       \
                                                 kspinlock_t *s = (kspinlock_t *)(lock);\
                                                 s->cpsr        = cpu_intrpt_save();    \
                                             } while (0)

#define krhino_spin_unlock_irq_restore(lock) do {                                       \
                                                 kspinlock_t *s = (kspinlock_t *)(lock);\
                                                 cpu_intrpt_restore(s->cpsr);           \
                                             } while (0)

#define krhino_spin_lock_init(lock)

//typedef void*			_thread_hdl_;
typedef void			thread_return;
typedef void			*thread_context;

#if !defined(CONFIG_PLATFORM_8710C)
typedef struct {
	volatile int counter;
} atomic_t;
#endif
#define ATOMIC_T atomic_t
#define HZ configTICK_RATE_HZ

#define RHINO_WAIT_FOREVER ((tick_t)-1)


#define   KERNEL_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))
/* emulate a modern version */
#define LINUX_VERSION_CODE KERNEL_VERSION(2, 6, 17)

static __inline _list *get_next(_list	*list)
{
	return list->next;
}

static __inline _list	*get_list_head(_queue	*queue)
{
	return (&(queue->queue));
}

#define LIST_CONTAINOR(ptr, type, member) \
	((type *)((char *)(ptr)-(SIZE_T)((char *)&((type *)ptr)->member - (char *)ptr)))
//#define container_of(p,t,n) (t*)((p)-&(((t*)0)->n))
#define container_of(ptr, type, member) \
			((type *)((char *)(ptr)-(SIZE_T)(&((type *)0)->member)))
#define TASK_PRORITY_LOW  				1
#define TASK_PRORITY_MIDDLE   			2
#define TASK_PRORITY_HIGH    			3
#define TASK_PRORITY_SUPER    			4

#define TIMER_MAX_DELAY    				0xFFFFFFFF



#ifndef mdelay
#define mdelay(t)					((t/portTICK_RATE_MS)>0)?(vTaskDelay(t/portTICK_RATE_MS)):(vTaskDelay(1))
#endif

#ifndef udelay
#define udelay(t)					((t/(portTICK_RATE_MS*1000))>0)?vTaskDelay(t/(portTICK_RATE_MS*1000)):(vTaskDelay(1))
#endif
//----- ------------------------------------------------------------------
// Common Definition
//----- ------------------------------------------------------------------



#define __init
#define __exit
#define __devinit
#define __devexit

#define KERN_ERR
#define KERN_INFO
#define KERN_NOTICE

#undef GFP_KERNEL
#define GFP_KERNEL			1
#define GFP_ATOMIC			1

#define SET_MODULE_OWNER(some_struct)	do { } while (0)
#define SET_NETDEV_DEV(dev, obj)	do { } while (0)
#define register_netdev(dev)		(0)
#define unregister_netdev(dev)		do { } while (0)
#define netif_queue_stopped(dev)	(0)
#define netif_wake_queue(dev)		do { } while (0)
#define printk				printf




#define DBG_ERR(fmt, args...)		printf("\n\r[%s] " fmt, __FUNCTION__, ## args)

#if defined(WLAN_INTF_DBG) && WLAN_INTF_DBG
#define DBG_TRACE(fmt, args...)		printf("\n\r[%s] " fmt, __FUNCTION__, ## args)
#define DBG_INFO(fmt, args...)		printf("\n\r[%s] " fmt, __FUNCTION__, ## args)
#else
#define DBG_TRACE(fmt, args...)
#define DBG_INFO(fmt, args...)
#endif
#define HALT()				do { cli(); for(;;);} while(0)
#undef ASSERT
#define ASSERT(x)			do { \
						if((x) == 0){\
							printf("\n\rAssert(" #x ") failed on line %d in file %s", __LINE__, __FILE__); \
						HALT();}\
					} while(0)

#undef DBG_ASSERT
#define DBG_ASSERT(x, msg)		do { \
						if((x) == 0) \
							printf("\n\r%s, Assert(" #x ") failed on line %d in file %s", msg, __LINE__, __FILE__); \
					} while(0)


//----- ------------------------------------------------------------------
// Atomic Operation
//----- ------------------------------------------------------------------

/*
 * atomic_read - read atomic variable
 * @v: pointer of type atomic_t
 *
 * Atomically reads the value of @v.  Note that the guaranteed
 * useful range of an atomic_t is only 24 bits.
 */
#undef atomic_read
#define atomic_read(v)  ((v)->counter)

/*
 * atomic_set - set atomic variable
 * @v: pointer of type atomic_t
 * @i: required value
 *
 * Atomically sets the value of @v to @i.  Note that the guaranteed
 * useful range of an atomic_t is only 24 bits.
 */
#undef atomic_set
#define atomic_set(v,i) ((v)->counter = (i))

/*
 *      These inlines deal with timer wrapping correctly. You are
 *      strongly encouraged to use them
 *      1. Because people otherwise forget
 *      2. Because if the timer wrap changes in future you wont have to
 *         alter your driver code.
 *
 * time_after(a,b) returns true if the time a is after time b.
 *
 * Do this with "<0" and ">=0" to only test the sign of the result. A
 * good compiler would generate better code (and a really good compiler
 * wouldn't care). Gcc is currently neither.
 */
#define time_after(a,b)	((long)(b) - (long)(a) < 0)
#define time_before(a,b)	time_after(b,a)

#define time_after_eq(a,b)	((long)(a) - (long)(b) >= 0)
#define time_before_eq(a,b)	time_after_eq(b,a)


extern void	rtw_init_listhead(_list *list);
extern u32	rtw_is_list_empty(_list *phead);
extern void	rtw_list_insert_head(_list *plist, _list *phead);
extern void	rtw_list_insert_tail(_list *plist, _list *phead);
extern void	rtw_list_delete(_list *plist);

extern int rtw_if_wifi_thread(char *name);

#if (defined CONFIG_PLATFORM_8711B) || (defined CONFIG_PLATFORM_8721D)
extern u32 random_seed;
#endif
#endif


