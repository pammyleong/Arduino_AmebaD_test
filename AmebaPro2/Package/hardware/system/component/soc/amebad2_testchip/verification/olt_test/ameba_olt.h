#include "ameba_soc.h"
#include "ameba_olt_ft_adc_dac.h"

/** @brief Log Module Definition */
typedef enum {
	_EQC_GPIO		= 0,
	_EQC_I2C		, // 1
	_EQC_UART		, // 2
	_EQC_SPI		, // 3

	_EQC_FLASH		, // 4
	_EQC_DDR		, // 5
	_EQC_USB		, // 6
	_EQC_AUDIO		, // 7

	_EQC_ADC		, // 8
	_EQC_MIPI		, // 9
	_EQC_CAPTOUCH 	, // 10
	_EQC_WIFI		, // 11

	_EQC_BT 		, // 12
	_EQC_USBLOOP	, // 13
	_EQC_APCore		, // 14
	_EQC_MAX		, // 15

	_EQC_IGNORE 	= 0xFF, //
} EQC_ITEMS_DEFINE;

typedef struct _EQC_CASE_TABLE_ {
	char *name;
	u32  Index;
	u32  CaseFlag;
	u32  ErrStatus;
	u32  DoneFlag;
	//u32(*func)(u16 argc, u8 *argv[]);
	//const   u8 *msg;
} EQC_CASE_TABLE, *PEQC_CASE_TABLE;


typedef enum {
	_LED_INIT				= 0,
	_LED_SPEED_NORMAL	, // 2
	_LED_SPEED_SLEEP	, // 3
	_LED_SPEED_ERROR	, // 4
	_LED_OFF			, // 1
} OLT_LED_MODE;

#define EQC_DONE_FLAG_REG	0x4200D010
#define EQC_ERROR_FLAG_REG	BKUP_REG1

/*
 * @brief: Burn In PIN selection and LED
 */
#define OLT_Mode_SEL_PIN	_PA_5
#define OLT_LED_PIN			_PA_6

/*
 * @brief: I2C TEST PIN
 */
// HP_I2C1
#define EQC_I2C_MTR_SDA    _PA_13
#define EQC_I2C_MTR_SCL    _PA_14
// HP_I2C2
#define EQC_I2C_SLV_SDA    _PA_15
#define EQC_I2C_SLV_SCL    _PA_16

/*
 * UART TEST PIN
 */
#define EQC_UARTA_TX        _PB_11
#define EQC_UARTA_RX        _PB_10
#define EQC_UARTB_TX        _PB_22
#define EQC_UARTB_RX        _PB_21

#define UART_LOOPBACK_EN	1
#define D_UART_TX_FIFO_SIZE 16

/*
 * @brief: ADC Test Items
 */
#define ADC_ROUTE_NUM	2

#define BAIS1_ADC_CH	_PA_2
#define EQC_VBAT_MEAS	_PA_6
#define EQC_BIAS1		_PA_30
#define EQC_BIAS2		_PA_31

//================================= olt functions start =================================
void eqc_loguartAGGoff(void);

void olt_adcsampleTest(void);
void olt_gpioloopbackTest(u8 gpio_in, u8 gpio_out);
void olt_uartloopbackTest(void);
void olt_i2cloopTest(void);
void olt_usbloopbackTest(void);
void olt_enterdeepsleep(void);
void olt_ddrStatusCheck(void);
void olt_thermal_result(void);
void olt_thermal_init(void);
void olt_apCoreStatusCheck(void);
#ifdef CONFIG_WIFI_EN
#ifdef CONFIG_MP_INCLUDED
void wifi_mp_ctx_thread(void);  // add test for mp_image:ctx start when boot success
#endif
#endif

void example_audio_ft_test(void);

//================================= olt functions end =================================


