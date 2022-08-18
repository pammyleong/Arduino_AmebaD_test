#ifndef _AMEBAD2_ZGB_H_
#define _AMEBAD2_ZGB_H_

/* AUTO_GEN_START */

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup ZGB
* @{
*/

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup ZGB_Register_Definitions ZGB Register Definitions
 * @{
 *****************************************************************************/

/** @defgroup ZGB_FUN_EN
 * @brief Zigbee Function enable
 * @{
 **/
#define ZGB_BIT_R_ZGB_RX_EN         ((u32)0x00000001 << 1)          /*!<R/W 0  zigbee mac rx enable */
#define ZGB_BIT_R_ZGB_TX_EN         ((u32)0x00000001 << 0)          /*!<R/W 0  zigbee mac tx enable */
/** @} */

/** @defgroup ZGB_TXBUF_CTRL
 * @brief Zigbee Tx buffer control
 * @{
 **/
#define ZGB_MASK_R_TXBUF_EMPTY_TH   ((u32)0x000007FF << 12)          /*!<R/W 140h  when zigbee txbuf empty entry is large than the r_txbuf_empty_th, interrupt is issued to CPU half size of tx buffer:320,unit is 4byte */
#define ZGB_R_TXBUF_EMPTY_TH(x)     ((u32)(((x) & 0x000007FF) << 12))
#define ZGB_GET_R_TXBUF_EMPTY_TH(x) ((u32)(((x >> 12) & 0x000007FF)))
#define ZGB_MASK_R_ZGB_TXDMA_TH     ((u32)0x000007FF << 1)          /*!<R/W 140h  when r_zgb_txdma_en is 1 and zigbee txbuf empty entry is large than the r_zgb_txdma_th, dma_tx_req is raised to GDMA half size of tx buffer:320,unit is 4byte */
#define ZGB_R_ZGB_TXDMA_TH(x)       ((u32)(((x) & 0x000007FF) << 1))
#define ZGB_GET_R_ZGB_TXDMA_TH(x)   ((u32)(((x >> 1) & 0x000007FF)))
#define ZGB_BIT_R_ZGB_TXDMA_EN      ((u32)0x00000001 << 0)          /*!<R/W 0  GDMA enable for Zigbee Txbuf */
/** @} */

/** @defgroup ZGB_RXBUF_CTRL
 * @brief Zigbee Rx buffer control
 * @{
 **/
#define ZGB_MASK_R_RXBUF_FULL_TH    ((u32)0x000003FF << 11)          /*!<R/W C0h  when zigbee rxbuf valid entry is large than the r_rxbuf_full_th, interrupt is issued to CPU half size of tx buffer:192,unit is 4byte */
#define ZGB_R_RXBUF_FULL_TH(x)      ((u32)(((x) & 0x000003FF) << 11))
#define ZGB_GET_R_RXBUF_FULL_TH(x)  ((u32)(((x >> 11) & 0x000003FF)))
#define ZGB_MASK_R_ZGB_RXDMA_TH     ((u32)0x000003FF << 1)          /*!<R/W C0h  when r_zgb_rxdma_en is 1 and zigbee rxbuf valid entry is large than the r_zgb_rxdma_th, dma_rx_req is raised to GDMA half size of tx buffer:192,unit is 4byte */
#define ZGB_R_ZGB_RXDMA_TH(x)       ((u32)(((x) & 0x000003FF) << 1))
#define ZGB_GET_R_ZGB_RXDMA_TH(x)   ((u32)(((x >> 1) & 0x000003FF)))
#define ZGB_BIT_R_ZGB_RXDMA_EN      ((u32)0x00000001 << 0)          /*!<R/W 0  GDMA enable for Zigbee Rxbuf */
/** @} */

/** @defgroup ZGB_ISR
 * @brief Zigbee Interrupt status
 * @{
 **/
#define ZGB_MASK_R_ZGB_ISR          ((u32)0xFFFFFFFF << 0)          /*!<RW1CB 0  interrupt status register of zigbee [31:14],dummy [13],INTER_ZIGBEE_AAGC_DONE, zigbee_aagcrdy posedge, pulse [12],rxbuf_underflow,when read rxbuf and txbuf is empty [11],rxbuf_empty,when rxbuf is empty [10],rxbuf_overflow,when write rxbuf and rxbuf is full [9],rxbuf_full,when rxbuf is full [8],INTER_ZIGBEE_RXBUF_ALMOST_FULL, when zigbee rxbuf valid entry is large than the r_rxbuf_full_th [7:6],dummy [5],INTER_ZIGBEE_TX_STOP, zigbee_rftxen negedege, pulse [4],txbuf_overflow, when wirte txbuf and txbuf is full [3],txbuf_full,when txbuf is full [2],txbuf_underflow,when read txbuf and txbuf is empty [1],txbuf_empty,when txbuf is empty [0], INTER_ZIGBEE_TXBUF_ALMOST_EMPTY, when zigbee txbuf empty entry is large than the r_txbuf_empty_th */
#define ZGB_R_ZGB_ISR(x)            ((u32)(((x) & 0xFFFFFFFF) << 0))
#define ZGB_GET_R_ZGB_ISR(x)        ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup ZGB_IMR
 * @brief Zigbee Interrupt mask
 * @{
 **/
#define ZGB_MASK_R_ZGB_IMR          ((u32)0xFFFFFFFF << 0)          /*!<R/W 0  interrupt mask register of zigbee */
#define ZGB_R_ZGB_IMR(x)            ((u32)(((x) & 0xFFFFFFFF) << 0))
#define ZGB_GET_R_ZGB_IMR(x)        ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup ZGB_TRXBUF_INFO
 * @brief Zigbee Tx/Rx buffer information
 * @{
 **/
#define ZGB_MASK_TXBUF_EMPTY_ENTRY  ((u32)0x000007FF << 10)          /*!<R 0  empty entry size of txbuf, unit is 4byte */
#define ZGB_TXBUF_EMPTY_ENTRY(x)    ((u32)(((x) & 0x000007FF) << 10))
#define ZGB_GET_TXBUF_EMPTY_ENTRY(x) ((u32)(((x >> 10) & 0x000007FF)))
#define ZGB_MASK_RXBUF_VALID_ENTRY  ((u32)0x000003FF << 0)          /*!<R 0  valid entry size of rxbuf, unit is 4byte */
#define ZGB_RXBUF_VALID_ENTRY(x)    ((u32)(((x) & 0x000003FF) << 0))
#define ZGB_GET_RXBUF_VALID_ENTRY(x) ((u32)(((x >> 0) & 0x000003FF)))
/** @} */

/** @defgroup ZGB_TRXBB_CTRL
 * @brief Zigbee Txbb/Rxbb control register
 * @{
 **/
#define ZGB_BIT_TX_DFIR_EN          ((u32)0x00000001 << 12)          /*!<R/W 1h  1,enable zigbee txdfir 0,disable zigbee txdfir */
#define ZGB_BIT_TX_IFMOD_EN         ((u32)0x00000001 << 11)          /*!<R/W 1h  1,enable zigbee txifmod 0,disable zigbee txifmod */
#define ZGB_BIT_RX_IFDEMOD_EN       ((u32)0x00000001 << 10)          /*!<R/W 1h  1,enable zigbee rxifdemod 0,disable zigbee rxifdemod */
#define ZGB_BIT_RX_DFIR1_EN         ((u32)0x00000001 << 9)          /*!<R/W 1h  1,enable zigbee rxdfir1 0,disable zigbee rxdifr1 */
#define ZGB_BIT_RX_DFIR2_EN         ((u32)0x00000001 << 8)          /*!<R/W 1h  1,enable zigbee rxdfir2 0,disable zigbee rxdfir2 */
#define ZGB_MASK_TX_SC              ((u32)0x0000000F << 4)          /*!<R/W 8h  TX channel location 1,offset=-17Mhz 2,offset=-12Mhz 3,offset=-9Mhz 4,offset=-7Mhz 5,offset=-4Mhz 6,offset=-2Mhz 7,offset=3Mhz 8,offset=8Mhz 9,offset=13Mhz 10,offset=18Mhz */
#define ZGB_TX_SC(x)                ((u32)(((x) & 0x0000000F) << 4))
#define ZGB_GET_TX_SC(x)            ((u32)(((x >> 4) & 0x0000000F)))
#define ZGB_MASK_RX_SC              ((u32)0x0000000F << 0)          /*!<R/W 8h  RX channel location 1,offset=17Mhz 2,offset=12Mhz 3,offset=9Mhz 4,offset=7Mhz 5,offset=4Mhz 6,offset=2Mhz 7,offset=-3Mhz 8,offset=-8Mhz 9,offset=-13Mhz 10,offset=-18Mhz */
#define ZGB_RX_SC(x)                ((u32)(((x) & 0x0000000F) << 0))
#define ZGB_GET_RX_SC(x)            ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup ZGB_TRX_REQ
 * @brief Zigbee Tx/Rx/pri request
 * @{
 **/
#define ZGB_BIT_TX_REQ              ((u32)0x00000001 << 2)          /*!<R/W 0  zigbee tx request */
#define ZGB_BIT_RX_REQ              ((u32)0x00000001 << 1)          /*!<R/W 0  zigbee rx request */
#define ZGB_BIT_PRI_REQ             ((u32)0x00000001 << 0)          /*!<R/W 0  zigbee priority request */
/** @} */
/** @} */



/* Exported types --------------------------------------------------------*/

/** @defgroup ZGB_Exported_Types ZGB Exported Types
  * @{
*****************************************************************************/


/**
 * @brief ZGB Register Declaration
 *****************************************************************************/
typedef struct {
	__IO uint32_t ZGB_FUN_EN;                             /*!< ZIGBEE FUNCTION ENABLE Register,  Address offset: 0x000 */
	__IO uint32_t ZGB_TXBUF_CTRL;                         /*!< ZIGBEE TX BUFFER CONTROL Register,  Address offset: 0x004 */
	__IO uint32_t ZGB_RXBUF_CTRL;                         /*!< ZIGBEE RX BUFFER CONTROL Register,  Address offset: 0x008 */
	__IO uint32_t ZGB_ISR;                                /*!< ZIGBEE INTERRUPT STATUS Register,  Address offset: 0x00C */
	__IO uint32_t ZGB_IMR;                                /*!< ZIGBEE INTERRUPT MASK Register,  Address offset: 0x010 */
	__IO uint32_t ZGB_TRXBUF_INFO;                        /*!< ZIGBEE TX/RX BUFFER INFORMATION Register,  Address offset: 0x014 */
	__IO uint32_t ZGB_TRXBB_CTRL;                         /*!< ZIGBEE TXBB/RXBB CONTROL REGISTER,  Address offset: 0x018 */
	__IO uint32_t ZGB_TRX_REQ;                            /*!< ZIGBEE TX/RX/PRI REQUEST Register,  Address offset: 0x01C */
} ZGB_TypeDef;
/** @} */
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your defination here

/* MANUAL_GEN_END */

#endif

/** @} */

/** @} */
