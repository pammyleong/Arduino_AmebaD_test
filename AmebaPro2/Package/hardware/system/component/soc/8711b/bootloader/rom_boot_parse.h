#ifndef __ROM_BOOT_PARSE_H_
#define __ROM_BOOT_PARSE_H_

#include "ameba_soc.h"
#include "rtl_consol.h"
#include <basic_types.h>

extern void UARTIMG_Download_A(u8 uart_idx);
extern void UARTIMG_Download_B(u8 uart_idx);

extern int _memcmp_A(const void *av, const void *bv, size_t len);
extern int _memcmp_B(const void *av, const void *bv, size_t len);

extern void * _memcpy_A( void *s1, const void *s2, size_t n );
extern void * _memcpy_B( void *s1, const void *s2, size_t n );

extern VOID *_memset_A(void *dst0,int Val,SIZE_T length);
extern VOID *_memset_B(void *dst0,int Val,SIZE_T length);

extern void DumpForOneBytes_A(u8 *pData, u8 Len);
extern void DumpForOneBytes_B(u8 *pData, u8 Len);

extern u32 CmdRomHelp_A(u16 argc, u8  *argv[]);
extern u32 CmdRomHelp_B(u16 argc, u8  *argv[]);

extern u32 CmdDumpWord_A(u16 argc, u8  *argv[]);
extern u32 CmdDumpWord_B(u16 argc, u8  *argv[]);

extern u32 CmdWriteWord_A(u16 argc, u8  *argv[]);
extern u32 CmdWriteWord_B(u16 argc, u8  *argv[]);

extern u32 CmdFlash_A( u16 argc, u8  *argv[]);
extern u32 CmdFlash_B( u16 argc, u8  *argv[]);

extern u32 CmdEfuse_A( u16 argc ,u8  *argv[]);
extern u32 CmdEfuse_B( u16 argc ,u8  *argv[]);

extern u32 CmdDumpByte_A( u16 argc ,u8  *argv[]);
extern u32 CmdDumpByte_B( u16 argc ,u8  *argv[]);

extern u32 CmdDumpHalfWord_A( u16 argc ,u8  *argv[]);
extern u32 CmdDumpHalfWord_B( u16 argc ,u8  *argv[]);

extern u32 CmdWriteByte_A( u16 argc ,u8  *argv[]);
extern u32 CmdWriteByte_B( u16 argc ,u8  *argv[]);

extern u32 SramReadWriteTest_A(u32 StartAddr, u32 EndAddr);
extern u32 SramReadWriteTest_B(u32 StartAddr, u32 EndAddr);

extern u32 CmdSRamTest_A( u16 argc ,u8 *argv[]);
extern u32 CmdSRamTest_B( u16 argc ,u8 *argv[]);

extern u32 GetRomCmdNum_A(void );
extern u32 GetRomCmdNum_B(void );

extern u32 Rand_A(void);
extern u32 Rand_B(void);

extern int Rand_Arc4_A();
extern int Rand_Arc4_B();

extern int RandBytes_Get_A(void *buf, u32 len);
extern int RandBytes_Get_B(void *buf, u32 len);

extern u32 Isspace_A(char ch);
extern u32 Isspace_B(char ch);

extern u32 Strtoul_A(const u8 *nptr, u8 **endptr, u32 base);
extern u32 Strtoul_B(const u8 *nptr, u8 **endptr, u32 base);

extern void ArrayInitialize_A(u8  *pArrayToInit, u8  ArrayLen, u8  InitValue);
extern void ArrayInitialize_B(u8  *pArrayToInit, u8  ArrayLen, u8  InitValue);

extern u8 GetArgc_A(const   u8  *string);
extern u8 GetArgc_B(const   u8  *string);

extern u8**GetArgv_A(const   u8  *string);
extern u8**GetArgv_B(const   u8  *string);

extern void UartLogCmdExecute_A(PUART_LOG_CTL   pUartLogCtlExe);
extern void UartLogCmdExecute_B(PUART_LOG_CTL   pUartLogCtlExe);

extern void UartLogShowBackSpace_A(u8  BackLen, u8  EchoFlag, VOID *pfINPUT);
extern void UartLogShowBackSpace_B(u8  BackLen, u8  EchoFlag, VOID *pfINPUT);

extern void UartLogRecallOldCmd_A(PUART_LOG_BUF  pTmpBuf, u8  *OldBuf, u8  EchoFlag, VOID *pfINPUT);
extern void UartLogRecallOldCmd_B(PUART_LOG_BUF  pTmpBuf, u8  *OldBuf, u8  EchoFlag, VOID *pfINPUT);

extern void UartLogHistoryCmd_A(u8  RevData,  UART_LOG_CTL *prvUartLogCtl, u8  EchoFlag);
extern void UartLogHistoryCmd_B(u8  RevData,  UART_LOG_CTL *prvUartLogCtl, u8  EchoFlag);

extern u8 UartLogCmdChk_A(u8  RevData,  UART_LOG_CTL *prvUartLogCtl,  u8  EchoFlag);
extern u8 UartLogCmdChk_B(u8  RevData,  UART_LOG_CTL *prvUartLogCtl,  u8  EchoFlag);

extern void UartLogIrqHandle_A(VOID * Data);
extern void UartLogIrqHandle_B(VOID * Data);

extern void RtlConsolInit_A(u32 Boot,u32 TBLSz,VOID *pTBL);
extern void RtlConsolInit_B(u32 Boot,u32 TBLSz,VOID *pTBL);

extern void RtlConsolTaskRom_A( VOID *Data);
extern void RtlConsolTaskRom_B( VOID *Data);

extern BOOLEAN RtlExitConsol_A(u32 MaxWaitCount);
extern BOOLEAN RtlExitConsol_B(u32 MaxWaitCount);

extern void RtlConsolRom_A(u32 MaxWaitCount);
extern void RtlConsolRom_B(u32 MaxWaitCount);

extern void BKUP_Write_A(u32 DwordIdx, u32 WriteVal);
extern void BKUP_Write_B(u32 DwordIdx, u32 WriteVal);

extern u32 BKUP_Read_A(u32 DwordIdx);
extern u32 BKUP_Read_B(u32 DwordIdx);

extern void BKUP_Set_A(u32 DwordIdx, u32 BitMask);
extern void BKUP_Set_B(u32 DwordIdx, u32 BitMask);

extern void BKUP_Clear_A(u32 DwordIdx, u32 BitMask);
extern void BKUP_Clear_B(u32 DwordIdx, u32 BitMask);

