#include "epdif.h"
#include "image.h"
#include <SPI.h>

EpdIf::EpdIf() {
};

EpdIf::~EpdIf() {
};

void EpdIf::driver_delay_us(unsigned int xus) {
  for (; xus > 1; xus--);
}

void EpdIf::driver_delay_xms(unsigned long xms) {//1ms
  unsigned long i = 0 , j = 0;
  for (j = 0; j < xms; j++)  {
    for (i = 0; i < 256; i++);
  }
}

void EpdIf::DELAY_S(unsigned int delaytime) {
  unsigned int i, j, k;
  for (i = 0; i < delaytime; i++)  {
    for (j = 0; j < 4000; j++)    {
      for (k = 0; k < 222; k++);
    }
  }
}

//////////////////////SPI///////////////////////////////////
void EpdIf::SPI_Delay(unsigned char xrate) {
  unsigned char i;
  while (xrate)  {
    for (i = 0; i < 2; i++);
    xrate--;
  }
}


/**
    @brief: basic function for transfering data
*/
void EpdIf::SPI_Write(unsigned char value) {
  unsigned char i;
  this->SPI_Delay(1);
  for (i = 0; i < 8; i++)  {
    EPD_W21_CLK_0;
    this->SPI_Delay(1);
    if (value & 0x80)
      EPD_W21_MOSI_1;
    else
      EPD_W21_MOSI_0;
    value = (value << 1);
    this->SPI_Delay(1);
    this->driver_delay_us(1);
    EPD_W21_CLK_1;
    this->SPI_Delay(1);
  }
}

/**
    @brief: basic function for sending commands
*/
void EpdIf::EPD_W21_WriteCMD(unsigned char command) {
  this->SPI_Delay(1);
  EPD_W21_CS_0;
  EPD_W21_DC_0;   // command write
  this->SPI_Write(command);
  EPD_W21_CS_1;
}

/**
    @brief: basic function for sending data
*/
void EpdIf::EPD_W21_WriteDATA(unsigned char command) {
  this->SPI_Delay(1);
  EPD_W21_CS_0;
  EPD_W21_DC_1;   // command write
  this->SPI_Write(command);
  EPD_W21_CS_1;
}

/**
    @brief: Wait until the busy_pin goes LOW
*/
void EpdIf::Epaper_READBUSY(void) {
  while (1)  { //=1 BUSY
    if (isEPD_W21_BUSY == 0) break;
  }
}

/**
    @brief: Same as Epaper_READBUSY
*/
void EpdIf::Epd_WaitUntilIdle(void) {
  this->Epaper_READBUSY();
}

/**
    @brief: module reset.
            often used to awaken the module in deep sleep,
            see Epd::Sleep();
*/
void EpdIf::EPD_Reset(void) {
  EPD_W21_RST_0;            // Module reset
  delay(1);                 // At least 10ms delay
  EPD_W21_RST_1;
  delay(1);
}

/**
    @brief: After this command is transmitted, the chip would enter the
            deep-sleep mode to save power.
            The deep sleep mode would return to standby by hardware reset.
            You can use Epd::Init() to awaken
*/
void EpdIf::EPD_DeepSleep(void) {
  this->EPD_W21_WriteCMD (0x10); //enter deep sleep, DEEP_SLEEP_MODE = 0x10
  this->EPD_W21_WriteDATA(0x01);
  delay(100);
}

