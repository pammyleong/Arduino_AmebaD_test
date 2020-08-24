#ifndef EPDIF_H
#define EPDIF_H
#include <Arduino.h>

// Define Pin Initialisation
#define BUSY_Pin    8
#define RES_Pin     9
#define DC_Pin     10
#define CS_Pin     11
#define SCK_Pin    12
#define SDI_Pin    13

#define EPD_W21_MOSI_0  digitalWrite(SDI_Pin,LOW)
#define EPD_W21_MOSI_1  digitalWrite(SDI_Pin,HIGH)

#define EPD_W21_CLK_0   digitalWrite(SCK_Pin,LOW)
#define EPD_W21_CLK_1   digitalWrite(SCK_Pin,HIGH)

#define EPD_W21_CS_0    digitalWrite(CS_Pin,LOW)
#define EPD_W21_CS_1    digitalWrite(CS_Pin,HIGH)

#define EPD_W21_DC_0    digitalWrite(DC_Pin,LOW)
#define EPD_W21_DC_1    digitalWrite(DC_Pin,HIGH)
#define EPD_W21_RST_0   digitalWrite(RES_Pin,LOW)
#define EPD_W21_RST_1   digitalWrite(RES_Pin,HIGH)
#define isEPD_W21_BUSY  digitalRead(BUSY_Pin)

#define MONOMSB_MODE           1
#define MONOLSB_MODE           2
#define RED_MODE               3

#define MAX_LINE_BYTES         16       // =128/8
#define MAX_COLUMN_BYTES      296

#define ALLSCREEN_GRAGHBYTES 4736

class EpdIf {
  public:
    EpdIf(void);
    ~EpdIf(void);
    //////// Internal Functions ////////
    void driver_delay_us(unsigned int xus);
    void driver_delay_xms(unsigned long xms);
    void DELAY_S(unsigned int delaytime);

    void SPI_Delay(unsigned char xrate);
    void SPI_Write(unsigned char value);
    //    void SPI_Write(u8 TxData);

    void EPD_W21_WriteDATA(unsigned char command);
    void EPD_W21_WriteCMD(unsigned char command);

    //    void EPD_W21_WriteCMD(u8 cmd);
    //    void EPD_W21_WriteDATA(u8 data);

    void EPD_select_LUT(const unsigned char * wave_data);
    void EPD_HW_Init(void);           //Electronic paper initialization
    void EPD_Update(void);
    void EPD_Dis_Part(
      unsigned int x_start,
      unsigned int y_start,
      const unsigned char * datas,
      unsigned int PART_COLUMN,
      unsigned int PART_LINE
    );

    void EPD_Part_Init(void);
    void EPD_Part_Update(void);
    void EPD_SetRAMValue_BaseMap(const unsigned char * datas);

    //Display
    void EPD_WhiteScreen_ALL(void);
    void EPD_WhiteScreen_White(void);
    void EPD_WhiteScreen_Black(void);

    void Epaper_READBUSY(void);
    void Epd_WaitUntilIdle(void);
    void EPD_DeepSleep(void);
    void EPD_Reset(void);



};
#endif