extern void NCO32K_Init_A(u32 clk_out, u32 clk_ref, u8 calibration_cycles, u8 calibration_thrs);
extern void NCO32K_Init_B(u32 clk_out, u32 clk_ref, u8 calibration_cycles, u8 calibration_thrs);

extern void EXT32K_Cmd_A(u32 NewStatus);
extern void EXT32K_Cmd_B(u32 NewStatus);

extern void NCO8M_Init_A(u32 clk_ref_Hz, u32 clk_out_Hz);
extern void NCO8M_Init_B(u32 clk_ref_Hz, u32 clk_out_Hz);

extern void NCO8M_Cmd_A(u32 NewState);
extern void NCO8M_Cmd_B(u32 NewState);

extern void ISO_Set_A(u32 BitMask, u32 NewState);
extern void ISO_Set_B(u32 BitMask, u32 NewState);

extern void PLL0_Set_A(u32 BitMask, u32 NewState);
extern void PLL0_Set_B(u32 BitMask, u32 NewState);

extern void PLL1_Set_A(u32 BitMask, u32 NewState);
extern void PLL1_Set_B(u32 BitMask, u32 NewState);

extern void PLL2_Set_A(u32 BitMask, u32 NewState);
extern void PLL2_Set_B(u32 BitMask, u32 NewState);

extern void PLL3_Set_A(u32 BitMask, u32 NewState);
extern void PLL3_Set_B(u32 BitMask, u32 NewState);

extern void XTAL0_Set_A(u32 BitMask, u32 NewState);
extern void XTAL0_Set_B(u32 BitMask, u32 NewState);

extern void XTAL1_Set_A(u32 BitMask, u32 NewState);
extern void XTAL1_Set_B(u32 BitMask, u32 NewState);

extern void XTAL2_Set_A(u32 BitMask, u32 NewState);
extern void XTAL2_Set_B(u32 BitMask, u32 NewState);

extern u32 XTAL_ClkGet_A(void);
extern u32 XTAL_ClkGet_B(void);

extern void CPU_ClkSet_A(u8  CpuType);
extern void CPU_ClkSet_B(u8  CpuType);

extern u32 CPU_ClkGet_A(u8 IsFPGA);
extern u32 CPU_ClkGet_B(u8 IsFPGA);

extern void OSC32K_Calibration_A(u32 LOG_EN, u32 CaliCycles);
extern void OSC32K_Calibration_B(u32 LOG_EN, u32 CaliCycles);

extern void OSC32K_Cmd_A(u32 NewStatus);
extern void OSC32K_Cmd_B(u32 NewStatus);

extern u32 OSC8M_Get_A(void);
extern u32 OSC8M_Get_B(void);

extern void rtl_cryptoEngine_SrcDesc_Show_A(RTL_CRYPTO_SOURCE_T *pSrcDesc);
extern void rtl_cryptoEngine_SrcDesc_Show_B(RTL_CRYPTO_SOURCE_T *pSrcDesc);

extern void rtl_cryptoEngine_info_A(void);
extern void rtl_cryptoEngine_info_B(void);

extern int rtl_cryptoEngine_init_A(void);
extern int rtl_cryptoEngine_init_B(void);

extern int rtl_crypto_md5_init_A(void);
extern int rtl_crypto_md5_init_B(void);

extern int rtl_crypto_md5_process_A(IN const u8* message, IN const u32 msglen, OUT u8* pDigest);
extern int rtl_crypto_md5_process_B(IN const u8* message, IN const u32 msglen, OUT u8* pDigest);

extern int rtl_crypto_md5_A(IN const u8* message, IN const u32 msglen, OUT u8* pDigest);
extern int rtl_crypto_md5_B(IN const u8* message, IN const u32 msglen, OUT u8* pDigest);

extern int rtl_crypto_sha1_init_A(void);
extern int rtl_crypto_sha1_init_B(void);

extern int rtl_crypto_sha1_process_A(IN const u8* message, IN const u32 msglen, OUT u8* pDigest);
extern int rtl_crypto_sha1_process_B(IN const u8* message, IN const u32 msglen, OUT u8* pDigest);

extern int rtl_crypto_sha1_A(const u8* message, const u32 msglen, u8* pDigest);
extern int rtl_crypto_sha1_B(const u8* message, const u32 msglen, u8* pDigest);

extern int rtl_crypto_sha2_init_A(IN const SHA2_TYPE sha2type);
extern int rtl_crypto_sha2_init_B(IN const SHA2_TYPE sha2type);

extern int rtl_crypto_sha2_process_A(const u8* message, const u32 msglen, u8* pDigest);
extern int rtl_crypto_sha2_process_B(const u8* message, const u32 msglen, u8* pDigest);

extern int rtl_crypto_sha2_A(IN const SHA2_TYPE sha2type, IN const u8* message, IN const u32 msglen, OUT u8* pDigest);
extern int rtl_crypto_sha2_B(IN const SHA2_TYPE sha2type, IN const u8* message, IN const u32 msglen, OUT u8* pDigest);

extern int rtl_crypto_hmac_md5_init_A(IN const u8* key, IN const u32 keylen);
extern int rtl_crypto_hmac_md5_init_B(IN const u8* key, IN const u32 keylen);

extern int rtl_crypto_hmac_md5_process_A(IN const u8* message, IN const u32 msglen, OUT u8* pDigest);
extern int rtl_crypto_hmac_md5_process_B(IN const u8* message, IN const u32 msglen, OUT u8* pDigest);

extern int rtl_crypto_hmac_md5_A(IN const u8* message, IN const u32 msglen, IN const u8* key, IN const u32 keylen, OUT u8* pDigest);
extern int rtl_crypto_hmac_md5_B(IN const u8* message, IN const u32 msglen, IN const u8* key, IN const u32 keylen, OUT u8* pDigest);

extern int rtl_crypto_hmac_sha1_init_A(IN const u8* key, IN const u32 keylen);
extern int rtl_crypto_hmac_sha1_init_B(IN const u8* key, IN const u32 keylen);

extern int rtl_crypto_hmac_sha1_process_A(			
	IN const u8* message, 	IN const u32 msglen, 
	OUT u8* pDigest);
extern int rtl_crypto_hmac_sha1_process_B(			
	IN const u8* message, 	IN const u32 msglen, 
	OUT u8* pDigest);

extern int rtl_crypto_hmac_sha1_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* key, 		IN const u32 keylen, 
	OUT u8* pDigest);
extern int rtl_crypto_hmac_sha1_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* key, 		IN const u32 keylen, 
	OUT u8* pDigest);

