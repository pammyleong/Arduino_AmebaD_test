#ifndef _AMEBAD2_CA7_H_
#define _AMEBAD2_CA7_H_

/* AUTO_GEN_START */

/** @addtogroup Ameba_Periph_Driver
  * @{
  */

/** @defgroup CA7
* @{
*/

/* Registers Definitions --------------------------------------------------------*/

/** @defgroup CA7_Register_Definitions CA7 Register Definitions
 * @{
 *****************************************************************************/

/** @defgroup CA7_C0_MISC_CTRL
 * @brief
 * @{
 **/
#define CA7_BIT_PSW_STS_HP_AP_L2           ((u32)0x00000001 << 27)          /*!<R 0  CA7 macro l2 power state for debug . 1: power is OK */
#define CA7_BIT_PSW_STS_HP_AP_CORE2        ((u32)0x00000001 << 26)          /*!<R 0  CA7 macro core2 power state for debug . 1: power is OK */
#define CA7_BIT_PSW_STS_HP_AP_CORE1        ((u32)0x00000001 << 25)          /*!<R 0  CA7 macro core1 power state for debug . 1: power is OK */
#define CA7_BIT_PSW_STS_HP_AP_CPUTOP       ((u32)0x00000001 << 24)          /*!<R 0  CA7 macro top power state for debug . 1: power is OK */
#define CA7_BIT_PSW_EN_HP_AP_L2            ((u32)0x00000001 << 23)          /*!<R/W 0  CA7 macro l2 power domain switch enable */
#define CA7_BIT_PSW_EN_HP_AP_CORE2         ((u32)0x00000001 << 22)          /*!<R/W 0  CA7 macro core2 power domain switch enable */
#define CA7_BIT_PSW_EN_HP_AP_CORE1         ((u32)0x00000001 << 21)          /*!<R/W 0  CA7 macro core1 power domain switch enable */
#define CA7_BIT_PSW_EN_HP_AP_CPUTOP        ((u32)0x00000001 << 20)          /*!<R/W 0  CA7 macro top power domain switch enable */
#define CA7_BIT_ISO_HP_AP_L2               ((u32)0x00000001 << 19)          /*!<R/W 1  CA7 macro l2 power domain isolatation, 1:assert */
#define CA7_BIT_ISO_HP_AP_CORE2            ((u32)0x00000001 << 18)          /*!<R/W 1  CA7 macro core2 power domain isolatation, 1:assert */
#define CA7_BIT_ISO_HP_AP_CORE1            ((u32)0x00000001 << 17)          /*!<R/W 1  CA7 macro core1 power domain isolatation, 1:assert */
#define CA7_BIT_ISO_HP_AP_CPUTOP           ((u32)0x00000001 << 16)          /*!<R/W 1  CA7 macro top power domain isolatation, 1:assert */
#define CA7_MASK_CKSL_AP                   ((u32)0x00000003 << 6)          /*!<R/W 0  CA7 clock selection 00: ap pll out (1.2G default) 10: ap pll div2 out (1.2G/2) 01/11: np pll out (600M) */
#define CA7_CKSL_AP(x)                     ((u32)(((x) & 0x00000003) << 6))
#define CA7_GET_CKSL_AP(x)                 ((u32)(((x >> 6) & 0x00000003)))
#define CA7_BIT_CKE_AP                     ((u32)0x00000001 << 4)          /*!<R/W 0x1  CA7 clock enable . */
#define CA7_MASK_CKD_AP                    ((u32)0x00000003 << 2)          /*!<R/WP 0  CA7 clock divider , this is after clk select by [7:6] 00: div1 01: div2 10: div3 11: div4 */
#define CA7_CKD_AP(x)                      ((u32)(((x) & 0x00000003) << 2))
#define CA7_GET_CKD_AP(x)                  ((u32)(((x >> 2) & 0x00000003)))
#define CA7_BIT_ISO_APLL                   ((u32)0x00000001 << 1)          /*!<R/W 0x0  Analog APPLL isolation signal , before CA7 power , this bit must be set to 1 */
#define CA7_BIT_FEN_AP                     ((u32)0x00000001 << 0)          /*!<R/W 0x0  CA7 function enable */
/** @} */

/** @defgroup CA7_C0_RST_CTRL
 * @brief Cluster 0 Reset Control Register
 * @{
 **/
