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

#include <gc_vip_lite_network.h>
#include <gc_vip_lite_debug.h>
#include <gc_vip_lite.h>
#include <gc_vip_user.h>
#include <gc_vip_user_port.h>
#include <gc_vip_hardware.h>

#if vpmdENABLE_LAYER_DUMP
static void dump_raw_file(
	void *data,
	vip_uint32_t size,
	char *file_name
)
{
	gcvip_file_t *fp = VIP_NULL;
	fp = gcvip_os_open_file(file_name, FILE_CREATE);
	if (fp != VIP_NULL) {
		gcvip_os_write_file(data, size, fp);
		gcvip_os_close_file(fp);
	} else {
		gcvip_info("Failed writing to file %s.\n", file_name);
	}
}

vip_status_e gcvip_layer_dump(
	gcvip_lite_segment_t *segment,
	vip_network_t *network,
	vip_uint32_t id
)
{
	vip_status_e status = VIP_SUCCESS;
	char filename[128] = {0};
	vip_uint32_t i = 0, j = 1;
	vip_uint32_t size = 0;
	vip_char_t *name = VIP_NULL;

	if (id != network->n_orig_layers - 1) {
		while (j < segment->out_count) {
			if (segment->out_buffers[i] != segment->out_buffers[j]) {
				++i;
				segment->out_buffers[i] = segment->out_buffers[j];
				segment->out_sizes[i] = segment->out_sizes[j];
				++j;
			} else {
				++j;
			}
		}
		for (j = 0; j <= i; ++j) {
			name = gcvip_get_layer_name(network, id);
			gcvip_os_print("nn layer dump layer_id=%d %s\n", id, name);
			GCVIP_GET_STRING(filename, 128, "Layer_%d_%s_%d_%d_uid_%d.bin",
							 id, name, j, segment->out_sizes[j], segment->uid);
			if (segment->out_count != 0) {
				dump_raw_file(segment->out_buffers[j], segment->out_sizes[j], filename);
			}
			gcvip_user_zero_memory(filename, sizeof(filename));
		}
	} else if (id == network->n_orig_layers - 1) {
		for (i = 0; i < network->n_outputs; i++) {
			name = gcvip_get_layer_name(network, id);
			gcvip_os_print("nn layer dump layer_id=%d %s\n", id, name);
			size = gcvip_get_io_buffer_size(&network->outputs[i]);
			GCVIP_GET_STRING(filename, 128, "Layer_%d_%s_networkoutput_%d.bin", id, name, i);
			dump_raw_file(network->network_outputs[i].logical, size, filename);
		}
	}

	return status;
}
#endif

#if vpmdENABLE_HANG_DUMP || vpmdDUMP_COMMANDS_EVERY_RUN || vpmdENABLE_CAPTURE
void gcvip_dump_duffer(
	gcvip_file_t fp,
	void *buffers,
	vip_uint32_t physical,
	vip_uint32_t size,
	gcvip_dump_buf_type_e type)
{
	vip_char_t info[256];
	static const vip_char_t *tags[] = {
		"command",
		"states",
		"pool",
		"input",
		"verify",
		"memory"
	};

	vip_uint32_t *buffer = (vip_uint32_t *)buffers;
	GCVIP_GET_STRING(info, 255, "@[%s 0x%08X 0x%08X\n", tags[type], physical, size);
	GCVIP_DUMP_STRING(fp, info);

	while (size >= 16) {
		GCVIP_GET_STRING(info, 255, "  0x%08X 0x%08X 0x%08X 0x%08X\n",
						 buffer[0], buffer[1], buffer[2], buffer[3]);
		GCVIP_DUMP_STRING(fp, info);
		size -= 16;
		buffer += 4;
	}

	/* The remaining data. */
	switch (size) {
	case 12:
		GCVIP_GET_STRING(info, 255, "  0x%08X 0x%08X 0x%08X\n",
						 buffer[0], buffer[1], buffer[2]);
		GCVIP_DUMP_STRING(fp, info);
		break;

	case 8:
		GCVIP_GET_STRING(info, 255, "  0x%08X 0x%08X\n", buffer[0], buffer[1]);
		GCVIP_DUMP_STRING(fp, info);
		break;

	case 4:
		GCVIP_GET_STRING(info, 255, "  0x%08X\n", buffer[0]);
		GCVIP_DUMP_STRING(fp, info);
		break;

	default:
		break;
	}

	GCVIP_DUMP_STRING(fp, "]\n");
}
#endif