extern int rtl_crypto_hmac_sha2_init_A(
	IN const SHA2_TYPE sha2type, 	
	IN const u8* key, 	IN const u32 keylen);
extern int rtl_crypto_hmac_sha2_init_B(
	IN const SHA2_TYPE sha2type, 	
	IN const u8* key, 	IN const u32 keylen);

extern int rtl_crypto_hmac_sha2_process_A(
	IN const u8* message, 	IN const u32 msglen, 
	OUT u8* pDigest);
extern int rtl_crypto_hmac_sha2_process_B(
	IN const u8* message, 	IN const u32 msglen, 
	OUT u8* pDigest);

extern int rtl_crypto_hmac_sha2_A(
	IN const SHA2_TYPE sha2type, 
	IN const u8* message, 			IN const u32 msglen, 
	IN const u8* key, 				IN const u32 keylen,
	OUT u8* pDigest);
extern int rtl_crypto_hmac_sha2_B(
	IN const SHA2_TYPE sha2type, 
	IN const u8* message, 			IN const u32 msglen, 
	IN const u8* key, 				IN const u32 keylen,
	OUT u8* pDigest);

extern int rtl_crypto_aes_cbc_init_A(IN const u8* key, IN const u32 keylen);
extern int rtl_crypto_aes_cbc_init_B(IN const u8* key, IN const u32 keylen);

extern int rtl_crypto_aes_cbc_encrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_aes_cbc_encrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_aes_cbc_decrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_aes_cbc_decrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_aes_ecb_init_A(const u8* key, const u32 keylen);
extern int rtl_crypto_aes_ecb_init_B(const u8* key, const u32 keylen);

extern int rtl_crypto_aes_ecb_encrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_aes_ecb_encrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_aes_ecb_decrypt_A(const u8* message, const u32 msglen, const u8* iv, const u32 ivlen, u8* pResult);
extern int rtl_crypto_aes_ecb_decrypt_B(const u8* message, const u32 msglen, const u8* iv, const u32 ivlen, u8* pResult);

extern int rtl_crypto_aes_ctr_init_A(IN const u8* key, 	IN const u32 keylen);
extern int rtl_crypto_aes_ctr_init_B(IN const u8* key, 	IN const u32 keylen);

extern int rtl_crypto_aes_ctr_encrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_aes_ctr_encrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_aes_ctr_decrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_aes_ctr_decrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_3des_cbc_init_A(IN const u8* key, IN const u32 keylen);
extern int rtl_crypto_3des_cbc_init_B(IN const u8* key, IN const u32 keylen);

extern int rtl_crypto_3des_cbc_encrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_3des_cbc_encrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_3des_cbc_decrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_3des_cbc_decrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_3des_ecb_init_A(IN const u8* key, IN const u32 keylen);
extern int rtl_crypto_3des_ecb_init_B(IN const u8* key, IN const u32 keylen);

extern int rtl_crypto_3des_ecb_encrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_3des_ecb_encrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_3des_ecb_decrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_3des_ecb_decrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_des_cbc_init_A(IN const u8* key, IN const u32 keylen);
extern int rtl_crypto_des_cbc_init_B(IN const u8* key, IN const u32 keylen);

extern int rtl_crypto_des_cbc_encrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_des_cbc_encrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_des_cbc_decrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_des_cbc_decrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_des_ecb_init_A(IN const u8* key, IN const u32 keylen);
extern int rtl_crypto_des_ecb_init_B(IN const u8* key, IN const u32 keylen);