#define CA7_MASK_DBGNOPWRDWN               ((u32)0x00000003 << 30)          /*!<R 0  Not Valid in test chip version */
#define CA7_DBGNOPWRDWN(x)                 ((u32)(((x) & 0x00000003) << 30))
#define CA7_GET_DBGNOPWRDWN(x)             ((u32)(((x >> 30) & 0x00000003)))
#define CA7_MASK_DBGPWRUPREQ               ((u32)0x00000003 << 28)          /*!<R 0  Not Valid in test chip version */
#define CA7_DBGPWRUPREQ(x)                 ((u32)(((x) & 0x00000003) << 28))
#define CA7_GET_DBGPWRUPREQ(x)             ((u32)(((x >> 28) & 0x00000003)))
#define CA7_BIT_L2RSTDISABLE               ((u32)0x00000001 << 25)          /*!<R/W 0  Disable automatic L2 cache invalidate at reset 0: L2 cache is reset by hardware. 1: L2 cache is not reset by hardware. L2RSTDISABLE must be held LOW during the initial reset sequence for the multiprocessor device. */
#define CA7_BIT_NL2RESET                   ((u32)0x00000001 << 24)          /*!<R/W 0x1  SCU global reset 0: Apply reset to shared L2 memory system controller. 1: Do not apply reset to shared L2 memory system controller. */
#define CA7_MASK_NCOREDBGRESET             ((u32)0x00000003 << 8)          /*!<R/W 0x3  Debug logic resets 0: Apply reset to debug, breakpoint and watchpoint logic. 1: Do not apply reset to debug, breakpoint and watchpoint logic. */
#define CA7_NCOREDBGRESET(x)               ((u32)(((x) & 0x00000003) << 8))
#define CA7_GET_NCOREDBGRESET(x)           ((u32)(((x >> 8) & 0x00000003)))
#define CA7_MASK_NCORERESET                ((u32)0x00000003 << 4)          /*!<R/W 0x3  Individual processor resets excluding Debug and ETM 0: Apply reset to processor that includes NEON and VFP, but excludes Debug, ETM, breakpoint and watchpoint logic. 1: Do not apply reset to processor that includes NEON and VFP, but excludes Debug, ETM, breakpoint and watchpoint logic. */
#define CA7_NCORERESET(x)                  ((u32)(((x) & 0x00000003) << 4))
#define CA7_GET_NCORERESET(x)              ((u32)(((x >> 4) & 0x00000003)))
#define CA7_MASK_NCOREPORESET              ((u32)0x00000003 << 0)          /*!<R/W 0x3  All processor reset 0: Apply reset to all processor logic that includes NEON and VFP, Debug, ETM, breakpoint and watchpoint logic. 1: Do not apply reset to all processor logic that includes NEON and VFP, Debug, ETM, breakpoint and watchpoint logic. */
#define CA7_NCOREPORESET(x)                ((u32)(((x) & 0x00000003) << 0))
#define CA7_GET_NCOREPORESET(x)            ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup CA7_C0_CPU_STATUS
 * @brief Cluster0 CPU Status Register
 * @{
 **/
#define CA7_BIT_STANDBYWFIL2               ((u32)0x00000001 << 19)          /*!<RO 0  Indicates if the L2 memory system is in WFE low-power state. This signal is active when the following conditions are met. * All processors are in WFI low-power state. * L2 memory system is idle. */
#define CA7_MASK_STANDBYWFE                ((u32)0x00000003 << 16)          /*!<RO 0  Indicates if a processor is in WFE low-power state. 0: Processor not in WFE low-power state. 1: Processor in WFE low-power state. */
#define CA7_STANDBYWFE(x)                  ((u32)(((x) & 0x00000003) << 16))
#define CA7_GET_STANDBYWFE(x)              ((u32)(((x >> 16) & 0x00000003)))
#define CA7_MASK_STANDBYWFI                ((u32)0x00000003 << 8)          /*!<RO 0x2  Indicates if a processor is in WFI low-power state. 0: Processor not in WFI low-power state. 1: Processor in WFI low-power state. */
#define CA7_STANDBYWFI(x)                  ((u32)(((x) & 0x00000003) << 8))
#define CA7_GET_STANDBYWFI(x)              ((u32)(((x >> 8) & 0x00000003)))
#define CA7_MASK_SMPNAMP                   ((u32)0x00000003 << 0)          /*!<RO 0x3  Signals Symmetric MultiProcessing (SMP) mode or Asymmetric MultiProcessing (AMP) for each processor in the Cortex-A7 MPCore processor. 0: AMP mode 1: SMP mode */
#define CA7_SMPNAMP(x)                     ((u32)(((x) & 0x00000003) << 0))
#define CA7_GET_SMPNAMP(x)                 ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup CA7_C0_CTRL_REG0
 * @brief Cluster 0 Control Register0
 * @{
 **/
#define CA7_MASK_VINITHI                   ((u32)0x00000003 << 20)          /*!<R/W 0   */
#define CA7_VINITHI(x)                     ((u32)(((x) & 0x00000003) << 20))
#define CA7_GET_VINITHI(x)                 ((u32)(((x >> 20) & 0x00000003)))
#define CA7_MASK_CFGTE                     ((u32)0x00000003 << 18)          /*!<R/W 0   */
#define CA7_CFGTE(x)                       ((u32)(((x) & 0x00000003) << 18))
#define CA7_GET_CFGTE(x)                   ((u32)(((x >> 18) & 0x00000003)))
#define CA7_MASK_CFGEND                    ((u32)0x00000003 << 16)          /*!<R/W 0  00: little endian ([0]/[1] for two core) 11: bit endian */
#define CA7_CFGEND(x)                      ((u32)(((x) & 0x00000003) << 16))
#define CA7_GET_CFGEND(x)                  ((u32)(((x >> 16) & 0x00000003)))
#define CA7_BIT_CFGSDISABLE                ((u32)0x00000001 << 8)          /*!<R/W 0  Disables write access to some secure GIC registers */
#define CA7_MASK_CP15SDISABLE              ((u32)0x00000003 << 0)          /*!<R/W 0  Disable write access to some secure CP15 registers */
#define CA7_CP15SDISABLE(x)                ((u32)(((x) & 0x00000003) << 0))
#define CA7_GET_CP15SDISABLE(x)            ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup CA7_APLL_CTRL0
 * @brief
 * @{
 **/
#define CA7_BIT_APLL_EN_SSC                ((u32)0x00000001 << 16)          /*!<R/W 0  Enable SSC */
#define CA7_BIT_APLL_POW_PI                ((u32)0x00000001 << 3)          /*!<R/W 0  Enable PI function */
#define CA7_BIT_APLL_POW_MBIAS             ((u32)0x00000001 << 2)          /*!<R/W 0  Enable pll mbias */
#define CA7_BIT_APLL_POW_POWER_CUT         ((u32)0x00000001 << 1)          /*!<R/W 0  Power cut of ap_pll */
#define CA7_BIT_APLL_POW_PLL               ((u32)0x00000001 << 0)          /*!<R/W 0  Enable pll */
/** @} */

/** @defgroup CA7_APLL_CTRL1
 * @brief
 * @{
 **/
#define CA7_BIT_APLL_CK_RDY                ((u32)0x00000001 << 31)          /*!<R 0  ap pll clock ready */
#define CA7_MASK_APLL_DIV_SEL              ((u32)0x000000FF << 16)          /*!<R/W 0  For SDM debug */
#define CA7_APLL_DIV_SEL(x)                ((u32)(((x) & 0x000000FF) << 16))
#define CA7_GET_APLL_DIV_SEL(x)            ((u32)(((x >> 16) & 0x000000FF)))
#define CA7_MASK_APLL_CP_ICP_SEL           ((u32)0x00000007 << 8)          /*!<R/W 0  Cp current select 000=10uA 001=15uA, 010=20uA, 011=25uA, 100=30uA, 101=35uA, 110=40uA, 111=45uA */
#define CA7_APLL_CP_ICP_SEL(x)             ((u32)(((x) & 0x00000007) << 8))
#define CA7_GET_APLL_CP_ICP_SEL(x)         ((u32)(((x >> 8) & 0x00000007)))
#define CA7_BIT_APLL_CP_ICPX2              ((u32)0x00000001 << 7)          /*!<R/W 0  Cp current doubler, 0=disable, 1=enable */
#define CA7_MASK_APLL_CK_OUT_SEL           ((u32)0x00000007 << 4)          /*!<R/W 0  Output clk divider 000=/1 100=/4 110=/8 111=/16 */
#define CA7_APLL_CK_OUT_SEL(x)             ((u32)(((x) & 0x00000007) << 4))
#define CA7_GET_APLL_CK_OUT_SEL(x)         ((u32)(((x >> 4) & 0x00000007)))
#define CA7_BIT_APLL_CK_EN_D2              ((u32)0x00000001 << 1)          /*!<R/W 1  Enable clk divided by 2 */
#define CA7_BIT_APLL_CK_EN                 ((u32)0x00000001 << 0)          /*!<R/W 1  Enable clk */
/** @} */

/** @defgroup CA7_APLL_CTRL2
 * @brief
 * @{
 **/
#define CA7_MASK_APLL_PI_SEL               ((u32)0x0000003F << 24)          /*!<R/W 0  For SDM debug, 应该只要4bit. */
#define CA7_APLL_PI_SEL(x)                 ((u32)(((x) & 0x0000003F) << 24))
#define CA7_GET_APLL_PI_SEL(x)             ((u32)(((x >> 24) & 0x0000003F)))
#define CA7_MASK_APLL_IB_PI                ((u32)0x00000003 << 20)          /*!<R/W 0  PI current select */
#define CA7_APLL_IB_PI(x)                  ((u32)(((x) & 0x00000003) << 20))
#define CA7_GET_APLL_IB_PI(x)              ((u32)(((x >> 20) & 0x00000003)))
#define CA7_BIT_APLL_PFD_RESET_GATED       ((u32)0x00000001 << 16)          /*!<R/W 0  0=normal mode 1=gated PFD/CP block(for debug use) */
#define CA7_MASK_APLL_LPF_RS               ((u32)0x00000007 << 12)          /*!<R/W 100  reg_LPF_RS<2:0> LPF RS parameter 000=15k 001=13k 010=11k 011=9k 100=7k 101=5k 110=3k 111=1k */
#define CA7_APLL_LPF_RS(x)                 ((u32)(((x) & 0x00000007) << 12))
#define CA7_GET_APLL_LPF_RS(x)             ((u32)(((x >> 12) & 0x00000007)))
#define CA7_MASK_APLL_LPF_R3               ((u32)0x00000007 << 8)          /*!<R/W 100  LPF R3 parameter 000=1.75k 001=1.5k 010=1.25k 011=1k 100=0.75k 101=0.5k 110=0.25k 111=0k */
#define CA7_APLL_LPF_R3(x)                 ((u32)(((x) & 0x00000007) << 8))
#define CA7_GET_APLL_LPF_R3(x)             ((u32)(((x >> 8) & 0x00000007)))
#define CA7_MASK_APLL_LPF_CS               ((u32)0x00000003 << 4)          /*!<R/W 10  LPF CS parameter 00=30p 01=40p 10=50p 11=60p */
#define CA7_APLL_LPF_CS(x)                 ((u32)(((x) & 0x00000003) << 4))
#define CA7_GET_APLL_LPF_CS(x)             ((u32)(((x >> 4) & 0x00000003)))
#define CA7_MASK_APLL_LPF_CP               ((u32)0x00000003 << 2)          /*!<R/W 10  LPF CP parameter 00=3p 01=4p 10=5p 11=6p */
#define CA7_APLL_LPF_CP(x)                 ((u32)(((x) & 0x00000003) << 2))
#define CA7_GET_APLL_LPF_CP(x)             ((u32)(((x >> 2) & 0x00000003)))
#define CA7_MASK_APLL_LPF_C3               ((u32)0x00000003 << 0)          /*!<R/W 10  LPF C3 parameter 00=0.5p 01=1p 10=1.5p 11=2p */
#define CA7_APLL_LPF_C3(x)                 ((u32)(((x) & 0x00000003) << 0))
#define CA7_GET_APLL_LPF_C3(x)             ((u32)(((x >> 0) & 0x00000003)))
/** @} */

/** @defgroup CA7_APLL_CTRL3
 * @brief
 * @{
 **/
#define CA7_MASK_APLL_SDM_XTAL_SEL         ((u32)0x0000000F << 16)          /*!<R/W 0  not used. */
#define CA7_APLL_SDM_XTAL_SEL(x)           ((u32)(((x) & 0x0000000F) << 16))
#define CA7_GET_APLL_SDM_XTAL_SEL(x)       ((u32)(((x >> 16) & 0x0000000F)))
#define CA7_BIT_APLL_XTAL_SEL              ((u32)0x00000001 << 10)          /*!<R/W 0  Output clk select 0= pll output 1=xtal */
#define CA7_BIT_APLL_XTAL_FREQ_SEL         ((u32)0x00000001 << 9)          /*!<R/W 0  0=XTAL 1=XTAL/2 */
#define CA7_BIT_APLL_XTAL_EDGE_SEL         ((u32)0x00000001 << 8)          /*!<R/W 0  Xtal edge select */
#define CA7_BIT_APLL_VC_TL                 ((u32)0x00000001 << 5)          /*!<R/W 0  For debug use */
#define CA7_BIT_APLL_VC_TH                 ((u32)0x00000001 << 4)          /*!<R/W 0  For debug use */
#define CA7_BIT_APLL_SDM_EDGE_SEL          ((u32)0x00000001 << 2)          /*!<R/W 0  SDM clk edge select */
#define CA7_BIT_APLL_SDM_CK_SEL            ((u32)0x00000001 << 1)          /*!<R/W 0  SDM clk select 0=ckdiv 1=XTAL */
#define CA7_BIT_APLL_SDM_CK_GATED          ((u32)0x00000001 << 0)          /*!<R/W 0  0=no gated SDM clk 1=gated SDM clk */
/** @} */

/** @defgroup CA7_APLL_CTRL4
 * @brief
 * @{
 **/
#define CA7_MASK_APLL_SDM_SSC_STEP         ((u32)0x000000FF << 16)          /*!<R/W 0  SSC step select */
#define CA7_APLL_SDM_SSC_STEP(x)           ((u32)(((x) & 0x000000FF) << 16))
#define CA7_GET_APLL_SDM_SSC_STEP(x)       ((u32)(((x >> 16) & 0x000000FF)))
#define CA7_MASK_APLL_SDM_SSC_TBASE        ((u32)0x00000FFF << 0)          /*!<R/W 0  SSC table select */
#define CA7_APLL_SDM_SSC_TBASE(x)          ((u32)(((x) & 0x00000FFF) << 0))
#define CA7_GET_APLL_SDM_SSC_TBASE(x)      ((u32)(((x >> 0) & 0x00000FFF)))
/** @} */

/** @defgroup CA7_APLL_CTRL5
 * @brief
 * @{
 **/
#define CA7_BIT_APLL_SDM_DELAY_PH          ((u32)0x00000001 << 29)          /*!<R/W 0  For SDM debug */
#define CA7_BIT_APLL_SDM_DEBUG_MODE        ((u32)0x00000001 << 28)          /*!<R/W 0  For SDM scan mode */
#define CA7_BIT_APLL_SDM_ORDER             ((u32)0x00000001 << 24)          /*!<R/W 0  SDM order */
#define CA7_MASK_APLL_SDM_F0N              ((u32)0x0000001F << 16)          /*!<R/W 0  SDM fractional function */
#define CA7_APLL_SDM_F0N(x)                ((u32)(((x) & 0x0000001F) << 16))
#define CA7_GET_APLL_SDM_F0N(x)            ((u32)(((x >> 16) & 0x0000001F)))
#define CA7_MASK_APLL_SDM_F0F              ((u32)0x000000FF << 8)          /*!<R/W 0  SDM fraction function */
#define CA7_APLL_SDM_F0F(x)                ((u32)(((x) & 0x000000FF) << 8))
#define CA7_GET_APLL_SDM_F0F(x)            ((u32)(((x >> 8) & 0x000000FF)))
#define CA7_MASK_APLL_SDM_DIVN             ((u32)0x000000FF << 0)          /*!<R/W 11010  N= SDM_DIVN<7:0>+2 */
#define CA7_APLL_SDM_DIVN(x)               ((u32)(((x) & 0x000000FF) << 0))
#define CA7_GET_APLL_SDM_DIVN(x)           ((u32)(((x >> 0) & 0x000000FF)))
/** @} */

/** @defgroup CA7_APLL_CTRL6
 * @brief
 * @{
 **/
#define CA7_MASK_APLL_DUMMY                ((u32)0x0003FFFF << 0)          /*!<R/W 0   */
#define CA7_APLL_DUMMY(x)                  ((u32)(((x) & 0x0003FFFF) << 0))
#define CA7_GET_APLL_DUMMY(x)              ((u32)(((x >> 0) & 0x0003FFFF)))
/** @} */

/** @defgroup CA7_DSS0
 * @brief
 * @{
 **/
#define CA7_MASK_DSS_COUNT_OUT_31_0        ((u32)0xFFFFFFFF << 0)          /*!<R 32'h0  [19:0] - core 0 dss count_out [39:20] - core 1 dss count_out count_out[19:0] is counter value indicates the speed of selected ring oscillator Cycle time = (count_out*dss_clk period)/ 16384 */
#define CA7_DSS_COUNT_OUT_31_0(x)          ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CA7_GET_DSS_COUNT_OUT_31_0(x)      ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup CA7_DSS1
 * @brief
 * @{
 **/
#define CA7_MASK_DSS_COUNT_OUT_39_32       ((u32)0x000000FF << 0)          /*!<R 8'h0  ca7_dss_count_out[39:20] - core 1 dss count_out count_out[19:0] is counter value indicates the speed of selected ring oscillator Cycle time = (count_out*dss_clk period)/ 16384 */
#define CA7_DSS_COUNT_OUT_39_32(x)         ((u32)(((x) & 0x000000FF) << 0))
#define CA7_GET_DSS_COUNT_OUT_39_32(x)     ((u32)(((x >> 0) & 0x000000FF)))
#define CA7_MASK_DSS_READY                 ((u32)0x00000003 << 8)          /*!<R 2'b0  [0] - core 0 dss ready [1] - core 1 dss ready Ready strobe to read count_out value for each DSS. */
#define CA7_DSS_READY(x)                   ((u32)(((x) & 0x00000003) << 8))
#define CA7_GET_DSS_READY(x)               ((u32)(((x >> 8) & 0x00000003)))
/** @} */

/** @defgroup CA7_DSS2
 * @brief
 * @{
 **/
#define CA7_MASK_DSS_RO_SEL                ((u32)0x0000003F << 0)          /*!<R/W 6'h0  [2:0]- core 0 dss ro_sel [5:3]- core 1 dss ro_sel ro_sel[2:0] - Ring Oscillator selection: 000: select dss_clk (for test mode) 001 : select 1st ring oscillator 010 : select 2nd ring oscillator 011 : select 3rd ring oscillator 100 : select 4th ring oscillator 101 : select multi-library ring oscillator Others : not used */
#define CA7_DSS_RO_SEL(x)                  ((u32)(((x) & 0x0000003F) << 0))
#define CA7_GET_DSS_RO_SEL(x)              ((u32)(((x >> 0) & 0x0000003F)))
#define CA7_MASK_DSS_SPEED_EN              ((u32)0x00000003 << 6)          /*!<R/W 2'b0  [0] - core 0 dss speed_en [1] - core 1 dss speed_en Speed sensor enable of each DSS 0: disable 1: enable */
#define CA7_DSS_SPEED_EN(x)                ((u32)(((x) & 0x00000003) << 6))
#define CA7_GET_DSS_SPEED_EN(x)            ((u32)(((x >> 6) & 0x00000003)))
#define CA7_MASK_DSS_WIRE_SEL              ((u32)0x00000003 << 8)          /*!<R/W 2'b0  [0] - core 0 dss wire_sel [1] - core 1 dss wire_sel wire selection 0: loong wire/delay cell/clock buffer 1: short wire */
#define CA7_DSS_WIRE_SEL(x)                ((u32)(((x) & 0x00000003) << 8))
#define CA7_GET_DSS_WIRE_SEL(x)            ((u32)(((x >> 8) & 0x00000003)))
#define CA7_MASK_DSS_RST_N                 ((u32)0x00000003 << 10)          /*!<R/W 2'b0  [0] - core 0 dss rst_n [1] - core 1 dss rst_n rst_n Reset signal of each Speed-Sensor (low active) (Software control reset) Function of DSS - Digital Speed Sensor On-chip variation measurement (PVT) – Process variation • Inter-die process variation • Intra-die process variation • Library cell variation • Specific component variation • PMOS and NMOS variation – Voltage variation • IR drop – Temperature variation •Testing – Sorting or binning ICs by target speed There is one DSS in ca7 core 0 and one DSS in ca7 core 1. */
#define CA7_DSS_RST_N(x)                   ((u32)(((x) & 0x00000003) << 10))
#define CA7_GET_DSS_RST_N(x)               ((u32)(((x >> 10) & 0x00000003)))
/** @} */

/** @defgroup CA7_LPS_CTRL
 * @brief
 * @{
 **/
#define CA7_MASK_CORE_CLAMP_EN             ((u32)0x00000003 << 0)          /*!<R/W 2'h3  [0] : core 0 [1] : core 1 0 : disable ISO cell clamping 1 : enable ISO cell clamping should be kept 0 in scan test */
#define CA7_CORE_CLAMP_EN(x)               ((u32)(((x) & 0x00000003) << 0))
#define CA7_GET_CORE_CLAMP_EN(x)           ((u32)(((x >> 0) & 0x00000003)))
#define CA7_MASK_CORE_PWRCTRL_IN           ((u32)0x00000003 << 2)          /*!<R/W 2'h0  [0] : core 0 [1] : core 1 0 : power on 1 : power off */
#define CA7_CORE_PWRCTRL_IN(x)             ((u32)(((x) & 0x00000003) << 2))
#define CA7_GET_CORE_PWRCTRL_IN(x)         ((u32)(((x >> 2) & 0x00000003)))
#define CA7_MASK_CORE_PWRCTRL_OUT          ((u32)0x00000003 << 4)          /*!<R 2'h0  [0] : core 0 [1] : core 1 0 : power on 1 : power off */
#define CA7_CORE_PWRCTRL_OUT(x)            ((u32)(((x) & 0x00000003) << 4))
#define CA7_GET_CORE_PWRCTRL_OUT(x)        ((u32)(((x >> 4) & 0x00000003)))
#define CA7_MASK_CORE_PWRCTRL_2ND_IN       ((u32)0x00000003 << 6)          /*!<R/W 2'h0  [0] : core 0 [1] : core 1 0 : power on 1 : power off */
#define CA7_CORE_PWRCTRL_2ND_IN(x)         ((u32)(((x) & 0x00000003) << 6))
#define CA7_GET_CORE_PWRCTRL_2ND_IN(x)     ((u32)(((x >> 6) & 0x00000003)))
#define CA7_MASK_CORE_PWRCTRL_2ND_OUT      ((u32)0x00000003 << 8)          /*!<R 2'h0  [0] : core 0 [1] : core 1 0 : power on 1 : power off */
#define CA7_CORE_PWRCTRL_2ND_OUT(x)        ((u32)(((x) & 0x00000003) << 8))
#define CA7_GET_CORE_PWRCTRL_2ND_OUT(x)    ((u32)(((x >> 8) & 0x00000003)))
#define CA7_BIT_TOP_CLAMP_EN               ((u32)0x00000001 << 10)          /*!<R/W 1'b1  0 : disable ISO cell clamping 1 : enable ISO cell clamping should be kept 0 in scan test */
#define CA7_BIT_TOP_PWRCTRL_IN             ((u32)0x00000001 << 11)          /*!<R/W 1'b0  0 : power on 1 : power off */
#define CA7_BIT_TOP_PWRCTRL_OUT            ((u32)0x00000001 << 12)          /*!<R 1'b0  0 : power on 1 : power off */
#define CA7_BIT_TOP_PWRCTRL_2ND_IN         ((u32)0x00000001 << 13)          /*!<R/W 1'b0  0 : power on 1 : power off */
#define CA7_BIT_TOP_PWRCTRL_2ND_OUT        ((u32)0x00000001 << 14)          /*!<R 1'b0  0 : power on 1 : power off */
#define CA7_BIT_L2_PWRCTRL_IN              ((u32)0x00000001 << 15)          /*!<R/W 1'b0  0 : power on 1 : power off */
#define CA7_BIT_L2_PWRCTRL_OUT             ((u32)0x00000001 << 16)          /*!<R 1'b0  0 : power on 1 : power off */
/** @} */

/** @defgroup CA7_SRAM_CTRL0
 * @brief
 * @{
 **/
#define CA7_MASK_EMA_DDATA                 ((u32)0x00000007 << 0)          /*!<R/W 3'h3  Extra Margin Adjustment (EMA) of ddata mem. slow down memory access and provide extra time for memory read and write 000 : fastest 111 : slowest */
#define CA7_EMA_DDATA(x)                   ((u32)(((x) & 0x00000007) << 0))
#define CA7_GET_EMA_DDATA(x)               ((u32)(((x >> 0) & 0x00000007)))
#define CA7_MASK_EMA_DTAG                  ((u32)0x00000007 << 3)          /*!<R/W 3'h3  Extra Margin Adjustment (EMA) of dtag mem. slow down memory access and provide extra time for memory read and write 000 : fastest 111 : slowest */
#define CA7_EMA_DTAG(x)                    ((u32)(((x) & 0x00000007) << 3))
#define CA7_GET_EMA_DTAG(x)                ((u32)(((x >> 3) & 0x00000007)))
#define CA7_MASK_EMA_DDIRTY                ((u32)0x00000007 << 6)          /*!<R/W 3'h3  Extra Margin Adjustment (EMA) of ddirty mem. slow down memory access and provide extra time for memory read and write 000 : fastest 111 : slowest */
#define CA7_EMA_DDIRTY(x)                  ((u32)(((x) & 0x00000007) << 6))
#define CA7_GET_EMA_DDIRTY(x)              ((u32)(((x >> 6) & 0x00000007)))
#define CA7_MASK_EMA_IDATA                 ((u32)0x00000007 << 9)          /*!<R/W 3'h3  Extra Margin Adjustment (EMA) of idata mem. slow down memory access and provide extra time for memory read and write 000 : fastest 111 : slowest */
#define CA7_EMA_IDATA(x)                   ((u32)(((x) & 0x00000007) << 9))
#define CA7_GET_EMA_IDATA(x)               ((u32)(((x >> 9) & 0x00000007)))
#define CA7_MASK_EMA_ITAG                  ((u32)0x00000007 << 12)          /*!<R/W 3'h3  Extra Margin Adjustment (EMA) of itag mem. slow down memory access and provide extra time for memory read and write 000 : fastest 111 : slowest */
#define CA7_EMA_ITAG(x)                    ((u32)(((x) & 0x00000007) << 12))
#define CA7_GET_EMA_ITAG(x)                ((u32)(((x >> 12) & 0x00000007)))
#define CA7_MASK_EMA_TLB                   ((u32)0x00000007 << 15)          /*!<R/W 3'h3  Extra Margin Adjustment (EMA) of tlb mem. slow down memory access and provide extra time for memory read and write 000 : fastest 111 : slowest */
#define CA7_EMA_TLB(x)                     ((u32)(((x) & 0x00000007) << 15))
#define CA7_GET_EMA_TLB(x)                 ((u32)(((x >> 15) & 0x00000007)))
#define CA7_MASK_EMA_SCU_TAG               ((u32)0x00000007 << 18)          /*!<R/W 3'h3  Extra Margin Adjustment (EMA) of scu tag mem. slow down memory access and provide extra time for memory read and write 000 : fastest 111 : slowest */
#define CA7_EMA_SCU_TAG(x)                 ((u32)(((x) & 0x00000007) << 18))
#define CA7_GET_EMA_SCU_TAG(x)             ((u32)(((x >> 18) & 0x00000007)))
#define CA7_MASK_EMA_L2_TAG                ((u32)0x00000007 << 21)          /*!<R/W 3'h3  Extra Margin Adjustment (EMA) of l2cache tag mem. slow down memory access and provide extra time for memory read and write 000 : fastest 111 : slowest */
#define CA7_EMA_L2_TAG(x)                  ((u32)(((x) & 0x00000007) << 21))
#define CA7_GET_EMA_L2_TAG(x)              ((u32)(((x >> 21) & 0x00000007)))
#define CA7_MASK_EMA_L2_DATA               ((u32)0x00000007 << 24)          /*!<R/W 3'h3  Extra Margin Adjustment (EMA) l2cache data mem. slow down memory access and provide extra time for memory read and write 000 : fastest 111 : slowest */
#define CA7_EMA_L2_DATA(x)                 ((u32)(((x) & 0x00000007) << 24))
#define CA7_GET_EMA_L2_DATA(x)             ((u32)(((x >> 24) & 0x00000007)))
/** @} */

/** @defgroup CA7_SRAM_CTRL1
 * @brief
 * @{
 **/
#define CA7_MASK_EMAW_DDATA                ((u32)0x00000003 << 0)          /*!<R/W 2'h0  Extra Margin Adjustment for Write (EMAW) control delay for write operation 00 : fastest 11 : slowest */
#define CA7_EMAW_DDATA(x)                  ((u32)(((x) & 0x00000003) << 0))
#define CA7_GET_EMAW_DDATA(x)              ((u32)(((x >> 0) & 0x00000003)))
#define CA7_MASK_EMAW_DTAG                 ((u32)0x00000003 << 2)          /*!<R/W 2'h1   */
#define CA7_EMAW_DTAG(x)                   ((u32)(((x) & 0x00000003) << 2))
#define CA7_GET_EMAW_DTAG(x)               ((u32)(((x >> 2) & 0x00000003)))
#define CA7_MASK_EMAW_DDIRTY               ((u32)0x00000003 << 4)          /*!<R/W 2'h1   */
#define CA7_EMAW_DDIRTY(x)                 ((u32)(((x) & 0x00000003) << 4))
#define CA7_GET_EMAW_DDIRTY(x)             ((u32)(((x >> 4) & 0x00000003)))
#define CA7_MASK_EMAW_IDATA                ((u32)0x00000003 << 6)          /*!<R/W 2'h0   */
#define CA7_EMAW_IDATA(x)                  ((u32)(((x) & 0x00000003) << 6))
#define CA7_GET_EMAW_IDATA(x)              ((u32)(((x >> 6) & 0x00000003)))
#define CA7_MASK_EMAW_ITAG                 ((u32)0x00000003 << 8)          /*!<R/W 2'h1   */
#define CA7_EMAW_ITAG(x)                   ((u32)(((x) & 0x00000003) << 8))
#define CA7_GET_EMAW_ITAG(x)               ((u32)(((x >> 8) & 0x00000003)))
#define CA7_MASK_EMAW_TLB                  ((u32)0x00000003 << 10)          /*!<R/W 2'h1   */
#define CA7_EMAW_TLB(x)                    ((u32)(((x) & 0x00000003) << 10))
#define CA7_GET_EMAW_TLB(x)                ((u32)(((x >> 10) & 0x00000003)))
#define CA7_MASK_EMAW_SCU_TAG              ((u32)0x00000003 << 12)          /*!<R/W 2'h1   */
#define CA7_EMAW_SCU_TAG(x)                ((u32)(((x) & 0x00000003) << 12))
#define CA7_GET_EMAW_SCU_TAG(x)            ((u32)(((x >> 12) & 0x00000003)))
#define CA7_MASK_EMAW_L2_TAG               ((u32)0x00000003 << 14)          /*!<R/W 2'h1   */
#define CA7_EMAW_L2_TAG(x)                 ((u32)(((x) & 0x00000003) << 14))
#define CA7_GET_EMAW_L2_TAG(x)             ((u32)(((x >> 14) & 0x00000003)))
#define CA7_MASK_EMAW_L2_DATA              ((u32)0x00000003 << 16)          /*!<R/W 2'h0   */
#define CA7_EMAW_L2_DATA(x)                ((u32)(((x) & 0x00000003) << 16))
#define CA7_GET_EMAW_L2_DATA(x)            ((u32)(((x >> 16) & 0x00000003)))
#define CA7_BIT_EMAS_DDATA                 ((u32)0x00000001 << 18)          /*!<R/W 1'b0  Extra Margin Adjustment Sense Amplifier Pulse (EMAS) extends pulse width of sense-amp enable signal 0 : LOW (default) 1 : HIGH, pulse is extended */
#define CA7_BIT_EMAS_DTAG                  ((u32)0x00000001 << 19)          /*!<R/W 1'b0   */
#define CA7_BIT_EMAS_DDIRTY                ((u32)0x00000001 << 20)          /*!<R/W 1'b0   */
#define CA7_BIT_EMAS_IDATA                 ((u32)0x00000001 << 21)          /*!<R/W 1'b0   */
#define CA7_BIT_EMAS_ITAG                  ((u32)0x00000001 << 22)          /*!<R/W 1'b0   */
#define CA7_BIT_EMAS_TLB                   ((u32)0x00000001 << 23)          /*!<R/W 1'b0   */
#define CA7_BIT_EMAS_SCU_TAG               ((u32)0x00000001 << 24)          /*!<R/W 1'b0   */
#define CA7_BIT_EMAS_L2_TAG                ((u32)0x00000001 << 25)          /*!<R/W 1'b0   */
#define CA7_BIT_EMAS_L2_DATA               ((u32)0x00000001 << 26)          /*!<R/W 1'b0   */
/** @} */

/** @defgroup CA7_SRAM_CTRL2
 * @brief
 * @{
 **/
#define CA7_MASK_CORE_SRAM_PWRCTRLN        ((u32)0x00000003 << 0)          /*!<R/W 2'b00  [0] : core 0 [1] : core 1 0: core ARM sram power gating disable. 1: core ARM sram power gating disable. */
#define CA7_CORE_SRAM_PWRCTRLN(x)          ((u32)(((x) & 0x00000003) << 0))
#define CA7_GET_CORE_SRAM_PWRCTRLN(x)      ((u32)(((x >> 0) & 0x00000003)))
#define CA7_MASK_CORE_SRAM_RET1N           ((u32)0x00000003 << 2)          /*!<R/W 2'b11  [0] : core 0 [1] : core 1 0 : core ARM sram enable retention 1 mode, light sleep. 1 : core ARM sram disable retention 1 mode. */
#define CA7_CORE_SRAM_RET1N(x)             ((u32)(((x) & 0x00000003) << 2))
#define CA7_GET_CORE_SRAM_RET1N(x)         ((u32)(((x >> 2) & 0x00000003)))
#define CA7_MASK_CORE_SRAM_RET2N           ((u32)0x00000003 << 4)          /*!<R/W 2'b11  [0] : core 0 [1] : core 1 0 : core ARM sram enable retention 2 mode, deep sleep. 1 : core ARM sram disable retention 2 mode. */
#define CA7_CORE_SRAM_RET2N(x)             ((u32)(((x) & 0x00000003) << 4))
#define CA7_GET_CORE_SRAM_RET2N(x)         ((u32)(((x >> 4) & 0x00000003)))
#define CA7_BIT_TOP_SRAM_PWRCTRLN          ((u32)0x00000001 << 6)          /*!<R/W 1'b0  0: top ARM sram power gating disable. 1: top ARM sram power gating disable. */
#define CA7_BIT_TOP_SRAM_RET1N             ((u32)0x00000001 << 7)          /*!<R/W 1'b1  0 : top ARM sram enable retention 1 mode, light sleep. 1 : top ARM sram disable retention 1 mode. */
#define CA7_BIT_TOP_SRAM_RET2N             ((u32)0x00000001 << 8)          /*!<R/W 1'b1  0 : top ARM sram enable retention 2 mode, deep sleep. 1 : vdisable retention 2 mode. */
#define CA7_BIT_L2_SRAM_PWRCTRLN           ((u32)0x00000001 << 9)          /*!<R/W 1'b0  0: L2cache ARM sram power gating disable. 1: L2cache ARM sram power gating disable. */
#define CA7_BIT_L2_SRAM_RET1N              ((u32)0x00000001 << 10)          /*!<R/W 1'b1  0 : L2cache ARM sram enable retention 1 mode, light sleep. 1 : L2cache ARM sram disable retention 1 mode. */
#define CA7_BIT_L2_SRAM_RET2N              ((u32)0x00000001 << 11)          /*!<R/W 1'b1  0 : L2cache ARM sram enable retention 2 mode, deep sleep. 1 : L2cache ARM sram disable retention 2 mode. */
/** @} */

/** @defgroup CA7_COOR_CTRL0
 * @brief
 * @{
 **/
#define CA7_BIT_COORD_RSTN                 ((u32)0x00000001 << 0)          /*!<R/W 0  Coordinator Controller Reset external register control reset signal, used for async reset of coordinator controller */
#define CA7_BIT_SHRBUS_EN_CPU              ((u32)0x00000001 << 1)          /*!<R/W 0  share bus enable bit for cpu top slice-0. To enable the share bus of the corresponding cpu core/top, MBIST share bus would not trigger until shrbus_go bit is set. */
#define CA7_BIT_SHRBUS_GO                  ((u32)0x00000001 << 2)          /*!<R/W 0  share bus go bit After programming shrbus_en_cpu, S/W can set this bit to trigger the coordinators whose shrbus_en_cpu is set */
#define CA7_BIT_MBISTCFG_SEL               ((u32)0x00000001 << 3)          /*!<R/W 0  mbist configuration selection from external control register. 0 : mbistcfg will be set 0 1 : mbistcfg will be set 1 mbistcfg : mbist configuration 0 : MBIST ALL mode disabled 1 : MBIST ALL mode enabled */
#define CA7_BIT_MBIST_FNSH                 ((u32)0x00000001 << 4)          /*!<R 0  coordinator mbist finish when all the selected memories had been tested, coordinator asserts the signal to indicate mbist or drf mbist finished. */
#define CA7_BIT_MBISTREQ_DBG               ((u32)0x00000001 << 5)          /*!<R 0  share bus mbist request debug signal replica of mbist request signal, used for external monitor */
#define CA7_BIT_MBISTACK_DBG               ((u32)0x00000001 << 6)          /*!<R 0  share bus mbist ack debug signal replica of mbist ack signal, used for external monitor */
#define CA7_BIT_BIST_MODE_ALL              ((u32)0x00000001 << 7)          /*!<R/W 0  when set, coordinator will test all the memories despite of bist_mode. */
#define CA7_MASK_BIST_ALG_SELECTION        ((u32)0x0000007F << 8)          /*!<R/W 7'h1  [0] : default algorithm [1] : write + consecutive read 4 times, reverse test once again [2] : write + consecutive read 8 times, reverse test once again [3] : write + consecutive read 12 times, reverse test once again */
#define CA7_BIST_ALG_SELECTION(x)          ((u32)(((x) & 0x0000007F) << 8))
#define CA7_GET_BIST_ALG_SELECTION(x)      ((u32)(((x >> 8) & 0x0000007F)))
#define CA7_MASK_BIST_MODE                 ((u32)0x0000FFFF << 16)          /*!<R/W 0  if ca7_bist_mode_all is 0, test memories whose corresponding ca7_bist_mode[15:0] bit is set 1. if ca7_bist_mode_all is 1, test all memories. */
#define CA7_BIST_MODE(x)                   ((u32)(((x) & 0x0000FFFF) << 16))
#define CA7_GET_BIST_MODE(x)               ((u32)(((x >> 16) & 0x0000FFFF)))
/** @} */

/** @defgroup CA7_COOR_CTRL1
 * @brief
 * @{
 **/
#define CA7_MASK_BIST_DONE                 ((u32)0x0000FFFF << 0)          /*!<R 0  mbist done status of each memory . */
#define CA7_BIST_DONE(x)                   ((u32)(((x) & 0x0000FFFF) << 0))
#define CA7_GET_BIST_DONE(x)               ((u32)(((x >> 0) & 0x0000FFFF)))
#define CA7_MASK_BIST_FAIL                 ((u32)0x0000FFFF << 16)          /*!<R 0  mbist fail status of each memory . when ca7_drf_mbist_mode = 0, bist_fail is corresponding to normal bist test. when ca7_drf_mbist_mode = 1, bist_fail is corresponding to drf bist test. */
#define CA7_BIST_FAIL(x)                   ((u32)(((x) & 0x0000FFFF) << 16))
#define CA7_GET_BIST_FAIL(x)               ((u32)(((x >> 16) & 0x0000FFFF)))
/** @} */

/** @defgroup CA7_COOR_CTRL2
 * @brief
 * @{
 **/
#define CA7_MASK_BIST_BANK_FAIL            ((u32)0x000000FF << 0)          /*!<R 0  sram maximum banks CA7 : 8 bank */
#define CA7_BIST_BANK_FAIL(x)              ((u32)(((x) & 0x000000FF) << 0))
#define CA7_GET_BIST_BANK_FAIL(x)          ((u32)(((x >> 0) & 0x000000FF)))
#define CA7_MASK_BIST_SRAM_DBG_SEL         ((u32)0x0000000F << 8)          /*!<R/W 0  select debug sram 0000 : ddata 0001 : dtag 0010 : ddirty 0011 : idata 0100 : itag 0101 : tlb 0110 : scu_tag 0111 : l2_tag 1000 : l2_data */
#define CA7_BIST_SRAM_DBG_SEL(x)           ((u32)(((x) & 0x0000000F) << 8))
#define CA7_GET_BIST_SRAM_DBG_SEL(x)       ((u32)(((x >> 8) & 0x0000000F)))
#define CA7_BIT_BIST_SRAM_DBG_EN           ((u32)0x00000001 << 12)          /*!<R/W 0  bist_sram_dbg_en is a global control signal to latch internal bist fail status when set 1, the sram bank fail status selected by bist_sram_dbg_sel revealed on bist_bank_fail port 0 : bist_bank_fail is not available 1 : internal bist bank fail status latched on bist_bank_fail */
#define CA7_BIT_BIST_SRAM_DBG_CLR          ((u32)0x00000001 << 13)          /*!<R/W 0  bist_sram_dbg_clr is used to clear bist_bank_fail 1 : reset bist_bank_fail */
#define CA7_BIT_DRF_BIST_MODE              ((u32)0x00000001 << 14)          /*!<R/W 0  DRF bist mode enable 1: select DRF/VDDR mode mbist 0: select normal mode mbist */
#define CA7_BIT_DRF_TEST_RESUME            ((u32)0x00000001 << 15)          /*!<R/W 0  1: test resume for DRF/VDDR mode mbist mode */
#define CA7_BIT_DRF_START_PAUSE            ((u32)0x00000001 << 16)          /*!<R 0  1: start pause for DRF/VDDR mode mbist mode */
#define CA7_BIT_DRF_BIST_DONE              ((u32)0x00000001 << 17)          /*!<R 0  bist done of all memory for DRF/VDDR mode mbist */
#define CA7_BIT_DRF_DYN_READ_EN            ((u32)0x00000001 << 18)          /*!<R/W 0  drf dynamic read enable for VDDR(Dynamic Data Retetion) test 0 : data retention fail test 1 : dynamic data retention test VDDR mode mbist is selected if both ca7_drf_dyn_read_en=1 and ca7_drf_bist_mode=1 */
/** @} */

/** @defgroup CA7_COOR_CTRL3
 * @brief
 * @{
 **/
#define CA7_MASK_DIAG_MODE                 ((u32)0x00000007 << 0)          /*!<R/W 0  0 : ram is not diagnosed 1 : ram is to be diagnosed */
#define CA7_DIAG_MODE(x)                   ((u32)(((x) & 0x00000007) << 0))
#define CA7_GET_DIAG_MODE(x)               ((u32)(((x >> 0) & 0x00000007)))
#define CA7_MASK_DIAG_MEMARRAY_SEL         ((u32)0x000001FF << 3)          /*!<R/W 0  select which memory bank will be diagnosized, it will substitute the original mbistarray when diag_mode is set. */
#define CA7_DIAG_MEMARRAY_SEL(x)           ((u32)(((x) & 0x000001FF) << 3))
#define CA7_GET_DIAG_MEMARRAY_SEL(x)       ((u32)(((x >> 3) & 0x000001FF)))
#define CA7_BIT_DIAG_SO                    ((u32)0x00000001 << 12)          /*!<R 0  diagnosis shift out data serial shift out data from MBISD. */
#define CA7_BIT_DIAG_START                 ((u32)0x00000001 << 13)          /*!<R 0  diagnosis start When failure is tested, diagnosis start will be asserted and deasserted until failure syndrome had been shifted out. */
#define CA7_MASK_BIST_LOOP_MODE            ((u32)0x00000003 << 15)          /*!<R/W 0  When the bist loop is set to 00, the coordinator can test every bank within a single memory. When the bist loop is set to 01, the coordinator can test a single memory bank repeatedly til the bist loop is set to 00. When the bist loop is set to 10, the coordinator can test a single memory bank. */
#define CA7_BIST_LOOP_MODE(x)              ((u32)(((x) & 0x00000003) << 15))
#define CA7_GET_BIST_LOOP_MODE(x)          ((u32)(((x >> 15) & 0x00000003)))
/** @} */

/** @defgroup CA7_DIAG_RCV_DATA_0
 * @brief diagnosis receive data bit[31:0]
 * @{
 **/
#define CA7_MASK_DIAG_RCV_DATA_0           ((u32)0xFFFFFFFF << 0)          /*!<R 0  diagnosis shift out data package [31:0]. */
#define CA7_DIAG_RCV_DATA_0(x)             ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CA7_GET_DIAG_RCV_DATA_0(x)         ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup CA7_DIAG_RCV_DATA_1
 * @brief diagnosis receive data bit[63:32]
 * @{
 **/
#define CA7_MASK_DIAG_RCV_DATA_1           ((u32)0xFFFFFFFF << 0)          /*!<R 0  diagnosis shift out data package [63:32]. */
#define CA7_DIAG_RCV_DATA_1(x)             ((u32)(((x) & 0xFFFFFFFF) << 0))
#define CA7_GET_DIAG_RCV_DATA_1(x)         ((u32)(((x >> 0) & 0xFFFFFFFF)))
/** @} */

/** @defgroup CA7_DIAG_RCV_DATA_2
 * @brief diagnosis receive data bit[94:64]
 * @{
 **/
#define CA7_MASK_DIAG_RCV_DATA_2           ((u32)0x7FFFFFFF << 0)          /*!<R 0  diagnosis shift out data package [94:64]. */
#define CA7_DIAG_RCV_DATA_2(x)             ((u32)(((x) & 0x7FFFFFFF) << 0))
#define CA7_GET_DIAG_RCV_DATA_2(x)         ((u32)(((x >> 0) & 0x7FFFFFFF)))
/** @} */

/** @defgroup CA7_TOP_DSS0
 * @brief CA7 top module C30 DSS
 * @{
 **/
#define CA7_MASK_TOP_DSS0_RO_SEL           ((u32)0x00000007 << 0)          /*!<R/W 3'h0  Ring Oscillator selection: 000: select dss_clk (for test mode) 001 : select 1st ring oscillator 010 : select 2nd ring oscillator 011 : select 3rd ring oscillator 100 : select 4th ring oscillator 101 : select multi-library ring oscillator Others : not used */
#define CA7_TOP_DSS0_RO_SEL(x)             ((u32)(((x) & 0x00000007) << 0))
#define CA7_GET_TOP_DSS0_RO_SEL(x)         ((u32)(((x >> 0) & 0x00000007)))
#define CA7_BIT_TOP_DSS0_SPEED_EN          ((u32)0x00000001 << 3)          /*!<R/W 1'b0  Speed sensor enable of each DSS 0: disable 1: enable */
#define CA7_BIT_TOP_DSS0_WIRE_SEL          ((u32)0x00000001 << 4)          /*!<R/W 1'b0  wire selection 0: loong wire/delay cell/clock buffer 1: short wire */
#define CA7_BIT_TOP_DSS0_RST_N             ((u32)0x00000001 << 5)          /*!<R/W 1'b0  rst_n Reset signal of each Speed-Sensor (low active) (Software control reset) */
#define CA7_BIT_TOP_DSS0_READY             ((u32)0x00000001 << 6)          /*!<R 1'b0  Ready strobe to read count_out value for each DSS. */
#define CA7_BIT_TOP_DSS0_WSORT_GO          ((u32)0x00000001 << 7)          /*!<R 1'b0  0: measured speed slower than expected. 1: measured speed faster than expected. */
#define CA7_MASK_TOP_DSS0_COUNT_OUT        ((u32)0x000FFFFF << 8)          /*!<R 20'h0  count_out[19:0] is counter value indicates the speed of selected ring oscillator Cycle time = (count_out*dss_clk period)/ 16384 */
#define CA7_TOP_DSS0_COUNT_OUT(x)          ((u32)(((x) & 0x000FFFFF) << 8))
#define CA7_GET_TOP_DSS0_COUNT_OUT(x)      ((u32)(((x >> 8) & 0x000FFFFF)))
/** @} */

/** @defgroup CA7_TOP_DSS1
 * @brief CA7 top module C35 DSS
 * @{
 **/
#define CA7_MASK_TOP_DSS1_RO_SEL           ((u32)0x00000007 << 0)          /*!<R/W 3'h0  Ring Oscillator selection: 000: select dss_clk (for test mode) 001 : select 1st ring oscillator 010 : select 2nd ring oscillator 011 : select 3rd ring oscillator 100 : select 4th ring oscillator 101 : select multi-library ring oscillator Others : not used */
#define CA7_TOP_DSS1_RO_SEL(x)             ((u32)(((x) & 0x00000007) << 0))
#define CA7_GET_TOP_DSS1_RO_SEL(x)         ((u32)(((x >> 0) & 0x00000007)))
#define CA7_BIT_TOP_DSS1_SPEED_EN          ((u32)0x00000001 << 3)          /*!<R/W 1'b0  Speed sensor enable of each DSS 0: disable 1: enable */
#define CA7_BIT_TOP_DSS1_WIRE_SEL          ((u32)0x00000001 << 4)          /*!<R/W 1'b0  wire selection 0: loong wire/delay cell/clock buffer 1: short wire */
#define CA7_BIT_TOP_DSS1_RST_N             ((u32)0x00000001 << 5)          /*!<R/W 1'b0  rst_n Reset signal of each Speed-Sensor (low active) (Software control reset) */
#define CA7_BIT_TOP_DSS1_READY             ((u32)0x00000001 << 6)          /*!<R 1'b0  Ready strobe to read count_out value for each DSS. */
#define CA7_BIT_TOP_DSS1_WSORT_GO          ((u32)0x00000001 << 7)          /*!<R 1'b0  0: measured speed slower than expected. 1: measured speed faster than expected. */
#define CA7_MASK_TOP_DSS1_COUNT_OUT        ((u32)0x000FFFFF << 8)          /*!<R 20'h0  count_out[19:0] is counter value indicates the speed of selected ring oscillator Cycle time = (count_out*dss_clk period)/ 16384 */
#define CA7_TOP_DSS1_COUNT_OUT(x)          ((u32)(((x) & 0x000FFFFF) << 8))
#define CA7_GET_TOP_DSS1_COUNT_OUT(x)      ((u32)(((x >> 8) & 0x000FFFFF)))
/** @} */

/** @defgroup CA7_TOP_DSS2
 * @brief CA7 top module C40 DSS
 * @{
 **/
#define CA7_MASK_TOP_DSS2_RO_SEL           ((u32)0x00000007 << 0)          /*!<R/W 3'h0  Ring Oscillator selection: 000: select dss_clk (for test mode) 001 : select 1st ring oscillator 010 : select 2nd ring oscillator 011 : select 3rd ring oscillator 100 : select 4th ring oscillator 101 : select multi-library ring oscillator Others : not used */
#define CA7_TOP_DSS2_RO_SEL(x)             ((u32)(((x) & 0x00000007) << 0))
#define CA7_GET_TOP_DSS2_RO_SEL(x)         ((u32)(((x >> 0) & 0x00000007)))
#define CA7_BIT_TOP_DSS2_SPEED_EN          ((u32)0x00000001 << 3)          /*!<R/W 1'b0  Speed sensor enable of each DSS 0: disable 1: enable */
#define CA7_BIT_TOP_DSS2_WIRE_SEL          ((u32)0x00000001 << 4)          /*!<R/W 1'b0  wire selection 0: loong wire/delay cell/clock buffer 1: short wire */
#define CA7_BIT_TOP_DSS2_RST_N             ((u32)0x00000001 << 5)          /*!<R/W 1'b0  rst_n Reset signal of each Speed-Sensor (low active) (Software control reset) */
#define CA7_BIT_TOP_DSS2_READY             ((u32)0x00000001 << 6)          /*!<R 1'b0  Ready strobe to read count_out value for each DSS. */
#define CA7_BIT_TOP_DSS2_WSORT_GO          ((u32)0x00000001 << 7)          /*!<R 1'b0  0: measured speed slower than expected. 1: measured speed faster than expected. */
#define CA7_MASK_TOP_DSS2_COUNT_OUT        ((u32)0x000FFFFF << 8)          /*!<R 20'h0  count_out[19:0] is counter value indicates the speed of selected ring oscillator Cycle time = (count_out*dss_clk period)/ 16384 */
#define CA7_TOP_DSS2_COUNT_OUT(x)          ((u32)(((x) & 0x000FFFFF) << 8))
#define CA7_GET_TOP_DSS2_COUNT_OUT(x)      ((u32)(((x >> 8) & 0x000FFFFF)))
/** @} */

/** @defgroup CA7_TOP_DSS_DATA_IN_0
 * @brief
 * @{
 **/
#define CA7_MASK_TOP_DSS0_DATA_IN          ((u32)0x000FFFFF << 0)          /*!<R/W 20'h0  Input data for speed comparison */
#define CA7_TOP_DSS0_DATA_IN(x)            ((u32)(((x) & 0x000FFFFF) << 0))
#define CA7_GET_TOP_DSS0_DATA_IN(x)        ((u32)(((x >> 0) & 0x000FFFFF)))
/** @} */

/** @defgroup CA7_TOP_DSS_DATA_IN_1
 * @brief
 * @{
 **/
#define CA7_MASK_TOP_DSS1_DATA_IN          ((u32)0x000FFFFF << 0)          /*!<R/W 20'h0  Input data for speed comparison */
#define CA7_TOP_DSS1_DATA_IN(x)            ((u32)(((x) & 0x000FFFFF) << 0))
#define CA7_GET_TOP_DSS1_DATA_IN(x)        ((u32)(((x >> 0) & 0x000FFFFF)))
/** @} */

/** @defgroup CA7_TOP_DSS_DATA_IN_2
 * @brief
 * @{
 **/
#define CA7_MASK_TOP_DSS2_DATA_IN          ((u32)0x000FFFFF << 0)          /*!<R/W 20'h0  Input data for speed comparison */
#define CA7_TOP_DSS2_DATA_IN(x)            ((u32)(((x) & 0x000FFFFF) << 0))
#define CA7_GET_TOP_DSS2_DATA_IN(x)        ((u32)(((x >> 0) & 0x000FFFFF)))
/** @} */
/** @} */



/* Exported types --------------------------------------------------------*/

/** @defgroup CA7_Exported_Types CA7 Exported Types
  * @{
*****************************************************************************/


/**
 * @brief AMEBAD2_CA7 Register Declaration
 *****************************************************************************/
typedef struct {
	__IO uint32_t CA7_C0_MISC_CTRL;                       /*!<  Register,  Address offset: 0x00 */
	__IO uint32_t CA7_C0_RST_CTRL;                        /*!< CLUSTER 0 RESET CONTROL REGISTER,  Address offset: 0x04 */
	__I  uint32_t CA7_C0_CPU_STATUS;                      /*!< CLUSTER0 CPU STATUS REGISTER,  Address offset: 0x08 */
	__IO uint32_t RSVD0;                                  /*!<  Reserved,  Address offset:0xC */
	__IO uint32_t CA7_C0_CTRL_REG0;                       /*!< CLUSTER 0 CONTROL REGISTER0 Register,  Address offset: 0x10 */
	__IO uint32_t RSVD1[11];                              /*!<  Reserved,  Address offset:0x14-0x3C */
	__IO uint32_t CA7_APLL_CTRL0;                         /*!<  Register,  Address offset: 0x40 */
	__IO uint32_t CA7_APLL_CTRL1;                         /*!<  Register,  Address offset: 0x44 */
	__IO uint32_t CA7_APLL_CTRL2;                         /*!<  Register,  Address offset: 0x48 */
	__IO uint32_t CA7_APLL_CTRL3;                         /*!<  Register,  Address offset: 0x4C */
	__IO uint32_t CA7_APLL_CTRL4;                         /*!<  Register,  Address offset: 0x50 */
	__IO uint32_t CA7_APLL_CTRL5;                         /*!<  Register,  Address offset: 0x54 */
	__IO uint32_t CA7_APLL_CTRL6;                         /*!<  Register,  Address offset: 0x58 */
	__IO uint32_t RSVD2;                                  /*!<  Reserved,  Address offset:0x5C */
	__I  uint32_t CA7_DSS0;                               /*!<  Register,  Address offset: 0x60 */
	__I  uint32_t CA7_DSS1;                               /*!<  Register,  Address offset: 0x64 */
	__IO uint32_t CA7_DSS2;                               /*!<  Register,  Address offset: 0x68 */
	__IO uint32_t CA7_LPS_CTRL;                           /*!<  Register,  Address offset: 0x6C */
	__IO uint32_t CA7_SRAM_CTRL0;                         /*!<  Register,  Address offset: 0x70 */
	__IO uint32_t CA7_SRAM_CTRL1;                         /*!<  Register,  Address offset: 0x74 */
	__IO uint32_t CA7_SRAM_CTRL2;                         /*!<  Register,  Address offset: 0x78 */
	__IO uint32_t CA7_COOR_CTRL0;                         /*!<  Register,  Address offset: 0x7C */
	__I  uint32_t CA7_COOR_CTRL1;                         /*!<  Register,  Address offset: 0x80 */
	__IO uint32_t CA7_COOR_CTRL2;                         /*!<  Register,  Address offset: 0x84 */
	__IO uint32_t CA7_COOR_CTRL3;                         /*!<  Register,  Address offset: 0x88 */
	__I  uint32_t CA7_DIAG_RCV_DATA_0;                    /*!< DIAGNOSIS RECEIVE DATA BIT[31:0] Register,  Address offset: 0x8C */
	__I  uint32_t CA7_DIAG_RCV_DATA_1;                    /*!< DIAGNOSIS RECEIVE DATA BIT[63:32] Register,  Address offset: 0x90 */
	__I  uint32_t CA7_DIAG_RCV_DATA_2;                    /*!< DIAGNOSIS RECEIVE DATA BIT[94:64] Register,  Address offset: 0x94 */
	__IO uint32_t CA7_TOP_DSS0;                           /*!< CA7 TOP MODULE C30 DSS Register,  Address offset: 0x98 */
	__IO uint32_t CA7_TOP_DSS1;                           /*!< CA7 TOP MODULE C35 DSS Register,  Address offset: 0x9C */
	__IO uint32_t CA7_TOP_DSS2;                           /*!< CA7 TOP MODULE C40 DSS Register,  Address offset: 0xA0 */
	__IO uint32_t CA7_TOP_DSS_DATA_IN_0;                  /*!<  Register,  Address offset: 0xA4 */
	__IO uint32_t CA7_TOP_DSS_DATA_IN_1;                  /*!<  Register,  Address offset: 0xA8 */
	__IO uint32_t CA7_TOP_DSS_DATA_IN_2;                  /*!<  Register,  Address offset: 0xAC */
} CA7_TypeDef;

#define CA7_BASE ((CA7_TypeDef *) (0x41000200))

/** @} */
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your defination here

/* MANUAL_GEN_END */

#endif

/** @} */

/** @} */
