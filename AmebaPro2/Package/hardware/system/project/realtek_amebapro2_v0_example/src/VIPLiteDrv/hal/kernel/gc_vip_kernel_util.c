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

#include <gc_vip_common.h>
#include <vip_lite.h>
#include <gc_vip_kernel.h>
#include <gc_vip_kernel_port.h>
#include <gc_vip_kernel_drv.h>


#if vpmdENABLE_MULTIPLE_TASK
vip_status_e gckvip_queue_initialize(
	gckvip_queue_t *queue
)
{
	vip_status_e status = VIP_SUCCESS;
	queue->begin_index = 0;
	queue->end_index = -1;

	status = gckvip_os_create_mutex(&queue->mutex);
	printf("queue %x queue mutex %x\n\r", queue, queue->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create mutex\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	gckvip_os_create_mutex(&queue->read_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create read mutex\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	gckvip_os_create_mutex(&queue->write_mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create write mutex\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	status = gckvip_os_create_signal(&queue->read_signal);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create read_signal\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	PRINTK_D("queue create read signal=0x%" PRIx64"\n", GCKVIPPTR_TO_UINT64(queue->read_signal));
	status = gckvip_os_create_signal(&queue->write_signal);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create write_signal\n");
		gcGoOnError(VIP_ERROR_IO);
	}
	PRINTK_D("queue create write signal=0x%" PRIx64"\n", GCKVIPPTR_TO_UINT64(queue->write_signal));
	status = gckvip_os_set_signal(queue->write_signal, vip_true_e);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create write_signal\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	queue->end_index = -1; /* queue is empty */
	queue->begin_index = 0;
	queue->queue_stop = vip_false_e;

onError:
	return status;
}

vip_status_e gckvip_queue_destroy(
	gckvip_queue_t *queue
)
{
	vip_status_e status = VIP_SUCCESS;

	queue->queue_stop = vip_true_e;
	if (queue->read_signal != VIP_NULL) {
		gckvip_os_set_signal(queue->read_signal, vip_true_e);
		gckvip_os_destroy_signal(queue->read_signal);
	}
	if (queue->write_signal != VIP_NULL) {
		gckvip_os_set_signal(queue->write_signal, vip_true_e);
		gckvip_os_destroy_signal(queue->write_signal);
	}
	if (queue->mutex != VIP_NULL) {
		gckvip_os_destroy_mutex(queue->mutex);
	}
	if (queue->read_mutex != VIP_NULL) {
		gckvip_os_destroy_mutex(queue->read_mutex);
	}
	if (queue->write_mutex != VIP_NULL) {
		gckvip_os_destroy_mutex(queue->write_mutex);
	}

	return status;
}

vip_bool_e gckvip_queue_read(
	gckvip_queue_t *queue,
	gckvip_queue_data_t **data_ptr
)
{
	vip_bool_e read = vip_false_e;
	vip_status_e status = VIP_SUCCESS;

	gckvip_os_lock_mutex(queue->read_mutex);
	while (VIP_SUCCESS == gckvip_os_wait_signal(queue->read_signal, WAIT_SIGNAL_TIMEOUT)) {
		if (queue->queue_stop) {
			break;
		}

		status = gckvip_os_lock_mutex(queue->mutex);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to lock mutex\n");
			return VIP_ERROR_FAILURE;
		}

		/* Read data if queue is not empty */
		if (queue->end_index != -1) {
			*data_ptr = queue->data[queue->begin_index];
			queue->begin_index = (queue->begin_index + 1) % SUPPORT_MAX_TASK_NUM;

			if (queue->begin_index == queue->end_index) {
				queue->end_index = -1;
			}
			gcOnError(gckvip_os_set_signal(queue->write_signal, vip_true_e));
			read = vip_true_e;
		}

		/* Pending all readers if queue is empty */
		if (queue->end_index == -1) {
			gcOnError(gckvip_os_set_signal(queue->read_signal, vip_false_e));
		}

		gckvip_os_unlock_mutex(queue->mutex);

		if (read) {
			break;
		}
	}

	gckvip_os_unlock_mutex(queue->read_mutex);
	return read;

onError:
	gckvip_os_unlock_mutex(queue->mutex);
	gckvip_os_unlock_mutex(queue->read_mutex);
	return read;
}

vip_bool_e gckvip_queue_write(
	gckvip_queue_t *queue,
	gckvip_queue_data_t *data
)
{
	vip_bool_e wrote = vip_false_e;
	vip_status_e status = VIP_SUCCESS;

	gckvip_os_lock_mutex(queue->write_mutex);

	while (VIP_SUCCESS == gckvip_os_wait_signal(queue->write_signal, WAIT_SIGNAL_TIMEOUT)) {
		if (queue->queue_stop) {
			break;
		}

		status = gckvip_os_lock_mutex(queue->mutex);
		if (status != VIP_SUCCESS) {
			PRINTK_E("failed to lock mutex\n");
			return VIP_ERROR_FAILURE;
		}

		/* Write data if queue is not full */
		if (queue->begin_index != queue->end_index) {
			if (queue->end_index == -1) {
				queue->end_index = queue->begin_index;
			}
			queue->data[queue->end_index] = data;
			queue->end_index = (queue->end_index + 1) % SUPPORT_MAX_TASK_NUM;

			gcOnError(gckvip_os_set_signal(queue->read_signal, vip_true_e));

			wrote = vip_true_e;
		}

		/* Pending all writers if queue is full */
		if (queue->begin_index == queue->end_index) {
			gcOnError(gckvip_os_set_signal(queue->write_signal, vip_false_e));
		}

		gckvip_os_unlock_mutex(queue->mutex);

		if (wrote) {
			break;
		} else {
			PRINTK_E("queue is full...\n");
		}
	}

	gckvip_os_unlock_mutex(queue->write_mutex);
	return wrote;

onError:
	gckvip_os_unlock_mutex(queue->mutex);
	gckvip_os_unlock_mutex(queue->write_mutex);
	return wrote;
}

vip_status_e gckvip_queue_clean(
	gckvip_queue_t *queue
)
{
	if (VIP_NULL == queue) {
		PRINTK_E("failed to clean queue, parameter is NULL\n");
		return VIP_ERROR_FAILURE;
	}

	gckvip_os_lock_mutex(queue->mutex);
	queue->end_index = -1;
	gckvip_os_unlock_mutex(queue->mutex);

	return VIP_SUCCESS;
}

gckvip_queue_status_e gckvip_queue_status(
	gckvip_queue_t *queue
)
{
	gckvip_queue_status_e status = GCKVIP_QUEUE_NONE;

	if (VIP_NULL == queue) {
		return GCKVIP_QUEUE_NONE;
	}

	gckvip_os_lock_mutex(queue->mutex);

	if (queue->begin_index == queue->end_index) {
		status = GCKVIP_QUEUE_FULL;
	} else if (queue->end_index == -1) {
		status = GCKVIP_QUEUE_EMPTY;
	} else {
		status =  GCKVIP_QUEUE_WITH_DATA;
	}

	gckvip_os_unlock_mutex(queue->mutex);

	return status;
}
#endif

#define DATABASE_TABLE_MAX_EXPAND    512

vip_status_e gckvip_database_init(
	gckvip_database_t *database
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_database_table_t *table = VIP_NULL;
	gcIsNULL(database);

	database->capacity = DATABASE_TABLE_MAX_EXPAND;
	database->free_count = DATABASE_TABLE_MAX_EXPAND;
	database->first_free_pos = 0;

	gcOnError(gckvip_os_allocate_memory(sizeof(gckvip_database_table_t) * database->capacity,
										(vip_ptr *)&table));
	gckvip_os_zero_memory(table, sizeof(gckvip_database_table_t) * database->capacity);
	database->table = table;

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_create_mutex(&database->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to create database mutex\n");
		gcGoOnError(VIP_ERROR_IO);
	}
#endif

	return status;

onError:
	if (database != VIP_NULL && database->table != VIP_NULL) {
		gckvip_os_free_memory(database->table);
	}
	PRINTK_E("failed to initialize data base\n");
	return status;
}

vip_status_e gckvip_database_get_id(
	gckvip_database_t *database,
	vip_ptr handle,
	vip_uint32_t process_id,
	vip_uint32_t *database_id
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_database_table_t *table = VIP_NULL;
	vip_uint32_t pos = 0;
	vip_uint32_t i = 0;
	gcIsNULL(database);

	if (VIP_NULL == database_id) {
		PRINTK_E("failed to get video memory id form database, id is NULL pointer");
		return VIP_ERROR_OUT_OF_RESOURCE;
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(database->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	if (database->free_count < 1) {
		vip_uint32_t expand = DATABASE_TABLE_MAX_EXPAND;
		vip_uint32_t capacity = database->capacity + expand;

		/* Extend table. */
		gcOnError(gckvip_os_allocate_memory(sizeof(gckvip_database_table_t) * capacity,
											(vip_ptr *)&table));
		gckvip_os_zero_memory(table, sizeof(gckvip_database_table_t) * capacity);

		if (database->table != VIP_NULL) {
			gckvip_os_memcopy(table, database->table,
							  sizeof(gckvip_database_table_t) * capacity);
			gckvip_os_free_memory(database->table);
		}

		/* Update databse with new allocated table. */
		database->table = table;
		database->first_free_pos = database->capacity; /* re-set first free pos */
		database->capacity = capacity;
		database->free_count += expand;
		PRINTK_I("expand video memory database, expend=%d, free count=%d, capacity=%d, pid=%d\n",
				 expand, database->free_count, database->capacity, process_id);
	}

	for (i = 0; i < database->first_free_pos; i++) {
		if (VIP_NULL == database->table[i].handle) {
			pos = i;
			break;
		}
	}

	if (i >= database->first_free_pos) {
		database->first_free_pos++;
		pos = i;
	}

	/* Connect id with database handle */
	database->table[pos].handle = handle;
	database->table[pos].process_id = process_id;
	*database_id = pos + DATABASE_MAGIC_DATA;

	PRINTK_D("database convert from first_free_pos=0x%x handle=0x%lx to id=0x%x, pid=%d\n",
			 database->first_free_pos, GCKVIPPTR_TO_UINT64(handle),
			 *database_id, process_id);

	database->free_count--;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	gckvip_os_unlock_mutex(database->mutex);
#endif
	return status;
}

vip_status_e gckvip_database_put_id(
	gckvip_database_t *database,
	vip_uint32_t database_id
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t id = 0;
	gcIsNULL(database);

	if (database_id < DATABASE_MAGIC_DATA) {
		PRINTK_E("failed data base id=0x%x, database magic=0x%x\n",
				 database_id, DATABASE_MAGIC_DATA);
		return VIP_ERROR_OUT_OF_RESOURCE;
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(database->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	if (VIP_NULL == database->table) {
		PRINTK_E("failed to free database, parameter is NULL\n");
		gcGoOnError(VIP_ERROR_OUT_OF_RESOURCE);
	}

	id = database_id - DATABASE_MAGIC_DATA;

	if (id > database->capacity) {
		PRINTK_E("database is is more than database capacity, %d > %d\n",
				 id, database->capacity);
		gcGoOnError(VIP_ERROR_OUT_OF_RESOURCE);
	}

	database->table[id].handle = VIP_NULL;
	database->table[id].process_id = 0;
	database->free_count++;
	if ((database->first_free_pos >= 1) && ((database->first_free_pos - 1) == id)) {
		database->first_free_pos--;
	}

onError:
#if vpmdENABLE_MULTIPLE_TASK
	gckvip_os_unlock_mutex(database->mutex);
#endif
	return status;
}

vip_uint32_t gckvip_database_get_freepos(
	gckvip_database_t *database
)
{
#if vpmdENABLE_MULTIPLE_TASK
	vip_status_e status = VIP_SUCCESS;
#endif
	vip_uint32_t pos = 0;

	if (VIP_NULL == database) {
		PRINTK_E("failed to get database free pos, database is NULL\n");
		return 0xFFFFFF;
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(database->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock mutex\n");
		return 0xFFFFFF;
	}
#endif

	pos = database->first_free_pos;

#if vpmdENABLE_MULTIPLE_TASK
	gckvip_os_unlock_mutex(database->mutex);
#endif

	return pos;
}

vip_status_e gckvip_database_get_table(
	gckvip_database_t *database,
	vip_uint32_t database_id,
	gckvip_database_table_t **table
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t id = 0;
	gcIsNULL(database);

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(database->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	if (VIP_NULL == database->table) {
		PRINTK_E("failed to convert database id, parameter is NULL, table=0x%lx\n",
				 GCKVIPPTR_TO_UINT64(database->table));
		gcGoOnError(VIP_ERROR_OUT_OF_RESOURCE);
	}

	if (database_id < DATABASE_MAGIC_DATA) {
		PRINTK_E("failed data base id=%d, database magic=%d\n",
				 database_id, DATABASE_MAGIC_DATA);
		gcGoOnError(VIP_ERROR_OUT_OF_RESOURCE);
	}

	id = database_id - DATABASE_MAGIC_DATA;

	if (id > database->capacity) {
		PRINTK_E("database is is more than database capacity, %d > %d\n",
				 id, database->capacity);
		gcGoOnError(VIP_ERROR_OUT_OF_RESOURCE);
	}

	*table = &database->table[id];

onError:
#if vpmdENABLE_MULTIPLE_TASK
	gckvip_os_unlock_mutex(database->mutex);
#endif
	return status;
}

vip_status_e gckvip_database_get_handle(
	gckvip_database_t *database,
	vip_uint32_t database_id,
	vip_ptr *handle
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t id = 0;
	gcIsNULL(database);

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_lock_mutex(database->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to lock mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	if ((VIP_NULL == database->table) || (VIP_NULL == handle)) {
		PRINTK_E("failed to convert database id, parameter is NULL,"
				 "mem_handle=0x%lx, table=0x%lx\n",
				 GCKVIPPTR_TO_UINT64(handle), GCKVIPPTR_TO_UINT64(database->table));
		gcGoOnError(VIP_ERROR_OUT_OF_RESOURCE);
	}

	if (database_id < DATABASE_MAGIC_DATA) {
		PRINTK_E("failed data base id=%d, database magic=%d\n",
				 database_id, DATABASE_MAGIC_DATA);
		gcGoOnError(VIP_ERROR_OUT_OF_RESOURCE);
	}

	id = database_id - DATABASE_MAGIC_DATA;

	if (id > database->capacity) {
		PRINTK_E("database is is more than database capacity, %d > %d\n",
				 id, database->capacity);
		gcGoOnError(VIP_ERROR_OUT_OF_RESOURCE);
	}

	*handle = database->table[id].handle;

#if 0
	PRINTK_D("database convert from id=0x%x to handle=0x%lx \n",
			 database_id, GCKVIPPTR_TO_UINT64(*handle));
#endif

onError:
#if vpmdENABLE_MULTIPLE_TASK
	gckvip_os_unlock_mutex(database->mutex);
#endif
	return status;
}

vip_status_e gckvip_database_uninit(
	gckvip_database_t *database
)
{
	vip_status_e status = VIP_SUCCESS;
	gcIsNULL(database);

	if (database->table != VIP_NULL) {
		gckvip_os_free_memory(database->table);
		database->table = VIP_NULL;
	}

	database->capacity = 0;
	database->free_count = 0;
	database->first_free_pos = 0;

#if vpmdENABLE_MULTIPLE_TASK
	status = gckvip_os_destroy_mutex(database->mutex);
	if (status != VIP_SUCCESS) {
		PRINTK_E("failed to destroy data base mutex\n");
	}
#endif

onError:
	return status;
}
