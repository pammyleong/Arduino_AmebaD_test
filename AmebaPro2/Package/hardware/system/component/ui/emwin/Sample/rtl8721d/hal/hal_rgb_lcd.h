
//
// Physical display parameters
//
#define LCD_HSW				123
#define LCD_HFP				6
#define LCD_HBP				6
#define LCD_VSW				10
#define LCD_VFP				2
#define LCD_VBP				2
#define LCD_SyncMode		LCDC_RGB_DE_MODE
#define LCD_SampleEdge		LCDC_RGB_DCLK_FALLING_EDGE_FETCH
#define LCD_RefreshFreq		50

void lcd_init(unsigned int width, unsigned int height, unsigned int bufAddr);
void lcd_set_dma_addr(unsigned int bufAddr);

