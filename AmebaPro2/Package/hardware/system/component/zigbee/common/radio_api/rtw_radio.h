
#ifndef RTW_RADIO_H__
#define RTW_RADIO_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <osdep_service.h>

#define RTW_802154_RADIO_MP_INCLUDE 1
#define RTW_802154_RADIO_TX_TASK 1
#define RTW_802154_RADIO_TRX_DIS_SEMA 1
#define MEASURE_RX_HANDLER_TIME 0
#define RX_ACK_TIME_DEBUG 0
/** @brief RADIO Clear Channel Assessment modes. */
typedef enum {
	RTW_RADIO_CCA_MODE_ED             = 0,           /**< Energy Above Threshold. Will report busy whenever energy is detected above set threshold. */
	RTW_RADIO_CCA_MODE_CARRIER,      /**< Carrier Seen. Will report busy whenever compliant IEEE 802.15.4 signal is seen. */
	RTW_RADIO_CCA_MODE_CARRIER_AND_ED, /**< Energy Above Threshold AND Carrier Seen. */
	RTW_RADIO_CCA_MODE_CARRIER_OR_ED,  /**< Energy Above Threshold OR Carrier Seen. */
	RTW_RADIO_CCA_MODE_ED_TEST1,      /**< Energy Above Threshold test mode that will abort when first ED measurement over threshold is seen. No averaging. */
} rtw_radio_cca_mode_t;

/** @brief Types of RADIO states. */
typedef enum {
	RTW_RADIO_STATE_DISABLED  = 0,  /**< No operations are going on inside the radio and the power consumption is at a minimum. */
	RTW_RADIO_STATE_ED,      /**< The radio is ed state. */
	RTW_RADIO_STATE_RXRU,      /**< The radio is ramping up and preparing for reception. */
	RTW_RADIO_STATE_RXIDLE,    /**< The radio is ready for reception to start. */
	RTW_RADIO_STATE_RX,        /**< Reception has been started. */
	RTW_RADIO_STATE_RXDISABLE, /**< The radio is disabling the receiver. */
	RTW_RADIO_STATE_TXRU,      /**< The radio is ramping up and preparing for transmission. */
	RTW_RADIO_STATE_TXIDLE,    /**< The radio is ready for transmission to start. */
	RTW_RADIO_STATE_TX,        /**< The radio is transmitting a packet. */
	RTW_RADIO_STATE_TXDISABLE, /**< The radio is disabling the transmitter. */
} rtw_radio_trx_state_t;

typedef enum {
	RTW_RADIO_RX_TASK_FRAME = 0,
	RTW_RADIO_RX_TASK_ED,
} rtw_radio_rx_task_mode_t;

/** @brief Types of RADIO TX power. */
typedef enum {
#if defined(RADIO_TXPOWER_TXPOWER_Pos8dBm) || defined(__NRFX_DOXYGEN__)
	RTW_RADIO_TXPOWER_POS8DBM  = 0,  /**< 8 dBm. */
#endif
#if defined(RADIO_TXPOWER_TXPOWER_Pos7dBm) || defined(__NRFX_DOXYGEN__)
	RTW_RADIO_TXPOWER_POS7DBM,  /**< 7 dBm. */
#endif
#if defined(RADIO_TXPOWER_TXPOWER_Pos6dBm) || defined(__NRFX_DOXYGEN__)
	RTW_RADIO_TXPOWER_POS6DBM,  /**< 6 dBm. */
#endif
#if defined(RADIO_TXPOWER_TXPOWER_Pos5dBm) || defined(__NRFX_DOXYGEN__)
	RTW_RADIO_TXPOWER_POS5DBM,  /**< 5 dBm. */
#endif
	RTW_RADIO_TXPOWER_POS4DBM,  /**< 4 dBm. */
#if defined(RADIO_TXPOWER_TXPOWER_Pos3dBm) || defined(__NRFX_DOXYGEN__)
	RTW_RADIO_TXPOWER_POS3DBM,  /**< 3 dBm. */
#endif
#if defined(RADIO_TXPOWER_TXPOWER_Pos2dBm) || defined(__NRFX_DOXYGEN__)
	RTW_RADIO_TXPOWER_POS2DBM,  /**< 2 dBm. */
#endif
	RTW_RADIO_TXPOWER_0DBM,     /**< 0 dBm. */
	RTW_RADIO_TXPOWER_NEG4DBM,  /**< -4 dBm. */
	RTW_RADIO_TXPOWER_NEG8DBM,  /**< -8 dBm. */
	RTW_RADIO_TXPOWER_NEG12DBM, /**< -12 dBm. */
	RTW_RADIO_TXPOWER_NEG16DBM, /**< -16 dBm. */
	RTW_RADIO_TXPOWER_NEG20DBM, /**< -20 dBm. */
	RTW_RADIO_TXPOWER_NEG30DBM, /**< -30 dBm. */
#if defined(RADIO_TXPOWER_TXPOWER_Neg40dBm) || defined(__NRFX_DOXYGEN__)
	RTW_RADIO_TXPOWER_NEG40DBM, /**< -40 dBm. */
#endif
} rtw_radio_txpower_t;