//////////////////////LUT///////////////////////////////////
const unsigned char LUT_DATA[] PROGMEM = {   //30 bytes
  //C221 25C Full update waveform
  0x50, 0xAA, 0x55, 0xAA, 0x11, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xFF, 0xFF, 0x1F, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char LUT_DATA_part[] PROGMEM = { //30 bytes
  //C221 25C partial update waveform
  0x10, 0x18, 0x18, 0x08, 0x18, 0x18,
  0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x13, 0x14, 0x44, 0x12,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/**
    @brief: set the look-up table register
*/
void EpdIf::EPD_select_LUT(const unsigned char * wave_data) {
  unsigned char count;
  this->EPD_W21_WriteCMD(0x32);
  for (count = 0; count < 30; count++)
    this->EPD_W21_WriteDATA(pgm_read_byte(&wave_data[count]));
}

//////////////////////EPD//////////////////////////////////
void EpdIf::EPD_HW_Init(void) {
  EPD_W21_RST_0;  // Module reset
  delay(1); //At least 10ms delay
  EPD_W21_RST_1;
  delay(1); //At least 10ms delay

  this->EPD_W21_WriteCMD(0x01); //Driver output control
  this->EPD_W21_WriteDATA(0x27); //Y%256--->(295+1)=296
  this->EPD_W21_WriteDATA(0x01); //Y%256
  this->EPD_W21_WriteDATA(0x00);

  this->EPD_W21_WriteCMD(0x0C); //softstart
  this->EPD_W21_WriteDATA(0xD7);   //is necessary
  this->EPD_W21_WriteDATA(0xD6);   //is necessary
  this->EPD_W21_WriteDATA(0x9D);  //is necessary

  this->EPD_W21_WriteCMD(0x2C);     //VCOM Voltage
  this->EPD_W21_WriteDATA(0x9A);

  this->EPD_W21_WriteCMD(0x3A);     //Dummy Line
  this->EPD_W21_WriteDATA(0x1A);
  this->EPD_W21_WriteCMD(0x3B);     //Gate time
  this->EPD_W21_WriteDATA(0X08);

  this->EPD_W21_WriteCMD(0x11); //data entry mode
  this->EPD_W21_WriteDATA(0x01);

  this->EPD_W21_WriteCMD(0x3C); //BorderWavefrom
  this->EPD_W21_WriteDATA(0x33);

  this->EPD_W21_WriteCMD(0x44); //set Ram-X address start/end position
  this->EPD_W21_WriteDATA(0x00);
  this->EPD_W21_WriteDATA(0x0F);    //0x0C-->(15+1)*8=128

  this->EPD_W21_WriteCMD(0x45); //set Ram-Y address start/end position
  this->EPD_W21_WriteDATA(0x27);   //Y%256--->(295+1)=296
  this->EPD_W21_WriteDATA(0x01);  //Y%256
  this->EPD_W21_WriteDATA(0x00);
  this->EPD_W21_WriteDATA(0x00);

  this->EPD_W21_WriteCMD(0x4E);   // set RAM x address count to 0;
  this->EPD_W21_WriteDATA(0x00);
  this->EPD_W21_WriteCMD(0x4F);   // set RAM y address count to 0X127;
  this->EPD_W21_WriteDATA(0x27);  //Y%256
  this->EPD_W21_WriteDATA(0x01);  //Y/256
  this->Epaper_READBUSY();
  this->EPD_select_LUT(LUT_DATA); //LUT
}

/**
    @brief: update the display
            there are 2 memory areas embedded in the e-paper display
            but once this function is called,
            the the next action of SetFrameMemory or ClearFrame will
            set the other memory area.
*/
void EpdIf::EPD_Update(void) {
  this->EPD_W21_WriteCMD(0x22);  //Display Update Control
  this->EPD_W21_WriteDATA(0xC4);
  this->EPD_W21_WriteCMD(0x20);  //Activate Display Update Sequence
  this->Epaper_READBUSY();
}

void EpdIf::EPD_Part_Init(void) {
  this->EPD_HW_Init();            //Electronic paper initialization
  this->EPD_select_LUT(LUT_DATA_part);
  //POWER ON
  this->EPD_W21_WriteCMD(0x22);   //Display Update Control
  this->EPD_W21_WriteDATA(0xC0);
  this->EPD_W21_WriteCMD(0x20);   //Activate Display Update Sequence
  this->Epaper_READBUSY();
  this->EPD_W21_WriteCMD(0x3C);   //BorderWavefrom
  this->EPD_W21_WriteDATA(0x01);
}

void EpdIf::EPD_Part_Update(void) {
  this->EPD_W21_WriteCMD(0x22);
  this->EPD_W21_WriteDATA(0x04);  //different
  this->EPD_W21_WriteCMD(0x20);
  this->Epaper_READBUSY();
}

void EpdIf::EPD_SetRAMValue_BaseMap( const unsigned char * datas) {
  unsigned int i;
  const unsigned char  *datas_flag;
  unsigned int x_end, y_start1, y_start2, y_end1, y_end2;
  unsigned int x_start = 0, y_start = 296;
  unsigned int PART_COLUMN = 296, PART_LINE = 128;
  datas_flag = datas;
  //FULL update
  this->EPD_HW_Init();
  this->EPD_W21_WriteCMD(0x24);   //Write Black and White image to RAM
  for (i = 0; i < ALLSCREEN_GRAGHBYTES; i++)
  {
    this->EPD_W21_WriteDATA(pgm_read_byte(&datas[i]));
  }
  this->EPD_Update();
  delay(100);
  //PART update
  this->EPD_Part_Init();          //Local initialization (the top left corner of the screen is the origin of the coordinates)
  datas = datas_flag;             //Record array first address
  x_start = x_start / 8;          //Convert to byte
  x_end = (x_start + PART_LINE) / 8 - 1;
  y_start1 = 0;
  y_start2 = y_start - 1;

  if (y_start >= 256)  {
    y_start1 = y_start2 / 256;
    y_start2 = y_start2 % 256;
  }
  y_end1 = 0; //0
  y_end2 = 0; //0
  if (y_end2 >= 256)  {
    y_end1 = y_end2 / 256;
    y_end2 = y_end2 % 256;
  }

  this->EPD_W21_WriteCMD(0x44);       // set RAM x address start/end, in page 35
  this->EPD_W21_WriteDATA(x_start);    // RAM x address start at 00h;
  this->EPD_W21_WriteDATA(x_end);    // RAM x address end at 0fh(15+1)*8->128
  this->EPD_W21_WriteCMD(0x45);       // set RAM y address start/end, in page 35
  this->EPD_W21_WriteDATA(y_start2);    // RAM y address start at 0127h;
  this->EPD_W21_WriteDATA(y_start1);    // RAM y address start at 0127h;
  this->EPD_W21_WriteDATA(y_end2);    // RAM y address end at 00h;
  this->EPD_W21_WriteDATA(y_end1);    // ????=0
  this->EPD_W21_WriteCMD(0x4E);   // set RAM x address count to 0;
  this->EPD_W21_WriteDATA(x_start);
  this->EPD_W21_WriteCMD(0x4F);   // set RAM y address count to 0X127;
  this->EPD_W21_WriteDATA(y_start2);
  this->EPD_W21_WriteDATA(y_start1);
  this->EPD_W21_WriteCMD(0x24);   //Write Black and White image to RAM
  for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)  {
    this->EPD_W21_WriteDATA(pgm_read_byte(&datas[i]));
  }
  this->EPD_Part_Update();
  delay(100);

  datas = datas_flag;
  this->EPD_W21_WriteCMD(0x44);         // set RAM x address start/end, in page 35
  this->EPD_W21_WriteDATA(x_start);     // RAM x address start at 00h;
  this->EPD_W21_WriteDATA(x_end);       // RAM x address end at 0fh(15+1)*8->128
  this->EPD_W21_WriteCMD(0x45);         // set RAM y address start/end, in page 35
  this->EPD_W21_WriteDATA(y_start2);    // RAM y address start at 0127h;
  this->EPD_W21_WriteDATA(y_start1);    // RAM y address start at 0127h;
  this->EPD_W21_WriteDATA(y_end2);      // RAM y address end at 00h;
  this->EPD_W21_WriteDATA(y_end1);      // ????=0
  this->EPD_W21_WriteCMD(0x4E);         // set RAM x address count to 0;
  this->EPD_W21_WriteDATA(x_start);
  this->EPD_W21_WriteCMD(0x4F);         // set RAM y address count to 0X127;
  this->EPD_W21_WriteDATA(y_start2);
  this->EPD_W21_WriteDATA(y_start1);

  this->EPD_W21_WriteCMD(0x24);   // Write Black and White image to RAM
  for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)  {
    this->EPD_W21_WriteDATA(pgm_read_byte(&datas[i]));
  }
}

