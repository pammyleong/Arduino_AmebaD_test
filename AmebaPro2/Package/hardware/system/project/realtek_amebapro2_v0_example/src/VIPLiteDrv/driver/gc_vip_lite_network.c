/******************************************************************************\
|* Copyright (c) 2017-2021 by Vivante Corporation.  All Rights Reserved.      *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of Vivante Corporation.  This is proprietary information owned by Vivante  *|
|* Corporation.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of Vivante Corporation.                                 *|
|*                                                                            *|
\******************************************************************************/

#include "gc_vip_lite_network.h"
#include "gc_vip_lite_debug.h"
#include "gc_vip_user_port.h"
#include "gc_vip_cpu.h"
#include <gc_vip_hardware.h>
#if vpmdENABLE_NODE
#include "gc_vip_lite_node.h"
#endif

#define vpmDUMP_NETWORK_RESOURCE        0

#define gcdVIP_SH_ALIGN_SIZE            256

#define GCVIP_INITIALIZE_CHECK() \
    GET_CONTEXT(); \
    if (context->initialize <= 0) { \
        gcvip_error("please call vip_init() to initialize viplite\n"); \
        gcGoOnError(VIP_ERROR_NOT_SUPPORTED); \
    }

/* A global context object. */
gcvip_lite_context_t lite_context = {0};
#define GET_CONTEXT() gcvip_lite_context_t *context = &lite_context

#if vpmdENABLE_MULTIPLE_TASK
#if defined(LINUX)
pthread_mutex_t init_mutex = PTHREAD_MUTEX_INITIALIZER;
#endif
#endif

gcvip_lite_context_t *gcvip_get_context(void)
{
	GET_CONTEXT();
	return context;
}

/******************** For binary file loading *******************/
static void open_reader(
	gcvip_data_reader *reader,
	void *data,
	vip_uint32_t size,
	void *file
)
{
	reader->current_data = reader->data = (vip_char_t *)data;
	reader->size = size;
	reader->offset = 0;
	reader->file = (gcvip_file_t)file;

	if (reader->data != VIP_NULL) {
		reader->create_from = GCVIP_CREATE_NETWORK_FROM_MEMORY;
#if vpmdCREATE_NETWORK_FROM_FLASH
		reader->create_from = GCVIP_CREATE_NETWORK_FROM_FLASH;
#endif
	} else {
		reader->create_from = GCVIP_CREATE_NETWORK_FROM_FILE;
	}
}

static void close_reader(
	gcvip_data_reader *reader
)
{
	reader->current_data = reader->data = VIP_NULL;
	reader->size = reader->offset = 0;
	reader->file = VIP_NULL;
}

/*
 * @brief
 * Rewind the current position to the beginning.
 */
static void reader_rewind(
	gcvip_data_reader *reader
)
{
	if (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FILE) {
		gcvip_os_seek_file(0, GCVIP_FILE_SET, reader->file);
	} else {
		reader->current_data = reader->data;
		reader->offset = 0;
	}
}

/*
 * @brief
 * Move the read pointer forward by Step.
 */
static vip_status_e reader_forward(
	gcvip_data_reader *reader,
	vip_uint32_t step
)
{
	vip_status_e error = VIP_SUCCESS;

	if (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FILE) {
		error = gcvip_os_seek_file((vip_int32_t)step,
								   GCVIP_FILE_CUR,
								   reader->file);
	} else {
		if (reader->offset + step >= reader->size) {
			gcvip_error("reader->offset + Step < reader->size\n");
			error = VIP_ERROR_INVALID_ARGUMENTS;
		} else {
			reader->offset += step;
			reader->current_data = reader->data + reader->offset;
		}
	}

	return error;
}

/*
 * @brief
 * Move the read pointer backward by Step.
 */
static vip_status_e reader_backward(
	gcvip_data_reader *reader,
	vip_uint32_t step
)
{
	vip_status_e error = VIP_SUCCESS;

	if (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FILE) {
		long offset = (long)step;
		error = gcvip_os_seek_file(-offset, GCVIP_FILE_CUR, reader->file);
	} else {
		if (reader->offset < step) {
			gcvip_error("reader->offset > Step\n");
			error = VIP_ERROR_INVALID_ARGUMENTS;
		} else {
			reader->offset -= step;
			reader->current_data = reader->data + reader->offset;
		}
	}

	return error;
}

/*
 * @brief
 * Move the read pointer to a new location.
 */
static vip_status_e reader_locate(
	gcvip_data_reader *reader,
	vip_uint32_t location
)
{
	vip_status_e error = VIP_SUCCESS;

	if (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FILE) {
		error = gcvip_os_seek_file((vip_int32_t)location, GCVIP_FILE_SET, reader->file);
	} else if ((reader->create_from == GCVIP_CREATE_NETWORK_FROM_MEMORY) ||
			   (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FLASH)) {
		if (location >= reader->size) {
			gcvip_error("Location < reader->size\n");
			error = VIP_ERROR_INVALID_ARGUMENTS;
		} else {
			reader->offset = location;
			reader->current_data = reader->data + reader->offset;
		}
	} else {
		gcvip_error("not support this create network type=%d\n", reader->create_from);
		error = VIP_ERROR_INVALID_ARGUMENTS;
	}

	return error;
}

/*********** Read different types of data. ***********/
/*
 * @brief
 * Read a byte.
 */
static vip_int8_t read_byte(
	gcvip_data_reader *reader,
	vip_uint32_t auto_move
)
{
	vip_int8_t data = 0;
	if (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FILE) {
		gcvip_os_read_file(&data, sizeof(data), reader->file);
		if (!auto_move) {
			reader_backward(reader, sizeof(data));
		}
	} else if ((reader->create_from == GCVIP_CREATE_NETWORK_FROM_MEMORY) ||
			   (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FLASH)) {
		data = *((vip_int8_t *)reader->current_data);
		if (auto_move != 0) {
			reader->offset += sizeof(vip_int8_t);
			reader->current_data = reader->data + reader->offset;
		}
	} else {
		gcvip_error("not support this create network type=%d\n", reader->create_from);
		data = -1;
	}

	return data;
}

static vip_uint32_t read_uInt(
	gcvip_data_reader *reader,
	vip_uint32_t auto_move
)
{
	vip_uint32_t data = 0;

	if (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FILE) {
		gcvip_os_read_file(&data, sizeof(data), reader->file);
		if (!auto_move) {
			reader_backward(reader, sizeof(data));
		}
	} else if ((reader->create_from == GCVIP_CREATE_NETWORK_FROM_MEMORY) ||
			   (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FLASH)) {
		data = *((vip_uint32_t *)reader->current_data);
		if (auto_move != 0) {
			reader->offset += sizeof(vip_uint32_t);
			reader->current_data = reader->data + reader->offset;
		}
	} else {
		gcvip_error("not support this create network type=%d\n",
					reader->create_from);
		data = 0;
	}

	return data;
}

static vip_status_e read_data(
	gcvip_data_reader *reader,
	vip_uint8_t **memory,
	vip_uint32_t size
)
{
	vip_status_e status = VIP_SUCCESS;

	if (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FILE) {
		gcvip_os_read_file(*memory, size, reader->file);
		reader_backward(reader, size);
	} else if (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FLASH) {
		if (reader->offset + size <= reader->size) {
			*memory = (vip_uint8_t *)reader->current_data;
		} else {
			gcvip_error("reader->offset + Size > reader->size\n");
			return VIP_ERROR_OUT_OF_RESOURCE;
		}
	} else if (reader->create_from == GCVIP_CREATE_NETWORK_FROM_MEMORY) {
		gcvip_user_memcopy(*memory, reader->current_data, size);
	} else {
		gcvip_error("not support this create network type=%d\n",
					reader->create_from);
		status = VIP_ERROR_OUT_OF_RESOURCE;
	}

	return status;
}

static vip_status_e read_data_copy(
	gcvip_data_reader *reader,
	void *memory,
	vip_uint32_t size
)
{
	vip_status_e status = VIP_SUCCESS;

	if (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FILE) {
		gcvip_os_read_file(memory, size, reader->file);
		reader_backward(reader, size);
	} else if ((reader->create_from == GCVIP_CREATE_NETWORK_FROM_MEMORY) ||
			   (reader->create_from == GCVIP_CREATE_NETWORK_FROM_FLASH)) {
		if (reader->offset + size <= reader->size) {
			gcvip_user_memcopy(memory, reader->current_data, size);
		} else {
			gcvip_error("reader->offset + Size > reader->size\n");
			status = VIP_ERROR_OUT_OF_RESOURCE;
		}
	} else {
		gcvip_error("not support this create network type=%d\n",
					reader->create_from);
		status = VIP_ERROR_OUT_OF_RESOURCE;
	}

	return status;
}

/***** Read different parts of the binary file. *****/
static vip_status_e read_bin_header(
	gcvip_data_reader *reader,
	gcvip_bin_header_t *header
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;

	static const char magic[4] = {'V', 'P', 'M', 'N'};
	reader_rewind(reader);   /* Go to the beginning. */

	/* Read magic. */
	for (i = 0; i < 4; i++) {
		header->magic[i] = read_byte(reader, 1);
		if (header->magic[i] != magic[i]) {
			gcvip_error("binary magic not match\n");
			gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
		}
	}

	/* Read "Version". */
	header->version = read_uInt(reader, 1);

	/* Read "hardware target". */
	header->hw_target = read_uInt(reader, 1);

	/* Read "network_name". */
	read_data_copy(reader, header->network_name, sizeof(header->network_name));
	reader_forward(reader, sizeof(header->network_name));

	/* Read "Layer_count". */
	header->layer_count = read_uInt(reader, 1);

	/* Read "operation_count". */
	header->operation_count = read_uInt(reader, 1);

	/* Read "input_count". */
	header->input_count = read_uInt(reader, 1);

	/* Read "output_count". */
	header->output_count = read_uInt(reader, 1);

	if (header->version >= 0x00010003) {
		read_data_copy(reader, &header->feature_db, sizeof(gcvip_bin_feature_database_t));
		reader_forward(reader, sizeof(gcvip_bin_feature_database_t));
		if (header->feature_db.core_count > 1) {
			gcvip_error("not support multi-VIP, core count=%d\n",
						header->feature_db.core_count);
			gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
		}
	}

onError:
	return status;
}

static vip_status_e read_bin_pool(
	gcvip_data_reader *reader,
	gcvip_bin_pool_t *pool
)
{
	vip_status_e status = VIP_SUCCESS;

	/* Read "aligned_size". */
	pool->size = read_uInt(reader, 1);

	/* Read "alignment". */
	pool->alignment = read_uInt(reader, 1);

	/* Read "pool_base". */
	pool->base = read_uInt(reader, 1);

	return status;
}

static vip_status_e read_bin_entry(
	gcvip_data_reader *reader,
	gcvip_bin_entry_t *entry
)
{
	vip_status_e status = VIP_SUCCESS;

	entry->offset = read_uInt(reader, 1);
	entry->size = read_uInt(reader, 1);

	return status;
}
static vip_status_e read_bin_fixed(
	gcvip_data_reader *reader,
	vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	GET_CONTEXT();

	/* Read each field. Note that the order is strictly followed. */
	gcOnError(read_bin_header(reader, &network->fixed.header));
	gcOnError(read_bin_pool(reader, &network->fixed.pool));
	network->fixed.axi_sram_base = read_uInt(reader, 1);
	network->fixed.axi_sram_size = read_uInt(reader, 1);
	if (network->fixed.header.version >= 0x00010008) {
		network->fixed.vip_sram_base = read_uInt(reader, 1);
		network->fixed.vip_sram_size = read_uInt(reader, 1);
	}
	gcOnError(read_bin_entry(reader, &network->fixed.input_table));
	gcOnError(read_bin_entry(reader, &network->fixed.output_table));
	gcOnError(read_bin_entry(reader, &network->fixed.layer_table));
	gcOnError(read_bin_entry(reader, &network->fixed.opeartion_table));
	gcOnError(read_bin_entry(reader, &network->fixed.LCD_table));
	gcOnError(read_bin_entry(reader, &network->fixed.LCD));
	gcOnError(read_bin_entry(reader, &network->fixed.nn_op_data_table));
	gcOnError(read_bin_entry(reader, &network->fixed.tp_op_data_table));
	gcOnError(read_bin_entry(reader, &network->fixed.sh_op_data_table));
	gcOnError(read_bin_entry(reader, &network->fixed.patch_data_table));
	gcOnError(read_bin_entry(reader, &network->fixed.layer_param_table));
	gcOnError(read_bin_entry(reader, &network->fixed.sw_op_data_table));
	if (network->fixed.header.version >= 0x0001000C) {
		gcOnError(read_bin_entry(reader, &network->fixed.hw_init_op_table));
		gcOnError(read_bin_entry(reader, &network->fixed.ICD_table));
		gcOnError(read_bin_entry(reader, &network->fixed.ICD));
	} else {
		network->fixed.hw_init_op_table.size = 0;
		network->fixed.ICD_table.size = 0;
		network->fixed.ICD.size = 0;
	}

	if (network->fixed.header.version >= 0x0001000E) {
		gcOnError(read_bin_entry(reader, &network->fixed.ppu_param_table));
		if (0 == network->fixed.header.feature_db.change_ppu_param) {
			network->fixed.ppu_param_table.size = 0;
		}
	} else {
		network->fixed.ppu_param_table.size = 0;
	}

	if (network->fixed.axi_sram_size != context->axi_sram_size) {
		gcvip_debug("info, binary axi-sram size=0x%08X, context=0x%08X\n",
					network->fixed.axi_sram_size, context->axi_sram_size);
		if (network->fixed.axi_sram_size > context->axi_sram_size) {
			gcvip_error("binary axi-sram size=0x%08X, context=0x%08X\n",
						network->fixed.axi_sram_size, context->axi_sram_size);
			gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
		}
	}

	/* check vip sram info */
	if (network->fixed.vip_sram_size > context->vip_sram_size) {
		gcvip_error("binary vip sram size=0x%x, actually size=0x%x\n",
					network->fixed.vip_sram_size, context->vip_sram_size);
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	return status;

onError:
	gcvip_error("failed to read binary file fixed section\n");
	return status;
}

static vip_status_e read_bin_dynamic(
	gcvip_data_reader *reader,
	vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint8_t *dyna_ptr = VIP_NULL;
	GET_CONTEXT();

#if !vpmdCREATE_NETWORK_FROM_FLASH
	vip_uint32_t dyna_size = 0;
	/* Calculate the mem size to put dyna data structures . */
	dyna_size = network->fixed.input_table.size +
				network->fixed.output_table.size +
				network->fixed.layer_table.size +
				network->fixed.opeartion_table.size +
				network->fixed.sh_op_data_table.size +
				network->fixed.patch_data_table.size +
				network->fixed.layer_param_table.size +
				network->fixed.sw_op_data_table.size +
				network->fixed.LCD_table.size +
				network->fixed.hw_init_op_table.size +
				network->fixed.ICD_table.size +
				network->fixed.ICD.size +
				network->fixed.ppu_param_table.size;
#endif

	/* Create the memory to put all dyna data structures in,
	   then set the pointers in network to this memory with offsets.
	   Since LCD data will be directly accessed by VIP */
#if vpmdCREATE_NETWORK_FROM_FLASH
	network->LCD.physical = network->flash_physical + network->fixed.LCD.offset;
	network->LCD.logical = network->flash_logical + network->fixed.LCD.offset;
	network->LCD.handle = VIP_NULL;
#else
	gcOnError(gcvip_user_allocate_memory(dyna_size, &network->dyna_data));
	gcvip_user_zero_memory(network->dyna_data, dyna_size);

	gcOnError(gcvip_user_allocate_videomemory(&network->LCD.logical, &network->LCD.handle,
			  &network->LCD.physical, network->fixed.LCD.size,
			  gcdVIP_SH_ALIGN_SIZE));
	gcvip_user_zero_memory(network->LCD.logical, network->fixed.LCD.size);
#endif

	network->LCD.size = network->fixed.LCD.size;
	dyna_ptr = (vip_uint8_t *)network->dyna_data;

	/****** Copy data and set each pointer. ******/
	/* Input data entries. */
	if (network->fixed.input_table.size > 0) {
		reader_locate(reader, network->fixed.input_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.input_table.size);
		network->inputs = (gcvip_bin_inout_entry_t *)dyna_ptr;
		dyna_ptr += network->fixed.input_table.size;
		if (network->fixed.header.version >= 0x0001000B) {
			network->n_inputs = network->fixed.input_table.size / sizeof(gcvip_bin_inout_entry_t);
		} else if ((network->fixed.header.version >= 0x00010004) &&
				   (network->fixed.header.version < 0x0001000B)) {
			network->n_inputs = network->fixed.input_table.size /
								(sizeof(gcvip_bin_inout_entry_t) - sizeof(vip_uint32_t) *
								 (MAX_NUM_DIMS - OLD_NBG_MAX_DIMS));
		} else {
			vip_uint32_t size = sizeof(vip_char_t) * MAX_IO_NAME_LEGTH;
			network->n_inputs = network->fixed.input_table.size /
								(sizeof(gcvip_bin_inout_entry_t) - size -
								 sizeof(vip_uint32_t) * (MAX_NUM_DIMS - OLD_NBG_MAX_DIMS));
		}
	}

	/* Output data entries. */
	if (network->fixed.output_table.size > 0) {
		reader_locate(reader, network->fixed.output_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.output_table.size);
		network->outputs = (gcvip_bin_inout_entry_t *)dyna_ptr;
		dyna_ptr += network->fixed.output_table.size;
		if (network->fixed.header.version >= 0x0001000B) {
			network->n_outputs = network->fixed.output_table.size / sizeof(gcvip_bin_inout_entry_t);
		} else if ((network->fixed.header.version >= 0x00010004) &&
				   (network->fixed.header.version < 0x0001000B)) {
			network->n_outputs = network->fixed.output_table.size /
								 (sizeof(gcvip_bin_inout_entry_t) - sizeof(vip_uint32_t) *
								  (MAX_NUM_DIMS - OLD_NBG_MAX_DIMS));
		} else {
			network->n_outputs = network->fixed.output_table.size /
								 (sizeof(gcvip_bin_inout_entry_t) -
								  sizeof(vip_char_t) * MAX_IO_NAME_LEGTH -
								  sizeof(vip_uint32_t) * (MAX_NUM_DIMS - OLD_NBG_MAX_DIMS));
		}
	}

	/* Layer data entries. */
	if (network->fixed.layer_table.size > 0) {
		reader_locate(reader, network->fixed.layer_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.layer_table.size);
		network->orig_layers = (gcvip_bin_layer_t *)dyna_ptr;
		dyna_ptr += network->fixed.layer_table.size;
		if (network->fixed.header.version >= 0x00010008) {
			network->n_orig_layers = network->fixed.layer_table.size / sizeof(gcvip_bin_layer_t);
		} else {
			network->n_orig_layers = network->fixed.layer_table.size /
									 (sizeof(gcvip_bin_layer_t) - sizeof(vip_uint32_t));
		}
	}

	/* operation data entries. */
	if (network->fixed.opeartion_table.size > 0) {
		reader_locate(reader, network->fixed.opeartion_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.opeartion_table.size);
		network->operations = (gcvip_bin_operation_t *)dyna_ptr;
		dyna_ptr += network->fixed.opeartion_table.size;
		network->n_operations = network->fixed.opeartion_table.size / sizeof(gcvip_bin_operation_t);
	}

	/* NN op data entries. */
	if (network->fixed.nn_op_data_table.size > 0) {
		/* request video memory */
		network->nnCmds.size = network->fixed.nn_op_data_table.size;
		gcOnError(gcvip_user_allocate_videomemory(&network->nnCmds.logical, &network->nnCmds.handle,
				  &network->nnCmds.physical, network->nnCmds.size,
				  gcdVIP_MEMORY_ALIGN_SIZE));
		gcvip_user_zero_memory(network->nnCmds.logical, network->nnCmds.size);

		reader_locate(reader, network->fixed.nn_op_data_table.offset);
		read_data_copy(reader, network->nnCmds.logical, network->fixed.nn_op_data_table.size);
		network->nn_ops = (void *)network->nnCmds.logical;
		if (GCVIP_NN_COMMAND_SIZE_192 == network->fixed.header.feature_db.nn_command_size) {
			network->n_nn_ops = network->fixed.nn_op_data_table.size / sizeof(gcvip_bin_nn_operation_192bytes_t);
		} else {
			network->n_nn_ops = network->fixed.nn_op_data_table.size / sizeof(gcvip_bin_nn_operation_t);
		}
	}

	/* TP op data entries. */
	if (network->fixed.tp_op_data_table.size > 0) {
		/* request video memory */
		network->tpCmds.size = network->fixed.tp_op_data_table.size;
		gcOnError(gcvip_user_allocate_videomemory(&network->tpCmds.logical, &network->tpCmds.handle,
				  &network->tpCmds.physical, network->tpCmds.size,
				  gcdVIP_MEMORY_ALIGN_SIZE));
		gcvip_user_zero_memory(network->tpCmds.logical, network->tpCmds.size);

		reader_locate(reader, network->fixed.tp_op_data_table.offset);
		read_data_copy(reader, network->tpCmds.logical, network->fixed.tp_op_data_table.size);
		network->tp_ops = (gcvip_bin_tp_operation_t *)network->tpCmds.logical;
		network->n_tp_ops = network->fixed.tp_op_data_table.size / sizeof(gcvip_bin_tp_operation_t);
	}

	/* SH op data entries. */
	if (network->fixed.sh_op_data_table.size > 0) {
		reader_locate(reader, network->fixed.sh_op_data_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.sh_op_data_table.size);
		network->sh_ops = (gcvip_bin_sh_operation_t *)dyna_ptr;
		dyna_ptr += network->fixed.sh_op_data_table.size;
		if (network->fixed.header.version >= 0x0001000E) {
			network->n_sh_ops = network->fixed.sh_op_data_table.size / sizeof(gcvip_bin_sh_operation_t);
		} else {
			network->n_sh_ops = network->fixed.sh_op_data_table.size /
								(sizeof(gcvip_bin_sh_operation_t) - sizeof(vip_uint32_t));
		}
	}

	/* Patch data entries. */
	if (network->fixed.patch_data_table.size > 0) {
		reader_locate(reader, network->fixed.patch_data_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.patch_data_table.size);
		network->pd_entries = (gcvip_bin_patch_data_entry_t *)dyna_ptr;
		dyna_ptr += network->fixed.patch_data_table.size;

		if (network->fixed.header.version >= 0x00010006) {
			network->n_pd_entries = network->fixed.patch_data_table.size /
									sizeof(gcvip_bin_patch_data_entry_t);
		} else {
			network->n_pd_entries = network->fixed.patch_data_table.size /
									(sizeof(gcvip_bin_patch_data_entry_t) - sizeof(vip_uint32_t));
		}
	}
	/*Layer Parameter Entrance*/
	if (network->fixed.layer_param_table.size > 0) {
		reader_locate(reader, network->fixed.layer_param_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.layer_param_table.size);
		network->lp_entries = (gcvip_bin_layer_parameter_t *)dyna_ptr;
		dyna_ptr += network->fixed.layer_param_table.size;
		network->n_layer_param = network->fixed.layer_param_table.size /
								 sizeof(gcvip_bin_layer_parameter_t);
	}
	/*Software Operation Data Table Entrance*/
	if (network->fixed.sw_op_data_table.size > 0) {
		reader_locate(reader, network->fixed.sw_op_data_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.sw_op_data_table.size);
		network->sw_ops = (gcvip_bin_sw_operation_info_t *)dyna_ptr;
		dyna_ptr += network->fixed.sw_op_data_table.size;
		if (network->fixed.header.version >= 0x00010009) {
			network->n_sw_ops = network->fixed.sw_op_data_table.size /
								sizeof(gcvip_bin_sw_operation_info_t);
		} else {
			network->n_sw_ops = network->fixed.sw_op_data_table.size /
								(sizeof(gcvip_bin_sw_operation_info_t) -
								 sizeof(vip_char_t) * MAX_SW_LAYER_NAME_LENGTH);
		}
	}

	/* LCDT data entries. */
	if (network->fixed.LCD_table.size > 0) {
		reader_locate(reader, network->fixed.LCD_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.LCD_table.size);
		network->LCDT = (gcvip_bin_entry_t *)dyna_ptr;
		dyna_ptr += network->fixed.LCD_table.size;
		network->n_LCDT = network->fixed.LCD_table.size / sizeof(gcvip_bin_entry_t);
	}

	/* HW initialize commands Entrance */
	if (network->fixed.hw_init_op_table.size > 0) {
		reader_locate(reader, network->fixed.hw_init_op_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.hw_init_op_table.size);
		network->init_ops = (gcvip_bin_hw_init_operation_info_entry_t *)dyna_ptr;
		dyna_ptr += network->fixed.hw_init_op_table.size;
		network->n_hw_init_ops = network->fixed.hw_init_op_table.size /
								 sizeof(gcvip_bin_hw_init_operation_info_entry_t);
	}

	/* ICDT */
	if (network->fixed.ICD_table.size > 0) {
		reader_locate(reader, network->fixed.ICD_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.ICD_table.size);
		network->ICDT = (gcvip_bin_entry_t *)dyna_ptr;
		dyna_ptr += network->fixed.ICD_table.size;
		network->n_ICDT = network->fixed.ICD_table.size / sizeof(gcvip_bin_entry_t);
	}

	/* PPU param */
	if (network->fixed.ppu_param_table.size > 0) {
		reader_locate(reader, network->fixed.ppu_param_table.offset);
		read_data(reader, &dyna_ptr, network->fixed.ppu_param_table.size);
		network->ppu_param = (gcvip_ppu_param_data_t *)dyna_ptr;
		dyna_ptr += network->fixed.ppu_param_table.size;
		network->n_ppu_param = network->fixed.ppu_param_table.size / sizeof(gcvip_ppu_param_data_t);

#if vpmdENABLE_CHANGE_PPU_PARAM
		if (network->n_ppu_param > 0) {
			vip_uint32_t size = sizeof(vip_ppu_param_patch_info_t) * network->n_ppu_param;
			gcOnError(gcvip_user_allocate_memory(size, (void **)&network->ppu_param_info));
			gcvip_user_zero_memory(network->ppu_param_info, size);
		} else {
			gcvip_error("failed the ppu param number=%d\n", network->n_ppu_param);
		}
#endif
	}

	/* ICD */
#if vpmdENABLE_MULTIPLE_TASK
	status = gcvip_os_lock_mutex(context->init_cmds_mutex);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to lock init cmds mutex\n");
	}
#endif
	if ((network->fixed.ICD.size > 0) && (VIP_NULL == context->ICD.handle)) {
		/* request video memory */
		context->ICD.size = network->fixed.ICD.size;
		gcOnError(gcvip_user_allocate_videomemory(&context->ICD.logical,
				  &context->ICD.handle,
				  &context->ICD.physical,
				  context->ICD.size,
				  gcdVIP_SH_ALIGN_SIZE));
		gcvip_user_zero_memory(context->ICD.logical, context->ICD.size);

		reader_locate(reader, network->fixed.ICD.offset);
		read_data_copy(reader, context->ICD.logical, context->ICD.size);
	}
#if vpmdENABLE_MULTIPLE_TASK
	status = gcvip_os_unlock_mutex(context->init_cmds_mutex);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to unlock init cmds mutex\n");
	}