#if vpmdENABLE_HANG_DUMP || vpmdDUMP_COMMANDS_EVERY_RUN
#define PRINT   gcvip_os_print
void gcvip_dump_command(
	gcvip_file_t fp,
	vip_network network,
	gcvip_lite_segment_t *segment
)
{
	gcvip_bin_operation_t *operation = VIP_NULL;
	vip_uint32_t i = 0;
	vip_char_t buffer[256];
	vip_uint8_t *commands_logical = VIP_NULL;
	vip_uint32_t commands_physical = 0;
	vip_uint32_t comamnds_size = 0;

	for (i = 0; i < network->n_operations; i++) {
		operation = &network->operations[i];
		if (GCVIP_OPERATION_TYPE_SH == operation->type) {
			gcvip_bin_sh_operation_t *op_sh = VIP_NULL;
			op_sh = (gcvip_bin_sh_operation_t *)gcvip_get_sh_op_ptr_by_index(network, network->sh_ops,
					operation->index);
			commands_logical = (vip_uint8_t *)network->LCD.logical + network->LCDT[op_sh->lcdt_index].offset;
			commands_physical = network->LCD.physical + network->LCDT[op_sh->lcdt_index].offset;
			comamnds_size = GCVIP_ALIGN(network->LCDT[op_sh->lcdt_index].size, 256);

			GCVIP_GET_STRING(buffer, 256, "#[sh command, layer:%d, op_id:%d, uid:%d, name:%s]\n",
							 operation->layer_id, i,
							 gcvip_get_layer_uid(network, operation->layer_id),
							 gcvip_get_layer_name(network, operation->layer_id));
			GCVIP_DUMP_STRING(fp, buffer);

			gcvip_dump_duffer(fp, commands_logical, commands_physical, comamnds_size, GCVIP_DUMP_MEMORY);
		} else if (GCVIP_OPERATION_TYPE_NN == operation->type) {
			void *nn_cmd = VIP_NULL;
			nn_cmd = gcvip_get_nn_op_ptr_by_index(network, network->nn_ops, operation->index);
			commands_logical = (vip_uint8_t *)nn_cmd;
			commands_physical = network->nnCmds.physical + (commands_logical - (vip_uint8_t *)network->nnCmds.logical);
			comamnds_size = gcvip_get_nn_command_size(network);

			GCVIP_GET_STRING(buffer, 256, "#[nn command, layer:%d, op_id:%d, uid:%d, name:%s]\n",
							 operation->layer_id, i,
							 gcvip_get_layer_uid(network, operation->layer_id),
							 gcvip_get_layer_name(network, operation->layer_id));
			GCVIP_DUMP_STRING(fp, buffer);

			gcvip_dump_duffer(fp, commands_logical, commands_physical, comamnds_size, GCVIP_DUMP_MEMORY);
		} else if (GCVIP_OPERATION_TYPE_TP == operation->type) {
			gcvip_bin_tp_operation_t *tp_cmd = VIP_NULL;
			tp_cmd = &network->tp_ops[operation->index];
			commands_logical = (vip_uint8_t *)tp_cmd;
			commands_physical = network->tpCmds.physical + (commands_logical - (vip_uint8_t *)network->tpCmds.logical);
			comamnds_size = TP_CMD_SIZE;

			GCVIP_GET_STRING(buffer, 256, "#[tp command, layer:%d, op_id:%d, uid:%d, name:%s]\n",
							 operation->layer_id, i,
							 gcvip_get_layer_uid(network, operation->layer_id),
							 gcvip_get_layer_name(network, operation->layer_id));
			GCVIP_DUMP_STRING(fp, buffer);

			gcvip_dump_duffer(fp, commands_logical, commands_physical, comamnds_size, GCVIP_DUMP_MEMORY);
		}
	}
}

