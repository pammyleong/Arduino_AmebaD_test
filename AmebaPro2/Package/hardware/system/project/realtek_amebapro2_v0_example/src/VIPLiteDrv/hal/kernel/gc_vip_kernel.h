/****************************************************************************
*
*    The MIT License (MIT)
*
*    Copyright (c) 2017 - 2021 Vivante Corporation
*
*    Permission is hereby granted, free of charge, to any person obtaining a
*    copy of this software and associated documentation files (the "Software"),
*    to deal in the Software without restriction, including without limitation
*    the rights to use, copy, modify, merge, publish, distribute, sublicense,
*    and/or sell copies of the Software, and to permit persons to whom the
*    Software is furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in
*    all copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
*    DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/

#ifndef _GC_VIP_KERNEL_H
#define _GC_VIP_KERNEL_H

#include <gc_vip_kernel_port.h>
#include <gc_vip_common.h>
#include <gc_vip_kernel_heap.h>
#include <gc_vip_kernel_util.h>

#define MAX_WRAP_USER_MEMORY_NUM            256
#define MAX_WRAP_USER_PHYSICAL_TABLE_SIZE   16384

/*
  the max value of command buffer size.
*/
#define gcdVIP_MAX_CMD_SIZE               (65535 * 8)

/*
  the size of memory alignment for video memory.
  64 bytes.
*/
#define gcdVIP_MEMORY_ALIGN_SIZE          64


/* user space can specify video memory allocatrion flag */
typedef enum _gckvip_video_mem_alloc_flag {
	GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE               = 0x00,
	GCVIP_VIDEO_MEM_ALLOC_FLAG_CONTIGUOUS         = 0x01, /* Physical contiguous. */
	GCVIP_VIDEO_MEM_ALLOC_FLAG_1M_CONTIGUOUS      = 0x02, /* allocate 1M bytes contiguous memory */
	GCVIP_VIDEO_MEM_ALLOC_FLAG_NON_CONTIGUOUS     = 0x04, /* Physical non contiguous. */
	GCVIP_VIDEO_MEM_ALLOC_FLAG_4GB_ADDR           = 0x08, /* Need 32bit address. */
	GCVIP_VIDEO_MEM_ALLOC_FLAG_NO_MMU_PAGE        = 0x10, /* without mmaped VIP's MMU page table */
	GCVIP_VIDEO_MEM_ALLOC_FLAG_MAP_USER           = 0X20, /* need map user space logical address */
	GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_CACHE         = 0x40, /* allocate none-cache video memory */
	GCVIP_VIDEO_MEM_ALLOC_FLAG_SECURE_MEM         = 0x80, /* allocate a memory form secure area */
	GCVIP_VIDEO_MEM_ALLOC_FLAG_NONE_SECURE_MEM    = 0x100,/* allocate a memory form none secure area */
	GCVIP_VIDEO_MEM_ALLOC_FLAG_MAX,
} gckvip_video_mem_alloc_flag_e;

/* Kernel Command IDs. */
typedef enum _gckvip_command_id {
	KERNEL_CMD_INIT = 0,
	KERNEL_CMD_DESTROY,
	KERNEL_CMD_READ_REG,
	KERNEL_CMD_WRITE_REG,
	KERNEL_CMD_WAIT,
	KERNEL_CMD_SUBMIT,
	KERNEL_CMD_ALLOCATION,
	KERNEL_CMD_DEALLOCATION,
	KERNEL_CMD_RESET_VIP,
	KERNEL_CMD_QUERY_ADDRESS_INFO,
	KERNEL_CMD_QUERY_DATABASE,
	KERNEL_CMD_OPERATE_CACHE,
	KERNEL_CMD_WRAP_USER_MEMORY,
	KERNEL_CMD_UNWRAP_USER_MEMORY,
	KERNEL_CMD_QUERY_POWER_INFO,
	KERNEL_CMD_SET_WORK_MODE,
	KERNEL_CMD_POWER_MANAGEMENT,
	KERNEL_CMD_WRAP_USER_PHYSICAL,
	KERNEL_CMD_UNWRAP_USER_PHYSICAL,
	KERNEL_CMD_MAX,
} gckvip_command_id_e;