void EpdIf::EPD_Dis_Part(
  unsigned int x_start,
  unsigned int y_start,
  const unsigned char * datas,
  unsigned int PART_COLUMN,
  unsigned int PART_LINE
) {
  const unsigned char  *datas_flag;
  unsigned int i;
  unsigned int x_end, y_start1, y_start2, y_end1, y_end2;
  datas_flag = datas;             // Record array first address
  x_start = x_start / 8;          // Convert to byte
  x_end = x_start + PART_LINE / 8 - 1;

  y_start1 = 0;
  y_start2 = y_start - 1;
  if (y_start >= 256)  {
    y_start1 = y_start2 / 256;
    y_start2 = y_start2 % 256;
  }
  y_end1 = 0;
  y_end2 = y_start + PART_COLUMN - 1;
  if (y_end2 >= 256)  {
    y_end1 = y_end2 / 256;
    y_end2 = y_end2 % 256;
  }

  this->EPD_W21_WriteCMD(0x44);         // set RAM x address start/end, in page 35
  this->EPD_W21_WriteDATA(x_start);     // RAM x address start at 00h;
  this->EPD_W21_WriteDATA(x_end);       // RAM x address end at 0fh(15+1)*8->128
  this->EPD_W21_WriteCMD(0x45);         // set RAM y address start/end, in page 35
  this->EPD_W21_WriteDATA(y_start2);    // RAM y address start at 0127h;
  this->EPD_W21_WriteDATA(y_start1);    // RAM y address start at 0127h;
  this->EPD_W21_WriteDATA(y_end2);      // RAM y address end at 00h;
  this->EPD_W21_WriteDATA(y_end1);      // ????=0

  this->EPD_W21_WriteCMD(0x4E);         // set RAM x address count to 0;
  this->EPD_W21_WriteDATA(x_start);
  this->EPD_W21_WriteCMD(0x4F);         // set RAM y address count to 0X127;
  this->EPD_W21_WriteDATA(y_start2);
  this->EPD_W21_WriteDATA(y_start1);


  this->EPD_W21_WriteCMD(0x24);         //Write Black and White image to RAM
  for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)  {
    this->EPD_W21_WriteDATA(pgm_read_byte(&datas[i]));
  }
  this->EPD_Part_Update();


  datas = datas_flag;
  this->EPD_W21_WriteCMD(0x44);         // set RAM x address start/end, in page 35
  this->EPD_W21_WriteDATA(x_start);     // RAM x address start at 00h;
  this->EPD_W21_WriteDATA(x_end);       // RAM x address end at 0fh(15+1)*8->128
  this->EPD_W21_WriteCMD(0x45);         // set RAM y address start/end, in page 35
  this->EPD_W21_WriteDATA(y_start2);    // RAM y address start at 0127h;
  this->EPD_W21_WriteDATA(y_start1);    // RAM y address start at 0127h;
  this->EPD_W21_WriteDATA(y_end2);      // RAM y address end at 00h;
  this->EPD_W21_WriteDATA(y_end1);      // ????=0


  this->EPD_W21_WriteCMD(0x4E);         // set RAM x address count to 0;
  this->EPD_W21_WriteDATA(x_start);
  this->EPD_W21_WriteCMD(0x4F);         // set RAM y address count to 0X127;
  this->EPD_W21_WriteDATA(y_start2);
  this->EPD_W21_WriteDATA(y_start1);


  this->EPD_W21_WriteCMD(0x24);         //Write Black and White image to RAM
  for (i = 0; i < PART_COLUMN * PART_LINE / 8; i++)  {
    this->EPD_W21_WriteDATA(pgm_read_byte(&datas[i]));
  }

}

