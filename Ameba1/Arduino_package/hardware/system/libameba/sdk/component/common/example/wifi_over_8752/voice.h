#ifndef BT8752_VOICE_H_
#define BT8752_VOICE_H_


#define APP_PRINT_INFO0  printf
#define APP_PRINT_INFO3  printf
#define APP_PRINT_WARN0 printf
typedef struct VOICE_QUEUE_DEF
{
	uint8_t queue_size ;
	uint8_t out_queue_index;
	uint8_t in_queue_index;
	uint8_t *p_voice_buff;
}T_VOICE_QUEUE_DEF;

typedef struct T_VOICE_GLOBAL_DATA
{
	uint8_t temp_data;
}T_VOICE_GLOBAL_DATA;

void voice_handle_init_data(void);
void voice_handle_init_encode_param(void);
void voice_handle_deinit_encode_param(void);
void voice_handle_init_queue(void);
bool voice_handle_is_queue_full(void);
bool voice_handle_is_queue_empty(void);
uint32_t voice_handle_get_queue_item_cnt(void);
bool voice_handle_in_queue(uint8_t *buffer);
bool voice_handle_out_queue(void);
void voice_handle_encode_raw_data(uint8_t *p_input_data, int32_t input_size,
                                         uint8_t *p_output_data, int32_t *p_output_size);
//void voice_handle_gdma_event(T_IO_MSG io_driver_msg_recv);

#endif