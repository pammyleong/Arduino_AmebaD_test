#ifndef __ROM_PARSE_H_
#define __ROM_PARSE_H_

#include <basic_types.h>
#include <drv_types.h>
#include <rtl_math_types.h>
#include "ameba_soc.h"
#include "rtl_consol.h"
#include "xmodem_rom.h"
#include "Ecp.h"
#include "Md5.h"
#include "Pem.h"
#include "Pk.h"
#include "Asn1.h"
#include "Cipher.h"
#include "Sha1.h"
#include "Sha256.h"
#include "Sha512.h"
#include "Hmac_drbg.h"
#include "aes.h"
#include "va_list.h"
#include "arc4.h"
#include "bignum.h"
#include "ctr_drbg.h"
#include "des.h"
#include "dhm.h"
#include "ecdh.h"
#include "md.h"
#include "ecdsa.h"

#include "phydm_types.h"
#include <rom_sha1.h>
#include "rom_md5.h"
#include "rom_rc4.h"
#include "rom_arc4.h"
#include "phydm_DIG.h"
#include "hal_data.h"


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

extern void GDMA_StructInit_A(PGDMA_InitTypeDef GDMA_InitStruct);
extern void GDMA_StructInit_B(PGDMA_InitTypeDef GDMA_InitStruct);

extern void GDMA_SetLLP_A(u8 GDMA_Index, u8 GDMA_ChNum, u32 MultiBlockCount, struct GDMA_CH_LLI *pGdmaChLli);
extern void GDMA_SetLLP_B(u8 GDMA_Index, u8 GDMA_ChNum, u32 MultiBlockCount, struct GDMA_CH_LLI *pGdmaChLli);

extern u32 GDMA_ClearINTPendingBit_A(u8 GDMA_Index, u8 GDMA_ChNum, u32 GDMA_IT);
extern u32 GDMA_ClearINTPendingBit_B(u8 GDMA_Index, u8 GDMA_ChNum, u32 GDMA_IT);

extern u32 GDMA_ClearINT_A(u8 GDMA_Index, u8 GDMA_ChNum);
extern u32 GDMA_ClearINT_B(u8 GDMA_Index, u8 GDMA_ChNum);

extern void GDMA_INTConfig_A(u8 GDMA_Index, u8 GDMA_ChNum, u32 GDMA_IT, u32 NewState);
extern void GDMA_INTConfig_B(u8 GDMA_Index, u8 GDMA_ChNum, u32 GDMA_IT, u32 NewState);

extern void GDMA_Cmd_A(u8 GDMA_Index, u8 GDMA_ChNum, u32 NewState);
extern void GDMA_Cmd_B(u8 GDMA_Index, u8 GDMA_ChNum, u32 NewState);

extern void GDMA_Init_A(u8 GDMA_Index, u8 GDMA_ChNum, PGDMA_InitTypeDef GDMA_InitStruct);
extern void GDMA_Init_B(u8 GDMA_Index, u8 GDMA_ChNum, PGDMA_InitTypeDef GDMA_InitStruct);

extern void GDMA_ChCleanAutoReload_A(u8 GDMA_Index, u8 GDMA_ChNum, u32 CleanType);
extern void GDMA_ChCleanAutoReload_B(u8 GDMA_Index, u8 GDMA_ChNum, u32 CleanType);

extern void GDMA_SetSrcAddr_A(u8 GDMA_Index, u8 GDMA_ChNum, u32 SrcAddr) ;
extern void GDMA_SetSrcAddr_B(u8 GDMA_Index, u8 GDMA_ChNum, u32 SrcAddr) ;

extern u32 GDMA_GetSrcAddr_A(u8 GDMA_Index, u8 GDMA_ChNum) ;
extern u32 GDMA_GetSrcAddr_B(u8 GDMA_Index, u8 GDMA_ChNum) ;

extern u32 GDMA_GetDstAddr_A(u8 GDMA_Index, u8 GDMA_ChNum) ;
extern u32 GDMA_GetDstAddr_B(u8 GDMA_Index, u8 GDMA_ChNum) ;

extern void GDMA_SetDstAddr_A(u8 GDMA_Index, u8 GDMA_ChNum, u32 DstAddr);
extern void GDMA_SetDstAddr_B(u8 GDMA_Index, u8 GDMA_ChNum, u32 DstAddr);

extern void GDMA_SetBlkSize_A(u8 GDMA_Index, u8 GDMA_ChNum, u32 BlkSize);
extern void GDMA_SetBlkSize_B(u8 GDMA_Index, u8 GDMA_ChNum, u32 BlkSize);

extern u32 GDMA_GetBlkSize_A(u8 GDMA_Index, u8 GDMA_ChNum);
extern u32 GDMA_GetBlkSize_B(u8 GDMA_Index, u8 GDMA_ChNum);

extern BOOL GDMA_ChnlRegister_A(u8 GDMA_Index, u8 GDMA_ChNum);
extern BOOL GDMA_ChnlRegister_B(u8 GDMA_Index, u8 GDMA_ChNum);

extern void GDMA_ChnlUnRegister_A(u8 GDMA_Index, u8 GDMA_ChNum);
extern void GDMA_ChnlUnRegister_B(u8 GDMA_Index, u8 GDMA_ChNum);

extern u8 GDMA_ChnlAlloc_A(u32 GDMA_Index, IRQ_FUN IrqFun, u32 IrqData, u32 IrqPriority);
extern u8 GDMA_ChnlAlloc_B(u32 GDMA_Index, IRQ_FUN IrqFun, u32 IrqData, u32 IrqPriority);

extern void GDMA_ChnlFree_A(u8 GDMA_Index, u8 GDMA_ChNum);
extern void GDMA_ChnlFree_B(u8 GDMA_Index, u8 GDMA_ChNum);

extern void GPIO_INTMode_A(u32 GPIO_Pin, u32 NewState,
	u32 GPIO_ITTrigger,
	u32 GPIO_ITPolarity,
	u32 GPIO_ITDebounce);
extern void GPIO_INTMode_B(u32 GPIO_Pin, u32 NewState,
	u32 GPIO_ITTrigger,
	u32 GPIO_ITPolarity,
	u32 GPIO_ITDebounce);

extern void GPIO_INTConfig_A(u32 GPIO_Pin, u32 NewState);
extern void GPIO_INTConfig_B(u32 GPIO_Pin, u32 NewState);

extern u32 GPIO_INTHandler_A(IN VOID *pData);
extern u32 GPIO_INTHandler_B(IN VOID *pData);

extern void GPIO_Direction_A(u32 GPIO_Pin, u32 data_direction);
extern void GPIO_Direction_B(u32 GPIO_Pin, u32 data_direction);

extern void GPIO_Init_A(GPIO_InitTypeDef  *GPIO_InitStruct);
extern void GPIO_Init_B(GPIO_InitTypeDef  *GPIO_InitStruct);

extern void GPIO_DeInit_A(u32 GPIO_Pin);
extern void GPIO_DeInit_B(u32 GPIO_Pin);

extern u32 GPIO_ReadDataBit_A(u32 GPIO_Pin);
extern u32 GPIO_ReadDataBit_B(u32 GPIO_Pin);

extern void GPIO_WriteBit_A(u32 GPIO_Pin, u32 Pin_State);
extern void GPIO_WriteBit_B(u32 GPIO_Pin, u32 Pin_State);

extern void GPIO_PortDirection_A(u32 GPIO_Port, u32 GPIO_Mask, u32 data_direction);
extern void GPIO_PortDirection_B(u32 GPIO_Port, u32 GPIO_Mask, u32 data_direction);

extern u32 GPIO_PortRead_A(u32 GPIO_Port, u32 GPIO_Mask);
extern u32 GPIO_PortRead_B(u32 GPIO_Port, u32 GPIO_Mask);

extern void GPIO_PortWrite_A(u32 GPIO_Port, u32 GPIO_Mask, u32 Port_State);
extern void GPIO_PortWrite_B(u32 GPIO_Port, u32 GPIO_Mask, u32 Port_State);

extern void GPIO_UserRegIrq_A(u32 GPIO_Pin, VOID *IrqHandler, VOID *IrqData);
extern void GPIO_UserRegIrq_B(u32 GPIO_Pin, VOID *IrqHandler, VOID *IrqData);

extern void I2C_StructInit_A(I2C_InitTypeDef* I2C_InitStruct);
extern void I2C_StructInit_B(I2C_InitTypeDef* I2C_InitStruct);

extern void I2C_SetSpeed_A(I2C_TypeDef *I2Cx, u32 SpdMd, u32 I2Clk, u32 I2CIPClk);
extern void I2C_SetSpeed_B(I2C_TypeDef *I2Cx, u32 SpdMd, u32 I2Clk, u32 I2CIPClk);

extern void I2C_SetSlaveAddress_A(I2C_TypeDef *I2Cx, u16 Address);
extern void I2C_SetSlaveAddress_B(I2C_TypeDef *I2Cx, u16 Address);

extern u8 I2C_CheckFlagState_A(I2C_TypeDef *I2Cx, u32 I2C_FLAG);
extern u8 I2C_CheckFlagState_B(I2C_TypeDef *I2Cx, u32 I2C_FLAG);

extern void I2C_INTConfig_A(I2C_TypeDef *I2Cx, u32 I2C_IT, u32 NewState);
extern void I2C_INTConfig_B(I2C_TypeDef *I2Cx, u32 I2C_IT, u32 NewState);

extern void I2C_ClearINT_A(I2C_TypeDef *I2Cx, u32 INTrBit);
extern void I2C_ClearINT_B(I2C_TypeDef *I2Cx, u32 INTrBit);

extern void I2C_ClearAllINT_A(I2C_TypeDef *I2Cx);
extern void I2C_ClearAllINT_B(I2C_TypeDef *I2Cx);

extern void I2C_Init_A(I2C_TypeDef *I2Cx, I2C_InitTypeDef* I2C_InitStruct);
extern void I2C_Init_B(I2C_TypeDef *I2Cx, I2C_InitTypeDef* I2C_InitStruct);

extern u32 I2C_GetRawINT_A(I2C_TypeDef *I2Cx);
extern u32 I2C_GetRawINT_B(I2C_TypeDef *I2Cx);

extern u32 I2C_GetINT_A(I2C_TypeDef *I2Cx);
extern u32 I2C_GetINT_B(I2C_TypeDef *I2Cx);

extern void I2C_MasterSendNullData_A(I2C_TypeDef *I2Cx, u8* pBuf, u8  I2CCmd, u8  I2CStop, u8  I2CReSTR);
extern void I2C_MasterSendNullData_B(I2C_TypeDef *I2Cx, u8* pBuf, u8  I2CCmd, u8  I2CStop, u8  I2CReSTR);

extern void I2C_MasterSend_A(I2C_TypeDef *I2Cx, u8* pBuf, u8  I2CCmd, u8  I2CStop, u8  I2CReSTR);
extern void I2C_MasterSend_B(I2C_TypeDef *I2Cx, u8* pBuf, u8  I2CCmd, u8  I2CStop, u8  I2CReSTR);

extern void I2C_SlaveSend_A(I2C_TypeDef *I2Cx, u8 Data);
extern void I2C_SlaveSend_B(I2C_TypeDef *I2Cx, u8 Data);

extern u8 I2C_ReceiveData_A(I2C_TypeDef *I2Cx);
extern u8 I2C_ReceiveData_B(I2C_TypeDef *I2Cx);

extern void I2C_MasterWrite_A(I2C_TypeDef *I2Cx, u8* pBuf, u8 len);
extern void I2C_MasterWrite_B(I2C_TypeDef *I2Cx, u8* pBuf, u8 len);

extern void I2C_MasterReadDW_A(I2C_TypeDef *I2Cx, u8* pBuf, u8 len);
extern void I2C_MasterReadDW_B(I2C_TypeDef *I2Cx, u8* pBuf, u8 len);

extern u8 I2C_MasterRead_A(I2C_TypeDef *I2Cx, u8* pBuf, u8 len);
extern u8 I2C_MasterRead_B(I2C_TypeDef *I2Cx, u8* pBuf, u8 len);

extern void I2C_SlaveWrite_A(I2C_TypeDef *I2Cx, u8* pBuf, u8 len);
extern void I2C_SlaveWrite_B(I2C_TypeDef *I2Cx, u8* pBuf, u8 len);

extern void I2C_SlaveRead_A(I2C_TypeDef *I2Cx, u8* pBuf, u8 len);
extern void I2C_SlaveRead_B(I2C_TypeDef *I2Cx, u8* pBuf, u8 len);

extern void I2C_MasterRepeatRead_A(I2C_TypeDef* I2Cx, u8* pWriteBuf, u8 Writelen, u8* pReadBuf, u8 Readlen);
extern void I2C_MasterRepeatRead_B(I2C_TypeDef* I2Cx, u8* pWriteBuf, u8 Writelen, u8* pReadBuf, u8 Readlen);

extern void I2C_Cmd_A(I2C_TypeDef *I2Cx, u8 NewState);
extern void I2C_Cmd_B(I2C_TypeDef *I2Cx, u8 NewState);

extern void I2C_PinMuxInit_A(u8 I2CIdx, u8 PinMux);
extern void I2C_PinMuxInit_B(u8 I2CIdx, u8 PinMux);

extern void I2C_PinMuxDeInit_A(u8 I2CIdx, u8 PinMux);
extern void I2C_PinMuxDeInit_B(u8 I2CIdx, u8 PinMux);

extern void I2C_DMAControl_A(I2C_TypeDef *I2Cx, u32 DmaCtrl, u8 NewState);
extern void I2C_DMAControl_B(I2C_TypeDef *I2Cx, u32 DmaCtrl, u8 NewState);

extern void I2C_DmaMode1Config_A(I2C_TypeDef *I2Cx, u32 I2C_DmaCmd, u32 I2C_DmaBLen);
extern void I2C_DmaMode1Config_B(I2C_TypeDef *I2Cx, u32 I2C_DmaCmd, u32 I2C_DmaBLen);

extern void I2C_DmaMode2Config_A(I2C_TypeDef *I2Cx, u32 I2C_DmaCmd, u32 I2C_DmaBLen);
extern void I2C_DmaMode2Config_B(I2C_TypeDef *I2Cx, u32 I2C_DmaCmd, u32 I2C_DmaBLen);

extern BOOL I2C_TXGDMA_Init_A(u8 Index, GDMA_InitTypeDef *GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pTxBuf, int TxCount);
extern BOOL I2C_TXGDMA_Init_B(u8 Index, GDMA_InitTypeDef *GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pTxBuf, int TxCount);

extern BOOL I2C_RXGDMA_Init_A(u8 Index, GDMA_InitTypeDef *GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pRxBuf, int RxCount);
extern BOOL I2C_RXGDMA_Init_B(u8 Index, GDMA_InitTypeDef *GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pRxBuf, int RxCount);

extern void I2C_Sleep_Cmd_A(I2C_TypeDef *I2Cx, u32 NewStatus);
extern void I2C_Sleep_Cmd_B(I2C_TypeDef *I2Cx, u32 NewStatus);

extern void I2C_WakeUp_A(I2C_TypeDef *I2Cx);
extern void I2C_WakeUp_B(I2C_TypeDef *I2Cx);

extern void I2S_StructInit_A(I2S_InitTypeDef* I2S_InitStruct);
extern void I2S_StructInit_B(I2S_InitTypeDef* I2S_InitStruct);

extern void I2S_Cmd_A(I2S_TypeDef* I2Sx, u8  NewState);
extern void I2S_Cmd_B(I2S_TypeDef* I2Sx, u8  NewState);

extern void I2S_TxDmaCmd_A(I2S_TypeDef* I2Sx, u32 NewState);
extern void I2S_TxDmaCmd_B(I2S_TypeDef* I2Sx, u32 NewState);

extern void I2S_RxDmaCmd_A(I2S_TypeDef* I2Sx, u32 NewState);
extern void I2S_RxDmaCmd_B(I2S_TypeDef* I2Sx, u32 NewState);

extern void I2S_INTConfig_A(I2S_TypeDef* I2Sx, u32 I2STxIntrMSK, u32 I2SRxIntrMSK);
extern void I2S_INTConfig_B(I2S_TypeDef* I2Sx, u32 I2STxIntrMSK, u32 I2SRxIntrMSK);

extern void I2S_INTClear_A(I2S_TypeDef* I2Sx, u32 I2STxIntrClr, u32 I2SRxIntrClr);
extern void I2S_INTClear_B(I2S_TypeDef* I2Sx, u32 I2STxIntrClr, u32 I2SRxIntrClr);

extern void I2S_INTClearAll_A(I2S_TypeDef* I2Sx);
extern void I2S_INTClearAll_B(I2S_TypeDef* I2Sx);

extern void I2S_Init_A(I2S_TypeDef* I2Sx, I2S_InitTypeDef* I2S_InitStruct);
extern void I2S_Init_B(I2S_TypeDef* I2Sx, I2S_InitTypeDef* I2S_InitStruct);

extern void I2S_ISRGet_A(I2S_TypeDef* I2Sx, u32* I2STxIsr, u32* I2SRxIsr);
extern void I2S_ISRGet_B(I2S_TypeDef* I2Sx, u32* I2STxIsr, u32* I2SRxIsr);

extern void I2S_SetRate_A(I2S_TypeDef* I2Sx, u32 I2S_Rate);
extern void I2S_SetRate_B(I2S_TypeDef* I2Sx, u32 I2S_Rate);

extern void I2S_SetWordLen_A(I2S_TypeDef* I2Sx, u32 I2S_WordLen);
extern void I2S_SetWordLen_B(I2S_TypeDef* I2Sx, u32 I2S_WordLen);

extern void I2S_SetChNum_A(I2S_TypeDef* I2Sx, u32 I2S_ChNum);
extern void I2S_SetChNum_B(I2S_TypeDef* I2Sx, u32 I2S_ChNum);

extern void I2S_SetPageNum_A(I2S_TypeDef* I2Sx, u32 I2S_PageNum);
extern void I2S_SetPageNum_B(I2S_TypeDef* I2Sx, u32 I2S_PageNum);

extern void I2S_SetPageSize_A(I2S_TypeDef* I2Sx, u32 I2S_PageSize);
extern void I2S_SetPageSize_B(I2S_TypeDef* I2Sx, u32 I2S_PageSize);

extern u32 I2S_GetPageSize_A(I2S_TypeDef* I2Sx);
extern u32 I2S_GetPageSize_B(I2S_TypeDef* I2Sx);

extern void I2S_SetDirection_A(I2S_TypeDef* I2Sx, u32 I2S_TRxAct);
extern void I2S_SetDirection_B(I2S_TypeDef* I2Sx, u32 I2S_TRxAct);

extern void I2S_SetDMABuf_A(I2S_TypeDef* I2Sx, u8 *I2STxData, u8 *I2SRxData);
extern void I2S_SetDMABuf_B(I2S_TypeDef* I2Sx, u8 *I2STxData, u8 *I2SRxData);

extern u32 I2S_TxPageBusy_A(I2S_TypeDef* I2Sx, u32 page_index);
extern u32 I2S_TxPageBusy_B(I2S_TypeDef* I2Sx, u32 page_index);

extern u32 I2S_GetTxPage_A(I2S_TypeDef* I2Sx);
extern u32 I2S_GetTxPage_B(I2S_TypeDef* I2Sx);

extern u32 I2S_GetRxPage_A(I2S_TypeDef* I2Sx);
extern u32 I2S_GetRxPage_B(I2S_TypeDef* I2Sx);

extern void I2S_SetTxPageAddr_A(u32 page_index, u32 page_address);
extern void I2S_SetTxPageAddr_B(u32 page_index, u32 page_address);

extern u32 I2S_GetTxPageAddr_A(u32 page_index);
extern u32 I2S_GetTxPageAddr_B(u32 page_index);

extern void I2S_SetRxPageAddr_A(u32 page_index, u32 page_address);
extern void I2S_SetRxPageAddr_B(u32 page_index, u32 page_address);

extern u32 I2S_GetRxPageAddr_A(u32 page_index);
extern u32 I2S_GetRxPageAddr_B(u32 page_index);

extern void I2S_TxPageDMA_EN_A(I2S_TypeDef* I2Sx, u32 I2STxIdx);
extern void I2S_TxPageDMA_EN_B(I2S_TypeDef* I2Sx, u32 I2STxIdx);

extern void I2S_RxPageDMA_EN_A(I2S_TypeDef* I2Sx,u32 I2SRxIdx);
extern void I2S_RxPageDMA_EN_B(I2S_TypeDef* I2Sx,u32 I2SRxIdx);

extern void io_assert_failed_A(uint8_t* file, uint32_t line);
extern void io_assert_failed_B(uint8_t* file, uint32_t line);

extern void OTF_init_A(u8* IV);
extern void OTF_init_B(u8* IV);

extern void OTF_Cmd_A(u32 NewStatus);
extern void OTF_Cmd_B(u32 NewStatus);

extern void OTF_Mask_A(u32 MaskIdx, u32 Addr, u32 Len, u32 NewStatus);
extern void OTF_Mask_B(u32 MaskIdx, u32 Addr, u32 Len, u32 NewStatus);

extern u32 KEY_Request_A(u32 KeyTypeBit);
extern u32 KEY_Request_B(u32 KeyTypeBit);

extern u32 RDP_EN_Request_A(void);
extern u32 RDP_EN_Request_B(void);

extern void RCC_PeriphClockCmd_A(u32 APBPeriph_in, u32 APBPeriph_Clock_in, u8 NewState);
extern void RCC_PeriphClockCmd_B(u32 APBPeriph_in, u32 APBPeriph_Clock_in, u8 NewState);

extern void FUNC_HCI_COM_A(u32 Function_Bit, u8 NewState);
extern void FUNC_HCI_COM_B(u32 Function_Bit, u8 NewState);

extern u8 RTC_ByteToBcd2_A(u8 Value);
extern u8 RTC_ByteToBcd2_B(u8 Value);

extern u8 RTC_Bcd2ToByte_A(u8 Value);
extern u8 RTC_Bcd2ToByte_B(u8 Value);

extern void RTC_ClokSource_A(u32 Xtal);
extern void RTC_ClokSource_B(u32 Xtal);

extern u32 RTC_EnterInitMode_A(void);
extern u32 RTC_EnterInitMode_B(void);

extern void RTC_ExitInitMode_A(void);
extern void RTC_ExitInitMode_B(void);

extern u32 RTC_WaitForSynchro_A(void);
extern u32 RTC_WaitForSynchro_B(void);

extern void RTC_BypassShadowCmd_A(u32 NewState);
extern void RTC_BypassShadowCmd_B(u32 NewState);

extern void RTC_StructInit_A(RTC_InitTypeDef* RTC_InitStruct);
extern void RTC_StructInit_B(RTC_InitTypeDef* RTC_InitStruct);

extern u32 RTC_Init_A(RTC_InitTypeDef* RTC_InitStruct);
extern u32 RTC_Init_B(RTC_InitTypeDef* RTC_InitStruct);

extern void RTC_TimeStructInit_A(RTC_TimeTypeDef* RTC_TimeStruct);
extern void RTC_TimeStructInit_B(RTC_TimeTypeDef* RTC_TimeStruct);

extern u32 RTC_SetTime_A(u32 RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct);
extern u32 RTC_SetTime_B(u32 RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct);

extern void RTC_GetTime_A(u32 RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct);
extern void RTC_GetTime_B(u32 RTC_Format, RTC_TimeTypeDef* RTC_TimeStruct);

extern u32 RTC_SetAlarm_A(u32 RTC_Format, RTC_AlarmTypeDef* RTC_AlarmStruct);
extern u32 RTC_SetAlarm_B(u32 RTC_Format, RTC_AlarmTypeDef* RTC_AlarmStruct);

extern void RTC_AlarmStructInit_A(RTC_AlarmTypeDef* RTC_AlarmStruct);
extern void RTC_AlarmStructInit_B(RTC_AlarmTypeDef* RTC_AlarmStruct);

extern void RTC_GetAlarm_A(u32 RTC_Format, RTC_AlarmTypeDef* RTC_AlarmStruct);
extern void RTC_GetAlarm_B(u32 RTC_Format, RTC_AlarmTypeDef* RTC_AlarmStruct);

extern void RTC_AlarmCmd_A(u32 NewState);
extern void RTC_AlarmCmd_B(u32 NewState);

extern void RTC_AlarmClear_A(void);
extern void RTC_AlarmClear_B(void);

extern void RTC_DayLightSavingConfig_A(u32 RTC_DayLightSaving, u32 RTC_StoreOperation);
extern void RTC_DayLightSavingConfig_B(u32 RTC_DayLightSaving, u32 RTC_StoreOperation);

extern u32 RTC_GetStoreOperation_A(void);
extern u32 RTC_GetStoreOperation_B(void);

extern void RTC_OutputConfig_A(u32 RTC_Output);
extern void RTC_OutputConfig_B(u32 RTC_Output);