#endif

	/* LCD. */
	if (network->fixed.LCD.size > 0) {
		reader_locate(reader, network->fixed.LCD.offset);
		read_data(reader, &network->LCD.logical, network->fixed.LCD.size);
	} else {
		gcvip_error("failed to read binary , lcd size is 0\n");
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	return status;

onError:
	gcvip_error("failed to read binary file dynamic section\n");
	return status;
}

vip_uint32_t gcvip_get_io_buffer_size(
	gcvip_bin_inout_entry_t *entry
)
{
	vip_uint32_t i = 0;
	vip_uint32_t size = 0;

	size = gcvip_get_format_size((vip_enum)entry->data_format);

	for (i = 0; i < entry->dim_count; i++) {
		size *= entry->dim_size[i];
	}

	return size;
}

void *gcvip_get_patch_ptr_by_index(
	vip_network_t *network,
	gcvip_bin_patch_data_entry_t *patch_ptr,
	vip_int32_t index
)
{
	void *ptr = VIP_NULL;
	vip_uint32_t size = 0;

	size = sizeof(gcvip_bin_patch_data_entry_t) - sizeof(vip_uint32_t);

	if (network->fixed.header.version >= 0x00010006) {
		ptr = (void *)(patch_ptr + index);
	} else {
		ptr = (void *)((vip_int8_t *)patch_ptr + index * size);
	}

	return ptr;
}

#if vpmdENABLE_FLUSH_CPU_CACHE
static void *search_video_memory_handle(
	vip_network_t *network,
	vip_uint32_t physical
)
{
	void *handle = VIP_NULL;
	vip_uint32_t i = 0;

	if ((physical > network->nnCmds.physical) &&
		(physical < (network->nnCmds.physical + network->nnCmds.size))) {
		handle = network->nnCmds.handle;
	} else if ((physical > network->tpCmds.physical) &&
			   (physical < (network->tpCmds.physical + network->tpCmds.size))) {
		handle = network->tpCmds.handle;
	} else {
		for (i = 0; i < network->segment_num; i++) {
			gcvip_lite_segment_t *segment = &network->segments[i];
			vip_uint32_t tmp_size = segment->states_buffer.physical + segment->states_buffer.size;
			if (segment->is_sw_segm == vip_false_e) {
				if ((physical > segment->states_buffer.physical) && (physical < tmp_size)) {
					handle = segment->states_buffer.handle;
					break;
				}
			}
		}
	}

	return handle;
}
#endif

static vip_uint32_t *gcvip_append_link(
	vip_uint32_t *command,
	vip_uint32_t bytes,
	vip_uint32_t address
)
{
	command[1] = address;
	command[0] = ((8 << 27) | ((bytes + 7) >> 3));

	return &command[0];
}

vip_char_t *gcvip_get_layer_name(
	vip_network_t *network,
	vip_uint32_t layer_id
)
{
	vip_uint32_t i = 0;
	vip_char_t *name = VIP_NULL;
	gcvip_bin_layer_t *orig_layer = VIP_NULL;

	for (i = 0; i < network->n_orig_layers; i++) {
		if (network->fixed.header.version >= 0x00010008) {
			orig_layer = &network->orig_layers[i];
		} else {
			vip_uint32_t size = sizeof(gcvip_bin_layer_t) - sizeof(vip_uint32_t);
			orig_layer = (void *)((vip_int8_t *)network->orig_layers + i * size);
		}

		if (layer_id == orig_layer->id) {
			name = orig_layer->name;
		}
	}

	return name;
}

vip_uint32_t gcvip_get_layer_uid(
	vip_network_t *network,
	vip_uint32_t layer_id
)
{
	vip_uint32_t i = 0;
	vip_uint32_t uid = 0;

	if (network->fixed.header.version < 0x00010008) {
		return 0;
	}

	for (i = 0; i < network->n_orig_layers; i++) {
		gcvip_bin_layer_t *orig_layer = &network->orig_layers[i];
		if (layer_id == orig_layer->id) {
			uid = orig_layer->uid;
		}
	}

	return uid;
}

#if vpmDUMP_NETWORK_RESOURCE
static vip_status_e dump_network_outputs(
	vip_network_t *network
)
{
	vip_uint32_t i = 0;

	for (i = 0; i < network->fixed.header.output_count; i++) {
		vip_char_t name[256];
		vip_uint32_t size = 0;
		void *fp = VIP_NULL;
		gcvip_bin_inout_entry_t *ptr_io = VIP_NULL;

		ptr_io = (gcvip_bin_inout_entry_t *)gcvip_get_io_ptr_by_index(network, network->outputs, i);
		size = gcvip_get_io_buffer_size(ptr_io);
		gcvip_os_snprint(name, 255, "viplite_output_%d.dat", i);
		fp = gcvip_os_open_file(name, FILE_CREATE);
		if (fp != VIP_NULL) {
			gcvip_os_write_file(network->network_outputs[i].logical, size, fp);
			gcvip_os_close_file(fp);
		} else {
			gcvip_error("failed to dump output, can't open file %s\n", name);
		}
	}

	return VIP_SUCCESS;
}

static vip_status_e dump_network_inputs(
	vip_network_t *network
)
{
	vip_char_t name[256];
	void *fp = VIP_NULL;
	vip_uint32_t size = 0;
	vip_uint32_t i = 0;
	gcvip_bin_inout_entry_t *ptr_io = VIP_NULL;

	for (i = 0; i < network->n_inputs; i++) {
		gcvip_io_patch_info_t *input = &network->network_inputs[i];
		ptr_io = (gcvip_bin_inout_entry_t *)gcvip_get_io_ptr_by_index(network,
				 network->inputs,
				 i);
		gcvip_os_snprint(name, 255, "viplite_input_%d.dat", i);
		size = gcvip_get_io_buffer_size(ptr_io);
		fp = gcvip_os_open_file(name, FILE_CREATE);
		if (fp != VIP_NULL) {
			gcvip_os_write_file(input->logical, size, fp);
			gcvip_os_close_file(fp);
		} else {
			gcvip_error("failed to dump input, can't open file %s\n", name);
		}
	}

	return VIP_SUCCESS;
}

static vip_status_e dump_save_file(
	vip_char_t *name,
	void *data,
	vip_uint32_t size
)
{
	void *fp = VIP_NULL;

	if ((VIP_NULL == data) || (0 == size)) {
		gcvip_error("failed to dump file, param is NULL\n");
		return VIP_ERROR_FAILURE;
	}

	fp = gcvip_os_open_file(name, FILE_CREATE);
	if (fp != VIP_NULL) {
		gcvip_os_write_file(data, size, fp);
		gcvip_os_close_file(fp);
	} else {
		gcvip_error("failed to dump data, can't open file %s\n", name);
		return VIP_ERROR_FAILURE;
	}

	return VIP_SUCCESS;
}
#endif