static void gcvip_dump_states(
	gcvip_file_t fp,
	gcvip_lite_segment_t *segment
)
{
	vip_uint32_t size = segment->states_buffer.size + APPEND_COMMAND_SIZE;
	vip_char_t buffer[256];

	if ((segment->states_buffer.size) && (segment->states_buffer.logical != VIP_NULL)) {
		GCVIP_GET_STRING(buffer, 256, "#[states]\n");

		GCVIP_DUMP_STRING(fp, buffer);

		gcvip_dump_duffer(fp, segment->states_buffer.logical, segment->states_buffer.physical,
						  size, GCVIP_DUMP_COMMAND);
	}
}

void gcvip_dump_states_command(
	vip_network_t *network,
	gcvip_lite_segment_t *segment,
	vip_uint32_t flag
)
{
	vip_char_t file_name[256];
	gcvip_file_t fp = VIP_NULL;
	static vip_uint32_t count = 0;
	vip_uint32_t pid = gcvip_os_get_pid();
	vip_uint32_t tid = gcvip_os_get_tid();

	if (HANG_DUMP == flag) {
		gcvip_os_snprint(file_name, 255, "viplite_hang_dump_%d_%d.log", pid, tid);
		gcvip_error("hang dump command...name=%s\n", file_name);
	} else {
		count++;
		gcvip_info("dump command each run %d\n", count);
		gcvip_os_snprint(file_name, 255, "viplite_dump_run_%d_%d_%d.log", pid, tid, count);
	}

	fp = gcvip_os_open_file(file_name, FILE_CREATETEXT);

	gcvip_dump_command(fp, network, segment);

	gcvip_dump_states(fp, segment);

	if (fp != VIP_NULL) {
		gcvip_os_close_file(fp);
	}
}
#endif

#if vpmdENABLE_CAPTURE
static void capture_dump_buffer(
	gcvip_file_t fp,
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_char_t buffer[256];
	static const vip_char_t *command_tags[] = {
		"nn",
		"tp",
		"sh",
		"states",
	};

	gcvip_info("dump %s command\n", command_tags[segment->cmd_dump->cmd_type]);
	GCVIP_GET_STRING(buffer, 255, "#[%s command, layer:%d, uid: %d]\n",
					 command_tags[segment->cmd_dump->cmd_type],
					 segment->cmd_dump->layer_id, segment->cmd_dump->uid);
	GCVIP_DUMP_STRING(fp, buffer);
	if (segment->cmd_dump->cmd_type == NN_COMMAND) {
		gcvip_dump_duffer(fp, network->nnCmds.logical + segment->cmd_dump->offset,
						  network->nnCmds.physical + segment->cmd_dump->offset,
						  segment->cmd_dump->size, GCVIP_DUMP_MEMORY);
	}

	if (segment->cmd_dump->cmd_type == TP_COMMAND) {
		gcvip_dump_duffer(fp, network->tpCmds.logical + segment->cmd_dump->offset,
						  network->tpCmds.physical + segment->cmd_dump->offset,
						  segment->cmd_dump->size, GCVIP_DUMP_MEMORY);
	}

	if (segment->cmd_dump->cmd_type == SH_COMMAND) {
		if ((network->fixed.header.version < 0x00010005) || network->realloc_sh_buff) {
			gcvip_dump_duffer(fp, segment->sh_cmd_buffer.logical + segment->cmd_dump->offset,
							  segment->sh_cmd_buffer.physical + segment->cmd_dump->offset,
							  segment->cmd_dump->size, GCVIP_DUMP_MEMORY);
		} else {
			gcvip_dump_duffer(fp, network->LCD.logical + segment->cmd_dump->offset,
							  network->LCD.physical + segment->cmd_dump->offset,
							  segment->cmd_dump->size, GCVIP_DUMP_MEMORY);
		}
	}

	if (segment->cmd_dump->cmd_type == STATES) {
		gcvip_dump_duffer(fp, segment->states_buffer.logical + segment->cmd_dump->offset,
						  segment->states_buffer.physical + segment->cmd_dump->offset,
						  segment->cmd_dump->size, GCVIP_DUMP_COMMAND);
	}
}