extern u32 RTC_SmoothCalibConfig_A(u32 CalibSign, u32 Value, u32 CalibPeriod, u32 Calib_Enable);
extern u32 RTC_SmoothCalibConfig_B(u32 CalibSign, u32 Value, u32 CalibPeriod, u32 Calib_Enable);

extern u8 SDIO_IsTimeout_A (u32 StartCount, u32 TimeoutCnt);
extern u8 SDIO_IsTimeout_B (u32 StartCount, u32 TimeoutCnt);

extern BOOL SDIOB_Init_A(VOID);
extern BOOL SDIOB_Init_B(VOID);

extern VOID SDIOB_INTConfig_A(u32 MaskBit, u32 NewState);
extern VOID SDIOB_INTConfig_B(u32 MaskBit, u32 NewState);

extern VOID SDIOB_DeInit_A(VOID);
extern VOID SDIOB_DeInit_B(VOID);

extern u8 SDIOB_H2C_WriteMem_A(IN u8 *DesAddr, IN u8 *SrcAddr, IN u16 Len, IN u8 Reply);
extern u8 SDIOB_H2C_WriteMem_B(IN u8 *DesAddr, IN u8 *SrcAddr, IN u16 Len, IN u8 Reply);

extern u8 SDIOB_H2C_SetMem_A(IN u8 *DesAddr, IN u8 Data, IN u16 Len, IN u8 Reply);
extern u8 SDIOB_H2C_SetMem_B(IN u8 *DesAddr, IN u8 Data, IN u16 Len, IN u8 Reply);

extern VOID SDIOB_H2C_DataHandle_A(u8 *pPkt, RAM_START_FUNCTION *pImageEntryFun);
extern VOID SDIOB_H2C_DataHandle_B(u8 *pPkt, RAM_START_FUNCTION *pImageEntryFun);

extern VOID SDIOB_H2C_DataReady_A(RAM_START_FUNCTION *pImageEntryFun);
extern VOID SDIOB_H2C_DataReady_B(RAM_START_FUNCTION *pImageEntryFun);

extern VOID SDIOB_IRQ_Handler_BH_A(u16 ISRStatus, RAM_START_FUNCTION *pImageEntryFun);
extern VOID SDIOB_IRQ_Handler_BH_B(u16 ISRStatus, RAM_START_FUNCTION *pImageEntryFun);

extern VOID SDIOB_H2C_Task_A(RAM_START_FUNCTION *pImageEntryFun);
extern VOID SDIOB_H2C_Task_B(RAM_START_FUNCTION *pImageEntryFun);

extern VOID SDIO_Boot_Up_A(VOID);
extern VOID SDIO_Boot_Up_B(VOID);

extern HAL_Status SPI_DmaInit_A(IN SPI_TypeDef *spi_dev, IN PGDMA_InitTypeDef pSSIRxGdmaInitStruct, IN u8  *pRxData, IN u32 Length);
extern HAL_Status SPI_DmaInit_B(IN SPI_TypeDef *spi_dev, IN PGDMA_InitTypeDef pSSIRxGdmaInitStruct, IN u8  *pRxData, IN u32 Length);

extern VOID SPI_DataHandle_A(u8 *pPkt, u16* precv_end);
extern VOID SPI_DataHandle_B(u8 *pPkt, u16* precv_end);

extern VOID SPI_Boot_DmaRxIrqHandle_A (VOID *Data);
extern VOID SPI_Boot_DmaRxIrqHandle_B (VOID *Data);

extern VOID SPI_Boot_ROM_A(VOID);
extern VOID SPI_Boot_ROM_B(VOID);

extern void SSI_StructInit_A(SSI_InitTypeDef* SSI_InitStruct);
extern void SSI_StructInit_B(SSI_InitTypeDef* SSI_InitStruct);

extern void SSI_Cmd_A(SPI_TypeDef *spi_dev, u32 NewStatus);
extern void SSI_Cmd_B(SPI_TypeDef *spi_dev, u32 NewStatus);

extern VOID SSI_INTConfig_A(SPI_TypeDef* spi_dev, u32 SSI_IT, u32 newState);
extern VOID SSI_INTConfig_B(SPI_TypeDef* spi_dev, u32 SSI_IT, u32 newState);

extern void SSI_SetSclkPolarity_A(SPI_TypeDef *spi_dev, u32 SclkPolarity);
extern void SSI_SetSclkPolarity_B(SPI_TypeDef *spi_dev, u32 SclkPolarity);

extern void SSI_SetSclkPhase_A(SPI_TypeDef *spi_dev, u32 SclkPhase);
extern void SSI_SetSclkPhase_B(SPI_TypeDef *spi_dev, u32 SclkPhase);

extern void SSI_SetDataFrameSize_A(SPI_TypeDef *spi_dev, u32 DataFrameSize);
extern void SSI_SetDataFrameSize_B(SPI_TypeDef *spi_dev, u32 DataFrameSize);

extern void SSI_SetReadLen_A(SPI_TypeDef *spi_dev, u32 DataFrameNumber);
extern void SSI_SetReadLen_B(SPI_TypeDef *spi_dev, u32 DataFrameNumber);

extern void SSI_SetBaudDiv_A(SPI_TypeDef *spi_dev, u32 ClockDivider);
extern void SSI_SetBaudDiv_B(SPI_TypeDef *spi_dev, u32 ClockDivider);

extern void SSI_SetBaud_A(SPI_TypeDef *SPIx, u32 BaudRate, u32 IpClk);
extern void SSI_SetBaud_B(SPI_TypeDef *SPIx, u32 BaudRate, u32 IpClk);

extern void SSI_SetDmaEnable_A(SPI_TypeDef *spi_dev, u32 newState, u32 Mask);
extern void SSI_SetDmaEnable_B(SPI_TypeDef *spi_dev, u32 newState, u32 Mask);

extern void SSI_SetDmaLevel_A(SPI_TypeDef *spi_dev, u32 TxLevel, u32 RxLevel);
extern void SSI_SetDmaLevel_B(SPI_TypeDef *spi_dev, u32 TxLevel, u32 RxLevel);

extern void SSI_SetIsrClean_A(SPI_TypeDef *spi_dev, u32 InterruptStatus);
extern void SSI_SetIsrClean_B(SPI_TypeDef *spi_dev, u32 InterruptStatus);

extern void SSI_WriteData_A(SPI_TypeDef *spi_dev, u32 value);
extern void SSI_WriteData_B(SPI_TypeDef *spi_dev, u32 value);

extern void SSI_SetRxFifoLevel_A(SPI_TypeDef *spi_dev, u32 RxThresholdLevel);
extern void SSI_SetRxFifoLevel_B(SPI_TypeDef *spi_dev, u32 RxThresholdLevel);

extern void SSI_SetTxFifoLevel_A(SPI_TypeDef *spi_dev, u32 TxThresholdLevel);
extern void SSI_SetTxFifoLevel_B(SPI_TypeDef *spi_dev, u32 TxThresholdLevel);

extern u32 SSI_ReadData_A(SPI_TypeDef *spi_dev);
extern u32 SSI_ReadData_B(SPI_TypeDef *spi_dev);

extern u32 SSI_GetRxCount_A(SPI_TypeDef *spi_dev);
extern u32 SSI_GetRxCount_B(SPI_TypeDef *spi_dev);

extern u32 SSI_GetTxCount_A(SPI_TypeDef *spi_dev);
extern u32 SSI_GetTxCount_B(SPI_TypeDef *spi_dev);

extern u32 SSI_GetStatus_A(SPI_TypeDef *spi_dev);
extern u32 SSI_GetStatus_B(SPI_TypeDef *spi_dev);

extern u32 SSI_Writeable_A(SPI_TypeDef *spi_dev);
extern u32 SSI_Writeable_B(SPI_TypeDef *spi_dev);

extern u32 SSI_Readable_A(SPI_TypeDef *spi_dev);
extern u32 SSI_Readable_B(SPI_TypeDef *spi_dev);

extern u32 SSI_GetDataFrameSize_A(SPI_TypeDef *spi_dev);
extern u32 SSI_GetDataFrameSize_B(SPI_TypeDef *spi_dev);

extern BOOL SSI_TXGDMA_Init_A(u32 Index, PGDMA_InitTypeDef GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pTxData, u32 Length);
extern BOOL SSI_TXGDMA_Init_B(u32 Index, PGDMA_InitTypeDef GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pTxData, u32 Length);

extern BOOL SSI_RXGDMA_Init_A(u32 Index, PGDMA_InitTypeDef GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pRxData, u32 Length);
extern BOOL SSI_RXGDMA_Init_B(u32 Index, PGDMA_InitTypeDef GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pRxData, u32 Length);

extern u32 SSI_ReceiveData_A(SPI_TypeDef *spi_dev, void* RxData, u32 Length);
extern u32 SSI_ReceiveData_B(SPI_TypeDef *spi_dev, void* RxData, u32 Length);

extern u32 SSI_SendData_A(SPI_TypeDef *spi_dev, void* TxData, u32 Length, u32 Role);
extern u32 SSI_SendData_B(SPI_TypeDef *spi_dev, void* TxData, u32 Length, u32 Role);

extern u32 SSI_Busy_A(SPI_TypeDef *spi_dev);
extern u32 SSI_Busy_B(SPI_TypeDef *spi_dev);

extern void SSI_SetSlaveEnable_A(SPI_TypeDef *spi_dev, u32 SlaveIndex);
extern void SSI_SetSlaveEnable_B(SPI_TypeDef *spi_dev, u32 SlaveIndex);

extern void SSI_Init_A(SPI_TypeDef *spi_dev, SSI_InitTypeDef *SSI_InitStruct);
extern void SSI_Init_B(SPI_TypeDef *spi_dev, SSI_InitTypeDef *SSI_InitStruct);

extern u32 SSI_GetIsr_A(SPI_TypeDef *spi_dev);
extern u32 SSI_GetIsr_B(SPI_TypeDef *spi_dev);

extern u32 SSI_GetRawIsr_A(SPI_TypeDef *spi_dev);
extern u32 SSI_GetRawIsr_B(SPI_TypeDef *spi_dev);

extern u32 SSI_GetSlaveEnable_A(SPI_TypeDef *spi_dev);
extern u32 SSI_GetSlaveEnable_B(SPI_TypeDef *spi_dev);

extern void SSI_PinmuxInit_A(u8 Index, u32 PinmuxSelect);
extern void SSI_PinmuxInit_B(u8 Index, u32 PinmuxSelect);

extern void SSI_PinmuxDeInit_A(u8 Index, u32 PinmuxSelect);
extern void SSI_PinmuxDeInit_B(u8 Index, u32 PinmuxSelect);

extern u32 SYSCFG0_Get_A(void);
extern u32 SYSCFG0_Get_B(void);

extern u32 SYSCFG0_CUTVersion_A(void);
extern u32 SYSCFG0_CUTVersion_B(void);

extern u32 SYSCFG0_BDOption_A(void);
extern u32 SYSCFG0_BDOption_B(void);

extern u32 SYSCFG1_Get_A(void);
extern u32 SYSCFG1_Get_B(void);

extern u32 SYSCFG1_AutoLoadDone_A(void);
extern u32 SYSCFG1_AutoLoadDone_B(void);

extern u32 SYSCFG1_TRP_LDOMode_A(void);
extern u32 SYSCFG1_TRP_LDOMode_B(void);

extern u32 SYSCFG1_TRP_UARTImage_A(void);
extern u32 SYSCFG1_TRP_UARTImage_B(void);

extern u32 SYSCFG1_TRP_ICFG_A(void);
extern u32 SYSCFG1_TRP_ICFG_B(void);

extern u32 SYSCFG2_Get_A(void);
extern u32 SYSCFG2_Get_B(void);

extern u32 SYSCFG2_ROMINFO_Get_A(void);
extern u32 SYSCFG2_ROMINFO_Get_B(void);

extern void SYSCFG2_ROMINFO_Set_A(void);
extern void SYSCFG2_ROMINFO_Set_B(void);

extern void RTIM_TimeBaseStructInit_A(RTIM_TimeBaseInitTypeDef* TIM_InitStruct);
extern void RTIM_TimeBaseStructInit_B(RTIM_TimeBaseInitTypeDef* TIM_InitStruct);

extern void RTIM_Cmd_A(RTIM_TypeDef* TIMx, u32 NewState);
extern void RTIM_Cmd_B(RTIM_TypeDef* TIMx, u32 NewState);

extern u32 RTIM_GetCount_A(RTIM_TypeDef* TIMx);
extern u32 RTIM_GetCount_B(RTIM_TypeDef* TIMx);

extern void RTIM_UpdateDisableConfig_A(RTIM_TypeDef* TIMx, u32 NewState);
extern void RTIM_UpdateDisableConfig_B(RTIM_TypeDef* TIMx, u32 NewState);

extern void RTIM_ARRPreloadConfig_A(RTIM_TypeDef* TIMx, u32 NewState);
extern void RTIM_ARRPreloadConfig_B(RTIM_TypeDef* TIMx, u32 NewState);

extern void RTIM_UpdateRequestConfig_A(RTIM_TypeDef* TIMx, u32 TIM_UpdateSource);
extern void RTIM_UpdateRequestConfig_B(RTIM_TypeDef* TIMx, u32 TIM_UpdateSource);

extern void RTIM_PrescalerConfig_A(RTIM_TypeDef* TIMx, u32 Prescaler, u32 TIM_PSCReloadMode);
extern void RTIM_PrescalerConfig_B(RTIM_TypeDef* TIMx, u32 Prescaler, u32 TIM_PSCReloadMode);

extern void RTIM_GenerateEvent_A(RTIM_TypeDef* TIMx, u32 TIM_EventSource);
extern void RTIM_GenerateEvent_B(RTIM_TypeDef* TIMx, u32 TIM_EventSource);

extern void RTIM_ChangePeriod_A(RTIM_TypeDef* TIMx, u32 Autoreload);
extern void RTIM_ChangePeriod_B(RTIM_TypeDef* TIMx, u32 Autoreload);

extern void RTIM_Reset_A(RTIM_TypeDef* TIMx);
extern void RTIM_Reset_B(RTIM_TypeDef* TIMx);

extern void RTIM_CCStructInit_A(TIM_CCInitTypeDef* TIM_CCInitStruct);
extern void RTIM_CCStructInit_B(TIM_CCInitTypeDef* TIM_CCInitStruct);

extern void RTIM_CCxInit_A(RTIM_TypeDef* TIMx, TIM_CCInitTypeDef* TIM_CCInitStruct, u16 TIM_Channel);
extern void RTIM_CCxInit_B(RTIM_TypeDef* TIMx, TIM_CCInitTypeDef* TIM_CCInitStruct, u16 TIM_Channel);

extern void RTIM_CCRxMode_A(RTIM_TypeDef* TIMx, u16 TIM_Channel, u32 TIM_CCMode);
extern void RTIM_CCRxMode_B(RTIM_TypeDef* TIMx, u16 TIM_Channel, u32 TIM_CCMode);

extern void RTIM_CCRxSet_A(RTIM_TypeDef* TIMx, u32 Compare, u16 TIM_Channel);
extern void RTIM_CCRxSet_B(RTIM_TypeDef* TIMx, u32 Compare, u16 TIM_Channel);

extern u32 RTIM_CCRxGet_A(RTIM_TypeDef* TIMx, u16 TIM_Channel);
extern u32 RTIM_CCRxGet_B(RTIM_TypeDef* TIMx, u16 TIM_Channel);

extern void RTIM_OCxPreloadConfig_A(RTIM_TypeDef* TIMx, u32 TIM_OCProtection, u16 TIM_Channel);
extern void RTIM_OCxPreloadConfig_B(RTIM_TypeDef* TIMx, u32 TIM_OCProtection, u16 TIM_Channel);

extern void RTIM_CCxPolarityConfig_A(RTIM_TypeDef* TIMx, u32 TIM_OCPolarity, u16 TIM_Channel);
extern void RTIM_CCxPolarityConfig_B(RTIM_TypeDef* TIMx, u32 TIM_OCPolarity, u16 TIM_Channel);

extern void RTIM_CCxCmd_A(RTIM_TypeDef* TIMx, u16 TIM_Channel, u32 TIM_CCx);
extern void RTIM_CCxCmd_B(RTIM_TypeDef* TIMx, u16 TIM_Channel, u32 TIM_CCx);

extern void RTIM_SetOnePulseOutputMode_A(RTIM_TypeDef* TIMx, u32 TIM_OPMode, u32 TrigerPolarity);
extern void RTIM_SetOnePulseOutputMode_B(RTIM_TypeDef* TIMx, u32 TIM_OPMode, u32 TrigerPolarity);

extern void RTIM_DMACmd_A(RTIM_TypeDef* TIMx, u16 TIM_DMASource, u32 NewState);
extern void RTIM_DMACmd_B(RTIM_TypeDef* TIMx, u16 TIM_DMASource, u32 NewState);

extern u32 RTIM_TXGDMA_Init_A(u32 TIM_Channel, GDMA_InitTypeDef *GdmaInitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8* pDataBuf, u32 DataLen);
extern u32 RTIM_TXGDMA_Init_B(u32 TIM_Channel, GDMA_InitTypeDef *GdmaInitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8* pDataBuf, u32 DataLen);

extern u32 RTIM_RXGDMA_Init_A(u32 TIM_Idx, u32 TIM_Channel, GDMA_InitTypeDef *GdmaInitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pDataBuf, int DataLen);
extern u32 RTIM_RXGDMA_Init_B(u32 TIM_Idx, u32 TIM_Channel, GDMA_InitTypeDef *GdmaInitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pDataBuf, int DataLen);

extern void RTIM_INTConfig_A(RTIM_TypeDef* TIMx, u32 TIM_IT, u32 NewState);
extern void RTIM_INTConfig_B(RTIM_TypeDef* TIMx, u32 TIM_IT, u32 NewState);

extern void RTIM_INTClear_A(RTIM_TypeDef* TIMx);
extern void RTIM_INTClear_B(RTIM_TypeDef* TIMx);

extern void RTIM_TimeBaseInit_A(RTIM_TypeDef* TIMx, RTIM_TimeBaseInitTypeDef* TIM_InitStruct, IRQn_Type IrqNum, IRQ_FUN UserCB, u32 UserCBData);
extern void RTIM_TimeBaseInit_B(RTIM_TypeDef* TIMx, RTIM_TimeBaseInitTypeDef* TIM_InitStruct, IRQn_Type IrqNum, IRQ_FUN UserCB, u32 UserCBData);

extern void RTIM_DeInit_A(RTIM_TypeDef* TIMx);
extern void RTIM_DeInit_B(RTIM_TypeDef* TIMx);

extern void RTIM_INTClearPendingBit_A(RTIM_TypeDef* TIMx, u16 TIM_IT);
extern void RTIM_INTClearPendingBit_B(RTIM_TypeDef* TIMx, u16 TIM_IT);

extern u32 RTIM_GetFlagStatus_A(RTIM_TypeDef* TIMx, u32 TIM_FLAG);
extern u32 RTIM_GetFlagStatus_B(RTIM_TypeDef* TIMx, u32 TIM_FLAG);

extern u32 RTIM_GetINTStatus_A(RTIM_TypeDef* TIMx, u32 TIM_IT);
extern u32 RTIM_GetINTStatus_B(RTIM_TypeDef* TIMx, u32 TIM_IT);

extern void UART_DeInit_A(UART_TypeDef* UARTx);
extern void UART_DeInit_B(UART_TypeDef* UARTx);

extern void UART_StructInit_A(UART_InitTypeDef* UART_InitStruct);
extern void UART_StructInit_B(UART_InitTypeDef* UART_InitStruct);

extern u32 UART_BaudParaGet_A(u32 baudrate, u32 *ovsr, u32 *ovsr_adj);
extern u32 UART_BaudParaGet_B(u32 baudrate, u32 *ovsr, u32 *ovsr_adj);

extern void UART_BaudParaGetFull_A(u32 IPclk, u32 baudrate, u32 *ovsr, u32 *ovsr_adj);
extern void UART_BaudParaGetFull_B(u32 IPclk, u32 baudrate, u32 *ovsr, u32 *ovsr_adj);

extern void UART_SetBaud_A(UART_TypeDef* UARTx, u32 BaudRate);
extern void UART_SetBaud_B(UART_TypeDef* UARTx, u32 BaudRate);

extern void UART_SetBaudExt_A(UART_TypeDef* UARTx, u32 Ovsr, u32 Ovsr_adj);
extern void UART_SetBaudExt_B(UART_TypeDef* UARTx, u32 Ovsr, u32 Ovsr_adj);

extern void UART_SetRxLevel_A(UART_TypeDef* UARTx, u32 FifoLv);
extern void UART_SetRxLevel_B(UART_TypeDef* UARTx, u32 FifoLv);

extern void UART_RxCmd_A(UART_TypeDef* UARTx, u32 NewState);
extern void UART_RxCmd_B(UART_TypeDef* UARTx, u32 NewState);

extern u32 UART_Writable_A(UART_TypeDef* UARTx);
extern u32 UART_Writable_B(UART_TypeDef* UARTx);

extern u32 UART_Readable_A(UART_TypeDef* UARTx);
extern u32 UART_Readable_B(UART_TypeDef* UARTx);

extern void UART_CharPut_A(UART_TypeDef* UARTx, u8 TxData);
extern void UART_CharPut_B(UART_TypeDef* UARTx, u8 TxData);

extern void UART_CharGet_A(UART_TypeDef* UARTx, u8  *pRxByte);
extern void UART_CharGet_B(UART_TypeDef* UARTx, u8  *pRxByte);

extern void UART_ReceiveData_A(UART_TypeDef* UARTx, u8* OutBuf, u32 Count);
extern void UART_ReceiveData_B(UART_TypeDef* UARTx, u8* OutBuf, u32 Count);

extern void UART_SendData_A(UART_TypeDef* UARTx, u8* InBuf, u32 Count);
extern void UART_SendData_B(UART_TypeDef* UARTx, u8* InBuf, u32 Count);

extern u32 UART_ReceiveDataTO_A(UART_TypeDef* UARTx,	u8* OutBuf, u32 Count, u32 Times);
extern u32 UART_ReceiveDataTO_B(UART_TypeDef* UARTx,	u8* OutBuf, u32 Count, u32 Times);

extern u32 UART_SendDataTO_A(UART_TypeDef* UARTx, u8* InBuf, u32 Count, u32 Times);
extern u32 UART_SendDataTO_B(UART_TypeDef* UARTx, u8* InBuf, u32 Count, u32 Times);

extern void UART_RxByteCntClear_A(UART_TypeDef* UARTx);
extern void UART_RxByteCntClear_B(UART_TypeDef* UARTx);

extern u32 UART_RxByteCntGet_A(UART_TypeDef* UARTx);
extern u32 UART_RxByteCntGet_B(UART_TypeDef* UARTx);

extern void UART_BreakCtl_A(UART_TypeDef* UARTx, u32 NewState);
extern void UART_BreakCtl_B(UART_TypeDef* UARTx, u32 NewState);

extern u32 UART_ClearRxFifo_A(UART_TypeDef* UARTx);
extern u32 UART_ClearRxFifo_B(UART_TypeDef* UARTx);

extern void UART_Init_A(UART_TypeDef* UARTx, UART_InitTypeDef *UART_InitStruct);
extern void UART_Init_B(UART_TypeDef* UARTx, UART_InitTypeDef *UART_InitStruct);

extern void UART_ClearTxFifo_A(UART_TypeDef* UARTx);
extern void UART_ClearTxFifo_B(UART_TypeDef* UARTx);

extern void UART_INTConfig_A(UART_TypeDef* UARTx, u32 UART_IT, u32 newState);
extern void UART_INTConfig_B(UART_TypeDef* UARTx, u32 UART_IT, u32 newState);

extern u32 UART_IntStatus_A(UART_TypeDef* UARTx);
extern u32 UART_IntStatus_B(UART_TypeDef* UARTx);

extern u32 UART_ModemStatusGet_A(UART_TypeDef* UARTx);
extern u32 UART_ModemStatusGet_B(UART_TypeDef* UARTx);

extern u32 UART_LineStatusGet_A(UART_TypeDef* UARTx);
extern u32 UART_LineStatusGet_B(UART_TypeDef* UARTx);

extern void UART_WaitBusy_A(UART_TypeDef* UARTx, u32 PollTimes);
extern void UART_WaitBusy_B(UART_TypeDef* UARTx, u32 PollTimes);

extern void UART_PinMuxInit_A(u8 UartIndex, u8 PinmuxSelect);
extern void UART_PinMuxInit_B(u8 UartIndex, u8 PinmuxSelect);

extern void UART_PinMuxDeinit_A(u8 UartIndex, u8 PinmuxSelect);
extern void UART_PinMuxDeinit_B(u8 UartIndex, u8 PinmuxSelect);

