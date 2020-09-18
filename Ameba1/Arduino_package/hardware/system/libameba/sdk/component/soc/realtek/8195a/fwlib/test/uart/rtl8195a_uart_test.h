#ifndef _RTL8195A_UART_TEST_H_
#define _RTL8195A_UART_TEST_H_

u32 BR_TABLE[] = {
       1200,    9600,   14400,   19200,
      28800,   38400,   57600,   76800,
     115200,  128000,  153600,  230400,
     460800,  500000,  921600, 1000000,
    1382400, 1444400, 1500000, 1843200,
    2000000, 2100000, 2764800, 3000000,
    3250000, 3692300, 3750000, 4000000,
    6000000
};

typedef struct _RUART_VERIFY_PARAMETER_ {
    u32  TestPara0;  // Command
    u32  TestPara1;  // VerifyItem
    u32  TestPara2;  // VerifyLoop
    u32  TestPara3;  // RUART_A ID
    u32  TestPara4;  // RUART_B ID
    u32  TestPara5;  // Baudrate
}RUART_VERIFY_PARAMETER, *PRUART_VERIFY_PARAMETER;

#endif
