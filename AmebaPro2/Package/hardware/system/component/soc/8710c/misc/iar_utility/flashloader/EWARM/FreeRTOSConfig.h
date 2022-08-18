/*
    The FreeRTOS kernel is released under the MIT open source license, the text of
    which is provided below.
    
    This license covers the FreeRTOS kernel source files, which are located in the
    /FreeRTOS/Source directory of the official FreeRTOS kernel download.  It also
    covers most of the source files in the demo application projects, which are
    located in the /FreeRTOS/Demo directory of the official FreeRTOS download.  The
    demo projects may also include third party software that is not part of FreeRTOS
    and is licensed separately to FreeRTOS.  Examples of third party software
    includes header files provided by chip or tools vendors, linker scripts,
    peripheral drivers, etc.  All the software in subdirectories of the /FreeRTOS
    directory is either open source or distributed with permission, and is free for
    use.  For the avoidance of doubt, refer to the comments at the top of each
    source file.
    
    
    License text:
    -------------
    
    Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION					1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	1
#define configUSE_QUEUE_SETS					1
#define configUSE_IDLE_HOOK						0
#define configUSE_TICK_HOOK						1
#define configCPU_CLOCK_HZ						( SystemCoreClock )
#define configTICK_RATE_HZ						( 1000 )
#define configMAX_PRIORITIES					( 11 )
#define configMINIMAL_STACK_SIZE				( ( unsigned short ) 130 )

#if defined(CONFIG_BUILD_SECURE)
#define configTOTAL_HEAP_SIZE					( ( size_t ) ( 20 * 1024 ) )
#elif defined(CONFIG_BUILD_NONSECURE)
#define configTOTAL_HEAP_SIZE					( ( size_t ) ( 50 * 1024 ) )
#else // ignore secure
#define configTOTAL_HEAP_SIZE					( ( size_t ) ( 120 * 1024 ) )
#endif

#define configMAX_TASK_NAME_LEN					( 10 )
#define configUSE_TRACE_FACILITY				1
#define configUSE_16_BIT_TICKS					0
#define configIDLE_SHOULD_YIELD					1
#define configUSE_MUTEXES						1
#define configQUEUE_REGISTRY_SIZE				8
#define configCHECK_FOR_STACK_OVERFLOW			2
#define configUSE_RECURSIVE_MUTEXES				1
#define configUSE_MALLOC_FAILED_HOOK			1
#define configUSE_APPLICATION_TASK_TAG			0
#define configUSE_COUNTING_SEMAPHORES			1
#define configUSE_TASK_NOTIFICATIONS            1

/* The full demo always has tasks to run so the tick will never be turned off.
The blinky demo will use the default tickless idle implementation to turn the
tick off. */
#define configUSE_TICKLESS_IDLE					0

/* Run time stats gathering definitions. */
#define configGENERATE_RUN_TIME_STATS	1
#if configGENERATE_RUN_TIME_STATS
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() //( ulHighFrequencyTimerTicks = 0UL )
#define portGET_RUN_TIME_COUNTER_VALUE() xTickCount //ulHighFrequencyTimerTicks
#undef	configUSE_TRACE_FACILITY
#define configUSE_TRACE_FACILITY			1
#define portCONFIGURE_STATS_PEROID_VALUE	1000 //unit Ticks
#endif 

/* This demo makes use of one or more example stats formatting functions.  These
format the raw data provided by the uxTaskGetSystemState() function in to human
readable ASCII form.  See the notes in the implementation of vTaskList() within
FreeRTOS/Source/tasks.c for limitations. */
#define configUSE_STATS_FORMATTING_FUNCTIONS	1

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 			0
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

/* Software timer definitions. */
#define configUSE_TIMERS				1
#define configTIMER_TASK_PRIORITY		( configMAX_PRIORITIES - 1 )
#define configTIMER_QUEUE_LENGTH		( 12 )
#define configTIMER_TASK_STACK_DEPTH	( configMINIMAL_STACK_SIZE * 2 )

#define PRIORITIE_OFFSET				( 4 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet		1
#define INCLUDE_uxTaskPriorityGet		1
#define INCLUDE_vTaskDelete				1
#define INCLUDE_vTaskCleanUpResources	1
#define INCLUDE_vTaskSuspend			1
#define INCLUDE_vTaskDelayUntil			1
#define INCLUDE_vTaskDelay				1
#define INCLUDE_eTaskGetState			1
#define INCLUDE_xTimerPendFunctionCall	1
#define INCLUDE_xTaskGetCurrentTaskHandle 1

/* Cortex-M specific definitions. */
#ifdef __NVIC_PRIO_BITS
	/* __BVIC_PRIO_BITS will be specified when CMSIS is being used. */
	#define configPRIO_BITS       		__NVIC_PRIO_BITS
#else
	#define configPRIO_BITS       		4        /* 15 priority levels */
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority"
function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY			15

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY	4

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
//#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY + 0x80 )
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
//#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 0x80 )

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */
//#define xPortPendSVHandler PendSV_Handler
//#define vPortSVCHandler SVC_Handler
//#define xPortSysTickHandler SysTick_Handler

/* Prevent the inclusion of items the assembler will not understand in assembly
files. */
#ifndef __IAR_SYSTEMS_ASM__

	/* Library includes. */
	//#include "stm32f7xx_hal.h"

	extern uint32_t SystemCoreClock;

	/* Normal assert() semantics without relying on the provision of an assert.h
	header file. */
	extern void vAssertCalled( uint32_t ulLine, const char *pcFile );
	#define configASSERT( x ) if( ( x ) == 0 ) vAssertCalled( __LINE__, __FILE__ )
	
	// _memxxx proto-type?
	//#define memcpy _memcpy
	//#define memset _memset
	//#define memcmp _memcmp
	#include "basic_types.h"
	#include "memory.h"
    
    extern int bprintf(char* fmt, ...);
    //#define traceTASK_SWITCHED_OUT()    do{if(pxCurrentTCB) bprintf(">%s\n\r", pxCurrentTCB->pcTaskName);}while(0)
    //#define traceTASK_SWITCHED_IN()     do{if(pxCurrentTCB) bprintf("<%s\n\r", pxCurrentTCB->pcTaskName);}while(0)    
#endif /* __IAR_SYSTEMS_ASM__ */

#endif /* FREERTOS_CONFIG_H */