extern void UART_TXDMAConfig_A(UART_TypeDef* UARTx, u32 TxDmaBurstSize);
extern void UART_TXDMAConfig_B(UART_TypeDef* UARTx, u32 TxDmaBurstSize);

extern void UART_RXDMAConfig_A(UART_TypeDef* UARTx, u32 RxDmaBurstSize);
extern void UART_RXDMAConfig_B(UART_TypeDef* UARTx, u32 RxDmaBurstSize);

extern void UART_TXDMACmd_A(UART_TypeDef* UARTx, u32 NewState);
extern void UART_TXDMACmd_B(UART_TypeDef* UARTx, u32 NewState);

extern void UART_RXDMACmd_A(UART_TypeDef* UARTx, u32 NewState);
extern void UART_RXDMACmd_B(UART_TypeDef* UARTx, u32 NewState);

extern BOOL UART_TXGDMA_Init_A(u8 UartIndex, GDMA_InitTypeDef *GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pTxBuf, int TxCount);
extern BOOL UART_TXGDMA_Init_B(u8 UartIndex, GDMA_InitTypeDef *GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pTxBuf, int TxCount);

extern BOOL UART_RXGDMA_Init_A(u8 UartIndex, GDMA_InitTypeDef *GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pRxBuf, int RxCount);
extern BOOL UART_RXGDMA_Init_B(u8 UartIndex, GDMA_InitTypeDef *GDMA_InitStruct, void *CallbackData, IRQ_FUN CallbackFunc, u8 *pRxBuf, int RxCount);

extern void UART_LPRxStructInit_A(LPUART_InitTypeDef* LPUART_InitStruct);
extern void UART_LPRxStructInit_B(LPUART_InitTypeDef* LPUART_InitStruct);

extern void UART_LPRxInit_A(UART_TypeDef* UARTx, LPUART_InitTypeDef *LPUART_InitStruct);
extern void UART_LPRxInit_B(UART_TypeDef* UARTx, LPUART_InitTypeDef *LPUART_InitStruct);

extern void UART_LPRxBaudSet_A(UART_TypeDef* UARTx, u32 BaudRate, u32 RxIPClockHz);
extern void UART_LPRxBaudSet_B(UART_TypeDef* UARTx, u32 BaudRate, u32 RxIPClockHz);

extern void UART_LPRxMonitorCmd_A(UART_TypeDef* UARTx, u32 NewState);
extern void UART_LPRxMonitorCmd_B(UART_TypeDef* UARTx, u32 NewState);

extern void UART_LPRxpathSet_A(UART_TypeDef* UARTx, u32 LPRxpath);
extern void UART_LPRxpathSet_B(UART_TypeDef* UARTx, u32 LPRxpath);

extern void UART_LPRxIPClockSet_A(UART_TypeDef* UARTx, u32 RxIPClock);
extern void UART_LPRxIPClockSet_B(UART_TypeDef* UARTx, u32 RxIPClock);

extern void UART_LPRxCmd_A(UART_TypeDef* UARTx, u32 NewState);
extern void UART_LPRxCmd_B(UART_TypeDef* UARTx, u32 NewState);

extern u32 UART_LPRxMonBaudCtrlRegGet_A(UART_TypeDef* UARTx);
extern u32 UART_LPRxMonBaudCtrlRegGet_B(UART_TypeDef* UARTx);

extern u32 UART_LPRxMonitorSatusGet_A(UART_TypeDef* UARTx);
extern u32 UART_LPRxMonitorSatusGet_B(UART_TypeDef* UARTx);

extern void UART_IrDAStructInit_A(IrDA_InitTypeDef * IrDA_InitStruct);
extern void UART_IrDAStructInit_B(IrDA_InitTypeDef * IrDA_InitStruct);

extern void UART_IrDAInit_A(UART_TypeDef* UARTx, IrDA_InitTypeDef * IrDA_InitStruct);
extern void UART_IrDAInit_B(UART_TypeDef* UARTx, IrDA_InitTypeDef * IrDA_InitStruct);

extern void UART_IrDACmd_A(UART_TypeDef* UARTx, u32 NewState);
extern void UART_IrDACmd_B(UART_TypeDef* UARTx, u32 NewState);

extern VOID INT_SysOn_A(VOID);
extern VOID INT_SysOn_B(VOID);

extern VOID INT_Wdg_A(VOID);
extern VOID INT_Wdg_B(VOID);

extern VOID INT_Timer0_A(VOID);
extern VOID INT_Timer0_B(VOID);

extern VOID INT_Timer1_A(VOID);
extern VOID INT_Timer1_B(VOID);

extern VOID INT_Timer2_A(VOID);
extern VOID INT_Timer2_B(VOID);

extern VOID INT_Timer3_A(VOID);
extern VOID INT_Timer3_B(VOID);

extern VOID INT_SPI0_A(VOID);
extern VOID INT_SPI0_B(VOID);

extern VOID INT_GPIO_A(VOID);
extern VOID INT_GPIO_B(VOID);

extern VOID INT_Uart0_A(VOID);
extern VOID INT_Uart0_B(VOID);

extern VOID INT_SPIFlash_A(VOID);
extern VOID INT_SPIFlash_B(VOID);

extern VOID INT_Uart1_A(VOID);
extern VOID INT_Uart1_B(VOID);

extern VOID INT_Timer4_A(VOID);
extern VOID INT_Timer4_B(VOID);

extern VOID INT_I2S0_A(VOID);
extern VOID INT_I2S0_B(VOID);

extern VOID INT_Timer5_A(VOID);
extern VOID INT_Timer5_B(VOID);

extern VOID INT_WlDma_A(VOID);
extern VOID INT_WlDma_B(VOID);

extern VOID INT_WlProtocol_A(VOID);
extern VOID INT_WlProtocol_B(VOID);

extern VOID INT_IPSEC_A(VOID);
extern VOID INT_IPSEC_B(VOID);

extern VOID INT_SPI1_A(VOID);
extern VOID INT_SPI1_B(VOID);

extern VOID INT_Peripheral_A(VOID);
extern VOID INT_Peripheral_B(VOID);

extern VOID INT_Gdma0Ch0_A(VOID);
extern VOID INT_Gdma0Ch0_B(VOID);

extern VOID INT_Gdma0Ch1_A(VOID);
extern VOID INT_Gdma0Ch1_B(VOID);

extern VOID INT_Gdma0Ch2_A(VOID);
extern VOID INT_Gdma0Ch2_B(VOID);

extern VOID INT_Gdma0Ch3_A(VOID);
extern VOID INT_Gdma0Ch3_B(VOID);

extern VOID INT_Gdma0Ch4_A(VOID);
extern VOID INT_Gdma0Ch4_B(VOID);

extern VOID INT_Gdma0Ch5_A(VOID);
extern VOID INT_Gdma0Ch5_B(VOID);

extern VOID INT_I2C0_A(VOID);
extern VOID INT_I2C0_B(VOID);

extern VOID INT_I2C1_A(VOID);
extern VOID INT_I2C1_B(VOID);

extern VOID INT_Uartlog_A(VOID);
extern VOID INT_Uartlog_B(VOID);

extern VOID INT_ADC_A(VOID);
extern VOID INT_ADC_B(VOID);

extern  VOID INT_RDP_A(VOID);
extern  VOID INT_RDP_B(VOID);

extern VOID INT_RTC_A(VOID);
extern VOID INT_RTC_B(VOID);

extern VOID INT_Gdma1Ch0_A(VOID);
extern VOID INT_Gdma1Ch0_B(VOID);

extern VOID INT_Gdma1Ch1_A(VOID);
extern VOID INT_Gdma1Ch1_B(VOID);

extern VOID INT_Gdma1Ch2_A(VOID);
extern VOID INT_Gdma1Ch2_B(VOID);

extern VOID INT_Gdma1Ch3_A(VOID);
extern VOID INT_Gdma1Ch3_B(VOID);

extern VOID INT_Gdma1Ch4_A(VOID);
extern VOID INT_Gdma1Ch4_B(VOID);

extern VOID INT_Gdma1Ch5_A(VOID);
extern VOID INT_Gdma1Ch5_B(VOID);

extern VOID INT_USB_A(VOID);
extern VOID INT_USB_B(VOID);

extern VOID INT_RXI300_A(VOID);
extern VOID INT_RXI300_B(VOID);

extern VOID INT_USB_SIE_A(VOID);
extern VOID INT_USB_SIE_B(VOID);

extern VOID INT_SdioD_A(VOID);
extern VOID INT_SdioD_B(VOID);

extern VOID INT_NMI_A(VOID);
extern VOID INT_NMI_B(VOID);

extern VOID INT_HardFault_A(u32 HardDefaultArg);
extern VOID INT_HardFault_B(u32 HardDefaultArg);

extern VOID INT_MemManage_A(VOID);
extern VOID INT_MemManage_B(VOID);

extern VOID INT_BusFault_A(VOID);
extern VOID INT_BusFault_B(VOID);

extern VOID INT_UsageFault_A(VOID);
extern VOID INT_UsageFault_B(VOID);

extern void VECTOR_TableInit_A(u32 StackP);
extern void VECTOR_TableInit_B(u32 StackP);

extern void VECTOR_TableInitForOS_A(void *PortSVC, void *PortPendSVH, void *PortSysTick);
extern void VECTOR_TableInitForOS_B(void *PortSVC, void *PortPendSVH, void *PortSysTick);

extern BOOL VECTOR_IrqRegister_A(IRQ_FUN IrqFun, IRQn_Type IrqNum, u32 Data, u32 Priority);
extern BOOL VECTOR_IrqRegister_B(IRQ_FUN IrqFun, IRQn_Type IrqNum, u32 Data, u32 Priority);

extern BOOL VECTOR_IrqUnRegister_A(IRQn_Type   IrqNum);
extern BOOL VECTOR_IrqUnRegister_B(IRQn_Type   IrqNum);

extern void VECTOR_IrqEn_A(IRQn_Type   IrqNum, u32 Priority);
extern void VECTOR_IrqEn_B(IRQn_Type   IrqNum, u32 Priority);

extern void VECTOR_IrqDis_A(IRQn_Type   IrqNum);
extern void VECTOR_IrqDis_B(IRQn_Type   IrqNum);

extern void WDG_Scalar_A(u32 Period, u32 *pCountProcess, u32 *pDivFacProcess);
extern void WDG_Scalar_B(u32 Period, u32 *pCountProcess, u32 *pDivFacProcess);

extern void WDG_Init_A(WDG_InitTypeDef *WDG_InitStruct);
extern void WDG_Init_B(WDG_InitTypeDef *WDG_InitStruct);

extern void WDG_IrqClear_A(void);
extern void WDG_IrqClear_B(void);

extern void WDG_IrqInit_A(void *handler, u32 Id);
extern void WDG_IrqInit_B(void *handler, u32 Id);

extern void WDG_Cmd_A(u32 NewState);
extern void WDG_Cmd_B(u32 NewState);

extern void WDG_Refresh_A(void);
extern void WDG_Refresh_B(void);

extern char *_strncpy_A(char *dest, const char *src, size_t count);
extern char *_strncpy_B(char *dest, const char *src, size_t count);

extern char *_strcpy_A(char *dest, const char *src);
extern char *_strcpy_B(char *dest, const char *src);

extern VOID prvStrCpy_A(IN  u8  *pDES, IN  const u8  *pSRC);
extern VOID prvStrCpy_B(IN  u8  *pDES, IN  const u8  *pSRC);

extern SIZE_T _strlen_A(const char *s);
extern SIZE_T _strlen_B(const char *s);

extern size_t _strnlen_A(const char *s, size_t count);
extern size_t _strnlen_B(const char *s, size_t count);

extern u32 prvStrLen_A(IN  const   u8  *pSRC);
extern u32 prvStrLen_B(IN  const   u8  *pSRC);

extern int _strcmp_A(const char *cs, const char *ct);
extern int _strcmp_B(const char *cs, const char *ct);

extern int _strncmp_A(const char *cs, const char *ct, size_t count);
extern int _strncmp_B(const char *cs, const char *ct, size_t count);

extern u8 prvStrCmp_A(IN  const   u8  *string1, IN  const   u8  *string2);
extern u8 prvStrCmp_B(IN  const   u8  *string1, IN  const   u8  *string2);

extern u8* StrUpr_A(IN  u8  *string);
extern u8* StrUpr_B(IN  u8  *string);

extern int prvAtoi_A(const char * s);
extern int prvAtoi_B(const char * s);

extern char* prvStrtok_A(char *str, const char* delim);
extern char* prvStrtok_B(char *str, const char* delim);

extern char* prvStrStr_A(const char *string, const char *substring);
extern char* prvStrStr_B(const char *string, const char *substring);

extern char *_strsep_A(char **s, const char *ct);
extern char *_strsep_B(char **s, const char *ct);

extern char *skip_spaces_A(const char *str);
extern char *skip_spaces_B(const char *str);

extern int skip_atoi_A(const char **s);
extern int skip_atoi_B(const char **s);

extern const char *_parse_integer_fixup_radix_A(const char *s, unsigned int *base);
extern const char *_parse_integer_fixup_radix_B(const char *s, unsigned int *base);

extern unsigned int _parse_integer_A(const char *s, unsigned int base, unsigned long long *p);
extern unsigned int _parse_integer_B(const char *s, unsigned int base, unsigned long long *p);

extern unsigned long long simple_strtoull_A(const char *cp, char **endp, unsigned int base);
extern unsigned long long simple_strtoull_B(const char *cp, char **endp, unsigned int base);

extern long long simple_strtoll_A(const char *cp, char **endp, unsigned int base);
extern long long simple_strtoll_B(const char *cp, char **endp, unsigned int base);

extern unsigned long simple_strtoul_A(const char *cp, char **endp, unsigned int base);
extern unsigned long simple_strtoul_B(const char *cp, char **endp, unsigned int base);

extern long simple_strtol_A(const char *cp, char **endp, unsigned int base);
extern long simple_strtol_B(const char *cp, char **endp, unsigned int base);

extern int _vsscanf_A(const char *buf, const char *fmt, va_list args);
extern int _vsscanf_B(const char *buf, const char *fmt, va_list args);

extern u64 div_u64_A(u64 dividend, u32 divisor);
extern u64 div_u64_B(u64 dividend, u32 divisor);

extern s64 div_s64_A(s64 dividend, s32 divisor);
extern s64 div_s64_B(s64 dividend, s32 divisor);

extern u64 div_u64_rem_A(u64 dividend, u32 divisor, u32 *remainder);
extern u64 div_u64_rem_B(u64 dividend, u32 divisor, u32 *remainder);

extern s64 div_s64_rem_A(s64 dividend, s32 divisor, s32 *remainder);
extern s64 div_s64_rem_B(s64 dividend, s32 divisor, s32 *remainder);

extern char *_strpbrk_A(const char *cs, const char *ct);
extern char *_strpbrk_B(const char *cs, const char *ct);

extern char *_strchr_A(const char *s, int c);
extern char *_strchr_B(const char *s, int c);

extern char COMMPORT_GET_T_A(char *pch, u32 timeout);
extern char COMMPORT_GET_T_B(char *pch, u32 timeout);

extern void COMMPORT_CLEAN_RX_A(VOID);
extern void COMMPORT_CLEAN_RX_B(VOID);

extern VOID xModemDebugInit_A(VOID);
extern VOID xModemDebugInit_B(VOID);

extern VOID xModemDebug_A(u32 code, u32 need_delay);
extern VOID xModemDebug_B(u32 code, u32 need_delay);

extern u32 xModemInquiry_A(u8 code);
extern u32 xModemInquiry_B(u8 code);

extern u32 xModemGetFirst_A(XMODEM_CTRL *pXMCtrl);
extern u32 xModemGetFirst_B(XMODEM_CTRL *pXMCtrl);

extern u32 xModemGetOthers_A(XMODEM_CTRL *pXMCtrl);
extern u32 xModemGetOthers_B(XMODEM_CTRL *pXMCtrl);

extern u32 xModemRxFrame_A(XMODEM_CTRL *pXMCtrl);
extern u32 xModemRxFrame_B(XMODEM_CTRL *pXMCtrl);

extern VOID xModemHandshake_A(VOID);
extern VOID xModemHandshake_B(VOID);

extern VOID xModemRxBuffer_A(u32 baud_rate);
extern VOID xModemRxBuffer_B(u32 baud_rate);

extern VOID xmodem_log_close_A(void);
extern VOID xmodem_log_close_B(void);

extern void xmodem_log_open_A(void);
extern void xmodem_log_open_B(void);

extern void xmodem_uart_init_A(u8 uart_idx, u8 pin_mux, u32 baud_rate);
extern void xmodem_uart_init_B(u8 uart_idx, u8 pin_mux, u32 baud_rate);

extern void xmodem_uart_deinit_A(void);
extern void xmodem_uart_deinit_B(void);

extern void xmodem_uart_port_init_A(u8 uart_idx, u8 pin_mux, u32 baud_rate);
extern void xmodem_uart_port_init_B(u8 uart_idx, u8 pin_mux, u32 baud_rate);

extern void xmodem_uart_port_deinit_A(u8 uart_idx);
extern void xmodem_uart_port_deinit_B(u8 uart_idx);

extern char xmodem_uart_readable_A(void);
extern char xmodem_uart_readable_B(void);

extern char xmodem_uart_writable_A(void);
extern char xmodem_uart_writable_B(void);

extern char xmodem_uart_getc_A(void);
extern char xmodem_uart_getc_B(void);

extern void xmodem_uart_putc_A(char c);
extern void xmodem_uart_putc_B(char c);

extern void xmodem_uart_putdata_A(u8* buf, u32 cnt);
extern void xmodem_uart_putdata_B(u8* buf, u32 cnt);

extern int aes_set_key_A( aes_context *ctx, u8 *key, int nbits );
extern int aes_set_key_B( aes_context *ctx, u8 *key, int nbits );

extern void aes_encrypt_A( aes_context *ctx, u8 input[16], u8 output[16] );
extern void aes_encrypt_B( aes_context *ctx, u8 input[16], u8 output[16] );

extern void aes_decrypt_A( aes_context *ctx, u8 input[16], u8 output[16]);
extern void aes_decrypt_B( aes_context *ctx, u8 input[16], u8 output[16]);

extern void AES_WRAP_A(
	unsigned char * plain, int plain_len,
	unsigned char * iv,	int iv_len,
	unsigned char * kek,	int kek_len,
	unsigned char *cipher, unsigned short *cipher_len);
extern void AES_WRAP_B(
	unsigned char * plain, int plain_len,
	unsigned char * iv,	int iv_len,
	unsigned char * kek,	int kek_len,
	unsigned char *cipher, unsigned short *cipher_len);

extern void AES_UnWRAP_A(
	unsigned char * cipher, int cipher_len,
	unsigned char * kek,	int kek_len,
	unsigned char * plain);
extern void AES_UnWRAP_B(
	unsigned char * cipher, int cipher_len,
	unsigned char * kek,	int kek_len,
	unsigned char * plain);

extern u32 crc32_get_A(u8 *buf, sint len);
extern u32 crc32_get_B(u8 *buf, sint len);

extern u32 arc4_byte_A(struct arc4context	*parc4ctx);
extern u32 arc4_byte_B(struct arc4context	*parc4ctx);

extern void rt_arc4_init_A(struct arc4context *parc4ctx, u8 * key,u32 key_len);
extern void rt_arc4_init_B(struct arc4context *parc4ctx, u8 * key,u32 key_len);

extern void rt_arc4_crypt_A(struct arc4context	*parc4ctx, u8 * dest, u8 * src, u32 len);
extern void rt_arc4_crypt_B(struct arc4context	*parc4ctx, u8 * dest, u8 * src, u32 len);

extern void rt_md5_init_A (md5_ctx *context);
extern void rt_md5_init_B (md5_ctx *context);

extern void rt_md5_append_A(md5_ctx *context, u8 *input, u32 inputLen);
extern void rt_md5_append_B(md5_ctx *context, u8 *input, u32 inputLen);

extern void rt_md5_final_A(u8 digest[16], md5_ctx *context);
extern void rt_md5_final_B(u8 digest[16], md5_ctx *context);

extern void rt_md5_hmac_A(unsigned char *text, int text_len, unsigned char *key,
	int key_len, void * digest);
extern void rt_md5_hmac_B(unsigned char *text, int text_len, unsigned char *key,
	int key_len, void * digest);

extern void RC4_A(RC4_KEY *key, unsigned long len, const unsigned char *indata,
	     unsigned char *outdata);
extern void RC4_B(RC4_KEY *key, unsigned long len, const unsigned char *indata,
	     unsigned char *outdata);

extern void RC4_set_key_A(RC4_KEY *key, int len, const unsigned char *data);
extern void RC4_set_key_B(RC4_KEY *key, int len, const unsigned char *data);

extern void ROM_WIFI_ReadPowerValue_A(
	PTxPowerInfo24G pwrInfo24G,
	u8 * PROMContent,
	BOOLEAN	 AutoLoadFail	);
extern void ROM_WIFI_ReadPowerValue_B(
	PTxPowerInfo24G pwrInfo24G,
	u8 * PROMContent,
	BOOLEAN	 AutoLoadFail	);

extern void ROM_WIFI_EfuseParseTxPowerInfo_A(
	u8* PROMContent,
	BOOLEAN	 AutoLoadFail,
	u8 Index24G_CCK_Base[MAX_RF_PATH][CHANNEL_MAX_NUMBER],
	u8 Index24G_BW40_Base[MAX_RF_PATH][CHANNEL_MAX_NUMBER],
	s8 OFDM_24G_Diff[MAX_RF_PATH][MAX_TX_COUNT],
	s8 BW20_24G_Diff[MAX_RF_PATH][MAX_TX_COUNT],
	u8 *EEPROMRegulatory);
extern void ROM_WIFI_EfuseParseTxPowerInfo_B(
	u8* PROMContent,
	BOOLEAN	 AutoLoadFail,
	u8 Index24G_CCK_Base[MAX_RF_PATH][CHANNEL_MAX_NUMBER],
	u8 Index24G_BW40_Base[MAX_RF_PATH][CHANNEL_MAX_NUMBER],
	s8 OFDM_24G_Diff[MAX_RF_PATH][MAX_TX_COUNT],
	s8 BW20_24G_Diff[MAX_RF_PATH][MAX_TX_COUNT],
	u8 *EEPROMRegulatory);

extern void ROM_WIFI_8051Reset_A(void);
extern void ROM_WIFI_8051Reset_B(void);

extern void ROM_WIFI_FWDownloadEnable_A(BOOLEAN enable); 
extern void ROM_WIFI_FWDownloadEnable_B(BOOLEAN enable);

extern void ROM_WIFI_BlockWrite_A(void *buffer, u32 buffSize); 
extern void ROM_WIFI_BlockWrite_B(void *buffer, u32 buffSize);

extern void ROM_WIFI_PageWrite_A(u32 page, void *buffer, u32 size); 
extern void ROM_WIFI_PageWrite_B(u32 page, void *buffer, u32 size);

extern void ROM_WIFI_FillDummy_A(u8 *pFwBuf, u32 *pFwLen); 
extern void ROM_WIFI_FillDummy_B(u8 *pFwBuf, u32 *pFwLen);

extern int ROM_WIFI_WriteFW_A(void *buffer, u32 size); 
extern int ROM_WIFI_WriteFW_B(void *buffer, u32 size);

extern s32 ROM_WIFI_FWFreeToGo_A(u8 debug); 
extern s32 ROM_WIFI_FWFreeToGo_B(u8 debug);

extern s32 ROM_WIFI_InitLLTTable_A(VOID); 
extern s32 ROM_WIFI_InitLLTTable_B(VOID);

extern BOOLEAN ROM_WIFI_GetChnlGroup_A(u8 Channel,	u8 *pGroup); 
extern BOOLEAN ROM_WIFI_GetChnlGroup_B(u8 Channel,	u8 *pGroup);

extern u8 ROM_WIFI_BWMapping_A(u8 bwmode, enum channel_width CurrentChannelBW); 
extern u8 ROM_WIFI_BWMapping_B(u8 bwmode, enum channel_width CurrentChannelBW);

extern u8 ROM_WIFI_SCMapping_A(u8 bwmode, enum channel_width CurrentChannelBW, u8 nCur40MhzPrimeSC, u8 nCur80MhzPrimeSC); 
extern u8 ROM_WIFI_SCMapping_B(u8 bwmode, enum channel_width CurrentChannelBW, u8 nCur40MhzPrimeSC, u8 nCur80MhzPrimeSC);

extern u8 ROM_WIFI_FillTxdescSectype_A(u8 encrypt, u8 bswenc); 
extern u8 ROM_WIFI_FillTxdescSectype_B(u8 encrypt, u8 bswenc);

extern void ROM_WIFI_FillFakeTxdesc_A(
	u32 dot11PrivacyAlgrthm,
	u8* pDesc,
	u32 BufferLen,
	u8 IsPsPoll,
	u8 IsBTQosNull,
	u8 bDataFrame); 