typedef enum _gckvip_power_status {
	GCKVIP_POWER_NONE       = 0,
	GCKVIP_POWER_OFF        = 1, /* power and clock off */
	GCKVIP_POWER_IDLE       = 2, /* slow down core freq */
	GCKVIP_POWER_CLK_ON     = 3, /* power and clock on, no initialize hardware */
	GCKVIP_POWER_ON         = 4, /* power and clock on, initialize hardware done */
	GCKVIP_POWER_SUSPEND    = 5, /* system suspended */
	GCKVIP_POWER_RESUME     = 6, /* system resume */
	GCKVIP_POWER_SUSPEND_OFF = 7, /* vip suspend done */
	GCKVIP_POWER_MAX
} gckvip_power_status_e;

typedef enum _gckvip_cache_type {
	GCKVIP_CACHE_NONE           = 0,
	GCKVIP_CACHE_FLUSH          = 1,
	GCKVIP_CACHE_CLEAN          = 2,
	GCKVIP_CACHE_INVALID        = 3,
	GCKVIP_CACHE_MAX            = 4,
} gckvip_cache_type_e;

typedef enum _gckvip_submit_event {
	GCKVIP_SUBMIT_WITH_EVENT    = 0,
	GCKVIP_SUBMIT_NO_EVENT      = 1,
} gckvip_submit_event_e;

typedef enum _gckvip_work_mode_event {
	GCKVIP_WORK_MODE_NORMAL     = 0,
	GCKVIP_WORK_MODE_SECURITY   = 1,
} gckvip_work_mode_e;

/* user to kernel structure start */
typedef struct _gckvip_initialize {
	vip_uint32_t     video_mem_size;
} gckvip_initialize_t;

typedef struct _gckvip_allocation {
	vip_uint64_t    logical;    /* the logical address in user space */
	vip_uint32_t    handle;     /* video memory handle in kernel space */
	vip_uint32_t    physical;   /* the physical addess or VIP virtual */
	vip_uint32_t    size;
	vip_uint32_t    align;
	vip_uint32_t    alloc_flag; /* see gckvip_video_mem_alloc_flag_e */
} gckvip_allocation_t;

typedef struct _gckvip_deallocation {
	vip_uint32_t    handle;  /* video memory handle in kernel space */
} gckvip_deallocation_t;

typedef struct _gckvip_wrap_user_memory {
	/* user space logical address */
	vip_uint64_t    logical;
	/* video memory handle */
	vip_uint32_t    handle;
	/* The type of this VIP buffer memory. see vip_buffer_memory_type_e*/
	vip_uint32_t    memory_type;
	/* the size of wrap memory */
	vip_uint32_t    size;
	/* VIP virtual memory */
	vip_uint32_t    virtual;
} gckvip_wrap_user_memory_t;

typedef struct _gckvip_wrap_user_physical {
	/* cpu physical address table */
	vip_address_t   physical_table[MAX_WRAP_USER_PHYSICAL_TABLE_SIZE];
	/* the size of physical table each element */
	vip_uint32_t    size_table[MAX_WRAP_USER_PHYSICAL_TABLE_SIZE];
	/* the number of physical table element */
	vip_uint32_t    physical_num;
	/* The type of this VIP buffer memory. see vip_buffer_memory_type_e */
	vip_uint32_t    memory_type;
	/* video memory handle */
	vip_uint32_t    handle;
	/* VIP virtual memory */
	vip_uint32_t    virtual;
} gckvip_wrap_user_physical_t;

typedef struct _gckvip_unwrap_user_memory {
	vip_uint32_t    handle;   /* video memory handle */
	vip_uint32_t    virtual;  /* VIP virtual memory */
} gckvip_unwrap_user_memory_t;

typedef struct _gckvip_reg {
	vip_uint32_t    reg;
	vip_uint32_t    data;
} gckvip_reg_t;

typedef struct _gckvip_wait {
	vip_uint32_t    handle;
	vip_uint32_t    mask;
	vip_uint32_t    time_out;
} gckvip_wait_t;

typedef struct _gckvip_commit {
	vip_uint64_t    cmd_logical;
	vip_uint32_t    cmd_handle;
	vip_uint32_t    cmd_physical;
	vip_uint32_t    cmd_size;
	vip_uint64_t    last_cmd_logical;
	vip_uint32_t    last_cmd_handle;
	vip_uint32_t    last_cmd_physical;
	vip_uint32_t    last_cmd_size;
	vip_uint32_t    wait_event;
} gckvip_commit_t;

typedef struct _gckvip_query_address_info {
	/* the user space logical address of wait-link buffer */
	vip_uint64_t    waitlink_logical;
	/* the physical address of wait-link buffer */
	vip_uint32_t    waitlink_physical;
	/* the size of wait-link buffer */
	vip_uint32_t    waitlink_size;
} gckvip_query_address_info_t;

