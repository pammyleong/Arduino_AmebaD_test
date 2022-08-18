/** @file ffs_linux_user_context.h
 *
 * @brief Ffs Linux user context API
 *
 * @copyright 2019 Amazon.com, Inc. or its affiliates.  All rights reserved.
 * AMAZON PROPRIETARY/CONFIDENTIAL
 * You may not use this file except in compliance with the terms and
 * conditions set forth in the accompanying LICENSE.TXT file.
 * This file is a Modifiable File, as defined in the accompanying LICENSE.TXT
 * file.
 * THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS,
 * IMPLIED, OR STATUTORY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef FFS_LINUX_USER_CONTEXT_H_
#define FFS_LINUX_USER_CONTEXT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "ffs/common/ffs_wifi.h"
#include "ffs/compat/ffs_linux_configuration_map.h"
#include "ffs/compat/ffs_user_context.h"
#include "ffs/dss/ffs_dss_client.h"
#include "ffs/linux/ffs_wifi_context.h"
#include "ffs/wifi_provisionee/ffs_wifi_provisionee_state.h"

#include <mbedtls/pem.h>
#include <stdbool.h>
#include <stdio.h>
  
#include "mbedtls/x509_crt.h"
#include "mbedtls/platform.h"
#include "osdep_service.h"


/** @brief Ffs Wi-Fi Linux user context structure
 */
typedef struct FfsUserContext_s {
    FfsLinuxWifiContext_t wifiContext;            //!< Wi-Fi context.
    FfsLinuxConfigurationMap_t configurationMap;  //!< Configuration map.

    char *setupNetworkSsid;                       //!< Custom setup network SSID.
    char *setupNetworkPsk;                        //!< Custom setup network PSK.
    char *dssHost;                                //!< Custom DSS host.
    uint16_t dssPort;                             //!< Custom DSS port.
    bool hasDssPort;                              //!< Do we have a custom DSS port?

    FFS_WIFI_PROVISIONEE_STATE provisioneeState;  //!< Current provisionee state.
    _mutex provisioneeStateMutex;                 //!< Mutex protecting the provisionee state.

    mbedtls_pk_context *cloudPublicKey;           //!< Cloud public key.

    mbedtls_pk_context *devicePrivateKey;         //!< Device private key.
    mbedtls_pk_context *devicePublicKey;          //!< Device public key.
    mbedtls_x509_crt *deviceCertificate;          //!< Client certificate.
    uint8_t *hostNameBuffer;                      //!< DSS client host name buffer.
    uint8_t *sessionIdBuffer;                     //!< DSS client session ID buffer.
    uint8_t *nonceBuffer;                         //!< DSS client nonce buffer.
    uint8_t *bodyBuffer;                          //!< DSS client body buffer.

    _sema backgroundWifiScanSemaphore;            //!< Semaphore for waiting to get the scan list.
    _sema ffsTaskWifiSemaphore;

} FfsUserContext_t;

/** @brief Initialize the Ffs Wi-Fi Linux user context.
 *
 * @param userContext Ffs Wi-Fi Linux user context structure
 *
 * @returns Enumerated [result](@ref FFS_RESULT)
 */
FFS_RESULT ffsInitializeUserContext(FfsUserContext_t *userContext);

/** @brief Deinitialize the Ffs Wi-Fi Linux user context.
 *
 * @param userContext Ffs Wi-Fi Linux user context structure
 *
 * @returns Enumerated [result](@ref FFS_RESULT)
 */
FFS_RESULT ffsDeinitializeUserContext(FfsUserContext_t *userContext);

#ifdef __cplusplus
}
#endif

#endif /* FFS_LINUX_USER_CONTEXT_H_ */