extern void ROM_WIFI_FillFakeTxdesc_B(
	u32 dot11PrivacyAlgrthm,
	u8* pDesc,
	u32 BufferLen,
	u8 IsPsPoll,
	u8 IsBTQosNull,
	u8 bDataFrame);

extern VOID ROM_WIFI_32K_Cmd_A(u32 NewStatus, u8 AckEnable); 
extern VOID ROM_WIFI_32K_Cmd_B(u32 NewStatus, u8 AckEnable);

extern VOID ROM_WIFI_DISCONNECT_A(u8 iface_type, u8 variable, u8 *val); 
extern VOID ROM_WIFI_DISCONNECT_B(u8 iface_type, u8 variable, u8 *val);

extern VOID ROM_WIFI_SET_TSF_A(int sta_buddy_fwstate_ap, u8 iface_type, u8 variable, u8* val, u32 *tsf); 
extern VOID ROM_WIFI_SET_TSF_B(int sta_buddy_fwstate_ap, u8 iface_type, u8 variable, u8* val, u32 *tsf);

extern VOID ROM_WIFI_BCN_FUNC_A(u8 iface_type, u8 variable, u8 *val); 
extern VOID ROM_WIFI_BCN_FUNC_B(u8 iface_type, u8 variable, u8 *val);

extern VOID ROM_WIFI_BSSID_SET_A(u8 iface_type, u8 variable, u8 *val); 
extern VOID ROM_WIFI_BSSID_SET_B(u8 iface_type, u8 variable, u8 *val);

extern VOID ROM_WIFI_MACADDR_SET_A(u8 iface_type, u8 variable, u8 *val); 
extern VOID ROM_WIFI_MACADDR_SET_B(u8 iface_type, u8 variable, u8 *val);

extern VOID ROM_WIFI_EnableInterrupt_A(u32 *IntrMask); 
extern VOID ROM_WIFI_EnableInterrupt_B(u32 *IntrMask);

extern VOID ROM_WIFI_DisableInterrupt_A(PADAPTER padapter); 
extern VOID ROM_WIFI_DisableInterrupt_B(PADAPTER padapter);

extern VOID ROM_WIFI_RESUME_TxBeacon_A(u8* RegFwHwTxQCtrl, u8* RegReg542); 
extern VOID ROM_WIFI_RESUME_TxBeacon_B(u8* RegFwHwTxQCtrl, u8* RegReg542);

extern VOID ROM_WIFI_STOP_TXBeacon_A(u8* RegFwHwTxQCtrl, u8* RegReg542); 
extern VOID ROM_WIFI_STOP_TXBeacon_B(u8* RegFwHwTxQCtrl, u8* RegReg542);

extern VOID ROM_WIFI_BCN_Interval_A(u16 bcn_interval); 
extern VOID ROM_WIFI_BCN_Interval_B(u16 bcn_interval);

extern VOID ROM_WIFI_BCN_FUNC_Enable_A(VOID); 
extern VOID ROM_WIFI_BCN_FUNC_Enable_B(VOID);

extern void ROM_WIFI_INIT_BeaconParameters_A(u8* RegFwHwTxQCtrl, u8* RegReg542, sint BeSta); 
extern void ROM_WIFI_INIT_BeaconParameters_B(u8* RegFwHwTxQCtrl, u8* RegReg542, sint BeSta);

extern VOID ROM_WIFI_MEDIA_STATUS1_A(u8* val); 
extern VOID ROM_WIFI_MEDIA_STATUS1_B(u8* val);

extern VOID ROM_WIFI_MEDIA_STATUS_A(u8* val); 
extern VOID ROM_WIFI_MEDIA_STATUS_B(u8* val);

extern void ROM_WIFI_SetBrateCfg_A(u8 *mBratesOS, u16 *pBrateCfg); 
extern void ROM_WIFI_SetBrateCfg_B(u8 *mBratesOS, u16 *pBrateCfg);

extern VOID ROM_WIFI_BASIC_RATE_A(u8* pval, u16 *BasicRateSet); 
extern VOID ROM_WIFI_BASIC_RATE_B(u8* pval, u16 *BasicRateSet);

extern VOID ROM_WIFI_CHECK_BSSID_A(u8* val); 
extern VOID ROM_WIFI_CHECK_BSSID_B(u8* val);

extern VOID ROM_WIFI_RESP_SIFS_A(u8 *val);
extern VOID ROM_WIFI_RESP_SIFS_B(u8 *val);

extern VOID ROM_WIFI_CAM_WRITE_A(u32 *cam_val);
extern VOID ROM_WIFI_CAM_WRITE_B(u32 *cam_val);

extern VOID ROM_WIFI_ACM_CTRL_A(u8 ctrl);
extern VOID ROM_WIFI_ACM_CTRL_B(u8 ctrl);

extern VOID ROM_WIFI_FIFO_CLEARN_UP_A(u16 *nqos_ssn, u8 bkeepfwalive);
extern VOID ROM_WIFI_FIFO_CLEARN_UP_B(u16 *nqos_ssn, u8 bkeepfwalive);

extern VOID ROM_WIFI_CHECK_TXBUF_A(VOID);
extern VOID ROM_WIFI_CHECK_TXBUF_B(VOID);

extern VOID ROM_WIFI_BCN_VALID_A(u8 iface_type);
extern VOID ROM_WIFI_BCN_VALID_B(u8 iface_type);

extern VOID ROM_WIFI_PROMISC_Cmd_A(rtw_rcr_level_t type, u32 *promisc_bk_rcr, u16 *promisc_bk_rxfltmap2);
extern VOID ROM_WIFI_PROMISC_Cmd_B(rtw_rcr_level_t type, u32 *promisc_bk_rcr, u16 *promisc_bk_rxfltmap2);

extern void ROM_WIFI_SetOpmodeAP_A(u8 iface_type, u8 buddy_fwstate_null, u8 FPGA_TwoMac);
extern void ROM_WIFI_SetOpmodeAP_B(u8 iface_type, u8 buddy_fwstate_null, u8 FPGA_TwoMac);

extern void ROM_WIFI_ReadChipVersion_A(HAL_VERSION *ChipVersion);
extern void ROM_WIFI_ReadChipVersion_B(HAL_VERSION *ChipVersion);

extern void ROM_WIFI_DumpChipInfo_A(HAL_VERSION ChipVersion);
extern void ROM_WIFI_DumpChipInfo_B(HAL_VERSION ChipVersion);

extern void ROM_WIFI_InitTxBufferBoundary_A(
	u8 txpktbuf_bndy,
	BOOLEAN bConcurrent);
extern void ROM_WIFI_InitTxBufferBoundary_B(
	u8 txpktbuf_bndy,
	BOOLEAN bConcurrent);

extern void ROM_WIFI_InitNormalChipRegPriority_A(
	u16 beQ,
	u16 bkQ,
	u16 viQ,
	u16 voQ,
	u16 mgtQ,
	u16 hiQ);
extern void ROM_WIFI_InitNormalChipRegPriority_B(
	u16 beQ,
	u16 bkQ,
	u16 viQ,
	u16 voQ,
	u16 mgtQ,
	u16 hiQ);

extern void ROM_WIFI_InitPageBoundary_A(u16 rxff_bndy);
extern void ROM_WIFI_InitPageBoundary_B(u16 rxff_bndy);

extern void ROM_WIFI_InitTransferPageSize_A(u8 PageSize);
extern void ROM_WIFI_InitTransferPageSize_B(u8 PageSize);

extern void ROM_WIFI_InitDriverInfoSize_A(u8 drvInfoSize);
extern void ROM_WIFI_InitDriverInfoSize_B(u8 drvInfoSize);

extern void ROM_WIFI_InitNetworkType_A(u32 NetType);
extern void ROM_WIFI_InitNetworkType_B(u32 NetType);

extern void ROM_WIFI_InitRCR_A(u32 ReceiveConfig, u16 RXFLTMAP2, u16 RXFLTMAP1, u16 RXFLTMAP0);
extern void ROM_WIFI_InitRCR_B(u32 ReceiveConfig, u16 RXFLTMAP2, u16 RXFLTMAP1, u16 RXFLTMAP0);

extern void ROM_WIFI_InitAdaptiveCtrl_A(u32 RATE_RRSR, u16 SIFS, u16 RetryLimit);
extern void ROM_WIFI_InitAdaptiveCtrl_B(u32 RATE_RRSR, u16 SIFS, u16 RetryLimit);

extern void ROM_WIFI_InitSIFS_A(u16 SPEC_SIFS, u16 MAC_SPEC_SIFS, u16 SIFS_CTX, u16 SIFS_TRX);
extern void ROM_WIFI_InitSIFS_B(u16 SPEC_SIFS, u16 MAC_SPEC_SIFS, u16 SIFS_CTX, u16 SIFS_TRX);

extern void ROM_WIFI_InitEDCA_A(u32 EDCA_BE, u32 EDCA_BK, u32 EDCA_VI, u32 EDCA_VO);
extern void ROM_WIFI_InitEDCA_B(u32 EDCA_BE, u32 EDCA_BK, u32 EDCA_VI, u32 EDCA_VO);

extern void ROM_WIFI_InitRateFallback_A(u32 DARFRC0, u32 DARFRC1, u32 RARFRC, u32 RARFRC1);
extern void ROM_WIFI_InitRateFallback_B(u32 DARFRC0, u32 DARFRC1, u32 RARFRC, u32 RARFRC1);

extern void ROM_WIFI_InitRetryFunction_A(u8 TXQ_CTRL, u8 ACK_timeout);
extern void ROM_WIFI_InitRetryFunction_B(u8 TXQ_CTRL, u8 ACK_timeout);

extern void ROM_WIFI_InitOperationMode_A(u8 regBwOpMode, u8 AMPDU_MinSpaceCfg);
extern void ROM_WIFI_InitOperationMode_B(u8 regBwOpMode, u8 AMPDU_MinSpaceCfg);

extern void ROM_WIFI_InitBurstPktLen_A(u8 PKT_LIMIT);
extern void ROM_WIFI_InitBurstPktLen_B(u8 PKT_LIMIT);

extern u32 phy_CalculateBitShift_A(u32 BitMask);
extern u32 phy_CalculateBitShift_B(u32 BitMask);

extern VOID PHY_SetBBReg_8711B_A(
	IN	PADAPTER	Adapter,
	IN	u32		RegAddr,
	IN	u32		BitMask,
	IN	u32		Data	);
extern VOID PHY_SetBBReg_8711B_B(
	IN	PADAPTER	Adapter,
	IN	u32		RegAddr,
	IN	u32		BitMask,
	IN	u32		Data	);

extern u32 PHY_QueryBBReg_8711B_A(
	IN	PADAPTER	Adapter,
	IN	u32		RegAddr,
	IN	u32		BitMask);
extern u32 PHY_QueryBBReg_8711B_B(
	IN	PADAPTER	Adapter,
	IN	u32		RegAddr,
	IN	u32		BitMask);

extern u1Byte ROM_odm_QueryRxPwrPercentage_A(IN s1Byte AntPower);
extern u1Byte ROM_odm_QueryRxPwrPercentage_B(IN s1Byte AntPower);

extern u1Byte ROM_odm_EVMdbToPercentage_A(IN s1Byte Value);
extern u1Byte ROM_odm_EVMdbToPercentage_B(IN s1Byte Value);

extern s4Byte ROM_odm_SignalScaleMapping_8711B_A(
    IN u1Byte SupportInterface,
    IN s4Byte CurrSig);
extern s4Byte ROM_odm_SignalScaleMapping_8711B_B(
    IN u1Byte SupportInterface,
    IN s4Byte CurrSig);

extern VOID ROM_odm_FalseAlarmCounterStatistics_A(IN PVOID pDM_VOID);
extern VOID ROM_odm_FalseAlarmCounterStatistics_B(IN PVOID pDM_VOID);

extern VOID ROM_odm_SetEDCCAThreshold_A(
    IN  PVOID   pDM_VOID,
    IN  s1Byte  H2L,
    IN  s1Byte  L2H);
extern VOID ROM_odm_SetEDCCAThreshold_B(
    IN  PVOID   pDM_VOID,
    IN  s1Byte  H2L,
    IN  s1Byte  L2H);

extern VOID ROM_odm_SetTRxMux_A(
    IN  PVOID               pDM_VOID,
    IN  ODM_Trx_MUX_Type    txMode,
    IN  ODM_Trx_MUX_Type    rxMode);
extern VOID ROM_odm_SetTRxMux_B(
    IN  PVOID               pDM_VOID,
    IN  ODM_Trx_MUX_Type    txMode,
    IN  ODM_Trx_MUX_Type    rxMode);

extern VOID ROM_odm_SetCrystalCap_A(
    IN      PVOID                   pDM_VOID,
    IN      u1Byte                  Crystal_Cap);
extern VOID ROM_odm_SetCrystalCap_B(
    IN      PVOID                   pDM_VOID,
    IN      u1Byte                  Crystal_Cap);

extern u1Byte ROM_odm_GetDefaultCrytaltalCap_A(
    IN      PVOID                   pDM_VOID);
extern u1Byte ROM_odm_GetDefaultCrytaltalCap_B(
    IN      PVOID                   pDM_VOID);

extern VOID ROM_ODM_CfoTrackingReset_A(
    IN      PVOID                   pDM_VOID);
extern VOID ROM_ODM_CfoTrackingReset_B(
    IN      PVOID                   pDM_VOID);

extern VOID ROM_odm_CfoTrackingFlow_A(
    IN      PVOID                   pDM_VOID);
extern VOID ROM_odm_CfoTrackingFlow_B(
    IN      PVOID                   pDM_VOID);

extern int rtw_get_bit_value_from_ieee_value_A(u8 val);
extern int rtw_get_bit_value_from_ieee_value_B(u8 val);

extern uint	rtw_is_cckrates_included_A(u8 *rate);
extern uint	rtw_is_cckrates_included_B(u8 *rate);

extern uint	rtw_is_cckratesonly_included_A(u8 *rate);
extern uint	rtw_is_cckratesonly_included_B(u8 *rate);

extern int rtw_check_network_type_A(unsigned char *rate, int ratelen, int channel);
extern int rtw_check_network_type_B(unsigned char *rate, int ratelen, int channel);

extern u8 *rtw_set_fixed_ie_A(unsigned char *pbuf, unsigned int len, unsigned char *source,
				unsigned int *frlen);
extern u8 *rtw_set_fixed_ie_B(unsigned char *pbuf, unsigned int len, unsigned char *source,
				unsigned int *frlen);

extern u8 *rtw_set_ie_A
(
	u8 *pbuf, 
	sint index, 
	uint len,
	u8 *source, 
	uint *frlen //frame length
);
extern u8 *rtw_set_ie_B
(
	u8 *pbuf, 
	sint index, 
	uint len,
	u8 *source, 
	uint *frlen //frame length
);

extern u8 *rtw_get_ie_A(u8 *pbuf, sint index, u32 *len, sint limit);
extern u8 *rtw_get_ie_B(u8 *pbuf, sint index, u32 *len, sint limit);

extern void rtw_set_supported_rate_A(u8* SupportedRates, uint mode) ;
extern void rtw_set_supported_rate_B(u8* SupportedRates, uint mode) ;

extern uint	rtw_get_rateset_len_A(u8	*rateset);
extern uint	rtw_get_rateset_len_B(u8	*rateset);

extern unsigned char *rtw_get_wpa_ie_A(unsigned char *pie, u32 *wpa_ie_len, int limit);
extern unsigned char *rtw_get_wpa_ie_B(unsigned char *pie, u32 *wpa_ie_len, int limit);

extern unsigned char *rtw_get_wpa2_ie_A(unsigned char *pie, u32 *rsn_ie_len, int limit);
extern unsigned char *rtw_get_wpa2_ie_B(unsigned char *pie, u32 *rsn_ie_len, int limit);

extern int rtw_get_wpa_cipher_suite_A(u8 *s);
extern int rtw_get_wpa_cipher_suite_B(u8 *s);

extern int rtw_get_wpa2_cipher_suite_A(u8 *s);
extern int rtw_get_wpa2_cipher_suite_B(u8 *s);

extern int rtw_parse_wpa_ie_A(u8* wpa_ie, int wpa_ie_len, int *group_cipher, int *pairwise_cipher, int *is_8021x);
extern int rtw_parse_wpa_ie_B(u8* wpa_ie, int wpa_ie_len, int *group_cipher, int *pairwise_cipher, int *is_8021x);

extern int rtw_parse_wpa2_ie_A(u8* rsn_ie, int rsn_ie_len, int *group_cipher, int *pairwise_cipher, int *is_8021x);
extern int rtw_parse_wpa2_ie_B(u8* rsn_ie, int rsn_ie_len, int *group_cipher, int *pairwise_cipher, int *is_8021x);

extern int rtw_get_sec_ie_A(u8 *in_ie,uint in_len,u8 *rsn_ie,u16 *rsn_len,u8 *wpa_ie,u16 *wpa_len);
extern int rtw_get_sec_ie_B(u8 *in_ie,uint in_len,u8 *rsn_ie,u16 *rsn_len,u8 *wpa_ie,u16 *wpa_len);

extern u8 *rtw_get_wps_ie_A(u8 *in_ie, uint in_len, u8 *wps_ie, uint *wps_ielen);
extern u8 *rtw_get_wps_ie_B(u8 *in_ie, uint in_len, u8 *wps_ie, uint *wps_ielen);

extern u8 *rtw_get_wps_attr_A(u8 *wps_ie, uint wps_ielen, u16 target_attr_id ,u8 *buf_attr, u32 *len_attr);
extern u8 *rtw_get_wps_attr_B(u8 *wps_ie, uint wps_ielen, u16 target_attr_id ,u8 *buf_attr, u32 *len_attr);

extern u8 *rtw_get_wps_attr_content_A(u8 *wps_ie, uint wps_ielen, u16 target_attr_id ,u8 *buf_content, uint *len_content);
extern u8 *rtw_get_wps_attr_content_B(u8 *wps_ie, uint wps_ielen, u16 target_attr_id ,u8 *buf_content, uint *len_content);

extern ParseRes rtw_ieee802_11_parse_elems_A(u8 *start, uint len,
				struct rtw_ieee802_11_elems *elems,
				int show_errors);
extern ParseRes rtw_ieee802_11_parse_elems_B(u8 *start, uint len,
				struct rtw_ieee802_11_elems *elems,
				int show_errors);

extern u8 str_2char2num_A(u8 hch, u8 lch);
extern u8 str_2char2num_B(u8 hch, u8 lch);

extern u8 key_2char2num_A(u8 hch, u8 lch);
extern u8 key_2char2num_B(u8 hch, u8 lch);

extern u8 convert_ip_addr_A(u8 hch, u8 mch, u8 lch);
extern u8 convert_ip_addr_B(u8 hch, u8 mch, u8 lch);

extern int rom_psk_PasswordHash_A(
	unsigned char *password,
	int passwordlength,
	unsigned char *ssid,
	int ssidlength,
	unsigned char *output);
extern int rom_psk_PasswordHash_B(
	unsigned char *password,
	int passwordlength,
	unsigned char *ssid,
	int ssidlength,
	unsigned char *output);

extern void rom_psk_CalcGTK_A(unsigned char *addr, unsigned char *nonce,
				unsigned char *keyin, int keyinlen,
				unsigned char *keyout, int keyoutlen);
extern void rom_psk_CalcGTK_B(unsigned char *addr, unsigned char *nonce,
				unsigned char *keyin, int keyinlen,
				unsigned char *keyout, int keyoutlen);

extern void rom_psk_CalcPTK_A(	unsigned char *addr1, unsigned char *addr2,
			unsigned char *nonce1, unsigned char *nonce2,
			unsigned char *keyin, int keyinlen,
			unsigned char *keyout, int keyoutlen);
extern void rom_psk_CalcPTK_B(	unsigned char *addr1, unsigned char *addr2,
			unsigned char *nonce1, unsigned char *nonce2,
			unsigned char *keyin, int keyinlen,
			unsigned char *keyout, int keyoutlen);

extern u16 _htons_rom_A(u16 n);
extern u16 _htons_rom_B(u16 n);

extern u16 _ntohs_rom_A(u16 n);
extern u16 _ntohs_rom_B(u16 n);

extern u32 _htonl_rom_A(u32 n);
extern u32 _htonl_rom_B(u32 n);

extern u32 _ntohl_rom_A(u32 n);
extern u32 _ntohl_rom_B(u32 n);

extern void Message_ReplayCounter_OC2LI_A(OCTET_STRING f, LARGE_INTEGER * li);
extern void Message_ReplayCounter_OC2LI_B(OCTET_STRING f, LARGE_INTEGER * li);

extern int Message_EqualReplayCounter_A(LARGE_INTEGER li1, OCTET_STRING f);
extern int Message_EqualReplayCounter_B(LARGE_INTEGER li1, OCTET_STRING f);

extern int Message_SmallerEqualReplayCounter_A(LARGE_INTEGER li1, OCTET_STRING f);
extern int Message_SmallerEqualReplayCounter_B(LARGE_INTEGER li1, OCTET_STRING f);

extern int Message_LargerReplayCounter_A(LARGE_INTEGER li1, OCTET_STRING f);
extern int Message_LargerReplayCounter_B(LARGE_INTEGER li1, OCTET_STRING f);

extern void Message_setReplayCounter_A(OCTET_STRING f, unsigned long h, unsigned long l);
extern void Message_setReplayCounter_B(OCTET_STRING f, unsigned long h, unsigned long l);

extern void INCLargeInteger_A(LARGE_INTEGER * x);
extern void INCLargeInteger_B(LARGE_INTEGER * x);

extern void INCOctet16_INTEGER_A(OCTET16_INTEGER * x);
extern void INCOctet16_INTEGER_B(OCTET16_INTEGER * x);

extern OCTET32_INTEGER *INCOctet32_INTEGER_A(OCTET32_INTEGER * x);
extern OCTET32_INTEGER *INCOctet32_INTEGER_B(OCTET32_INTEGER * x);

extern void SetEAPOL_KEYIV_A(OCTET_STRING ocDst, OCTET32_INTEGER oc32Counter);
extern void SetEAPOL_KEYIV_B(OCTET_STRING ocDst, OCTET32_INTEGER oc32Counter);

extern int CheckMIC_A(OCTET_STRING EAPOLMsgRecvd, unsigned char *key, int keylen);
extern int CheckMIC_B(OCTET_STRING EAPOLMsgRecvd, unsigned char *key, int keylen);

extern void CalcMIC_A(OCTET_STRING EAPOLMsgSend, int algo, unsigned char *key, int keylen);
extern void CalcMIC_B(OCTET_STRING EAPOLMsgSend, int algo, unsigned char *key, int keylen);

extern int DecWPA2KeyData_rom_A(OCTET_STRING EAPOLMsgRecvd, OCTET_STRING EapolKeyMsgRecvd, unsigned char *key, int keylen, unsigned char *kek, int keklen, unsigned char *kout)
;
extern int DecWPA2KeyData_rom_B(OCTET_STRING EAPOLMsgRecvd, OCTET_STRING EapolKeyMsgRecvd, unsigned char *key, int keylen, unsigned char *kek, int keklen, unsigned char *kout)
;

extern int DecGTK_A(OCTET_STRING EAPOLMsgRecvd, unsigned char *kek, int keklen, int keylen, unsigned char *kout);
extern int DecGTK_B(OCTET_STRING EAPOLMsgRecvd, unsigned char *kek, int keklen, int keylen, unsigned char *kout);

extern void GetRandomBuffer_A(unsigned char *pHashed);
extern void GetRandomBuffer_B(unsigned char *pHashed);

extern void GenNonce_A(unsigned char *nonce, unsigned char *addr);
extern void GenNonce_B(unsigned char *nonce, unsigned char *addr);

extern VOID ClientConstructEAPOL_2Of4Way_A(
	OCTET_STRING *pEapolKeyMsgSend, 
	OCTET_STRING StaInfoEapolKeyMsgRecvd, 
	OCTET_STRING StaInfoSNonce,
	OCTET_STRING GblInfoAuthInfoElement);
extern VOID ClientConstructEAPOL_2Of4Way_B(
	OCTET_STRING *pEapolKeyMsgSend, 
	OCTET_STRING StaInfoEapolKeyMsgRecvd, 
	OCTET_STRING StaInfoSNonce,
	OCTET_STRING GblInfoAuthInfoElement);

extern VOID ClientConstructEAPOL_4Of4Way_A(
	OCTET_STRING *pEapolKeyMsgSend,
	OCTET_STRING StaInfoEapolKeyMsgRecvd);
extern VOID ClientConstructEAPOL_4Of4Way_B(
	OCTET_STRING *pEapolKeyMsgSend,
	OCTET_STRING StaInfoEapolKeyMsgRecvd);

extern VOID ClientConstructEAPOL_2Of2Way_A(
	OCTET_STRING *pEapolKeyMsgSend, 
	OCTET_STRING StaInfoEapolKeyMsgRecvd,
	int GblInfoGN);
