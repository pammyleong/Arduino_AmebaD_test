#ifndef _AMEBAD2_MEM_CTRL_H_
#define _AMEBAD2_MEM_CTRL_H_

/* AUTO_GEN_START */

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup MEM_CTRL
* @{
*/

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup MEM_CTRL_Register_Definitions MEM_CTRL Register Definitions
 * @{
 *****************************************************************************/

/** @defgroup REG_CTRL_MEM_AONPMC_E0_FTC_ULP_ROM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_AONPMC_E0_FTC_ROM_SLP                ((u32)0x00000001 << 5)          /*!<R/W 0x0  FTC_ULP_SPROM, PG bit2, not used in btrom */
#define CTRL_BIT_MEM_AONPMC_E0_FTC_ROM_DVSE               ((u32)0x00000001 << 4)          /*!<R/W 0x0  FTC_ULP_SPROM */
#define CTRL_MASK_MEM_AONPMC_E0_FTC_ROM_DVS               ((u32)0x0000000F << 0)          /*!<R/W 0x5  FTC_ULP_SPROM */
#define CTRL_MEM_AONPMC_E0_FTC_ROM_DVS(x)                 ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_AONPMC_E0_FTC_ROM_DVS(x)             ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_LRET_E0_ARM_ULL_RF_PG_0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_PGEN               ((u32)0x00000001 << 14)          /*!<R/W 0x0  ARM_ULL RF With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_RET2N              ((u32)0x00000001 << 13)          /*!<R/W 0x1  ARM_ULL RF With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_RET1N              ((u32)0x00000001 << 12)          /*!<R/W 0x1  ARM_ULL RF With Power Gating, PG bit0 */
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_RAWLM_0P8         ((u32)0x00000003 << 10)          /*!<R/W 2'b00  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_RAWLM_0P8(x)           ((u32)(((x) & 0x00000003) << 10))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_RAWLM_0P8(x)       ((u32)(((x >> 10) & 0x00000003)))
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_RAWL_0P8           ((u32)0x00000001 << 9)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_WABLM_0P8         ((u32)0x00000003 << 7)          /*!<R/W 2'b01  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_WABLM_0P8(x)           ((u32)(((x) & 0x00000003) << 7))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_WABLM_0P8(x)       ((u32)(((x >> 7) & 0x00000003)))
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_WABL_0P8           ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_EMAS_0P8           ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_EMAW_0P8          ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_EMAW_0P8(x)            ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_EMAW_0P8(x)        ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_EMA_0P8           ((u32)0x00000007 << 0)          /*!<R/W 3'b100  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_EMA_0P8(x)             ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_EMA_0P8(x)         ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_LRET_E0_ARM_ULL_RF_PG_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_RAWLM_1P0         ((u32)0x00000003 << 22)          /*!<R/W 2'b0  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_RAWLM_1P0(x)           ((u32)(((x) & 0x00000003) << 22))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_RAWLM_1P0(x)       ((u32)(((x >> 22) & 0x00000003)))
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_RAWL_1P0           ((u32)0x00000001 << 21)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_WABLM_1P0         ((u32)0x00000003 << 19)          /*!<R/W 2'b0  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_WABLM_1P0(x)           ((u32)(((x) & 0x00000003) << 19))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_WABLM_1P0(x)       ((u32)(((x >> 19) & 0x00000003)))
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_WABL_1P0           ((u32)0x00000001 << 18)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_EMAS_1P0           ((u32)0x00000001 << 17)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_EMAW_1P0          ((u32)0x00000003 << 15)          /*!<R/W 2'b01  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_EMAW_1P0(x)            ((u32)(((x) & 0x00000003) << 15))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_EMAW_1P0(x)        ((u32)(((x >> 15) & 0x00000003)))
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_EMA_1P0           ((u32)0x00000007 << 12)          /*!<R/W 3'b011  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_EMA_1P0(x)             ((u32)(((x) & 0x00000007) << 12))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_EMA_1P0(x)         ((u32)(((x >> 12) & 0x00000007)))
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_RAWLM_0P9         ((u32)0x00000003 << 10)          /*!<R/W 2'b00  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_RAWLM_0P9(x)           ((u32)(((x) & 0x00000003) << 10))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_RAWLM_0P9(x)       ((u32)(((x >> 10) & 0x00000003)))
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_RAWL_0P9           ((u32)0x00000001 << 9)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_WABLM_0P9         ((u32)0x00000003 << 7)          /*!<R/W 2'b00  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_WABLM_0P9(x)           ((u32)(((x) & 0x00000003) << 7))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_WABLM_0P9(x)       ((u32)(((x >> 7) & 0x00000003)))
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_WABL_0P9           ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_BIT_MEM_LRET_E0_ARM_RF_PG_EMAS_0P9           ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_EMAW_0P9          ((u32)0x00000003 << 3)          /*!<R/W 2'b01  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_EMAW_0P9(x)            ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_EMAW_0P9(x)        ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_LRET_E0_ARM_RF_PG_EMA_0P9           ((u32)0x00000007 << 0)          /*!<R/W 3'b011  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MEM_LRET_E0_ARM_RF_PG_EMA_0P9(x)             ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_LRET_E0_ARM_RF_PG_EMA_0P9(x)         ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_LSYS_E0_ARM_ULL_SRAM_PG_0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_LSYS_PGEN_SLEP                       ((u32)0x00000001 << 26)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_LSYS_RET2N_SLEP                      ((u32)0x00000001 << 25)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating, PG bit1 */
#define CTRL_BIT_MEM_LSYS_RET1N_SLEP                      ((u32)0x00000001 << 24)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit0 */
#define CTRL_BIT_MEM_LSYS_PGEN_NORM                       ((u32)0x00000001 << 22)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_LSYS_RET2N_NORM                      ((u32)0x00000001 << 21)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit1 */
#define CTRL_BIT_MEM_LSYS_RET1N_NORM                      ((u32)0x00000001 << 20)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit0 */
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_PGEN             ((u32)0x00000001 << 16)          /*!<R/W/ES 0x0  ARM_ULL SRAM With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_RET2N            ((u32)0x00000001 << 15)          /*!<R/W/ES 0x1  ARM_ULL SRAM With Power Gating, PG bit1 */
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_RET1N            ((u32)0x00000001 << 14)          /*!<R/W/ES 0x1  ARM_ULL SRAM With Power Gating, PG bit0 */
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_STOV             ((u32)0x00000001 << 13)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating */
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_RAWLM_0P8       ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_RAWLM_0P8(x)         ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_RAWLM_0P8(x)     ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_RAWL_0P8         ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_WABLM_0P8       ((u32)0x00000007 << 7)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_WABLM_0P8(x)         ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_WABLM_0P8(x)     ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_WABL_0P8         ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_EMAS_0P8         ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_EMAW_0P8        ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_EMAW_0P8(x)          ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_EMAW_0P8(x)      ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_EMA_0P8         ((u32)0x00000007 << 0)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_EMA_0P8(x)           ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_EMA_0P8(x)       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_LSYS_E0_ARM_ULL_SRAM_PG_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_RAWLM_1P0       ((u32)0x00000003 << 25)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_RAWLM_1P0(x)         ((u32)(((x) & 0x00000003) << 25))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_RAWLM_1P0(x)     ((u32)(((x >> 25) & 0x00000003)))
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_RAWL_1P0         ((u32)0x00000001 << 24)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_WABLM_1P0       ((u32)0x00000007 << 21)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_WABLM_1P0(x)         ((u32)(((x) & 0x00000007) << 21))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_WABLM_1P0(x)     ((u32)(((x >> 21) & 0x00000007)))
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_WABL_1P0         ((u32)0x00000001 << 20)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_EMAS_1P0         ((u32)0x00000001 << 19)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_EMAW_1P0        ((u32)0x00000003 << 17)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_EMAW_1P0(x)          ((u32)(((x) & 0x00000003) << 17))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_EMAW_1P0(x)      ((u32)(((x >> 17) & 0x00000003)))
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_EMA_1P0         ((u32)0x00000007 << 14)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_EMA_1P0(x)           ((u32)(((x) & 0x00000007) << 14))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_EMA_1P0(x)       ((u32)(((x >> 14) & 0x00000007)))
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_RAWLM_0P9       ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_RAWLM_0P9(x)         ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_RAWLM_0P9(x)     ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_RAWL_0P9         ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_WABLM_0P9       ((u32)0x00000007 << 7)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_WABLM_0P9(x)         ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_WABLM_0P9(x)     ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_WABL_0P9         ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_BIT_MEM_LSYS_E0_ARM_SRAM_PG_EMAS_0P9         ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_EMAW_0P9        ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_EMAW_0P9(x)          ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_EMAW_0P9(x)      ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_LSYS_E0_ARM_SRAM_PG_EMA_0P9         ((u32)0x00000007 << 0)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_LSYS_E0_ARM_SRAM_PG_EMA_0P9(x)           ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_LSYS_E0_ARM_SRAM_PG_EMA_0P9(x)       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_LSPMC_E0_FTC_ULP_ROM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_LSPMC_E0_FTC_ROM_SLP                 ((u32)0x00000001 << 5)          /*!<R/W 0x0  FTC_ULP_SPROM, PG bit2, not used in btrom, must write before ls_system powered */
#define CTRL_BIT_MEM_LSPMC_E0_FTC_ROM_DVSE                ((u32)0x00000001 << 4)          /*!<R/W 0x0  FTC_ULP_SPROM, must write before ls_system powered */
#define CTRL_MASK_MEM_LSPMC_E0_FTC_ROM_DVS                ((u32)0x0000000F << 0)          /*!<R/W 0x5  FTC_ULP_SPROM, must write before ls_system powered */
#define CTRL_MEM_LSPMC_E0_FTC_ROM_DVS(x)                  ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_LSPMC_E0_FTC_ROM_DVS(x)              ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_HSYS_E0_ARM_ULL_SRAM_PG_0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_PGEN             ((u32)0x00000001 << 16)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_RET2N            ((u32)0x00000001 << 15)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit1 */
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_RET1N            ((u32)0x00000001 << 14)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit0 */
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_STOV             ((u32)0x00000001 << 13)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating */
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_RAWLM_0P8       ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_RAWLM_0P8(x)         ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_RAWLM_0P8(x)     ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_RAWL_0P8         ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_WABLM_0P8       ((u32)0x00000007 << 7)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_WABLM_0P8(x)         ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_WABLM_0P8(x)     ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_WABL_0P8         ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_EMAS_0P8         ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_EMAW_0P8        ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_EMAW_0P8(x)          ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_EMAW_0P8(x)      ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_EMA_0P8         ((u32)0x00000007 << 0)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_EMA_0P8(x)           ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_EMA_0P8(x)       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_HSYS_E0_ARM_ULL_SRAM_PG_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_RAWLM_1P0       ((u32)0x00000003 << 25)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_RAWLM_1P0(x)         ((u32)(((x) & 0x00000003) << 25))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_RAWLM_1P0(x)     ((u32)(((x >> 25) & 0x00000003)))
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_RAWL_1P0         ((u32)0x00000001 << 24)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_WABLM_1P0       ((u32)0x00000007 << 21)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_WABLM_1P0(x)         ((u32)(((x) & 0x00000007) << 21))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_WABLM_1P0(x)     ((u32)(((x >> 21) & 0x00000007)))
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_WABL_1P0         ((u32)0x00000001 << 20)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_EMAS_1P0         ((u32)0x00000001 << 19)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_EMAW_1P0        ((u32)0x00000003 << 17)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_EMAW_1P0(x)          ((u32)(((x) & 0x00000003) << 17))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_EMAW_1P0(x)      ((u32)(((x >> 17) & 0x00000003)))
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_EMA_1P0         ((u32)0x00000007 << 14)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_EMA_1P0(x)           ((u32)(((x) & 0x00000007) << 14))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_EMA_1P0(x)       ((u32)(((x >> 14) & 0x00000007)))
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_RAWLM_0P9       ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_RAWLM_0P9(x)         ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_RAWLM_0P9(x)     ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_RAWL_0P9         ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_WABLM_0P9       ((u32)0x00000007 << 7)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_WABLM_0P9(x)         ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_WABLM_0P9(x)     ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_WABL_0P9         ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_BIT_MEM_HSYS_E0_ARM_SRAM_PG_EMAS_0P9         ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_EMAW_0P9        ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_EMAW_0P9(x)          ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_EMAW_0P9(x)      ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_HSYS_E0_ARM_SRAM_PG_EMA_0P9         ((u32)0x00000007 << 0)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_HSYS_E0_ARM_SRAM_PG_EMA_0P9(x)           ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_HSYS_E0_ARM_SRAM_PG_EMA_0P9(x)       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_CA7BOOT_E0_FTC_ROM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_CA7BOOT_E0_FTC_ROM_SLP               ((u32)0x00000001 << 5)          /*!<R/W 0x0  FTC_ULP_SPROM, PG bit2, not used in btrom */
#define CTRL_BIT_MEM_CA7BOOT_E0_FTC_ROM_DVSE              ((u32)0x00000001 << 4)          /*!<R/W 0x0  FTC_ULP_SPROM */
#define CTRL_MASK_MEM_CA7BOOT_E0_FTC_ROM_DVS              ((u32)0x0000000F << 0)          /*!<R/W 0x5  FTC_ULP_SPROM */
#define CTRL_MEM_CA7BOOT_E0_FTC_ROM_DVS(x)                ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_CA7BOOT_E0_FTC_ROM_DVS(x)            ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_WLK4_E0_ARM_ULL_SRAM_PG_0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_PGEN             ((u32)0x00000001 << 16)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_RET2N            ((u32)0x00000001 << 15)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit1 */
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_RET1N            ((u32)0x00000001 << 14)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit0 */
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_STOV             ((u32)0x00000001 << 13)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating */
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_RAWLM_0P8       ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_RAWLM_0P8(x)         ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_RAWLM_0P8(x)     ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_RAWL_0P8         ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_WABLM_0P8       ((u32)0x00000007 << 7)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_WABLM_0P8(x)         ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_WABLM_0P8(x)     ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_WABL_0P8         ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_EMAS_0P8         ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_EMAW_0P8        ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_EMAW_0P8(x)          ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_EMAW_0P8(x)      ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_EMA_0P8         ((u32)0x00000007 << 0)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_EMA_0P8(x)           ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_EMA_0P8(x)       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_WLK4_E0_ARM_ULL_SRAM_PG_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_RAWLM_1P0       ((u32)0x00000003 << 25)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_RAWLM_1P0(x)         ((u32)(((x) & 0x00000003) << 25))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_RAWLM_1P0(x)     ((u32)(((x >> 25) & 0x00000003)))
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_RAWL_1P0         ((u32)0x00000001 << 24)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_WABLM_1P0       ((u32)0x00000007 << 21)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_WABLM_1P0(x)         ((u32)(((x) & 0x00000007) << 21))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_WABLM_1P0(x)     ((u32)(((x >> 21) & 0x00000007)))
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_WABL_1P0         ((u32)0x00000001 << 20)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_EMAS_1P0         ((u32)0x00000001 << 19)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_EMAW_1P0        ((u32)0x00000003 << 17)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_EMAW_1P0(x)          ((u32)(((x) & 0x00000003) << 17))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_EMAW_1P0(x)      ((u32)(((x >> 17) & 0x00000003)))
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_EMA_1P0         ((u32)0x00000007 << 14)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_EMA_1P0(x)           ((u32)(((x) & 0x00000007) << 14))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_EMA_1P0(x)       ((u32)(((x >> 14) & 0x00000007)))
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_RAWLM_0P9       ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_RAWLM_0P9(x)         ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_RAWLM_0P9(x)     ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_RAWL_0P9         ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_WABLM_0P9       ((u32)0x00000007 << 7)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_WABLM_0P9(x)         ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_WABLM_0P9(x)     ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_WABL_0P9         ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_BIT_MEM_WLK4_E0_ARM_SRAM_PG_EMAS_0P9         ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_EMAW_0P9        ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_EMAW_0P9(x)          ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_EMAW_0P9(x)      ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_WLK4_E0_ARM_SRAM_PG_EMA_0P9         ((u32)0x00000007 << 0)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_WLK4_E0_ARM_SRAM_PG_EMA_0P9(x)           ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_WLK4_E0_ARM_SRAM_PG_EMA_0P9(x)       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_WPOFF_E0_ARM_ULL_RF_PG_0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_PGEN              ((u32)0x00000001 << 14)          /*!<R/W 0x0  ARM_ULL RF With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_RET2N             ((u32)0x00000001 << 13)          /*!<R/W 0x1  ARM_ULL RF With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_RET1N             ((u32)0x00000001 << 12)          /*!<R/W 0x1  ARM_ULL RF With Power Gating, PG bit0 */
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_RAWLM_0P8        ((u32)0x00000003 << 10)          /*!<R/W 2'b00  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_RAWLM_0P8(x)          ((u32)(((x) & 0x00000003) << 10))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_RAWLM_0P8(x)      ((u32)(((x >> 10) & 0x00000003)))
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_RAWL_0P8          ((u32)0x00000001 << 9)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_WABLM_0P8        ((u32)0x00000003 << 7)          /*!<R/W 2'b01  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_WABLM_0P8(x)          ((u32)(((x) & 0x00000003) << 7))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_WABLM_0P8(x)      ((u32)(((x >> 7) & 0x00000003)))
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_WABL_0P8          ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_EMAS_0P8          ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_EMAW_0P8         ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_EMAW_0P8(x)           ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_EMAW_0P8(x)       ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_EMA_0P8          ((u32)0x00000007 << 0)          /*!<R/W 3'b100  ARM_ULL RF With Power Gating, 0.8V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_EMA_0P8(x)            ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_EMA_0P8(x)        ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_WPOFF_E0_ARM_ULL_RF_PG_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_RAWLM_1P0        ((u32)0x00000003 << 22)          /*!<R/W 2'b0  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_RAWLM_1P0(x)          ((u32)(((x) & 0x00000003) << 22))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_RAWLM_1P0(x)      ((u32)(((x >> 22) & 0x00000003)))
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_RAWL_1P0          ((u32)0x00000001 << 21)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_WABLM_1P0        ((u32)0x00000003 << 19)          /*!<R/W 2'b0  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_WABLM_1P0(x)          ((u32)(((x) & 0x00000003) << 19))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_WABLM_1P0(x)      ((u32)(((x >> 19) & 0x00000003)))
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_WABL_1P0          ((u32)0x00000001 << 18)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_EMAS_1P0          ((u32)0x00000001 << 17)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_EMAW_1P0         ((u32)0x00000003 << 15)          /*!<R/W 2'b01  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_EMAW_1P0(x)           ((u32)(((x) & 0x00000003) << 15))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_EMAW_1P0(x)       ((u32)(((x >> 15) & 0x00000003)))
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_EMA_1P0          ((u32)0x00000007 << 12)          /*!<R/W 3'b011  ARM_ULL RF With Power Gating, 1.0V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_EMA_1P0(x)            ((u32)(((x) & 0x00000007) << 12))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_EMA_1P0(x)        ((u32)(((x >> 12) & 0x00000007)))
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_RAWLM_0P9        ((u32)0x00000003 << 10)          /*!<R/W 2'b00  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_RAWLM_0P9(x)          ((u32)(((x) & 0x00000003) << 10))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_RAWLM_0P9(x)      ((u32)(((x >> 10) & 0x00000003)))
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_RAWL_0P9          ((u32)0x00000001 << 9)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_WABLM_0P9        ((u32)0x00000003 << 7)          /*!<R/W 2'b00  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_WABLM_0P9(x)          ((u32)(((x) & 0x00000003) << 7))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_WABLM_0P9(x)      ((u32)(((x >> 7) & 0x00000003)))
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_WABL_0P9          ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_BIT_MEM_WPOFF_E0_ARM_RF_PG_EMAS_0P9          ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_EMAW_0P9         ((u32)0x00000003 << 3)          /*!<R/W 2'b01  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_EMAW_0P9(x)           ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_EMAW_0P9(x)       ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_WPOFF_E0_ARM_RF_PG_EMA_0P9          ((u32)0x00000007 << 0)          /*!<R/W 3'b011  ARM_ULL RF With Power Gating, 0.9V */
#define CTRL_MEM_WPOFF_E0_ARM_RF_PG_EMA_0P9(x)            ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_WPOFF_E0_ARM_RF_PG_EMA_0P9(x)        ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_WPOFF_E1_FTC_ULP_RW
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_WPOFF_E1_FTC_RW_NAP                  ((u32)0x00000001 << 14)          /*!<R/W 0x0  FTC_ULP_SPRAM_RW: pg_b0 CSB=1 & NAP=1 reduce peripheral power. Cell array's data retained. */
#define CTRL_BIT_MEM_WPOFF_E1_FTC_RW_TMCK                 ((u32)0x00000001 << 13)          /*!<R/W 0x0  FTC_ULP_SPRAM_RW Internal timing bypass signal. TMCK=1: WL pulse will be controlled by the clock duty cycle. TMCK=0: default value, RAM access normally. */
#define CTRL_BIT_MEM_WPOFF_E1_FTC_RW_WAE                  ((u32)0x00000001 << 12)          /*!<R/W 0x0  FTC_ULP_SPRAM_RW WAE=1: Turn on the write assist circuit. WAE=0: Turn off the write assist circuit. */
#define CTRL_MASK_MEM_WPOFF_E1_FTC_RW_WAEM                ((u32)0x0000000F << 8)          /*!<R/W 0xA  FTC_ULP_SPRAM_RW WAEM[3:2] controls the write assist circuit timing margin when WAE=1. WAEM[3:2]=00: turn off the time margin of the write assist circuit. WAEM[3:2]=01: Lossest timing margin WAEM[3:2]=10: WAEM[3:2]=11: Tightest timing margin. WAEM[1:0] controls the write assist circuit voltage margin when WAE=1. WAEM[1:0]=00: Turn off the voltage margin of the write assist circuit WAEM[1:0]=01: Minimum voltage margin WAEM[1:0]=10: WAEM[1:0]=11: Maximum voltage margin. */
#define CTRL_MEM_WPOFF_E1_FTC_RW_WAEM(x)                  ((u32)(((x) & 0x0000000F) << 8))
#define CTRL_GET_MEM_WPOFF_E1_FTC_RW_WAEM(x)              ((u32)(((x >> 8) & 0x0000000F)))
#define CTRL_BIT_MEM_WPOFF_E1_FTC_RW_RAE                  ((u32)0x00000001 << 7)          /*!<R/W 0x0  FTC_ULP_SPRAM_RW RAE=1: turn on the read assist circuit. RAE=0: turn off the read assist circuit. */
#define CTRL_MASK_MEM_WPOFF_E1_FTC_RW_RAEM                ((u32)0x00000003 << 5)          /*!<R/W 0x0  FTC_ULP_SPRAM_RW adjust the margin of read assist circuit when RAE=1. RAEM=00: default WL voltage drop RAEM=01 RAEM=10 RAEM=11: maximum WL voltage drop */
#define CTRL_MEM_WPOFF_E1_FTC_RW_RAEM(x)                  ((u32)(((x) & 0x00000003) << 5))
#define CTRL_GET_MEM_WPOFF_E1_FTC_RW_RAEM(x)              ((u32)(((x >> 5) & 0x00000003)))
#define CTRL_BIT_MEM_WPOFF_E1_FTC_RW_DVSE                 ((u32)0x00000001 << 4)          /*!<R/W 0x0  FTC_ULP_SPRAM_RW DVSE=1: delay option enable. DVSE=0: delay option disable. */
#define CTRL_MASK_MEM_WPOFF_E1_FTC_RW_DVS                 ((u32)0x0000000F << 0)          /*!<R/W 0xC  FTC_ULP_SPRAM_RW DVS[0] controls the SRAM sensing pulse when DVSE=1. DVS[0]=1: short pulse width DVS[0]=0: long pulse width dvs[3:1] is delay option control words when DVSE=1. DVS[3:1] = 000: loosest margin. DVS[3:1] = 001 DVS[3:1] = 010 DVS[3:1] = 011 ... */
#define CTRL_MEM_WPOFF_E1_FTC_RW_DVS(x)                   ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_WPOFF_E1_FTC_RW_DVS(x)               ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_WPOFF_E2_FTC_ULP_RW_TPRAM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_WPOFF_E2_FTC_RW_TPSRAM_NAP           ((u32)0x00000001 << 14)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM:pg_b0 CSA(B)=1 & NAP=1 reduce peripheral power. Cell array's data retained. */
#define CTRL_BIT_MEM_WPOFF_E2_FTC_RW_TPSRAM_TMCK          ((u32)0x00000001 << 13)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM */
#define CTRL_BIT_MEM_WPOFF_E2_FTC_RW_TPSRAM_WAE           ((u32)0x00000001 << 12)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM */
#define CTRL_MASK_MEM_WPOFF_E2_FTC_RW_TPSRAM_WAEM         ((u32)0x0000000F << 8)          /*!<R/W 0xA  FTC_ULP_RW_TPRAM */
#define CTRL_MEM_WPOFF_E2_FTC_RW_TPSRAM_WAEM(x)           ((u32)(((x) & 0x0000000F) << 8))
#define CTRL_GET_MEM_WPOFF_E2_FTC_RW_TPSRAM_WAEM(x)       ((u32)(((x >> 8) & 0x0000000F)))
#define CTRL_BIT_MEM_WPOFF_E2_FTC_RW_TPSRAM_RAE           ((u32)0x00000001 << 7)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM */
#define CTRL_MASK_MEM_WPOFF_E2_FTC_RW_TPSRAM_RAEM         ((u32)0x00000003 << 5)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM */
#define CTRL_MEM_WPOFF_E2_FTC_RW_TPSRAM_RAEM(x)           ((u32)(((x) & 0x00000003) << 5))
#define CTRL_GET_MEM_WPOFF_E2_FTC_RW_TPSRAM_RAEM(x)       ((u32)(((x >> 5) & 0x00000003)))
#define CTRL_BIT_MEM_WPOFF_E2_FTC_RW_TPSRAM_DVSE          ((u32)0x00000001 << 4)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM */
#define CTRL_MASK_MEM_WPOFF_E2_FTC_RW_TPSRAM_DVS          ((u32)0x0000000F << 0)          /*!<R/W 0xA  FTC_ULP_RW_TPRAM */
#define CTRL_MEM_WPOFF_E2_FTC_RW_TPSRAM_DVS(x)            ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_WPOFF_E2_FTC_RW_TPSRAM_DVS(x)        ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_WPOFF_E3_FTC_ULP_RW
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_WPOFF_E3_FTC_RW_NAP                  ((u32)0x00000001 << 14)          /*!<R/W 0x0  FTC_ULP_RW_RF: pg_b0 CSB=1 & NAP=1 reduce peripheral power. Cell array's data retained. */
#define CTRL_BIT_MEM_WPOFF_E3_FTC_RW_TMCK                 ((u32)0x00000001 << 13)          /*!<R/W 0x0  FTC_ULP_RW_RF Internal timing bypass signal. TMCK=1: WL pulse will be controlled by the clock duty cycle. TMCK=0: default value, RAM access normally. */
#define CTRL_BIT_MEM_WPOFF_E3_FTC_RW_WAE                  ((u32)0x00000001 << 12)          /*!<R/W 0x0  FTC_ULP_RW_RF WAE=1: Turn on the write assist circuit. WAE=0: Turn off the write assist circuit. */
#define CTRL_MASK_MEM_WPOFF_E3_FTC_RW_WAEM                ((u32)0x0000000F << 8)          /*!<R/W 0xA  FTC_ULP_RW_RF WAEM[3:2] controls the write assist circuit timing margin when WAE=1. WAEM[3:2]=00: turn off the time margin of the write assist circuit. WAEM[3:2]=01: Lossest timing margin WAEM[3:2]=10: WAEM[3:2]=11: Tightest timing margin. WAEM[1:0] controls the write assist circuit voltage margin when WAE=1. WAEM[1:0]=00: Turn off the voltage margin of the write assist circuit WAEM[1:0]=01: Minimum voltage margin WAEM[1:0]=10: WAEM[1:0]=11: Maximum voltage margin. */
#define CTRL_MEM_WPOFF_E3_FTC_RW_WAEM(x)                  ((u32)(((x) & 0x0000000F) << 8))
#define CTRL_GET_MEM_WPOFF_E3_FTC_RW_WAEM(x)              ((u32)(((x >> 8) & 0x0000000F)))
#define CTRL_BIT_MEM_WPOFF_E3_FTC_RW_RAE                  ((u32)0x00000001 << 7)          /*!<R/W 0x0  FTC_ULP_RW_RF RAE=1: turn on the read assist circuit. RAE=0: turn off the read assist circuit. */
#define CTRL_MASK_MEM_WPOFF_E3_FTC_RW_RAEM                ((u32)0x00000003 << 5)          /*!<R/W 0x0  FTC_ULP_RW_RF adjust the margin of read assist circuit when RAE=1. RAEM=00: default WL voltage drop RAEM=01 RAEM=10 RAEM=11: maximum WL voltage drop */
#define CTRL_MEM_WPOFF_E3_FTC_RW_RAEM(x)                  ((u32)(((x) & 0x00000003) << 5))
#define CTRL_GET_MEM_WPOFF_E3_FTC_RW_RAEM(x)              ((u32)(((x >> 5) & 0x00000003)))
#define CTRL_BIT_MEM_WPOFF_E3_FTC_RW_DVSE                 ((u32)0x00000001 << 4)          /*!<R/W 0x0  FTC_ULP_RW_RF DVSE=1: delay option enable. DVSE=0: delay option disable. */
#define CTRL_MASK_MEM_WPOFF_E3_FTC_RW_DVS                 ((u32)0x0000000F << 0)          /*!<R/W 0xC  FTC_ULP_RW_RF DVS[0] controls the SRAM sensing pulse when DVSE=1. DVS[0]=1: short pulse width DVS[0]=0: long pulse width dvs[3:1] is delay option control words when DVSE=1. DVS[3:1] = 000: loosest margin. DVS[3:1] = 001 DVS[3:1] = 010 DVS[3:1] = 011 … */
#define CTRL_MEM_WPOFF_E3_FTC_RW_DVS(x)                   ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_WPOFF_E3_FTC_RW_DVS(x)               ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_WPOFF_E4_FTC_ULP_RW_TPSRAM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_WPOFF_E4_FTC_RW_TPSRAM_NAP           ((u32)0x00000001 << 14)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM: pg_b0 CSA(B)=1 & NAP=1 reduce peripheral power. Cell array's data retained. */
#define CTRL_BIT_MEM_WPOFF_E4_FTC_RW_TPSRAM_TMCK          ((u32)0x00000001 << 13)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM */
#define CTRL_BIT_MEM_WPOFF_E4_FTC_RW_TPSRAM_WAE           ((u32)0x00000001 << 12)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM */
#define CTRL_MASK_MEM_WPOFF_E4_FTC_RW_TPSRAM_WAEM         ((u32)0x0000000F << 8)          /*!<R/W 0xA  FTC_ULP_RW_TPRAM */
#define CTRL_MEM_WPOFF_E4_FTC_RW_TPSRAM_WAEM(x)           ((u32)(((x) & 0x0000000F) << 8))
#define CTRL_GET_MEM_WPOFF_E4_FTC_RW_TPSRAM_WAEM(x)       ((u32)(((x >> 8) & 0x0000000F)))
#define CTRL_BIT_MEM_WPOFF_E4_FTC_RW_TPSRAM_RAE           ((u32)0x00000001 << 7)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM */
#define CTRL_MASK_MEM_WPOFF_E4_FTC_RW_TPSRAM_RAEM         ((u32)0x00000003 << 5)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM */
#define CTRL_MEM_WPOFF_E4_FTC_RW_TPSRAM_RAEM(x)           ((u32)(((x) & 0x00000003) << 5))
#define CTRL_GET_MEM_WPOFF_E4_FTC_RW_TPSRAM_RAEM(x)       ((u32)(((x >> 5) & 0x00000003)))
#define CTRL_BIT_MEM_WPOFF_E4_FTC_RW_TPSRAM_DVSE          ((u32)0x00000001 << 4)          /*!<R/W 0x0  FTC_ULP_RW_TPRAM */
#define CTRL_MASK_MEM_WPOFF_E4_FTC_RW_TPSRAM_DVS          ((u32)0x0000000F << 0)          /*!<R/W 0xA  FTC_ULP_RW_TPRAM */
#define CTRL_MEM_WPOFF_E4_FTC_RW_TPSRAM_DVS(x)            ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_WPOFF_E4_FTC_RW_TPSRAM_DVS(x)        ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_WPOFF_E5_FTC_ULP_TPSRAM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_WPOFF_E5_FTC_TPSRAM_SLP              ((u32)0x00000001 << 8)          /*!<R/W 0x0   */
#define CTRL_BIT_MEM_WPOFF_E5_FTC_TPSRAM_RET              ((u32)0x00000001 << 7)          /*!<R/W 0x0   */
#define CTRL_BIT_MEM_WPOFF_E5_FTC_TPSRAM_NAP              ((u32)0x00000001 << 6)          /*!<R/W 0x0   */
#define CTRL_BIT_MEM_WPOFF_E5_FTC_TPSRAM_TMCK             ((u32)0x00000001 << 5)          /*!<R/W 0x0  FTC_ULP_2P_RF */
#define CTRL_BIT_MEM_WPOFF_E5_FTC_TPSRAM_DVSE             ((u32)0x00000001 << 4)          /*!<R/W 0x0  FTC_ULP_2P_RF */
#define CTRL_MASK_MEM_WPOFF_E5_FTC_TPSRAM_DVS             ((u32)0x0000000F << 0)          /*!<R/W 0xA  FTC_ULP_2P_RF */
#define CTRL_MEM_WPOFF_E5_FTC_TPSRAM_DVS(x)               ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_WPOFF_E5_FTC_TPSRAM_DVS(x)           ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_WPON_E0_ARM_ULL_SRAM_PG_0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_PGEN             ((u32)0x00000001 << 16)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_RET2N            ((u32)0x00000001 << 15)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit1 */
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_RET1N            ((u32)0x00000001 << 14)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit0 */
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_STOV             ((u32)0x00000001 << 13)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating */
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_RAWLM_0P8       ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_RAWLM_0P8(x)         ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_RAWLM_0P8(x)     ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_RAWL_0P8         ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_WABLM_0P8       ((u32)0x00000007 << 7)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_WABLM_0P8(x)         ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_WABLM_0P8(x)     ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_WABL_0P8         ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_EMAS_0P8         ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_EMAW_0P8        ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_EMAW_0P8(x)          ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_EMAW_0P8(x)      ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_EMA_0P8         ((u32)0x00000007 << 0)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_EMA_0P8(x)           ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_EMA_0P8(x)       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_WPON_E0_ARM_ULL_SRAM_PG_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_RAWLM_1P0       ((u32)0x00000003 << 25)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_RAWLM_1P0(x)         ((u32)(((x) & 0x00000003) << 25))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_RAWLM_1P0(x)     ((u32)(((x >> 25) & 0x00000003)))
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_RAWL_1P0         ((u32)0x00000001 << 24)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_WABLM_1P0       ((u32)0x00000007 << 21)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_WABLM_1P0(x)         ((u32)(((x) & 0x00000007) << 21))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_WABLM_1P0(x)     ((u32)(((x >> 21) & 0x00000007)))
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_WABL_1P0         ((u32)0x00000001 << 20)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_EMAS_1P0         ((u32)0x00000001 << 19)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_EMAW_1P0        ((u32)0x00000003 << 17)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_EMAW_1P0(x)          ((u32)(((x) & 0x00000003) << 17))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_EMAW_1P0(x)      ((u32)(((x >> 17) & 0x00000003)))
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_EMA_1P0         ((u32)0x00000007 << 14)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_EMA_1P0(x)           ((u32)(((x) & 0x00000007) << 14))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_EMA_1P0(x)       ((u32)(((x >> 14) & 0x00000007)))
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_RAWLM_0P9       ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_RAWLM_0P9(x)         ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_RAWLM_0P9(x)     ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_RAWL_0P9         ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_WABLM_0P9       ((u32)0x00000007 << 7)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_WABLM_0P9(x)         ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_WABLM_0P9(x)     ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_WABL_0P9         ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_BIT_MEM_WPON_E0_ARM_SRAM_PG_EMAS_0P9         ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_EMAW_0P9        ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_EMAW_0P9(x)          ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_EMAW_0P9(x)      ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_WPON_E0_ARM_SRAM_PG_EMA_0P9         ((u32)0x00000007 << 0)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_WPON_E0_ARM_SRAM_PG_EMA_0P9(x)           ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_WPON_E0_ARM_SRAM_PG_EMA_0P9(x)       ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_HPER_E0_SNPS_ULP_SPRAM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_HPER_E0_SNPS_SPRAM_LS                ((u32)0x00000001 << 6)          /*!<R/W 0x0  SNPS_ULP_SPRAM: pg_b0 LS=1 ram is in light sleep mode, memory array's data retained. */
#define CTRL_BIT_MEM_HPER_E0_SNPS_SPRAM_TEST1             ((u32)0x00000001 << 5)          /*!<R/W 0x0  SNPS_ULP_SPRAM Test1 pin to bypass self-timed circuit. The external clock controls the read and write controls. The self time bypass mode occpuied High phase of external clock. The self time bypass mode may used to determine time margin of internal self-timed circuitry. */
#define CTRL_BIT_MEM_HPER_E0_SNPS_SPRAM_RME               ((u32)0x00000001 << 4)          /*!<R/W 0x0  SNPS_ULP_SPRAM RME selects between internal and external RM[2:0] settings, RM[3] is not controlled by RME. RME=1: select external RM[2:0] RME=0: select internal RM[2:0] */
#define CTRL_MASK_MEM_HPER_E0_SNPS_SPRAM_RM               ((u32)0x0000000F << 0)          /*!<R/W 0x2  SNPS_ULP_SPRAM RM[1:0] are used to trade-off betwwen speed and robustness(yield). 2'b11: fast 2'b10: default 2'b01: slow 2'b00: VDDmin RM[3:2] are used for test purpose. */
#define CTRL_MEM_HPER_E0_SNPS_SPRAM_RM(x)                 ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_HPER_E0_SNPS_SPRAM_RM(x)             ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_HPER_E1_SNPS_ULP_SPRAM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_HPER_E1_SNPS_SPRAM_LS                ((u32)0x00000001 << 6)          /*!<R/W 0x0  SNPS_ULP_SPRAM: pg_b0 LS=1 ram is in light sleep mode, memory array's data retained. */
#define CTRL_BIT_MEM_HPER_E1_SNPS_SPRAM_TEST1             ((u32)0x00000001 << 5)          /*!<R/W 0x0  SNPS_ULP_SPRAM Test1 pin to bypass self-timed circuit. The external clock controls the read and write controls. The self time bypass mode occpuied High phase of external clock. The self time bypass mode may used to determine time margin of internal self-timed circuitry. */
#define CTRL_BIT_MEM_HPER_E1_SNPS_SPRAM_RME               ((u32)0x00000001 << 4)          /*!<R/W 0x0  SNPS_ULP_SPRAM RME selects between internal and external RM[2:0] settings, RM[3] is not controlled by RME. RME=1: select external RM[2:0] RME=0: select internal RM[2:0] */
#define CTRL_MASK_MEM_HPER_E1_SNPS_SPRAM_RM               ((u32)0x0000000F << 0)          /*!<R/W 0x2  SNPS_ULP_SPRAM RM[1:0] are used to trade-off betwwen speed and robustness(yield). 2'b11: fast 2'b10: default 2'b01: slow 2'b00: VDDmin RM[3:2] are used for test purpose. */
#define CTRL_MEM_HPER_E1_SNPS_SPRAM_RM(x)                 ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_HPER_E1_SNPS_SPRAM_RM(x)             ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_HPER_E2_SNPS_ULP_TPSRAM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_HPER_E2_SNPS_TPSRAM_LS               ((u32)0x00000001 << 12)          /*!<R/W 0x0  SNPS_ULP_TPRAM: pg_b0 LS=1 ram is in light sleep mode, memory array's data retained. */
#define CTRL_BIT_MEM_HPER_E2_SNPS_TPSRAM_TEST1B           ((u32)0x00000001 << 11)          /*!<R/W 0x0  SNPS_ULP_TPRAM */
#define CTRL_BIT_MEM_HPER_E2_SNPS_TPSRAM_TEST1A           ((u32)0x00000001 << 10)          /*!<R/W 0x0  SNPS_ULP_TPRAM */
#define CTRL_BIT_MEM_HPER_E2_SNPS_TPSRAM_RMEB             ((u32)0x00000001 << 9)          /*!<R/W 0x0  SNPS_ULP_TPRAM */
#define CTRL_MASK_MEM_HPER_E2_SNPS_TPSRAM_RMB             ((u32)0x0000000F << 5)          /*!<R/W 0x2  SNPS_ULP_TPRAM */
#define CTRL_MEM_HPER_E2_SNPS_TPSRAM_RMB(x)               ((u32)(((x) & 0x0000000F) << 5))
#define CTRL_GET_MEM_HPER_E2_SNPS_TPSRAM_RMB(x)           ((u32)(((x >> 5) & 0x0000000F)))
#define CTRL_BIT_MEM_HPER_E2_SNPS_TPSRAM_RMEA             ((u32)0x00000001 << 4)          /*!<R/W 0x0  SNPS_ULP_TPRAM */
#define CTRL_MASK_MEM_HPER_E2_SNPS_TPSRAM_RMA             ((u32)0x0000000F << 0)          /*!<R/W 0x2  SNPS_ULP_TPRAM */
#define CTRL_MEM_HPER_E2_SNPS_TPSRAM_RMA(x)               ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_HPER_E2_SNPS_TPSRAM_RMA(x)           ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_HPER_E3_ARM_ULL_SRAM_0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_RET1N               ((u32)0x00000001 << 14)          /*!<R/W 0x1  ARM_ULL SPRAM: pg_b0 retention mode 1 enable, active Low. */
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_STOV                ((u32)0x00000001 << 13)          /*!<R/W 0x0  ARM_ULL SPRAM Self-timed pulse override, active high. RAM access normally when STOV=0. */
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_RAWLM_0P8          ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SPRAM Margin adjustment and delay for read assist: 00: No margin adjustment. This is the default and recommanded setting 01: Minimum margin adjustment with lowest negative boost level. 10: Intermediate margin adjustment setting wth medium level of read assist. 11: Highest margin adjustment with maximum level of read assist. */
#define CTRL_MEM_HPER_E3_ARM_SRAM_RAWLM_0P8(x)            ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_RAWLM_0P8(x)        ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_RAWL_0P8            ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SPRAM Read assist enable, active high. */
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_WABLM_0P8          ((u32)0x00000007 << 7)          /*!<R/W 3'b001  ARM_ULL SPRAM Margin adjustment and delay for write assist: 00: Minimum margin adjustment with lowest negative boost level. 01: Increased margin adjustment with more negatve boost. 10: Minimum boost level with increased delay for enabling write assist. 11: Increase margin adjustment, increased delay for enabling write assist. */
#define CTRL_MEM_HPER_E3_ARM_SRAM_WABLM_0P8(x)            ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_WABLM_0P8(x)        ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_WABL_0P8            ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SPRAM Write assist bitline VSS lowering enable, active high. */
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_EMAS_0P8            ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SPRAM Extra margin adjustment sense amplifier pulse. */
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_EMAW_0P8           ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SPRAM Extra margin adjustment for write operation. */
#define CTRL_MEM_HPER_E3_ARM_SRAM_EMAW_0P8(x)             ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_EMAW_0P8(x)         ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_EMA_0P8            ((u32)0x00000007 << 0)          /*!<R/W 3'b010  ARM_ULL SPRAM, Default value of 0.9v Extra margin adjustment. */
#define CTRL_MEM_HPER_E3_ARM_SRAM_EMA_0P8(x)              ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_EMA_0P8(x)          ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_HPER_E3_ARM_ULL_SRAM_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_RAWLM_1P0          ((u32)0x00000003 << 25)          /*!<R/W 2'b00  ARM_ULL SRAM, 1.0V */
#define CTRL_MEM_HPER_E3_ARM_SRAM_RAWLM_1P0(x)            ((u32)(((x) & 0x00000003) << 25))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_RAWLM_1P0(x)        ((u32)(((x >> 25) & 0x00000003)))
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_RAWL_1P0            ((u32)0x00000001 << 24)          /*!<R/W 1'b0  ARM_ULL SRAM, 1.0V */
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_WABLM_1P0          ((u32)0x00000007 << 21)          /*!<R/W 3'b000  ARM_ULL SRAM, 1.0V */
#define CTRL_MEM_HPER_E3_ARM_SRAM_WABLM_1P0(x)            ((u32)(((x) & 0x00000007) << 21))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_WABLM_1P0(x)        ((u32)(((x >> 21) & 0x00000007)))
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_WABL_1P0            ((u32)0x00000001 << 20)          /*!<R/W 1'b0  ARM_ULL SRAM, 1.0V */
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_EMAS_1P0            ((u32)0x00000001 << 19)          /*!<R/W 1'b0  ARM_ULL SRAM, 1.0V */
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_EMAW_1P0           ((u32)0x00000003 << 17)          /*!<R/W 2'b00  ARM_ULL SRAM, 1.0V */
#define CTRL_MEM_HPER_E3_ARM_SRAM_EMAW_1P0(x)             ((u32)(((x) & 0x00000003) << 17))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_EMAW_1P0(x)         ((u32)(((x >> 17) & 0x00000003)))
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_EMA_1P0            ((u32)0x00000007 << 14)          /*!<R/W 3'b010  ARM_ULL SRAM, 1.0V */
#define CTRL_MEM_HPER_E3_ARM_SRAM_EMA_1P0(x)              ((u32)(((x) & 0x00000007) << 14))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_EMA_1P0(x)          ((u32)(((x >> 14) & 0x00000007)))
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_RAWLM_0P9          ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM, 0.9V */
#define CTRL_MEM_HPER_E3_ARM_SRAM_RAWLM_0P9(x)            ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_RAWLM_0P9(x)        ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_RAWL_0P9            ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM, 0.9V */
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_WABLM_0P9          ((u32)0x00000007 << 7)          /*!<R/W 3'b000  ARM_ULL SRAM, 0.9V */
#define CTRL_MEM_HPER_E3_ARM_SRAM_WABLM_0P9(x)            ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_WABLM_0P9(x)        ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_WABL_0P9            ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM, 0.9V */
#define CTRL_BIT_MEM_HPER_E3_ARM_SRAM_EMAS_0P9            ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM, 0.9V */
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_EMAW_0P9           ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM, 0.9V */
#define CTRL_MEM_HPER_E3_ARM_SRAM_EMAW_0P9(x)             ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_EMAW_0P9(x)         ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_HPER_E3_ARM_SRAM_EMA_0P9            ((u32)0x00000007 << 0)          /*!<R/W 3'b001  ARM_ULL SRAM, 0.9V */
#define CTRL_MEM_HPER_E3_ARM_SRAM_EMA_0P9(x)              ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_HPER_E3_ARM_SRAM_EMA_0P9(x)          ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_BTONK4_E0_ARM_ULL_SRAM_PG_0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_PGEN           ((u32)0x00000001 << 16)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_RET2N          ((u32)0x00000001 << 15)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit1 */
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_RET1N          ((u32)0x00000001 << 14)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit0 */
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_STOV           ((u32)0x00000001 << 13)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating */
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_RAWLM_0P8     ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_RAWLM_0P8(x)       ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_RAWLM_0P8(x)   ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_RAWL_0P8       ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_WABLM_0P8     ((u32)0x00000007 << 7)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_WABLM_0P8(x)       ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_WABLM_0P8(x)   ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_WABL_0P8       ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_EMAS_0P8       ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_EMAW_0P8      ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_EMAW_0P8(x)        ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_EMAW_0P8(x)    ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_EMA_0P8       ((u32)0x00000007 << 0)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_EMA_0P8(x)         ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_EMA_0P8(x)     ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_BTONK4_E0_ARM_ULL_SRAM_PG_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_RAWLM_1P0     ((u32)0x00000003 << 25)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_RAWLM_1P0(x)       ((u32)(((x) & 0x00000003) << 25))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_RAWLM_1P0(x)   ((u32)(((x >> 25) & 0x00000003)))
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_RAWL_1P0       ((u32)0x00000001 << 24)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_WABLM_1P0     ((u32)0x00000007 << 21)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_WABLM_1P0(x)       ((u32)(((x) & 0x00000007) << 21))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_WABLM_1P0(x)   ((u32)(((x >> 21) & 0x00000007)))
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_WABL_1P0       ((u32)0x00000001 << 20)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_EMAS_1P0       ((u32)0x00000001 << 19)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_EMAW_1P0      ((u32)0x00000003 << 17)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_EMAW_1P0(x)        ((u32)(((x) & 0x00000003) << 17))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_EMAW_1P0(x)    ((u32)(((x >> 17) & 0x00000003)))
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_EMA_1P0       ((u32)0x00000007 << 14)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_EMA_1P0(x)         ((u32)(((x) & 0x00000007) << 14))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_EMA_1P0(x)     ((u32)(((x >> 14) & 0x00000007)))
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_RAWLM_0P9     ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_RAWLM_0P9(x)       ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_RAWLM_0P9(x)   ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_RAWL_0P9       ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_WABLM_0P9     ((u32)0x00000007 << 7)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_WABLM_0P9(x)       ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_WABLM_0P9(x)   ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_WABL_0P9       ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_BIT_MEM_BTONK4_E0_ARM_SRAM_PG_EMAS_0P9       ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_EMAW_0P9      ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_EMAW_0P9(x)        ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_EMAW_0P9(x)    ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_BTONK4_E0_ARM_SRAM_PG_EMA_0P9       ((u32)0x00000007 << 0)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_BTONK4_E0_ARM_SRAM_PG_EMA_0P9(x)         ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_BTONK4_E0_ARM_SRAM_PG_EMA_0P9(x)     ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_BTOFFK4_E0_ARM_ULL_SRAM_PG_0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_PGEN          ((u32)0x00000001 << 16)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating, PG bit2 */
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_RET2N         ((u32)0x00000001 << 15)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit1 */
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_RET1N         ((u32)0x00000001 << 14)          /*!<R/W 0x1  ARM_ULL SRAM With Power Gating, PG bit0 */
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_STOV          ((u32)0x00000001 << 13)          /*!<R/W 0x0  ARM_ULL SRAM With Power Gating */
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWLM_0P8    ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWLM_0P8(x)      ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWLM_0P8(x)  ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWL_0P8      ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABLM_0P8    ((u32)0x00000007 << 7)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABLM_0P8(x)      ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABLM_0P8(x)  ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABL_0P8      ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAS_0P8      ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAW_0P8     ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAW_0P8(x)       ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAW_0P8(x)   ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMA_0P8      ((u32)0x00000007 << 0)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 0.8V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMA_0P8(x)        ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMA_0P8(x)    ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_BTOFFK4_E0_ARM_ULL_SRAM_PG_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWLM_1P0    ((u32)0x00000003 << 25)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWLM_1P0(x)      ((u32)(((x) & 0x00000003) << 25))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWLM_1P0(x)  ((u32)(((x >> 25) & 0x00000003)))
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWL_1P0      ((u32)0x00000001 << 24)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABLM_1P0    ((u32)0x00000007 << 21)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABLM_1P0(x)      ((u32)(((x) & 0x00000007) << 21))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABLM_1P0(x)  ((u32)(((x >> 21) & 0x00000007)))
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABL_1P0      ((u32)0x00000001 << 20)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAS_1P0      ((u32)0x00000001 << 19)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAW_1P0     ((u32)0x00000003 << 17)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAW_1P0(x)       ((u32)(((x) & 0x00000003) << 17))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAW_1P0(x)   ((u32)(((x >> 17) & 0x00000003)))
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMA_1P0      ((u32)0x00000007 << 14)          /*!<R/W 3'b010  ARM_ULL SRAM With Power Gating, 1.0V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMA_1P0(x)        ((u32)(((x) & 0x00000007) << 14))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMA_1P0(x)    ((u32)(((x >> 14) & 0x00000007)))
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWLM_0P9    ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWLM_0P9(x)      ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWLM_0P9(x)  ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_RAWL_0P9      ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABLM_0P9    ((u32)0x00000007 << 7)          /*!<R/W 3'b000  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABLM_0P9(x)      ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABLM_0P9(x)  ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_WABL_0P9      ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_BIT_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAS_0P9      ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAW_0P9     ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAW_0P9(x)       ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMAW_0P9(x)   ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMA_0P9      ((u32)0x00000007 << 0)          /*!<R/W 3'b001  ARM_ULL SRAM With Power Gating, 0.9V */
#define CTRL_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMA_0P9(x)        ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_BTOFFK4_E0_ARM_SRAM_PG_EMA_0P9(x)    ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_DDRC_RRB_E0_FTC_ULP_TPSRAM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_DDRC_RRB_E0_FTC_TPSRAM_NAP           ((u32)0x00000001 << 6)          /*!<R/W 0x0  FTC_ULP_2P_RF: pg_b0 CSA(B)=1 & NAP=1 reduce peripheral power. Cell array's data retained. */
#define CTRL_BIT_MEM_DDRC_RRB_E0_FTC_TPSRAM_TMCK          ((u32)0x00000001 << 5)          /*!<R/W 0x0  FTC_ULP_2P_RF */
#define CTRL_BIT_MEM_DDRC_RRB_E0_FTC_TPSRAM_DVSE          ((u32)0x00000001 << 4)          /*!<R/W 0x0  FTC_ULP_2P_RF */
#define CTRL_MASK_MEM_DDRC_RRB_E0_FTC_TPSRAM_DVS          ((u32)0x0000000F << 0)          /*!<R/W 0xA  FTC_ULP_2P_RF */
#define CTRL_MEM_DDRC_RRB_E0_FTC_TPSRAM_DVS(x)            ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_DDRC_RRB_E0_FTC_TPSRAM_DVS(x)        ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_DDRC_BSTC_E0_SNPS_ULP_SPRAM
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_DDRC_BSTC_E0_SNPS_SPRAM_LS           ((u32)0x00000001 << 6)          /*!<R/W 0x0  SNPS_ULP_SPRAM: pg_b0 LS=1 ram is in light sleep mode, memory array's data retained. */
#define CTRL_BIT_MEM_DDRC_BSTC_E0_SNPS_SPRAM_TEST1        ((u32)0x00000001 << 5)          /*!<R/W 0x0  SNPS_ULP_SPRAM Test1 pin to bypass self-timed circuit. The external clock controls the read and write controls. The self time bypass mode occpuied High phase of external clock. The self time bypass mode may used to determine time margin of internal self-timed circuitry. */
#define CTRL_BIT_MEM_DDRC_BSTC_E0_SNPS_SPRAM_RME          ((u32)0x00000001 << 4)          /*!<R/W 0x0  SNPS_ULP_SPRAM RME selects between internal and external RM[2:0] settings, RM[3] is not controlled by RME. RME=1: select external RM[2:0] RME=0: select internal RM[2:0] */
#define CTRL_MASK_MEM_DDRC_BSTC_E0_SNPS_SPRAM_RM          ((u32)0x0000000F << 0)          /*!<R/W 0x2  SNPS_ULP_SPRAM RM[1:0] are used to trade: off betwwen speed and robustness(yield). 2'b11: fast 2'b10: default 2'b01: slow 2'b00: VDDmin RM[3:2] are used for test purpose. */
#define CTRL_MEM_DDRC_BSTC_E0_SNPS_SPRAM_RM(x)            ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_DDRC_BSTC_E0_SNPS_SPRAM_RM(x)        ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_CTRL_STAT
 * @brief MEMx MBIST control and status register
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_STA                          ((u32)0x0000001F << 16)          /*!<R 0x0  0: MBIST START_PAUSE 1: MBIST NRML_DONE 2: MBIST NRML_FAIL 3: MBIST DRF_DONE 4: MBIST DRF_FAIL */
#define CTRL_MEMX_MBIST_STA(x)                            ((u32)(((x) & 0x0000001F) << 16))
#define CTRL_GET_MEMX_MBIST_STA(x)                        ((u32)(((x >> 16) & 0x0000001F)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_GROUP_EN_0
 * @brief MEMx system memory group enable control register
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_HPER_E0_GRP_EN               ((u32)0x00000003 << 19)          /*!<R/W 0x3   */
#define CTRL_MEMX_MBIST_HPER_E0_GRP_EN(x)                 ((u32)(((x) & 0x00000003) << 19))
#define CTRL_GET_MEMX_MBIST_HPER_E0_GRP_EN(x)             ((u32)(((x >> 19) & 0x00000003)))
#define CTRL_MASK_MEMX_MBIST_WPOFF_E1_GRP_EN              ((u32)0x0000001F << 14)          /*!<R/W 0x1f   */
#define CTRL_MEMX_MBIST_WPOFF_E1_GRP_EN(x)                ((u32)(((x) & 0x0000001F) << 14))
#define CTRL_GET_MEMX_MBIST_WPOFF_E1_GRP_EN(x)            ((u32)(((x >> 14) & 0x0000001F)))
#define CTRL_MASK_MEMX_MBIST_WPOFF_E0_GRP_EN              ((u32)0x00000003 << 12)          /*!<R/W 0x3   */
#define CTRL_MEMX_MBIST_WPOFF_E0_GRP_EN(x)                ((u32)(((x) & 0x00000003) << 12))
#define CTRL_GET_MEMX_MBIST_WPOFF_E0_GRP_EN(x)            ((u32)(((x >> 12) & 0x00000003)))
#define CTRL_MASK_MEMX_MBIST_WLK4_E0_GRP_EN               ((u32)0x00000003 << 10)          /*!<R/W 0x3   */
#define CTRL_MEMX_MBIST_WLK4_E0_GRP_EN(x)                 ((u32)(((x) & 0x00000003) << 10))
#define CTRL_GET_MEMX_MBIST_WLK4_E0_GRP_EN(x)             ((u32)(((x >> 10) & 0x00000003)))
#define CTRL_MASK_MEMX_MBIST_LSYS_E0_GRP_EN               ((u32)0x00000003 << 8)          /*!<R/W 0x3   */
#define CTRL_MEMX_MBIST_LSYS_E0_GRP_EN(x)                 ((u32)(((x) & 0x00000003) << 8))
#define CTRL_GET_MEMX_MBIST_LSYS_E0_GRP_EN(x)             ((u32)(((x >> 8) & 0x00000003)))
#define CTRL_MASK_MEMX_MBIST_HSYS_E0_GRP_EN               ((u32)0x000000FF << 0)          /*!<R/W 0xff  Note: group with only 1 memory don't have group_enable TPRAM group don't have group_enable */
#define CTRL_MEMX_MBIST_HSYS_E0_GRP_EN(x)                 ((u32)(((x) & 0x000000FF) << 0))
#define CTRL_GET_MEMX_MBIST_HSYS_E0_GRP_EN(x)             ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_GROUP_EN_1
 * @brief MEMx system meory group enable control register
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_DDRC_BSTC_E0_GRP_EN          ((u32)0x000000FF << 9)          /*!<R/W 0xff   */
#define CTRL_MEMX_MBIST_DDRC_BSTC_E0_GRP_EN(x)            ((u32)(((x) & 0x000000FF) << 9))
#define CTRL_GET_MEMX_MBIST_DDRC_BSTC_E0_GRP_EN(x)        ((u32)(((x >> 9) & 0x000000FF)))
#define CTRL_MASK_MEMX_MBIST_BTOFFK4_E0_GRP_EN            ((u32)0x00000003 << 7)          /*!<R/W 0x3   */
#define CTRL_MEMX_MBIST_BTOFFK4_E0_GRP_EN(x)              ((u32)(((x) & 0x00000003) << 7))
#define CTRL_GET_MEMX_MBIST_BTOFFK4_E0_GRP_EN(x)          ((u32)(((x >> 7) & 0x00000003)))
#define CTRL_MASK_MEMX_MBIST_BTONK4_E0_GRP_EN             ((u32)0x0000000F << 3)          /*!<R/W 0xf   */
#define CTRL_MEMX_MBIST_BTONK4_E0_GRP_EN(x)               ((u32)(((x) & 0x0000000F) << 3))
#define CTRL_GET_MEMX_MBIST_BTONK4_E0_GRP_EN(x)           ((u32)(((x >> 3) & 0x0000000F)))
#define CTRL_MASK_MEMX_MBIST_HPER_E1_GRP_EN               ((u32)0x00000007 << 0)          /*!<R/W 0x7   */
#define CTRL_MEMX_MBIST_HPER_E1_GRP_EN(x)                 ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEMX_MBIST_HPER_E1_GRP_EN(x)             ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_RSTB
 * @brief MEMx MBIST reset control register
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_RSTB                         ((u32)0x03FFFFFF << 0)          /*!<R/W 0x3ffffff  mbist reset of each group: system memory group - 22 special group - bt_e0, km0_e0, km4_e0, mipic_e0 */
#define CTRL_MEMX_MBIST_RSTB(x)                           ((u32)(((x) & 0x03FFFFFF) << 0))
#define CTRL_GET_MEMX_MBIST_RSTB(x)                       ((u32)(((x >> 0) & 0x03FFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_MSEL_0
 * @brief MEMx MBIST method select register control bit[31:0]
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_MSEL_31_0                    ((u32)0xFFFFFFFF << 0)          /*!<R/W 0xffffffff  if MEMX_MBIST_MSEL_ALL select normal, and MEMX_MBIST_MSEL[BIT_0_MBIST_MSEL_groupx] is 1, normal mode of groupx is selected; if MEMX_MBIST_MSEL_ALL select drf, and MEMX_MBIST_MSEL[BIT_1_MBIST_MSEL_groupx] is 1, drf mode of groupx is selected; */
#define CTRL_MEMX_MBIST_MSEL_31_0(x)                      ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEMX_MBIST_MSEL_31_0(x)                  ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_MSEL_1
 * @brief MEMx MBIST method select control register bit[51:32]
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_MSEL_51_32                   ((u32)0x000FFFFF << 0)          /*!<R/W 0xfffff  if MEMX_MBIST_MSEL_ALL selects normal, and MEMX_MBIST_MSEL[BIT_0_MBIST_MSEL_groupx] is 1, normal mode of groupx is selected; if MEMX_MBIST_MSEL_ALL selects drf, and MEMX_MBIST_MSEL[BIT_1_MBIST_MSEL_groupx] is 1, drf mode of groupx is selected; */
#define CTRL_MEMX_MBIST_MSEL_51_32(x)                     ((u32)(((x) & 0x000FFFFF) << 0))
#define CTRL_GET_MEMX_MBIST_MSEL_51_32(x)                 ((u32)(((x >> 0) & 0x000FFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_LOOP_MODE
 * @brief MEMx MBIST loop mode controlregister
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_LOOP_MODE                    ((u32)0x03FFFFFF << 0)          /*!<R/W 0x0  mbist loop mode of each group. */
#define CTRL_MEMX_MBIST_LOOP_MODE(x)                      ((u32)(((x) & 0x03FFFFFF) << 0))
#define CTRL_GET_MEMX_MBIST_LOOP_MODE(x)                  ((u32)(((x >> 0) & 0x03FFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_START_PAUSE_STAT
 * @brief MEMx mbist start pause status register
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_START_PAUSE_STAT             ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEMX_MBIST_START_PAUSE_STAT(x)               ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEMX_MBIST_START_PAUSE_STAT(x)           ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_DONE_STAT
 * @brief MEMx MBIST done status register
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_DONE_STAT                    ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEMX_MBIST_DONE_STAT(x)                      ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEMX_MBIST_DONE_STAT(x)                  ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_FAIL_NRML_STAT_0
 * @brief MEMx MBIST fail status register bit[31:0]
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_FAIL_NRML_STAT_31_0          ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEMX_MBIST_FAIL_NRML_STAT_31_0(x)            ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEMX_MBIST_FAIL_NRML_STAT_31_0(x)        ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_FAIL_NRML_STAT_1
 * @brief MEMx MBIST fail status register bit[63:32]
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_FAIL_NRML_STAT_63_32         ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEMX_MBIST_FAIL_NRML_STAT_63_32(x)           ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEMX_MBIST_FAIL_NRML_STAT_63_32(x)       ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_FAIL_DRF_STAT_0
 * @brief MEMx drf mbist fail status register bit[31:0]
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_FAIL_DRF_STAT_31_0           ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEMX_MBIST_FAIL_DRF_STAT_31_0(x)             ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEMX_MBIST_FAIL_DRF_STAT_31_0(x)         ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEMX_MBIST_FAIL_DRF_STAT_1
 * @brief MEMx drf mbist fail status register bit[63:32]
 * @{
 **/
#define CTRL_MASK_MEMX_MBIST_FAIL_DRF_STAT_63_32          ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEMX_MBIST_FAIL_DRF_STAT_63_32(x)            ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEMX_MBIST_FAIL_DRF_STAT_63_32(x)        ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_ROM_LSPMC_E0_MISR_DOUT_0
 * @brief lspmc_e0 ROM mbist misr_dout[31:0]
 * @{
 **/
#define CTRL_MASK_ROM_LSPMC_E0_MISR_DOUT_31_0             ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_ROM_LSPMC_E0_MISR_DOUT_31_0(x)               ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_ROM_LSPMC_E0_MISR_DOUT_31_0(x)           ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_ROM_LSPMC_E0_MISR_DOUT_1
 * @brief lspmc_e0 ROM mbist misr_dout[35:32]
 * @{
 **/
#define CTRL_MASK_ROM_LSPMC_E0_MISR_DOUT_35_32            ((u32)0x0000000F << 0)          /*!<R 0x0   */
#define CTRL_ROM_LSPMC_E0_MISR_DOUT_35_32(x)              ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_ROM_LSPMC_E0_MISR_DOUT_35_32(x)          ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_ROM_AONPMC_E0_MISR_DOUT_0
 * @brief aonpmc_e0 ROM mbist misr_dout[31:0]
 * @{
 **/
#define CTRL_MASK_ROM_AONPMC_E0_MISR_DOUT_31_0            ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_ROM_AONPMC_E0_MISR_DOUT_31_0(x)              ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_ROM_AONPMC_E0_MISR_DOUT_31_0(x)          ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_ROM_AONPMC_E0_MISR_DOUT_1
 * @brief aonpmc_e0 ROM mbist misr_dout[35:32]
 * @{
 **/
#define CTRL_MASK_ROM_AONPMC_E0_MISR_DOUT_35_32           ((u32)0x0000000F << 0)          /*!<R 0x0   */
#define CTRL_ROM_AONPMC_E0_MISR_DOUT_35_32(x)             ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_ROM_AONPMC_E0_MISR_DOUT_35_32(x)         ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_ROM_CA7BOOT_E0_MISR_DOUT_0
 * @brief catboot_e0 ROM mbist misr_dout[31:0]
 * @{
 **/
#define CTRL_MASK_ROM_CA7BOOT_E0_MISR_DOUT_31_0           ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_ROM_CA7BOOT_E0_MISR_DOUT_31_0(x)             ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_ROM_CA7BOOT_E0_MISR_DOUT_31_0(x)         ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_ROM_CA7BOOT_E0_MISR_DOUT_1
 * @brief catboot_e0 ROM mbist misr_dout[63:32]
 * @{
 **/
#define CTRL_MASK_ROM_CA7BOOT_E0_MISR_DOUT_63_32          ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_ROM_CA7BOOT_E0_MISR_DOUT_63_32(x)            ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_ROM_CA7BOOT_E0_MISR_DOUT_63_32(x)        ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_DCACHE_DATA_ARM_ULL_SRAM_0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_KM0_ARM_SRAM_RET1N_ALL               ((u32)0x00000001 << 14)          /*!<R/W 0x1  for all km0 memory retention mode 1 enable, active Low. */
#define CTRL_BIT_MEM_KM0_ARM_SRAM_STOV_ALL                ((u32)0x00000001 << 13)          /*!<R/W 0x0  for all km0 memory Self-timed pulse override, active high. RAM access normally when STOV=0. */
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWLM_0P8  ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SPRAM Margin adjustment and delay for read assist: 00-No margin adjustment. This is the default and recommanded setting 01-Minimum margin adjustment with lowest negative boost level. 10-Intermediate margin adjustment setting wth medium level of read assist. 11-Highest margin adjustment with maximum level of read assist. */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWLM_0P8(x)    ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWLM_0P8(x) ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWL_0P8    ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SPRAM Read assist enable, active high. */
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABLM_0P8  ((u32)0x00000007 << 7)          /*!<R/W 3'b001  ARM_ULL SPRAM Margin adjustment and delay for write assist: 00-Minimum margin adjustment with lowest negative boost level. 01-Increased margin adjustment with more negatve boost. 10-Minimum boost level with increased delay for enabling write assist. 11-Increase margin adjustment, increased delay for enabling write assist. */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABLM_0P8(x)    ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABLM_0P8(x) ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABL_0P8    ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SPRAM Write assist bitline VSS lowering enable, active high. */
#define CTRL_BIT_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAS_0P8    ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SPRAM Extra margin adjustment sense amplifier pulse. */
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAW_0P8   ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SPRAM Extra margin adjustment for write operation. */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAW_0P8(x)     ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAW_0P8(x) ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMA_0P8    ((u32)0x00000007 << 0)          /*!<R/W 3'b010  ARM_ULL SPRAM, Default value of 0.9v Extra margin adjustment. */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMA_0P8(x)      ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMA_0P8(x)  ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_DCACHE_DATA_ARM_ULL_SRAM_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWLM_1P0  ((u32)0x00000003 << 25)          /*!<R/W 2'b00  ARM_ULL SRAM , 1.0v */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWLM_1P0(x)    ((u32)(((x) & 0x00000003) << 25))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWLM_1P0(x) ((u32)(((x >> 25) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWL_1P0    ((u32)0x00000001 << 24)          /*!<R/W 1'b0  ARM_ULL SRAM , 1.0v */
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABLM_1P0  ((u32)0x00000007 << 21)          /*!<R/W 3'b000  ARM_ULL SRAM , 1.0v */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABLM_1P0(x)    ((u32)(((x) & 0x00000007) << 21))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABLM_1P0(x) ((u32)(((x >> 21) & 0x00000007)))
#define CTRL_BIT_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABL_1P0    ((u32)0x00000001 << 20)          /*!<R/W 1'b0  ARM_ULL SRAM , 1.0v */
#define CTRL_BIT_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAS_1P0    ((u32)0x00000001 << 19)          /*!<R/W 1'b0  ARM_ULL SRAM , 1.0v */
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAW_1P0   ((u32)0x00000003 << 17)          /*!<R/W 2'b00  ARM_ULL SRAM , 1.0v */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAW_1P0(x)     ((u32)(((x) & 0x00000003) << 17))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAW_1P0(x) ((u32)(((x >> 17) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMA_1P0    ((u32)0x00000007 << 14)          /*!<R/W 3'b010  ARM_ULL SRAM , 1.0v */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMA_1P0(x)      ((u32)(((x) & 0x00000007) << 14))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMA_1P0(x)  ((u32)(((x >> 14) & 0x00000007)))
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWLM_0P9  ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM , 0.9v */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWLM_0P9(x)    ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWLM_0P9(x) ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_DCACHE_DATA_ARM_SRAM_RAWL_0P9    ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM , 0.9v */
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABLM_0P9  ((u32)0x00000007 << 7)          /*!<R/W 3'b000  ARM_ULL SRAM , 0.9v */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABLM_0P9(x)    ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABLM_0P9(x) ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_KM0_DCACHE_DATA_ARM_SRAM_WABL_0P9    ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM , 0.9v */
#define CTRL_BIT_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAS_0P9    ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM , 0.9v */
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAW_0P9   ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM , 0.9v */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAW_0P9(x)     ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMAW_0P9(x) ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMA_0P9    ((u32)0x00000007 << 0)          /*!<R/W 3'b001  ARM_ULL SRAM , 0.9v */
#define CTRL_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMA_0P9(x)      ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_KM0_DCACHE_DATA_ARM_SRAM_EMA_0P9(x)  ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_DCACHE_TAG_ARM_ULL_RF_0
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_RAWLM_0P8     ((u32)0x00000003 << 10)          /*!<R/W 2'b00  ARM_ULL SPRAM Margin adjustment and delay for read assist: 00-No margin adjustment. This is the default and recommanded setting 01-Minimum margin adjustment with lowest negative boost level. 10-Intermediate margin adjustment setting wth medium level of read assist. 11-Highest margin adjustment with maximum level of read assist. */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_RAWLM_0P8(x)       ((u32)(((x) & 0x00000003) << 10))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_RAWLM_0P8(x)   ((u32)(((x >> 10) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_DCACHE_TAG_ARM_RF_RAWL_0P8       ((u32)0x00000001 << 9)          /*!<R/W 1'b0  ARM_ULL SPRAM Read assist enable, active high. */
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_WABLM_0P8     ((u32)0x00000003 << 7)          /*!<R/W 2'b01  ARM_ULL SPRAM Margin adjustment and delay for write assist: 00-Minimum margin adjustment with lowest negative boost level. 01-Increased margin adjustment with more negatve boost. 10-Minimum boost level with increased delay for enabling write assist. 11-Increase margin adjustment, increased delay for enabling write assist. */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_WABLM_0P8(x)       ((u32)(((x) & 0x00000003) << 7))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_WABLM_0P8(x)   ((u32)(((x >> 7) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_DCACHE_TAG_ARM_RF_WABL_0P8       ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SPRAM Write assist bitline VSS lowering enable, active high. */
#define CTRL_BIT_MEM_KM0_DCACHE_TAG_ARM_RF_EMAS_0P8       ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SPRAM Extra margin adjustment sense amplifier pulse. */
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_EMAW_0P8      ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SPRAM Extra margin adjustment for write operation. */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_EMAW_0P8(x)        ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_EMAW_0P8(x)    ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_EMA_0P8       ((u32)0x00000007 << 0)          /*!<R/W 3'b100  ARM_ULL SPRAM, Default value of 0.8v Extra margin adjustment. */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_EMA_0P8(x)         ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_EMA_0P8(x)     ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_DCACHE_TAG_ARM_ULL_RF_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_RAWLM_1P0     ((u32)0x00000003 << 22)          /*!<R/W 2'b0  ARM_ULL RF , 1.0V */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_RAWLM_1P0(x)       ((u32)(((x) & 0x00000003) << 22))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_RAWLM_1P0(x)   ((u32)(((x >> 22) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_DCACHE_TAG_ARM_RF_RAWL_1P0       ((u32)0x00000001 << 21)          /*!<R/W 1'b0  ARM_ULL RF , 1.0V */
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_WABLM_1P0     ((u32)0x00000003 << 19)          /*!<R/W 2'b0  ARM_ULL RF , 1.0V */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_WABLM_1P0(x)       ((u32)(((x) & 0x00000003) << 19))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_WABLM_1P0(x)   ((u32)(((x >> 19) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_DCACHE_TAG_ARM_RF_WABL_1P0       ((u32)0x00000001 << 18)          /*!<R/W 1'b0  ARM_ULL RF , 1.0V */
#define CTRL_BIT_MEM_KM0_DCACHE_TAG_ARM_RF_EMAS_1P0       ((u32)0x00000001 << 17)          /*!<R/W 1'b0  ARM_ULL RF , 1.0V */
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_EMAW_1P0      ((u32)0x00000003 << 15)          /*!<R/W 2'b01  ARM_ULL RF , 1.0V */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_EMAW_1P0(x)        ((u32)(((x) & 0x00000003) << 15))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_EMAW_1P0(x)    ((u32)(((x >> 15) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_EMA_1P0       ((u32)0x00000007 << 12)          /*!<R/W 3'b011  ARM_ULL RF , 1.0V */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_EMA_1P0(x)         ((u32)(((x) & 0x00000007) << 12))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_EMA_1P0(x)     ((u32)(((x >> 12) & 0x00000007)))
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_RAWLM_0P9     ((u32)0x00000003 << 10)          /*!<R/W 2'b00  ARM_ULL RF 0.9V */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_RAWLM_0P9(x)       ((u32)(((x) & 0x00000003) << 10))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_RAWLM_0P9(x)   ((u32)(((x >> 10) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_DCACHE_TAG_ARM_RF_RAWL_0P9       ((u32)0x00000001 << 9)          /*!<R/W 1'b0  ARM_ULL RF 0.9V */
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_WABLM_0P9     ((u32)0x00000003 << 7)          /*!<R/W 2'b00  ARM_ULL RF 0.9V */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_WABLM_0P9(x)       ((u32)(((x) & 0x00000003) << 7))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_WABLM_0P9(x)   ((u32)(((x >> 7) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_DCACHE_TAG_ARM_RF_WABL_0P9       ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL RF 0.9V */
#define CTRL_BIT_MEM_KM0_DCACHE_TAG_ARM_RF_EMAS_0P9       ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL RF 0.9V */
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_EMAW_0P9      ((u32)0x00000003 << 3)          /*!<R/W 2'b01  ARM_ULL RF 0.9V */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_EMAW_0P9(x)        ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_EMAW_0P9(x)    ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_DCACHE_TAG_ARM_RF_EMA_0P9       ((u32)0x00000007 << 0)          /*!<R/W 3'b011  ARM_ULL RF 0.9V */
#define CTRL_MEM_KM0_DCACHE_TAG_ARM_RF_EMA_0P9(x)         ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_KM0_DCACHE_TAG_ARM_RF_EMA_0P9(x)     ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_ICACHE_DATA_ARM_ULL_SRAM_0
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWLM_0P8  ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SPRAM Margin adjustment and delay for read assist: 00-No margin adjustment. This is the default and recommanded setting 01-Minimum margin adjustment with lowest negative boost level. 10-Intermediate margin adjustment setting wth medium level of read assist. 11-Highest margin adjustment with maximum level of read assist. */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWLM_0P8(x)    ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWLM_0P8(x) ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWL_0P8    ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SPRAM Read assist enable, active high. */
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABLM_0P8  ((u32)0x00000007 << 7)          /*!<R/W 3'b001  ARM_ULL SPRAM Margin adjustment and delay for write assist: 00-Minimum margin adjustment with lowest negative boost level. 01-Increased margin adjustment with more negatve boost. 10-Minimum boost level with increased delay for enabling write assist. 11-Increase margin adjustment, increased delay for enabling write assist. */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABLM_0P8(x)    ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABLM_0P8(x) ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABL_0P8    ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SPRAM Write assist bitline VSS lowering enable, active high. */
#define CTRL_BIT_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAS_0P8    ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SPRAM Extra margin adjustment sense amplifier pulse. */
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAW_0P8   ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SPRAM Extra margin adjustment for write operation. */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAW_0P8(x)     ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAW_0P8(x) ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMA_0P8    ((u32)0x00000007 << 0)          /*!<R/W 3'b010  ARM_ULL SPRAM, Default value of 0.9v Extra margin adjustment. */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMA_0P8(x)      ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMA_0P8(x)  ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_ICACHE_DATA_ARM_ULL_SRAM_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWLM_1P0  ((u32)0x00000003 << 25)          /*!<R/W 2'b00  ARM_ULL SRAM , 1.0v */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWLM_1P0(x)    ((u32)(((x) & 0x00000003) << 25))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWLM_1P0(x) ((u32)(((x >> 25) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWL_1P0    ((u32)0x00000001 << 24)          /*!<R/W 1'b0  ARM_ULL SRAM , 1.0v */
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABLM_1P0  ((u32)0x00000007 << 21)          /*!<R/W 3'b000  ARM_ULL SRAM , 1.0v */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABLM_1P0(x)    ((u32)(((x) & 0x00000007) << 21))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABLM_1P0(x) ((u32)(((x >> 21) & 0x00000007)))
#define CTRL_BIT_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABL_1P0    ((u32)0x00000001 << 20)          /*!<R/W 1'b0  ARM_ULL SRAM , 1.0v */
#define CTRL_BIT_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAS_1P0    ((u32)0x00000001 << 19)          /*!<R/W 1'b0  ARM_ULL SRAM , 1.0v */
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAW_1P0   ((u32)0x00000003 << 17)          /*!<R/W 2'b00  ARM_ULL SRAM , 1.0v */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAW_1P0(x)     ((u32)(((x) & 0x00000003) << 17))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAW_1P0(x) ((u32)(((x >> 17) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMA_1P0    ((u32)0x00000007 << 14)          /*!<R/W 3'b010  ARM_ULL SRAM , 1.0v */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMA_1P0(x)      ((u32)(((x) & 0x00000007) << 14))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMA_1P0(x)  ((u32)(((x >> 14) & 0x00000007)))
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWLM_0P9  ((u32)0x00000003 << 11)          /*!<R/W 2'b00  ARM_ULL SRAM , 0.9v */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWLM_0P9(x)    ((u32)(((x) & 0x00000003) << 11))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWLM_0P9(x) ((u32)(((x >> 11) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_ICACHE_DATA_ARM_SRAM_RAWL_0P9    ((u32)0x00000001 << 10)          /*!<R/W 1'b1  ARM_ULL SRAM , 0.9v */
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABLM_0P9  ((u32)0x00000007 << 7)          /*!<R/W 3'b000  ARM_ULL SRAM , 0.9v */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABLM_0P9(x)    ((u32)(((x) & 0x00000007) << 7))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABLM_0P9(x) ((u32)(((x >> 7) & 0x00000007)))
#define CTRL_BIT_MEM_KM0_ICACHE_DATA_ARM_SRAM_WABL_0P9    ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL SRAM , 0.9v */
#define CTRL_BIT_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAS_0P9    ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL SRAM , 0.9v */
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAW_0P9   ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL SRAM , 0.9v */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAW_0P9(x)     ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMAW_0P9(x) ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMA_0P9    ((u32)0x00000007 << 0)          /*!<R/W 3'b001  ARM_ULL SRAM , 0.9v */
#define CTRL_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMA_0P9(x)      ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_KM0_ICACHE_DATA_ARM_SRAM_EMA_0P9(x)  ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_ICACHE_TAG_ARM_ULL_RF_0
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_RAWLM_0P8     ((u32)0x00000003 << 10)          /*!<R/W 2'b00  ARM_ULL RF , 0.8V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_RAWLM_0P8(x)       ((u32)(((x) & 0x00000003) << 10))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_RAWLM_0P8(x)   ((u32)(((x >> 10) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_ICACHE_TAG_ARM_RF_RAWL_0P8       ((u32)0x00000001 << 9)          /*!<R/W 1'b0  ARM_ULL RF , 0.8V */
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_WABLM_0P8     ((u32)0x00000003 << 7)          /*!<R/W 2'b01  ARM_ULL RF , 0.8V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_WABLM_0P8(x)       ((u32)(((x) & 0x00000003) << 7))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_WABLM_0P8(x)   ((u32)(((x >> 7) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_ICACHE_TAG_ARM_RF_WABL_0P8       ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL RF , 0.8V */
#define CTRL_BIT_MEM_KM0_ICACHE_TAG_ARM_RF_EMAS_0P8       ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL RF , 0.8V */
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_EMAW_0P8      ((u32)0x00000003 << 3)          /*!<R/W 2'b00  ARM_ULL RF , 0.8V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_EMAW_0P8(x)        ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_EMAW_0P8(x)    ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_EMA_0P8       ((u32)0x00000007 << 0)          /*!<R/W 3'b100  ARM_ULL RF , 0.8V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_EMA_0P8(x)         ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_EMA_0P8(x)     ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_ICACHE_TAG_ARM_ULL_RF_1
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_RAWLM_1P0     ((u32)0x00000003 << 22)          /*!<R/W 2'b0  ARM_ULL RF , 1.0V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_RAWLM_1P0(x)       ((u32)(((x) & 0x00000003) << 22))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_RAWLM_1P0(x)   ((u32)(((x >> 22) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_ICACHE_TAG_ARM_RF_RAWL_1P0       ((u32)0x00000001 << 21)          /*!<R/W 1'b0  ARM_ULL RF , 1.0V */
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_WABLM_1P0     ((u32)0x00000003 << 19)          /*!<R/W 2'b0  ARM_ULL RF , 1.0V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_WABLM_1P0(x)       ((u32)(((x) & 0x00000003) << 19))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_WABLM_1P0(x)   ((u32)(((x >> 19) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_ICACHE_TAG_ARM_RF_WABL_1P0       ((u32)0x00000001 << 18)          /*!<R/W 1'b0  ARM_ULL RF , 1.0V */
#define CTRL_BIT_MEM_KM0_ICACHE_TAG_ARM_RF_EMAS_1P0       ((u32)0x00000001 << 17)          /*!<R/W 1'b0  ARM_ULL RF , 1.0V */
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_EMAW_1P0      ((u32)0x00000003 << 15)          /*!<R/W 2'b01  ARM_ULL RF , 1.0V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_EMAW_1P0(x)        ((u32)(((x) & 0x00000003) << 15))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_EMAW_1P0(x)    ((u32)(((x >> 15) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_EMA_1P0       ((u32)0x00000007 << 12)          /*!<R/W 3'b011  ARM_ULL RF , 1.0V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_EMA_1P0(x)         ((u32)(((x) & 0x00000007) << 12))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_EMA_1P0(x)     ((u32)(((x >> 12) & 0x00000007)))
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_RAWLM_0P9     ((u32)0x00000003 << 10)          /*!<R/W 2'b00  ARM_ULL RF 0.9V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_RAWLM_0P9(x)       ((u32)(((x) & 0x00000003) << 10))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_RAWLM_0P9(x)   ((u32)(((x >> 10) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_ICACHE_TAG_ARM_RF_RAWL_0P9       ((u32)0x00000001 << 9)          /*!<R/W 1'b0  ARM_ULL RF 0.9V */
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_WABLM_0P9     ((u32)0x00000003 << 7)          /*!<R/W 2'b00  ARM_ULL RF 0.9V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_WABLM_0P9(x)       ((u32)(((x) & 0x00000003) << 7))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_WABLM_0P9(x)   ((u32)(((x >> 7) & 0x00000003)))
#define CTRL_BIT_MEM_KM0_ICACHE_TAG_ARM_RF_WABL_0P9       ((u32)0x00000001 << 6)          /*!<R/W 1'b1  ARM_ULL RF 0.9V */
#define CTRL_BIT_MEM_KM0_ICACHE_TAG_ARM_RF_EMAS_0P9       ((u32)0x00000001 << 5)          /*!<R/W 1'b0  ARM_ULL RF 0.9V */
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_EMAW_0P9      ((u32)0x00000003 << 3)          /*!<R/W 2'b01  ARM_ULL RF 0.9V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_EMAW_0P9(x)        ((u32)(((x) & 0x00000003) << 3))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_EMAW_0P9(x)    ((u32)(((x >> 3) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_ICACHE_TAG_ARM_RF_EMA_0P9       ((u32)0x00000007 << 0)          /*!<R/W 3'b011  ARM_ULL RF 0.9V */
#define CTRL_MEM_KM0_ICACHE_TAG_ARM_RF_EMA_0P9(x)         ((u32)(((x) & 0x00000007) << 0))
#define CTRL_GET_MEM_KM0_ICACHE_TAG_ARM_RF_EMA_0P9(x)     ((u32)(((x >> 0) & 0x00000007)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_FTC_ULP_ROM
 * @brief KM0 itcm and dtcm parameter register
 * @{
 **/
#define CTRL_BIT_MEM_KM0_FTC_ROM_DVSE                     ((u32)0x00000001 << 4)          /*!<R/W 0x0  for all rom memory */
#define CTRL_MASK_MEM_KM0_FTC_ROM_DVS                     ((u32)0x0000000F << 0)          /*!<R/W 0x5  for all rom memory */
#define CTRL_MEM_KM0_FTC_ROM_DVS(x)                       ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_KM0_FTC_ROM_DVS(x)                   ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_BIST_CTRL
 * @brief KM0 memory bist control register
 * @{
 **/
#define CTRL_MASK_MEM_KM0_RPT_SEL                         ((u32)0x0000000F << 8)          /*!<R/W 0x0  select rom misr_dataout */
#define CTRL_MEM_KM0_RPT_SEL(x)                           ((u32)(((x) & 0x0000000F) << 8))
#define CTRL_GET_MEM_KM0_RPT_SEL(x)                       ((u32)(((x >> 8) & 0x0000000F)))
#define CTRL_MASK_MEM_KM0_ITCM_E0_GRP_EN                  ((u32)0x00000007 << 4)          /*!<R/W 0x7  group enable of itcm_e0 */
#define CTRL_MEM_KM0_ITCM_E0_GRP_EN(x)                    ((u32)(((x) & 0x00000007) << 4))
#define CTRL_GET_MEM_KM0_ITCM_E0_GRP_EN(x)                ((u32)(((x >> 4) & 0x00000007)))
#define CTRL_MASK_MEM_KM0_ICACHE_E0_GRP_EN                ((u32)0x00000003 << 2)          /*!<R/W 0x3  group enable of icache_e0 */
#define CTRL_MEM_KM0_ICACHE_E0_GRP_EN(x)                  ((u32)(((x) & 0x00000003) << 2))
#define CTRL_GET_MEM_KM0_ICACHE_E0_GRP_EN(x)              ((u32)(((x >> 2) & 0x00000003)))
#define CTRL_MASK_MEM_KM0_DCACHE_E0_GRP_EN                ((u32)0x00000003 << 0)          /*!<R/W 0x3  group enable of dcache_e0 */
#define CTRL_MEM_KM0_DCACHE_E0_GRP_EN(x)                  ((u32)(((x) & 0x00000003) << 0))
#define CTRL_GET_MEM_KM0_DCACHE_E0_GRP_EN(x)              ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM0_BIST_RPT
 * @brief KM0 memory bist report register
 * @{
 **/
#define CTRL_MASK_MEM_KM0_BIST_RPT                        ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEM_KM0_BIST_RPT(x)                          ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEM_KM0_BIST_RPT(x)                      ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM4_PARAM
 * @brief parameter for km4 memory
 * @{
 **/
#define CTRL_BIT_MEM_KM4_LS_ALL                           ((u32)0x00000001 << 12)          /*!<R/W 0x0  LS for all km4 memory. LS=1 ram is in light sleep mode, memory array's data retained. */
#define CTRL_BIT_MEM_KM4_TEST1_ALL                        ((u32)0x00000001 << 11)          /*!<R/W 0x0  Test1 pin to bypass self-timed circuit. The external clock controls the read and write controls. The self time bypass mode occpuied High phase of external clock. The self time bypass mode may used to determine time margin of internal self-timed circuitry. */
#define CTRL_BIT_MEM_KM4_RME_ALL                          ((u32)0x00000001 << 10)          /*!<R/W 0x0  RME for all km4 memory. RME selects between internal and external RM[2:0] settings, RM[3] is not controlled by RME. RME=1: select external RM[2:0] RME=0: select internal RM[2:0] */
#define CTRL_MASK_MEM_KM4_RM32_ALL                        ((u32)0x00000003 << 8)          /*!<R/W 0x0  RM32 for all km4 memory. RM[3:2] are used for test purpose. */
#define CTRL_MEM_KM4_RM32_ALL(x)                          ((u32)(((x) & 0x00000003) << 8))
#define CTRL_GET_MEM_KM4_RM32_ALL(x)                      ((u32)(((x >> 8) & 0x00000003)))
#define CTRL_MASK_MEM_KM4_ITCM_E0_SPROM_RM10              ((u32)0x00000003 << 6)          /*!<R/W 0x2  SNPS_ULP_SPROM, for KM4 itcm0~7 : RM[1:0] are used to trade-off betwwen speed and robustness(yield). 2'b11 - fast 2'b10 - default 2'b01 - slow 2'b00 - VDDmin RM[3:2] are used for test purpose. */
#define CTRL_MEM_KM4_ITCM_E0_SPROM_RM10(x)                ((u32)(((x) & 0x00000003) << 6))
#define CTRL_GET_MEM_KM4_ITCM_E0_SPROM_RM10(x)            ((u32)(((x >> 6) & 0x00000003)))
#define CTRL_MASK_MEM_KM4_DTCM_E0_SPROM_RM10              ((u32)0x00000003 << 4)          /*!<R/W 0x2  SNPS_ULP_SPROM, for KM4 dtcm0~2 : RM[1:0] are used to trade-off betwwen speed and robustness(yield). 2'b11 - fast 2'b10 - default 2'b01 - slow 2'b00 - VDDmin RM[3:2] are used for test purpose. */
#define CTRL_MEM_KM4_DTCM_E0_SPROM_RM10(x)                ((u32)(((x) & 0x00000003) << 4))
#define CTRL_GET_MEM_KM4_DTCM_E0_SPROM_RM10(x)            ((u32)(((x >> 4) & 0x00000003)))
#define CTRL_MASK_MEM_KM4_ICACHE_E0_SPRAM_RM10            ((u32)0x00000003 << 2)          /*!<R/W 0x2  SNPS_ULP_SPRAM RM[1:0] are used to trade-off betwwen speed and robustness(yield). 2'b11 - fast 2'b10 - default 2'b01 - slow 2'b00 - VDDmin RM[3:2] are used for test purpose. */
#define CTRL_MEM_KM4_ICACHE_E0_SPRAM_RM10(x)              ((u32)(((x) & 0x00000003) << 2))
#define CTRL_GET_MEM_KM4_ICACHE_E0_SPRAM_RM10(x)          ((u32)(((x >> 2) & 0x00000003)))
#define CTRL_MASK_MEM_KM4_DCACHE_E0_SPRAM_RM10            ((u32)0x00000003 << 0)          /*!<R/W 0x2  SNPS_ULP_SPRAM RM[1:0] are used to trade-off betwwen speed and robustness(yield). 2'b11 - fast 2'b10 - default 2'b01 - slow 2'b00 - VDDmin RM[3:2] are used for test purpose. */
#define CTRL_MEM_KM4_DCACHE_E0_SPRAM_RM10(x)              ((u32)(((x) & 0x00000003) << 0))
#define CTRL_GET_MEM_KM4_DCACHE_E0_SPRAM_RM10(x)          ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM4_BIST_CTRL
 * @brief KM4 memory bist control register
 * @{
 **/
#define CTRL_MASK_MEM_KM4_RPT_SEL                         ((u32)0x0000001F << 15)          /*!<R/W 0x0  select rom misr_dataout */
#define CTRL_MEM_KM4_RPT_SEL(x)                           ((u32)(((x) & 0x0000001F) << 15))
#define CTRL_GET_MEM_KM4_RPT_SEL(x)                       ((u32)(((x >> 15) & 0x0000001F)))
#define CTRL_MASK_MEM_KM4_ITCM_E0_GRP_EN                  ((u32)0x000000FF << 7)          /*!<R/W 0xff  group enable of itcm_e0 */
#define CTRL_MEM_KM4_ITCM_E0_GRP_EN(x)                    ((u32)(((x) & 0x000000FF) << 7))
#define CTRL_GET_MEM_KM4_ITCM_E0_GRP_EN(x)                ((u32)(((x >> 7) & 0x000000FF)))
#define CTRL_MASK_MEM_KM4_DTCM_E0_GRP_EN                  ((u32)0x00000007 << 4)          /*!<R/W 0x7  group enable of dtcm_e0 */
#define CTRL_MEM_KM4_DTCM_E0_GRP_EN(x)                    ((u32)(((x) & 0x00000007) << 4))
#define CTRL_GET_MEM_KM4_DTCM_E0_GRP_EN(x)                ((u32)(((x >> 4) & 0x00000007)))
#define CTRL_MASK_MEM_KM4_ICACHE_E0_GRP_EN                ((u32)0x00000003 << 2)          /*!<R/W 0x3  group enable of icache_e0 */
#define CTRL_MEM_KM4_ICACHE_E0_GRP_EN(x)                  ((u32)(((x) & 0x00000003) << 2))
#define CTRL_GET_MEM_KM4_ICACHE_E0_GRP_EN(x)              ((u32)(((x >> 2) & 0x00000003)))
#define CTRL_MASK_MEM_KM4_DCACHE_E0_GRP_EN                ((u32)0x00000003 << 0)          /*!<R/W 0x3  group enable of dcache_e0 */
#define CTRL_MEM_KM4_DCACHE_E0_GRP_EN(x)                  ((u32)(((x) & 0x00000003) << 0))
#define CTRL_GET_MEM_KM4_DCACHE_E0_GRP_EN(x)              ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_CTRL_MEM_KM4_BIST_RPT
 * @brief KM4 memory bist report register
 * @{
 **/
#define CTRL_MASK_MEM_KM4_BIST_RPT                        ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEM_KM4_BIST_RPT(x)                          ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEM_KM4_BIST_RPT(x)                      ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEM_BT_BIST_CTRL
 * @brief BT mbist control of BT
 * @{
 **/
#define CTRL_MASK_MEM_BT_RPT_SEL                          ((u32)0x0000000F << 20)          /*!<R/W 0x0   */
#define CTRL_MEM_BT_RPT_SEL(x)                            ((u32)(((x) & 0x0000000F) << 20))
#define CTRL_GET_MEM_BT_RPT_SEL(x)                        ((u32)(((x >> 20) & 0x0000000F)))
#define CTRL_BIT_MEM_BT_MEM_DS                            ((u32)0x00000001 << 18)          /*!<R/W 0x0   */
#define CTRL_BIT_MEM_BT_LVDRF_CLKDIS                      ((u32)0x00000001 << 17)          /*!<R/W 0x0   */
#define CTRL_BIT_MEM_BT_LOOP_MODE                         ((u32)0x00000001 << 16)          /*!<R/W 0x0   */
#define CTRL_MASK_MEM_BT_CELL_EN                          ((u32)0x000000FF << 8)          /*!<R/W 0xff   */
#define CTRL_MEM_BT_CELL_EN(x)                            ((u32)(((x) & 0x000000FF) << 8))
#define CTRL_GET_MEM_BT_CELL_EN(x)                        ((u32)(((x >> 8) & 0x000000FF)))
#define CTRL_MASK_MEM_BT_GRP_SEL                          ((u32)0x0000000F << 0)          /*!<R/W 0xf   */
#define CTRL_MEM_BT_GRP_SEL(x)                            ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_BT_GRP_SEL(x)                        ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_BT_BIST_RPT
 * @brief BT mbist report
 * @{
 **/
#define CTRL_MASK_MEM_BT_BIST_RPT                         ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEM_BT_BIST_RPT(x)                           ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEM_BT_BIST_RPT(x)                       ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEM_BT_BIST_DONE
 * @brief BT mbist done
 * @{
 **/
#define CTRL_MASK_MEM_BT_BIST_DONE                        ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEM_BT_BIST_DONE(x)                          ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEM_BT_BIST_DONE(x)                      ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEM_BT_BIST_FAIL
 * @brief BT mbist fail
 * @{
 **/
#define CTRL_MASK_MEM_BT_BIST_FAIL                        ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEM_BT_BIST_FAIL(x)                          ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEM_BT_BIST_FAIL(x)                      ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEM_BT_BIST_DRF_PAUSE
 * @brief BT mbist drf start pause
 * @{
 **/
#define CTRL_MASK_MEM_BT_BIST_DRF_PAUSE                   ((u32)0xFFFFFFFF << 0)          /*!<R 0x0   */
#define CTRL_MEM_BT_BIST_DRF_PAUSE(x)                     ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CTRL_GET_MEM_BT_BIST_DRF_PAUSE(x)                 ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup REG_CTRL_MEM_BT_FTC_ULP_1PRF0
 * @brief
 * @{
 **/
#define CTRL_BIT_MEM_BT_ROM_DVSE                          ((u32)0x00000001 << 20)          /*!<R/W 0x0  connect to r_MEM_RME_ROM of BT. DVSE=1: delay option enable. DVSE=0: delay option disable. */
#define CTRL_MASK_MEM_BT_ROM_DVS                          ((u32)0x0000000F << 16)          /*!<R/W 0x2  connect to r_MEM_RM_ROM of BT. DVS[0] controls the SRAM sensing pulse when DVSE=1. DVS[0]=1: short pulse width DVS[0]=0: long pulse width dvs[3:1] is delay option control words when DVSE=1. DVS[3:1] = 000: loosest margin. DVS[3:1] = 001 DVS[3:1] = 010 DVS[3:1] = 011 … */
#define CTRL_MEM_BT_ROM_DVS(x)                            ((u32)(((x) & 0x0000000F) << 16))
#define CTRL_GET_MEM_BT_ROM_DVS(x)                        ((u32)(((x >> 16) & 0x0000000F)))
#define CTRL_BIT_MEM_BT_1PSR_DVSE                         ((u32)0x00000001 << 15)          /*!<R/W 0x0  connect to r_MEM_RME_1PSR of BT. DVSE=1: delay option enable. DVSE=0: delay option disable. */
#define CTRL_MASK_MEM_BT_1PSR_DVS                         ((u32)0x0000000F << 11)          /*!<R/W 0x2  connect to r_MEM_RM_1PSR of BT. DVS[0] controls the SRAM sensing pulse when DVSE=1. DVS[0]=1: short pulse width DVS[0]=0: long pulse width dvs[3:1] is delay option control words when DVSE=1. DVS[3:1] = 000: loosest margin. DVS[3:1] = 001 DVS[3:1] = 010 DVS[3:1] = 011 … */
#define CTRL_MEM_BT_1PSR_DVS(x)                           ((u32)(((x) & 0x0000000F) << 11))
#define CTRL_GET_MEM_BT_1PSR_DVS(x)                       ((u32)(((x >> 11) & 0x0000000F)))
#define CTRL_BIT_MEM_BT_1PRF1_DVSE                        ((u32)0x00000001 << 10)          /*!<R/W 0x0  connect to r_MEM_RME_1PRF1 of BT. DVSE=1: delay option enable. DVSE=0: delay option disable. */
#define CTRL_MASK_MEM_BT_1PRF1_DVS                        ((u32)0x0000000F << 6)          /*!<R/W 0x2  connect to r_MEM_RM_1PRF1 of BT. DVS[0] controls the SRAM sensing pulse when DVSE=1. DVS[0]=1: short pulse width DVS[0]=0: long pulse width dvs[3:1] is delay option control words when DVSE=1. DVS[3:1] = 000: loosest margin. DVS[3:1] = 001 DVS[3:1] = 010 DVS[3:1] = 011 … */
#define CTRL_MEM_BT_1PRF1_DVS(x)                          ((u32)(((x) & 0x0000000F) << 6))
#define CTRL_GET_MEM_BT_1PRF1_DVS(x)                      ((u32)(((x >> 6) & 0x0000000F)))
#define CTRL_BIT_MEM_BT_TMCK_ALL                          ((u32)0x00000001 << 5)          /*!<R/W 0x0  connect to r_TEST1 of BT. Internal timing bypass signal. TMCK=1: WL pulse will be controlled by the clock duty cycle. TMCK=0: default value, RAM access normally. */
#define CTRL_BIT_MEM_BT_1PRF0_DVSE                        ((u32)0x00000001 << 4)          /*!<R/W 0x0  connect to r_MEM_RME_1PRF0 of BT. DVSE=1: delay option enable. DVSE=0: delay option disable. */
#define CTRL_MASK_MEM_BT_1PRF0_DVS                        ((u32)0x0000000F << 0)          /*!<R/W 0x2  connect to r_MEM_RM_1PRF0 of BT. DVS[0] controls the SRAM sensing pulse when DVSE=1. DVS[0]=1: short pulse width DVS[0]=0: long pulse width dvs[3:1] is delay option control words when DVSE=1. DVS[3:1] = 000: loosest margin. DVS[3:1] = 001 DVS[3:1] = 010 DVS[3:1] = 011 … */
#define CTRL_MEM_BT_1PRF0_DVS(x)                          ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_BT_1PRF0_DVS(x)                      ((u32)(((x >> 0) & 0x0000000F)))
/** @} */

/** @defgroup REG_CTRL_MEM_MIPI_FTC_2PRAM
 * @brief
 * @{
 **/
#define CTRL_MASK_MEM_MIPI_2PRAM_DVS                      ((u32)0x0000000F << 0)          /*!<R/W 4'b1111  *.ds */
#define CTRL_MEM_MIPI_2PRAM_DVS(x)                        ((u32)(((x) & 0x0000000F) << 0))
#define CTRL_GET_MEM_MIPI_2PRAM_DVS(x)                    ((u32)(((x >> 0) & 0x0000000F)))
#define CTRL_BIT_MEM_MIPI_2PRAM_DVSE                      ((u32)0x00000001 << 4)          /*!<R/W 1'b0   */
#define CTRL_BIT_MEM_MIPI_2PRAM_TMCKA                     ((u32)0x00000001 << 5)          /*!<R/W 1'b0   */
#define CTRL_BIT_MEM_MIPI_2PRAM_TMCKB                     ((u32)0x00000001 << 6)          /*!<R/W 1'b0   */
#define CTRL_BIT_MEM_MIPI_2PRAM_NAP                       ((u32)0x00000001 << 7)          /*!<R/W 1'b0   */
#define CTRL_BIT_MEM_MIPI_2PRAM_RET                       ((u32)0x00000001 << 8)          /*!<R/W 1'b0   */
#define CTRL_BIT_MEM_MIPI_2PRAM_SLP                       ((u32)0x00000001 << 9)          /*!<R/W 1'b0   */
#define CTRL_MASK_MBIST_MIPI_GRP_EN                       ((u32)0x00000003 << 16)          /*!<R/W 2'b11  [0]-vide0 memory mbist enable [1]-cmd memory mbist enable */
#define CTRL_MBIST_MIPI_GRP_EN(x)                         ((u32)(((x) & 0x00000003) << 16))
#define CTRL_GET_MBIST_MIPI_GRP_EN(x)                     ((u32)(((x >> 16) & 0x00000003)))
#define CTRL_MASK_MBIST_MIPI_RPT                          ((u32)0x000003FF << 18)          /*!<R 10'h0  {cmd_drf_start_pause,cmd_mbist_drf_fail,cmd_mbist_fail,cmd_mbist_drf_done,cmd_mbist_done, vedio_drf_start_pause,video_mbist_drf_fail,video_mbist_fail,video_mbist_drf_done,video_mbist_done} */
#define CTRL_MBIST_MIPI_RPT(x)                            ((u32)(((x) & 0x000003FF) << 18))
#define CTRL_GET_MBIST_MIPI_RPT(x)                        ((u32)(((x >> 18) & 0x000003FF)))
/** @} */

/** @defgroup REG_CTRL_SCAN_CTRL1
 * @brief
 * @{
 **/
#define CTRL_BIT_SCAN_PLL_CTRL_MIPI                       ((u32)0x00000001 << 23)          /*!<R/W 0x0  scan pll ctrl mipi */
#define CTRL_BIT_SCAN_PLL_CTRL_USB                        ((u32)0x00000001 << 22)          /*!<R/W 0x0  scan pll ctrl usb */
#define CTRL_MASK_SCAN_OCC_DBG_EN_DPLL                    ((u32)0x00000003 << 20)          /*!<R/W 0x0  scan occ dbg en dpll */
#define CTRL_SCAN_OCC_DBG_EN_DPLL(x)                      ((u32)(((x) & 0x00000003) << 20))
#define CTRL_GET_SCAN_OCC_DBG_EN_DPLL(x)                  ((u32)(((x >> 20) & 0x00000003)))
#define CTRL_MASK_SCAN_OCC_DBG_EN_MIPI                    ((u32)0x00000003 << 18)          /*!<R/W 0x0  scan occ dbg en mipi */
#define CTRL_SCAN_OCC_DBG_EN_MIPI(x)                      ((u32)(((x) & 0x00000003) << 18))
#define CTRL_GET_SCAN_OCC_DBG_EN_MIPI(x)                  ((u32)(((x >> 18) & 0x00000003)))
#define CTRL_MASK_SCAN_OCC_DBG_EN_USB                     ((u32)0x00000003 << 16)          /*!<R/W 0x0  scan occ dbg en usb */
#define CTRL_SCAN_OCC_DBG_EN_USB(x)                       ((u32)(((x) & 0x00000003) << 16))
#define CTRL_GET_SCAN_OCC_DBG_EN_USB(x)                   ((u32)(((x >> 16) & 0x00000003)))
#define CTRL_MASK_SCAN_OCC_DBG_EN_AP                      ((u32)0x00000003 << 14)          /*!<R/W 0x0  scan occ dbg en ap */
#define CTRL_SCAN_OCC_DBG_EN_AP(x)                        ((u32)(((x) & 0x00000003) << 14))
#define CTRL_GET_SCAN_OCC_DBG_EN_AP(x)                    ((u32)(((x >> 14) & 0x00000003)))
#define CTRL_MASK_SCAN_OCC_DBG_EN_SDH                     ((u32)0x00000003 << 12)          /*!<R/W 0x0  scan occ dbg en sdh */
#define CTRL_SCAN_OCC_DBG_EN_SDH(x)                       ((u32)(((x) & 0x00000003) << 12))
#define CTRL_GET_SCAN_OCC_DBG_EN_SDH(x)                   ((u32)(((x >> 12) & 0x00000003)))
#define CTRL_MASK_SCAN_OCC_DBG_EN_SEC                     ((u32)0x00000003 << 10)          /*!<R/W 0x0  scan occ dbg en sec */
#define CTRL_SCAN_OCC_DBG_EN_SEC(x)                       ((u32)(((x) & 0x00000003) << 10))
#define CTRL_GET_SCAN_OCC_DBG_EN_SEC(x)                   ((u32)(((x >> 10) & 0x00000003)))
#define CTRL_MASK_SCAN_OCC_DBG_EN_PSRAM                   ((u32)0x00000003 << 8)          /*!<R/W 0x0  scan occ dbg en psram */
#define CTRL_SCAN_OCC_DBG_EN_PSRAM(x)                     ((u32)(((x) & 0x00000003) << 8))
#define CTRL_GET_SCAN_OCC_DBG_EN_PSRAM(x)                 ((u32)(((x >> 8) & 0x00000003)))
#define CTRL_MASK_SCAN_OCC_DBG_EN_SPIC                    ((u32)0x00000003 << 6)          /*!<R/W 0x0  scan occ dbg en spic */
#define CTRL_SCAN_OCC_DBG_EN_SPIC(x)                      ((u32)(((x) & 0x00000003) << 6))
#define CTRL_GET_SCAN_OCC_DBG_EN_SPIC(x)                  ((u32)(((x >> 6) & 0x00000003)))
#define CTRL_MASK_SCAN_OCC_DBG_EN_HPERI                   ((u32)0x00000003 << 4)          /*!<R/W 0x0  scan occ dbg en hperi */
#define CTRL_SCAN_OCC_DBG_EN_HPERI(x)                     ((u32)(((x) & 0x00000003) << 4))
#define CTRL_GET_SCAN_OCC_DBG_EN_HPERI(x)                 ((u32)(((x >> 4) & 0x00000003)))
#define CTRL_MASK_SCAN_OCC_DBG_EN_HBUS                    ((u32)0x00000003 << 2)          /*!<R/W 0x0  scan occ dbg en hbus */
#define CTRL_SCAN_OCC_DBG_EN_HBUS(x)                      ((u32)(((x) & 0x00000003) << 2))
#define CTRL_GET_SCAN_OCC_DBG_EN_HBUS(x)                  ((u32)(((x >> 2) & 0x00000003)))
#define CTRL_MASK_SCAN_OCC_DBG_EN_NP                      ((u32)0x00000003 << 0)          /*!<R/W 0x0  scan occ dbg en np */
#define CTRL_SCAN_OCC_DBG_EN_NP(x)                        ((u32)(((x) & 0x00000003) << 0))
#define CTRL_GET_SCAN_OCC_DBG_EN_NP(x)                    ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup REG_CTRL_SCAN_CTRL0
 * @brief
 * @{
 **/
#define CTRL_BIT_SCAN_RET_EN                              ((u32)0x00000001 << 19)          /*!<   scan retention test enable */
#define CTRL_MASK_SCAN_PLL_OUT_SEL                        ((u32)0x00000007 << 16)          /*!<R/W 0x0  scan pll out sel: 2'b000: nppll out 2'b001: wlpll out 2'b010: appll out 2'b011: usb0 pll out 2'b100: usb1 pll out 2'b101: mipi pll out 2'b110: dpll out */
#define CTRL_SCAN_PLL_OUT_SEL(x)                          ((u32)(((x) & 0x00000007) << 16))
#define CTRL_GET_SCAN_PLL_OUT_SEL(x)                      ((u32)(((x >> 16) & 0x00000007)))
#define CTRL_BIT_SCAN_CFT4                                ((u32)0x00000001 << 15)          /*!<R/W 0x0  scan QFN68 package ft mode4 */
#define CTRL_BIT_SCAN_CFT3                                ((u32)0x00000001 << 14)          /*!<R/W 0x0  scan QFN68 package ft mode3 */
#define CTRL_BIT_SCAN_CFT2                                ((u32)0x00000001 << 13)          /*!<R/W 0x0  scan QFN68 package ft mode2 */
#define CTRL_BIT_SCAN_CFT1                                ((u32)0x00000001 << 12)          /*!<R/W 0x0  scan QFN68 package ft mode1 */
#define CTRL_BIT_SCAN_CFT0                                ((u32)0x00000001 << 11)          /*!<R/W 0x0  scan QFN68 package ft mode0 */
#define CTRL_BIT_SCAN_BFT1                                ((u32)0x00000001 << 10)          /*!<R/W 0x0  scan QFN128 NON-MCM package ft mode1 */
#define CTRL_BIT_SCAN_BFT0                                ((u32)0x00000001 << 9)          /*!<R/W 0x0  scan QFN128 NON-MCM package ft mode0 */
#define CTRL_BIT_SCAN_AFT1                                ((u32)0x00000001 << 8)          /*!<R/W 0x0  scan QFN128 MCM package ft mode1 */
#define CTRL_BIT_SCAN_AFT0                                ((u32)0x00000001 << 7)          /*!<R/W 0x0  scan QFN128 MCM package ft mode0 */
#define CTRL_BIT_SCAN_CP1                                 ((u32)0x00000001 << 6)          /*!<R/W 0x0  scan cp mode1 */
#define CTRL_BIT_SCAN_CP0                                 ((u32)0x00000001 << 5)          /*!<R/W 0x0  scan cp mode0 */
#define CTRL_BIT_SCAN_SPC_DISABLE                         ((u32)0x00000001 << 4)          /*!<R/W 0x0  scan spc disable */
#define CTRL_BIT_SCAN_PLL_BYPASS                          ((u32)0x00000001 << 3)          /*!<R/W 0x0  scan pll bypass */
#define CTRL_BIT_SCAN_COMPRESS                            ((u32)0x00000001 << 2)          /*!<R/W 0x0  scan compress */
#define CTRL_BIT_SCAN_PAR_LATPS                           ((u32)0x00000001 << 1)          /*!<WA0 0x0  scan latch up pulse */
#define CTRL_BIT_SCAN_MODE                                ((u32)0x00000001 << 0)          /*!<WA0 0x0  scan mode pulse */
/** @} */


/*==========MEM_CTRL Register Address Definition==========*/
#define REG_CTRL_MEM_AONPMC_E0_FTC_ULP_ROM           0x0000
#define REG_CTRL_MEM_LRET_E0_ARM_ULL_RF_PG_0         0x0004
#define REG_CTRL_MEM_LRET_E0_ARM_ULL_RF_PG_1         0x0008
#define REG_CTRL_MEM_LSYS_E0_ARM_ULL_SRAM_PG_0       0x000C
#define REG_CTRL_MEM_LSYS_E0_ARM_ULL_SRAM_PG_1       0x0010
#define REG_CTRL_MEM_LSPMC_E0_FTC_ULP_ROM            0x0014
#define REG_CTRL_MEM_HSYS_E0_ARM_ULL_SRAM_PG_0       0x0018
#define REG_CTRL_MEM_HSYS_E0_ARM_ULL_SRAM_PG_1       0x001C
#define REG_CTRL_MEM_CA7BOOT_E0_FTC_ROM              0x0020
#define REG_CTRL_MEM_WLK4_E0_ARM_ULL_SRAM_PG_0       0x0024
#define REG_CTRL_MEM_WLK4_E0_ARM_ULL_SRAM_PG_1       0x0028
#define REG_CTRL_MEM_WPOFF_E0_ARM_ULL_RF_PG_0        0x002C
#define REG_CTRL_MEM_WPOFF_E0_ARM_ULL_RF_PG_1        0x0030
#define REG_CTRL_MEM_WPOFF_E1_FTC_ULP_RW             0x0034
#define REG_CTRL_MEM_WPOFF_E2_FTC_ULP_RW_TPRAM       0x0038
#define REG_CTRL_MEM_WPOFF_E3_FTC_ULP_RW             0x003C
#define REG_CTRL_MEM_WPOFF_E4_FTC_ULP_RW_TPSRAM      0x0040
#define REG_CTRL_MEM_WPOFF_E5_FTC_ULP_TPSRAM         0x0044
#define REG_CTRL_MEM_WPON_E0_ARM_ULL_SRAM_PG_0       0x0048
#define REG_CTRL_MEM_WPON_E0_ARM_ULL_SRAM_PG_1       0x004C
#define REG_CTRL_MEM_HPER_E0_SNPS_ULP_SPRAM          0x0050
#define REG_CTRL_MEM_HPER_E1_SNPS_ULP_SPRAM          0x0054
#define REG_CTRL_MEM_HPER_E2_SNPS_ULP_TPSRAM         0x0058
#define REG_CTRL_MEM_HPER_E3_ARM_ULL_SRAM_0          0x005C
#define REG_CTRL_MEM_HPER_E3_ARM_ULL_SRAM_1          0x0060
#define REG_CTRL_MEM_BTONK4_E0_ARM_ULL_SRAM_PG_0     0x0064
#define REG_CTRL_MEM_BTONK4_E0_ARM_ULL_SRAM_PG_1     0x0068
#define REG_CTRL_MEM_BTOFFK4_E0_ARM_ULL_SRAM_PG_0    0x006C
#define REG_CTRL_MEM_BTOFFK4_E0_ARM_ULL_SRAM_PG_1    0x0070
#define REG_CTRL_MEM_DDRC_RRB_E0_FTC_ULP_TPSRAM      0x0074
#define REG_CTRL_MEM_DDRC_BSTC_E0_SNPS_ULP_SPRAM     0x0078
#define REG_CTRL_MEMX_MBIST_CTRL_STAT                0x007C
#define REG_CTRL_MEMX_MBIST_GROUP_EN_0               0x0080
#define REG_CTRL_MEMX_MBIST_GROUP_EN_1               0x0084
#define REG_CTRL_MEMX_MBIST_RSTB                     0x0088
#define REG_CTRL_MEMX_MBIST_MSEL_0                   0x008C
#define REG_CTRL_MEMX_MBIST_MSEL_1                   0x0090
#define REG_CTRL_MEMX_MBIST_LOOP_MODE                0x0094
#define REG_CTRL_MEMX_MBIST_START_PAUSE_STAT         0x0098
#define REG_CTRL_MEMX_MBIST_DONE_STAT                0x009C
#define REG_CTRL_MEMX_MBIST_FAIL_NRML_STAT_0         0x00A0
#define REG_CTRL_MEMX_MBIST_FAIL_NRML_STAT_1         0x00A4
#define REG_CTRL_MEMX_MBIST_FAIL_DRF_STAT_0          0x00A8
#define REG_CTRL_MEMX_MBIST_FAIL_DRF_STAT_1          0x00AC
#define REG_CTRL_ROM_LSPMC_E0_MISR_DOUT_0            0x00B0
#define REG_CTRL_ROM_LSPMC_E0_MISR_DOUT_1            0x00B4
#define REG_CTRL_ROM_AONPMC_E0_MISR_DOUT_0           0x00B8
#define REG_CTRL_ROM_AONPMC_E0_MISR_DOUT_1           0x00BC
#define REG_CTRL_ROM_CA7BOOT_E0_MISR_DOUT_0          0x00C0
#define REG_CTRL_ROM_CA7BOOT_E0_MISR_DOUT_1          0x00C4
#define REG_CTRL_MEM_KM0_DCACHE_DATA_ARM_ULL_SRAM_0  0x00C8
#define REG_CTRL_MEM_KM0_DCACHE_DATA_ARM_ULL_SRAM_1  0x00CC
#define REG_CTRL_MEM_KM0_DCACHE_TAG_ARM_ULL_RF_0     0x00D0
#define REG_CTRL_MEM_KM0_DCACHE_TAG_ARM_ULL_RF_1     0x00D4
#define REG_CTRL_MEM_KM0_ICACHE_DATA_ARM_ULL_SRAM_0  0x00D8
#define REG_CTRL_MEM_KM0_ICACHE_DATA_ARM_ULL_SRAM_1  0x00DC
#define REG_CTRL_MEM_KM0_ICACHE_TAG_ARM_ULL_RF_0     0x00E0
#define REG_CTRL_MEM_KM0_ICACHE_TAG_ARM_ULL_RF_1     0x00E4
#define REG_CTRL_MEM_KM0_FTC_ULP_ROM                 0x00E8
#define REG_CTRL_MEM_KM0_BIST_CTRL                   0x00EC
#define REG_CTRL_MEM_KM0_BIST_RPT                    0x00F0
#define REG_CTRL_MEM_KM4_PARAM                       0x00F4
#define REG_CTRL_MEM_KM4_BIST_CTRL                   0x00F8
#define REG_CTRL_MEM_KM4_BIST_RPT                    0x00FC
#define REG_CTRL_MEM_BT_BIST_CTRL                    0x0100
#define REG_CTRL_MEM_BT_BIST_RPT                     0x0104
#define REG_CTRL_MEM_BT_BIST_DONE                    0x0108
#define REG_CTRL_MEM_BT_BIST_FAIL                    0x010C
#define REG_CTRL_MEM_BT_BIST_DRF_PAUSE               0x0110
#define REG_CTRL_MEM_BT_FTC_ULP_1PRF0                0x0114
#define REG_CTRL_MEM_MIPI_FTC_2PRAM                  0x0118
#define REG_CTRL_SCAN_CTRL1                          0x0130
#define REG_CTRL_SCAN_CTRL0                          0x0134

/** @} */

/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your defination here
#define SYSTEM_MEM_CTRL_BASE     0x42009100

/* MANUAL_GEN_END */

#endif

/** @} */

/** @} */
