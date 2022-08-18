#ifndef _AMEBAD2_TIMERBASIC_H_
#define _AMEBAD2_TIMERBASIC_H_

/* AUTO_GEN_START */

/**************************************************************************//**
 * @defgroup TM_TIM_EN
 * @brief TIM enable register
 * @{
 *****************************************************************************/
#define TM_SHIFT_CNT_EN                              16
#define TM_BIT_CNT_EN                                ((u32)0x00000001 << TM_SHIFT_CNT_EN)                              /*!<R 0x0  counter working status * 0: counter is stoppped * 1: counter is working */
#define TM_SHIFT_CNT_RUN                             8
#define TM_BIT_CNT_RUN                               ((u32)0x00000001 << TM_SHIFT_CNT_RUN)                             /*!<R 0x0  counter run status * 0: counter is disabled * 1: counter is enabled */
#define TM_SHIFT_CNT_STOP                            1
#define TM_BIT_CNT_STOP                              ((u32)0x00000001 << TM_SHIFT_CNT_STOP)                            /*!<WA0 0x0  disable the counter. Poll CNT_RUN to see the counter status. If CNT_RUN is 0, it means that the counter has been disabled internally. */
#define TM_SHIFT_CNT_START                           0
#define TM_BIT_CNT_START                             ((u32)0x00000001 << TM_SHIFT_CNT_START)                           /*!<WA0 0x0  enable the counter. Poll CNT_RUN to see the counter status. If CNT_RUN is 1, it means that the counter has been enabled internally. */
/** @} */

/**************************************************************************//**
 * @defgroup TM_TIM_CR
 * @brief TIM control register
 * @{
 *****************************************************************************/
#define TM_SHIFT_ARPE                                4
#define TM_BIT_ARPE                                  ((u32)0x00000001 << TM_SHIFT_ARPE)                                /*!<R/W 0x0  enable auto-reload preloading * 0: TIM_ARR register is not buffered * 1: TIM_ARR register is buffered */
#define TM_SHIFT_URS                                 2
#define TM_BIT_URS                                   ((u32)0x00000001 << TM_SHIFT_URS)                                 /*!<R/W 0x0  update request source * 0: counter overflow and setting the UG bit * 1: counter overflow */
#define TM_SHIFT_UDIS                                1
#define TM_BIT_UDIS                                  ((u32)0x00000001 << TM_SHIFT_UDIS)                                /*!<R/W 0x0  disable UEV. Shadow registers keep their values. Otherwise, buffered registers are then loaded with their preload values when UEV happen. */
/** @} */

/**************************************************************************//**
 * @defgroup TM_TIM_DIER
 * @brief TIM interupt enable register
 * @{
 *****************************************************************************/
#define TM_SHIFT_UIE                                 0
#define TM_BIT_UIE                                   ((u32)0x00000001 << TM_SHIFT_UIE)                                 /*!<R/W 0x0  enable update interrupt */
/** @} */

/**************************************************************************//**
 * @defgroup TM_TIM_SR
 * @brief TIM status register
 * @{
 *****************************************************************************/
#define TM_SHIFT_UG_DONE                             31
#define TM_BIT_UG_DONE                               ((u32)0x00000001 << TM_SHIFT_UG_DONE)                             /*!<R 0x1  UG operation status This bit is cleared by hardware when the UG bit in the TIMx_EGR register is set. When the UG operation is done, hardware set this bit to ‘1’. So, software can poll this bit to see the UG operation status. */
#define TM_SHIFT_UIF                                 0
#define TM_BIT_UIF                                   ((u32)0x00000001 << TM_SHIFT_UIF)                                 /*!<R/W1C/ES 0x0  update interrupt flag */
/** @} */

/**************************************************************************//**
 * @defgroup TM_TIM_EGR
 * @brief TIM event generation register
 * @{
 *****************************************************************************/
#define TM_SHIFT_UG                                  0
#define TM_BIT_UG                                    ((u32)0x00000001 << TM_SHIFT_UG)                                  /*!<WA0 0x0  update generation. Re-initialize the counter and generate an update of registers. Note that the prescaler counter is cleared too.(anyway the prescaler ratio is not affected) */
/** @} */

/**************************************************************************//**
 * @defgroup TM_TIM_CNT
 * @brief TIM counter
 * @{
 *****************************************************************************/
#define TM_SHIFT_CNT                                 0
#define TM_MASK_CNT                                  ((u32)0xFFFFFFFF << TM_SHIFT_CNT)                                 /*!<R 0x0  counter value */
/** @} */

/**************************************************************************//**
 * @defgroup TM_TIM_ARR
 * @brief TIM auto
 * @{
 *****************************************************************************/
#define TM_SHIFT_ARR                                 0
#define TM_MASK_ARR                                  ((u32)0xFFFFFFFF << TM_SHIFT_ARR)                                 /*!<R/W 0xFFFFFFFF  the value to be loaded in the actual auto-reload register. It can be preloaded by setting ARPE bit in TIM_CR. */
/** @} */

/**************************************************************************//**
 * @defgroup TM_TIM_SEC
 * @brief TIM security control register
 * @{
 *****************************************************************************/
#define TM_SHIFT_SEC                                 0
#define TM_BIT_SEC                                   ((u32)0x00000001 << TM_SHIFT_SEC)                                 /*!<R/W 0x0  Secure timer enable. 0: This is a non-secure timer. All its registers except TIMx_SEC can be accessed from both secure and non-secure address. As a result, both secure and non-secure code can access it. 1: This is a secure timer. All its registers can only be accessed from secure address. As a result, only secure code can access it. Non-secure code can't access it through non-secure address. */
/** @} */



/**************************************************************************//**
 * @defgroup AMEBAD2_TIMERBASIC
 * @{
 * @brief AMEBAD2_TIMERBASIC Register Declaration
 *****************************************************************************/
typedef struct {
	__O  uint32_t TM_TIM_EN;                              /*!< TIM ENABLE REGISTER,  Address offset: 0x000 */
	__IO uint32_t TM_TIM_CR;                              /*!< TIM CONTROL REGISTER,  Address offset: 0x004 */
	__IO uint32_t TM_TIM_DIER;                            /*!< TIM INTERUPT ENABLE REGISTER,  Address offset: 0x008 */
	__IO uint32_t TM_TIM_SR;                              /*!< TIM STATUS REGISTER,  Address offset: 0x00C */
	__O  uint32_t TM_TIM_EGR;                             /*!< TIM EVENT GENERATION REGISTER,  Address offset: 0x010 */
	__I  uint32_t TM_TIM_CNT;                             /*!< TIM COUNTER Register,  Address offset: 0x014 */
	__IO uint32_t RSVD0;                                  /*!<  Reserved,  Address offset:0x18 */
	__IO uint32_t TM_TIM_ARR;                             /*!< TIM AUTO-RELOAD REGISTER,  Address offset: 0x01C */
	__IO uint32_t TM_TIM_SEC;                             /*!< TIM SECURITY CONTROL REGISTER,  Address offset: 0x020 */
} TIMERBASIC_TypeDef;
/** @} */
/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your defination here

/* MANUAL_GEN_END */

#endif