typedef struct _gckvip_query_database {
	vip_uint32_t    vip_sram_base;
	vip_uint32_t    vip_sram_size;
	vip_uint32_t    axi_sram_base;
	vip_uint32_t    axi_sram_size;
#if vpmdENABLE_VIDEO_MEMORY_HEAP
	/* physical address when MMU is disabled, otherwise virtual address */
	vip_uint32_t    video_heap_base;
#endif
	/* hardware customer ID */
	vip_uint32_t    hw_cid;
} gckvip_query_database_t;

typedef struct _gckvip_operate_cache {
	/* user logical address  */
	vip_uint64_t    logical;
	/* video memory handle should be flushed */
	vip_uint32_t    handle;
	/* when MMU is enabled, physical is virtual address. otherwise physical is CPU's physical */
	vip_uint32_t    physical;
	/* the size of memory should be flushed */
	vip_uint32_t    size;
	/* operate CPU cache type, flush/clean/invalid */
	gckvip_cache_type_e type;
} gckvip_operate_cache_t;

typedef struct _gckvip_query_power_info {
	vip_uint8_t    power_status;
} gckvip_query_power_info_t;

typedef struct _gckvip_set_work_mode {
	vip_uint8_t    work_mode;
} gckvip_set_work_mode_t;

typedef struct _gckvip_power_management {
	/* see vip_power_property_e */
	vip_enum       property;
	/* only for property is VIP_POWER_PROPERTY_SET_FREQUENCY.
	    other property, fscale_percent is useless */
	vip_uint8_t    fscale_percent;
} gckvip_power_management_t;
/* user to kernel structure end */

/* kernel space use structure start */
typedef struct _gckvip_submit {
	/* first command buffer */
	void            *cmd_handle;
	vip_uint8_t     *cmd_logical;
	vip_uint32_t    cmd_physical;
	vip_uint32_t    cmd_size;

	/*
	last command buffer. it is used to support submit multiple command buffer.
	If only one command buffer submit, you can set cmd_xxx equal to last_cmd_xxx.
	*/
	void            *last_cmd_handle;
	vip_uint8_t     *last_cmd_logical;
	vip_uint32_t    last_cmd_physical;
	vip_uint32_t    last_cmd_size;

	vip_uint32_t    wait_event;
} gckvip_submit_t;

#if vpmdENABLE_MULTIPLE_TASK
typedef struct _gckvip_multi_thread_submit {
	gckvip_submit_t       submit_handle;
	gckvip_queue_data_t   queue_data;
	void                  *wait_signal;
	volatile vip_bool_e   is_empty;
} gckvip_multi_thread_submit_t;
#endif

typedef struct _gckvip_video_memory {
	void            *handle;
	vip_uint32_t    physical;
	void            *logical;
	vip_uint32_t    size;
} gckvip_video_memory_t;

