

typedef enum
{
	MCU_CMD_WMEM			= 0x2C,
	MCU_CMD_SETX			= 0x2A,
	MCU_CMD_SETY			= 0x2B,
	MCU_CMD_RMEM			= 0x2E,
} MCU_LCD_COMMAND;


void lcd_mcu_write(int x0, int y0, int x1, int y1, void *buf, unsigned int color);
void lcd_mcu_read(int x0, int y0, int x1, int y1, void *buf);
void lcd_init(void);

