/**************************************************************************//**
 * @file     boot_usr.h
 * @brief    The file is to let user define what they need
 * @version  V1.00
 * @date     2020-07-29
 *
 * @note     
 *
 ******************************************************************************/

#ifdef  __cplusplus
 extern "C"
 {
#endif

typedef struct load_fw_fail_info_s {
    uint32_t fw1_sn;                // the FW1 SN
    uint32_t fw2_sn;                // the FW2 SN
    uint8_t fw1_valid;              // is FW1 valid (OTA signature valid)
    uint8_t fw2_valid;              // is FW2 valid (OTA signature valid)
    uint8_t loaded_fw_idx;          // select loaded fw index
    uint8_t reserved;               // select loaded fw index
} load_fw_fail_info_t;

#ifdef  __cplusplus
}
#endif