#if RTW_802154_RADIO_MP_INCLUDE
typedef enum {
	RTW_RADIO_INIT_STATE_MP_OFF = 0,
	RTW_RADIO_INIT_STATE_MP_IDLE,
	RTW_RADIO_INIT_STATE_MP_TX,
	RTW_RADIO_INIT_STATE_MP_RX,
} rtw_radio_init_state_t;

typedef struct rtw_radio_mp_tx {
	uint32_t pkt_cnt;//total tx pkt cnt, continus if 0
	uint32_t pkt_num;//the num of pkt has been transmitted
	uint32_t pkt_len;
	uint32_t psdu_type;
	uint32_t pkt_intv;
	uint8_t *payload;
#if (RTW_802154_RADIO_TX_TASK == 0)
	struct task_struct tx_task;
#endif
} rtw_radio_mp_tx_t;
#endif
#if RTW_802154_RADIO_TX_TASK
typedef enum {
	RTW_RADIO_TX_FRAME = 0,
	RTW_RADIO_TX_ACK,
	RTW_RADIO_TX_MP,
	RTW_RADIO_TX_DIS,
	RTW_RADIO_TX_DEINIT,
} rtw_radio_tx_frame_type_t;
typedef struct rtw_radio_tx_message {
	rtw_radio_tx_frame_type_t tx_frame_type;
	uint8_t *tx_ptr;
} rtw_radio_tx_message_t;
#endif
typedef struct rtw_radio_adapter {
	rtw_radio_trx_state_t m_radio_state;///< State of the radio.
	volatile struct task_struct radio_rx_task;
	uint8_t *rx_ptr;
#if RTW_802154_RADIO_TRX_DIS_SEMA
	_sema radio_rx_dis_sema;
#endif
	uint8_t radio_rx_task_mode;
	void *radio_rx_task_lock; //to avoid rx task can't exit
#if RTW_802154_RADIO_TX_TASK
	volatile struct task_struct radio_tx_task;
	_xqueue radio_tx_queue;
	//uint8_t *tx_ptr;
#if RTW_802154_RADIO_TRX_DIS_SEMA
	_sema radio_tx_dis_sema;
#endif
#endif
	void *radio_tx_task_lock;
	uint32_t radio_ed_start_time;
	uint32_t radio_ed_duration;
#if RTW_802154_RADIO_MP_INCLUDE
	uint8_t radio_mp_state;
	rtw_radio_mp_tx_t radio_mp_tx;
#endif
}
rtw_radio_adapter_t;
extern rtw_radio_adapter_t rtw_radio_obj;

rtw_radio_trx_state_t rtw_radio_state_get(void);
void rtw_radio_rx_packetptr_set(uint8_t *p_ptr);
bool rtw_radio_psdu_is_being_received(void);
bool rtw_radio_tx_started(void);
void rtw_radio_on(void);
void rtw_radio_off(void);
void rtw_radio_power_reset(void);
void rtw_radio_rx_enable(void);
void rtw_radio_rx_disable(void);
void rtw_radio_irq_init();
void rtw_radio_irq_deinit();
void rtw_radio_tx_frame(uint8_t *p_frame);
bool rtw_radio_tx_cca_check(void);
void rtw_radio_rx_restart(void);
void rtw_radio_channel_set(uint8_t channel);
void rtw_radio_rssi_measure_start(void);
void rtw_radio_rssi_measure_stop(void);
bool rtw_radio_rssi_measure_wait_end(void);
int8_t rtw_radio_rssi_sample_get(void);
void rtw_radio_cca_configure(void);
void rtw_radio_txpower_set(rtw_radio_txpower_t tx_power);
void rtw_radio_cca_start(void);
void rtw_radio_cca_stop(void);
void rtw_radio_continuous_carrier_start(void);
void rtw_radio_continuous_carrier_stop(void);
void rtw_radio_ed_set(uint32_t time_us);
void rtw_radio_ed_start(void);
void rtw_radio_ed_stop(void);
uint32_t rtw_radio_ed_sample_get(void);
void rtw_radio_crc_configure(void);
void rtw_radio_mode_set(void);
void rtw_radio_temperature_get(void);
bool rtw_radio_crc_status_check(uint8_t              *p_data);
void rtw_radio_rx_task_init(void);
void rtw_radio_rx_task_deinit(void);
void rtw_radio_reg_dump();

void rtw_radio_mp_on();
void rtw_radio_mp_off();
void rtw_radio_mp_trx_status_reset();
void rtw_radio_mp_tx_pkt_create();
void rtw_radio_mp_tx_task(void);
void rtw_radio_mp_continue_tx_start(uint32_t pkt_cnt, uint32_t pkt_len, uint32_t psdu_type, uint32_t pkt_intv);
void rtw_radio_mp_continue_tx_stop(void);
void rtw_radio_mp_continue_rx_start(void);
void rtw_radio_mp_continue_rx_stop(void);
#endif //RTW_RADIO_H__