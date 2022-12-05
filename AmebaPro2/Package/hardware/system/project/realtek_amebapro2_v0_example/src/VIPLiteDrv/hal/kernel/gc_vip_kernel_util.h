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

#ifndef _GC_VIP_KERNEL_UTIL_H
#define _GC_VIP_KERNEL_UTIL_H

#include <gc_vip_common.h>
#include <vip_lite.h>

typedef enum _gckvip_queue_status {
	GCKVIP_QUEUE_NONE       = 0,
	GCKVIP_QUEUE_EMPTY      = 1,
	GCKVIP_QUEUE_WITH_DATA  = 2,
	GCKVIP_QUEUE_FULL       = 3,
	GCKVIP_QUEUE_MAX,
} gckvip_queue_status_e;

typedef struct _gckvip_database_table {
	vip_ptr            *handle;
	vip_uint32_t       process_id;
} gckvip_database_table_t;

typedef struct _gckvip_database {
	gckvip_database_table_t *table;
	vip_uint32_t       capacity;
	vip_uint32_t       free_count;     /* the number of free in database */
	vip_uint32_t       first_free_pos; /* the first free position in database */
#if vpmdENABLE_MULTIPLE_TASK
	void               *mutex;
#endif
} gckvip_database_t;

#if vpmdENABLE_MULTIPLE_TASK
typedef struct _gckvip_queue_data {
	vip_uint64_t        v1;
	vip_uint64_t        v2;
} gckvip_queue_data_t;

typedef struct _gckvip_queue {
	gckvip_queue_data_t  *data[SUPPORT_MAX_TASK_NUM];
	vip_int32_t         begin_index;
	vip_int32_t         end_index;
	void                *mutex;
	void                *read_mutex;
	void                *write_mutex;
	void                *read_signal;
	void                *write_signal;
	vip_bool_e          queue_stop;
} gckvip_queue_t;

vip_status_e gckvip_queue_initialize(
	gckvip_queue_t *queue
);

vip_status_e gckvip_queue_destroy(
	gckvip_queue_t *queue
);

vip_bool_e gckvip_queue_read(
	gckvip_queue_t *queue,
	gckvip_queue_data_t **data_ptr
);

vip_bool_e gckvip_queue_write(
	gckvip_queue_t *queue,
	gckvip_queue_data_t *data
);

vip_status_e gckvip_queue_clean(
	gckvip_queue_t *queue
);
gckvip_queue_status_e gckvip_queue_status(
	gckvip_queue_t *queue
);
#endif

#define DATABASE_MAGIC_DATA          0x15000000

vip_status_e gckvip_database_init(
	gckvip_database_t *database
);

vip_status_e gckvip_database_get_id(
	gckvip_database_t *database,
	vip_ptr handle,
	vip_uint32_t process_id,
	vip_uint32_t *database_id
);

vip_status_e gckvip_database_put_id(
	gckvip_database_t *database,
	vip_uint32_t database_id
);

vip_status_e gckvip_database_get_handle(
	gckvip_database_t *database,
	vip_uint32_t database_id,
	vip_ptr *handle
);

vip_uint32_t gckvip_database_get_freepos(
	gckvip_database_t *database
);

vip_status_e gckvip_database_get_table(
	gckvip_database_t *database,
	vip_uint32_t database_id,
	gckvip_database_table_t **table
);

vip_status_e gckvip_database_uninit(
	gckvip_database_t *database
);

#endif