#if vpmdENABLE_CHANGE_PPU_PARAM
static vip_status_e gcvip_change_ppu_shape(
	vip_network network,
	gcvip_bin_inout_entry_t *io_entry,
	gcvip_io_patch_info_t *io_patch,
	vip_uint32_t index
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_bin_inout_entry_t *ptr_io = VIP_NULL;
	vip_uint32_t *address = VIP_NULL;
	vip_uint32_t op_code = 0;
	vip_buffer buffer = io_patch->buffer;

	if (io_patch->slice_num > 1) {
		gcvip_error("not support change ppu shape, io slice_num=%d\n", io_patch->slice_num);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	if ((VIP_NULL == io_patch->logical_in_cmd[0]) && (VIP_NULL == io_patch->sw_op_buffer)) {
		gcvip_error("failed logical_in_cmd[0] is NULL and sw_op_buffer is NULL\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	ptr_io = (gcvip_bin_inout_entry_t *)gcvip_get_io_ptr_by_index(network,
			 io_entry,
			 index);
	if (ptr_io->dim_count != buffer->param.num_of_dims) {
		gcvip_error("failed to shape, index[%d], nbg dim_count=%d, bufer dim_count=%d, not matched\n",
					index, ptr_io->dim_count, buffer->param.num_of_dims);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	address = (vip_uint32_t *)(gcvip_uintptr_t)io_patch->logical_in_cmd[0];

	if ((GCVIP_BUFFER_TYPE_TENSOR == ptr_io->data_type) ||
		(GCVIP_BUFFER_TYPE_IMAGE == ptr_io->data_type)) {
		op_code = *(address - 1);
		if ((op_code & 0x0804d800) != 0x0804d800) {
			gcvip_error("not change ppu shape, may not ppu node, data_type=%d\n", ptr_io->data_type);
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}
	}

	if (buffer->param.data_format != ptr_io->data_format) {
		gcvip_error("buffer format=%d not equal to format=%d in nbg\n",
					buffer->param.data_format, ptr_io->data_format);
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	switch (ptr_io->data_type) {
	case GCVIP_BUFFER_TYPE_TENSOR: {
		vip_uint32_t stride[3] = {0, 0, 0};
		vip_uint32_t size[3] = {0, 0, 0};
		vip_uint32_t depth = 0;

		if (1 == buffer->param.num_of_dims) {
			size[0] = buffer->param.sizes[0];
		} else if (2 == buffer->param.num_of_dims) {
			size[0] = buffer->param.sizes[0];
			size[1] = buffer->param.sizes[1];
		} else if (3 == buffer->param.num_of_dims) {
			size[0] = buffer->param.sizes[0];
			size[1] = buffer->param.sizes[1];
			size[2] = buffer->param.sizes[2];
		} else if (buffer->param.num_of_dims > 3) {
			size[0] = buffer->param.sizes[0];
			size[1] = buffer->param.sizes[1];
			size[2] = buffer->param.sizes[2];
			if (buffer->param.sizes[3] > 1) {
				gcvip_error("buffer dim_num=%d, shape[3]=%d\n", buffer->param.num_of_dims,
							buffer->param.sizes[3]);
				gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
			}
		}

		if (buffer->param.num_of_dims >= 3) {
			depth = size[2];
		} else {
			depth = 1;
		}

		stride[0] = gcvip_get_format_size(buffer->param.data_format);
		stride[1] = stride[0] * size[0];
		stride[2] = stride[1] * size[1];

		*(address + 1) = stride[1];
		*(address + 2) = size[0] | (size[1] << 16);

		/* height <= 1 sh image is 1D, other than sh imag is 2D */
		if (buffer->param.sizes[1] <= 1) {
			vip_uint32_t data = *(address + 3);
			*(address + 3) =  data & (~(1 << 12));
		} else {
			vip_uint32_t data = *(address + 3);
			*(address + 3) =  data | (1 << 12);
		}

		*(address + 6) = stride[2];
		*(address + 7) = depth;
	}
	break;

	case GCVIP_BUFFER_TYPE_IMAGE: {
		vip_uint32_t stride[3] = {0, 0, 0};
		vip_uint32_t size[3] = {0, 0, 0};

		if (1 == buffer->param.num_of_dims) {
			size[0] = buffer->param.sizes[0];
		} else if (2 == buffer->param.num_of_dims) {
			size[0] = buffer->param.sizes[0];
			size[1] = buffer->param.sizes[1];
		} else if (3 == buffer->param.num_of_dims) {
			size[0] = buffer->param.sizes[0];
			size[1] = buffer->param.sizes[1];
			size[2] = buffer->param.sizes[2];
		} else if (buffer->param.num_of_dims > 3) {
			size[0] = buffer->param.sizes[0];
			size[1] = buffer->param.sizes[1];
			size[2] = buffer->param.sizes[2];
			if (buffer->param.sizes[3] > 1) {
				gcvip_error("buffer dim_num=%d, shape[3]=%d\n", buffer->param.num_of_dims,
							buffer->param.sizes[3]);
				gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
			}
		}

		stride[0] = gcvip_get_format_size(buffer->param.data_format);
		stride[1] = stride[0] * size[0];
		stride[2] = stride[1] * size[1];

		*(address + 1) = stride[1];
		*(address + 2) = size[0] | (size[1] << 16);

		/* height <= 1 sh image is 1D, other than sh imag is 2D */
		if (buffer->param.sizes[1] <= 1) {
			vip_uint32_t data = *(address + 3);
			*(address + 3) =  data & (~(1 << 12));
		} else {
			vip_uint32_t data = *(address + 3);
			*(address + 3) =  data | (1 << 12);
		}

		*(address + 6) = stride[2];
		*(address + 7) = size[2];
	}
	break;

	case GCVIP_BUFFER_TYPE_SCALAR:
		break;

	case GCVIP_BUFFER_TYPE_ARRAY: {
		*(address - 1) = buffer->param.sizes[0];
		if (buffer->param.sizes[1] > 1) {
			gcvip_error("change ppu shape, array shape[%d, %d]\n",
						buffer->param.sizes[0], buffer->param.sizes[1]);
		}
	}
	break;

	default:
		gcvip_error("not support this data type=%d\n", ptr_io->data_type);
		break;
	}

onError:
	return status;
}

static vip_status_e patch_ppu_params(
	vip_network network,
	vip_uint8_t *state_buf,
	vip_uint32_t state_size,
	gcvip_bin_sh_operation_t *shop
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_ppu_param_data_t *ppu_param_data = &network->ppu_param[shop->ppu_param_index];
	vip_ppu_param_patch_info_t *ppu_param_i = VIP_NULL;
	vip_uint32_t *cmd = (vip_uint32_t *)state_buf;
	vip_uint32_t i = 0;

	if (VIP_NULL == network->ppu_param_info) {
		gcvip_error("failed to patch ppu param, ppu_param_info is NULL\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	ppu_param_i = &network->ppu_param_info[shop->ppu_param_index];

	ppu_param_i->glooffset_x_logic = (vip_address_t *)(state_buf + ppu_param_data->global_offset_x);
	ppu_param_i->glooffset_y_logic = (vip_address_t *)(state_buf + ppu_param_data->global_offset_y);
	ppu_param_i->glooffset_z_logic = (vip_address_t *)(state_buf + ppu_param_data->global_offset_z);

	ppu_param_i->gloscale_x_logic = (vip_address_t *)(state_buf + ppu_param_data->global_scale_x);
	ppu_param_i->gloscale_y_logic = (vip_address_t *)(state_buf + ppu_param_data->global_scale_y);
	ppu_param_i->gloscale_z_logic = (vip_address_t *)(state_buf + ppu_param_data->global_scale_z);

	ppu_param_i->grosize_x_logic = (vip_address_t *)(state_buf + ppu_param_data->group_size_x);
	ppu_param_i->grosize_y_logic = (vip_address_t *)(state_buf + ppu_param_data->group_size_y);
	ppu_param_i->grosize_z_logic = (vip_address_t *)(state_buf + ppu_param_data->group_size_z);

	ppu_param_i->grocount_x_logic = (vip_address_t *)(state_buf + ppu_param_data->group_count_x);
	ppu_param_i->grocount_y_logic = (vip_address_t *)(state_buf + ppu_param_data->group_count_y);
	ppu_param_i->grocount_z_logic = (vip_address_t *)(state_buf + ppu_param_data->group_count_z);

	for (i = 0; i < (state_size / sizeof(vip_uint32_t)); i++) {
		if (0x08010240 == cmd[i]) {
			network->ppu_work_dim = cmd[i + 1] & 0x3;
			break;
		}
	}

onError:
	return status;
}
#endif

/*
@ brief
    insert link command in command buffer
*/
static vip_status_e gcvip_patch_link(
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint8_t i = 0;
	vip_uint8_t *command = (vip_uint8_t *)segment->states_buffer.logical;
	vip_uint32_t physical = segment->states_buffer.physical;
	vip_uint32_t location = 0;
	vip_uint32_t size = 0;
	vip_uint32_t total = 0;
	vip_uint32_t *split_size = (vip_uint32_t *)segment->split_size;
	vip_uint32_t *patch_loc = (vip_uint32_t *)segment->patch_pos;

	if (segment->patch_num < 1) {
		return VIP_SUCCESS;
	}

	total = split_size[0];

	gcvip_info("index: 0, command buffer phy=0x%08X, link command size=0x%08X, patch num=%d\n",
			   physical, total, segment->patch_num);

	for (i = 0; i < segment->patch_num; i++) {
		location = patch_loc[i];
		if (i == (segment->patch_num - 1)) {
			/* this is the last split */
			size = split_size[i + 1] + APPEND_COMMAND_SIZE;
		} else {
			size = split_size[i + 1];
		}

		gcvip_info("index: %d, insert link location: 0x%08X, link command size: 0x%08X\n",
				   i, location, size);

		gcvip_append_link((vip_uint32_t *)(command + location), size, physical + location + LINK_SIZE);

		total += split_size[i + 1];
	}

	if (segment->states_buffer.size != total) {
		gcvip_error("insert link command failed total size: 0x%08X, submit->size: 0x%08X\n",
					total, segment->states_buffer.size);
		return VIP_ERROR_NOT_SUPPORTED;
	}

	return status;
}

static vip_status_e patch_source_input(
	vip_network_t *network,
	vip_uint8_t *cmd_logical,
	vip_uint32_t cmd_physical,
	gcvip_bin_patch_data_entry_t *patch
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint8_t *patch_addr = VIP_NULL;
	vip_address_t *ref_addr = VIP_NULL;
	vip_int32_t io_index = patch->index;
	gcvip_io_patch_info_t *input = VIP_NULL;
	vip_uint32_t counter = 0;

	patch_addr = (vip_uint8_t *)cmd_logical + patch->offset_in_states;

	if ((io_index >= 0) && (io_index < (vip_int32_t)network->fixed.header.input_count)) {
		input = &network->network_inputs[io_index];
		counter = network->network_inputs[io_index].counter;
		ref_addr = input->logical_in_cmd + counter;
		*ref_addr = (vip_address_t)(gcvip_uintptr_t)patch_addr;
		input->physical_in_cmd[counter] = (vip_uint32_t)(cmd_physical + patch->offset_in_states);
		if (0 == network->prepare_count) {
			input->offsets[counter] = *((vip_uint32_t *)patch_addr) - patch->orig_base;
			patch->orig_base = input->offsets[counter];
		} else {
			input->offsets[counter] = patch->orig_base;
		}
		input->counter++;
	} else {
		gcvip_error("failed to patch network input. ioindex is %d\n", io_index);
		status = VIP_ERROR_IO;
	}

	return status;
}

static vip_status_e patch_source_output(
	vip_network_t *network,
	vip_uint8_t *cmd_logical,
	vip_uint32_t cmd_physical,
	gcvip_bin_patch_data_entry_t *patch
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_int32_t io_index = patch->index;
	vip_uint8_t *patch_addr = VIP_NULL;
	vip_address_t *ref_addr = VIP_NULL;
	gcvip_io_patch_info_t *output = VIP_NULL;
	vip_uint32_t  counter = 0;

	patch_addr = (vip_uint8_t *)cmd_logical + patch->offset_in_states;

	if ((io_index >= 0) && (io_index < (vip_int32_t)network->fixed.header.output_count)) {
		output = &network->network_outputs[io_index];
		counter = network->network_outputs[io_index].counter;
		ref_addr = &output->logical_in_cmd[counter];
		*ref_addr = (vip_address_t)(gcvip_uintptr_t)patch_addr;
		output->physical_in_cmd[counter] = (vip_uint32_t)(cmd_physical + patch->offset_in_states);
		if (0 == network->prepare_count) {
			output->offsets[counter] = *((vip_uint32_t *)patch_addr) - patch->orig_base;
			patch->orig_base = output->offsets[counter];
		} else {
			output->offsets[counter] = patch->orig_base;
		}
		output->counter++;
	} else {
		gcvip_error("failed to patch network output. ioindex is %d\n", io_index);
		status = VIP_ERROR_IO;
	}

	return status;
}

static vip_status_e patch_source_mempool(
	vip_network_t *network,
	vip_uint8_t *command,
	gcvip_bin_patch_data_entry_t *patch
)
{
	vip_uint32_t old_addr = ~0;
	vip_uint32_t new_addr = ~0;
	vip_uint32_t *patch_addr = VIP_NULL;
	vip_status_e status = VIP_SUCCESS;

	patch_addr = (vip_uint32_t *)(command + patch->offset_in_states);
	old_addr = *patch_addr;
	if (0 == network->prepare_count) {
		new_addr = network->pool.physical + (old_addr - patch->orig_base);
		/* save patch offset into orig_base for next prepare network */
		patch->orig_base = old_addr - patch->orig_base;
	} else {
		new_addr = network->pool.physical + patch->orig_base;
	}

	*patch_addr = new_addr;

	if (patch->transformed == GCVIP_PATCH_TRANSFORMATION_RIGHT_SHIFT_6) {
		gcvip_error("error, don't support right shift 6 bits in memory pool\n");
		status = VIP_ERROR_FAILURE;
	}

	return status;
}

static vip_status_e patch_source_sram(
	vip_network_t *network,
	vip_uint8_t *command,
	gcvip_bin_patch_data_entry_t *patch,
	vip_uint32_t type
)
{
	vip_uint32_t *mem_addr = VIP_NULL;
	vip_uint32_t src_addr = 0;
	vip_uint32_t dst_addr = 0;
	vip_uint32_t base_physical = 0;
	vip_status_e status = VIP_SUCCESS;
	GET_CONTEXT();

	if (GCVIP_SOURCE_AXI_SRAM == type) {
		base_physical = context->axi_sram_base;
	} else if (GCVIP_SOURCE_VIP_SRAM == type) {
		base_physical = context->vip_sram_base;
	} else {
		gcvip_error("fail to patch sram, type error\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	mem_addr = (vip_uint32_t *)(command + patch->offset_in_states);
	src_addr = *mem_addr;
	if (patch->transformed == GCVIP_PATCH_TRANSFORMATION_RIGHT_SHIFT_6) {
		src_addr &= ~0u >> 6;
		if ((network->fixed.header.version < 0x00010007)) {
			/* after NBG format 0x00010007 version, store offset in command buffer,
			   don't need shift 6bits if store offset in NBG */
			src_addr <<= 6;
		}
	}

	if (0 == network->prepare_count) {
		dst_addr = (src_addr - patch->orig_base) + base_physical;
		/* save patch offset into orig_base for next prepare network */
		patch->orig_base = src_addr - patch->orig_base;
	} else {
		dst_addr = patch->orig_base + base_physical;
	}

	if (patch->transformed == GCVIP_PATCH_TRANSFORMATION_RIGHT_SHIFT_6) {
		dst_addr = ((*mem_addr) & 0xfc000000) | (dst_addr >> 6);
	}
	*mem_addr = dst_addr;

#if vpmdENABLE_LAYER_DUMP
	gcvip_error("this NBG doesn't support layer dump, please re-genereate a NBG\n");
#endif

onError:
	return status;
}

/*
 * @brief
 * Patch the NN command data to apply the actual pool base.
 */
static vip_status_e patch_nn(
	vip_uint8_t *nn_source,
	vip_uint8_t *states,
	gcvip_bin_operation_t *operation,
	vip_network_t *network,
	vip_uint32_t *size,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint8_t *nn_cmd_logical = VIP_NULL;
	vip_uint8_t *states_buffer = VIP_NULL;
	vip_uint32_t *trigger_word = VIP_NULL;
	vip_uint32_t nn_cmd_physical = ~0;
	gcvip_bin_entry_t *lcdt_entry = VIP_NULL;
	gcvip_bin_patch_data_entry_t *pd_entry = VIP_NULL;
	vip_uint32_t i = 0;

	if (VIP_NULL == segment) {
		gcvip_error("segment is NULL\n");
		return VIP_ERROR_INVALID_NETWORK;
	}

	/* Set shortcuts. */
	nn_cmd_logical = nn_source;
	states_buffer = states;

	nn_cmd_physical = network->nnCmds.physical + (nn_cmd_logical - (vip_uint8_t *)network->nnCmds.logical);

	/* Copy control states. */
	lcdt_entry = &network->LCDT[operation->state_id];
	gcvip_user_memcopy(states_buffer,
					   (vip_uint8_t *)network->LCD.logical + lcdt_entry->offset,
					   lcdt_entry->size);

	/* Query the states size. */
	if (size != VIP_NULL) {
		*size = lcdt_entry->size;
	}

	/* Patch addresses used by the command. */
	for (i = 0; i < operation->patch_count; i++) {
		pd_entry = (gcvip_bin_patch_data_entry_t *)gcvip_get_patch_ptr_by_index(network,
				   network->pd_entries,
				   operation->patch_index + i
																			   );

		if (pd_entry->type == GCVIP_PATCH_TYPE_STATE) {
			/* Patch the control states for NN. */
			states_buffer += pd_entry->offset_in_states;
			trigger_word = (vip_uint32_t *)states_buffer;
			*trigger_word = ((*trigger_word) & 0x3f) | (nn_cmd_physical & ~0x3f);
		} else if (pd_entry->type == GCVIP_PATCH_TYPE_COMMAND) {
			switch (pd_entry->source_type) {
			case GCVIP_SOURCE_INPUT: {
				gcOnError(patch_source_input(network, nn_cmd_logical, nn_cmd_physical, pd_entry));
			}
			break;

			case GCVIP_SOURCE_OUTPUT: {
				gcOnError(patch_source_output(network, nn_cmd_logical, nn_cmd_physical, pd_entry));
			}
			break;

			case GCVIP_SOURCE_MEMORY_POOL: {
				gcOnError(patch_source_mempool(network, nn_cmd_logical, pd_entry));
			}
			break;

			case GCVIP_SOURCE_AXI_SRAM: {
				gcOnError(patch_source_sram(network, nn_cmd_logical, pd_entry, GCVIP_SOURCE_AXI_SRAM));
			}
			break;

			case GCVIP_SOURCE_VIP_SRAM: {
				gcOnError(patch_source_sram(network, nn_cmd_logical, pd_entry, GCVIP_SOURCE_VIP_SRAM));
			}
			break;

			case GCVIP_SOURCE_MISC_DYNA_GENERIC: {
				vip_uint32_t lcdt;
				vip_uint32_t offset = 0;
				vip_uint32_t *addr = (vip_uint32_t *)(nn_cmd_logical + pd_entry->offset_in_states);
				lcdt = network->LCD.physical + network->LCDT[pd_entry->index].offset + offset;
				lcdt >>= 6;
				*addr = ((*addr) & 0xfc000000) | lcdt;

#if (vpmdENABLE_CAPTURE > 1)
				{
					GET_CONTEXT();
					gcvip_debug("dump nn weight/bias\n");
					offset = network->LCDT[pd_entry->index].offset;
					GCVIP_DUMP_STRING(context->capture_file, "#[info=NN KS data]\n");
					gcvip_dump_duffer(context->capture_file,
									  network->LCD.logical + offset,
									  network->LCD.physical + offset,
									  GCVIP_ALIGN(network->LCDT[pd_entry->index].size, 64),
									  GCVIP_DUMP_MEMORY);
				}
#endif
			}
			break;

			case GCVIP_SOURCE_MISC_DYNA_INPUT:
			case GCVIP_SOURCE_MISC_DYNA_OUTPUT: {
				vip_uint32_t offset = 0;
				vip_uint32_t *addr = (vip_uint32_t *)(nn_cmd_logical + pd_entry->offset_in_states);
				if (0 == network->prepare_count) {
					offset = *addr - pd_entry->orig_base;
					pd_entry->orig_base = offset;
				} else {
					offset = pd_entry->orig_base;
				}
				*addr = network->LCD.physical + network->LCDT[pd_entry->index].offset + offset;

#if vpmdENABLE_LAYER_DUMP
				if (pd_entry->source_type == GCVIP_SOURCE_MISC_DYNA_OUTPUT) {
					segment->out_sizes[segment->out_count] = network->LCDT[pd_entry->index].size;
					segment->out_buffers[segment->out_count] = network->LCD.logical +
							network->LCDT[pd_entry->index].offset;
					segment->out_count++;
				}
#endif
			}
			break;

			case GCVIP_SOURCE_COMMAND:
			default:
				gcvip_error("not implement this source_type=%d\n", pd_entry->source_type);
				break;
			}
		}
	}

#if vpmdENABLE_CAPTURE
	{
		vip_uint32_t offset = nn_cmd_logical - (vip_uint8_t *)network->nnCmds.logical;
		vip_uint32_t size = gcvip_get_nn_command_size(network);
		vip_uint32_t layer_id = operation->layer_id;
		gcvip_capture_add_list(segment, offset, size, layer_id,
							   gcvip_get_layer_uid(network, layer_id),
							   NN_COMMAND);
	}
#endif

onError:
	return status;
}

/*
 * @brief
 * Patch the TP command data to apply the actual pool base.
 */
static vip_status_e patch_tp(
	vip_uint8_t *tp_source,
	vip_uint8_t *states,
	gcvip_bin_operation_t *operation,
	vip_network_t *network,
	vip_uint32_t *size,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint8_t *tp_cmd_logical = VIP_NULL;
	vip_uint32_t *trigger_word = VIP_NULL;
	vip_uint8_t *states_buffer = VIP_NULL;
	vip_uint32_t tp_cmd_physical = 0;
	gcvip_bin_entry_t *lcdt_entry = VIP_NULL;
	gcvip_bin_patch_data_entry_t *pd_entry = VIP_NULL;
	vip_uint32_t i = 0;

	if (VIP_NULL == segment) {
		gcvip_error("segment is NULL\n");
		return VIP_ERROR_INVALID_NETWORK;
	}

	/* Set shortcuts. */
	tp_cmd_logical = tp_source;
	states_buffer = states;

	tp_cmd_physical = network->tpCmds.physical + (tp_cmd_logical - (vip_uint8_t *)network->tpCmds.logical);

	/* Copy TP engine control states. */
	lcdt_entry = &network->LCDT[operation->state_id];
	gcvip_user_memcopy(states_buffer, (vip_uint8_t *)network->LCD.logical + lcdt_entry->offset,
					   lcdt_entry->size);

	if (size != VIP_NULL) {
		*size = lcdt_entry->size;
	}

	for (i = 0; i < operation->patch_count; i++) {
		pd_entry = (gcvip_bin_patch_data_entry_t *)gcvip_get_patch_ptr_by_index(network,
				   network->pd_entries,
				   operation->patch_index + i
																			   );

		if (pd_entry->type == GCVIP_PATCH_TYPE_STATE) {
			/* Assert (pd_entry->source_type == 0). */
			states_buffer += pd_entry->offset_in_states;
			trigger_word = (vip_uint32_t *)states_buffer;
			*trigger_word = ((*trigger_word) & 0x3f) | (tp_cmd_physical & ~0x3f);
		} else if (pd_entry->type == GCVIP_PATCH_TYPE_COMMAND) {
			switch (pd_entry->source_type) {
			case GCVIP_SOURCE_INPUT: {
				gcOnError(patch_source_input(network, tp_cmd_logical, tp_cmd_physical, pd_entry));
			}
			break;

			case GCVIP_SOURCE_OUTPUT: {
				gcOnError(patch_source_output(network, tp_cmd_logical, tp_cmd_physical, pd_entry));
			}
			break;

			case GCVIP_SOURCE_MEMORY_POOL: {
				gcOnError(patch_source_mempool(network, tp_cmd_logical, pd_entry));
			}
			break;

			case GCVIP_SOURCE_AXI_SRAM: {
				gcOnError(patch_source_sram(network, tp_cmd_logical, pd_entry, GCVIP_SOURCE_AXI_SRAM));
			}
			break;

			case GCVIP_SOURCE_VIP_SRAM: {
				gcOnError(patch_source_sram(network, tp_cmd_logical, pd_entry, GCVIP_SOURCE_VIP_SRAM));
			}
			break;

			case GCVIP_SOURCE_MISC_DYNA_GENERIC:
			case GCVIP_SOURCE_MISC_DYNA_INPUT:
			case GCVIP_SOURCE_MISC_DYNA_OUTPUT: {
				vip_uint32_t *addr = VIP_NULL;
				vip_uint32_t lcdt = 0;
				vip_uint32_t offset = 0;
				addr = (vip_uint32_t *)(tp_cmd_logical + pd_entry->offset_in_states);
				if (0 == network->prepare_count) {
					offset = *addr - pd_entry->orig_base;
					pd_entry->orig_base = offset;
				} else {
					offset = pd_entry->orig_base;
				}

				if (pd_entry->index >= 0) {
					lcdt = network->LCD.physical + network->LCDT[pd_entry->index].offset + offset;
					*addr = lcdt;
				} else {
					gcvip_error("source type=%d\n", pd_entry->source_type);
					gcOnError(VIP_ERROR_INVALID_NETWORK);
				}

#if vpmdENABLE_LAYER_DUMP
				if (pd_entry->source_type == GCVIP_SOURCE_MISC_DYNA_OUTPUT) {
					segment->out_sizes[segment->out_count] = network->LCDT[pd_entry->index].size;
					segment->out_buffers[segment->out_count] = network->LCD.logical +
							network->LCDT[pd_entry->index].offset;
					segment->out_count++;
				}
#endif

#if (vpmdENABLE_CAPTURE > 1)
				if (pd_entry->source_type == GCVIP_SOURCE_MISC_DYNA_GENERIC) {
					GET_CONTEXT();
					gcvip_debug("dump tp weight/bias\n");
					offset = network->LCDT[pd_entry->index].offset;
					GCVIP_DUMP_STRING(context->capture_file, "#[info=TP KS data]\n");
					gcvip_dump_duffer(context->capture_file, network->LCD.logical + offset,
									  network->LCD.physical + offset,
									  GCVIP_ALIGN(network->LCDT[pd_entry->index].size, 64),
									  GCVIP_DUMP_MEMORY);
				}
#endif
			}
			break;

			case GCVIP_SOURCE_COMMAND:
			default:
				/* assert(false);*/
				gcvip_error("not implement this source_type=%d\n", pd_entry->source_type);
				break;
			}
		}
	}

#if vpmdENABLE_CAPTURE
	{
		vip_uint32_t offset = tp_cmd_logical - (vip_uint8_t *)network->tpCmds.logical;
		vip_uint32_t size = TP_CMD_SIZE;
		vip_uint32_t layer_id = operation->layer_id;
		gcvip_capture_add_list(segment, offset, size, layer_id,
							   gcvip_get_layer_uid(network, layer_id), TP_COMMAND);
	}
#endif

onError:
	return status;
}

/*
 * @brief
 * Patch the SH command data to apply the actual pool base.
 */
static vip_status_e patch_sh(
	gcvip_bin_sh_operation_t *shop,
	vip_uint8_t *cmd_buf,
	vip_uint8_t *state_buf,
	gcvip_bin_operation_t *operation,
	vip_network_t *network,
	vip_uint32_t *cmd_buf_size,
	vip_uint32_t *state_bufSize,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint8_t *commands_logical = VIP_NULL;
	vip_uint32_t commands_physical = 0;
	vip_uint8_t *states = VIP_NULL;
	vip_uint32_t states_physical = 0;
	vip_uint32_t i = 0;

	commands_logical = cmd_buf;
	states = state_buf;

	if (VIP_NULL == segment) {
		gcvip_error("segment is NULL\n");
		return VIP_ERROR_INVALID_NETWORK;
	}

	states_physical = segment->states_buffer.physical +
					  (state_buf - (vip_uint8_t *)segment->states_buffer.logical);

	/* 1. Copy SH command and states. */
	gcvip_user_memcopy(states,
					   (vip_uint8_t *)network->LCD.logical + network->LCDT[operation->state_id].offset,
					   network->LCDT[operation->state_id].size);

	if ((network->fixed.header.version < 0x00010005) || network->realloc_sh_buff) {
		gcvip_user_memcopy(commands_logical,
						   (vip_uint8_t *)network->LCD.logical + network->LCDT[shop->lcdt_index].offset,
						   network->LCDT[shop->lcdt_index].size);
		if (cmd_buf_size != VIP_NULL) {
			*cmd_buf_size = GCVIP_ALIGN(network->LCDT[shop->lcdt_index].size, gcdVIP_SH_ALIGN_SIZE);
		}
		commands_physical = segment->sh_cmd_buffer.physical +
							(commands_logical - segment->sh_cmd_buffer.logical);
	} else {
		commands_logical = (vip_uint8_t *)network->LCD.logical + network->LCDT[shop->lcdt_index].offset;
		commands_physical = network->LCD.physical + network->LCDT[shop->lcdt_index].offset;
	}

	if (state_bufSize != VIP_NULL) {
		*state_bufSize = network->LCDT[operation->state_id].size;
	}

#if vpmdENABLE_CHANGE_PPU_PARAM
	if (network->change_ppu_param && (shop->ppu_param_index < 0xFFFFFFFF)) {
		status = patch_ppu_params(network, states, network->LCDT[operation->state_id].size, shop);
		if (status != VIP_SUCCESS) {
			gcvip_error("failed to patch ppu parameters\n");
			gcGoOnError(VIP_ERROR_INVALID_NETWORK);
		}
	}
#endif

	/* 2. Patch the SH command. */
	for (i = 0; i < operation->patch_count; i++) {
		gcvip_bin_patch_data_entry_t *pd_entry = VIP_NULL;

		pd_entry = (gcvip_bin_patch_data_entry_t *)gcvip_get_patch_ptr_by_index(network,
				   network->pd_entries,
				   operation->patch_index + i
																			   );
		switch (pd_entry->source_type) {
		case GCVIP_SOURCE_COMMAND: { /* Patch the command address to this offset. */
			vip_uint32_t *memory = (vip_uint32_t *)(states + pd_entry->offset_in_states);
			vip_uint32_t cmd_physical = commands_physical;
			if (pd_entry->transformed == GCVIP_PATCH_TRANSFORMATION_RIGHT_SHIFT_6) {
				cmd_physical >>= 6;
			}
			*memory = cmd_physical;
		}
		break;

		case GCVIP_SOURCE_INPUT: {
			gcOnError(patch_source_input(network, states, states_physical, pd_entry));
		}
		break;

		case GCVIP_SOURCE_OUTPUT: {
			gcOnError(patch_source_output(network, states, states_physical, pd_entry));
		}
		break;

		case GCVIP_SOURCE_MEMORY_POOL: {
			gcOnError(patch_source_mempool(network, states, pd_entry));
		}
		break;

		case GCVIP_SOURCE_AXI_SRAM: {
			gcOnError(patch_source_sram(network, states, pd_entry, GCVIP_SOURCE_AXI_SRAM));
		}
		break;

		case GCVIP_SOURCE_VIP_SRAM: {
			gcOnError(patch_source_sram(network, states, pd_entry, GCVIP_SOURCE_VIP_SRAM));
		}
		break;

		case GCVIP_SOURCE_MISC_DYNA_GENERIC:
		case GCVIP_SOURCE_MISC_DYNA_INPUT:
		case GCVIP_SOURCE_MISC_DYNA_OUTPUT: {
			vip_uint32_t *addr = VIP_NULL;
			vip_uint32_t lcdt = 0;
			vip_uint32_t offset = 0;
			if (pd_entry->type == GCVIP_PATCH_TYPE_STATE) {
				addr = (vip_uint32_t *)(states + pd_entry->offset_in_states);
			} else {
				gcvip_error("patch sh type=%d\n", pd_entry->type);
				gcGoOnError(VIP_ERROR_INVALID_NETWORK);
			}
			if (0 == network->prepare_count) {
				offset = *addr - pd_entry->orig_base;
				pd_entry->orig_base = offset;
			} else {
				offset = pd_entry->orig_base;
			}

			if (pd_entry->index >= 0) {
				lcdt = network->LCD.physical + network->LCDT[pd_entry->index].offset + offset;
				*addr = lcdt;
			} else {
				gcvip_error("source type=%d\n", pd_entry->source_type);
				gcGoOnError(VIP_ERROR_INVALID_NETWORK);
			}

#if vpmdENABLE_LAYER_DUMP
			if (pd_entry->source_type == GCVIP_SOURCE_MISC_DYNA_OUTPUT) {
				segment->out_sizes[segment->out_count] = network->LCDT[pd_entry->index].size;
				segment->out_buffers[segment->out_count] = network->LCD.logical +
						network->LCDT[pd_entry->index].offset;
				segment->out_count++;
			}
#endif

#if (vpmdENABLE_CAPTURE > 1)
			if (pd_entry->source_type == GCVIP_SOURCE_MISC_DYNA_GENERIC) {
				GET_CONTEXT();
				gcvip_debug("dump sh weight/bias\n");
				offset = network->LCDT[pd_entry->index].offset;
				GCVIP_DUMP_STRING(context->capture_file, "#[info: SH KS data]\n");
				gcvip_dump_duffer(context->capture_file,
								  network->LCD.logical + offset,
								  network->LCD.physical + offset,
								  GCVIP_ALIGN(network->LCDT[pd_entry->index].size, 64),
								  GCVIP_DUMP_MEMORY);
			}
#endif
		}
		break;

		default:
			gcvip_error("not implement this source_type=%d\n", pd_entry->source_type);
			break;
		}
	}

#if vpmdENABLE_CAPTURE
	{
		vip_uint32_t offset = 0;
		vip_uint32_t size = GCVIP_ALIGN(network->LCDT[shop->lcdt_index].size, gcdVIP_SH_ALIGN_SIZE);
		vip_uint32_t layer_id = operation->layer_id;
		if ((network->fixed.header.version < 0x00010005) || network->realloc_sh_buff) {
			offset = commands_logical - (vip_uint8_t *)segment->sh_cmd_buffer.logical;
		} else {
			offset = network->LCDT[shop->lcdt_index].offset;
		}
		gcvip_capture_add_list(segment, offset, size, layer_id,
							   gcvip_get_layer_uid(network, layer_id),
							   SH_COMMAND);
	}
#endif

onError:
	return status;
}

static vip_status_e patch_init_command(
	vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t commands_size = 0;
	vip_uint32_t i = 0;
	vip_uint32_t j = 0;
	gcvip_bin_entry_t *icdt_entry = VIP_NULL;
	vip_uint8_t *states_buffer = VIP_NULL;
	gcvip_bin_patch_data_entry_t *pd_entry = VIP_NULL;
	gcvip_bin_hw_init_operation_info_entry_t *op = VIP_NULL;
	vip_uint8_t *instr = VIP_NULL;
	GET_CONTEXT();

	gcvip_info("patch init command init op num=%d\n", network->n_hw_init_ops);
	for (i = 0; i < network->n_hw_init_ops; i++) {
		op = &network->init_ops[i];
		icdt_entry = &network->ICDT[op->state_id];
		commands_size += icdt_entry->size;
	}

	context->init_commands.size = commands_size;
	gcOnError(gcvip_user_allocate_videomemory(&context->init_commands.logical,
			  &context->init_commands.handle,
			  &context->init_commands.physical,
			  context->init_commands.size + APPEND_COMMAND_SIZE,
			  gcdVIP_MEMORY_ALIGN_SIZE));
	gcvip_user_zero_memory(context->init_commands.logical,
						   context->init_commands.size + APPEND_COMMAND_SIZE);

	states_buffer = context->init_commands.logical;

	for (i = 0; i < network->n_hw_init_ops; i++) {
		op = &network->init_ops[i];
		icdt_entry = &network->ICDT[op->state_id];
		gcvip_user_memcopy(states_buffer, (vip_uint8_t *)context->ICD.logical + icdt_entry->offset,
						   icdt_entry->size);

		for (j = 0; j < op->patch_count; j++) {
			pd_entry = &network->pd_entries[op->patch_index + j];
			if (pd_entry->type == GCVIP_PATCH_TYPE_STATE) {
				vip_uint32_t *memory = (vip_uint32_t *)(states_buffer + pd_entry->offset_in_states);
				switch (pd_entry->source_type) {
				case GCVIP_SOURCE_COMMAND: {
					gcvip_bin_entry_t *icdt = &network->ICDT[pd_entry->index];
					vip_uint32_t physical = context->ICD.physical + icdt->offset;
					if (pd_entry->transformed == GCVIP_PATCH_TRANSFORMATION_RIGHT_SHIFT_6) {
						vip_uint32_t *trigger_word = VIP_NULL;
						trigger_word = (vip_uint32_t *)memory;
						*trigger_word = ((*trigger_word) & 0x3f) | (physical & ~0x3f);
					} else {
						*memory = physical;
					}
					instr = context->ICD.logical + icdt->offset;
				}
				break;

				case GCVIP_SOURCE_MISC_DYNA_INPUT:
				case GCVIP_SOURCE_MISC_DYNA_OUTPUT: {
					gcvip_bin_entry_t *icdt = &network->ICDT[pd_entry->index];
					vip_uint32_t physical = context->ICD.physical + icdt->offset;
					*memory = physical;
				}
				break;

				default:
					gcvip_error("not support this source_type=%d\n", pd_entry->source_type);
					break;
				}
			} else if (pd_entry->type == GCVIP_PATCH_TYPE_COMMAND) {
				if (instr != VIP_NULL) {
					vip_uint32_t *memory = (vip_uint32_t *)(instr + pd_entry->offset_in_states);
					switch (pd_entry->source_type) {
					case GCVIP_SOURCE_MISC_DYNA_INPUT:
					case GCVIP_SOURCE_MISC_DYNA_OUTPUT: {
						gcvip_bin_entry_t *icdt = &network->ICDT[pd_entry->index];
						vip_uint32_t physical = context->ICD.physical + icdt->offset;
						*memory = physical;
					}
					break;

					case GCVIP_SOURCE_MISC_DYNA_GENERIC: {
						gcvip_bin_entry_t *icdt = &network->ICDT[pd_entry->index];
						vip_uint32_t physical = context->ICD.physical + icdt->offset;
						if (pd_entry->transformed == GCVIP_PATCH_TRANSFORMATION_RIGHT_SHIFT_6) {
							vip_uint32_t *trigger_word = VIP_NULL;
							trigger_word = (vip_uint32_t *)memory;
							physical >>= 6;
							*trigger_word = ((*trigger_word) & 0xfc000000) | physical;
						} else {
							*memory = physical;
						}
					}
					break;

					default:
						gcvip_error("not support this source_type=%d\n", pd_entry->source_type);
						break;
					}
				} else {
					gcvip_error("failed to patch command, op index=%d\n", i);
					gcOnError(VIP_ERROR_FAILURE);
				}
			}
		}

		states_buffer += icdt_entry->size;
		instr = VIP_NULL;
	}

#if vpmdENABLE_FLUSH_CPU_CACHE
	gcOnError(gcvip_user_flush_cache(context->ICD.handle,
									 context->ICD.physical,
									 context->ICD.logical,
									 context->ICD.size,
									 GCKVIP_CACHE_FLUSH));
	gcOnError(gcvip_user_flush_cache(context->init_commands.handle,
									 context->init_commands.physical,
									 context->init_commands.logical,
									 context->init_commands.size,
									 GCKVIP_CACHE_FLUSH));
#endif

#if vpmdENABLE_CAPTURE
	{
		GET_CONTEXT();
		gcvip_capture_init_command(context, network);
	}
#endif

onError:
	return status;
}

static vip_status_e patch_init_states(
	gcvip_bin_operation_t *operation,
	vip_uint8_t *states,
	vip_network_t *network,
	vip_uint32_t *size
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_bin_patch_data_entry_t *patch = VIP_NULL;
	vip_uint32_t i = 0;
	vip_int32_t sram_to_patch = 0;      /* Indicate whether there SRAM (End) Patch needed. */
	GET_CONTEXT();

	/* Copy States from LCD to State Buffer. */
	gcvip_user_memcopy(states, network->LCD.logical + network->LCDT[operation->state_id].offset,
					   network->LCDT[operation->state_id].size);

	if (size != VIP_NULL) {
		*size = network->LCDT[operation->state_id].size;
	}

	/* Apply sram patch item. */
	for (i = 0; i < operation->patch_count; i++) {
		patch = (gcvip_bin_patch_data_entry_t *)gcvip_get_patch_ptr_by_index(network,
				network->pd_entries,
				operation->patch_index + i
																			);
		if (patch->type == GCVIP_PATCH_TYPE_COMMAND) {
			switch (patch->source_type) {
			case GCVIP_SOURCE_AXI_SRAM: {
				vip_uint32_t *to_patch;
				/* ASSERT(sram_size != 0) */
				if (sram_to_patch == 0) {
					sram_to_patch = 1;
					/* SramStart to be patched. */
					to_patch = (vip_uint32_t *)(states + patch->offset_in_states);
					*to_patch = context->axi_sram_base;
				} else {
					sram_to_patch = 0;
					/* SramEnd to be patched. */
					to_patch = (vip_uint32_t *)(states + patch->offset_in_states);
					*to_patch = context->axi_sram_base + context->axi_sram_size;
					sram_to_patch = -1;
				}
			}
			break;

			case GCVIP_SOURCE_VIP_SRAM: {
				vip_uint32_t *patch_addr = VIP_NULL;
				vip_uint32_t new_addr = ~0;
				patch_addr = (vip_uint32_t *)(states + patch->offset_in_states);
				new_addr = context->vip_sram_base + (*patch_addr - patch->orig_base);
				*patch_addr = new_addr;
			}
			break;

			case GCVIP_SOURCE_COMMAND:
			case GCVIP_SOURCE_MEMORY_POOL:
			case GCVIP_SOURCE_INPUT:
			case GCVIP_SOURCE_OUTPUT:
			case GCVIP_SOURCE_MISC_DYNA_GENERIC:
			case GCVIP_SOURCE_MISC_DYNA_INPUT:
			case GCVIP_SOURCE_MISC_DYNA_OUTPUT:
				break;

			}
		} else {
			gcvip_error("INIT patch type=%d\n", patch->type);
		}
	}

	return status;
}

static vip_status_e patch_end(
	gcvip_bin_operation_t *operation,
	vip_uint8_t *states,
	vip_network_t *network,
	vip_uint32_t *size
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t state_size = network->LCDT[operation->state_id].size;
	vip_uint32_t offset = network->LCDT[operation->state_id].offset;

	gcvip_user_memcopy(states, network->LCD.logical + offset, state_size);

	if (size != VIP_NULL) {
		*size = state_size;
	}

	if (operation->patch_count > 0) {
		gcvip_error("end operation patch count=%d\n", operation->patch_count);
	}

	return status;
}

static vip_status_e patch_network_inputs(
	vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0, j = 0;

	if (network->input_dirty == 0) {
		gcvip_error("input dirty is %d\n", network->input_dirty);
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	for (i = 0; i < network->n_inputs; i++) {
		gcvip_io_patch_info_t *input = &network->network_inputs[i];

		if (0 == input->physical) {
			gcvip_error("error, didn't set input %d\n", i);
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}

		/* change ppu kernel input shape */
#if vpmdENABLE_CHANGE_PPU_PARAM
		if (network->change_ppu_param) {
			status = gcvip_change_ppu_shape(network, network->inputs, input, i);
			if (status != VIP_SUCCESS) {
				gcvip_error("failed to change input[%d] shape\n", i);
			}
		}
#endif

		// rtk, get tensor0 in address from this position?????
		for (j = 0; j < input->slice_num; j++) {
			if (input->logical_in_cmd[j] != VIP_NULL) {
				vip_uint32_t *address = (vip_uint32_t *)(gcvip_uintptr_t)input->logical_in_cmd[j];
				*address = input->physical + input->offsets[j];
			} else if (VIP_NULL == input->sw_op_buffer) {
				gcvip_error("input logical in cmd is NULL, input %d, slice=%d\n", i, j);
				gcGoOnError(VIP_ERROR_IO);
			} else {
				continue;
			}

#if vpmdENABLE_FLUSH_CPU_CACHE
			/* flush a cache line, 64 bytes? */
			{
				void *handle = search_video_memory_handle(network, input->physical_in_cmd[j]);
				if (handle != VIP_NULL) {
					gcOnError(gcvip_user_flush_cache(handle, input->physical_in_cmd[j],
													 (void *)(gcvip_uintptr_t)input->logical_in_cmd[j],
													 64, GCKVIP_CACHE_FLUSH));
				}
			}
#endif
		}

		if (input->sw_op_buffer != VIP_NULL) {
			*input->sw_op_buffer = input->logical;
		}

#if (vpmdENABLE_CAPTURE > 1)
		if (network->capture_done == 0) {
			vip_uint32_t size = 0;
			vip_char_t buffer[256];
			gcvip_bin_inout_entry_t *ptr_io = VIP_NULL;
			GET_CONTEXT();
			gcvip_info("dump input\n");
			GCVIP_GET_STRING(buffer, 255, "#[input %d dump]\n", i);
			GCVIP_DUMP_STRING(context->capture_file, buffer);
			ptr_io = (gcvip_bin_inout_entry_t *)gcvip_get_io_ptr_by_index(network,
					 network->inputs,
					 i);
			size = gcvip_get_io_buffer_size(ptr_io);
			gcvip_dump_duffer(context->capture_file,
							  input->logical,
							  input->physical,
							  size,
							  GCVIP_DUMP_MEMORY);
		}
#endif
	}

	network->input_dirty = 0;

#if vpmDUMP_NETWORK_RESOURCE
	dump_network_inputs(network);
#endif

onError:
	return status;
}

static vip_status_e patch_network_outputs(
	vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t  i = 0, j = 0;

	if (network->output_dirty == 0) {
		gcvip_error("output dirty is %d\n", network->input_dirty);
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	for (i = 0; i < network->n_outputs; i++) {
		gcvip_io_patch_info_t *output = &network->network_outputs[i];

		if (0 == output->physical) {
			gcvip_error("error, didn't set output %d\n", i);
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}

		/* change ppu kernel output shape */
#if vpmdENABLE_CHANGE_PPU_PARAM
		if (network->change_ppu_param) {
			status = gcvip_change_ppu_shape(network, network->outputs, output, i);
			if (status != VIP_SUCCESS) {
				gcvip_error("failed to change output[%d] shape\n", i);
			}
		}
#endif

		// rtk, get tensor0out and tensor1out from this position ????

		for (j = 0; j < output->slice_num; j++) {
			if (output->logical_in_cmd[j] != VIP_NULL) {
				vip_uint32_t *address = (vip_uint32_t *)(gcvip_uintptr_t)output->logical_in_cmd[j];
				*address = output->physical + output->offsets[j];
			} else if (VIP_NULL == output->sw_op_buffer) {
				gcvip_error("output logical in cmd is NULL, output %d, slice=%d\n", i, j);
				gcGoOnError(VIP_ERROR_IO);
			} else {
				continue;
			}

#if vpmdENABLE_FLUSH_CPU_CACHE
			/* flush a cache line, 64 bytes? */
			{
				void *handle = search_video_memory_handle(network, output->physical_in_cmd[j]);
				if (handle != VIP_NULL) {
					gcOnError(gcvip_user_flush_cache(handle, output->physical_in_cmd[j],
													 (void *)(gcvip_uintptr_t)output->logical_in_cmd[j],
													 64, GCKVIP_CACHE_FLUSH));
				}
			}
#endif
		}

		if (output->sw_op_buffer != VIP_NULL) {
			*output->sw_op_buffer = output->logical;
		}
	}
	network->output_dirty = 0;

onError:
	return status;
}

void *gcvip_get_io_ptr_by_index(
	vip_network_t *network,
	gcvip_bin_inout_entry_t *io_ptr,
	vip_int32_t index
)
{
	void *ptr = VIP_NULL;
	vip_uint32_t size_04 = 0, size_0B = 0;

	size_04 = sizeof(gcvip_bin_inout_entry_t) - sizeof(vip_int8_t) *
			  MAX_IO_NAME_LEGTH - sizeof(vip_uint32_t) * (MAX_NUM_DIMS - OLD_NBG_MAX_DIMS);

	size_0B = sizeof(gcvip_bin_inout_entry_t) - sizeof(vip_uint32_t) * (MAX_NUM_DIMS - OLD_NBG_MAX_DIMS);

	if (network->fixed.header.version >= 0x0001000B) {
		ptr = (void *)((vip_int8_t *)io_ptr + index * sizeof(gcvip_bin_inout_entry_t));
	} else if ((network->fixed.header.version >= 0x00010004) &&
			   (network->fixed.header.version < 0x0001000B)) {
		ptr = (void *)((vip_int8_t *)io_ptr + index * size_0B);
	} else {
		ptr = (void *)((vip_int8_t *)io_ptr + index * size_04);
	}

	return ptr;
}

void *gcvip_get_nn_op_ptr_by_index(
	vip_network_t *network,
	void *nn_op,
	vip_uint32_t index
)
{
	void *ptr = VIP_NULL;
	vip_uint32_t cmd_size = gcvip_get_nn_command_size(network);

	ptr = (vip_uint8_t *)nn_op + cmd_size * index;

	return ptr;
}

void *gcvip_get_sh_op_ptr_by_index(
	vip_network_t *network,
	void *sh_op,
	vip_uint32_t index
)
{
	void *ptr = VIP_NULL;
	vip_uint32_t size = 0;

	if (network->fixed.header.version >= 0x0001000E) {
		size = sizeof(gcvip_bin_sh_operation_t);
	} else {
		size = sizeof(gcvip_bin_sh_operation_t) - sizeof(vip_uint32_t);
	}

	ptr = (vip_uint8_t *)sh_op + size * index;

	return ptr;
}

vip_uint32_t gcvip_get_nn_command_size(
	vip_network_t *network
)
{
	vip_uint32_t cmd_size = 0;

	if (GCVIP_NN_COMMAND_SIZE_192 == network->fixed.header.feature_db.nn_command_size) {
		cmd_size = NN_CMD_SIZE_192;
	} else {
		cmd_size = NN_CMD_SIZE_128;
	}

	return cmd_size;
}

/*
@brief Submit a command buffer to hardware.
@param command command buffer video memory object.
@param event with event or not for the command buffer. see gckvip_submit_event_e.
*/
vip_status_e gcvip_commit_command(
	gcvip_videomemory_t *command,
	vip_uint32_t event
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_submit_param_t param;

	gcvip_user_zero_memory((void *)&param, sizeof(gcvip_submit_param_t));

	param.cmd_handle = command->handle;
	param.cmd_logical = (vip_uint8_t *)command->logical;
	param.cmd_physical = command->physical;
	param.cmd_size = command->size;
	param.last_cmd_handle = command->handle;
	param.last_cmd_logical = (vip_uint8_t *)command->logical;
	param.last_cmd_physical = command->physical;
	param.last_cmd_size = command->size;
	param.wait_event = event;
	gcvip_debug("submit command size=0x%x, memory handle=%p, physical=0x%08x\n",
				param.cmd_size, param.cmd_handle, param.cmd_physical);

	if (0 == param.cmd_size) {
		gcvip_error("failed to submit commands to hardware, cmds size=0x%x\n",
					param.cmd_size);
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	status = gcvip_user_submit(&param);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to submit command buffer\n");
		gcGoOnError(status);
	}
	gcvip_debug("submit command done..\n");

onError:
	return status;
}

/*
@brief Submit multiple command buffer to hardware.
@param command command buffer video memory object.
@param event with event or not for the command buffer. see gckvip_submit_event_e.
*/
vip_status_e gcvip_commit_multiple_command(
	gcvip_videomemory_t *first_command,
	gcvip_videomemory_t *last_command,
	vip_uint32_t event
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_submit_param_t param;

	gcvip_user_zero_memory((void *)&param, sizeof(gcvip_submit_param_t));

	param.cmd_handle = first_command->handle;
	param.cmd_logical = (vip_uint8_t *)first_command->logical;
	param.cmd_physical = first_command->physical;
	param.cmd_size = first_command->size;
	param.last_cmd_handle = last_command->handle;
	param.last_cmd_logical = (vip_uint8_t *)last_command->logical;
	param.last_cmd_physical = last_command->physical;
	param.last_cmd_size = last_command->size;
	param.wait_event = event;
	gcvip_debug("submit command size=0x%x, memory handle=%p, physical=0x%08x\n",
				param.cmd_size, param.cmd_handle, param.cmd_physical);

	if ((0 == param.cmd_size) || (0 == param.last_cmd_size)) {
		gcvip_error("failed to submit commands to hardware, cmds size=0x%x, last size=0x%x\n",
					param.cmd_size, param.last_cmd_size);
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	status = gcvip_user_submit(&param);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to submit command buffer\n");
		gcGoOnError(status);
	}

onError:
	return status;
}

/*
@brief Get network input/output parameters.
       This function is used for NBG format version greater than 0x0001000A.
@param io_table The input/output entry table.
@param property The property of query.
@param [OUT] value The returns value.
*/
static vip_status_e gcvip_get_io_param(
	vip_network_t *network,
	void *io_table,
	vip_enum property,
	void *value
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_bin_inout_entry_t *table = (gcvip_bin_inout_entry_t *)io_table;
	vip_uint32_t *ptr_u32 = (vip_uint32_t *)value;
	vip_int32_t *ptr_32 = (vip_int32_t *)value;
	vip_float_t *ptr_fl = (vip_float_t *)value;
	vip_char_t *ptr_char = (vip_char_t *)value;
	GCVIP_INITIALIZE_CHECK();

	switch (property) {
	case VIP_BUFFER_PROP_QUANT_FORMAT:
		*ptr_u32 = table->quan_format;
		break;

	case VIP_BUFFER_PROP_NUM_OF_DIMENSION:
		*ptr_u32 = table->dim_count;
		break;

	case VIP_BUFFER_PROP_SIZES_OF_DIMENSION: {
		vip_uint32_t i = 0;
		vip_uint32_t count = (table->dim_count > MAX_NUM_DIMS) ? MAX_NUM_DIMS : table->dim_count;
		for (i = 0; i < count; i++) {
			ptr_u32[i] = table->dim_size[i];
		}
	}
	break;

	case VIP_BUFFER_PROP_DATA_FORMAT:
		*ptr_u32 = table->data_format;
		break;

	case VIP_BUFFER_PROP_DATA_TYPE:
		*ptr_u32 = table->data_type;
		break;

	case VIP_BUFFER_PROP_FIXED_POINT_POS:
		*ptr_32 = table->fixed_pos;
		break;

	case VIP_BUFFER_PROP_TF_SCALE:
		*ptr_fl = table->tf_scale;
		break;

	case VIP_BUFFER_PROP_TF_ZERO_POINT:
		*ptr_32 = table->tf_zerop;
		break;

	case VIP_BUFFER_PROP_NAME:
		if (network->fixed.header.version >= 0x00010004) {
			gcvip_os_strcpy(ptr_char, table->name);
		} else {
			gcvip_os_strcpy(ptr_char, "dumy_input_name");
		}
		break;

	default:
		gcvip_error("viplite doesn't support this property=%d\n", property);
		status = VIP_ERROR_INVALID_ARGUMENTS;
		break;
	}

onError:
	return status;
}

/*
@brief Get network input/output parameters.
       This function is used for NBG format version small than 0x0001000B.
@param io_table The input/output entry table.
@param property The property of query.
@param [OUT] value The returns value.
*/
static vip_status_e gcvip_get_io_param_old(
	vip_network_t *network,
	void *io_table,
	vip_enum property,
	void *value
)
{
	typedef struct _gcvip_bin_inout_entry_old {
		vip_uint32_t    dim_count;
		vip_uint32_t    dim_size[OLD_NBG_MAX_DIMS];
		vip_uint32_t    data_format;
		vip_uint32_t    data_type;
		vip_uint32_t    quan_format;
		vip_int32_t     fixed_pos;
		vip_float_t     tf_scale;
		vip_int32_t     tf_zerop;
		vip_char_t      name[MAX_IO_NAME_LEGTH];
	} gcvip_bin_inout_entry_old_t;
	vip_status_e status = VIP_SUCCESS;
	gcvip_bin_inout_entry_old_t *table = (gcvip_bin_inout_entry_old_t *)io_table;
	vip_uint32_t *ptr_u32 = (vip_uint32_t *)value;
	vip_int32_t *ptr_32 = (vip_int32_t *)value;
	vip_float_t *ptr_fl = (vip_float_t *)value;
	vip_char_t *ptr_char = (vip_char_t *)value;
	GCVIP_INITIALIZE_CHECK();

	switch (property) {
	case VIP_BUFFER_PROP_QUANT_FORMAT:
		*ptr_u32 = table->quan_format;
		break;

	case VIP_BUFFER_PROP_NUM_OF_DIMENSION:
		*ptr_u32 = table->dim_count;
		break;

	case VIP_BUFFER_PROP_SIZES_OF_DIMENSION: {
		vip_uint32_t i = 0;
		vip_uint32_t count = (table->dim_count > OLD_NBG_MAX_DIMS) ? OLD_NBG_MAX_DIMS : table->dim_count;
		for (i = 0; i < count; i++) {
			ptr_u32[i] = table->dim_size[i];
		}
	}
	break;

	case VIP_BUFFER_PROP_DATA_FORMAT:
		*ptr_u32 = table->data_format;
		break;

	case VIP_BUFFER_PROP_DATA_TYPE:
		*ptr_u32 = table->data_type;
		break;

	case VIP_BUFFER_PROP_FIXED_POINT_POS:
		*ptr_32 = table->fixed_pos;
		break;

	case VIP_BUFFER_PROP_TF_SCALE:
		*ptr_fl = table->tf_scale;
		break;

	case VIP_BUFFER_PROP_TF_ZERO_POINT:
		*ptr_32 = table->tf_zerop;
		break;

	case VIP_BUFFER_PROP_NAME:
		if (network->fixed.header.version >= 0x00010004) {
			gcvip_os_strcpy(ptr_char, table->name);
		} else {
			gcvip_os_strcpy(ptr_char, "dumy_input_name");
		}
		break;

	default:
		gcvip_error("viplite doesn't support this property=%d\n", property);
		status = VIP_ERROR_INVALID_ARGUMENTS;
		break;
	}

onError:
	return status;
}

static vip_status_e gcvip_user_wait_network(
	IN vip_network network,
	IN gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;

	if (VIP_NULL == segment) {
		gcvip_error("fail to wait network, parameter is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	/* Wait for commands to be done. */
	status = gcvip_user_wait(segment->states_buffer.handle);
	if (status != VIP_SUCCESS) {
#if vpmdENABLE_HANG_DUMP
		gcvip_dump_states_command(network, segment, HANG_DUMP);
#endif
		gcvip_error("user wait time out\n");
	}

	return status;
}

static vip_status_e gcvip_init_commands(
	vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_lite_segment_t segment;
	vip_uint32_t wait_event = GCKVIP_SUBMIT_WITH_EVENT;
	GET_CONTEXT();

	if (GCVIP_INIT_CMD_STATUS_DONE == context->init_status) {
		return VIP_SUCCESS;
	}

	if (0 == network->n_hw_init_ops) {
		return VIP_SUCCESS;
	}

	if (VIP_NULL == context->init_commands.logical) {
		gcvip_error("failed to init commands buffer is NULL\n");
		return VIP_ERROR_FAILURE;
	}

	gcvip_debug("submit hardware initialize commands size=0x%x, data size=0x%x\n",
				context->init_commands.size, context->ICD.size);

#if vpmdENABLE_SECURE
	wait_event = GCKVIP_SUBMIT_NO_EVENT;
#else
	wait_event = GCKVIP_SUBMIT_WITH_EVENT;
#endif
	status = gcvip_commit_command(&context->init_commands, wait_event);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to submit initialize command\n");
		gcGoOnError(status);
	}

	segment.states_buffer.handle = context->init_commands.handle;
	segment.states_buffer.logical = context->init_commands.logical;
	segment.states_buffer.physical = context->init_commands.physical;
	segment.states_buffer.size = context->init_commands.size;

	status = gcvip_user_wait_network(network, &segment);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to wait network finish initialize states\n");
		gcGoOnError(status);
	}

onError:
	return status;
}

static vip_status_e gcvip_init_states(
	vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_lite_segment_t segment;
	vip_uint32_t wait_event = GCKVIP_SUBMIT_WITH_EVENT;
	GET_CONTEXT();

	if (GCVIP_INIT_CMD_STATUS_DONE == context->init_status) {
		return VIP_SUCCESS;
	}

	if (VIP_NULL == network->init_states.logical) {
		gcvip_error("failed to init states\n");
		return VIP_ERROR_FAILURE;
	}

#if (vpmdENABLE_CNN_PROFILING && !vpmdENABLE_LAYER_DUMP)
	{
		vip_uint32_t i = 0, j = 0;
		vip_uint32_t init_states_size = 0;
		vip_uint8_t states_buffer[100];
		for (i = 0; i < network->n_operations; i++) {
			gcvip_bin_operation_t *operation = &network->operations[i];
			if (operation->type == GCVIP_OPERATION_TYPE_INIT) {
				gcOnError(patch_init_states(operation, network->init_states.logical + network->init_states_size,
											network, &init_states_size));
				network->init_states_size += init_states_size;

				init_states_size = 0;
				for (j = 0; j < network->n_operations; j++) {
					if (operation->type == GCVIP_OPERATION_TYPE_END) {
						gcOnError(patch_end(operation, states_buffer, network, &init_states_size));
						gcvip_user_memcopy(network->init_states.logical + network->init_states_size,
										   states_buffer, init_states_size);
						network->init_states_size += init_states_size;

						break;
					}
				}
				break;
			}
		}
	}
#endif

	if (network->init_states_size == 0) {
		return VIP_SUCCESS;
	}

	gcvip_debug("initialize states command, size=0x%x\n", network->init_states_size);

#if vpmdENABLE_CAPTURE
	if (network->init_states_size > 0) {
		GCVIP_DUMP_STRING(context->capture_file, "#[initial states]\n");
		gcvip_dump_duffer(context->capture_file,
						  network->init_states.logical,
						  network->init_states.physical,
						  network->init_states_size,
						  GCVIP_DUMP_COMMAND);
	}
	GCVIP_DUMP_STRING(context->capture_file, "@[commit]\n");
	GCVIP_DUMP_STRING(context->capture_file, "@[stall]\n");
#endif

#if vpmdENABLE_FLUSH_CPU_CACHE
	gcOnError(gcvip_user_flush_cache(network->init_states.handle,
									 network->init_states.physical,
									 network->init_states.logical,
									 network->init_states_size,
									 GCKVIP_CACHE_FLUSH));
#endif

#if vpmdENABLE_SECURE
	wait_event = GCKVIP_SUBMIT_NO_EVENT;
#else
	wait_event = GCKVIP_SUBMIT_WITH_EVENT;
#endif

	network->init_states.size = network->init_states_size;

	status = gcvip_commit_command(&network->init_states, wait_event);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to submit initialize states\n");
		gcGoOnError(status);
	}

	segment.states_buffer.handle = network->init_states.handle;
	segment.states_buffer.logical = network->init_states.logical;
	segment.states_buffer.physical = network->init_states.physical;
	segment.states_buffer.size = network->init_states_size;

	status = gcvip_user_wait_network(network, &segment);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to wait network finish initialize states\n");
		gcGoOnError(status);
	}

	return status;
onError:
	gcvip_error("failed to submit init states..\n");
	return status;
}

#if vpmdPOWER_OFF_TIMEOUT || vpmdENABLE_USER_CONTROL_POWER || vpmdENABLE_SUSPEND_RESUME
/* check hardware has been power management power off or not */
static vip_status_e gcvip_check_power_status(
	vip_network network
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_query_power_info_t info;
#if (vpmdENABLE_DEBUG_LOG > 3)
	vip_char_t string[GCKVIP_POWER_MAX][24] = {
		"NONE",
		"OFF",
		"IDLE",
		"CLOCK_ON",
		"ON",
		"SUSPEND",
		"RESUME",
		"SUSPEND_OFF"
	};
#endif
	GET_CONTEXT();

#if vpmdENABLE_MULTIPLE_TASK
	status = gcvip_os_lock_mutex(context->init_cmds_mutex);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to lock init cmds mutex\n");
		return VIP_ERROR_FAILURE;
	}
#endif

	gcOnError(gcvip_user_query_power_info(&info));
	gcvip_debug("query power status=%s, init_status=%s\n",
				string[info.power_status],
				(GCVIP_INIT_CMD_STATUS_POWER_OFF == context->init_status) ? "OFF" : "DONE");

	if ((GCKVIP_POWER_OFF == info.power_status) ||
		(GCKVIP_POWER_RESUME == info.power_status) ||
		(GCVIP_INIT_CMD_STATUS_POWER_OFF == context->init_status)) {
		/* hardware power off, re-initialize */
		context->init_status = GCVIP_INIT_CMD_STATUS_POWER_OFF;
		status = gcvip_init_states(network);
		if (status != VIP_SUCCESS) {
			gcvip_error("hardware has power off, fail to submit init states..\n");
			gcGoOnError(status);
		}

		status = gcvip_init_commands(network);
		if (status != VIP_SUCCESS) {
			gcvip_error("fail to initialize command\n");
			gcGoOnError(status);
		}

		context->init_status = GCVIP_INIT_CMD_STATUS_DONE;
	}

onError:
#if vpmdENABLE_MULTIPLE_TASK
	status = gcvip_os_unlock_mutex(context->init_cmds_mutex);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to lock init cmds mutex\n");
	}
#endif
	return status;
}
#endif

/*
 * @brief
 * Go through all operations, copy and patch them into the command buffer,
   and generate control states.
 */
static vip_status_e generate_hardware_command(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_uint8_t *sh_commands = VIP_NULL;
	vip_uint8_t *states_buffer = VIP_NULL;
	gcvip_bin_operation_t *operation = VIP_NULL;
	gcvip_bin_tp_operation_t *op_tp = VIP_NULL;
	void *op_sh = VIP_NULL;
	void *op_nn = VIP_NULL;
	vip_uint32_t cmd_size = 0;
	vip_uint32_t states_size = 0;
	vip_uint32_t total_states_size = 0;
	vip_uint32_t init_states_size = 0;
	vip_uint32_t i = 0;
	vip_uint8_t states_index = 0;
	vip_status_e status = VIP_SUCCESS;

	if ((segment != VIP_NULL) && (network != VIP_NULL)) {
		sh_commands = (vip_uint8_t *)segment->sh_cmd_buffer.logical;
		states_buffer = (vip_uint8_t *)segment->states_buffer.logical;
	} else {
		gcvip_error("segment or network is NULL");
		gcGoOnError(VIP_ERROR_INVALID_NETWORK);
	}

	if (VIP_NULL == states_buffer) {
		gcvip_error("states buffer is NULL");
		gcGoOnError(VIP_ERROR_INVALID_NETWORK);
	}

	/* Go through all operations to generate commands (TP & NN) and states (TP, NN, SH). */
	for (i = 0; i < network->n_operations; i++) {
		operation = &network->operations[i];

#if vpmdENABLE_LAYER_DUMP
		if (((operation->type != GCVIP_OPERATION_TYPE_INIT) ||
			 (segment->segm_start_id != 0)) &&
			((operation->type != GCVIP_OPERATION_TYPE_END) ||
			 (segment->segm_end_id != network->n_orig_layers)) &&
			((operation->layer_id >= segment->segm_end_id) ||
			 (operation->layer_id < segment->segm_start_id))) {
			continue;
		}
#elif vpmdENABLE_CNN_PROFILING
		if ((operation->type == GCVIP_OPERATION_TYPE_INIT) ||
			(operation->type == GCVIP_OPERATION_TYPE_END) ||
			(i != segment->segm_end_id)) {
			continue;
		}
#else
		if ((i >= segment->segm_end_id) || (i < segment->segm_start_id)) {
			continue;
		}
#endif

		switch (operation->type) {
		case GCVIP_OPERATION_TYPE_NN: {
			op_nn = gcvip_get_nn_op_ptr_by_index(network, network->nn_ops, operation->index);
			gcOnError(patch_nn((vip_uint8_t_ptr)op_nn, states_buffer, operation, network,
							   &states_size, segment));
			states_buffer += states_size;
		}
		break;

		case GCVIP_OPERATION_TYPE_TP: {
			op_tp = &network->tp_ops[operation->index];
			gcOnError(patch_tp((vip_uint8_t_ptr)op_tp, states_buffer, operation, network,
							   &states_size, segment));
			states_buffer += states_size;
		}
		break;

		case GCVIP_OPERATION_TYPE_SH: {
			op_sh = gcvip_get_sh_op_ptr_by_index(network, network->sh_ops, operation->index);
			gcOnError(patch_sh(op_sh, sh_commands, states_buffer, operation, network,
							   &cmd_size, &states_size, segment));
			if ((network->fixed.header.version < 0x00010005) || network->realloc_sh_buff) {
				sh_commands += cmd_size;
			}
			states_buffer += states_size;
		}
		break;

		case GCVIP_OPERATION_TYPE_SC: {
			gcvip_warning("not implement sc operation\n");
		}
		break;

		case GCVIP_OPERATION_TYPE_INIT: {
			if (network->init_states_size < network->init_states.size) {
				gcOnError(patch_init_states(operation, network->init_states.logical + network->init_states_size,
											network, &init_states_size));
				network->init_states_size += init_states_size;
			} else {
				gcvip_error("fail to patch initialize operation");
				gcOnError(VIP_ERROR_NOT_SUPPORTED);
			}
		}
		break;

		case GCVIP_OPERATION_TYPE_END: {
			gcOnError(patch_end(operation, states_buffer, network, &states_size));

			/* copy end states to init states buffer */
			if (network->init_states_size < network->init_states.size) {
				gcvip_user_memcopy(network->init_states.logical + network->init_states_size,
								   states_buffer, states_size);
				network->init_states_size += states_size;
			} else {
				gcvip_error("fail to copy end operation commands to init states buffer\n");
				gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
			}

			states_buffer += states_size;
		}
		break;

		case GCVIP_OPERATION_TYPE_SW:
			break;

		default:
			gcvip_error("unsupport operation type=%d\n", operation->type);
			break;
		}

		/* reserved LINK bits in states buffer for patch it in submit function */
		if ((segment->operation_pos != VIP_NULL) &&
			(i == segment->operation_pos[states_index]) && (i != 0)) {
			vip_uint32_t *memory = (vip_uint32_t *)segment->patch_pos;
			vip_uint32_t *split_cmd_size = (vip_uint32_t *)segment->split_size;
			memory[states_index] = states_buffer - (vip_uint8_t *)segment->states_buffer.logical;
			states_buffer += LINK_SIZE;
			total_states_size += LINK_SIZE;
			if (states_index > 0) {
				if ((memory[states_index] - memory[states_index - 1]) != split_cmd_size[states_index]) {
					gcvip_error("fail to split command buffer. index=%d.\n", states_index);
					gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
				}
			} else {
				if ((memory[states_index] + LINK_SIZE) != split_cmd_size[states_index]) {
					gcvip_error("fail to split command buffer. index=%d.\n", states_index);
					gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
				}
			}
			states_index++;
		}

		total_states_size += states_size;
	}

	if (total_states_size != segment->states_buffer.size) {
		gcvip_warning("failed to generate hardware commmand, total command size=%dbyte"
					  "not equal buffer size %dbyte\n",
					  total_states_size, segment->states_buffer.size);
		if (0 == total_states_size) {
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}
	}

onError:
	return status;
}

static vip_uint32_t get_sh_command_size(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_uint32_t cmd_size = 0;
	gcvip_bin_operation_t *op = VIP_NULL;
	gcvip_bin_sh_operation_t *shop = VIP_NULL;
	vip_uint32_t i = 0;

	for (i = 0; i < network->n_operations; i++) {
		op = &network->operations[i];
#if vpmdENABLE_LAYER_DUMP
		if ((op->layer_id >= segment->segm_end_id) ||
			(op->layer_id < segment->segm_start_id)) {
			continue;
		}
#elif vpmdENABLE_CNN_PROFILING
		if (i != segment->segm_end_id) {
			continue;
		}
#else
		if ((i >= segment->segm_end_id) || (i < segment->segm_start_id)) {
			continue;
		}
#endif

		if (op->type == GCVIP_OPERATION_TYPE_SH) {
			shop = (gcvip_bin_sh_operation_t *)gcvip_get_sh_op_ptr_by_index(network, network->sh_ops,
					op->index);
			cmd_size += GCVIP_ALIGN(network->LCDT[shop->lcdt_index].size, gcdVIP_SH_ALIGN_SIZE);
		}
	}

	return cmd_size;
}

static vip_uint32_t get_init_states_size(
	vip_network_t *network
)
{
	vip_uint32_t init_size = 0;
	vip_uint32_t end_size = 0;
	vip_uint32_t total_size = 0;
	vip_uint32_t i = 0;
	gcvip_bin_operation_t *op = VIP_NULL;

	for (i = 0; i < network->n_operations; i++) {
		op = &network->operations[i];

		if (op->type == GCVIP_OPERATION_TYPE_INIT) {
			init_size += network->LCDT[op->state_id].size;
		}

		if (op->type == GCVIP_OPERATION_TYPE_END) {
			end_size += network->LCDT[op->state_id].size;
		}
	}

	total_size = init_size + end_size;

	return total_size;
}

static vip_uint32_t get_sh_cmds_status(
	vip_network_t *network
)
{
	vip_uint32_t i = 0;
	vip_uint32_t physical = 0;
	vip_status_e status = VIP_SUCCESS;
	gcvip_bin_operation_t *operation = VIP_NULL;
	gcvip_bin_sh_operation_t *op_sh = VIP_NULL;

	network->realloc_sh_buff = vip_false_e;
	for (i = 0; i < network->n_operations; i++) {
		operation = &network->operations[i];
		if (GCVIP_OPERATION_TYPE_SH == operation->type) {
			op_sh = (gcvip_bin_sh_operation_t *)gcvip_get_sh_op_ptr_by_index(network, network->sh_ops,
					operation->index);
			physical = network->LCD.physical + network->LCDT[op_sh->lcdt_index].offset;
			if ((physical % gcdVIP_SH_ALIGN_SIZE) != 0) {
				network->realloc_sh_buff = vip_true_e;
				return status;
			}
		}
	}

	return status;
}

/* Get the command states size. */
static vip_uint32_t get_states_size(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_uint32_t states_size = 0;
	gcvip_bin_operation_t *op = VIP_NULL;
	vip_uint32_t i = 0;

	/* calculate states size. */
	for (i = 0; i < network->n_operations; i++) {
		op = &network->operations[i];

#if vpmdENABLE_LAYER_DUMP
		if ((op->type == GCVIP_OPERATION_TYPE_END) &&
			(segment->segm_end_id == network->n_orig_layers)) {
			/* end states only in last segment*/
			states_size += network->LCDT[op->state_id].size;
		}

		if ((op->layer_id < segment->segm_end_id) &&
			(op->layer_id >= segment->segm_start_id) &&
			(op->type != GCVIP_OPERATION_TYPE_INIT) &&
			(op->type != GCVIP_OPERATION_TYPE_END)) {

			states_size += network->LCDT[op->state_id].size;
		}
#elif vpmdENABLE_CNN_PROFILING
		if ((i == segment->segm_end_id) &&
			(op->type != GCVIP_OPERATION_TYPE_INIT) &&
			(op->type != GCVIP_OPERATION_TYPE_END)) {
			states_size += network->LCDT[op->state_id].size;
		}
#else
		/* init command doesn't in command buffer */
		if ((op->type != GCVIP_OPERATION_TYPE_INIT) &&
			(i < segment->segm_end_id) &&
			(i >= segment->segm_start_id)) {
			states_size += network->LCDT[op->state_id].size;
		}
#endif
	}

	return states_size;
}

#if vpmdENABLE_FLUSH_CPU_CACHE
static vip_status_e flush_cmd_cache(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;

	if (network->nnCmds.size > 0) {
		gcOnError(gcvip_user_flush_cache(network->nnCmds.handle,
										 network->nnCmds.physical,
										 network->nnCmds.logical,
										 network->nnCmds.size,
										 GCKVIP_CACHE_FLUSH));
	}
	if (network->tpCmds.size > 0) {
		gcOnError(gcvip_user_flush_cache(network->tpCmds.handle,
										 network->tpCmds.physical,
										 network->tpCmds.logical,
										 network->tpCmds.size,
										 GCKVIP_CACHE_FLUSH));
	}
	if (segment->states_buffer.size > 0) {
		gcOnError(gcvip_user_flush_cache(segment->states_buffer.handle,
										 segment->states_buffer.physical,
										 segment->states_buffer.logical,
										 segment->states_buffer.size,
										 GCKVIP_CACHE_FLUSH));
	}
	if ((segment->sh_cmd_buffer.size > 0) &&
		((network->fixed.header.version < 0x00010005) || network->realloc_sh_buff)) {
		gcOnError(gcvip_user_flush_cache(segment->sh_cmd_buffer.handle,
										 segment->sh_cmd_buffer.physical,
										 segment->sh_cmd_buffer.logical,
										 segment->sh_cmd_buffer.size,
										 GCKVIP_CACHE_FLUSH));
	}

onError:
	return status;
}
#endif


#if vpmdENABLE_FLUSH_CPU_CACHE && (vpmdENABLE_DEBUG_LOG > 3)
static vip_status_e flush_output_cache(
	vip_network_t *network
)
{
	vip_uint32_t i = 0;
	vip_status_e status = VIP_SUCCESS;

	for (i = 0; i < (vip_int32_t)network->fixed.header.output_count; i++) {
		gcvip_io_patch_info_t *entry = entry = &network->network_outputs[i];
		gcOnError(gcvip_user_flush_cache(entry->buffer->memory.handle,
										 entry->buffer->memory.physical,
										 entry->buffer->memory.logical,
										 entry->buffer->memory.size,
										 GCKVIP_CACHE_INVALID));

		gcvip_debug("flush output[%d] cache, logical=%p, physical=0x%08x, size=0x%x, mem_handle=%p\n",
					i, entry->logical, entry->physical, entry->buffer->memory.size,
					entry->buffer->memory.handle);
	}

onError:
	return status;
}
#endif

#if (vpmdENABLE_CAPTURE > 1)
static vip_status_e capture_network_output(
	vip_network_t *network
)
{
	vip_uint32_t i = 0;
	vip_uint32_t size = 0;
	vip_char_t buffer[256];
	GET_CONTEXT();
	gcvip_bin_inout_entry_t *ptr_io = VIP_NULL;

	if (0 == network->capture_done) {
		for (i = 0; i < network->fixed.header.output_count; i++) {
			gcvip_info("dump output\n");
			GCVIP_GET_STRING(buffer, 255, "#[output %d dump]\n", i);
			GCVIP_DUMP_STRING(context->capture_file, buffer);
			ptr_io = (gcvip_bin_inout_entry_t *)gcvip_get_io_ptr_by_index(network, network->outputs, i);
			size = gcvip_get_io_buffer_size(ptr_io);
			gcvip_dump_duffer(context->capture_file, network->network_outputs[i].logical,
							  network->network_outputs[i].physical,
							  size, GCVIP_DUMP_VERIFY);
		}
	}

	network->capture_done = 1;

	return VIP_SUCCESS;
}
#endif

static vip_uint32_t get_insertlink_states_size(
	vip_network_t *network,
	gcvip_lite_segment_t *segment,
	vip_uint32_t size
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t states_size = 0;
	gcvip_bin_operation_t *op = VIP_NULL;
	vip_uint32_t i = 0;
	vip_uint32_t split_count = size / gcdVIP_MAX_CMD_SIZE;
	vip_uint32_t total_size = 0;
	vip_uint32_t *split_cmd_size = VIP_NULL;
	vip_uint32_t mem_size = split_count * sizeof(vip_uint32_t);

	if (0 == split_count) {
		gcvip_error("insert link max is 0\n");
		return size;
	}

	gcOnError(gcvip_user_allocate_memory(mem_size, (void **)&segment->operation_pos));
	gcvip_user_zero_memory((void *)segment->operation_pos, mem_size);

	gcOnError(gcvip_user_allocate_memory(mem_size, (void **)&segment->patch_pos));
	gcvip_user_zero_memory((void *)segment->patch_pos, mem_size);

	gcOnError(gcvip_user_allocate_memory(mem_size, (void **)&segment->split_size));
	gcvip_user_zero_memory((void *)segment->split_size, mem_size);

	segment->patch_num = 0;

	if ((VIP_NULL == segment->operation_pos) || (VIP_NULL == segment->patch_pos) ||
		(VIP_NULL == segment->split_size)) {
		gcvip_error("fail to malloc operation_pos or patch pos, split size\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}

	split_cmd_size = (vip_uint32_t *)segment->split_size;

	/* Calculate NB state size. */
	for (i = 0; i < network->n_operations; i++) {
		op = &network->operations[i];

#if vpmdENABLE_LAYER_DUMP
		if ((op->type == GCVIP_OPERATION_TYPE_END) &&
			(segment->segm_end_id == network->n_orig_layers)) {
			/* end states only in last segment*/
			states_size += network->LCDT[op->state_id].size;
		}

		if ((op->layer_id < segment->segm_end_id) &&
			(op->layer_id >= segment->segm_start_id) &&
			(op->type != GCVIP_OPERATION_TYPE_INIT) &&
			(op->type != GCVIP_OPERATION_TYPE_END)) {
			states_size += network->LCDT[op->state_id].size;
		}
#elif vpmdENABLE_CNN_PROFILING
		if ((i == segment->segm_end_id) &&
			(op->type != GCVIP_OPERATION_TYPE_INIT) &&
			(op->type != GCVIP_OPERATION_TYPE_END)) {
			states_size += network->LCDT[op->state_id].size;
		}
#else
		if ((op->type != GCVIP_OPERATION_TYPE_INIT) &&
			(i < segment->segm_end_id) &&
			(i >= segment->segm_start_id)) {
			states_size += network->LCDT[op->state_id].size;
		}
#endif

		/* this is for more than command buffer size, we should split it and link them together */
		if ((states_size + LINK_SIZE) >= gcdVIP_MAX_CMD_SIZE) {
			segment->operation_pos[segment->patch_num] = i - 1;
			/* insert LINK_SIZE bytes in command buffer for LINK command */
			states_size = states_size - network->LCDT[op->state_id].size + LINK_SIZE;
			if (states_size >= gcdVIP_MAX_CMD_SIZE) {
				gcvip_error("failed to insert LINK command for big command buffer,"
							"split command size=0x%x, max support size=0x%x\n",
							states_size, gcdVIP_MAX_CMD_SIZE);
				gcGoOnError(VIP_ERROR_FAILURE);
			}
			split_cmd_size[segment->patch_num] = states_size;
			segment->patch_num++;
			i = i - 1;
			total_size += states_size;
			states_size = 0;
		}
	}

	split_cmd_size[segment->patch_num] = states_size;
	total_size += states_size;

	return total_size;

onError:
	gcvip_error("failed to insert link states size..\n");
	if (segment->operation_pos != VIP_NULL) {
		gcvip_user_free_memory((void *)segment->operation_pos);
		segment->operation_pos = VIP_NULL;
	}
	if (segment->patch_pos != VIP_NULL) {
		gcvip_user_free_memory(segment->patch_pos);
		segment->patch_pos = VIP_NULL;
	}
	if (segment->split_size != VIP_NULL) {
		gcvip_user_free_memory(segment->split_size);
		segment->split_size = VIP_NULL;
	}
	return 0;
}

#if (!vpmdENABLE_CNN_PROFILING && !vpmdENABLE_LAYER_DUMP)
static vip_uint32_t get_sw_operation_count(
	vip_network_t *network
)
{
	vip_uint32_t count = 0, i = 0;

	for (i = 0; i < network->n_operations; i++) {
		gcvip_bin_operation_t *operation = &network->operations[i];
		if (operation->type == GCVIP_OPERATION_TYPE_SW) {
			count++;
		}
	}

	return count;
}
#endif

/*
@brief Check network input or output parameters
@param network The network object create by vip_create_network().
@param index The index of this output.
@param buffer The viplite buffer object
@param flag 0 is for input buffer. 1 is output buffer.
*/
static vip_int8_t gcvip_check_io_params(
	vip_network_t *network,
	vip_uint32_t index,
	vip_buffer buffer,
	vip_int8_t flag
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_int8_t matched = vip_true_e;
	vip_int32_t quant_format = 0;
	vip_uint32_t dims[MAX_NUM_DIMS];
	vip_uint32_t num_dim;
	vip_int32_t zero_point = 0;
	vip_float_t scale = 0.0;
	vip_int32_t data_format = 0;
	vip_int32_t fixed_point_pos = 0;
	vip_uint32_t i = 0;

	if (0 == flag) {
		gcvip_query_input(network, index, VIP_BUFFER_PROP_QUANT_FORMAT, &quant_format);
		gcvip_query_input(network, index, VIP_BUFFER_PROP_SIZES_OF_DIMENSION, dims);
		gcvip_query_input(network, index, VIP_BUFFER_PROP_NUM_OF_DIMENSION, &num_dim);
		gcvip_query_input(network, index, VIP_BUFFER_PROP_TF_ZERO_POINT, &zero_point);
		gcvip_query_input(network, index, VIP_BUFFER_PROP_TF_SCALE, &scale);
		gcvip_query_input(network, index, VIP_BUFFER_PROP_DATA_FORMAT, &data_format);
		gcvip_query_input(network, index, VIP_BUFFER_PROP_FIXED_POINT_POS, &fixed_point_pos);
	} else {
		gcvip_query_output(network, index, VIP_BUFFER_PROP_QUANT_FORMAT, &quant_format);
		gcvip_query_output(network, index, VIP_BUFFER_PROP_SIZES_OF_DIMENSION, dims);
		gcvip_query_output(network, index, VIP_BUFFER_PROP_NUM_OF_DIMENSION, &num_dim);
		gcvip_query_output(network, index, VIP_BUFFER_PROP_TF_ZERO_POINT, &zero_point);
		gcvip_query_output(network, index, VIP_BUFFER_PROP_TF_SCALE, &scale);
		gcvip_query_output(network, index, VIP_BUFFER_PROP_DATA_FORMAT, &data_format);
		gcvip_query_output(network, index, VIP_BUFFER_PROP_FIXED_POINT_POS, &fixed_point_pos);
	}

	/* check shape if the network doesn't supports change ppu param */
#if vpmdENABLE_CHANGE_PPU_PARAM
	if (vip_false_e == network->change_ppu_param) {
#endif
		if (VIP_NULL == network->memory_pool) {
			for (i = 0; i < num_dim; i++) {
				if (dims[i] != buffer->param.sizes[i]) {
					gcvip_error("fail to set %s %d ", (flag == 0) ? "input" : "output", index);
					matched = vip_false_e;
					break;
				}
			}
		}
#if vpmdENABLE_CHANGE_PPU_PARAM
	}
#endif

	if (vip_false_e == matched) {
		gcvip_os_print("nbg dims ");
		for (i = 0; i < num_dim; i++) {
			gcvip_os_print("%d ", dims[i]);
		}
		gcvip_os_print(", vip buffer dims ");
		for (i = 0; i < num_dim; i++) {
			gcvip_os_print("%d ", buffer->param.sizes[i]);
		}
		gcvip_os_print("\n");
		status = VIP_ERROR_INVALID_ARGUMENTS;
		gcGoOnError(status);
	}

	if (quant_format != (vip_int32_t)buffer->param.quant_format) {
		gcvip_error("fail to set %s , index=%d, nbg quant format=%d, runtime quant format=%d\n",
					(flag == 0) ? "input" : "output", index, quant_format, buffer->param.quant_format);
		matched = vip_false_e;
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	if (data_format != (vip_int32_t)buffer->param.data_format) {
		gcvip_error("fail to set %s , index=%d, nbg data format=%d, runtime data format=%d\n",
					(flag == 0) ? "input" : "output", index, data_format, buffer->param.data_format);
		matched = vip_false_e;
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	if (VIP_BUFFER_QUANTIZE_DYNAMIC_FIXED_POINT == quant_format) {
		if (fixed_point_pos != buffer->param.quant_data.dfp.fixed_point_pos) {
			gcvip_error("fail to set %s , index=%d, nbg zfp=%d, runtime zfp=%d\n",
						(flag == 0) ? "input" : "output", index, fixed_point_pos,
						buffer->param.quant_data.dfp.fixed_point_pos);
			matched = vip_false_e;
			gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
		}
	} else if (VIP_BUFFER_QUANTIZE_TF_ASYMM == quant_format) {
		vip_float_t diff = scale / buffer->param.quant_data.affine.scale;
		if ((diff >= 1.1) || (diff <= 0.9)) {
			gcvip_error("fail to set %s , index=%d, nbg scale=%f, runtime scale=%f\n",
						(flag == 0) ? "input" : "output", index, scale,
						buffer->param.quant_data.affine.scale);
			matched = vip_false_e;
			gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
		}

		if (zero_point != buffer->param.quant_data.affine.zeroPoint) {
			gcvip_error("fail to set %s , index=%d, nbg zero point=%d, runtime zero point=%d\n",
						(flag == 0) ? "input" : "output", index, zero_point,
						buffer->param.quant_data.affine.zeroPoint);
			matched = vip_false_e;
			gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
		}
	}

	return matched;

onError:
	gcvip_error("failed to check %s[%d] parameter, status=%d\n",
				(0 == flag) ? "input" : "output", index, status);
	return matched;
}

#if vpmdENABLE_USE_AGENT_TRIGGER
static vip_status_e gcvip_get_network_address_info(
	vip_network_t *network,
	void *value
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_query_address_info_t address;
	vip_address_info_t *info = (vip_address_info_t *)value;
	gcvip_lite_segment_t *segment = &network->segments[0];
	vip_uint32_t i = 0;
	vip_uint32_t j = 0;
	GCVIP_CHECK_NETWORK();
	gcIsNULL(value);
	gcIsNULL(network);

	if ((value == VIP_NULL) || (segment == VIP_NULL)) {
		gcvip_error("value or segment is null");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	if (network->segment_num != 1) {
		gcvip_error("not support segment number is %d for this feature",
					network->segment_num);
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	gcvip_user_zero_memory((void *)info, sizeof(vip_address_info_t));

	/* allocate memory */
	gcOnError(gcvip_user_allocate_memory(sizeof(vip_input_output_info_t) * network->n_inputs,
										 (void **) &info->input_info));
	gcvip_user_zero_memory((void *)info->input_info, sizeof(vip_input_output_info_t) * network->n_inputs);
	gcOnError(gcvip_user_allocate_memory(sizeof(vip_input_output_info_t) * network->n_outputs,
										 (void **) &info->output_info));
	gcvip_user_zero_memory((void *)info->output_info, sizeof(vip_input_output_info_t) * network->n_outputs);

	/* query wait-link address */
	gcvip_user_query_address_info(&address);
	info->waitlink_logical = GCVIPUINT64_TO_PTR(address.waitlink_logical);
	info->waitlink_physical = address.waitlink_physical;
	info->waitlink_size = address.waitlink_size;

	/* get command buffer base address and size */
	info->commandbuffer_logical = (void *)segment->states_buffer.logical;
	info->commandbuffer_physical = segment->states_buffer.physical;
	info->commandbuffer_size = segment->states_buffer.size;

	/* get input address in command buffer */
	info->input_num = network->n_inputs;
	for (i = 0; i < network->n_inputs; i++) {
		gcvip_io_patch_info_t *input = &network->network_inputs[i];
		info->input_info[i].logical_in_cmd = (void *)input->logical_in_cmd;
		info->input_info[i].physical_in_cmd = (vip_uint32_t *)input->physical_in_cmd;
		info->input_info[i].offset = (vip_uint32_t *)input->offsets;
		info->input_info[i].slice_num = input->slice_num;
		info->input_info[i].physical = input->physical;
		gcvip_debug("input logical ref=%p, physical ref=%p, offset=%p, num=%d,"
					"input buffer physical=%08X\n",
					input->logical_in_cmd, input->physical_in_cmd, input->offsets,
					input->slice_num, info->input_info[i].physical);

		for (j = 0; j < input->slice_num; j++) {
			gcvip_debug("input in cmd logical=%08X, physical=%08X, offset=%08X\n",
						input->logical_in_cmd[j], input->physical_in_cmd[j],
						(vip_uint32_t)(input->offsets[j]));
		}
		if (input->physical == 0) {
			gcvip_error("input buffer is NULL, please call vip_set_input() before this\n");
		}
	}

	/* get output address in command buffer */
	info->output_num = network->n_outputs;
	for (i = 0; i < network->n_outputs; i++) {
		gcvip_io_patch_info_t *output = &network->network_outputs[i];
		info->output_info[i].logical_in_cmd = (void *)output->logical_in_cmd;
		info->output_info[i].physical_in_cmd = (vip_uint32_t *)output->physical_in_cmd;
		info->output_info[i].offset = (vip_uint32_t *)output->offsets;
		info->output_info[i].slice_num = output->slice_num;
		info->output_info[i].physical = output->physical;
		gcvip_debug("output logical ref=%p, physical ref=%p, offset=%p, num=%d,"
					"output buffer pyhsical=%08X\n",
					output->logical_in_cmd, output->physical_in_cmd, output->offsets,
					output->slice_num, info->output_info[i].physical);

		for (j = 0; j < output->slice_num; j++) {
			gcvip_debug("output in cmd logical=%08X, physical=%08X, offset=%08X\n",
						output->logical_in_cmd[j], output->physical_in_cmd[j],
						(vip_uint32_t)(output->offsets[j]));
		}

		if ((output->physical == 0) || (output->logical == VIP_NULL)) {
			gcvip_error("output buffer is NULL, please call vip_set_output() before this\n");
			gcGoOnError(VIP_ERROR_NETWORK_INCOMPATIBLE);
		}
	}

	gcvip_debug("wait-link physical=%08X, logical=%p, command physical=%08X, logical=%p,"
				"size=0x%08X bytes\n",
				info->waitlink_physical, info->waitlink_logical,
				info->commandbuffer_physical, info->commandbuffer_logical,
				info->commandbuffer_size);
onError:
	return status;
}
#endif

vip_status_e gcvip_create_network(
	vip_network_t *network,
	gcvip_data_reader *reader
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_bin_patch_data_entry_t *patch = VIP_NULL;
	gcvip_lite_segment_t *segment = VIP_NULL;
	vip_int32_t io_id = 0;
	vip_uint32_t i = 0, j = 0;
	GCVIP_INITIALIZE_CHECK();
	GCVIP_CHECK_NETWORK();

	network->weak_dup = vip_false_e;
	network->cmd_dirty = 1;
	network->input_dirty = 1;
	network->output_dirty = 1;
	network->prepare_count = 0;

	if ((reader->data == VIP_NULL) && (vpmdCREATE_NETWORK_FROM_FLASH)) {
		gcvip_error("fail to create network, maybe you should set"
					"vpmdCREATE_NETWORK_FROM_FLASH to 0 in gc_vip_common.h\n");
		gcGoOnError(VIP_ERROR_NETWORK_INCOMPATIBLE);
	}

	gcOnError(read_bin_fixed(reader, network));
	gcvip_info("cid=0x%X, NBG version=0x%X\n", context->hw_target, network->fixed.header.version);
	gcvip_info("network name=%s, thread_id=0x%x\n", network->fixed.header.network_name, gcvip_os_get_tid());

	/* hardware target check */
	if (network->fixed.header.hw_target != context->hw_target) {
		// rtk, 0xAE -> 0xAD, 0xD1->0x00
		if ((0xAD != network->fixed.header.hw_target) || (0X00 != context->hw_target)) {
			gcvip_error("binary target=0x%X, actually target=0x%X\n",
						network->fixed.header.hw_target, context->hw_target);
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}
	}

	/* binary version check */
	if (network->fixed.header.version > NBG_VERSION) {
		gcvip_warning("NBG format version=0x%X, support NBG version=0x%X\n",
					  network->fixed.header.version, NBG_VERSION);
	}

	gcOnError(read_bin_dynamic(reader, network));

#if vpmdENABLE_LAYER_DUMP
	/* per-layer run network for nn layer dump feature */
	network->segment_num = network->n_orig_layers;
#elif vpmdENABLE_CNN_PROFILING
	/* per-operation run network */
	network->segment_num = network->n_operations - gcvip_get_num_initend_operation(network);
#else
	/* Normal run mode. segment by software layer/operation.
	   segment_num is the number of segment in viplite. this is for
	   supporting CPU operation in viplite.
	*/
	network->segment_num = 2 * get_sw_operation_count(network) + 1;
#endif

	gcOnError(gcvip_user_allocate_memory(sizeof(gcvip_lite_segment_t) * network->segment_num,
										 (void **)&network->segments));
	gcvip_user_zero_memory((void *)network->segments,
						   sizeof(gcvip_lite_segment_t) * network->segment_num);

#if vpmdENABLE_LAYER_DUMP
	for (i = 0; i < network->n_operations; i++) {
		gcvip_bin_operation_t *operation = &network->operations[i];
		for (j = 0; j < network->n_orig_layers; j++) {
			if (operation->layer_id == j) {
				segment = &network->segments[j];
				segment->segm_start_id = j;
				segment->segm_end_id = j + 1;
				segment->name = gcvip_get_layer_name(network, j);
				segment->uid = gcvip_get_layer_uid(network, j);
				if (operation->type == GCVIP_OPERATION_TYPE_SW) {
					segment->is_sw_segm = vip_true_e;
				} else {
					segment->is_sw_segm = vip_false_e;
				}
			}
		}
	}
#elif vpmdENABLE_CNN_PROFILING
	{
		vip_uint32_t count = 0;
		for (i = 0; i < network->n_operations; i++) {
			gcvip_bin_operation_t *operation = &network->operations[i];
			if ((operation->type == GCVIP_OPERATION_TYPE_INIT) ||
				(operation->type == GCVIP_OPERATION_TYPE_END)) {
				continue;
			}
			segment = &network->segments[count];
			segment->segm_start_id = operation->layer_id; /* layer id */
			segment->segm_end_id = i;  /* op index */
			segment->name = gcvip_get_layer_name(network, operation->layer_id);
			segment->uid = gcvip_get_layer_uid(network, operation->layer_id);
			if (operation->type == GCVIP_OPERATION_TYPE_SW) {
				segment->is_sw_segm = vip_true_e;
			} else {
				segment->is_sw_segm = vip_false_e;
			}

			count++;
			if (count > network->segment_num) {
				gcvip_error("fail to check segment number\n");
				gcGoOnError(VIP_ERROR_NETWORK_INCOMPATIBLE);
			}
		}
	}
#else
	{
		vip_uint32_t pre_op_type = GCVIP_OPERATION_TYPE_NONE;
		vip_uint32_t prev_segm_id = 0;
		vip_uint32_t count = 0;
		for (i = 0; i < network->n_operations; i++) {
			gcvip_bin_operation_t *operation = &network->operations[i];

			if (operation->type == GCVIP_OPERATION_TYPE_SW) {
				/* 1. VIP segment */
				if (pre_op_type != GCVIP_OPERATION_TYPE_SW) {
					segment = &network->segments[count];
					segment->is_sw_segm = vip_false_e;
					segment->segm_start_id = prev_segm_id;
					segment->segm_end_id = i;
					segment->name = gcvip_get_layer_name(network, operation->layer_id);
					prev_segm_id = segment->segm_end_id;
					count++;
				}

				/* 2. software layer segment */
				segment = &network->segments[count];
				segment->is_sw_segm = vip_true_e;
				segment->segm_start_id = i;
				segment->segm_end_id = i;
				segment->name = gcvip_get_layer_name(network, operation->layer_id);
				prev_segm_id = i + 1;
				count++;
			}
			pre_op_type = operation->type;
		}

		if (prev_segm_id != network->n_operations) {
			/* this is VIP segment */
			segment = &network->segments[count];
			segment->is_sw_segm = vip_false_e;
			segment->segm_start_id = prev_segm_id;
			segment->segm_end_id = network->n_operations;
			segment->name = gcvip_get_layer_name(network, network->n_orig_layers);
			count++;
		}

		if (count != network->segment_num) {
			gcvip_error("please check segment number..\n");
			gcGoOnError(VIP_ERROR_NETWORK_INCOMPATIBLE);
		}
	}
#endif

	if ((0 == network->fixed.header.input_count) ||
		(0 == network->fixed.header.output_count)) {
		gcvip_error("network input or output is 0, input=%d, output=%d\n",
					network->fixed.header.input_count, network->fixed.header.output_count);
		gcGoOnError(VIP_ERROR_NETWORK_INCOMPATIBLE);
	}

	/* Create input/output table for command buffer. */
	gcOnError(gcvip_user_allocate_memory(sizeof(gcvip_io_patch_info_t) * network->fixed.header.input_count,
										 (void **) &network->network_inputs));
	gcOnError(gcvip_user_allocate_memory(sizeof(gcvip_io_patch_info_t) * network->fixed.header.output_count,
										 (void **) &network->network_outputs));
	gcvip_user_zero_memory((void *)network->network_inputs,
						   sizeof(gcvip_io_patch_info_t) * network->fixed.header.input_count);
	gcvip_user_zero_memory((void *)network->network_outputs,
						   sizeof(gcvip_io_patch_info_t) * network->fixed.header.output_count);

	for (i = 0; i < network->n_operations; i++) {
		gcvip_bin_operation_t *op = &network->operations[i];
		if (op->type != GCVIP_OPERATION_TYPE_SW) {
			for (j = 0; j < op->patch_count; j++) {
				patch = (gcvip_bin_patch_data_entry_t *)gcvip_get_patch_ptr_by_index(network,
						network->pd_entries,
						op->patch_index + j);
				io_id = patch->index;
				if (patch->source_type == GCVIP_SOURCE_INPUT) {
					if (io_id >= 0) {
						network->network_inputs[io_id].slice_num++;
					}
				} else if (patch->source_type == GCVIP_SOURCE_OUTPUT) {
					if (io_id >= 0) {
						network->network_outputs[io_id].slice_num++;
					}
				}
			}
		} else {
			for (j = 0; j < op->patch_count; j++) {
				gcvip_bin_layer_parameter_t *layer_param = &network->lp_entries[op->patch_index + j];
				io_id = layer_param->index;
				if (layer_param->source_type == GCVIP_SOURCE_INPUT) {
					if (io_id >= 0) {
						network->network_inputs[io_id].slice_num++;
					}
				} else if (layer_param->source_type == GCVIP_SOURCE_OUTPUT) {
					if (io_id >= 0) {
						network->network_outputs[io_id].slice_num++;
					}
				}
			}
		}
	}

	for (i = 0; i < network->n_inputs; i++) {
		if (network->network_inputs[i].slice_num > 0) {
			vip_uint32_t tmp_size = sizeof(vip_address_t) * network->network_inputs[i].slice_num;
			gcOnError(gcvip_user_allocate_memory(tmp_size,
												 (void **)&network->network_inputs[i].logical_in_cmd));
			gcvip_user_zero_memory(network->network_inputs[i].logical_in_cmd, tmp_size);

			tmp_size = sizeof(vip_uint32_t) * network->network_inputs[i].slice_num;
			gcOnError(gcvip_user_allocate_memory(tmp_size,
												 (void **)&network->network_inputs[i].physical_in_cmd));
			gcOnError(gcvip_user_allocate_memory(tmp_size, (void **)&network->network_inputs[i].offsets));
			gcvip_user_zero_memory(network->network_inputs[i].physical_in_cmd, tmp_size);
			gcvip_user_zero_memory(network->network_inputs[i].offsets, tmp_size);
		}
		network->network_inputs[i].counter = 0;
	}

	for (i = 0; i < network->n_outputs; i++) {
		if (network->network_outputs[i].slice_num > 0) {
			vip_uint32_t tmp_size = sizeof(vip_address_t) * network->network_outputs[i].slice_num;
			gcOnError(gcvip_user_allocate_memory(tmp_size,
												 (void **)&network->network_outputs[i].logical_in_cmd));
			gcvip_user_zero_memory(network->network_outputs[i].logical_in_cmd, tmp_size);

			tmp_size = sizeof(vip_uint32_t) * network->network_outputs[i].slice_num;
			gcOnError(gcvip_user_allocate_memory(tmp_size,
												 (void **)&network->network_outputs[i].physical_in_cmd));
			gcOnError(gcvip_user_allocate_memory(tmp_size,
												 (void **)&network->network_outputs[i].offsets));

			gcvip_user_zero_memory(network->network_outputs[i].physical_in_cmd, tmp_size);
			gcvip_user_zero_memory(network->network_outputs[i].offsets, tmp_size);
		}
		network->network_outputs[i].counter = 0;
	}

	status = get_sh_cmds_status(network);
	if (status != VIP_SUCCESS) {
		network->realloc_sh_buff = vip_true_e;
	}

#if vpmdENABLE_CAPTURE
	{
		GET_CONTEXT();
		gcvip_capture_hardware_info(context);
	}
#endif

onError:
	if (status != VIP_SUCCESS) {
		gcvip_error("fail to create network\n");
		gcvip_finish_network(network);
	}
	return status;
}

vip_status_e gcvip_create_network_from_file(
	IN gcvip_file_t file,
	OUT vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_data_reader reader;
	GCVIP_INITIALIZE_CHECK();
	GCVIP_CHECK_NETWORK();

	open_reader(&reader, VIP_NULL, 0, file);

	status = gcvip_create_network(network, &reader);
	if (status != VIP_SUCCESS) {
		gcvip_error("fail to create network\n");
		gcGoOnError(VIP_ERROR_NETWORK_INCOMPATIBLE);
	}

	close_reader(&reader);

onError:
	return status;
}

vip_status_e gcvip_create_network_from_memory(
	vip_network_t *network,
	void *data,
	vip_uint32_t size
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_data_reader reader;

#if vpmdCREATE_NETWORK_FROM_FLASH
	vip_uint8_t *logical = VIP_NULL;
	vip_uint32_t physical = 0xFFFF;
	vip_uint32_t nbg_size = 0;
	GCVIP_INITIALIZE_CHECK();
	GCVIP_CHECK_NETWORK();
	nbg_size = size;
	logical = (vip_uint8_t *)data; /* only for Linux */
	gcvip_user_get_flashaddress(&nbg_size, &logical, &physical);
	network->flash_logical = logical;
	network->flash_physical = physical;
	data = logical;
	gcvip_debug("create network from flash...\n");
#else
	GCVIP_INITIALIZE_CHECK();
	GCVIP_CHECK_NETWORK();

#if vpmDUMP_NETWORK_RESOURCE
	dump_save_file("viplite_network_binary.nb", data, size);
#endif
#endif

	open_reader(&reader, data, size, VIP_NULL);

	status = gcvip_create_network(network, &reader);
	if (status != VIP_SUCCESS) {
		gcvip_error("fail to create network\n");
		gcGoOnError(VIP_ERROR_NETWORK_INCOMPATIBLE);
	}

	close_reader(&reader);

onError:
	return status;
}

vip_status_e gcvip_destroy_network(
	IN vip_network network
)
{
	vip_uint32_t i = 0;
	GCVIP_CHECK_NETWORK();

#if vpmdENABLE_GROUP_MODE
	if (network->weak_dup) {
		/* finish dup network object */
		if (network->prepared_network) {
			gcvip_finish_network(network);
		}
	}
#endif

	/* Free the resources allocated during creating network. */
	for (i = 0; i < network->n_inputs; i++) {
		if (network->network_inputs[i].logical_in_cmd != VIP_NULL) {
			gcvip_user_free_memory(network->network_inputs[i].logical_in_cmd);
			network->network_inputs[i].logical_in_cmd = VIP_NULL;
		}
		if (network->network_inputs[i].physical_in_cmd != VIP_NULL) {
			gcvip_user_free_memory(network->network_inputs[i].physical_in_cmd);
			network->network_inputs[i].physical_in_cmd = VIP_NULL;
		}
		if (network->network_inputs[i].offsets != VIP_NULL) {
			gcvip_user_free_memory(network->network_inputs[i].offsets);
			network->network_inputs[i].offsets = VIP_NULL;
		}
	}

	for (i = 0; i < network->n_outputs; i++) {
		if (network->network_outputs[i].logical_in_cmd != VIP_NULL) {
			gcvip_user_free_memory((void *)network->network_outputs[i].logical_in_cmd);
			network->network_outputs[i].logical_in_cmd = VIP_NULL;
		}
		if (network->network_outputs[i].physical_in_cmd != VIP_NULL) {
			gcvip_user_free_memory((void *)network->network_outputs[i].physical_in_cmd);
			network->network_outputs[i].physical_in_cmd = VIP_NULL;
		}
		if (network->network_outputs[i].offsets != VIP_NULL) {
			gcvip_user_free_memory(network->network_outputs[i].offsets);
			network->network_outputs[i].offsets = VIP_NULL;
		}
	}

	if (network->network_inputs != VIP_NULL) {
		gcvip_user_free_memory((void *)network->network_inputs);
		network->network_inputs = VIP_NULL;
	}

	if (network->network_outputs != VIP_NULL) {
		gcvip_user_free_memory((void *)network->network_outputs);
		network->network_outputs = VIP_NULL;
	}

	if (network->tpCmds.logical != VIP_NULL) {
		gcvip_user_free_videomemory(network->tpCmds.handle);
		network->tpCmds.logical = VIP_NULL;
	}

	if (network->nnCmds.logical != VIP_NULL) {
		gcvip_user_free_videomemory(network->nnCmds.handle);
		network->nnCmds.logical = VIP_NULL;
	}

	if (!network->weak_dup) {
		if (network->dyna_data != VIP_NULL) {
			gcvip_user_free_memory(network->dyna_data);
			network->dyna_data = VIP_NULL;
		}

		if (network->LCD.handle != VIP_NULL) {
			gcvip_user_free_videomemory(network->LCD.handle);
			network->LCD.handle = VIP_NULL;
			network->LCD.logical = VIP_NULL;
			network->LCD.physical = 0;
			network->LCD.size = 0;
		}

#if vpmdENABLE_CHANGE_PPU_PARAM
		if (network->ppu_param_info != VIP_NULL) {
			gcvip_user_free_memory(network->ppu_param_info);
			network->ppu_param_info = VIP_NULL;
		}
#endif
	}

	if (network->segments != VIP_NULL) {
		gcvip_user_free_memory(network->segments);
		network->segments = VIP_NULL;
	}

	gcvip_info("destroy network=%p\n", network);
	/* Reset the network members. */
	gcvip_user_zero_memory((void *)network, sizeof(*network));

	return VIP_SUCCESS;
}

vip_status_e gcvip_finish_network(
	IN vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_lite_segment_t *segment = VIP_NULL;
	vip_uint32_t i = 0;
	GCVIP_CHECK_NETWORK();

	network->cmd_dirty = 1;
	network->prepared_network = vip_false_e;
	network->init_states_size = 0;

	for (i = 0; i < network->n_inputs; i++) {
		if (network->network_inputs[i].slice_num > 0) {
			vip_uint32_t tmp_size = sizeof(vip_address_t) * network->network_inputs[i].slice_num;
			gcvip_user_zero_memory(network->network_inputs[i].logical_in_cmd, tmp_size);

			tmp_size = sizeof(vip_uint32_t) * network->network_inputs[i].slice_num;

			gcvip_user_zero_memory(network->network_inputs[i].physical_in_cmd, tmp_size);
			gcvip_user_zero_memory(network->network_inputs[i].offsets, tmp_size);
		}
		network->network_inputs[i].counter = 0;
	}

	for (i = 0; i < network->n_outputs; i++) {
		vip_uint32_t tmp_size = sizeof(vip_address_t) * network->network_outputs[i].slice_num;
		gcvip_user_zero_memory(network->network_outputs[i].logical_in_cmd, tmp_size);

		tmp_size = sizeof(vip_uint32_t) * network->network_outputs[i].slice_num;
		gcvip_user_zero_memory(network->network_outputs[i].physical_in_cmd, tmp_size);
		gcvip_user_zero_memory(network->network_outputs[i].offsets, tmp_size);
		network->network_outputs[i].counter = 0;
	}
	for (i = 0; i < network->segment_num; i++) {
		segment = &network->segments[i];
		if ((segment != VIP_NULL) && (segment->is_sw_segm != vip_true_e)) {
			status = gcvip_user_wait_network(network, segment);
			if (status != VIP_SUCCESS) {
				gcvip_error("failed to wait network segment %d\n", i);
			}
		}
	}

	if (!network->weak_dup) {
		if ((network->pool.logical != VIP_NULL) && (VIP_NULL == network->memory_pool)) {
			gcvip_user_free_videomemory(network->pool.handle);
			network->pool.logical = VIP_NULL;
		}

		if (network->init_states.logical != VIP_NULL) {
			gcvip_user_free_videomemory(network->init_states.handle);
			network->init_states.logical = VIP_NULL;
			network->init_states.size = 0;
		}
	}

	if (network->segments != VIP_NULL) {
		for (i = 0; i < network->segment_num; i++) {
			segment = &network->segments[i];

			if (vip_true_e == segment->is_sw_segm) {
#if vpmdENABLE_SUPPORT_CPU_LAYER
				gcvip_sw_release_resource(segment);
#else
				gcvip_error("NOT support CPU layers, please set vpmdENABLE_SUPPORT_CPU_LAYER to 1\n");
#endif
			}

			if ((segment->sh_cmd_buffer.logical != VIP_NULL) &&
				((network->fixed.header.version < 0x00010005) || network->realloc_sh_buff)) {
				gcvip_user_free_videomemory(segment->sh_cmd_buffer.handle);
				segment->sh_cmd_buffer.logical = VIP_NULL;
			}

			if (segment->states_buffer.logical != VIP_NULL) {
				gcvip_user_free_videomemory(segment->states_buffer.handle);
				segment->states_buffer.logical = VIP_NULL;
			}
		}
	}

	return status;
}

vip_status_e gcvip_set_network(
	IN vip_network_t *network,
	IN vip_enum property,
	IN void *value
)
{
	vip_status_e status = VIP_SUCCESS;
	gcIsNULL(value);

	switch (property) {
	case VIP_NETWORK_PROP_SET_MEMORY_POOL: {
		vip_buffer buffer = (vip_buffer)value;
		vip_uint32_t pool_size = GCVIP_ALIGN(network->fixed.pool.size, gcdVIP_MEMORY_ALIGN_SIZE);
		GCVIP_CHECK_NETWORK();

		if (network->prepared_network) {
			gcvip_error("failed please set memory pool before calling prepare network\n");
			gcOnError(VIP_ERROR_FAILURE);
		}

		gcvip_debug("set network memory pool buffer=%p\n", buffer);
		if ((buffer->allocated > GCVIP_BUFFER_ALLOCATE_MAX) ||
			(GCVIP_BUFFER_ALLOCATE_MAX == buffer->allocated)) {
			gcvip_error("failed to set memory pool, memory not allocated=%d\n", buffer->allocated);
			gcOnError(VIP_ERROR_FAILURE);
		}
		if (0 == buffer->memory.physical) {
			gcvip_error("failed to set memory pool, handle=%p, logical=%d, physical=0x%08x\n",
						buffer->memory.handle, buffer->memory.logical,
						buffer->memory.physical);
			gcOnError(VIP_ERROR_FAILURE);
		}
		if (pool_size > buffer->memory.size) {
			gcvip_error("failed to set memory pool, buffer size is small than"
						"network memory pool size, buffer_size=%d < pool_size=%d\n",
						buffer->memory.size, pool_size);
			gcOnError(VIP_ERROR_FAILURE);
		}
		network->memory_pool = buffer;
	}
	break;

	case VIP_NETWORK_PROP_CHANGE_PPU_PARAM: {
#if vpmdENABLE_CHANGE_PPU_PARAM
		network->change_ppu_param = vip_false_e;

		if (network->prepared_network) {
			gcvip_error("failed please enable change ppu params before calling prepare network\n");
			gcOnError(VIP_ERROR_FAILURE);
		}

		if (value != VIP_NULL) {
			vip_uint32_t *data = (vip_uint32_t *)value;
			if (1 == *data) {
				if (1 == network->fixed.header.feature_db.change_ppu_param) {
					network->change_ppu_param = vip_true_e;
				} else {
					gcvip_error("the network not support change ppu param change ppu=%d\n",
								network->fixed.header.feature_db.change_ppu_param);
					gcOnError(VIP_ERROR_FAILURE);
				}
			}
		} else {
			gcvip_error("failed to set changes ppu param, valus is NULL\n");
			gcOnError(VIP_ERROR_FAILURE);
		}
#else
		gcvip_error("driver doesn't support this feature, please enable in driver\n");
#endif
	}
	break;

	default:
		gcvip_error("not implement this case property=%d\n", property);
		break;
	}

	return status;

onError:
	gcvip_error("failed to set network=%p property=%d, value=%p\n",
				network, property, value);
	return status;
}

vip_status_e gcvip_query_network(
	IN vip_network_t *network,
	IN vip_enum property,
	OUT void *value
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();
	gcIsNULL(value);

	switch (property) {
	case VIP_NETWORK_PROP_LAYER_COUNT:
		*((vip_uint32_t *)value) = network->fixed.header.layer_count;
		break;

	case VIP_NETWORK_PROP_INPUT_COUNT:
		*((vip_uint32_t *)value) = network->fixed.header.input_count;
		break;

	case VIP_NETWORK_PROP_OUTPUT_COUNT:
		*((vip_uint32_t *)value) = network->fixed.header.output_count;
		break;

	case VIP_NETWORK_PROP_NETWORK_NAME:
		gcvip_user_memcopy(value, network->fixed.header.network_name,
						   sizeof(network->fixed.header.network_name));
		break;
	case VIP_NETWORK_PROP_MEMORY_POOL_SIZE:
		*((vip_uint32_t *)value) = GCVIP_ALIGN(network->fixed.pool.size, gcdVIP_MEMORY_ALIGN_SIZE);
		break;

#if vpmdENABLE_SECURE
	case VIP_NETWORK_PROP_READ_REG_IRQ: {
		vip_uint32_t *data = (vip_uint32_t *)value;
		gcvip_user_read_reg(0x00010, (vip_uint32_t *)value);
		if (0x10 == *data) {
#if vpmdENABLE_FLUSH_CPU_CACHE && (vpmdENABLE_DEBUG_LOG > 3)
			gcvip_debug("network run complete, flush output buffers\n");
			if (network != VIP_NULL) {
				status = flush_output_cache(network);
				if (status != VIP_SUCCESS) {
					gcvip_error("failed to flush output cache in secure mode\n");
				}
			} else {
				gcvip_error("failed to flush output buffer cache\n");
			}
#endif

#if (vpmdENABLE_CAPTURE > 1)
			capture_network_output(network);
#endif

#if vpmDUMP_NETWORK_RESOURCE
			dump_network_outputs(network);
#endif
		} else if (0x00 != *data) {
			gcvip_error("failed to read irq reg value=0x%08x\n", *data);
		}
	}
	break;
#endif

#if vpmdENABLE_USE_AGENT_TRIGGER
	case VIP_NETWORK_PROP_ADDRESS_INFO:
		if (network->prepared_network) {
			status = gcvip_get_network_address_info(network, value);
		} else {
			gcvip_error("failed to query address, network not prepare\n");
			gcOnError(VIP_ERROR_FAILURE);
		}
		break;
#endif

	default:
		gcvip_error("query network not support this property=%d\n", property);
		status = VIP_ERROR_INVALID_ARGUMENTS;
		break;
	}

	return status;

onError:
	gcvip_error("failed to query network, value=%p, property=%d\n", value, property);
	return status;
}

/*
 * @brief
 * Generate the executable command buffer from the given network object (loaded from NBG file).
 * It should create the pool, load the data, and patch the necessary addresses used by commands.
 */
vip_status_e gcvip_prepare_network(
	vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t sh_cmd_size = 0;
	vip_uint32_t states_size = 0;
	vip_uint32_t i = 0;
	gcvip_videomemory_t *allocation = VIP_NULL;
	GCVIP_INITIALIZE_CHECK();

	/* TODO: Preparing as following.
	 * 1. Create pool;
	 * 2. Acquire the command buffer;
	 * 3. Generate the ctrl states (to trigger TP/NN and run SH). Prepare done.
	*/
	if (network->cmd_dirty == 0) {
		gcvip_error("network not ready....\n");
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	if (network->segment_num < 1) {
		gcvip_error("fail the number of segment is %d\n", network->segment_num);
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	/* 1. Create the pool if necessary. */
	if (network->fixed.pool.size > 0) {
		vip_uint32_t tmp_size = GCVIP_ALIGN(network->fixed.pool.size, gcdVIP_MEMORY_ALIGN_SIZE);
		network->pool.size = network->fixed.pool.size;
		if ((network->memory_pool != VIP_NULL) &&
			(tmp_size <= network->memory_pool->memory.size)) {
			network->pool.logical = network->memory_pool->memory.logical;
			network->pool.handle = network->memory_pool->memory.handle;
			network->pool.physical = network->memory_pool->memory.physical;
			gcvip_debug("memory pool specify by app, physical=0x%08X, logical=0x%p, pool size=0x%08X\n",
						network->pool.physical, network->pool.logical, network->memory_pool->memory.size);
		} else {
			gcOnError(gcvip_user_allocate_videomemory(&network->pool.logical, &network->pool.handle,
					  &network->pool.physical, network->pool.size,
					  gcdVIP_MEMORY_ALIGN_SIZE));
			gcvip_user_zero_memory(network->pool.logical, network->pool.size);
#if vpmdENABLE_FLUSH_CPU_CACHE
			gcOnError(gcvip_user_flush_cache(network->pool.handle, network->pool.physical,
											 network->pool.logical, network->pool.size,
											 GCKVIP_CACHE_CLEAN));
#endif
			gcvip_debug("memory pool physical=0x%08X, logical=0x%p, pool size=0x%08X\n",
						network->pool.physical, network->pool.logical, network->pool.size);
		}
	}

	network->init_states.size = get_init_states_size(network) + APPEND_COMMAND_SIZE;
	if (network->init_states.size > APPEND_COMMAND_SIZE) {
		allocation = &network->init_states;
		gcOnError(gcvip_user_allocate_videomemory((vip_uint8_t **)&allocation->logical,
				  &allocation->handle,
				  &allocation->physical,
				  allocation->size,
				  gcdVIP_MEMORY_ALIGN_SIZE));
		gcvip_user_zero_memory(allocation->logical, allocation->size);
	}

	for (i = 0; i < network->segment_num; i++) {
		gcvip_lite_segment_t *segment = &network->segments[i];

		if (segment->is_sw_segm == vip_false_e) {
			sh_cmd_size = get_sh_command_size(network, segment);
			states_size = get_states_size(network, segment);
			if (states_size >= gcdVIP_MAX_CMD_SIZE) {
				states_size = get_insertlink_states_size(network, segment, states_size);
			}

			/* 2. Acquire the command buffer. */
			if ((sh_cmd_size > 0) &&
				((network->fixed.header.version < 0x00010005) || network->realloc_sh_buff)) {
				allocation = &segment->sh_cmd_buffer;
				gcOnError(gcvip_user_allocate_videomemory((vip_uint8_t **)&allocation->logical,
						  &allocation->handle,
						  &allocation->physical,
						  sh_cmd_size,
						  gcdVIP_SH_ALIGN_SIZE));
				allocation->size = sh_cmd_size;
				gcvip_user_zero_memory(allocation->logical, sh_cmd_size);
			}

			if (states_size > 0) {
				allocation = &segment->states_buffer;
				gcOnError(gcvip_user_allocate_videomemory((vip_uint8_t **)&allocation->logical,
						  &allocation->handle,
						  &allocation->physical,
						  states_size + APPEND_COMMAND_SIZE,
						  gcdVIP_MEMORY_ALIGN_SIZE));
				allocation->size = states_size;
				gcvip_user_zero_memory(allocation->logical, states_size + APPEND_COMMAND_SIZE);
			} else {
				gcvip_error("states size is 0\n");
				gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
			}

			/* 3. Patch and generate command buffer. */
			status = generate_hardware_command(network, segment);
			if (status != VIP_SUCCESS) {
				gcvip_error("failed to generate hardware commands\n");
				gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
			}

			/* 4. insert link command */
			if (segment->patch_num > 0) {
				status = gcvip_patch_link(segment);
				if (status != VIP_SUCCESS) {
					gcvip_error("failed to patch link cmd in command buffer\n");
					gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
				}
			}

#if vpmdENABLE_FLUSH_CPU_CACHE
			status = flush_cmd_cache(network, segment);
			if (status != VIP_SUCCESS) {
				gcvip_error("fail to flush commands cache\n");
				gcGoOnError(VIP_ERROR_IO);
			}
#endif

			if (segment->patch_pos != VIP_NULL) {
				gcvip_user_free_memory(segment->patch_pos);
				segment->patch_pos = VIP_NULL;
			}
			if (segment->operation_pos != VIP_NULL) {
				gcvip_user_free_memory((void *)segment->operation_pos);
				segment->operation_pos = VIP_NULL;
			}
			if (segment->split_size != VIP_NULL) {
				gcvip_user_free_memory(segment->split_size);
				segment->split_size = VIP_NULL;
			}
		} else {
#if vpmdENABLE_SUPPORT_CPU_LAYER
			/* handle cpu operation */
			gcvip_debug("prepare cpu layer.. segment index=%d, num=%d\n", i, network->segment_num);
			status = gcvip_sw_prepare_layer(network, segment);
			if (status != VIP_SUCCESS) {
				gcvip_error("fail to prepare software operation\n");
				gcGoOnError(VIP_ERROR_IO);
			}
#else
			gcvip_error("NOT support CPU layers, please set vpmdENABLE_SUPPORT_CPU_LAYER to 1\n");
#endif
		}
	}

	network->cmd_dirty = 0;

#if vpmdENABLE_FLUSH_CPU_CACHE && !vpmdCREATE_NETWORK_FROM_FLASH
	gcOnError(gcvip_user_flush_cache(network->LCD.handle, network->LCD.physical,
									 network->LCD.logical, network->LCD.size,
									 GCKVIP_CACHE_FLUSH));
#endif

#if vpmdENABLE_MULTIPLE_TASK
	status = gcvip_os_lock_mutex(context->init_cmds_mutex);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to lock init cmds mutex\n");
		gcGoOnError(VIP_ERROR_FAILURE);
	}
#endif

	status = gcvip_init_states(network);
	if (status != VIP_SUCCESS) {
		gcvip_error("%fail to submit init states..\n");
		gcGoOnError(status);
	}

	if ((network->n_hw_init_ops > 0) && (0 == context->init_commands.size)) {
		status = patch_init_command(network);
		if (status != VIP_SUCCESS) {
			gcvip_error("fail to patch init command\n");
			gcGoOnError(status);
		}

		status = gcvip_init_commands(network);
		if (status != VIP_SUCCESS) {
			gcvip_error("fail to initialize command\n");
			gcGoOnError(status);
		}

		/* free initialize video memory if PM is disabled */
#if (0 == vpmdPOWER_OFF_TIMEOUT) && !vpmdENABLE_USER_CONTROL_POWER && !vpmdENABLE_SUSPEND_RESUME
		if (context->ICD.handle != VIP_NULL) {
			gcvip_user_free_videomemory(context->ICD.handle);
			context->ICD.handle = VIP_NULL;
			context->ICD.logical = VIP_NULL;
		}

		if (context->init_commands.handle != VIP_NULL) {
			gcvip_user_free_videomemory(context->init_commands.handle);
			context->init_commands.handle = VIP_NULL;
			context->init_commands.logical = VIP_NULL;
			context->init_commands.size = 0;
		}
#endif
	}

#if vpmdENABLE_MULTIPLE_TASK
	status = gcvip_os_unlock_mutex(context->init_cmds_mutex);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to lock init cmds mutex\n");
	}
#endif

#if vpmdENABLE_BW_PROFILING
	{
		vip_uint32_t data = 0;
		gcvip_user_read_reg(0x00040, &data);
		gcvip_user_read_reg(0x00044, &data);
		gcvip_user_read_reg(0x005C0, &data);
		gcvip_user_read_reg(0x005D0, &data);
	}
#endif

	context->init_status = GCVIP_INIT_CMD_STATUS_DONE;

	network->prepared_network = vip_true_e;

	if (network->prepare_count >= 255) {
		network->prepare_count = 0;
	}
	network->prepare_count++;

	gcvip_info("prepare network done, alloc sh cmd status=%d, prepare_count=%d\n",
			   network->realloc_sh_buff, network->prepare_count);

	return status;

onError:
	gcvip_error("fail to prepare network\n");
#if vpmdENABLE_MULTIPLE_TASK
	gcvip_os_unlock_mutex(context->init_cmds_mutex);
#endif
	gcvip_finish_network(network);

	return status;
}

static vip_status_e gcvip_commit_network(
	IN vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	gcvip_lite_segment_t *segment = VIP_NULL;
#if vpmdENABLE_CAPTURE
	GET_CONTEXT();
#endif
	GCVIP_CHECK_NETWORK();

	if (network->prepared_network == vip_false_e) {
		gcvip_error("network doesn't initialize\n");
		gcGoOnError(VIP_ERROR_NETWORK_NOT_PREPARED);
	}

	/* Error if network is not well prepared. */
	if (network->cmd_dirty != 0) {
		gcvip_error("network is not well prepared\n");
		gcGoOnError(VIP_ERROR_NETWORK_NOT_PREPARED);
	}

	if (network->input_dirty != 0) {
		gcOnError(patch_network_inputs(network));
	}

	if (network->output_dirty != 0) {
		gcOnError(patch_network_outputs(network));
	}

#if vpmdENABLE_CAPTURE
	gcvip_capture_dump_list(context, network);
#endif

	/* submit commands */
	for (i = 0; i < network->segment_num; i++) {
		segment = &network->segments[i];
		if (segment->is_sw_segm == vip_false_e) {
#if vpmdDUMP_COMMANDS_EVERY_RUN
			gcvip_dump_states_command(network, segment, RUN_DUMP);
#endif

#if vpmdENABLE_CNN_PROFILING
			segment->start_time = gcvip_os_get_time();
#endif

#if vpmdPOWER_OFF_TIMEOUT || vpmdENABLE_USER_CONTROL_POWER || vpmdENABLE_SUSPEND_RESUME
			status = gcvip_check_power_status(network);
			if (status != VIP_SUCCESS) {
				gcvip_error("failed to check power status\n");
				gcGoOnError(VIP_ERROR_FAILURE);
			}
#endif

			status = gcvip_commit_command(&segment->states_buffer, GCKVIP_SUBMIT_WITH_EVENT);
			if (status != VIP_SUCCESS) {
				gcvip_error("failed to submit network\n");
				gcGoOnError(status);
			}

#if vpmdENABLE_CAPTURE
			gcvip_capture_dump_states(context, network, segment);
#endif

#if vpmdENABLE_LAYER_DUMP || vpmdENABLE_CNN_PROFILING
#if vpmdENABLE_CNN_PROFILING
			status = gcvip_layer_profile(network, segment);
#else
			status = gcvip_user_wait_network(network, segment);
#endif

			gcOnError(status);

#if vpmdENABLE_LAYER_DUMP
			gcvip_layer_dump(segment, network, i);
#endif
#endif
		} else {
			/*1. wait last vip segment finish */
#if (!vpmdENABLE_CNN_PROFILING && !vpmdENABLE_LAYER_DUMP)
			if (i > 0) {
				vip_int32_t j = 0;
				gcvip_lite_segment_t *last_segment = VIP_NULL;
				/* find out previous VIP segment */
				for (j = i - 1; j >= 0; j--) {
					last_segment = &network->segments[j];
					if (last_segment->is_sw_segm == vip_false_e) {
						break;
					}
				}
				if ((last_segment != VIP_NULL) && (last_segment->is_sw_segm == vip_false_e)) {
					status = gcvip_user_wait_network(network, last_segment);
					if (status != VIP_SUCCESS) {
						gcvip_error("failed to wait network finish in sw branch\n");
						gcGoOnError(status);
					}

#if vpmdENABLE_BW_PROFILING
					gcvip_bw_profiling(network);
#endif
				}
			}
#endif

#if vpmdENABLE_SUPPORT_CPU_LAYER
			/*2. do sw segment*/
			gcvip_debug("do sw operation...\n");
			gcOnError(gcvip_sw_do_layer(network, segment));
#else
			gcvip_error("NOT support CPU layers, please set vpmdENABLE_SUPPORT_CPU_LAYER to 1\n");
#endif

#if vpmdENABLE_LAYER_DUMP
			gcvip_layer_dump(segment, network, i);
#endif
		}
	}

#if vpmdENABLE_CNN_PROFILING
	gcvip_os_print("=== network process total time=%d us or %d ms===\n",
				   network->total_time, network->total_time / 1000);
#endif

onError:
	return status;
}

vip_status_e gcvip_trigger_network(
	IN vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;

	status = gcvip_commit_network(network);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to commit network\n");
		gcGoOnError(VIP_ERROR_IO);
	}

onError:
	return status;
}

/* Waiting for commands to be done. */
vip_status_e gcvip_wait_network(
	IN vip_network network
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_lite_segment_t *final_segment = VIP_NULL;
	vip_int32_t i = 0;

	if (VIP_NULL == network) {
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	for (i = (vip_int32_t)(network->segment_num - 1); i >= 0; i--) {
		final_segment = &network->segments[i];
		if ((final_segment != VIP_NULL) && (final_segment->is_sw_segm == vip_false_e)) {
			break;
		}
	}

#if (!vpmdENABLE_CNN_PROFILING && !vpmdENABLE_LAYER_DUMP && !vpmdENABLE_SECURE)
	/* wait network done */
	if ((final_segment != VIP_NULL) && (final_segment->is_sw_segm == vip_false_e)) {
		status = gcvip_user_wait_network(network, final_segment);
		if (status != VIP_SUCCESS) {
			gcvip_error("failed to wait network finish in gcvip wait network\n");
			gcGoOnError(status);
		}

#if vpmdENABLE_BW_PROFILING
		gcvip_bw_profiling(network);
#endif
	}
#endif

#if vpmdENABLE_FLUSH_CPU_CACHE && !vpmdENABLE_SECURE && (vpmdENABLE_DEBUG_LOG > 3)
	gcOnError(flush_output_cache(network));
#endif

#if (vpmdENABLE_CAPTURE > 1)
	capture_network_output(network);
#endif

#if vpmDUMP_NETWORK_RESOURCE && !vpmdENABLE_SECURE
	dump_network_outputs(network);
#endif

onError:
	return status;
}

vip_status_e gcvip_run_network(
	IN vip_network_t *network
)
{
	vip_status_e status = VIP_SUCCESS;
	GCVIP_CHECK_NETWORK();

	status = gcvip_commit_network(network);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to commit network\n");
		gcGoOnError(VIP_ERROR_IO);
	}

	status = gcvip_wait_network(network);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to wait network finish in run network\n");
		gcGoOnError(status);
	}

onError:
	return status;
}

vip_status_e gcvip_set_input(
	IN vip_network_t *network,
	IN vip_uint32_t index,
	IN vip_buffer input
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_io_patch_info_t *entry = VIP_NULL;
	gcvip_videomemory_t *memory = VIP_NULL;
	vip_int8_t matched = vip_true_e;
	GCVIP_INITIALIZE_CHECK();
	GCVIP_CHECK_NETWORK();

	if (VIP_NULL == input) {
		gcvip_error("input is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	memory = &input->memory;
	if (VIP_NULL == memory) {
		gcvip_error("failed to set input, parameter is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	if (index >= network->fixed.header.input_count) {
		/* Out of index. */
		gcvip_error("index > network->fixed.header.input_count error\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	matched = gcvip_check_io_params(network, index, input, 0);
	if (vip_true_e != matched) {
		gcvip_error("failed to set input %d, parameter not matched\n", index);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	if (network->cmd_dirty) {
		/* Not ready. */
		gcvip_error("network command buffer not ready error\n");
		gcGoOnError(VIP_ERROR_NETWORK_NOT_PREPARED);
	}

	/* Set input. */
	entry = &network->network_inputs[index];
	entry->physical = memory->physical;
	entry->logical = memory->logical;
	entry->buffer = input;

#if vpmdENABLE_FLUSH_CPU_CACHE && (vpmdENABLE_DEBUG_LOG > 3)
	/* flush user memory cache */
	gcOnError(gcvip_user_flush_cache(memory->handle,
									 memory->physical,
									 memory->logical,
									 memory->size,
									 GCKVIP_CACHE_FLUSH));
#endif

	gcvip_debug("set input index=%d, physical=0x%08x, logical=%p, mem_handle=%p, size=0x%d\n",
				index, memory->physical, memory->logical, memory->handle,
				memory->size);

	/* Mark cmd input dirty. */
	network->input_dirty = 1;

	return status;

onError:
	gcvip_error("failed to set network input %d, buffer_handle=%p, status=%d\n",
				index, memory->handle, status);
	return status;
}

vip_status_e gcvip_set_output(
	IN vip_network_t *network,
	IN vip_uint32_t index,
	IN vip_buffer output
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_io_patch_info_t *entry = VIP_NULL;
	gcvip_videomemory_t *memory = VIP_NULL;
	vip_int8_t matched = vip_true_e;
	GCVIP_INITIALIZE_CHECK();
	GCVIP_CHECK_NETWORK();

	if (VIP_NULL == output) {
		gcvip_error("output is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	memory = &output->memory;
	if (VIP_NULL == memory) {
		gcvip_error("failed to set output, parameter is NULL\n");
		return VIP_ERROR_INVALID_ARGUMENTS;
	}

	if (index >= network->fixed.header.output_count) {
		/* Out of index. */
		gcvip_error("index > network->fixed.header.output_count error\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	matched = gcvip_check_io_params(network, index, output, 1);
	if (vip_true_e != matched) {
		gcvip_error("failed to set output %d, parameter not matched\n", index);
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	if (network->cmd_dirty) {
		/* Not ready. */
		gcvip_error("network command buffer not ready error\n");
		gcGoOnError(VIP_ERROR_NETWORK_NOT_PREPARED);
	}

	/* Set output. */
	entry = &network->network_outputs[index];
	entry->physical = memory->physical;
	entry->logical = memory->logical;
	entry->buffer = output;

	gcvip_debug("set output index=%d, physical=0x%08x, logical=%p, mem_handle=%p, size=0x%x\n",
				index, memory->physical, memory->logical, memory->handle,
				memory->size);

	/* Mark cmd input dirty. */
	network->output_dirty = 1;

	return status;

onError:
	gcvip_error("failed to set network output %d, buffer_handle=%p, status=%d\n",
				index, memory->handle, status);
	return status;
}

/*
@brief Query network input information. format, shape, quante format and so on.
@param network The network object create by vip_create_network().
@param index The index of this input.
@param property The query property, see vip_buffer_property_e.
@param [OUT] value The return value.
*/
vip_status_e gcvip_query_input(
	IN vip_network_t *network,
	IN vip_uint32_t index,
	IN vip_enum property,
	OUT void *value
)
{
	vip_status_e status = VIP_SUCCESS;
	void *input;
	GCVIP_CHECK_NETWORK();
	gcIsNULL(value);

	if (index >= network->fixed.header.input_count) {
		gcvip_error("index > network->fixed.header.input_count error\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	input = (void *)gcvip_get_io_ptr_by_index(network, network->inputs, index);

	if (network->fixed.header.version >= 0x0001000B) {
		gcOnError(gcvip_get_io_param(network, input, property, value));
	} else {
		gcOnError(gcvip_get_io_param_old(network, input, property, value));
	}

	return status;

onError:
	gcvip_error("failed to query input[%d], property=%d\n", index, property);
	return status;
}

/*
@brief Query network output information. format, shape, quante format and so on.
@param network The network object create by vip_create_network().
@param index The index of this output.
@param property The query property, see vip_buffer_property_e.
@param [OUT] value The return value.
*/
vip_status_e gcvip_query_output(
	IN vip_network_t *network,
	IN vip_uint32_t index,
	IN vip_enum property,
	OUT void *value
)
{
	vip_status_e status = VIP_SUCCESS;
	void *output = VIP_NULL;
	GCVIP_CHECK_NETWORK();
	gcIsNULL(value);

	if (index >= network->fixed.header.output_count) {
		gcvip_error("index > network->fixed.header.input_count error\n");
		gcGoOnError(VIP_ERROR_INVALID_ARGUMENTS);
	}

	output = (void *)gcvip_get_io_ptr_by_index(network, network->outputs, index);

	if (network->fixed.header.version >= 0x0001000B) {
		gcOnError(gcvip_get_io_param(network, output, property, value));
	} else {
		gcOnError(gcvip_get_io_param_old(network, output, property, value));
	}

	return status;

onError:
	gcvip_error("failed to query output[%d], property=%d\n", index, property);
	return status;
}

/*
@brief Get the size of buffer format.
@param format
*/
vip_uint32_t gcvip_get_format_size(
	vip_enum format
)
{
	vip_uint32_t size = 1;
	switch (format) {
	case VIP_BUFFER_FORMAT_FP32:
		size = sizeof(vip_float_t);
		break;
	case VIP_BUFFER_FORMAT_UINT32:
	case VIP_BUFFER_FORMAT_INT32:
		size = sizeof(vip_int32_t);
		break;
	case VIP_BUFFER_FORMAT_FP16:
	case VIP_BUFFER_FORMAT_BFP16:
	case VIP_BUFFER_FORMAT_UINT16:
	case VIP_BUFFER_FORMAT_INT16:
		size = sizeof(vip_int16_t);
		break;

	case VIP_BUFFER_FORMAT_UINT8:
	case VIP_BUFFER_FORMAT_INT8:
		size = sizeof(vip_int8_t);
		break;

	case VIP_BUFFER_FORMAT_FP64:
	case VIP_BUFFER_FORMAT_UINT64:
	case VIP_BUFFER_FORMAT_INT64:
		size = sizeof(vip_int64_t);
		break;

	default:
		gcvip_error("viplite doesn't support this buffer format=%d\n", format);
		break;
	}

	return size;
}

/*
@brief Initialize VIPLite software and hardware.
@param sys_mem_size The size of system memory heap.
@pram video_mem_size The size of video memory heap.
*/
vip_status_e gcvip_init(
	IN vip_uint32_t sys_mem_size,
	IN vip_uint32_t video_mem_size
)
{
	vip_status_e status = VIP_SUCCESS;
	gckvip_query_database_t database;
	GET_CONTEXT();

#if vpmdENABLE_MULTIPLE_TASK
#if defined(LINUX)
	/* some risk, only one initialize_mutex lock if many thread call vip_init at the same time */
	pthread_mutex_lock(&init_mutex);
#endif
#endif

	gcvip_info("VIPLite driver software version %d.%d.%d\n",
			   VERSION_MAJOR, VERSION_MINOR, VERSION_SUB_MINOR);

#if vpmdENABLE_MULTIPLE_TASK
	if (VIP_NULL == context->initialize_mutex) {
		gcvip_info("start create user initialize mutex...\n");
		gcvip_os_zero_memory(context, sizeof(gcvip_lite_context_t));
		status = gcvip_os_create_mutex(&context->initialize_mutex);
		if (status != VIP_SUCCESS) {
			gcvip_error("failed to create mutex for user initialize\n");
			gcGoOnError(VIP_ERROR_IO);
		}
	}
	gcvip_os_lock_mutex(context->initialize_mutex);
#endif

	if (context->initialize > 0) {
		gcvip_info("vip has been initialized, don't need initialize again\n");

#if vpmdENABLE_MULTIPLE_TASK
		context->initialize++;
		if (context->initialize > SUPPORT_MAX_TASK_NUM) {
			gcvip_error("failed to initialize, max support %d tasks\n", SUPPORT_MAX_TASK_NUM);
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}
		gcvip_os_unlock_mutex(context->initialize_mutex);
#if defined(LINUX)
		pthread_mutex_unlock(&init_mutex);
#endif
#endif

		return VIP_SUCCESS;
	}

	/* init underlying software layers and HW. */
	status = gcvip_user_init(sys_mem_size, video_mem_size);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to user init\n");
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}

	status = gcvip_user_query_database(&database);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to query database\n");
		gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
	}
	context->vip_sram_base = database.vip_sram_base;
	context->vip_sram_size = database.vip_sram_size;
	context->axi_sram_base = database.axi_sram_base;
	context->axi_sram_size = database.axi_sram_size;
	context->hw_target = database.hw_cid;
	gcvip_debug("axi sram size=0x%x, address=0x%08X, vip sram size=0x%x, address=0x%08X, cid=0x%X\n",
				context->axi_sram_size, context->axi_sram_base, context->vip_sram_size,
				context->vip_sram_base, context->hw_target);

#if vpmdENABLE_CAPTURE
	gcOnError(gcvip_capture_init(context));
#endif

#if vpmdENABLE_MULTIPLE_TASK
	status = gcvip_os_create_mutex(&context->init_cmds_mutex);
	if (status != VIP_SUCCESS) {
		gcvip_error("failed to create init cmds mutex\n");
	}
#endif

	context->initialize = 1;

onError:
#if vpmdENABLE_MULTIPLE_TASK
	gcvip_os_unlock_mutex(context->initialize_mutex);
#if defined(LINUX)
	pthread_mutex_unlock(&init_mutex);
#endif
#endif

	return status;
}

/*
@brief Destroy VIPLite software and hardware.
*/
vip_status_e gcvip_destroy(void)
{
	vip_status_e status = VIP_SUCCESS;
	GET_CONTEXT();

#if vpmdENABLE_MULTIPLE_TASK
#if defined(LINUX)
	pthread_mutex_lock(&init_mutex);
#endif

	if (context->initialize_mutex != VIP_NULL) {
		gcvip_os_lock_mutex(context->initialize_mutex);
	} else {
		gcvip_error("error initialize mutex is NULL in do destory\n");
	}
#endif

#if vpmdENABLE_MULTIPLE_TASK
	context->initialize--;

	gcvip_debug("vip destroy initialize count=%d\n", context->initialize);
	if (context->initialize <= 0) {
#else
	if (context->initialize > 0) {
		context->initialize = 0;
#endif
#if vpmdENABLE_CAPTURE
		gcvip_capture_uninit(context);
#endif

		if (context->ICD.handle != VIP_NULL) {
			gcvip_user_free_videomemory(context->ICD.handle);
			context->ICD.handle = VIP_NULL;
			context->ICD.logical = VIP_NULL;
		}

		if (context->init_commands.handle != VIP_NULL) {
			gcvip_user_free_videomemory(context->init_commands.handle);
			context->init_commands.handle = VIP_NULL;
			context->init_commands.logical = VIP_NULL;
			context->init_commands.size = 0;
		}

		status = gcvip_user_destroy();
		if (status != VIP_SUCCESS) {
			gcvip_error("failed to user destroy..\n");
		}

#if vpmdENABLE_MULTIPLE_TASK
		if (context->init_cmds_mutex != VIP_NULL) {
			gcvip_os_unlock_mutex(context->init_cmds_mutex);
			gcvip_info("destroy init cmds mutex\n");
			gcvip_os_destroy_mutex(context->init_cmds_mutex);
			context->init_cmds_mutex = VIP_NULL;
		}
		/* unlock and destroy initialize mutex last */
		if (context->initialize_mutex != VIP_NULL) {
			gcvip_os_unlock_mutex(context->initialize_mutex);
			gcvip_info("destroy initialize mutex\n");
			gcvip_os_destroy_mutex(context->initialize_mutex);
			context->initialize_mutex = VIP_NULL;
		}
#endif

		gcvip_user_zero_memory(context, sizeof(gcvip_lite_context_t));
	}
#if vpmdENABLE_MULTIPLE_TASK
	else {
		if (context->initialize_mutex != VIP_NULL) {
			gcvip_os_unlock_mutex(context->initialize_mutex);
		}
	}
#if defined(LINUX)
	pthread_mutex_unlock(&init_mutex);
#endif
#endif

	return status;
}

#if vpmdENABLE_GROUP_MODE
/*
@brief Link two command buffer together
*/
vip_status_e gcvip_link_command(
	gcvip_videomemory_t *pre_cmd,
	gcvip_videomemory_t *cur_cmd
)
{
	vip_status_e status = VIP_SUCCESS;

	gcvip_append_link((vip_uint32_t *)(pre_cmd->logical + pre_cmd->size),
					  cur_cmd->size + APPEND_COMMAND_SIZE,
					  cur_cmd->physical);

	return status;
}

/*
@brief Wait for HW to finish executing the submitted group tasks.
@param group vip_group object
*/
vip_status_e gcvip_wait_group(
	vip_group group
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_videomemory_t *first_cmd = VIP_NULL;

	/* run tasks */
	status = gcvip_group_item_get_command(&group->tasks[0], &first_cmd);
	if (status == VIP_SUCCESS) {
		/* Wait for commands to be done. */
		status = gcvip_user_wait(first_cmd->handle);
	}

	return status;
}

/*
@brief update input and output of tasks in group
@param group vip_group object
@param the number of task will be run.
*/
vip_status_e gcvip_update_group_io(
	vip_group group,
	vip_uint32_t num
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;

	for (i = 0; i < num; i++) {
		if (GCVIP_OBJ_NETWORK == group->tasks[i].object.type) {
			vip_network network = (vip_network)group->tasks[i].task;
			if (network->input_dirty != 0) {
				gcOnError(patch_network_inputs(network));
			}

			if (network->output_dirty != 0) {
				gcOnError(patch_network_outputs(network));
			}
		}
	}

onError:
	return status;
}

vip_status_e gcvip_group_item_get_command(
	const gcvip_group_item_t *item,
	gcvip_videomemory_t **cmd_ptr
)
{
	vip_status_e status = VIP_SUCCESS;

	if (!item) {
		gcvip_error("unexpect null task.");
		return VIP_ERROR_FAILURE;
	}

	switch (item->object.type) {
	case GCVIP_OBJ_NETWORK: {
		vip_network network = (vip_network)item->task;
		if (network->segment_num > 1) {
			gcvip_error("failed to get command, network segment num is more than 1, is %d\n",
						network->segment_num);
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}
		/* check original network weight data */
		if ((network->weak_dup) && (VIP_NULL == network->LCD.handle)) {
			gcvip_error("failed the weak network coefficient data is destroy\n");
			gcGoOnError(VIP_ERROR_NOT_SUPPORTED);
		}
		*cmd_ptr = &network->segments[0].states_buffer;
	}
	break;
#if vpmdENABLE_NODE
	case GCVIP_OBJ_NODE: {
		vip_node node = (vip_node)item->task;
		*cmd_ptr = &node->states_buffer;
	}
	break;
#endif
	default:
		gcvip_error("Unknown object type %#x\n", item->object.type);
		status = VIP_ERROR_FAILURE;
		break;
	}

onError:
	return status;
}

vip_status_e gcvip_weak_dup_network(
	vip_network network,
	vip_network copy
)
{
	vip_status_e status = VIP_SUCCESS;
	gcvip_bin_patch_data_entry_t *pd_entry = VIP_NULL;
	gcvip_bin_operation_t *operation = VIP_NULL;
	vip_uint8_t *op_tp = VIP_NULL;
	vip_uint8_t *op_nn = VIP_NULL;
	gcvip_bin_entry_t *lcdt_entry = VIP_NULL;
	vip_uint8_t *states_buffer = VIP_NULL;
	vip_uint32_t *trigger_word = VIP_NULL;
	vip_uint32_t i = 0;
	vip_uint32_t j = 0;
	vip_uint32_t cmd_physical = 0;

	for (i = 0; i < network->segment_num; i++) {
		gcvip_lite_segment_t *segment = &copy->segments[i];

		if (segment != VIP_NULL) {
			states_buffer = (vip_uint8_t *)segment->states_buffer.logical;
		} else {
			gcvip_error("segment or network is NULL");
			gcGoOnError(VIP_ERROR_INVALID_NETWORK);
		}

		if (VIP_NULL == states_buffer) {
			gcvip_error("states buffer is NULL");
			gcGoOnError(VIP_ERROR_INVALID_NETWORK);
		}

		if (segment->is_sw_segm == vip_false_e) {
			for (i = 0; i < network->n_operations; i++) {
				operation = &network->operations[i];

#if vpmdENABLE_LAYER_DUMP
				if (((operation->type != GCVIP_OPERATION_TYPE_INIT) ||
					 (segment->segm_start_id != 0)) &&
					((operation->type != GCVIP_OPERATION_TYPE_END) ||
					 (segment->segm_end_id != network->n_orig_layers)) &&
					((operation->layer_id >= segment->segm_end_id) ||
					 (operation->layer_id < segment->segm_start_id))) {
					continue;
				}
#elif vpmdENABLE_CNN_PROFILING
				if ((operation->type == GCVIP_OPERATION_TYPE_INIT) ||
					(operation->type == GCVIP_OPERATION_TYPE_END) ||
					(i != segment->segm_end_id)) {
					continue;
				}
#else
				if ((i >= segment->segm_end_id) || (i < segment->segm_start_id)) {
					continue;
				}
#endif

				lcdt_entry = &network->LCDT[operation->state_id];

				switch (operation->type) {
				case GCVIP_OPERATION_TYPE_NN: {
					op_nn = (vip_uint8_t *)gcvip_get_nn_op_ptr_by_index(network, network->nn_ops,
							operation->index);
					cmd_physical = copy->nnCmds.physical + (op_nn - network->nnCmds.logical);
					for (j = 0; j < operation->patch_count; j++) {
						pd_entry = (gcvip_bin_patch_data_entry_t *)gcvip_get_patch_ptr_by_index(network,
								   network->pd_entries,
								   operation->patch_index + j
																							   );
						if (pd_entry->type == GCVIP_PATCH_TYPE_STATE) {
							vip_uint8_t *tmp = states_buffer + pd_entry->offset_in_states;
							trigger_word = (vip_uint32_t *)tmp;
							*trigger_word = ((*trigger_word) & 0x3f) | (cmd_physical & ~0x3f);
							break;
						}
					}

					states_buffer += lcdt_entry->size;
				}
				break;

				case GCVIP_OPERATION_TYPE_TP: {
					op_tp = (vip_uint8_t *)&network->tp_ops[operation->index];
					cmd_physical = copy->tpCmds.physical + (op_tp - network->tpCmds.logical);
					for (j = 0; j < operation->patch_count; j++) {
						pd_entry = (gcvip_bin_patch_data_entry_t *)gcvip_get_patch_ptr_by_index(network,
								   network->pd_entries,
								   operation->patch_index + j
																							   );
						if (pd_entry->type == GCVIP_PATCH_TYPE_STATE) {
							vip_uint8_t *tmp = states_buffer + pd_entry->offset_in_states;
							trigger_word = (vip_uint32_t *)tmp;
							*trigger_word = ((*trigger_word) & 0x3f) | (cmd_physical & ~0x3f);
							break;
						}
					}

					states_buffer += lcdt_entry->size;
				}
				break;

				default:
					break;
				}
			}
		} else {
			gcvip_error("failed to dup network, have SW operation in network, not support\n");
			gcGoOnError(VIP_ERROR_FAILURE);
		}
	}

onError:
	return status;
}
#endif
