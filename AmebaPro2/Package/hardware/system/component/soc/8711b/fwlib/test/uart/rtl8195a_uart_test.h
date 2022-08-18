#ifndef _RTL8195A_UART_TEST_H_
#define _RTL8195A_UART_TEST_H_

#define LP_RX_MONITOR_FUNC_TEST   (1)

#define LP_RX_SWTH_CLK_TEST   (1)

#define UART_WAKE_UP_TEST   (1)

#define UART_ROM_FUNC_INTERFACE_TEST  (1)

#define UART_RX_TIME_OUT_TEST  (1)

#define QFN32_PACKAGE_UART_VERIFY     (1)

typedef struct _RUART_VERIFY_PARAMETER_ {
    u32  TestPara0;  // Command
    u32  TestPara1;  // VerifyItem
    u32  TestPara2;
    u32  TestPara3;
    u32  TestPara4;
    u32  TestPara5;
}RUART_VERIFY_PARAMETER, *PRUART_VERIFY_PARAMETER;

#define UART_DMA_NEW_METHOD			(0)

#if (UART_DMA_NEW_METHOD)

#define UART_RX_DMA_BUF_LEN		(16)

#define UART_RX_DMA_BUF_SIZE		(2)

/*time out value for test*/
#define UART_TIMER_TEST_TO			(1000)

#define UART_DMA_RD_BYT_CNT_BUF_SIZE	(2)

enum uart_timer_cnt_state{
        UART_FST_TIMEOUT_STATE,
        UART_CONS_TIMEOUT_STATE
};

typedef struct {
	u32 DataLen;
	u8 Data[UART_RX_DMA_BUF_LEN];
}UART_RX_DMA_DAT_BUFFER;

typedef struct {
	u32 CurrentState;
	UART_RX_DMA_DAT_BUFFER DataBuf;
}UART_RX_DMA_BUFFER;

typedef enum  _UART_DMA_BUF_STATUS
{
  UART_RX_DMA_BUF_IDLE = 0x00,
  UART_RX_DMA_BUF_BUSY= 0x01,
} UART_RX_DMA_BUF_STATUS;

#endif

#endif