extern VOID ClientConstructEAPOL_2Of2Way_B(
	OCTET_STRING *pEapolKeyMsgSend, 
	OCTET_STRING StaInfoEapolKeyMsgRecvd,
	int GblInfoGN);

extern VOID ClientConstructEAPOL_MICOf2Way_A(
	OCTET_STRING *pStaInfoEAPOLMsgSend, 
	OCTET_STRING *pStaInfoEapolKeyMsgSend, 
	LARGE_INTEGER *pStaInfoclientMICReportReplayCounter,
	int StaInfoRSNEnabled,
	u8 KeyDescriptorVer);
extern VOID ClientConstructEAPOL_MICOf2Way_B(
	OCTET_STRING *pStaInfoEAPOLMsgSend, 
	OCTET_STRING *pStaInfoEapolKeyMsgSend, 
	LARGE_INTEGER *pStaInfoclientMICReportReplayCounter,
	int StaInfoRSNEnabled,
	u8 KeyDescriptorVer);

extern u16 psk_strip_rsn_pairwise_A(u8 *ie, u16 ie_len);
extern u16 psk_strip_rsn_pairwise_B(u8 *ie, u16 ie_len);

extern u16 psk_strip_wpa_pairwise_A(u8 *ie, u16 ie_len);
extern u16 psk_strip_wpa_pairwise_B(u8 *ie, u16 ie_len);

extern void wep_80211_encrypt_A(
	u8 *pframe, u32 wlan_hdr_len, \
	u32 iv_len, u32 payload_len,\
	u8* key, u32 key_len);
extern void wep_80211_encrypt_B(
	u8 *pframe, u32 wlan_hdr_len, \
	u32 iv_len, u32 payload_len,\
	u8* key, u32 key_len);

extern u8 wep_80211_decrypt_A(
	u8 *pframe, u32 wlan_hdr_len, 
	u32 iv_len, u32 payload_len,
	u8* key, u32 key_len,
	union u_crc *pcrc);
extern u8 wep_80211_decrypt_B(
	u8 *pframe, u32 wlan_hdr_len, 
	u32 iv_len, u32 payload_len,
	u8* key, u32 key_len,
	union u_crc *pcrc);

extern void tkip_micappendbyte_A(struct mic_data *pmicdata, u8 b );
extern void tkip_micappendbyte_B(struct mic_data *pmicdata, u8 b );

extern void rtw_secmicsetkey_A(struct mic_data *pmicdata, u8 * key );
extern void rtw_secmicsetkey_B(struct mic_data *pmicdata, u8 * key );

extern void rtw_secmicappend_A(struct mic_data *pmicdata, u8 * src, u32 nbytes );
extern void rtw_secmicappend_B(struct mic_data *pmicdata, u8 * src, u32 nbytes );

extern void rtw_secgetmic_A(struct mic_data *pmicdata, u8 * dst );
extern void rtw_secgetmic_B(struct mic_data *pmicdata, u8 * dst );

extern void rtw_seccalctkipmic_A(u8 * key,u8 *header,u8 *data,u32 data_len,u8 *mic_code, u8 pri);
extern void rtw_seccalctkipmic_B(u8 * key,u8 *header,u8 *data,u32 data_len,u8 *mic_code, u8 pri);

extern void tkip_phase1_A(u16 *p1k,const u8 *tk,const u8 *ta,u32 iv32);
extern void tkip_phase1_B(u16 *p1k,const u8 *tk,const u8 *ta,u32 iv32);

extern void tkip_phase2_A(u8 *rc4key,const u8 *tk,const u16 *p1k,u16 iv16);
extern void tkip_phase2_B(u8 *rc4key,const u8 *tk,const u16 *p1k,u16 iv16);

extern void tkip_80211_encrypt_A(
	u8 *pframe, u32 wlan_hdr_len, \
	u32 iv_len, u32 payload_len,\
	u8* key, u32 key_len,\
	u8* ta);
extern void tkip_80211_encrypt_B(
	u8 *pframe, u32 wlan_hdr_len, \
	u32 iv_len, u32 payload_len,\
	u8* key, u32 key_len,\
	u8* ta);

extern u8 tkip_80211_decrypt_A(
	u8 *pframe, u32 wlan_hdr_len, \
	u32 iv_len, u32 payload_len,\
	u8* key, u32 key_len,\
	u8* ta, union u_crc *pcrc);
extern u8 tkip_80211_decrypt_B(
	u8 *pframe, u32 wlan_hdr_len, \
	u32 iv_len, u32 payload_len,\
	u8* key, u32 key_len,\
	u8* ta, union u_crc *pcrc);

extern void aes1_encrypt_A(u8 *key, u8 *data, u8 *ciphertext);
extern void aes1_encrypt_B(u8 *key, u8 *data, u8 *ciphertext);

extern void aesccmp_construct_mic_iv_A(
	u8 *mic_iv, sint qc_exists, sint a4_exists, 
	u8 *mpdu, uint payload_length,u8 *pn_vector);
extern void aesccmp_construct_mic_iv_B(
	u8 *mic_iv, sint qc_exists, sint a4_exists, 
	u8 *mpdu, uint payload_length,u8 *pn_vector);

extern void aesccmp_construct_mic_header1_A(u8 *mic_header1, sint header_length, u8 *mpdu)    ;
extern void aesccmp_construct_mic_header1_B(u8 *mic_header1, sint header_length, u8 *mpdu)    ;

extern void aesccmp_construct_mic_header2_A(
	u8 *mic_header2, u8 *mpdu, sint a4_exists, sint qc_exists);
extern void aesccmp_construct_mic_header2_B(
	u8 *mic_header2, u8 *mpdu, sint a4_exists, sint qc_exists);

extern void aesccmp_construct_ctr_preload_A(
	u8 *ctr_preload, sint a4_exists, sint qc_exists,
	u8 *mpdu, u8 *pn_vector, sint c);
extern void aesccmp_construct_ctr_preload_B(
	u8 *ctr_preload, sint a4_exists, sint qc_exists,
	u8 *mpdu, u8 *pn_vector, sint c);

extern u32 aes_80211_encrypt_A(
	u8 *pframe, u32 wlan_hdr_len, \
	u32 payload_len, u8 *key, \
	u32 frame_type, u8 *mic);
extern u32 aes_80211_encrypt_B(
	u8 *pframe, u32 wlan_hdr_len, \
	u32 payload_len, u8 *key, \
	u32 frame_type, u8 *mic);

extern u32 aes_80211_decrypt_A(
	u8 *pframe, u32 wlan_hdr_len, \
	u32 payload_len, u8 *key, \
	u32 frame_type, u8 *mic);
extern u32 aes_80211_decrypt_B(
	u8 *pframe, u32 wlan_hdr_len, \
	u32 payload_len, u8 *key, \
	u32 frame_type, u8 *mic);

extern int cckrates_included_A(unsigned char *rate, int ratelen);
extern int cckrates_included_B(unsigned char *rate, int ratelen);

extern int cckratesonly_included_A(unsigned char *rate, int ratelen);
extern int cckratesonly_included_B(unsigned char *rate, int ratelen);

extern unsigned char  networktype_to_raid_ex_rom_A(u8 rf_type, u8 cur_bwmode, unsigned char network_type);
extern unsigned char  networktype_to_raid_ex_rom_B(u8 rf_type, u8 cur_bwmode, unsigned char network_type);

extern u8 judge_network_type_rom_A(u8 cur_channel, u8 HT_enable, unsigned char *rate, int ratelen);
extern u8 judge_network_type_rom_B(u8 cur_channel, u8 HT_enable, unsigned char *rate, int ratelen);

extern unsigned char ratetbl_val_2wifirate_A(unsigned char rate);
extern unsigned char ratetbl_val_2wifirate_B(unsigned char rate);

extern int is_basicrate_rom_A(u8 basicrate[], unsigned char rate);
extern int is_basicrate_rom_B(u8 basicrate[], unsigned char rate);

extern unsigned int ratetbl2rateset_rom_A(u8 datarate[], unsigned char *rateset);
extern unsigned int ratetbl2rateset_rom_B(u8 datarate[], u8 basicrate[], unsigned char *rateset);

extern void UpdateBrateTbl_rom_A(
	IN u8			*mBratesOS
);
extern void UpdateBrateTbl_rom_B(
	IN u8			*mBratesOS
);

extern void UpdateBrateTblForSoftAP_A(u8 *bssrateset, u32 bssratelen);
extern void UpdateBrateTblForSoftAP_B(u8 *bssrateset, u32 bssratelen);

extern void write_cam_rom_A(u8 entry, u16 ctrl, u8 *mac, u8 *key);
extern void write_cam_rom_B(u8 entry, u16 ctrl, u8 *mac, u8 *key);

extern void HT_caps_handler_rom_A(struct HT_caps_element *HT_caps, PNDIS_802_11_VARIABLE_IEs pIE);
extern void HT_caps_handler_rom_B(struct HT_caps_element *HT_caps, PNDIS_802_11_VARIABLE_IEs pIE);

extern int wifirate2_ratetbl_inx_A(unsigned char rate);
extern int wifirate2_ratetbl_inx_B(unsigned char rate);

extern unsigned int update_basic_rate_A(unsigned char *ptn, unsigned int ptn_sz);
extern unsigned int update_basic_rate_B(unsigned char *ptn, unsigned int ptn_sz);

extern unsigned int update_supported_rate_A(unsigned char *ptn, unsigned int ptn_sz);
extern unsigned int update_supported_rate_B(unsigned char *ptn, unsigned int ptn_sz);

extern unsigned int update_MCS_rate_A(struct HT_caps_element *pHT_caps);
extern unsigned int update_MCS_rate_B(struct HT_caps_element *pHT_caps);

extern unsigned char get_highest_rate_idx_A(u32 mask);
extern unsigned char get_highest_rate_idx_B(u32 mask);

extern void _sha1_process_message_block_A(SHA1Context *context);
extern void _sha1_process_message_block_B(SHA1Context *context);

extern void _sha1_pad_message_A(SHA1Context *context);
extern void _sha1_pad_message_B(SHA1Context *context);

extern int rt_sha1_init_A(SHA1Context *context);
extern int rt_sha1_init_B(SHA1Context *context);

extern int rt_sha1_update_A(    SHA1Context    *context,
                  const u8  *message_array,
                  unsigned       length);
extern int rt_sha1_update_B(    SHA1Context    *context,
                  const u8  *message_array,
                  unsigned       length);

extern int rt_sha1_finish_A( SHA1Context *context,
                u8 Message_Digest[SHA1HashSize]);
extern int rt_sha1_finish_B( SHA1Context *context,
                u8 Message_Digest[SHA1HashSize]);

extern void rt_hmac_sha1_A(unsigned char *text, int text_len, unsigned char *key,
		 int key_len, unsigned char *digest);
extern void rt_hmac_sha1_B(unsigned char *text, int text_len, unsigned char *key,
		 int key_len, unsigned char *digest);

extern int rom_aes_128_cbc_encrypt_A(const u8 *key, const u8 *iv, u8 *data, size_t data_len);
extern int rom_aes_128_cbc_encrypt_B(const u8 *key, const u8 *iv, u8 *data, size_t data_len);

extern int rom_aes_128_cbc_decrypt_A(const u8 *key, const u8 *iv, u8 *data, size_t data_len);
extern int rom_aes_128_cbc_decrypt_B(const u8 *key, const u8 *iv, u8 *data, size_t data_len);

extern void rom_rijndaelKeySetupEnc_A(u32 rk[/*44*/], const u8 cipherKey[]);
extern void rom_rijndaelKeySetupEnc_B(u32 rk[/*44*/], const u8 cipherKey[]);

extern void *rom_aes_decrypt_init_A(unsigned char *mem, const u8 *key, size_t len);
extern void *rom_aes_decrypt_init_B(unsigned char *mem, const u8 *key, size_t len);

extern void rom_aes_internal_decrypt_A(void *ctx, const u8 *crypt, u8 *plain);
extern void rom_aes_internal_decrypt_B(void *ctx, const u8 *crypt, u8 *plain);

extern void rom_aes_decrypt_deinit_A(void *ctx);
extern void rom_aes_decrypt_deinit_B(void *ctx);

extern void *rom_aes_encrypt_init_A(unsigned char *mem, const u8 *key, size_t len);
extern void *rom_aes_encrypt_init_B(unsigned char *mem, const u8 *key, size_t len);

extern void rom_aes_internal_encrypt_A(void *ctx, const u8 *plain, u8 *crypt);
extern void rom_aes_internal_encrypt_B(void *ctx, const u8 *plain, u8 *crypt);

extern void rom_aes_encrypt_deinit_A(void *ctx);
extern void rom_aes_encrypt_deinit_B(void *ctx);

extern struct bignum *bignum_init_A(void);
extern struct bignum *bignum_init_B(void);

extern void bignum_deinit_A(struct bignum *n);
extern void bignum_deinit_B(struct bignum *n);

extern size_t bignum_get_unsigned_bin_len_A(struct bignum *n);
extern size_t bignum_get_unsigned_bin_len_B(struct bignum *n);

extern int bignum_get_unsigned_bin_A(const struct bignum *n, u8 *buf, size_t *len);
extern int bignum_get_unsigned_bin_B(const struct bignum *n, u8 *buf, size_t *len);

extern int bignum_set_unsigned_bin_A(struct bignum *n, const u8 *buf, size_t len);
extern int bignum_set_unsigned_bin_B(struct bignum *n, const u8 *buf, size_t len);

extern int bignum_cmp_A(const struct bignum *a, const struct bignum *b);
extern int bignum_cmp_B(const struct bignum *a, const struct bignum *b);

extern int bignum_cmp_d_A(const struct bignum *a, unsigned long b);
extern int bignum_cmp_d_B(const struct bignum *a, unsigned long b);

extern int bignum_add_A(const struct bignum *a, const struct bignum *b,
	       struct bignum *c);
extern int bignum_add_B(const struct bignum *a, const struct bignum *b,
	       struct bignum *c);

extern int bignum_sub_A(const struct bignum *a, const struct bignum *b,
	       struct bignum *c);
extern int bignum_sub_B(const struct bignum *a, const struct bignum *b,
	       struct bignum *c);

extern int bignum_mul_A(const struct bignum *a, const struct bignum *b,
	       struct bignum *c);
extern int bignum_mul_B(const struct bignum *a, const struct bignum *b,
	       struct bignum *c);

extern int bignum_exptmod_A(const struct bignum *a, const struct bignum *b,
		   const struct bignum *c, struct bignum *d);
extern int bignum_exptmod_B(const struct bignum *a, const struct bignum *b,
		   const struct bignum *c, struct bignum *d);

extern u8 *WPS_realloc_A(u8 *old_buf, u32 old_sz, u32 new_sz);
extern u8 *WPS_realloc_B(u8 *old_buf, u32 old_sz, u32 new_sz);

extern void *os_zalloc_A(size_t size);
extern void *os_zalloc_B(size_t size);

extern int rom_hmac_sha256_vector_A(const u8 *key, size_t key_len, size_t num_elem,
		       const u8 *addr[], const size_t *len, u8 *mac);
extern int rom_hmac_sha256_vector_B(const u8 *key, size_t key_len, size_t num_elem,
		       const u8 *addr[], const size_t *len, u8 *mac);

extern int rom_hmac_sha256_A(const u8 *key, size_t key_len, const u8 *data,
		size_t data_len, u8 *mac);
extern int rom_hmac_sha256_B(const u8 *key, size_t key_len, const u8 *data,
		size_t data_len, u8 *mac);

extern int rom_sha256_vector_A(size_t num_elem, const u8 *addr[], const size_t *len,
		  u8 *mac);
extern int rom_sha256_vector_B(size_t num_elem, const u8 *addr[], const size_t *len,
		  u8 *mac);

extern void CRYPTO_chacha_20_A(unsigned char *out,
		      const unsigned char *in, size_t in_len,
		      const unsigned char key[32],
		      const unsigned char nonce[8],
		      size_t counter);
extern void CRYPTO_chacha_20_B(unsigned char *out,
		      const unsigned char *in, size_t in_len,
		      const unsigned char key[32],
		      const unsigned char nonce[8],
		      size_t counter);

extern char * __rtl_dtoa_r_v1_00_A(
	struct _reent *ptr,
	double _d,
	int mode,
	int ndigits,
	int *decpt,
	int *sign,
	char **rve);
extern char * __rtl_dtoa_r_v1_00_B(
	struct _reent *ptr,
	double _d,
	int mode,
	int ndigits,
	int *decpt,
	int *sign,
	char **rve);

extern char* __rtl_ltoa_v1_00_A( long value, char *string, int radix );
extern char* __rtl_ltoa_v1_00_B( long value, char *string, int radix );

extern char* __rtl_ultoa_v1_00_A( unsigned long value, char *string, int radix );
extern char* __rtl_ultoa_v1_00_B( unsigned long value, char *string, int radix );

extern int __rtl_dtoi_v1_00_A(double d);
extern int __rtl_dtoi_v1_00_B(double d);

extern int64 __rtl_dtoi64_v1_00_A(double d);
extern int64 __rtl_dtoi64_v1_00_B(double d);

extern unsigned int __rtl_dtoui_v1_00_A(double d);
extern unsigned int __rtl_dtoui_v1_00_B(double d);

extern long __rtl_ftol_v1_00_A(float f);
extern long __rtl_ftol_v1_00_B(float f);

extern float __rtl_itof_v1_00_A(int32 lval);
extern float __rtl_itof_v1_00_B(int32 lval);

extern double __rtl_itod_v1_00_A(int32 lval);
extern double __rtl_itod_v1_00_B(int32 lval);

extern double __rtl_i64tod_v1_00_A(int64 lval);
extern double __rtl_i64tod_v1_00_B(int64 lval);

extern double __rtl_uitod_v1_00_A(uint32 lval);
extern double __rtl_uitod_v1_00_B(uint32 lval);

extern double __rtl_ftod_v1_00_A(float f);
extern double __rtl_ftod_v1_00_B(float f);

extern float __rtl_dtof_v1_00_A(double d);
extern float __rtl_dtof_v1_00_B(double d);

extern float __rtl_uitof_v1_00_A(uint32 lval);
extern float __rtl_uitof_v1_00_B(uint32 lval);

extern float __rtl_fadd_v1_00_A(float a, float b);
extern float __rtl_fadd_v1_00_B(float a, float b);

extern float __rtl_fsub_v1_00_A(float a, float b);
extern float __rtl_fsub_v1_00_B(float a, float b);

extern float __rtl_fmul_v1_00_A(float a, float b);
extern float __rtl_fmul_v1_00_B(float a, float b);

extern float __rtl_fdiv_v1_00_A(float a, float b);
extern float __rtl_fdiv_v1_00_B(float a, float b);

extern double __rtl_dadd_v1_00_A(double a, double b);
extern double __rtl_dadd_v1_00_B(double a, double b);

extern double __rtl_dsub_v1_00_A(double a, double b);
extern double __rtl_dsub_v1_00_B(double a, double b);

extern double __rtl_dmul_v1_00_A(double a, double b);
extern double __rtl_dmul_v1_00_B(double a, double b);

extern double __rtl_ddiv_v1_00_A(double a, double b);
extern double __rtl_ddiv_v1_00_B(double a, double b);

extern int __rtl_dcmpeq_v1_00_A(double a, double b);
extern int __rtl_dcmpeq_v1_00_B(double a, double b);

extern int __rtl_dcmplt_v1_00_A(double a, double b);
extern int __rtl_dcmplt_v1_00_B(double a, double b);

extern int __rtl_dcmpgt_v1_00_A(double a, double b);
extern int __rtl_dcmpgt_v1_00_B(double a, double b);

extern int __rtl_dcmple_v1_00_A(double a, double b);
extern int __rtl_dcmple_v1_00_B(double a, double b);

extern int __rtl_fcmplt_v1_00_A(float a, float b);
extern int __rtl_fcmplt_v1_00_B(float a, float b);

extern int __rtl_fcmpgt_v1_00_A(float a, float b);
extern int __rtl_fcmpgt_v1_00_B(float a, float b);

extern int __rtl_fpclassifyd_A (double x);
extern int __rtl_fpclassifyd_B (double x);

extern int __rtl_close_v1_00_A(int fildes);
extern int __rtl_close_v1_00_B(int fildes);

extern int __rtl_fstat_v1_00_A(int fildes , struct stat *st);
extern int __rtl_fstat_v1_00_B(int fildes , struct stat *st);

extern int __rtl_isatty_v1_00_A(int file);
extern int __rtl_isatty_v1_00_B(int file);

extern int __rtl_lseek_v1_00_A(int file , int ptr , int dir);
extern int __rtl_lseek_v1_00_B(int file , int ptr , int dir);

extern int __rtl_open_v1_00_A(char *file , int flags , int mode);
extern int __rtl_open_v1_00_B(char *file , int flags , int mode);

extern int __rtl_read_v1_00_A(int file , char *ptr , int len);
extern int __rtl_read_v1_00_B(int file , char *ptr , int len);

extern int __rtl_write_v1_00_A(int file , const char *ptr , int len);
extern int __rtl_write_v1_00_B(int file , const char *ptr , int len);

extern void* __rtl_sbrk_v1_00_A(int incr);
extern void* __rtl_sbrk_v1_00_B(int incr);

extern void __rom_mallocr_init_v1_00_A(void);
extern void __rom_mallocr_init_v1_00_B(void);

#if 0
extern void __rtl_free_r_v1_00_A(RARG Void_t* mem);
extern void __rtl_free_r_v1_00_B(RARG Void_t* mem);

extern void* __rtl_malloc_r_v1_00_A(RARG size_t bytes);
extern void* __rtl_malloc_r_v1_00_B(RARG size_t bytes);

extern void* __rtl_realloc_r_v1_00_A(RARG void* oldmem, size_t bytes);
extern void* __rtl_realloc_r_v1_00_B(RARG void* oldmem, size_t bytes);

extern void* __rtl_memalign_r_v1_00_A(RARG size_t alignment, size_t bytes);
extern void* __rtl_memalign_r_v1_00_B(RARG size_t alignment, size_t bytes);

extern void* __rtl_valloc_r_v1_00_A(RARG size_t bytes);
extern void* __rtl_valloc_r_v1_00_B(RARG size_t bytes);

extern void* __rtl_pvalloc_r_v1_00_A(RARG size_t bytes);
extern void* __rtl_pvalloc_r_v1_00_B(RARG size_t bytes);

extern Void_t* __rtl_calloc_r_v1_00_A(RARG size_t n, size_t elem_size);
extern Void_t* __rtl_calloc_r_v1_00_B(RARG size_t n, size_t elem_size);
#endif

extern void __rtl_cfree_r_v1_00_A(void *mem);
extern void __rtl_cfree_r_v1_00_B(void *mem);

extern float __rtl_cos_f32_v1_00_A(float x);
extern float __rtl_cos_f32_v1_00_B(float x);

extern float __rtl_sin_f32_v1_00_A(float x);
extern float __rtl_sin_f32_v1_00_B(float x);

extern double __rtl_fabs_v1_00_A(double d);
extern double __rtl_fabs_v1_00_B(double d);

extern float __rtl_fabsf_v1_00_A(float x);
extern float __rtl_fabsf_v1_00_B(float x);

extern void * __rtl_memchr_v1_00_A(const void * src_void , int c , size_t length);
extern void * __rtl_memchr_v1_00_B(const void * src_void , int c , size_t length);

extern int __rtl_memcmp_v1_00_A(const void * m1 , const void * m2 , size_t n);
extern int __rtl_memcmp_v1_00_B(const void * m1 , const void * m2 , size_t n);

extern void * __rtl_memcpy_v1_00_A(void * __restrict dst0 , const void * __restrict src0 , size_t len0);
extern void * __rtl_memcpy_v1_00_B(void * __restrict dst0 , const void * __restrict src0 , size_t len0);


extern void *  __rtl_memmove_v1_00_A( void * dst_void , const void * src_void , size_t length);
extern void *  __rtl_memmove_v1_00_B( void * dst_void , const void * src_void , size_t length);

extern void *  __rtl_memset_v1_00_A(void * m , int c , size_t n);
extern void *  __rtl_memset_v1_00_B(void * m , int c , size_t n);

#if 0
extern _Bigint * __rtl_Balloc_v1_00_A(struct _reent *ptr, int k);
extern _Bigint * __rtl_Balloc_v1_00_B(struct _reent *ptr, int k);

extern void __rtl_Bfree_v1_00_A(struct _reent *ptr, _Bigint * v);
extern void __rtl_Bfree_v1_00_B(struct _reent *ptr, _Bigint * v);

extern _Bigint * __rtl_i2b_v1_00_A(struct _reent *ptr, int i );
extern _Bigint * __rtl_i2b_v1_00_B(struct _reent *ptr, int i );