void gcvip_capture_dump_list(
	gcvip_lite_context_t *context,
	vip_network_t *network
)
{
	vip_uint32_t i = 0;

	if (network->capture_done == 0) {
		for (i = 0; i < network->segment_num; i++) {
			gcvip_lite_segment_t *segment = &network->segments[i];
			if (segment->is_sw_segm == vip_false_e) {
				segment->lp1 = segment->cmd_dump;
				segment->lp2 = segment->cmd_dump;

				while (VIP_NULL != segment->cmd_dump->next) {
					capture_dump_buffer(context->capture_file, network, segment);
					segment->lp1 = segment->cmd_dump->next;
					segment->cmd_dump = segment->lp1;
					gcvip_os_free_memory(segment->lp2);
					segment->lp2 = segment->cmd_dump;
				}

				if (segment->cmd_dump->next == VIP_NULL) {
					capture_dump_buffer(context->capture_file, network, segment);
					gcvip_os_free_memory(segment->cmd_dump);
					segment->lp1 = VIP_NULL;
					segment->lp2 = VIP_NULL;
					segment->cmd_dump = VIP_NULL;
				}
			}
		}
	}

#if (vpmdENABLE_CAPTURE == 1)
	network->capture_done = 1;
#endif
}

void gcvip_capture_add_list(
	gcvip_lite_segment_t *segment,
	vip_uint32_t offset,
	vip_uint32_t size,
	vip_uint32_t layer_id,
	vip_uint32_t uid,
	vip_uint32_t type
)
{
	gcvip_command_dump_t *ptr = VIP_NULL;
	gcvip_os_allocate_memory(sizeof(gcvip_command_dump_t), (void **)&ptr);
	gcvip_user_zero_memory(ptr, sizeof(gcvip_command_dump_t));
	segment->lp1 = ptr;
	segment->lp1->offset = offset;
	segment->lp1->size = size;
	segment->lp1->cmd_type = type;
	segment->lp1->layer_id = layer_id;
	segment->lp1->uid = uid;

	if (segment->cmd_dump == VIP_NULL) {
		segment->cmd_dump = ptr;
		segment->lp2 = segment->cmd_dump;
		segment->cmd_dump->next = VIP_NULL;

	} else {
		segment->lp2->next = segment->lp1;
		segment->lp2 = segment->lp1;
		segment->lp2->next = VIP_NULL;
	}
}

vip_status_e gcvip_capture_dump_states(
	gcvip_lite_context_t *context,
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	if (segment->states_buffer.size > 0) {
		GCVIP_DUMP_STRING(context->capture_file, "#[states]\n");
		gcvip_dump_duffer(context->capture_file, segment->states_buffer.logical,
						  segment->states_buffer.physical,
						  segment->states_buffer.size, GCVIP_DUMP_COMMAND);
		GCVIP_DUMP_STRING(context->capture_file, "@[commit]\n");
		GCVIP_DUMP_STRING(context->capture_file, "@[stall]\n");
	}

	return VIP_SUCCESS;
}

