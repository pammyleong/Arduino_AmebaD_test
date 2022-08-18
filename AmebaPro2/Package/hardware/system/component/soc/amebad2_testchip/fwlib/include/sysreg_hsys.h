#ifndef _AMEBAD2_HSYS_H_
#define _AMEBAD2_HSYS_H_

/* AUTO_GEN_START */

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup HSYS
* @{
*/

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup HSYS_Register_Definitions HSYS Register Definitions
 * @{
 *****************************************************************************/

/** @defgroup REG_HSYS_HPLAT_CTRL
 * @brief
 * @{
 **/
#define HSYS_BIT_PSRAM_SPIC_BIG_ENDIAN   ((u32)0x00000001 << 28)          /*!<R/W 0  1: big endian 0: little endian */
#define HSYS_BIT_SW_SECURE_BOOT_FLAG     ((u32)0x00000001 << 27)          /*!<WO 0h   */
#define HSYS_BIT_SPI1_MST                ((u32)0x00000001 << 26)          /*!<R/W 0h  1: SPI1 used as master 0: SPI1 used as slaver */
#define HSYS_BIT_SPI0_MST                ((u32)0x00000001 << 25)          /*!<R/W 0h  1: SPI0 used as master 0: SPI0 used as slaver */
#define HSYS_BIT_EXT_MEM_IS_DDR          ((u32)0x00000001 << 24)          /*!<R/W 0  system DDR PSRAM select 1: using DDR 0: using PSRAM */
#define HSYS_BIT_DDRC_SPDUPSIM           ((u32)0x00000001 << 23)          /*!<R/W 0  ddrc simulatin speedup enable */
#define HSYS_MASK_GDMA0_CCM              ((u32)0x00000003 << 21)          /*!<R/W 0h  GDMA0 clock control mode */
#define HSYS_GDMA0_CCM(x)                ((u32)(((x) & 0x00000003) << 21))
#define HSYS_GET_GDMA0_CCM(x)            ((u32)(((x >> 21) & 0x00000003)))
#define HSYS_BIT_PSRAM_SPDUPSIM          ((u32)0x00000001 << 20)          /*!<R/W 0  psramc simulatin speedup enable */
#define HSYS_BIT_PLFM_AUTO_ICG_EN        ((u32)0x00000001 << 19)          /*!<R/W 0  1: Enable HS platform auto clock-gating for power saving 0: Disable */
#define HSYS_BIT_SHARE_BT_MEM            ((u32)0x00000001 << 18)          /*!<R/W 0  1: Enable KM4 to share BT memory */
#define HSYS_BIT_SHARE_WL_MEM            ((u32)0x00000001 << 17)          /*!<R/W 0  1: Enable KM4 to share WL memory */
#define HSYS_BIT_KM4_RETENTION_MODE      ((u32)0x00000001 << 16)          /*!<R/W 0  1: Enable, when KM4 reset, cache will not be cleared 0: Disable, when KM4 reset, cache will be cleared by HW */
/** @} */

/** @defgroup REG_HSYS_HPLAT_STATUS
 * @brief
 * @{
 **/
#define HSYS_BIT_DRAM_ADAP_IDLE          ((u32)0x00000001 << 10)          /*!<R 0   */
#define HSYS_BIT_LX2_MST_IDLE            ((u32)0x00000001 << 9)          /*!<R 0  Indicate Lx2 mst is idle */
#define HSYS_BIT_LX1_MST_IDLE            ((u32)0x00000001 << 8)          /*!<R 0  Indicate Lx1 mst is idle */
#define HSYS_BIT_KM4_DBGRESTARTED_M      ((u32)0x00000001 << 3)          /*!<R 0  KM4 debug restart status */
#define HSYS_BIT_KM4_HALTED_M            ((u32)0x00000001 << 2)          /*!<R 0  KM4 halt status */
#define HSYS_BIT_KM4_LOCKUP_M            ((u32)0x00000001 << 1)          /*!<R 0  KM4 lockup status */
#define HSYS_BIT_KM4_SL_SLEEPSYS_R       ((u32)0x00000001 << 0)          /*!<R 0  KM4 sleep status */
/** @} */

/** @defgroup REG_HSYS_SPIC_CTRL
 * @brief
 * @{
 **/
#define HSYS_BIT_FLASH_CAL_EN            ((u32)0x00000001 << 15)          /*!<R/W 0  Flash calibration enable 1: delay flash sout for calibration 0: bypass flash sout to spic */
#define HSYS_BIT_FLASH_DIV_EN            ((u32)0x00000001 << 13)          /*!<R/W 0  1: enable to generate flash clock (no phase shift) divided by 600M pll clock, HW detect this signal's rising edge to start the no phase shift division circuit. */
#define HSYS_BIT_FLASH_PS_DIV_EN         ((u32)0x00000001 << 12)          /*!<R/W 0  1: enable to generate flash clock (with phase shift) divided by 600M pll clock, HW detect this signal's rising edge to start the phase shift clock division circuit. */
#define HSYS_MASK_FLASH_DIV_INT          ((u32)0x00000003 << 10)          /*!<R/W 0  Flash clock division ratio, integrate part 2'b00: divided by 3 (600M/3 = 200M) 2'b01: divided by 4 2'b10: divided by 5 2'b11: divided by 6 Note: SPI clock frequency is this divided clock/2 */
#define HSYS_FLASH_DIV_INT(x)            ((u32)(((x) & 0x00000003) << 10))
#define HSYS_GET_FLASH_DIV_INT(x)        ((u32)(((x >> 10) & 0x00000003)))
#define HSYS_MASK_FLASH_PS_PHASE         ((u32)0x00000007 << 4)          /*!<R/W 0  Flash clock phase shift in units of 600M np pll clock cycels */
#define HSYS_FLASH_PS_PHASE(x)           ((u32)(((x) & 0x00000007) << 4))
#define HSYS_GET_FLASH_PS_PHASE(x)       ((u32)(((x >> 4) & 0x00000007)))
#define HSYS_BIT_FLASH_PS_DIV_RDY        ((u32)0x00000001 << 3)          /*!<R 0  Ready flag of Flash clock with phase shift, Read only (input signal) */
#define HSYS_BIT_FLASH_DIV_RDY           ((u32)0x00000001 << 2)          /*!<R 0  Ready flag of Flash clock, Read only (input signal) */
/** @} */

/** @defgroup REG_HSYS_USB_CTRL
 * @brief
 * @{
 **/
#define HSYS_BIT_USB2_DIGOTGPADEN        ((u32)0x00000001 << 28)          /*!<R/W 0   */
#define HSYS_BIT_USB_OTGMODE             ((u32)0x00000001 << 27)          /*!<R/W 0   */
#define HSYS_BIT_USB2_DIGPADEN           ((u32)0x00000001 << 26)          /*!<R/W 0   */
#define HSYS_BIT_ISO_USBA_EN             ((u32)0x00000001 << 25)          /*!<R/W 1  1: Enable signal from uSBPHY analog 0: disable */
#define HSYS_BIT_ISO_USBD_EN             ((u32)0x00000001 << 24)          /*!<R/W 1   */
#define HSYS_BIT_USBA_LDO_EN             ((u32)0x00000001 << 23)          /*!<R/W 0   */
#define HSYS_BIT_PDN_UPHY_EN             ((u32)0x00000001 << 20)          /*!<R/W 1  0: enable USBPHY shutdown */
#define HSYS_BIT_PWC_UABG_EN             ((u32)0x00000001 << 19)          /*!<R/W 0  1: enable USBPHY BG power cut */
#define HSYS_BIT_PWC_UAHV_EN             ((u32)0x00000001 << 18)          /*!<R/W 0  1: enable USBPHY HV power cut */
#define HSYS_BIT_PWC_UALV_EN             ((u32)0x00000001 << 17)          /*!<R/W 0  1: enable USBPHY LV power cut */
#define HSYS_BIT_OTG_ANA_EN              ((u32)0x00000001 << 16)          /*!<R/W 0  1: enable usb aphy lv2hv, hv2lv check for otg */
#define HSYS_MASK_USBOTG_CTRL            ((u32)0x0000FFFF << 0)          /*!<R/W 0h   */
#define HSYS_USBOTG_CTRL(x)              ((u32)(((x) & 0x0000FFFF) << 0))
#define HSYS_GET_USBOTG_CTRL(x)          ((u32)(((x >> 0) & 0x0000FFFF)))
/** @} */

/** @defgroup REG_HSYS_USB_TEST_CTRL
 * @brief
 * @{
 **/
#define HSYS_BIT_UPHY_SLB_CMD            ((u32)0x00000001 << 9)          /*!<R/W 0   */
#define HSYS_BIT_UPHY_DBG_CLK            ((u32)0x00000001 << 8)          /*!<R 0   */
#define HSYS_BIT_UPHY_SLB_HS             ((u32)0x00000001 << 7)          /*!<R/W 0   */
#define HSYS_BIT_UPHY_HS_SLB_OK          ((u32)0x00000001 << 6)          /*!<R 0   */
#define HSYS_BIT_UPHY_SLB_HW_PRD         ((u32)0x00000001 << 5)          /*!<R 0   */
#define HSYS_BIT_UPHY_FS_SLB_OK          ((u32)0x00000001 << 4)          /*!<R 0   */
#define HSYS_BIT_UPHY_FORCE_SLB          ((u32)0x00000001 << 3)          /*!<R/W 0   */
#define HSYS_BIT_UPHY_SLB_FAIL           ((u32)0x00000001 << 2)          /*!<R 0   */
#define HSYS_BIT_UPHY_SLB_DONE           ((u32)0x00000001 << 1)          /*!<R 0   */
#define HSYS_BIT_USB_TST_SEL             ((u32)0x00000001 << 0)          /*!<R/W 0h  select the location where the USB test signals are from 0: register 1: PINMUX GPIO */
/** @} */

/** @defgroup REG_HSYS_SDH_CTRL
 * @brief
 * @{
 **/
#define HSYS_BIT_SDCD_DBNC_EN            ((u32)0x00000001 << 7)          /*!<R/W 0  1: enable SDH card connect debounce */
#define HSYS_MASK_SDCD_DBNC_CNT          ((u32)0x0000003F << 0)          /*!<R/W 0h  debounce count value, unit is 1ms */
#define HSYS_SDCD_DBNC_CNT(x)            ((u32)(((x) & 0x0000003F) << 0))
#define HSYS_GET_SDCD_DBNC_CNT(x)        ((u32)(((x >> 0) & 0x0000003F)))
/** @} */

/** @defgroup REG_HSYS_DDR_CTRL
 * @brief
 * @{
 **/
#define HSYS_BIT_DDRP_CLKEN_DCPHY        ((u32)0x00000001 << 1)          /*!<R/W 1h  1: enable all rbus signal 0: disable all rbus clock signal */
#define HSYS_BIT_DDRP_CLKEN_PLLREG       ((u32)0x00000001 << 0)          /*!<R/W 1h  1: enable ddr phy crt register rbus clock 0: disable */
/** @} */

/** @defgroup REG_HSYS_LXBUS_DBG_CTRL
 * @brief
 * @{
 **/
#define HSYS_BIT_LX1_LOCK_OK             ((u32)0x00000001 << 12)          /*!<R 0  lock lx1 bus lock ok */
#define HSYS_BIT_LX1_LOCK_BUS            ((u32)0x00000001 << 8)          /*!<R/W 0  lock lx1 bus for debug */
#define HSYS_MASK_BUSTIMEOUT             ((u32)0x00000003 << 4)          /*!<R/W 0  lx sys bus arb timeout thresh */
#define HSYS_BUSTIMEOUT(x)               ((u32)(((x) & 0x00000003) << 4))
#define HSYS_GET_BUSTIMEOUT(x)           ((u32)(((x >> 4) & 0x00000003)))
#define HSYS_BIT_ENBUSTIMEOUT            ((u32)0x00000001 << 0)          /*!<R/W 0  lx sys bus arb timeout enable */
/** @} */

/** @defgroup REG_HSYS_LXBUS_DBG0
 * @brief
 * @{
 **/
#define HSYS_MASK_TIMEOUT_ADDR_MST       ((u32)0xFFFFFFFF << 0)          /*!<R 0  lx sys bus addr debug out */
#define HSYS_TIMEOUT_ADDR_MST(x)         ((u32)(((x) & 0xFFFFFFFF) << 0))
#define HSYS_GET_TIMEOUT_ADDR_MST(x)     ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_HSYS_LXBUS_DBG1
 * @brief
 * @{
 **/
#define HSYS_MASK_TIMEOUT_ADDR_SLV       ((u32)0xFFFFFFFF << 0)          /*!<R 0  lx sys bus addr debug out */
#define HSYS_TIMEOUT_ADDR_SLV(x)         ((u32)(((x) & 0xFFFFFFFF) << 0))
#define HSYS_GET_TIMEOUT_ADDR_SLV(x)     ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */


/*==========HSYS Register Address Definition==========*/
#define REG_HSYS_HPLAT_CTRL                          0x0030
#define REG_HSYS_HPLAT_STATUS                        0x0034
#define REG_HSYS_SPIC_CTRL                           0x0040
#define REG_HSYS_USB_CTRL                            0x0060
#define REG_HSYS_USB_TEST_CTRL                       0x0064
#define REG_HSYS_SDH_CTRL                            0x0070
#define REG_HSYS_DDR_CTRL                            0x0080
#define REG_HSYS_LXBUS_DBG_CTRL                      0x0090
#define REG_HSYS_LXBUS_DBG0                          0x0094
#define REG_HSYS_LXBUS_DBG1                          0x0098
#define REG_HSYS_DUMMY_1E0                           0x01E0
#define REG_HSYS_DUMMY_1E4                           0x01E4
#define REG_HSYS_DUMMY_1E8                           0x01E8
#define REG_HSYS_DUMMY_1EC                           0x01EC
#define REG_HSYS_BOUNDARY_CHK                        0x01F0
#define REG_HSYS_DUMMY_1F4                           0x01F4
#define REG_HSYS_DUMMY_1F8                           0x01F8
#define REG_HSYS_DUMMY_1FC                           0x01FC

/** @} */

/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your defination here

/* MANUAL_GEN_END */

#endif

/** @} */

/** @} */