extern _Bigint * __rtl_multadd_v1_00_A(
	struct _reent *ptr,
	_Bigint * b,
	int m,
	int a);
extern _Bigint * __rtl_multadd_v1_00_B(
	struct _reent *ptr,
	_Bigint * b,
	int m,
	int a);

extern _Bigint * __rtl_mult_v1_00_A(struct _reent *ptr, _Bigint *a, _Bigint *b);
extern _Bigint * __rtl_mult_v1_00_B(struct _reent *ptr, _Bigint *a, _Bigint *b);

extern _Bigint * __rtl_pow5mult_v1_00_A(struct _reent * ptr, _Bigint *b, int k);
extern _Bigint * __rtl_pow5mult_v1_00_B(struct _reent * ptr, _Bigint *b, int k);

extern int __rtl_hi0bits_v1_00_A(register __ULong x);
extern int __rtl_hi0bits_v1_00_B(register __ULong x);

extern _Bigint * __rtl_d2b_v1_00_A(
	struct _reent * ptr,
	double _d,
	int *e,
	int *bits);
extern _Bigint * __rtl_d2b_v1_00_B(
	struct _reent * ptr,
	double _d,
	int *e,
	int *bits);

extern _Bigint *__rtl_lshift_v1_00_A(struct _reent *ptr, _Bigint *b, int k);
extern _Bigint *__rtl_lshift_v1_00_B(struct _reent *ptr, _Bigint *b, int k);

extern int __rtl_cmp_v1_00_A(_Bigint *a, _Bigint *b);
extern int __rtl_cmp_v1_00_B(_Bigint *a, _Bigint *b);

extern _Bigint *__rtl_diff_v1_00_A(struct _reent* ptr, _Bigint *a, _Bigint *b);
extern _Bigint *__rtl_diff_v1_00_B(struct _reent* ptr, _Bigint *a, _Bigint *b);

extern _READ_WRITE_RETURN_TYPE __rtl_sread_v1_00_A(
       struct _reent *ptr,
       void *cookie,
       char *buf,
       _READ_WRITE_BUFSIZE_TYPE n);
extern _READ_WRITE_RETURN_TYPE __rtl_sread_v1_00_B(
       struct _reent *ptr,
       void *cookie,
       char *buf,
       _READ_WRITE_BUFSIZE_TYPE n);

extern _READ_WRITE_RETURN_TYPE __rtl_seofread_v1_00_A(
       struct _reent *_ptr,
       _PTR cookie,
       char *buf,
       _READ_WRITE_BUFSIZE_TYPE len);
extern _READ_WRITE_RETURN_TYPE __rtl_seofread_v1_00_B(
       struct _reent *_ptr,
       _PTR cookie,
       char *buf,
       _READ_WRITE_BUFSIZE_TYPE len);

extern _READ_WRITE_RETURN_TYPE __rtl_swrite_v1_00_A(
       struct _reent *ptr,
       void *cookie,
       char const *buf,
       _READ_WRITE_BUFSIZE_TYPE n);
extern _READ_WRITE_RETURN_TYPE __rtl_swrite_v1_00_B(
       struct _reent *ptr,
       void *cookie,
       char const *buf,
       _READ_WRITE_BUFSIZE_TYPE n);

extern _fpos_t __rtl_sseek_v1_00_A(
       struct _reent *ptr,
       void *cookie,
       _fpos_t offset,
       int whence);
extern _fpos_t __rtl_sseek_v1_00_B(
       struct _reent *ptr,
       void *cookie,
       _fpos_t offset,
       int whence);

extern int __rtl_sclose_v1_00_A(
       struct _reent *ptr _AND
       void *cookie);
extern int __rtl_sclose_v1_00_B(
       struct _reent *ptr _AND
       void *cookie);

extern void * __rtl_sbrk_r_v1_00_A(
     struct _reent *ptr,
     ptrdiff_t incr);
extern void * __rtl_sbrk_r_v1_00_B(
     struct _reent *ptr,
     ptrdiff_t incr);
#endif
extern char * __rtl_strcat_v1_00_A(char *__restrict s1 , const char *__restrict s2);
extern char * __rtl_strcat_v1_00_B(char *__restrict s1 , const char *__restrict s2);

extern char * __rtl_strchr_v1_00_A(const char *s1 , int i);
extern char * __rtl_strchr_v1_00_B(const char *s1 , int i);

extern int __rtl_strcmp_v1_00_A(const char *s1 ,	const char *s2);
extern int __rtl_strcmp_v1_00_B(const char *s1 ,	const char *s2);

extern char* __rtl_strcpy_v1_00_A(char *dst0 , const char *src0);
extern char* __rtl_strcpy_v1_00_B(char *dst0 , const char *src0);

extern size_t __rtl_strlen_v1_00_A(const char *str);
extern size_t __rtl_strlen_v1_00_B(const char *str);

extern char * __rtl_strncat_v1_00_A(char *__restrict s1 , const char *__restrict s2 , size_t n);
extern char * __rtl_strncat_v1_00_B(char *__restrict s1 , const char *__restrict s2 , size_t n);

extern int __rtl_strncmp_v1_00_A(const char *s1 , const char *s2 , size_t n);
extern int __rtl_strncmp_v1_00_B(const char *s1 , const char *s2 , size_t n);

extern char * __rtl_strncpy_v1_00_A(char *__restrict dst0 , const char *__restrict src0 , size_t count);
extern char * __rtl_strncpy_v1_00_B(char *__restrict dst0 , const char *__restrict src0 , size_t count);

extern char * __rtl_strsep_v1_00_A(register char **source_ptr , register const char *delim);
extern char * __rtl_strsep_v1_00_B(register char **source_ptr , register const char *delim);

extern char * __rtl_strstr_v1_00_A(const char *searchee , const char *lookfor);
extern char * __rtl_strstr_v1_00_B(const char *searchee , const char *lookfor);

extern char * __rtl_strtok_v1_00_A(register char *__restrict s , register const char *__restrict delim);
extern char * __rtl_strtok_v1_00_B(register char *__restrict s , register const char *__restrict delim);

extern char * __rtl__strtok_r_v1_00_A(register char *s , register const char *delim , char **lasts , int skip_leading_delim);
extern char * __rtl__strtok_r_v1_00_B(register char *s , register const char *delim , char **lasts , int skip_leading_delim);

extern char * __rtl_strtok_r_v1_00_A(register char *__restrict s , register const char *__restrict delim , char **__restrict lasts);
extern char * __rtl_strtok_r_v1_00_B(register char *__restrict s , register const char *__restrict delim , char **__restrict lasts);


extern int __rtl_fflush_r_v1_00_A(
       void *ptr,
       register void * fp);
extern int __rtl_fflush_r_v1_00_B(
       void *ptr,
       register void * fp);

extern int __rtl_vfprintf_r_v1_00_A(
       void *data,
      void * fp,
       const char *fmt0,
       va_list ap);
extern int __rtl_vfprintf_r_v1_00_B(
       void *data,
       void * fp,
       const char *fmt0,
       va_list ap);

extern  void polarssl_aes_init_A(aes_context *ctx );
extern  void polarssl_aes_init_B(aes_context *ctx );

extern void aes_free_A( aes_context *ctx );
extern void aes_free_B( aes_context *ctx );

extern int aes_setkey_enc_A( aes_context *ctx, const unsigned char *key,
                    unsigned int keysize );
extern int aes_setkey_enc_B( aes_context *ctx, const unsigned char *key,
                    unsigned int keysize );

extern int aes_setkey_dec_A( aes_context *ctx, const unsigned char *key,
                    unsigned int keysize );
extern int aes_setkey_dec_B( aes_context *ctx, const unsigned char *key,
                    unsigned int keysize );

extern int aes_crypt_ecb_A( aes_context *ctx,
                    int mode,
                    const unsigned char input[16],
                    unsigned char output[16] );
extern int aes_crypt_ecb_B( aes_context *ctx,
                    int mode,
                    const unsigned char input[16],
                    unsigned char output[16] );

extern int aes_crypt_cbc_A( aes_context *ctx,
                    int mode,
                    size_t length,
                    unsigned char iv[16],
                    const unsigned char *input,
                    unsigned char *output );
extern int aes_crypt_cbc_B( aes_context *ctx,
                    int mode,
                    size_t length,
                    unsigned char iv[16],
                    const unsigned char *input,
                    unsigned char *output );

extern int aes_crypt_cfb128_A( aes_context *ctx,
                       int mode,
                       size_t length,
                       size_t *iv_off,
                       unsigned char iv[16],
                       const unsigned char *input,
                       unsigned char *output );
extern int aes_crypt_cfb128_B( aes_context *ctx,
                       int mode,
                       size_t length,
                       size_t *iv_off,
                       unsigned char iv[16],
                       const unsigned char *input,
                       unsigned char *output );

extern int aes_crypt_cfb8_A( aes_context *ctx,
                       int mode,
                       size_t length,
                       unsigned char iv[16],
                       const unsigned char *input,
                       unsigned char *output );
extern int aes_crypt_cfb8_B( aes_context *ctx,
                       int mode,
                       size_t length,
                       unsigned char iv[16],
                       const unsigned char *input,
                       unsigned char *output );

extern int aes_crypt_ctr_A( aes_context *ctx,
                       size_t length,
                       size_t *nc_off,
                       unsigned char nonce_counter[16],
                       unsigned char stream_block[16],
                       const unsigned char *input,
                       unsigned char *output );
extern int aes_crypt_ctr_B( aes_context *ctx,
                       size_t length,
                       size_t *nc_off,
                       unsigned char nonce_counter[16],
                       unsigned char stream_block[16],
                       const unsigned char *input,
                       unsigned char *output );

extern void arc4_init_A( arc4_context *ctx );
extern void arc4_init_B( arc4_context *ctx );

extern void arc4_free_A( arc4_context *ctx );
extern void arc4_free_B( arc4_context *ctx );

extern void arc4_setup_A( arc4_context *ctx, const unsigned char *key,
                 unsigned int keylen );
extern void arc4_setup_B( arc4_context *ctx, const unsigned char *key,
                 unsigned int keylen );

extern int arc4_crypt_A( arc4_context *ctx, size_t length, const unsigned char *input,
                unsigned char *output );
extern int arc4_crypt_B( arc4_context *ctx, size_t length, const unsigned char *input,
                unsigned char *output );

extern int asn1_get_len_A( unsigned char **p,
                  const unsigned char *end,
                  size_t *len );
extern int asn1_get_len_B( unsigned char **p,
                  const unsigned char *end,
                  size_t *len );

extern int asn1_get_tag_A( unsigned char **p,
                  const unsigned char *end,
                  size_t *len, int tag );
extern int asn1_get_tag_B( unsigned char **p,
                  const unsigned char *end,
                  size_t *len, int tag );

extern int asn1_get_bool_A( unsigned char **p,
                   const unsigned char *end,
                   int *val );
extern int asn1_get_bool_B( unsigned char **p,
                   const unsigned char *end,
                   int *val );

extern int asn1_get_int_A( unsigned char **p,
                  const unsigned char *end,
                  int *val );
extern int asn1_get_int_B( unsigned char **p,
                  const unsigned char *end,
                  int *val );

extern int asn1_get_mpi_A( unsigned char **p,
                  const unsigned char *end,
                  mpi *X );
extern int asn1_get_mpi_B( unsigned char **p,
                  const unsigned char *end,
                  mpi *X );

extern int asn1_get_bitstring_A( unsigned char **p, const unsigned char *end,
                        asn1_bitstring *bs);
extern int asn1_get_bitstring_B( unsigned char **p, const unsigned char *end,
                        asn1_bitstring *bs);

extern int asn1_get_bitstring_null_A( unsigned char **p, const unsigned char *end,
                             size_t *len );
extern int asn1_get_bitstring_null_B( unsigned char **p, const unsigned char *end,
                             size_t *len );

extern int asn1_get_sequence_of_A( unsigned char **p,
                          const unsigned char *end,
                          asn1_sequence *cur,
                          int tag);
extern int asn1_get_sequence_of_B( unsigned char **p,
                          const unsigned char *end,
                          asn1_sequence *cur,
                          int tag);

extern int asn1_get_alg_A( unsigned char **p,
                  const unsigned char *end,
                  asn1_buf *alg, asn1_buf *params );
extern int asn1_get_alg_B( unsigned char **p,
                  const unsigned char *end,
                  asn1_buf *alg, asn1_buf *params );

extern int asn1_get_alg_null_A( unsigned char **p,
                       const unsigned char *end,
                       asn1_buf *alg );
extern int asn1_get_alg_null_B( unsigned char **p,
                       const unsigned char *end,
                       asn1_buf *alg );

extern void asn1_free_named_data_A( asn1_named_data *cur );
extern void asn1_free_named_data_B( asn1_named_data *cur );

extern void asn1_free_named_data_list_A( asn1_named_data **head );
extern void asn1_free_named_data_list_B( asn1_named_data **head );

extern asn1_named_data *asn1_find_named_data_A( asn1_named_data *list,
                                       const char *oid, size_t len );
extern asn1_named_data *asn1_find_named_data_B( asn1_named_data *list,
                                       const char *oid, size_t len );

extern int asn1_write_len_A( unsigned char **p, unsigned char *start, size_t len );
extern int asn1_write_len_B( unsigned char **p, unsigned char *start, size_t len );

extern int asn1_write_tag_A( unsigned char **p, unsigned char *start, unsigned char tag );
extern int asn1_write_tag_B( unsigned char **p, unsigned char *start, unsigned char tag );

extern int asn1_write_raw_buffer_A( unsigned char **p, unsigned char *start,
                           const unsigned char *buf, size_t size );
extern int asn1_write_raw_buffer_B( unsigned char **p, unsigned char *start,
                           const unsigned char *buf, size_t size );

extern int asn1_write_mpi_A( unsigned char **p, unsigned char *start, mpi *X );
extern int asn1_write_mpi_B( unsigned char **p, unsigned char *start, mpi *X );


extern int asn1_write_null_A( unsigned char **p, unsigned char *start );
extern int asn1_write_null_B( unsigned char **p, unsigned char *start );

extern int asn1_write_oid_A( unsigned char **p, unsigned char *start,
                    const char *oid, size_t oid_len );
extern int asn1_write_oid_B( unsigned char **p, unsigned char *start,
                    const char *oid, size_t oid_len );

extern int asn1_write_algorithm_identifier_A( unsigned char **p, unsigned char *start,
                                     const char *oid, size_t oid_len,
                                     size_t par_len );
extern int asn1_write_algorithm_identifier_B( unsigned char **p, unsigned char *start,
                                     const char *oid, size_t oid_len,
                                     size_t par_len );

extern int asn1_write_bool_A( unsigned char **p, unsigned char *start, int boolean );
extern int asn1_write_bool_B( unsigned char **p, unsigned char *start, int boolean );

extern int asn1_write_int_A( unsigned char **p, unsigned char *start, int val );
extern int asn1_write_int_B( unsigned char **p, unsigned char *start, int val );

extern int asn1_write_printable_string_A( unsigned char **p, unsigned char *start,
                                 const char *text, size_t text_len );
extern int asn1_write_printable_string_B( unsigned char **p, unsigned char *start,
                                 const char *text, size_t text_len );

extern int asn1_write_ia5_string_A( unsigned char **p, unsigned char *start,
                           const char *text, size_t text_len );
extern int asn1_write_ia5_string_B( unsigned char **p, unsigned char *start,
                           const char *text, size_t text_len );

extern int asn1_write_bitstring_A( unsigned char **p, unsigned char *start,
                          const unsigned char *buf, size_t bits );
extern int asn1_write_bitstring_B( unsigned char **p, unsigned char *start,
                          const unsigned char *buf, size_t bits );

extern int asn1_write_octet_string_A( unsigned char **p, unsigned char *start,
                             const unsigned char *buf, size_t size );
extern int asn1_write_octet_string_B( unsigned char **p, unsigned char *start,
                             const unsigned char *buf, size_t size );

extern asn1_named_data *asn1_store_named_data_A( asn1_named_data **head,
                                        const char *oid, size_t oid_len,
                                        const unsigned char *val,
                                        size_t val_len );
extern asn1_named_data *asn1_store_named_data_B( asn1_named_data **head,
                                        const char *oid, size_t oid_len,
                                        const unsigned char *val,
                                        size_t val_len );

extern int base64_encode_A( unsigned char *dst, size_t *dlen,
                   const unsigned char *src, size_t slen );
extern int base64_encode_B( unsigned char *dst, size_t *dlen,
                   const unsigned char *src, size_t slen );

extern int base64_decode_A( unsigned char *dst, size_t *dlen,
                   const unsigned char *src, size_t slen );
extern int base64_decode_B( unsigned char *dst, size_t *dlen,
                   const unsigned char *src, size_t slen );

extern void mpi_init_A( mpi *X );
extern void mpi_init_B( mpi *X );

extern void mpi_free_A( mpi *X );
extern void mpi_free_B( mpi *X );

extern int mpi_grow_A( mpi *X, size_t nblimbs );
extern int mpi_grow_B( mpi *X, size_t nblimbs );

extern int mpi_shrink_A( mpi *X, size_t nblimbs );
extern int mpi_shrink_B( mpi *X, size_t nblimbs );

extern int mpi_copy_A( mpi *X, const mpi *Y );
extern int mpi_copy_B( mpi *X, const mpi *Y );

extern void mpi_swap_A( mpi *X, mpi *Y );
extern void mpi_swap_B( mpi *X, mpi *Y );

extern int mpi_safe_cond_assign_A( mpi *X, const mpi *Y, unsigned char assign );
extern int mpi_safe_cond_assign_B( mpi *X, const mpi *Y, unsigned char assign );

extern int mpi_safe_cond_swap_A( mpi *X, mpi *Y, unsigned char swap );
extern int mpi_safe_cond_swap_B( mpi *X, mpi *Y, unsigned char swap );

extern int mpi_lset_A( mpi *X, t_sint z );
extern int mpi_lset_B( mpi *X, t_sint z );

extern int mpi_get_bit_A( const mpi *X, size_t pos );
extern int mpi_get_bit_B( const mpi *X, size_t pos );

extern int mpi_set_bit_A( mpi *X, size_t pos, unsigned char val );
extern int mpi_set_bit_B( mpi *X, size_t pos, unsigned char val );

extern size_t mpi_lsb_A( const mpi *X );
extern size_t mpi_lsb_B( const mpi *X );

extern size_t mpi_msb_A( const mpi *X );
extern size_t mpi_msb_B( const mpi *X );

extern size_t mpi_size_A( const mpi *X );
extern size_t mpi_size_B( const mpi *X );

extern int mpi_read_binary_A( mpi *X, const unsigned char *buf, size_t buflen );
extern int mpi_read_binary_B( mpi *X, const unsigned char *buf, size_t buflen );

extern int mpi_write_binary_A( const mpi *X, unsigned char *buf, size_t buflen );
extern int mpi_write_binary_B( const mpi *X, unsigned char *buf, size_t buflen );

extern int mpi_shift_l_A( mpi *X, size_t count );
extern int mpi_shift_l_B( mpi *X, size_t count );

extern int mpi_shift_r_A( mpi *X, size_t count );
extern int mpi_shift_r_B( mpi *X, size_t count );

extern int mpi_cmp_abs_A( const mpi *X, const mpi *Y );
extern int mpi_cmp_abs_B( const mpi *X, const mpi *Y );

extern int mpi_cmp_mpi_A( const mpi *X, const mpi *Y );
extern int mpi_cmp_mpi_B( const mpi *X, const mpi *Y );

extern int mpi_cmp_int_A( const mpi *X, t_sint z );
extern int mpi_cmp_int_B( const mpi *X, t_sint z );

extern int mpi_add_abs_A( mpi *X, const mpi *A, const mpi *B );
extern int mpi_add_abs_B( mpi *X, const mpi *A, const mpi *B );

extern int mpi_sub_abs_A( mpi *X, const mpi *A, const mpi *B );
extern int mpi_sub_abs_B( mpi *X, const mpi *A, const mpi *B );

extern int mpi_add_mpi_A( mpi *X, const mpi *A, const mpi *B );
extern int mpi_add_mpi_B( mpi *X, const mpi *A, const mpi *B );

extern int mpi_sub_mpi_A( mpi *X, const mpi *A, const mpi *B );
extern int mpi_sub_mpi_B( mpi *X, const mpi *A, const mpi *B );

extern int mpi_add_int_A( mpi *X, const mpi *A, t_sint b );
extern int mpi_add_int_B( mpi *X, const mpi *A, t_sint b );

extern int mpi_sub_int_A( mpi *X, const mpi *A, t_sint b );
extern int mpi_sub_int_B( mpi *X, const mpi *A, t_sint b );

extern int mpi_mul_mpi_A( mpi *X, const mpi *A, const mpi *B );
extern int mpi_mul_mpi_B( mpi *X, const mpi *A, const mpi *B );

extern int mpi_read_string_A( mpi *X, int radix, const char *s );
extern int mpi_read_string_B( mpi *X, int radix, const char *s );

extern int mpi_mul_int_A( mpi *X, const mpi *A, t_sint b );
extern int mpi_mul_int_B( mpi *X, const mpi *A, t_sint b );

extern int mpi_div_mpi_A( mpi *Q, mpi *R, const mpi *A, const mpi *B );
extern int mpi_div_mpi_B( mpi *Q, mpi *R, const mpi *A, const mpi *B );

extern int mpi_div_int_A( mpi *Q, mpi *R, const mpi *A, t_sint b );
extern int mpi_div_int_B( mpi *Q, mpi *R, const mpi *A, t_sint b );

extern int mpi_mod_mpi_A( mpi *R, const mpi *A, const mpi *B );
extern int mpi_mod_mpi_B( mpi *R, const mpi *A, const mpi *B );

extern int mpi_mod_int_A( t_uint *r, const mpi *A, t_sint b );
extern int mpi_mod_int_B( t_uint *r, const mpi *A, t_sint b );

extern int mpi_write_string_A( const mpi *X, int radix, char *s, size_t *slen );
extern int mpi_write_string_B( const mpi *X, int radix, char *s, size_t *slen );

extern int mpi_exp_mod_A( mpi *X, const mpi *A, const mpi *E, const mpi *N, mpi *_RR );
extern int mpi_exp_mod_B( mpi *X, const mpi *A, const mpi *E, const mpi *N, mpi *_RR );

extern int mpi_gcd_A( mpi *G, const mpi *A, const mpi *B );
extern int mpi_gcd_B( mpi *G, const mpi *A, const mpi *B );

extern int mpi_fill_random_A( mpi *X, size_t size,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );
extern int mpi_fill_random_B( mpi *X, size_t size,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );

extern int mpi_inv_mod_A( mpi *X, const mpi *A, const mpi *N );
extern int mpi_inv_mod_B( mpi *X, const mpi *A, const mpi *N );

extern int mpi_is_prime_A( mpi *X,
                  int (*f_rng)(void *, unsigned char *, size_t),
                  void *p_rng );
extern int mpi_is_prime_B( mpi *X,
                  int (*f_rng)(void *, unsigned char *, size_t),
                  void *p_rng );

extern int mpi_gen_prime_A( mpi *X, size_t nbits, int dh_flag,
                   int (*f_rng)(void *, unsigned char *, size_t),
                   void *p_rng );
extern int mpi_gen_prime_B( mpi *X, size_t nbits, int dh_flag,
                   int (*f_rng)(void *, unsigned char *, size_t),
                   void *p_rng );

extern void ctr_drbg_free_A( ctr_drbg_context *ctx );
extern void ctr_drbg_free_B( ctr_drbg_context *ctx );

extern void ctr_drbg_set_prediction_resistance_A( ctr_drbg_context *ctx, int resistance );
extern void ctr_drbg_set_prediction_resistance_B( ctr_drbg_context *ctx, int resistance );

extern void ctr_drbg_set_entropy_len_A( ctr_drbg_context *ctx, size_t len );
extern void ctr_drbg_set_entropy_len_B( ctr_drbg_context *ctx, size_t len );

extern void ctr_drbg_set_reseed_interval_A( ctr_drbg_context *ctx, int interval );
extern void ctr_drbg_set_reseed_interval_B( ctr_drbg_context *ctx, int interval );

extern void ctr_drbg_update_A( ctr_drbg_context *ctx,
                      const unsigned char *additional, size_t add_len );
extern void ctr_drbg_update_B( ctr_drbg_context *ctx,
                      const unsigned char *additional, size_t add_len );

extern int ctr_drbg_reseed_A( ctr_drbg_context *ctx,
                     const unsigned char *additional, size_t len );
extern int ctr_drbg_reseed_B( ctr_drbg_context *ctx,
                     const unsigned char *additional, size_t len );

extern int ctr_drbg_init_entropy_len_A(
                   ctr_drbg_context *ctx,
                   int (*f_entropy)(void *, unsigned char *, size_t),
                   void *p_entropy,
                   const unsigned char *custom,
                   size_t len,
                   size_t entropy_len );