vip_status_e gcvip_capture_hardware_info(
	gcvip_lite_context_t *context
)
{
	vip_uint32_t chip_rev1 = 0;
	vip_uint32_t chip_rev2 = 0;
	vip_uint32_t chip_date = 0;
	vip_uint32_t chip_cid = 0;
	vip_char_t buffer[256];

	gcvip_user_read_reg(0x00020, &chip_rev1);

	gcvip_user_read_reg(0x00024, &chip_rev2);

	gcvip_user_read_reg(0x00028, &chip_date);

	gcvip_user_read_reg(0x00030, &chip_cid);

	GCVIP_GET_STRING(buffer, 256, "#[chip rev1] 0x%08X\n", chip_rev1);
	GCVIP_DUMP_STRING(context->capture_file, buffer);

	GCVIP_GET_STRING(buffer, 256, "#[chip rev2] 0x%08X\n", chip_rev2);
	GCVIP_DUMP_STRING(context->capture_file, buffer);

	GCVIP_GET_STRING(buffer, 256, "#[chip date] 0x%08X\n", chip_date);
	GCVIP_DUMP_STRING(context->capture_file, buffer);

	GCVIP_GET_STRING(buffer, 256, "#[chip cid] 0x%08X\n\n", chip_cid);
	GCVIP_DUMP_STRING(context->capture_file, buffer);

	return VIP_SUCCESS;
}

vip_status_e gcvip_capture_init_command(
	gcvip_lite_context_t *context,
	vip_network_t *network
)
{
#define STRING_SIZE  256
	vip_uint32_t i = 0, j = 0;
	vip_char_t info[STRING_SIZE];
	gcvip_bin_patch_data_entry_t *pd_entry = VIP_NULL;
	gcvip_bin_entry_t *icdt = VIP_NULL;
	gcvip_bin_entry_t *icdt_entry = VIP_NULL;
	gcvip_dump_buf_type_e type = GCVIP_DUMP_MEMORY;

	for (j = 0; j < network->n_hw_init_ops; j++) {
		gcvip_bin_hw_init_operation_info_entry_t *op = &network->init_ops[i];
		icdt_entry = &network->ICDT[op->state_id];

		for (i = 0; i < op->patch_count; i++) {
			pd_entry = &network->pd_entries[op->patch_index + i];
			icdt = &network->ICDT[pd_entry->index];

			switch (pd_entry->source_type) {
			case GCVIP_SOURCE_COMMAND:
				GCVIP_GET_STRING(info, STRING_SIZE, "#[initial_%d command]\n", j);
				type = GCVIP_DUMP_MEMORY;
				break;
			case GCVIP_SOURCE_MISC_DYNA_INPUT:
				GCVIP_GET_STRING(info, STRING_SIZE, "#[initial_%d input]\n", j);
				type = GCVIP_DUMP_MEMORY;
				break;
			case GCVIP_SOURCE_MISC_DYNA_OUTPUT:
				GCVIP_GET_STRING(info, STRING_SIZE, "#[initial_%d output]\n", j);
				type = GCVIP_DUMP_VERIFY;
				break;
			default:
				break;
			}

			GCVIP_DUMP_STRING(context->capture_file, info);
			gcvip_dump_duffer(context->capture_file,
							  context->ICD.logical + icdt->offset,
							  context->ICD.physical + icdt->offset,
							  icdt->size,
							  type);
		}

		GCVIP_GET_STRING(info, STRING_SIZE, "#[initial_%d states]\n", j);
		GCVIP_DUMP_STRING(context->capture_file, info);
		gcvip_dump_duffer(context->capture_file,
						  context->ICD.logical + icdt_entry->offset,
						  context->ICD.physical + icdt_entry->offset,
						  icdt_entry->size,
						  GCVIP_DUMP_COMMAND);
		GCVIP_DUMP_STRING(context->capture_file, "@[commit]\n");
		GCVIP_DUMP_STRING(context->capture_file, "@[stall]\n");
	}

	return VIP_SUCCESS;
}