//////////////////ALL screen update ////////////////////
/**
    @brief: Display the whole screen as White
*/
void EpdIf::EPD_WhiteScreen_White(void) {
  unsigned int i, k;
  this->EPD_W21_WriteCMD(0x24);
  for (k = 0; k < 296; k++) {
    for (i = 0; i < 16; i++) {
      this->EPD_W21_WriteDATA(0xff); //write RAM for black(0)/white (1)
    }
  }
  this->EPD_Update();
}

/**
    @brief: Display the whole screen as Black
*/
void EpdIf::EPD_WhiteScreen_Black(void) {
  unsigned int i, k;
  this->EPD_W21_WriteCMD(0x24);
  for (k = 0; k < 296; k++) {
    for (i = 0; i < 16; i++) {
      this->EPD_W21_WriteDATA(0x00);  //write RAM for black(0)/white (1)
    }
  }
  this->EPD_Update();
}

/**
    @brief: Display the whole based on the basemap image
*/
void EpdIf::EPD_WhiteScreen_ALL(void) {
  unsigned int i;
  this->EPD_W21_WriteCMD(0x24);   //write RAM for black(0)/white (1)
  for (i = 0; i < ALLSCREEN_GRAGHBYTES; i++)  {
    this->EPD_W21_WriteDATA(pgm_read_byte(&gImage_basemapNA[i]));
  }
  this->EPD_Update();
}

//////////////////END ////////////////////