extern int ctr_drbg_init_entropy_len_B(
                   ctr_drbg_context *ctx,
                   int (*f_entropy)(void *, unsigned char *, size_t),
                   void *p_entropy,
                   const unsigned char *custom,
                   size_t len,
                   size_t entropy_len );

extern int ctr_drbg_init_A( ctr_drbg_context *ctx,
                   int (*f_entropy)(void *, unsigned char *, size_t),
                   void *p_entropy,
                   const unsigned char *custom,
                   size_t len );
extern int ctr_drbg_init_B( ctr_drbg_context *ctx,
                   int (*f_entropy)(void *, unsigned char *, size_t),
                   void *p_entropy,
                   const unsigned char *custom,
                   size_t len );

extern int ctr_drbg_random_with_add_A( void *p_rng,
                              unsigned char *output, size_t output_len,
                              const unsigned char *additional, size_t add_len );
extern int ctr_drbg_random_with_add_B( void *p_rng,
                              unsigned char *output, size_t output_len,
                              const unsigned char *additional, size_t add_len );

extern int ctr_drbg_random_A( void *p_rng, unsigned char *output, size_t output_len );
extern int ctr_drbg_random_B( void *p_rng, unsigned char *output, size_t output_len );

extern void des_init_A( des_context *ctx );
extern void des_init_B( des_context *ctx );

extern void des_free_A( des_context *ctx );
extern void des_free_B( des_context *ctx );

extern void des3_init_A( des3_context *ctx );
extern void des3_init_B( des3_context *ctx );

extern void des3_free_A( des3_context *ctx );
extern void des3_free_B( des3_context *ctx );

extern void des_key_set_parity_A( unsigned char key[DES_KEY_SIZE] );
extern void des_key_set_parity_B( unsigned char key[DES_KEY_SIZE] );

extern int des_key_check_key_parity_A( const unsigned char key[DES_KEY_SIZE] );
extern int des_key_check_key_parity_B( const unsigned char key[DES_KEY_SIZE] );

extern int des_key_check_weak_A( const unsigned char key[DES_KEY_SIZE] );
extern int des_key_check_weak_B( const unsigned char key[DES_KEY_SIZE] );

extern int des_setkey_enc_A( des_context *ctx, const unsigned char key[DES_KEY_SIZE] );
extern int des_setkey_enc_B( des_context *ctx, const unsigned char key[DES_KEY_SIZE] );

extern int des_setkey_dec_A( des_context *ctx, const unsigned char key[DES_KEY_SIZE] );
extern int des_setkey_dec_B( des_context *ctx, const unsigned char key[DES_KEY_SIZE] );

extern int des3_set2key_enc_A( des3_context *ctx,
                      const unsigned char key[DES_KEY_SIZE * 2] );
extern int des3_set2key_enc_B( des3_context *ctx,
                      const unsigned char key[DES_KEY_SIZE * 2] );

extern int des3_set2key_dec_A( des3_context *ctx,
                      const unsigned char key[DES_KEY_SIZE * 2] );
extern int des3_set2key_dec_B( des3_context *ctx,
                      const unsigned char key[DES_KEY_SIZE * 2] );

extern int des3_set3key_enc_A( des3_context *ctx,
                      const unsigned char key[DES_KEY_SIZE * 3] );
extern int des3_set3key_enc_B( des3_context *ctx,
                      const unsigned char key[DES_KEY_SIZE * 3] );

extern int des3_set3key_dec_A( des3_context *ctx,
                      const unsigned char key[DES_KEY_SIZE * 3] );
extern int des3_set3key_dec_B( des3_context *ctx,
                      const unsigned char key[DES_KEY_SIZE * 3] );

extern int des_crypt_ecb_A( des_context *ctx,
                    const unsigned char input[8],
                    unsigned char output[8] );
extern int des_crypt_ecb_B( des_context *ctx,
                    const unsigned char input[8],
                    unsigned char output[8] );

extern int des_crypt_cbc_A( des_context *ctx,
                    int mode,
                    size_t length,
                    unsigned char iv[8],
                    const unsigned char *input,
                    unsigned char *output );
extern int des_crypt_cbc_B( des_context *ctx,
                    int mode,
                    size_t length,
                    unsigned char iv[8],
                    const unsigned char *input,
                    unsigned char *output );

extern int des3_crypt_ecb_A( des3_context *ctx,
                     const unsigned char input[8],
                     unsigned char output[8] );
extern int des3_crypt_ecb_B( des3_context *ctx,
                     const unsigned char input[8],
                     unsigned char output[8] );

extern int des3_crypt_cbc_A( des3_context *ctx,
                     int mode,
                     size_t length,
                     unsigned char iv[8],
                     const unsigned char *input,
                     unsigned char *output );
extern int des3_crypt_cbc_B( des3_context *ctx,
                     int mode,
                     size_t length,
                     unsigned char iv[8],
                     const unsigned char *input,
                     unsigned char *output );

extern void dhm_init_A( dhm_context *ctx );
extern void dhm_init_B( dhm_context *ctx );

extern int dhm_read_params_A( dhm_context *ctx,
                     unsigned char **p,
                     const unsigned char *end );
extern int dhm_read_params_B( dhm_context *ctx,
                     unsigned char **p,
                     const unsigned char *end );

extern int dhm_make_params_A( dhm_context *ctx, int x_size,
                     unsigned char *output, size_t *olen,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );
extern int dhm_make_params_B( dhm_context *ctx, int x_size,
                     unsigned char *output, size_t *olen,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );

extern int dhm_read_public_A( dhm_context *ctx,
                     const unsigned char *input, size_t ilen );
extern int dhm_read_public_B( dhm_context *ctx,
                     const unsigned char *input, size_t ilen );

extern int dhm_make_public_A( dhm_context *ctx, int x_size,
                     unsigned char *output, size_t olen,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );
extern int dhm_make_public_B( dhm_context *ctx, int x_size,
                     unsigned char *output, size_t olen,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );

extern int dhm_calc_secret_A( dhm_context *ctx,
                     unsigned char *output, size_t *olen,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );
extern int dhm_calc_secret_B( dhm_context *ctx,
                     unsigned char *output, size_t *olen,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );

extern void dhm_free_A( dhm_context *ctx );
extern void dhm_free_B( dhm_context *ctx );

extern int dhm_parse_dhm_A( dhm_context *dhm, const unsigned char *dhmin,
                   size_t dhminlen );
extern int dhm_parse_dhm_B( dhm_context *dhm, const unsigned char *dhmin,
                   size_t dhminlen );

extern int ecdh_gen_public_A( ecp_group *grp, mpi *d, ecp_point *Q,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );
extern int ecdh_gen_public_B( ecp_group *grp, mpi *d, ecp_point *Q,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );

extern int ecdh_compute_shared_A( ecp_group *grp, mpi *z,
                         const ecp_point *Q, const mpi *d,
                         int (*f_rng)(void *, unsigned char *, size_t),
                         void *p_rng );
extern int ecdh_compute_shared_B( ecp_group *grp, mpi *z,
                         const ecp_point *Q, const mpi *d,
                         int (*f_rng)(void *, unsigned char *, size_t),
                         void *p_rng );

extern void ecdh_init_A( ecdh_context *ctx );
extern void ecdh_init_B( ecdh_context *ctx );

extern void ecdh_free_A( ecdh_context *ctx );
extern void ecdh_free_B( ecdh_context *ctx );

extern int ecdh_make_params_A( ecdh_context *ctx, size_t *olen,
                      unsigned char *buf, size_t blen,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng );
extern int ecdh_make_params_B( ecdh_context *ctx, size_t *olen,
                      unsigned char *buf, size_t blen,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng );

extern int ecdh_read_params_A( ecdh_context *ctx,
                      const unsigned char **buf, const unsigned char *end );
extern int ecdh_read_params_B( ecdh_context *ctx,
                      const unsigned char **buf, const unsigned char *end );

extern int ecdh_get_params_A( ecdh_context *ctx, const ecp_keypair *key,
                     ecdh_side side );
extern int ecdh_get_params_B( ecdh_context *ctx, const ecp_keypair *key,
                     ecdh_side side );

extern int ecdh_make_public_A( ecdh_context *ctx, size_t *olen,
                      unsigned char *buf, size_t blen,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng );
extern int ecdh_make_public_B( ecdh_context *ctx, size_t *olen,
                      unsigned char *buf, size_t blen,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng );

extern int ecdh_read_public_A( ecdh_context *ctx,
                      const unsigned char *buf, size_t blen );
extern int ecdh_read_public_B( ecdh_context *ctx,
                      const unsigned char *buf, size_t blen );

extern int ecdh_calc_secret_A( ecdh_context *ctx, size_t *olen,
                      unsigned char *buf, size_t blen,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng );
extern int ecdh_calc_secret_B( ecdh_context *ctx, size_t *olen,
                      unsigned char *buf, size_t blen,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng );

extern int ecdsa_sign_A( ecp_group *grp, mpi *r, mpi *s,
                const mpi *d, const unsigned char *buf, size_t blen,
                int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );
extern int ecdsa_sign_B( ecp_group *grp, mpi *r, mpi *s,
                const mpi *d, const unsigned char *buf, size_t blen,
                int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );

extern int ecdsa_sign_det_A( ecp_group *grp, mpi *r, mpi *s,
                    const mpi *d, const unsigned char *buf, size_t blen,
                    md_type_t md_alg );
extern int ecdsa_sign_det_B( ecp_group *grp, mpi *r, mpi *s,
                    const mpi *d, const unsigned char *buf, size_t blen,
                    md_type_t md_alg );

extern int ecdsa_verify_A( ecp_group *grp,
                  const unsigned char *buf, size_t blen,
                  const ecp_point *Q, const mpi *r, const mpi *s);
extern int ecdsa_verify_B( ecp_group *grp,
                  const unsigned char *buf, size_t blen,
                  const ecp_point *Q, const mpi *r, const mpi *s);

extern int ecdsa_write_signature_A( ecdsa_context *ctx,
                           const unsigned char *hash, size_t hlen,
                           unsigned char *sig, size_t *slen,
                           int (*f_rng)(void *, unsigned char *, size_t),
                           void *p_rng );
extern int ecdsa_write_signature_B( ecdsa_context *ctx,
                           const unsigned char *hash, size_t hlen,
                           unsigned char *sig, size_t *slen,
                           int (*f_rng)(void *, unsigned char *, size_t),
                           void *p_rng );

extern int ecdsa_write_signature_det_A( ecdsa_context *ctx,
                               const unsigned char *hash, size_t hlen,
                               unsigned char *sig, size_t *slen,
                               md_type_t md_alg );
extern int ecdsa_write_signature_det_B( ecdsa_context *ctx,
                               const unsigned char *hash, size_t hlen,
                               unsigned char *sig, size_t *slen,
                               md_type_t md_alg );

extern int ecdsa_read_signature_A( ecdsa_context *ctx,
                          const unsigned char *hash, size_t hlen,
                          const unsigned char *sig, size_t slen );
extern int ecdsa_read_signature_B( ecdsa_context *ctx,
                          const unsigned char *hash, size_t hlen,
                          const unsigned char *sig, size_t slen );

extern int ecdsa_genkey_A( ecdsa_context *ctx, ecp_group_id gid,
                  int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );
extern int ecdsa_genkey_B( ecdsa_context *ctx, ecp_group_id gid,
                  int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );

extern void ecdsa_init_A( ecdsa_context *ctx );
extern void ecdsa_init_B( ecdsa_context *ctx );

extern void ecdsa_free_A( ecdsa_context *ctx );
extern void ecdsa_free_B( ecdsa_context *ctx );

extern int ecdsa_from_keypair_A( ecdsa_context *ctx, const ecp_keypair *key );
extern int ecdsa_from_keypair_B( ecdsa_context *ctx, const ecp_keypair *key );

extern const ecp_curve_info *ecp_curve_list_A( void );
extern const ecp_curve_info *ecp_curve_list_B( void );

extern const ecp_curve_info *ecp_curve_info_from_grp_id_A( ecp_group_id grp_id );
extern const ecp_curve_info *ecp_curve_info_from_grp_id_B( ecp_group_id grp_id );

extern const ecp_curve_info *ecp_curve_info_from_tls_id_A( uint16_t tls_id );
extern const ecp_curve_info *ecp_curve_info_from_tls_id_B( uint16_t tls_id );

extern const ecp_curve_info *ecp_curve_info_from_name_A( const char *name );
extern const ecp_curve_info *ecp_curve_info_from_name_B( const char *name );

extern void ecp_point_init_A( ecp_point *pt );
extern void ecp_point_init_B( ecp_point *pt );

extern void ecp_group_init_A( ecp_group *grp );
extern void ecp_group_init_B( ecp_group *grp );

extern void ecp_keypair_init_A( ecp_keypair *key );
extern void ecp_keypair_init_B( ecp_keypair *key );

extern void ecp_point_free_A( ecp_point *pt );
extern void ecp_point_free_B( ecp_point *pt );

extern void ecp_group_free_A( ecp_group *grp );
extern void ecp_group_free_B( ecp_group *grp );

extern void ecp_keypair_free_A( ecp_keypair *key );
extern void ecp_keypair_free_B( ecp_keypair *key );

extern int ecp_copy_A( ecp_point *P, const ecp_point *Q );
extern int ecp_copy_B( ecp_point *P, const ecp_point *Q );

extern int ecp_group_copy_A( ecp_group *dst, const ecp_group *src );
extern int ecp_group_copy_B( ecp_group *dst, const ecp_group *src );

extern int ecp_set_zero_A( ecp_point *pt );
extern int ecp_set_zero_B( ecp_point *pt );

extern int ecp_is_zero_A( ecp_point *pt );
extern int ecp_is_zero_B( ecp_point *pt );

extern int ecp_point_read_string_A( ecp_point *P, int radix,
                           const char *x, const char *y );
extern int ecp_point_read_string_B( ecp_point *P, int radix,
                           const char *x, const char *y );

extern int ecp_point_write_binary_A( const ecp_group *grp, const ecp_point *P,
                            int format, size_t *olen,
                            unsigned char *buf, size_t buflen );
extern int ecp_point_write_binary_B( const ecp_group *grp, const ecp_point *P,
                            int format, size_t *olen,
                            unsigned char *buf, size_t buflen );

extern int ecp_point_read_binary_A( const ecp_group *grp, ecp_point *pt,
                           const unsigned char *buf, size_t ilen );
extern int ecp_point_read_binary_B( const ecp_group *grp, ecp_point *pt,
                           const unsigned char *buf, size_t ilen );

extern int ecp_tls_read_point_A( const ecp_group *grp, ecp_point *pt,
                        const unsigned char **buf, size_t buf_len );
extern int ecp_tls_read_point_B( const ecp_group *grp, ecp_point *pt,
                        const unsigned char **buf, size_t buf_len );

extern int ecp_tls_write_point_A( const ecp_group *grp, const ecp_point *pt,
                         int format, size_t *olen,
                         unsigned char *buf, size_t blen );
extern int ecp_tls_write_point_B( const ecp_group *grp, const ecp_point *pt,
                         int format, size_t *olen,
                         unsigned char *buf, size_t blen );

extern int ecp_group_read_string_A( ecp_group *grp, int radix,
                           const char *p, const char *b,
                           const char *gx, const char *gy, const char *n);
extern int ecp_group_read_string_B( ecp_group *grp, int radix,
                           const char *p, const char *b,
                           const char *gx, const char *gy, const char *n);

extern int ecp_tls_read_group_A( ecp_group *grp, const unsigned char **buf, size_t len );
extern int ecp_tls_read_group_B( ecp_group *grp, const unsigned char **buf, size_t len );

extern int ecp_tls_write_group_A( const ecp_group *grp, size_t *olen,
                         unsigned char *buf, size_t blen );
extern int ecp_tls_write_group_B( const ecp_group *grp, size_t *olen,
                         unsigned char *buf, size_t blen );

extern int ecp_add_A( const ecp_group *grp, ecp_point *R,
             const ecp_point *P, const ecp_point *Q );
extern int ecp_add_B( const ecp_group *grp, ecp_point *R,
             const ecp_point *P, const ecp_point *Q );

extern int ecp_sub_A( const ecp_group *grp, ecp_point *R,
             const ecp_point *P, const ecp_point *Q );
extern int ecp_sub_B( const ecp_group *grp, ecp_point *R,
             const ecp_point *P, const ecp_point *Q );

extern int ecp_check_pubkey_A( const ecp_group *grp, const ecp_point *pt );
extern int ecp_check_pubkey_B( const ecp_group *grp, const ecp_point *pt );

extern int ecp_check_privkey_A( const ecp_group *grp, const mpi *d );
extern int ecp_check_privkey_B( const ecp_group *grp, const mpi *d );

extern int ecp_mul_A( ecp_group *grp, ecp_point *R,
             const mpi *m, const ecp_point *P,
             int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );
extern int ecp_mul_B( ecp_group *grp, ecp_point *R,
             const mpi *m, const ecp_point *P,
             int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );

extern int ecp_gen_keypair_A( ecp_group *grp, mpi *d, ecp_point *Q,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );
extern int ecp_gen_keypair_B( ecp_group *grp, mpi *d, ecp_point *Q,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng );

extern int ecp_gen_key_A( ecp_group_id grp_id, ecp_keypair *key,
                int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );
extern int ecp_gen_key_B( ecp_group_id grp_id, ecp_keypair *key,
                int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );

extern int ecp_use_known_dp_A( ecp_group *grp, ecp_group_id id );
extern int ecp_use_known_dp_B( ecp_group *grp, ecp_group_id id );

extern void hmac_drbg_update_A( hmac_drbg_context *ctx,
                       const unsigned char *additional, size_t add_len );
extern void hmac_drbg_update_B( hmac_drbg_context *ctx,
                       const unsigned char *additional, size_t add_len );

extern int hmac_drbg_init_buf_A( hmac_drbg_context *ctx,
                        const md_info_t * md_info,
                        const unsigned char *data, size_t data_len );
extern int hmac_drbg_init_buf_B( hmac_drbg_context *ctx,
                        const md_info_t * md_info,
                        const unsigned char *data, size_t data_len );

extern int hmac_drbg_reseed_A( hmac_drbg_context *ctx,
                      const unsigned char *additional, size_t len );
extern int hmac_drbg_reseed_B( hmac_drbg_context *ctx,
                      const unsigned char *additional, size_t len );

extern int hmac_drbg_init_A( hmac_drbg_context *ctx,
                    const md_info_t * md_info,
                    int (*f_entropy)(void *, unsigned char *, size_t),
                    void *p_entropy,
                    const unsigned char *custom,
                    size_t len );
extern int hmac_drbg_init_B( hmac_drbg_context *ctx,
                    const md_info_t * md_info,
                    int (*f_entropy)(void *, unsigned char *, size_t),
                    void *p_entropy,
                    const unsigned char *custom,
                    size_t len );

extern void hmac_drbg_set_prediction_resistance_A( hmac_drbg_context *ctx,
                                          int resistance );
extern void hmac_drbg_set_prediction_resistance_B( hmac_drbg_context *ctx,
                                          int resistance );

extern void hmac_drbg_set_entropy_len_A( hmac_drbg_context *ctx, size_t len );
extern void hmac_drbg_set_entropy_len_B( hmac_drbg_context *ctx, size_t len );

extern void hmac_drbg_set_reseed_interval_A( hmac_drbg_context *ctx, int interval );
extern void hmac_drbg_set_reseed_interval_B( hmac_drbg_context *ctx, int interval );

extern int hmac_drbg_random_with_add_A( void *p_rng,
                               unsigned char *output, size_t out_len,
                               const unsigned char *additional, size_t add_len );
extern int hmac_drbg_random_with_add_B( void *p_rng,
                               unsigned char *output, size_t out_len,
                               const unsigned char *additional, size_t add_len );

extern int hmac_drbg_random_A( void *p_rng, unsigned char *output, size_t out_len );
extern int hmac_drbg_random_B( void *p_rng, unsigned char *output, size_t out_len );

extern void hmac_drbg_free_A( hmac_drbg_context *ctx );
extern void hmac_drbg_free_B( hmac_drbg_context *ctx );

extern const int *md_list_A( void );
extern const int *md_list_B( void );

extern const md_info_t *md_info_from_string_A( const char *md_name );
extern const md_info_t *md_info_from_string_B( const char *md_name );

extern const md_info_t *md_info_from_type_A( md_type_t md_type );
extern const md_info_t *md_info_from_type_B( md_type_t md_type );

extern void md_init_A( md_context_t *ctx );
extern void md_init_B( md_context_t *ctx );

extern void md_free_A( md_context_t *ctx );
extern void md_free_B( md_context_t *ctx );

extern int md_init_ctx_A( md_context_t *ctx, const md_info_t *md_info );
extern int md_init_ctx_B( md_context_t *ctx, const md_info_t *md_info );

extern int md_free_ctx_A( md_context_t *ctx );
extern int md_free_ctx_B( md_context_t *ctx );

extern int md_starts_A( md_context_t *ctx );
extern int md_starts_B( md_context_t *ctx );

extern int md_update_A( md_context_t *ctx, const unsigned char *input, size_t ilen );
extern int md_update_B( md_context_t *ctx, const unsigned char *input, size_t ilen );

extern int md_finish_A( md_context_t *ctx, unsigned char *output );
extern int md_finish_B( md_context_t *ctx, unsigned char *output );

extern int md_A( const md_info_t *md_info, const unsigned char *input, size_t ilen,
            unsigned char *output );
extern int md_B( const md_info_t *md_info, const unsigned char *input, size_t ilen,
            unsigned char *output );

extern int md_file_A( const md_info_t *md_info, const char *path, unsigned char *output );
extern int md_file_B( const md_info_t *md_info, const char *path, unsigned char *output );

extern int md_hmac_starts_A( md_context_t *ctx, const unsigned char *key, size_t keylen );
extern int md_hmac_starts_B( md_context_t *ctx, const unsigned char *key, size_t keylen );

extern int md_hmac_update_A( md_context_t *ctx, const unsigned char *input, size_t ilen );
extern int md_hmac_update_B( md_context_t *ctx, const unsigned char *input, size_t ilen );

extern int md_hmac_finish_A( md_context_t *ctx, unsigned char *output );
extern int md_hmac_finish_B( md_context_t *ctx, unsigned char *output );

extern int md_hmac_reset_A( md_context_t *ctx );
extern int md_hmac_reset_B( md_context_t *ctx );

extern int md_hmac_A( const md_info_t *md_info, const unsigned char *key, size_t keylen,
                const unsigned char *input, size_t ilen,
                unsigned char *output );
extern int md_hmac_B( const md_info_t *md_info, const unsigned char *key, size_t keylen,
                const unsigned char *input, size_t ilen,
                unsigned char *output );

extern int md_process_A( md_context_t *ctx, const unsigned char *data );
extern int md_process_B( md_context_t *ctx, const unsigned char *data );

extern void md5_init_A( md5_context *ctx );
extern void md5_init_B( md5_context *ctx );

extern void md5_free_A( md5_context *ctx );
extern void md5_free_B( md5_context *ctx );

extern void md5_starts_A( md5_context *ctx );
extern void md5_starts_B( md5_context *ctx );

extern void md5_process_A( md5_context *ctx, const unsigned char data[64] );
extern void md5_process_B( md5_context *ctx, const unsigned char data[64] );

extern void md5_update_A( md5_context *ctx, const unsigned char *input, size_t ilen );
extern void md5_update_B( md5_context *ctx, const unsigned char *input, size_t ilen );

extern void md5_finish_A( md5_context *ctx, unsigned char output[16] );
extern void md5_finish_B( md5_context *ctx, unsigned char output[16] );

extern void md5_A( const unsigned char *input, size_t ilen, unsigned char output[16] );
extern void md5_B( const unsigned char *input, size_t ilen, unsigned char output[16] );

extern void md5_hmac_starts_A( md5_context *ctx, const unsigned char *key,
                      size_t keylen );
extern void md5_hmac_starts_B( md5_context *ctx, const unsigned char *key,
                      size_t keylen );

extern void md5_hmac_update_A( md5_context *ctx, const unsigned char *input,
                      size_t ilen );
extern void md5_hmac_update_B( md5_context *ctx, const unsigned char *input,
                      size_t ilen );

extern void md5_hmac_finish_A( md5_context *ctx, unsigned char output[16] );
extern void md5_hmac_finish_B( md5_context *ctx, unsigned char output[16] );

extern void md5_hmac_reset_A( md5_context *ctx );
extern void md5_hmac_reset_B( md5_context *ctx );

extern void md5_hmac_A( const unsigned char *key, size_t keylen,
               const unsigned char *input, size_t ilen,
               unsigned char output[16] );
extern void md5_hmac_B( const unsigned char *key, size_t keylen,
               const unsigned char *input, size_t ilen,
               unsigned char output[16] );

