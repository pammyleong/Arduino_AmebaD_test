#ifndef _EXAMPLE_GUI_GRAPHIC_MIPI_H
#define _EXAMPLE_GUI_GRAPHIC_MIPI_H

#include "lvgl.h"
#include "ameba_soc.h"

#define LCDC_TEST_IMG_BUF_X             480 //240 //(272)
#define LCDC_TEST_IMG_BUF_Y             800 //320 //(480)

#define LCDC_IMG_BUF_OFFSET             (7 << 20) /*offset is 20M In DDR or PSRAM */
#define LCDC_IMG_BUF_ALIGNED64B(x)      (((x) & ~0x3F) + 0x40)/*Start Addr shall aligned to 64Byte*/
#define LCDC_IMG_BUF_SIZE               LCDC_IMG_BUF_ALIGNED64B(LCDC_TEST_IMG_BUF_X * LCDC_TEST_IMG_BUF_Y * 4)

#define RGB_BLACK           0x00000000
#define RGB_WHITE           0xFFFFFFFF

#define REGFLAG_DELAY                       0xFC
#define REGFLAG_END_OF_TABLE                0xFD    // END OF REGISTERS MARKER

#define Mhz                                 1000000UL
#define T_LPX       5
#define T_HS_PREP   6
#define T_HS_TRAIL  8
#define T_HS_EXIT   7
#define T_HS_ZERO   10

#define MIPI_DSI_RTNI       2//4
#define MIPI_DSI_HSA        4
#define MIPI_DSI_HBP        30
#define MIPI_DSI_HFP        30

#define MIPI_DSI_VSA        5
#define MIPI_DSI_VBP        20
#define MIPI_DSI_VFP        15

/*=========MIPI IRQ Info=========*/
typedef struct MIPI_Irq {
	u32 IrqNum;
	u32 IrqData;
	u32 IrqPriority;
} MIPI_IRQInfo;

typedef struct {
	u8 dataid;
	u8 byte0;
	u8 byte1;
} cmd_header_t;

typedef struct LCM_setting_table {
	u8 cmd;
	u8 count;
	u8 para_list[128];
} LCM_setting_table_t;

typedef struct {
	u8 blue;
	u8 green;
	u8 red;
	u8 alpha;
} argb8888_t;

typedef struct {
	u8 blue;
	u8 green;
	u8 red;
} rgb888_t;

void mipi_init(void);
void mipi_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);

#endif