vip_status_e gcvip_capture_init(
	gcvip_lite_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_char_t file_name[256];
	vip_uint32_t pid = gcvip_os_get_pid();
	vip_uint32_t tid = gcvip_os_get_tid();

	gcvip_os_snprint(file_name, 255, "viplite_hal_capture_%d_%d.log", pid, tid);
	context->capture_file = gcvip_os_open_file(file_name, FILE_APPENDTEXT);
	if (context->capture_file == VIP_NULL) {
		gcvip_os_print("failed to open %s file for capture\n", file_name);
		return VIP_ERROR_IO;
	}

	return status;
}

vip_status_e gcvip_capture_uninit(
	gcvip_lite_context_t *context
)
{
	vip_status_e status = VIP_SUCCESS;

	if (context->capture_file != VIP_NULL) {
		gcvip_os_close_file(context->capture_file);
		context->capture_file = VIP_NULL;
	}

	return status;
}
#endif

#if vpmdENABLE_BW_PROFILING
vip_status_e gcvip_bw_profiling(
	vip_network_t *network
)
{
	gcvip_bin_feature_database_t *feature_db = &network->fixed.header.feature_db;
	vip_uint32_t i = 0;
	vip_uint32_t chip_info = 0;
	vip_uint32_t control = 0;
	/*8bytes, total reads in terms of 64bits*/
	vip_uint32_t total_reads_8B = 0;
	vip_uint32_t total_writes_8B = 0;
	vip_uint32_t total_reads_ocb_16B = 0;
	vip_uint32_t total_writes_ocb_16B = 0;
	vip_uint32_t total_cycle = 0;
	vip_uint32_t total_idle_cycle = 0;
	vip_float64_t read_bw = 0.0;
	vip_float64_t write_bw = 0.0;
	vip_float64_t ocb_read_bw = 0.0;
	vip_float64_t ocb_write_bw = 0.0;
	vip_float64_t ddr_read_bw = 0.0;
	vip_float64_t ddr_write_bw = 0.0;

	if (0 == feature_db->num_pixel_pipes) {
		gcvip_error("This NBG doesn't support bandwidth profiling\n");
		return VIP_ERROR_NETWORK_NOT_PREPARED;
	}

	/* read cycles */
	gcvip_user_read_reg(0x00078, &total_cycle);
	gcvip_user_read_reg(0x0007C, &total_idle_cycle);

	/* read chip info */
	gcvip_user_read_reg(0x000A4, &chip_info);

	/* read clock control register. */
	gcvip_user_read_reg(0x00000, &control);

	for (i = 0; i < feature_db->num_pixel_pipes; i++) {
		vip_uint32_t read = 0, write = 0, data = 0;

		/* select pipe */
		data = control;
		data &= ~(0xF << 20);
		data |= (i << 20);
		gcvip_user_write_reg(0x00000, data);

		gcvip_user_read_reg(0x00040, &read);
		gcvip_user_read_reg(0x00044, &write);

		total_reads_8B += read;
		total_writes_8B += write;

		if (feature_db->ocb_counter) {
			read = 0;
			write = 0;
			gcvip_user_read_reg(0x005C0, &read);
			gcvip_user_read_reg(0x005D0, &write);

			total_reads_ocb_16B += read;
			total_writes_ocb_16B += write;
		}
	}

	if ((chip_info & (1 << 21)) == (1 << 21)) {
		total_reads_8B *= 2;
		total_writes_8B *= 2;
	}

	read_bw = total_reads_8B * 8 * 0.00000095367;
	write_bw = total_writes_8B * 8 * 0.00000095367;

	ocb_read_bw = total_reads_ocb_16B * 16 * 0.00000095367;
	ocb_write_bw = total_writes_ocb_16B * 16 * 0.00000095367;

	ddr_read_bw = read_bw - ocb_read_bw;
	ddr_write_bw = write_bw - ocb_write_bw;

	gcvip_os_print("Total read bandwidth (MByte): %f\n", read_bw);
	gcvip_os_print("Total write bandwidth (MByte): %f\n", write_bw);

	gcvip_os_print("AXI read bandwidth (MByte): %f\n", ocb_read_bw);
	gcvip_os_print("AXI write bandwidth (MByte): %f\n", ocb_write_bw);

	gcvip_os_print("DDR read bandwidth (MByte): %f\n", ddr_read_bw);
	gcvip_os_print("DDR write bandwidth (MByte): %f\n", ddr_write_bw);

	gcvip_os_print("VIP total cycles: %u\n", total_cycle);
	gcvip_os_print("VIP total idle cycles: %u\n", total_idle_cycle);

	gcvip_user_write_reg(0x00000, control);

	gcvip_user_write_reg(0x00438, 0);
	gcvip_user_write_reg(0x00078, 0);
	gcvip_user_write_reg(0x0007C, 0);
	gcvip_user_write_reg(0x00040, 0);
	gcvip_user_write_reg(0x00044, 0);
	gcvip_user_write_reg(0x005C0, 0);
	gcvip_user_write_reg(0x005D0, 0);

	gcvip_user_write_reg(0x0003C, 1);
	gcvip_user_write_reg(0x0003C, 0);

	return VIP_SUCCESS;
}
#endif

