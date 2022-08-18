#ifndef _AMEBAD2_PSRAM_H_
#define _AMEBAD2_PSRAM_H_

#include "ameba_spic.h"

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup PSRAM
* @{
*/

/* AUTO_GEN_START */


/* AUTO_GEN_END */

/* MANUAL_GEN_START */

/* Exported types ------------------------------------------------------------*/
/** @defgroup PSRAM_Exported_Types PSRAM Exported Types
  * @{
  */

/**
  * @brief  PSRAM Init structure definition
  */
typedef struct {
	// 0x0 control reg
	u32 PSRAMC_ddr_en;			/*!< Specifies DDR mode in CMD_CH/DATA_CH/ADDR_CH. */
	u32 PSRAMC_ch;				/*!< Specifies channel number of cmd/data/addr phase in transmitting or receiving data. */
	u32 PSRAMC_ck_mtims;			/*!< Specifies the check times */

	//0x14 clk div
	u32 PSRAMC_clk_div;			/*!< Specifies spi_sclk divider value. spi_sclk = The frequency of bus_clk / (2*SCKDV) */

	//0x118
	u32 PSRAMC_user_rd_dummy_len;			/*!< Specifies rd latency in user mode */
	u32 PSRAMC_user_cmd_len;			/*!< Specifies cmd len in user mode */
	u32 PSRAMC_user_addr_len;			/*!< Specifies addr len in user mode */

	//0x11C delay in auto mode and cmd length
	u32 PSRAMC_auto_rd_latency;		/*!< Specifies delay cycles for receiving data */
	u32 PSRAMC_auto_in_phy_cyc; 		/*!< Specifies the byte size of an address in read/write command in auto_mode. */
	u32 PSRAMC_auto_addr_len; 		/*!< Specifies the byte size of an address in read/write command in auto_mode. */

	//0x120 valid cmd
	u32 PSRAMC_frd_single;		/*!< Specifies whether fast read command is a valid command to execute . */
	u32 PSRAMC_seq_trans_en;	/*!< Specifies whether to enable read sequential transaction read function. */

	//0x138 Timing para
	u32 PSRAMC_rd_dum_len; 		/*!< Specifies the dummy cycles between sending read cmd to spic. to avoid the timing violation of CS high time*/
	u32 PSRAMC_wr_dum_len;		/*!< Specifies the dummy cycles between sending write cmd to spic. to avoid the timing violation of CS high time.*/
	u32 PSRAMC_cs_active_hold;	/*!< Specifies the active hold time after SCLK rising edge, max 4.*/
	u32 PSRAMC_cs_seq_timeout;	/*!< Specifies the timeout setting of auto cmd after aeq read cmd.*/
	u32 PSRAMC_cs_tcem;			/*!< Set to chop auto cmd when CSN low pulse width = (tcem*32)*busclk.*/

	//0x134 device info
	u32 PSRAMC_page_size;		/*!< Specifies the page size of psram, device page size = 2^PSRAMC_page_size*/
	u32 PSRAMC_wr_page_en;		/*!< Specifies whether to chop the burst write cmd across page boundaries in auto mode */
	u32 PSRAMC_rd_page_en;		/*!< Specifies whether to chop the burst read cmd across page boundaries in auto mode*/
	u32 PSRAMC_qspi_psram;		/*!< choose device type: psram */

	//0x110 hw status
	u32 PSRAMC_so_dnum; 			/*!< Specifies single channel(0) connection of multi channels(1) */
	u32 PSRAMC_tx_fifo_entry; 			/*!< <5 when fifo entry = 32 */
	u32 PSRAMC_rx_fifo_entry; 		/*!< Specifies quad data read cmd */
	u32 PSRAMC_full_wr; 		/*!< Specifies whether to enable full write in auto mode, set 0 to use spi_dm to do partial write */

	//0x13c wr latency
	u32 PSRAMC_auto_wr_latency;		/*!< Specifies delay cycles for writing data */

	//0xe0 rd cmd
	u32 PSRAMC_frd_cmd;			/*!< Specifies fast read cmd in auto mode */

	//0xf4 wr cmd
	u32 PSRAMC_wr_cmd;			/*!< Specifies write cmd in auto mode */

} PCTL_InitTypeDef;

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup PSRAM_Exported_Functions PSRAM Exported Functions
  * @{
  */

_LONG_CALL_ void PSRAM_CTRL_StructInit(PCTL_InitTypeDef *PCTL_InitStruct);
_LONG_CALL_ void PSRAM_CTRL_Init(PCTL_InitTypeDef *PCTL_InitStruct);
_LONG_CALL_ void PSRAM_REG_Read(u8 cmd, u32 addr, u32 read_len, u8 *read_data);
_LONG_CALL_ void PSRAM_REG_Write(u8 cmd, u32 addr, u32 write_len, u8 *write_data);
_LONG_CALL_ void PSRAM_MEM_Write(u8 cmd, u32 addr, u32 write_len, u8 *write_data);
_LONG_CALL_ BOOL PSRAM_calibration(VOID);
_LONG_CALL_ void PSRAM_CTRL_WB_StructInit(PCTL_InitTypeDef *PCTL_InitStruct);
_LONG_CALL_ void PSRAM_WB_REG_Write(u32 regnum, u32 write_len, u8 *write_data);
_LONG_CALL_ void PSRAM_WB_REG_Read(u32 regnum, u32 type,  u32 read_len, u8 *read_data);

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup PSRAM_Exported_Constants PSRAM Exported Constants
  * @{
  */

/** @defgroup PSRAM_INIT_LATENCY_definitions
  * @{
  */
#define APM_WR_INIT_LATENCY_3CLK		0
#define APM_WR_INIT_LATENCY_4CLK		0x4
#define APM_WR_INIT_LATENCY_5CLK		0x2
#define APM_WR_INIT_LATENCY_6CLK		0x6
#define APM_WR_INIT_LATENCY_7CLK		0x1
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/* Other definations --------------------------------------------------------*/
extern u8 APM_WR_INIT_LATENCY_SPEC[5];

#define PSRAM_BIT_MR0_FIX_LATENCY       ((u8)0x01 << 5)
#define PSRAM_INIT_RD_LATENCY_CLK		10
#define PSRAM_INIT_WR_LATENCY_CLK		5
#define PSRAM_INIT_WR_LATENCY_APMSPEC

#define PSRAM_WB_INIT_RD_LATENCY_CLK	12
#define PSRAM_WB_INIT_WR_LATENCY_CLK	12


#define PSRAM_WB_IR0		0x0
#define PSRAM_WB_IR1		0x1
#define PSRAM_WB_CR0		0x0
#define PSRAM_WB_CR1		0x1

/* MANUAL_GEN_END */

#endif
