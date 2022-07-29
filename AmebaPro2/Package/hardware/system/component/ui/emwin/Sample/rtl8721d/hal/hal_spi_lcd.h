

typedef enum
{
	SPI_CMD_WMEM			= 0x2C,
	SPI_CMD_SETX			= 0x2A,
	SPI_CMD_SETY			= 0x2B,
} SPI_LCD_COMMAND;


void lcd_spi_write(int x0, int y0, int x1, int y1, void *buf, unsigned int color);
void lcd_init(void);