extern int oid_get_attr_short_name_A( const asn1_buf *oid, const char ** short_name );
extern int oid_get_attr_short_name_B( const asn1_buf *oid, const char ** short_name );

extern int oid_get_x509_ext_type_A( const asn1_buf *oid, int *ext_type );
extern int oid_get_x509_ext_type_B( const asn1_buf *oid, int *ext_type );

extern int oid_get_extended_key_usage_A( const asn1_buf *oid, const char **description );
extern int oid_get_extended_key_usage_B( const asn1_buf *oid, const char **description );

extern int oid_get_sig_alg_desc_A( const asn1_buf *oid, const char **description );
extern int oid_get_sig_alg_desc_B( const asn1_buf *oid, const char **description );

extern int oid_get_sig_alg_A( const asn1_buf *oid, md_type_t *md_alg, pk_type_t *pk_alg );
extern int oid_get_sig_alg_B( const asn1_buf *oid, md_type_t *md_alg, pk_type_t *pk_alg );

extern int oid_get_oid_by_sig_alg_A( pk_type_t pk_alg, md_type_t md_alg, const char **oid , size_t *olen );
extern int oid_get_oid_by_sig_alg_B( pk_type_t pk_alg, md_type_t md_alg, const char **oid , size_t *olen );

extern int oid_get_pk_alg_A( const asn1_buf *oid, pk_type_t *pk_alg );
extern int oid_get_pk_alg_B( const asn1_buf *oid, pk_type_t *pk_alg );

extern int oid_get_oid_by_pk_alg_A( pk_type_t pk_alg, const char **oid, size_t *olen );
extern int oid_get_oid_by_pk_alg_B( pk_type_t pk_alg, const char **oid, size_t *olen );

extern int oid_get_ec_grp_A( const asn1_buf *oid, ecp_group_id *grp_id);
extern int oid_get_ec_grp_B( const asn1_buf *oid, ecp_group_id *grp_id);

extern int oid_get_oid_by_ec_grp_A( ecp_group_id grp_id, const char **oid, size_t *olen );
extern int oid_get_oid_by_ec_grp_B( ecp_group_id grp_id, const char **oid, size_t *olen );

extern int oid_get_cipher_alg_A( const asn1_buf *oid, cipher_type_t *cipher_alg );
extern int oid_get_cipher_alg_B( const asn1_buf *oid, cipher_type_t *cipher_alg );

extern int oid_get_md_alg_A( const asn1_buf *oid, md_type_t *md_alg );
extern int oid_get_md_alg_B( const asn1_buf *oid, md_type_t *md_alg );

extern int oid_get_oid_by_md_A( md_type_t  md_alg, const char **oid, size_t *olen );
extern int oid_get_oid_by_md_B( md_type_t  md_alg, const char **oid, size_t *olen );

extern int oid_get_pkcs12_pbe_alg_A( const asn1_buf *oid, md_type_t *md_alg, cipher_type_t *cipher_alg );
extern int oid_get_pkcs12_pbe_alg_B( const asn1_buf *oid, md_type_t *md_alg, cipher_type_t *cipher_alg );

extern int oid_get_numeric_string_A( char *buf, size_t size,
                            const asn1_buf *oid );
extern int oid_get_numeric_string_B( char *buf, size_t size,
                            const asn1_buf *oid );

extern void pem_init_A( pem_context *ctx );
extern void pem_init_B( pem_context *ctx );

extern int pem_read_buffer_A( pem_context *ctx, const char *header, const char *footer,
                     const unsigned char *data, const unsigned char *pwd,
                     size_t pwdlen, size_t *use_len );
extern int pem_read_buffer_B( pem_context *ctx, const char *header, const char *footer,
                     const unsigned char *data, const unsigned char *pwd,
                     size_t pwdlen, size_t *use_len );

extern void pem_free_A( pem_context *ctx );
extern void pem_free_B( pem_context *ctx );


extern int pem_write_buffer_A( const char *header, const char *footer,
                      const unsigned char *der_data, size_t der_len,
                      unsigned char *buf, size_t buf_len, size_t *olen );
extern int pem_write_buffer_B( const char *header, const char *footer,
                      const unsigned char *der_data, size_t der_len,
                      unsigned char *buf, size_t buf_len, size_t *olen );

extern void pk_init_A( pk_context *ctx );
extern void pk_init_B( pk_context *ctx );

extern void pk_free_A( pk_context *ctx );
extern void pk_free_B( pk_context *ctx );

extern const pk_info_t * pk_info_from_type_A( pk_type_t pk_type );
extern const pk_info_t * pk_info_from_type_B( pk_type_t pk_type );

extern int pk_init_ctx_A( pk_context *ctx, const pk_info_t *info );
extern int pk_init_ctx_B( pk_context *ctx, const pk_info_t *info );

extern int pk_init_ctx_rsa_alt_A( pk_context *ctx, void * key,
                         pk_rsa_alt_decrypt_func decrypt_func,
                         pk_rsa_alt_sign_func sign_func,
                         pk_rsa_alt_key_len_func key_len_func );
extern int pk_init_ctx_rsa_alt_B( pk_context *ctx, void * key,
                         pk_rsa_alt_decrypt_func decrypt_func,
                         pk_rsa_alt_sign_func sign_func,
                         pk_rsa_alt_key_len_func key_len_func );

extern int pk_can_do_A( pk_context *ctx, pk_type_t type );
extern int pk_can_do_B( pk_context *ctx, pk_type_t type );

extern int pk_verify_A( pk_context *ctx, md_type_t md_alg,
               const unsigned char *hash, size_t hash_len,
               const unsigned char *sig, size_t sig_len );
extern int pk_verify_B( pk_context *ctx, md_type_t md_alg,
               const unsigned char *hash, size_t hash_len,
               const unsigned char *sig, size_t sig_len );

extern int pk_verify_ext_A( pk_type_t type, const void *options,
                   pk_context *ctx, md_type_t md_alg,
                   const unsigned char *hash, size_t hash_len,
                   const unsigned char *sig, size_t sig_len );
extern int pk_verify_ext_B( pk_type_t type, const void *options,
                   pk_context *ctx, md_type_t md_alg,
                   const unsigned char *hash, size_t hash_len,
                   const unsigned char *sig, size_t sig_len );

extern int pk_sign_A( pk_context *ctx, md_type_t md_alg,
             const unsigned char *hash, size_t hash_len,
             unsigned char *sig, size_t *sig_len,
             int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );
extern int pk_sign_B( pk_context *ctx, md_type_t md_alg,
             const unsigned char *hash, size_t hash_len,
             unsigned char *sig, size_t *sig_len,
             int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );

extern int pk_decrypt_A( pk_context *ctx,
                const unsigned char *input, size_t ilen,
                unsigned char *output, size_t *olen, size_t osize,
                int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );
extern int pk_decrypt_B( pk_context *ctx,
                const unsigned char *input, size_t ilen,
                unsigned char *output, size_t *olen, size_t osize,
                int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );

extern int pk_encrypt_A( pk_context *ctx,
                const unsigned char *input, size_t ilen,
                unsigned char *output, size_t *olen, size_t osize,
                int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );
extern int pk_encrypt_B( pk_context *ctx,
                const unsigned char *input, size_t ilen,
                unsigned char *output, size_t *olen, size_t osize,
                int (*f_rng)(void *, unsigned char *, size_t), void *p_rng );

extern size_t pk_get_size_A( const pk_context *ctx );
extern size_t pk_get_size_B( const pk_context *ctx );

extern int pk_debug_A( const pk_context *ctx, pk_debug_item *items );
extern int pk_debug_B( const pk_context *ctx, pk_debug_item *items );

extern const char * pk_get_name_A( const pk_context *ctx );
extern const char * pk_get_name_B( const pk_context *ctx );

extern pk_type_t pk_get_type_A( const pk_context *ctx );
extern pk_type_t pk_get_type_B( const pk_context *ctx );

extern int pk_write_pubkey_A( unsigned char **p, unsigned char *start,
                     const pk_context *key );
extern int pk_write_pubkey_B( unsigned char **p, unsigned char *start,
                     const pk_context *key );

extern int pk_write_pubkey_der_A( pk_context *key, unsigned char *buf, size_t size );
extern int pk_write_pubkey_der_B( pk_context *key, unsigned char *buf, size_t size );

extern int pk_write_key_der_A( pk_context *key, unsigned char *buf, size_t size );
extern int pk_write_key_der_B( pk_context *key, unsigned char *buf, size_t size );

extern int pk_write_pubkey_pem_A( pk_context *key, unsigned char *buf, size_t size );
extern int pk_write_pubkey_pem_B( pk_context *key, unsigned char *buf, size_t size );

extern int pk_write_key_pem_A( pk_context *key, unsigned char *buf, size_t size );
extern int pk_write_key_pem_B( pk_context *key, unsigned char *buf, size_t size );

extern void rsa_init_A( rsa_context *ctx,
               int padding,
               int hash_id );
extern void rsa_init_B( rsa_context *ctx,
               int padding,
               int hash_id );

extern void rsa_set_padding_A( rsa_context *ctx, int padding, int hash_id );
extern void rsa_set_padding_B( rsa_context *ctx, int padding, int hash_id );

extern int rsa_check_pubkey_A( const rsa_context *ctx );
extern int rsa_check_pubkey_B( const rsa_context *ctx );

extern int rsa_check_privkey_A( const rsa_context *ctx );
extern int rsa_check_privkey_B( const rsa_context *ctx );

extern int rsa_public_A( rsa_context *ctx,
                const unsigned char *input,
                unsigned char *output );
extern int rsa_public_B( rsa_context *ctx,
                const unsigned char *input,
                unsigned char *output );

extern int rsa_private_A( rsa_context *ctx,
                 int (*f_rng)(void *, unsigned char *, size_t),
                 void *p_rng,
                 const unsigned char *input,
                 unsigned char *output );
extern int rsa_private_B( rsa_context *ctx,
                 int (*f_rng)(void *, unsigned char *, size_t),
                 void *p_rng,
                 const unsigned char *input,
                 unsigned char *output );

extern int rsa_rsaes_oaep_encrypt_A( rsa_context *ctx,
                            int (*f_rng)(void *, unsigned char *, size_t),
                            void *p_rng,
                            int mode,
                            const unsigned char *label, size_t label_len,
                            size_t ilen,
                            const unsigned char *input,
                            unsigned char *output );
extern int rsa_rsaes_oaep_encrypt_B( rsa_context *ctx,
                            int (*f_rng)(void *, unsigned char *, size_t),
                            void *p_rng,
                            int mode,
                            const unsigned char *label, size_t label_len,
                            size_t ilen,
                            const unsigned char *input,
                            unsigned char *output );

extern int rsa_rsaes_pkcs1_v15_encrypt_A( rsa_context *ctx,
                                 int (*f_rng)(void *, unsigned char *, size_t),
                                 void *p_rng,
                                 int mode, size_t ilen,
                                 const unsigned char *input,
                                 unsigned char *output );
extern int rsa_rsaes_pkcs1_v15_encrypt_B( rsa_context *ctx,
                                 int (*f_rng)(void *, unsigned char *, size_t),
                                 void *p_rng,
                                 int mode, size_t ilen,
                                 const unsigned char *input,
                                 unsigned char *output );

extern int rsa_pkcs1_encrypt_A( rsa_context *ctx,
                       int (*f_rng)(void *, unsigned char *, size_t),
                       void *p_rng,
                       int mode, size_t ilen,
                       const unsigned char *input,
                       unsigned char *output );
extern int rsa_pkcs1_encrypt_B( rsa_context *ctx,
                       int (*f_rng)(void *, unsigned char *, size_t),
                       void *p_rng,
                       int mode, size_t ilen,
                       const unsigned char *input,
                       unsigned char *output );

extern int rsa_rsaes_oaep_decrypt_A( rsa_context *ctx,
                            int (*f_rng)(void *, unsigned char *, size_t),
                            void *p_rng,
                            int mode,
                            const unsigned char *label, size_t label_len,
                            size_t *olen,
                            const unsigned char *input,
                            unsigned char *output,
                            size_t output_max_len );
extern int rsa_rsaes_oaep_decrypt_B( rsa_context *ctx,
                            int (*f_rng)(void *, unsigned char *, size_t),
                            void *p_rng,
                            int mode,
                            const unsigned char *label, size_t label_len,
                            size_t *olen,
                            const unsigned char *input,
                            unsigned char *output,
                            size_t output_max_len );

extern int rsa_rsaes_pkcs1_v15_decrypt_A( rsa_context *ctx,
                                 int (*f_rng)(void *, unsigned char *, size_t),
                                 void *p_rng,
                                 int mode, size_t *olen,
                                 const unsigned char *input,
                                 unsigned char *output,
                                 size_t output_max_len);
extern int rsa_rsaes_pkcs1_v15_decrypt_B( rsa_context *ctx,
                                 int (*f_rng)(void *, unsigned char *, size_t),
                                 void *p_rng,
                                 int mode, size_t *olen,
                                 const unsigned char *input,
                                 unsigned char *output,
                                 size_t output_max_len);

extern int rsa_pkcs1_decrypt_A( rsa_context *ctx,
                       int (*f_rng)(void *, unsigned char *, size_t),
                       void *p_rng,
                       int mode, size_t *olen,
                       const unsigned char *input,
                       unsigned char *output,
                       size_t output_max_len);
extern int rsa_pkcs1_decrypt_B( rsa_context *ctx,
                       int (*f_rng)(void *, unsigned char *, size_t),
                       void *p_rng,
                       int mode, size_t *olen,
                       const unsigned char *input,
                       unsigned char *output,
                       size_t output_max_len);

extern int rsa_rsassa_pss_sign_A( rsa_context *ctx,
                         int (*f_rng)(void *, unsigned char *, size_t),
                         void *p_rng,
                         int mode,
                         md_type_t md_alg,
                         unsigned int hashlen,
                         const unsigned char *hash,
                         unsigned char *sig );
extern int rsa_rsassa_pss_sign_B( rsa_context *ctx,
                         int (*f_rng)(void *, unsigned char *, size_t),
                         void *p_rng,
                         int mode,
                         md_type_t md_alg,
                         unsigned int hashlen,
                         const unsigned char *hash,
                         unsigned char *sig );

extern int rsa_rsassa_pkcs1_v15_sign_A( rsa_context *ctx,
                               int (*f_rng)(void *, unsigned char *, size_t),
                               void *p_rng,
                               int mode,
                               md_type_t md_alg,
                               unsigned int hashlen,
                               const unsigned char *hash,
                               unsigned char *sig );
extern int rsa_rsassa_pkcs1_v15_sign_B( rsa_context *ctx,
                               int (*f_rng)(void *, unsigned char *, size_t),
                               void *p_rng,
                               int mode,
                               md_type_t md_alg,
                               unsigned int hashlen,
                               const unsigned char *hash,
                               unsigned char *sig );

extern int rsa_pkcs1_sign_A( rsa_context *ctx,
                    int (*f_rng)(void *, unsigned char *, size_t),
                    void *p_rng,
                    int mode,
                    md_type_t md_alg,
                    unsigned int hashlen,
                    const unsigned char *hash,
                    unsigned char *sig );
extern int rsa_pkcs1_sign_B( rsa_context *ctx,
                    int (*f_rng)(void *, unsigned char *, size_t),
                    void *p_rng,
                    int mode,
                    md_type_t md_alg,
                    unsigned int hashlen,
                    const unsigned char *hash,
                    unsigned char *sig );

extern int rsa_rsassa_pss_verify_ext_A( rsa_context *ctx,
                               int (*f_rng)(void *, unsigned char *, size_t),
                               void *p_rng,
                               int mode,
                               md_type_t md_alg,
                               unsigned int hashlen,
                               const unsigned char *hash,
                               md_type_t mgf1_hash_id,
                               int expected_salt_len,
                               const unsigned char *sig );
extern int rsa_rsassa_pss_verify_ext_B( rsa_context *ctx,
                               int (*f_rng)(void *, unsigned char *, size_t),
                               void *p_rng,
                               int mode,
                               md_type_t md_alg,
                               unsigned int hashlen,
                               const unsigned char *hash,
                               md_type_t mgf1_hash_id,
                               int expected_salt_len,
                               const unsigned char *sig );

extern int rsa_rsassa_pss_verify_A( rsa_context *ctx,
                           int (*f_rng)(void *, unsigned char *, size_t),
                           void *p_rng,
                           int mode,
                           md_type_t md_alg,
                           unsigned int hashlen,
                           const unsigned char *hash,
                           const unsigned char *sig );
extern int rsa_rsassa_pss_verify_B( rsa_context *ctx,
                           int (*f_rng)(void *, unsigned char *, size_t),
                           void *p_rng,
                           int mode,
                           md_type_t md_alg,
                           unsigned int hashlen,
                           const unsigned char *hash,
                           const unsigned char *sig );

extern int rsa_rsassa_pkcs1_v15_verify_A( rsa_context *ctx,
                                 int (*f_rng)(void *, unsigned char *, size_t),
                                 void *p_rng,
                                 int mode,
                                 md_type_t md_alg,
                                 unsigned int hashlen,
                                 const unsigned char *hash,
                                 const unsigned char *sig );
extern int rsa_rsassa_pkcs1_v15_verify_B( rsa_context *ctx,
                                 int (*f_rng)(void *, unsigned char *, size_t),
                                 void *p_rng,
                                 int mode,
                                 md_type_t md_alg,
                                 unsigned int hashlen,
                                 const unsigned char *hash,
                                 const unsigned char *sig );

extern int rsa_pkcs1_verify_A( rsa_context *ctx,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng,
                      int mode,
                      md_type_t md_alg,
                      unsigned int hashlen,
                      const unsigned char *hash,
                      const unsigned char *sig );
extern int rsa_pkcs1_verify_B( rsa_context *ctx,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng,
                      int mode,
                      md_type_t md_alg,
                      unsigned int hashlen,
                      const unsigned char *hash,
                      const unsigned char *sig );

extern void rsa_free_A( rsa_context *ctx );
extern void rsa_free_B( rsa_context *ctx );

extern int rsa_gen_key_A( rsa_context *ctx,
                 int (*f_rng)(void *, unsigned char *, size_t),
                 void *p_rng,
                 unsigned int nbits, int exponent );
extern int rsa_gen_key_B( rsa_context *ctx,
                 int (*f_rng)(void *, unsigned char *, size_t),
                 void *p_rng,
                 unsigned int nbits, int exponent );

extern int rsa_copy_A( rsa_context *dst, const rsa_context *src );
extern int rsa_copy_B( rsa_context *dst, const rsa_context *src );

extern void sha1_init_A( sha1_context *ctx );
extern void sha1_init_B( sha1_context *ctx );

extern void sha1_free_A( sha1_context *ctx );
extern void sha1_free_B( sha1_context *ctx );

extern void sha1_starts_A( sha1_context *ctx );
extern void sha1_starts_B( sha1_context *ctx );

extern void sha1_process_A( sha1_context *ctx, const unsigned char data[64] );
extern void sha1_process_B( sha1_context *ctx, const unsigned char data[64] );

extern void sha1_update_A( sha1_context *ctx, const unsigned char *input, size_t ilen );
extern void sha1_update_B( sha1_context *ctx, const unsigned char *input, size_t ilen );

extern void sha1_finish_A( sha1_context *ctx, unsigned char output[20] );
extern void sha1_finish_B( sha1_context *ctx, unsigned char output[20] );


extern void sha1_A( const unsigned char *input, size_t ilen, unsigned char output[20] );
extern void sha1_B( const unsigned char *input, size_t ilen, unsigned char output[20] );


extern void sha1_hmac_starts_A( sha1_context *ctx, const unsigned char *key,
                       size_t keylen );
extern void sha1_hmac_starts_B( sha1_context *ctx, const unsigned char *key,
                       size_t keylen );

extern void sha1_hmac_update_A( sha1_context *ctx, const unsigned char *input,
                       size_t ilen );
extern void sha1_hmac_update_B( sha1_context *ctx, const unsigned char *input,
                       size_t ilen );

extern void sha1_hmac_finish_A( sha1_context *ctx, unsigned char output[20] );
extern void sha1_hmac_finish_B( sha1_context *ctx, unsigned char output[20] );

extern void sha1_hmac_reset_A( sha1_context *ctx );
extern void sha1_hmac_reset_B( sha1_context *ctx );

extern void sha1_hmac_A( const unsigned char *key, size_t keylen,
                const unsigned char *input, size_t ilen,
                unsigned char output[20] );
extern void sha1_hmac_B( const unsigned char *key, size_t keylen,
                const unsigned char *input, size_t ilen,
                unsigned char output[20] );

extern void sha256_init_A( sha256_context *ctx );
extern void sha256_init_B( sha256_context *ctx );

extern void sha256_free_A( sha256_context *ctx );
extern void sha256_free_B( sha256_context *ctx );

extern void sha256_starts_A( sha256_context *ctx, int is224 );
extern void sha256_starts_B( sha256_context *ctx, int is224 );

extern void sha256_process_A( sha256_context *ctx, const unsigned char data[64] );
extern void sha256_process_B( sha256_context *ctx, const unsigned char data[64] );

extern void sha256_update_A( sha256_context *ctx, const unsigned char *input,
                    size_t ilen );
extern void sha256_update_B( sha256_context *ctx, const unsigned char *input,
                    size_t ilen );

extern void sha256_finish_A( sha256_context *ctx, unsigned char output[32] );
extern void sha256_finish_B( sha256_context *ctx, unsigned char output[32] );

extern void sha256_A( const unsigned char *input, size_t ilen,
             unsigned char output[32], int is224 );
extern void sha256_B( const unsigned char *input, size_t ilen,
             unsigned char output[32], int is224 );

extern void sha256_hmac_starts_A( sha256_context *ctx, const unsigned char *key,
                         size_t keylen, int is224 );
extern void sha256_hmac_starts_B( sha256_context *ctx, const unsigned char *key,
                         size_t keylen, int is224 );

extern void sha256_hmac_update_A( sha256_context *ctx, const unsigned char *input,
                         size_t ilen );
extern void sha256_hmac_update_B( sha256_context *ctx, const unsigned char *input,
                         size_t ilen );

extern void sha256_hmac_finish_A( sha256_context *ctx, unsigned char output[32] );
extern void sha256_hmac_finish_B( sha256_context *ctx, unsigned char output[32] );

extern void sha256_hmac_reset_A( sha256_context *ctx );
extern void sha256_hmac_reset_B( sha256_context *ctx );

extern void sha256_hmac_A( const unsigned char *key, size_t keylen,
                  const unsigned char *input, size_t ilen,
                  unsigned char output[32], int is224 );
extern void sha256_hmac_B( const unsigned char *key, size_t keylen,
                  const unsigned char *input, size_t ilen,
                  unsigned char output[32], int is224 );

extern void sha512_init_A( sha512_context *ctx );
extern void sha512_init_B( sha512_context *ctx );

extern void sha512_free_A( sha512_context *ctx );
extern void sha512_free_B( sha512_context *ctx );

extern void sha512_starts_A( sha512_context *ctx, int is384 );
extern void sha512_starts_B( sha512_context *ctx, int is384 );

extern void sha512_process_A( sha512_context *ctx, const unsigned char data[128] );
extern void sha512_process_B( sha512_context *ctx, const unsigned char data[128] );

extern void sha512_update_A( sha512_context *ctx, const unsigned char *input,
                    size_t ilen );
extern void sha512_update_B( sha512_context *ctx, const unsigned char *input,
                    size_t ilen );

extern void sha512_finish_A( sha512_context *ctx, unsigned char output[64] );
extern void sha512_finish_B( sha512_context *ctx, unsigned char output[64] );

extern void sha512_A( const unsigned char *input, size_t ilen,
             unsigned char output[64], int is384 );
extern void sha512_B( const unsigned char *input, size_t ilen,
             unsigned char output[64], int is384 );

extern void sha512_hmac_starts_A( sha512_context *ctx, const unsigned char *key,
                         size_t keylen, int is384 );
extern void sha512_hmac_starts_B( sha512_context *ctx, const unsigned char *key,
                         size_t keylen, int is384 );

extern void sha512_hmac_update_A( sha512_context  *ctx,
                         const unsigned char *input, size_t ilen );
extern void sha512_hmac_update_B( sha512_context  *ctx,
                         const unsigned char *input, size_t ilen );

extern void sha512_hmac_finish_A( sha512_context *ctx, unsigned char output[64] );
extern void sha512_hmac_finish_B( sha512_context *ctx, unsigned char output[64] );

extern void sha512_hmac_reset_A( sha512_context *ctx );
extern void sha512_hmac_reset_B( sha512_context *ctx );

extern void sha512_hmac_A( const unsigned char *key, size_t keylen,
                const unsigned char *input, size_t ilen,
                unsigned char output[64], int is384 );
extern void sha512_hmac_B( const unsigned char *key, size_t keylen,
                const unsigned char *input, size_t ilen,
                unsigned char output[64], int is384 );

#endif