extern int rtl_crypto_des_ecb_encrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_des_ecb_encrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int rtl_crypto_des_ecb_decrypt_A(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int rtl_crypto_des_ecb_decrypt_B(
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* iv, 		IN const u32 ivlen, 
	OUT u8* pResult);


extern void SYSTIMER_Init_A(void);
extern void SYSTIMER_Init_B(void);

extern u32 SYSTIMER_TickGet_A(void);
extern u32 SYSTIMER_TickGet_B(void);

extern u32 SYSTIMER_GetPassTime_A(u32 start);
extern u32 SYSTIMER_GetPassTime_B(u32 start);

extern void DelayNop_A(u32 count);
extern void DelayNop_B(u32 count);

extern void DelayUs_A(u32 us);
extern void DelayUs_B(u32 us);

extern void DelayMs_A(u32 ms);
extern void DelayMs_B(u32 ms);

extern void USOC_DongleSpecialCmd_A(u8 cmd_val);
extern void USOC_DongleSpecialCmd_B(u8 cmd_val);

extern void USOC_DongleCmd_A(void);
extern void USOC_DongleCmd_B(void);

extern void USOC_DongleIsr_A(void *DATA);
extern void USOC_DongleIsr_B(void *DATA);

extern void USOC_SIE_INTConfig_A(u32 SIE_INT, u32 NewState);
extern void USOC_SIE_INTConfig_B(u32 SIE_INT, u32 NewState);

extern void USOC_SIE_INTClear_A(void);
extern void USOC_SIE_INTClear_B(void);

extern u32 USOC_PHY_Write_A(u8 addr, u8 data);
extern u32 USOC_PHY_Write_B(u8 addr, u8 data);

extern u32 USOC_PHY_Read_A(u8 addr, u8 *data);
extern u32 USOC_PHY_Read_B(u8 addr, u8 *data);

extern void USOC_PHY_Autoload_A(void);
extern void USOC_PHY_Autoload_B(void);

extern void EFUSE_USER_Read_A(u8 UserArea, u8 *pContant);
extern void EFUSE_USER_Read_B(u8 UserArea, u8 *pContant);

extern void EFUSE_USER1_Read_A(u8 *pContant);
extern void EFUSE_USER1_Read_B(u8 *pContant);

extern u8 EFUSE_RemainLength_A(void);
extern u8 EFUSE_RemainLength_B(void);

extern u8 EFUSE_USER_Write_A(u8 offset, u8 WordEnable, u8 *pContant);
extern u8 EFUSE_USER_Write_B(u8 offset, u8 WordEnable, u8 *pContant);

extern u8 EFUSE_USER1_Write_A(u8 SectionIdx, u8 WordEnable, u8 *pContant);
extern u8 EFUSE_USER1_Write_B(u8 SectionIdx, u8 WordEnable, u8 *pContant);

extern u32 EFUSE_OTP_Read1B_A(u32 CtrlSetting, u16 Addr, u8 *Data, u8 L25OutVoltage);
extern u32 EFUSE_OTP_Read1B_B(u32 CtrlSetting, u16 Addr, u8 *Data, u8 L25OutVoltage);

extern u32 EFUSE_OTP_Write1B_A(u32 CtrlSetting, u16 Addr, u8 Data, u8 L25OutVoltage);
extern u32 EFUSE_OTP_Write1B_B(u32 CtrlSetting, u16 Addr, u8 Data, u8 L25OutVoltage);

extern void EFUSE_OTP_Read32B_A(u8 *pContant);
extern void EFUSE_OTP_Read32B_B(u8 *pContant);

extern u32 EFUSE_OTP_Write32B_A(u8 *pContant);
extern u32 EFUSE_OTP_Write32B_B(u8 *pContant);

extern void EFUSE_RDP_EN_A(void);
extern void EFUSE_RDP_EN_B(void);

extern void EFUSE_RDP_KEY_A(u8 *RdpKey);
extern void EFUSE_RDP_KEY_B(u8 *RdpKey);

extern void EFUSE_OTF_KEY_A(u8 *OtfKey);
extern void EFUSE_OTF_KEY_B(u8 *OtfKey);

extern u32 EFUSE_JTAG_OFF_A(void);
extern u32 EFUSE_JTAG_OFF_B(void);

extern void PAD_DrvStrength_A(u8 PinName, u32 DrvStrength);
extern void PAD_DrvStrength_B(u8 PinName, u32 DrvStrength);

extern void PAD_PullCtrl_A(u8 PinName, u8 PullType);
extern void PAD_PullCtrl_B(u8 PinName, u8 PullType);

extern void Pinmux_Config_A(u8 PinName, u32 PinFunc);
extern void Pinmux_Config_B(u8 PinName, u32 PinFunc);

extern u32 Pinmux_ConfigGet_A(u8 PinName);
extern u32 Pinmux_ConfigGet_B(u8 PinName);

extern void Pinmux_Deinit_A(u8 PinName);
extern void Pinmux_Deinit_B(u8 PinName);

extern void PINMUX_UART0_Ctrl_A(u32  PinLocation, BOOL Operation);
extern void PINMUX_UART0_Ctrl_B(u32  PinLocation, BOOL Operation);

extern void PINMUX_UART1_Ctrl_A(u32  PinLocation, BOOL Operation);
extern void PINMUX_UART1_Ctrl_B(u32  PinLocation, BOOL Operation);

extern void PINMUX_UARTLOG_Ctrl_A(u32  PinLocation, BOOL   Operation);
extern void PINMUX_UARTLOG_Ctrl_B(u32  PinLocation, BOOL   Operation);

extern void PINMUX_SPI0_Ctrl_A(u32  PinLocation, BOOL Operation);
extern void PINMUX_SPI0_Ctrl_B(u32  PinLocation, BOOL Operation);

extern void PINMUX_SPI1_Ctrl_A(u32  PinLocation, BOOL Operation);
extern void PINMUX_SPI1_Ctrl_B(u32  PinLocation, BOOL Operation);

extern void PINMUX_SPIF_Ctrl_A(u32  PinLocation, BOOL Operation);
extern void PINMUX_SPIF_Ctrl_B(u32  PinLocation, BOOL Operation);

extern void PINMUX_I2C0_Ctrl_A(u32  PinLocation, BOOL Operation);
extern void PINMUX_I2C0_Ctrl_B(u32  PinLocation, BOOL Operation);

extern void PINMUX_I2C1_Ctrl_A(u32  PinLocation, BOOL Operation);
extern void PINMUX_I2C1_Ctrl_B(u32  PinLocation, BOOL Operation);

extern void PINMUX_SDIOD_Ctrl_A(u32  PinLocation, BOOL Operation);
extern void PINMUX_SDIOD_Ctrl_B(u32  PinLocation, BOOL Operation);

extern void PINMUX_I2S0_Ctrl_A(u32  PinLocation, BOOL Operation);
extern void PINMUX_I2S0_Ctrl_B(u32  PinLocation, BOOL Operation);

extern void PINMUX_SWD_Ctrl_A(u32  PinLocation, BOOL Operation);
extern void PINMUX_SWD_Ctrl_B(u32  PinLocation, BOOL Operation);

extern void PINMUX_SWD_OFF_A(void);
extern void PINMUX_SWD_OFF_B(void);

extern BOOL PINMUX_SWD_REG_A(u32 Addr);
extern BOOL PINMUX_SWD_REG_B(u32 Addr);

extern void PINMUX_Ctrl_A(u32  Function, u32  PinLocation, BOOL Operation);
extern void PINMUX_Ctrl_B(u32  Function, u32  PinLocation, BOOL Operation);

extern void SOCPS_BackupCPUClk_A(void);
extern void SOCPS_BackupCPUClk_B(void);

extern void SOCPS_RestoreCPUClk_A(void);
extern void SOCPS_RestoreCPUClk_B(void);

extern void SOCPS_BootFromPS_A(u32 NewStatus);
extern void SOCPS_BootFromPS_B(u32 NewStatus);

extern void SOCPS_TrapPin_A(u32 NewStatus);
extern void SOCPS_TrapPin_B(u32 NewStatus);

extern void SOCPS_ANACKSel_A(u32 ANACLK);
extern void SOCPS_ANACKSel_B(u32 ANACLK);

extern u32 SOCPS_CLKCal_A(u32 ClkSel);
extern u32 SOCPS_CLKCal_B(u32 ClkSel);

extern void SOCPS_SetWakeEvent_A(u32 Option, u32 NewStatus);
extern void SOCPS_SetWakeEvent_B(u32 Option, u32 NewStatus);

extern void SOCPS_ClearWakeEvent_A(void);
extern void SOCPS_ClearWakeEvent_B(void);

extern void SOCPS_WakePinsCtrl_A(u32 GpioOption);
extern void SOCPS_WakePinsCtrl_B(u32 GpioOption);

extern void SOCPS_WakePinCtrl_A(u32 Index, u32 Polarity);
extern void SOCPS_WakePinCtrl_B(u32 Index, u32 Polarity);

extern void SOCPS_WakePinClear_A(void);
extern void SOCPS_WakePinClear_B(void);

extern void SOCPS_GetANATimerParam_A(u32 SDuration, u32 *ScaleTemp, u32 *PeriodTemp);
extern void SOCPS_GetANATimerParam_B(u32 SDuration, u32 *ScaleTemp, u32 *PeriodTemp);

extern void SOCPS_SetANATimer_A(u32 SDuration, u32 NewStatus);
extern void SOCPS_SetANATimer_B(u32 SDuration, u32 NewStatus);

extern void SOCPS_SetReguWakepin_A(void);
extern void SOCPS_SetReguWakepin_B(void);

extern void SOCPS_SetReguTimer_A(u32 SDuration, u32 CalibData);
extern void SOCPS_SetReguTimer_B(u32 SDuration, u32 CalibData);

extern void SOCPS_PWROption_A(u32 pwrmgt_option);
extern void SOCPS_PWROption_B(u32 pwrmgt_option);

extern void SOCPS_PWROptionExt_A(u32 pwrmgt_option);
extern void SOCPS_PWROptionExt_B(u32 pwrmgt_option);

extern void SOCPS_PWRMode_A(u32 pwrmode, u32 snz_bypass);
extern void SOCPS_PWRMode_B(u32 pwrmode, u32 snz_bypass);

extern void SOCPS_SNZMode_A(u32 SnzMask, u32 NewStatus);
extern void SOCPS_SNZMode_B(u32 SnzMask, u32 NewStatus);

extern void SOCPS_DeepStandby_A(void);
extern void SOCPS_DeepStandby_B(void);

extern void SOCPS_DeepSleep_A(void);
extern void SOCPS_DeepSleep_B(void);

extern void SDIO_StructInit_A(SDIO_InitTypeDef* SDIO_InitStruct);
extern void SDIO_StructInit_B(SDIO_InitTypeDef* SDIO_InitStruct);

extern void SDIO_Init_A(SDIO_InitTypeDef* SDIOInit_Struct);
extern void SDIO_Init_B(SDIO_InitTypeDef* SDIOInit_Struct);

extern void SDIO_INTClear_A(void);
extern void SDIO_INTClear_B(void);

extern VOID SDIO_INTConfig_A(u16 IntMask, u32 NewState);
extern VOID SDIO_INTConfig_B(u16 IntMask, u32 NewState);

extern u8 SDIO_RPWM1_Get_A(void);
extern u8 SDIO_RPWM1_Get_B(void);

extern u16 SDIO_RPWM2_Get_A(void);
extern u16 SDIO_RPWM2_Get_B(void);

extern void SDIO_CPWM1_Set_A(u8 Val);
extern void SDIO_CPWM1_Set_B(u8 Val);

extern void SDIO_CPWM2_Set_A(u16 Val, u32 Newstate);
extern void SDIO_CPWM2_Set_B(u16 Val, u32 Newstate);

extern u16 SDIO_RXBD_RPTR_Get_A(void);
extern u16 SDIO_RXBD_RPTR_Get_B(void);

extern void SDIO_RXBD_WPTR_Set_A(u16 Val);
extern void SDIO_RXBD_WPTR_Set_B(u16 Val);

extern u16 SDIO_TXBD_WPTR_Get_A(void);
extern u16 SDIO_TXBD_WPTR_Get_B(void);

extern void SDIO_TXBD_RPTR_Set_A(u16 Val);
extern void SDIO_TXBD_RPTR_Set_B(u16 Val);

extern void SDIO_DMA_Reset_A(void);
extern void SDIO_DMA_Reset_B(void);

extern VOID BOOT_ROM_Simulation_A(VOID);
extern VOID BOOT_ROM_Simulation_B(VOID);

extern VOID USOC_BOOT_TXBD_Proc_A(u32 *StartUp);
extern VOID USOC_BOOT_TXBD_Proc_B(u32 *StartUp);

extern VOID USOC_BOOT_Init_A(void);
extern VOID USOC_BOOT_Init_B(void);

extern VOID USB_Boot_ROM_A(VOID);
extern VOID USB_Boot_ROM_B(VOID);

extern VOID USOC_CH_Cmd_A(USOC_REG_TypeDef * usoc_reg, u32 ch, u32 NewStatus);
extern VOID USOC_CH_Cmd_B(USOC_REG_TypeDef * usoc_reg, u32 ch, u32 NewStatus);

extern VOID USOC_Cmd_A(USOC_REG_TypeDef * usoc_reg, u32 NewStatus);
extern VOID USOC_Cmd_B(USOC_REG_TypeDef * usoc_reg, u32 NewStatus);

extern VOID USOC_PHY_Cmd_A(USOC_REG_TypeDef * usoc_reg, u32 NewStatus);
extern VOID USOC_PHY_Cmd_B(USOC_REG_TypeDef * usoc_reg, u32 NewStatus);

extern VOID USOC_MODE_Cfg_A(USOC_REG_TypeDef * usoc_reg, u32 mode);
extern VOID USOC_MODE_Cfg_B(USOC_REG_TypeDef * usoc_reg, u32 mode);

extern VOID USOC_TXBD_SWIDX_Cfg_A(USOC_REG_TypeDef * usoc_reg, u32 index);
extern VOID USOC_TXBD_SWIDX_Cfg_B(USOC_REG_TypeDef * usoc_reg, u32 index);

extern u32 USOC_TXBD_SWIDX_Get_A(USOC_REG_TypeDef * usoc_reg);
extern u32 USOC_TXBD_SWIDX_Get_B(USOC_REG_TypeDef * usoc_reg);

extern u32 USOC_TXBD_HWIDX_Get_A(USOC_REG_TypeDef * usoc_reg);
extern u32 USOC_TXBD_HWIDX_Get_B(USOC_REG_TypeDef * usoc_reg);

extern u32 USOC_RXBD_HWIDX_Get_A(USOC_REG_TypeDef * usoc_reg);
extern u32 USOC_RXBD_HWIDX_Get_B(USOC_REG_TypeDef * usoc_reg);

extern VOID USOC_RXBD_SWIDX_Cfg_A(USOC_REG_TypeDef * usoc_reg, u32 index);
extern VOID USOC_RXBD_SWIDX_Cfg_B(USOC_REG_TypeDef * usoc_reg, u32 index);

extern u32 USOC_RXBD_SWIDX_Get_A(USOC_REG_TypeDef * usoc_reg);
extern u32 USOC_RXBD_SWIDX_Get_B(USOC_REG_TypeDef * usoc_reg);

extern VOID USOC_StructInit_A(USOC_InitTypeDef* USOCInit_Struct);
extern VOID USOC_StructInit_B(USOC_InitTypeDef* USOCInit_Struct);

extern VOID USOC_Init_A(USOC_REG_TypeDef * usoc_reg, USOC_InitTypeDef* USOCInit_Struct);
extern VOID USOC_Init_B(USOC_REG_TypeDef * usoc_reg, USOC_InitTypeDef* USOCInit_Struct);

extern VOID USOC_SW_RST_A(USOC_REG_TypeDef * usoc_reg);
extern VOID USOC_SW_RST_B(USOC_REG_TypeDef * usoc_reg);

extern VOID USOC_INTCfg_A(USOC_REG_TypeDef * usoc_reg, u32 mask);
extern VOID USOC_INTCfg_B(USOC_REG_TypeDef * usoc_reg, u32 mask);

extern VOID USOC_INTClr_A(USOC_REG_TypeDef * usoc_reg, u32 mask);
extern VOID USOC_INTClr_B(USOC_REG_TypeDef * usoc_reg, u32 mask);

extern u32 USOC_INTGet_A(USOC_REG_TypeDef * usoc_reg);
extern u32 USOC_INTGet_B(USOC_REG_TypeDef * usoc_reg);

extern VOID USOC_MIT_Cfg_A(USOC_REG_TypeDef * usoc_reg, u32 NewStatus);
extern VOID USOC_MIT_Cfg_B(USOC_REG_TypeDef * usoc_reg, u32 NewStatus);

extern VOID USOC_TXSTUCK_Cfg_A(USOC_REG_TypeDef * usoc_reg, u32 NewStatus, u32 TVal);
extern VOID USOC_TXSTUCK_Cfg_B(USOC_REG_TypeDef * usoc_reg, u32 NewStatus, u32 TVal);

extern VOID USOC_RXSTUCK_Cfg_A(USOC_REG_TypeDef * usoc_reg, u32 NewStatus, u32 RVal);
extern VOID USOC_RXSTUCK_Cfg_B(USOC_REG_TypeDef * usoc_reg, u32 NewStatus, u32 RVal);

extern VOID USOC_POWER_On_A(VOID);
extern VOID USOC_POWER_On_B(VOID);

extern u32 ADC_RXGDMA_Init_A(GDMA_InitTypeDef *GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8* pDataBuf, u32 DataLen);
extern u32 ADC_RXGDMA_Init_B(GDMA_InitTypeDef *GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8* pDataBuf, u32 DataLen);

extern void ADC_SetAudio_A(u32 NewState);
extern void ADC_SetAudio_B(u32 NewState);

extern void ADC_SetAnalog_A(ADC_InitTypeDef* ADC_InitStruct);
extern void ADC_SetAnalog_B(ADC_InitTypeDef* ADC_InitStruct);

extern void ADC_Cmd_A(u32 ADCEn);
extern void ADC_Cmd_B(u32 ADCEn);

extern void ADC_INTConfig_A(u32 IntrMSK, u32 NewState);
extern void ADC_INTConfig_B(u32 IntrMSK, u32 NewState);

extern void ADC_SetOneShot_A(u32 NewState, u32 PeriodMs, u32 InterruptThresh);
extern void ADC_SetOneShot_B(u32 NewState, u32 PeriodMs, u32 InterruptThresh);

extern void ADC_SetComp_A(u8 ChanIdx, u16 ADCCompTD, u16 ADCCompCtrl);
extern void ADC_SetComp_B(u8 ChanIdx, u16 ADCCompTD, u16 ADCCompCtrl);

extern void ADC_INTClear_A(void);
extern void ADC_INTClear_B(void);

extern void ADC_INTClearPendingBits_A(u32 Mask);
extern void ADC_INTClearPendingBits_B(u32 Mask);

extern u32 ADC_GetISR_A(void);
extern u32 ADC_GetISR_B(void);

extern u32 ADC_Read_A(void);
extern u32 ADC_Read_B(void);

extern void ADC_ReceiveBuf_A(u32 *pBuf);
extern void ADC_ReceiveBuf_B(u32 *pBuf);

extern void ADC_InitStruct_A(ADC_InitTypeDef *ADC_InitStruct);
extern void ADC_InitStruct_B(ADC_InitTypeDef *ADC_InitStruct);

extern void ADC_Init_A(ADC_InitTypeDef* ADC_InitStruct);
extern void ADC_Init_B(ADC_InitTypeDef* ADC_InitStruct);

extern VOID BOOT_ROM_ShowBuildInfo_A(u32 Complete);
extern VOID BOOT_ROM_ShowBuildInfo_B(u32 Complete);

extern VOID BOOT_ROM_OTFCheck_A(VOID);
extern VOID BOOT_ROM_OTFCheck_B(VOID);

extern VOID BOOT_ROM_InitFlash_A(void);
extern VOID BOOT_ROM_InitFlash_B(void);

extern VOID BOOT_ROM_FromFlash_A(void);
extern VOID BOOT_ROM_FromFlash_B(void);

extern VOID BOOT_ROM_InitUsb_A(void);
extern VOID BOOT_ROM_InitUsb_B(void);

extern VOID BOOT_ROM_Process_A(VOID);
extern VOID BOOT_ROM_Process_B(VOID);

extern VOID BOOT_ROM_InitDebugFlg_A(VOID);
extern VOID BOOT_ROM_InitDebugFlg_B(VOID);

extern VOID HalResetVsr_A(VOID);
extern VOID HalResetVsr_B(VOID);

extern void Cache_Enable_A(u32 Enable);
extern void Cache_Enable_B(u32 Enable);

extern void Cache_Flush_A(void);
extern void Cache_Flush_B(void);

extern void Cache_Debug_A(u32 PrintLog);
extern void Cache_Debug_B(u32 PrintLog);

extern void CRYPTO_AlignToBe32_A(u32 *pData, int bytes4_num );
extern void CRYPTO_AlignToBe32_B(u32 *pData, int bytes4_num );

extern void CRYPTO_MemDump_A(const u8 *start, u32 size, char * strHeader);
extern void CRYPTO_MemDump_B(const u8 *start, u32 size, char * strHeader);

extern int CRYPTO_GetAESKey_A(const u8 *userKey, const int bits, RTL_SW_AES_KEY *key) ;
extern int CRYPTO_GetAESKey_B(const u8 *userKey, const int bits, RTL_SW_AES_KEY *key) ;

extern int CRYPTO_SetAESKey_A(HAL_CRYPTO_ADAPTER *pIE, const u8 *userKey, const int bits,
	const u8 *outputKey);
extern int CRYPTO_SetAESKey_B(HAL_CRYPTO_ADAPTER *pIE, const u8 *userKey, const int bits,
	const u8 *outputKey);

extern int CRYPTO_SetSecurityMode_A(HAL_CRYPTO_ADAPTER *pIE, 
	IN const u32 mode_select, IN const u32 cipher_type, IN const u32 auth_type,
	IN const void* pCipherKey, IN const u32 lenCipherKey, 
	IN const void* pAuthKey, IN const u32 lenAuthKey
	);
extern int CRYPTO_SetSecurityMode_B(HAL_CRYPTO_ADAPTER *pIE, 
	IN const u32 mode_select, IN const u32 cipher_type, IN const u32 auth_type,
	IN const void* pCipherKey, IN const u32 lenCipherKey, 
	IN const void* pAuthKey, IN const u32 lenAuthKey
	);

extern int CRYPTO_Init_A(HAL_CRYPTO_ADAPTER *pIE);
extern int CRYPTO_Init_B(HAL_CRYPTO_ADAPTER *pIE);

extern int CRYPTO_DeInit_A(HAL_CRYPTO_ADAPTER *pIE);
extern int CRYPTO_DeInit_B(HAL_CRYPTO_ADAPTER *pIE);

extern int CRYPTO_Reset_A(HAL_CRYPTO_ADAPTER *pIE);
extern int CRYPTO_Reset_B(HAL_CRYPTO_ADAPTER *pIE);

extern int CRYPTO_Process_A(HAL_CRYPTO_ADAPTER *pIE, 
	IN const u8 *message, 	IN const u32 msglen, 
	IN const u8 *pIv, 		IN const u32 ivlen,
	IN const u32 a2eo, 		OUT void *pResult);
extern int CRYPTO_Process_B(HAL_CRYPTO_ADAPTER *pIE, 
	IN const u8 *message, 	IN const u32 msglen, 
	IN const u8 *pIv, 		IN const u32 ivlen,
	IN const u32 a2eo, 		OUT void *pResult);

extern int CRYPTO_CipherInit_A(HAL_CRYPTO_ADAPTER *pIE, 
	IN const u32 cipher_type, 
	IN const u8* key, IN const u32 keylen);
extern int CRYPTO_CipherInit_B(HAL_CRYPTO_ADAPTER *pIE, 
	IN const u32 cipher_type, 
	IN const u8* key, IN const u32 keylen);

extern int CRYPTO_CipherEncrypt_A(HAL_CRYPTO_ADAPTER *pIE, 
	IN const u32 cipher_type, 	
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* piv, 		IN const u32 ivlen, 
	OUT u8* pResult);
extern int CRYPTO_CipherEncrypt_B(HAL_CRYPTO_ADAPTER *pIE, 
	IN const u32 cipher_type, 	
	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* piv, 		IN const u32 ivlen, 
	OUT u8* pResult);

extern int CRYPTO_CipherDecrypt_A(HAL_CRYPTO_ADAPTER *pIE, 
	IN const u32 cipher_type, 	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* piv, 			IN const u32 ivlen, 	
	OUT u8* pResult );
extern int CRYPTO_CipherDecrypt_B(HAL_CRYPTO_ADAPTER *pIE, 
	IN const u32 cipher_type, 	IN const u8* message, 	IN const u32 msglen, 
	IN const u8* piv, 			IN const u32 ivlen, 	
	OUT u8* pResult );

extern void CRYPTO_SetCheckSumEn_A(u32 checksum_en);
extern void CRYPTO_SetCheckSumEn_B(u32 checksum_en);

extern void CRYPTO_GetCheckSumData_A(u32* pChecksum);
extern void CRYPTO_GetCheckSumData_B(u32* pChecksum);

extern void LOGUART_StructInit_A(UART_InitTypeDef* LOGUART_InitStruct);
extern void LOGUART_StructInit_B(UART_InitTypeDef* LOGUART_InitStruct);

extern void LOGUART_Init_A(UART_InitTypeDef* LOGUART_InitStruct);
extern void LOGUART_Init_B(UART_InitTypeDef* LOGUART_InitStruct);

extern void LOGUART_PutChar_A(u8 c);
extern void LOGUART_PutChar_B(u8 c);

extern u8 LOGUART_GetChar_A(BOOL PullMode);
extern u8 LOGUART_GetChar_B(BOOL PullMode);

extern u32 LOGUART_GetIMR_A(void);
extern u32 LOGUART_GetIMR_B(void);

extern void LOGUART_SetIMR_A(u32 SetValue);
extern void LOGUART_SetIMR_B(u32 SetValue);

extern void LOGUART_WaitBusy_A(void);
extern void LOGUART_WaitBusy_B(void);

extern void DIAG_UartInit_A(BOOL InitConsol);
extern void DIAG_UartInit_B(BOOL InitConsol);

extern void DIAG_UartReInit_A(IRQ_FUN IrqFun);
extern void DIAG_UartReInit_B(IRQ_FUN IrqFun);

extern void EFUSE_PowerSwitchROM_A(u8 bWrite, u8 PwrState, u8 L25OutVoltage);
extern void EFUSE_PowerSwitchROM_B(u8 bWrite, u8 PwrState, u8 L25OutVoltage);

extern u32 EFUSE_OneByteReadROM_A(u32 CtrlSetting, u16 Addr, u8 *Data, u8 L25OutVoltage);
extern u32 EFUSE_OneByteReadROM_B(u32 CtrlSetting, u16 Addr, u8 *Data, u8 L25OutVoltage);

extern u32 EFUSE_OneByteWriteROM_A(u32 CtrlSetting, u16 Addr, u8 Data, u8 L25OutVoltage);
extern u32 EFUSE_OneByteWriteROM_B(u32 CtrlSetting, u16 Addr, u8 Data, u8 L25OutVoltage);

extern u8 EFUSE_PG_Packet_A(u8 offset , u8 WordEnable, u8 *pContant);
extern u8 EFUSE_PG_Packet_B(u8 offset , u8 WordEnable, u8 *pContant);

extern u8 EFUSE_LogicalMap_Read_A(u8 *pbuf);
extern u8 EFUSE_LogicalMap_Read_B(u8 *pbuf);

extern u8 EFUSE_LogicalMap_Write_A(u32 addr, u32 cnts, u8 *data);
extern u8 EFUSE_LogicalMap_Write_B(u32 addr, u32 cnts, u8 *data);

extern void FLASH_SetSpiMode_A(FLASH_InitTypeDef *FLASH_InitStruct, u8 SpicBitMode);
extern void FLASH_SetSpiMode_B(FLASH_InitTypeDef *FLASH_InitStruct, u8 SpicBitMode);

extern void FLASH_RxCmd_A(u8 cmd, u32 read_len, u8* read_data);
extern void FLASH_RxCmd_B(u8 cmd, u32 read_len, u8* read_data);

extern void FLASH_WaitBusy_A(u32 WaitType) ;
extern void FLASH_WaitBusy_B(u32 WaitType) ;

extern void FLASH_RxData_A(u8 cmd, u32 StartAddr, u32 read_len, u8* read_data);
extern void FLASH_RxData_B(u8 cmd, u32 StartAddr, u32 read_len, u8* read_data);

extern void FLASH_TxCmd_A(u8 cmd, u8 DataPhaseLen, u8* pData);
extern void FLASH_TxCmd_B(u8 cmd, u8 DataPhaseLen, u8* pData);

extern void FLASH_WriteEn_A(void);
extern void FLASH_WriteEn_B(void);

extern void FLASH_TxData12B_A(u32 StartAddr, u8 DataPhaseLen, u8* pData);
extern void FLASH_TxData12B_B(u32 StartAddr, u8 DataPhaseLen, u8* pData);

extern void FLASH_SetStatus_A(u8 Cmd, u32 Len, u8* Status);
extern void FLASH_SetStatus_B(u8 Cmd, u32 Len, u8* Status);

extern void FLASH_Erase_A(u32 EraseType, u32 Address);
extern void FLASH_Erase_B(u32 EraseType, u32 Address);

extern void FLASH_DeepPowerDown_A(u32 NewState);
extern void FLASH_DeepPowerDown_B(u32 NewState);

extern void FLASH_SetStatusBits_A(u32 SetBits, u32 NewState);
extern void FLASH_SetStatusBits_B(u32 SetBits, u32 NewState);

extern u32 FLASH_Calibration_A(FLASH_InitTypeDef* FLASH_InitStruct, u8 SpicBitMode, u8 LineDelay);
extern u32 FLASH_Calibration_B(FLASH_InitTypeDef* FLASH_InitStruct, u8 SpicBitMode, u8 LineDelay);

extern void FLASH_StructInit_Micron_A(FLASH_InitTypeDef* FLASH_InitStruct);
extern void FLASH_StructInit_Micron_B(FLASH_InitTypeDef* FLASH_InitStruct);

extern void FLASH_StructInit_MXIC_A(FLASH_InitTypeDef* FLASH_InitStruct);
extern void FLASH_StructInit_MXIC_B(FLASH_InitTypeDef* FLASH_InitStruct);

extern void FLASH_StructInit_GD_A(FLASH_InitTypeDef* FLASH_InitStruct);
extern void FLASH_StructInit_GD_B(FLASH_InitTypeDef* FLASH_InitStruct);

extern void FLASH_StructInit_A(FLASH_InitTypeDef* FLASH_InitStruct);
extern void FLASH_StructInit_B(FLASH_InitTypeDef* FLASH_InitStruct);

extern u8 FLASH_Init_A(u8 SpicBitMode);
extern u8 FLASH_Init_B(u8 SpicBitMode);

extern u32 FLASH_ClockDiv_A(u8 Div);
extern u32 FLASH_ClockDiv_B(u8 Div);

extern u32 FLASH_CalibrationInit_A(u8 CalibrationEnd);
extern u32 FLASH_CalibrationInit_B(u8 CalibrationEnd);

extern u32 FLASH_Calibration500MPSCmd_A(u32 NewStatus);
extern u32 FLASH_Calibration500MPSCmd_B(u32 NewStatus);

extern u32 FLASH_CalibrationPhase_A(u8 phase_int, u8 phase_sel);
extern u32 FLASH_CalibrationPhase_B(u8 phase_int, u8 phase_sel);

extern u32 FLASH_CalibrationPhaseIdx_A(u8 phase_idx);
extern u32 FLASH_CalibrationPhaseIdx_B(u8 phase_idx);

extern u32 FLASH_CalibrationNewCmd_A(u32 NewStatus);
extern u32 FLASH_CalibrationNewCmd_B(u32 NewStatus);

extern u32 FLASH_CalibrationNew_A(FLASH_InitTypeDef* FLASH_InitStruct, u8 SpicBitMode, u8 Div, u8 CalStep, u8 LineDelay, u8 StartIdx) ;
extern u32 FLASH_CalibrationNew_B(FLASH_InitTypeDef* FLASH_InitStruct, u8 SpicBitMode, u8 Div, u8 CalStep, u8 LineDelay, u8 StartIdx) ;

extern int _strcmp_A(const char *cs, const char *ct);
extern int _strcmp_B(const char *cs, const char *ct);

extern u32 SYSCFG1_AutoLoadDone_A(void);
extern u32 SYSCFG1_AutoLoadDone_B(void);

extern void VECTOR_TableInit_A(u32 StackP);
extern void VECTOR_TableInit_B(u32 StackP);

extern void RCC_PeriphClockCmd_A(u32 APBPeriph_in, u32 APBPeriph_Clock_in, u8 NewState);
extern void RCC_PeriphClockCmd_B(u32 APBPeriph_in, u32 APBPeriph_Clock_in, u8 NewState);

extern void OTF_Mask_A(u32 MaskIdx, u32 Addr, u32 Len, u32 NewStatus);
extern void OTF_Mask_B(u32 MaskIdx, u32 Addr, u32 Len, u32 NewStatus);

extern u32 SYSCFG1_TRP_LDOMode_A(void);
extern u32 SYSCFG1_TRP_LDOMode_B(void);

extern u32 SYSCFG2_ROMINFO_Get_A(void);
extern u32 SYSCFG2_ROMINFO_Get_B(void);

extern u32 RDP_EN_Request_A(void);
extern u32 RDP_EN_Request_B(void);

extern u32 KEY_Request_A(u32 KeyTypeBit);
extern u32 KEY_Request_B(u32 KeyTypeBit);

extern void GPIO_Init_A(GPIO_InitTypeDef  *GPIO_InitStruct);
extern void GPIO_Init_B(GPIO_InitTypeDef  *GPIO_InitStruct);

extern void GPIO_DeInit_A(u32 GPIO_Pin);
extern void GPIO_DeInit_B(u32 GPIO_Pin);

extern u32 GPIO_ReadDataBit_A(u32 GPIO_Pin);
extern u32 GPIO_ReadDataBit_B(u32 GPIO_Pin);

extern void md5_A( const unsigned char *input, size_t ilen, unsigned char output[16] );
extern void md5_B( const unsigned char *input, size_t ilen, unsigned char output[16] );

extern int rom_ed25519_verify_signature_A(const unsigned char sig[],
                                 const unsigned char *m, unsigned long long mlen,
                                 const unsigned char pk[]);
extern int rom_ed25519_verify_signature_B(const unsigned char sig[],
                                 const unsigned char *m, unsigned long long mlen,
                                 const unsigned char pk[]);
#endif