/* Kernel context. */
typedef struct _gckvip_context {
#if vpmdENABLE_WAIT_LINK_LOOP
	/* wait link buffer. */
	void           *waitlinkbuf_handle;
	vip_uint32_t   *waitlinkbuf_logical;
	vip_uint32_t    waitlinkbuf_physical;
	vip_uint32_t    waitlinkbuf_size;
	vip_uint32_t   *waitlink_pos;
#endif

	volatile vip_int8_t initialize;
	volatile vip_bool_e vip_idle;
	vip_int8_t      recovery_times;
	volatile vip_uint32_t process_id[SUPPORT_MAX_TASK_NUM];

	gckvip_submit_t curr_command;

	vip_uint32_t    chip_ver1;
	vip_uint32_t    chip_ver2;
	vip_uint32_t    chip_cid;
	vip_uint32_t    chip_date;

#if vpmdENABLE_HANG_DUMP
	volatile vip_uint8_t dump_finish;
	vip_uint32_t    execute_count;
#endif

#if vpmdENABLE_VIDEO_MEMORY_HEAP
	gckvip_heap_t   video_mem_heap;   /* video memory heap management object */
	void            *user_mem_base;   /* cpu virtual base address in user space */
	void            *kernel_mem_base; /* cpu virtual base address in kernel space */
	phy_address_t   physical_base;    /* vip physical base address */
	vip_uint32_t    mem_size;         /* video memory memory size */
	vip_uint32_t    vip_virtual_base; /* The virtual base address of VIP when MMU enabled */
#endif

	void            *reg_base; /* register base memory address */

	void            *irq_queue; /* interrupt sync object */
	vip_uint32_t    *irq_flag;   /* interrupt flag */

#if vpmdENABLE_MMU
	gckvip_video_memory_t  MTLB;
	gckvip_video_memory_t  STLB_1M;
	gckvip_video_memory_t  STLB_4K;
	gckvip_video_memory_t  MMU_entry;
	gckvip_video_memory_t  MMU_flush;
	volatile vip_uint8_t   flush_mmu;

	void             *wrap_handles[MAX_WRAP_USER_MEMORY_NUM];
	volatile vip_uint32_t  wrap_handle_num;

#if vpmdENABLE_MULTIPLE_TASK
	void                  *wrap_mutex;
	void                  *mmu_mutex;
#endif

#if vpmdENABLE_SECURE
	/* security page table */
	gckvip_video_memory_t  secu_STLB_1M;
	gckvip_video_memory_t  secu_STLB_4K;
	gckvip_video_memory_t  secu_MMU_flush;
	gckvip_video_memory_t  secu_MMU_flush_page;
	gckvip_video_memory_t  MMU_flush_page;

	volatile vip_uint8_t   work_mode;
	volatile vip_uint8_t   work_mode_change;
	volatile vip_uint8_t   work_mode_last_submit;
	gckvip_video_memory_t  *ptr_MMU_flush_page;
#endif

	/* page table pointer */
	gckvip_video_memory_t  *ptr_STLB_1M;
	gckvip_video_memory_t  *ptr_STLB_4K;
	gckvip_video_memory_t  *ptr_MMU_flush;
#endif

	vip_uint32_t    vip_sram_size;
	vip_uint32_t    vip_sram_address; /* the physical or VIP's virtual address of VIP SRAM */
	vip_uint32_t    axi_sram_size;
	vip_uint32_t    axi_sram_address; /* the physical or VIP's virtual address of AXI SRAM */

#if vpmdENABLE_MULTIPLE_TASK
	vip_bool_e            mt_thread_running;  /* a flag for multiple task thread is running */
	gckvip_queue_t        mt_input_queue;
	void                  *mt_mutex;          /* mutex for multiple task */
	void                  *mt_thread_handle;  /* multiple task thread process handle */
	gckvip_multi_thread_submit_t mt_submit[SUPPORT_MAX_TASK_NUM];
	void                  *mt_thread_signal;  /* signal for destroy multiple task thread */
	void                  *reg_mutex;         /* mutex for read/write register */
	void                  *flush_cache_mutex; /* mutex for flush CPU cache */
	void                  *initialize_mutex;  /* mutex for initialize kernel space driver */
#endif

#if vpmdENABLE_DEBUGFS
	void                  *memory_mutex;      /* mutex for allocate/free video memory debugfs */
#endif

	volatile vip_uint8_t  power_status;

#if vpmdPOWER_OFF_TIMEOUT
	void                  *power_timer;
	void                  *power_mutex;
	void                  *power_signal;
	void                  *power_thread;
	volatile vip_uint8_t  power_thread_running;
	volatile vip_uint8_t  user_query_power;
#endif

#if vpmdENABLE_SUSPEND_RESUME
	/* A signal for waiting system resume, then submit a new task to hardware */
	void                 *resume_signal;
	/* A flag for resume signal in waiting status */
	volatile vip_uint8_t wait_resume_signal;
#endif

	/* maintain video memory heandle pointer(kernel space) and handle id(user space) */
	gckvip_database_t     videomem_database;

#if vpmdENABLE_USER_CONTROL_POWER
	volatile vip_uint8_t  user_pm_status;
	volatile vip_uint8_t  user_pm_switch;
	void                 *user_pm_mutex;
#endif

	volatile vip_uint32_t core_fscale_percent;
	volatile vip_uint32_t last_fscale_percent;
} gckvip_context_t;
/* kernel space use structure end */


/************ EXPOSED APIs  ***************/
/*
@brief Destroy kernel space resource.
       This function only use on Linux/Andorid system when used ctrl+c
       to exit application or application crash happend.
       When the appliction exits abnormally, gckvip_destroy() used
       to free all kenerl space resource.
*/
vip_status_e gckvip_destroy(void);

/*
@brief Get kernel context object.
*/
gckvip_context_t *gckvip_get_context(void);

/*
@brief To run any initial commands once in the beginning.
*/
vip_status_e gckvip_init_commands(void);

/*
@brief  dispatch kernel command
@param  command, command type.
@param  data, the data for command type.
*/
vip_status_e gckvip_kernel_call(
	gckvip_command_id_e command,
	void *data
);

#endif