#if vpmdENABLE_CNN_PROFILING
vip_uint32_t gcvip_get_num_initend_operation(
	vip_network_t *network
)
{
	vip_uint32_t num = 0;
	vip_uint32_t i = 0;

	for (i = 0; i < network->n_operations; i++) {
		gcvip_bin_operation_t *operation = &network->operations[i];
		if ((operation->type == GCVIP_OPERATION_TYPE_INIT) ||
			(operation->type == GCVIP_OPERATION_TYPE_END)) {
			num++;
		}
	}

	return num;
}

static vip_status_e gcvip_layer_info(
	vip_network_t *network,
	vip_char_t *name,
	vip_uint32_t layer_id,
	vip_uint32_t op_id,
	vip_uint32_t uid
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint32_t i = 0;
	gcvip_bin_operation_t *operation = VIP_NULL;
	vip_char_t operaton_target[5];

	for (i = 0; i < network->n_operations; i++) {
		operation = &network->operations[i];

		if (i == op_id) {
			switch (operation->type) {
			case GCVIP_OPERATION_TYPE_NN: {
				GCVIP_GET_STRING(operaton_target, 5, "NN");
			}
			break;

			case GCVIP_OPERATION_TYPE_TP: {
				GCVIP_GET_STRING(operaton_target, 5, "TP");
			}
			break;

			case GCVIP_OPERATION_TYPE_SH: {
				GCVIP_GET_STRING(operaton_target, 5, "SH");
			}
			break;

			case GCVIP_OPERATION_TYPE_SW: {
				GCVIP_GET_STRING(operaton_target, 5, "SW");
			}
			break;

			default:
				break;
			}
		}
	}

	gcvip_os_print("layer id: %d, uid: %d, layer name: %s, operation target: %s\n",
				   layer_id + 1, uid, name, operaton_target);

	return status;
}

vip_status_e gcvip_layer_profile(
	vip_network_t *network,
	gcvip_lite_segment_t *segment
)
{
	vip_status_e status = VIP_SUCCESS;
	vip_uint64_t diff_time = 0;

	gcvip_layer_info(network,
					 segment->name,
					 segment->segm_start_id, /* layer id */
					 segment->segm_end_id,   /* op index */
					 segment->uid
					);

	if (vip_false_e == segment->is_sw_segm) {
		status = gcvip_user_wait(segment->states_buffer.handle);
	}

	segment->end_time = gcvip_os_get_time();

	if (segment->end_time > segment->start_time) {
		diff_time = segment->end_time - segment->start_time;
	} else {
		gcvip_error("failed to get layer time, start %ld, end %ld\n",
					segment->start_time, segment->end_time);
	}

	network->total_time += diff_time;

	gcOnError(status);

	gcvip_os_print("execution time: %d us\n", diff_time);

#if vpmdENABLE_BW_PROFILING
	gcvip_bw_profiling(network);
#endif

	gcvip_os_print("\n");

onError:
	return status;
}
#endif
