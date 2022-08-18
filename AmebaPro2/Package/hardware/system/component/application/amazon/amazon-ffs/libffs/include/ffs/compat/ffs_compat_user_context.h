/** @file ffs_compat_user_context.h
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

#ifndef FFS_COMPAT_USER_CONTEXT_H_
#define FFS_COMPAT_USER_CONTEXT_H_

#include <FreeRTOS.h>
#include <semphr.h>    // semaphore
#include <task.h>      // thread
#include "mbedtls/pem.h"

#include "ffs/compat/ffs_wifi_context.h"
#include "ffs/compat/ffs_linux_configuration_map.h"
#include "ffs/wifi_provisionee/ffs_wifi_provisionee_state.h"

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
    SemaphoreHandle_t provisioneeStateMutex;        //!< Mutex protecting the provisionee state.

    char *serverCaCertificatesPath;               //!< Path to the PEM encoded server CA certificates directory. Must be preprocessed with c_rehash tool from OpenSSL.
    char *clientCertificatePath;                  //!< Path to the PEM encoded client certificate file.
    char *clientCertificatePrivateKeyPath;        //!< Path to the PEM encoded private key for the client certificate.
    //EVP_PKEY *cloudPublicKey;                     //!< Cloud public key.
    unsigned char* cloudPublicKey;                     //!< Cloud public key.

    unsigned char* devicePrivateKey;                   //!< Device private key. EVP_PKEY *
    unsigned char* devicePublicKey;                    //!< Device public key.  EVP_PKEY *

    uint8_t *hostNameBuffer;                      //!< DSS client host name buffer.
    uint8_t *sessionIdBuffer;                     //!< DSS client session ID buffer.
    uint8_t *nonceBuffer;                         //!< DSS client nonce buffer.
    uint8_t *bodyBuffer;                          //!< DSS client body buffer.

    TaskHandle_t taskThread;                         //!< Thread for the main task. pthread_t 
    SemaphoreHandle_t* ffsTaskWifiSemaphore;                  //!< Semaphore to block the Ffs Wi-Fi provisionee task on async Wi-Fi manager operations. sem_t *
    SemaphoreHandle_t* backgroundWifiScanSemaphore;           //!< Semaphore for waiting to get the scan list. sem_t *
} FfsUserContext_t;

/*
 * Get the client-allocated buffers used by the Device Setup Service client.
 */
FFS_RESULT ffsDssClientGetBuffers(struct FfsUserContext_s *userContext,
        FfsStream_t *hostNameStream, FfsStream_t *sessionIdStream,
        FfsStream_t *nonceStream, FfsStream_t *bodyStream);

/*
 * Get a configuration value (\a e.g., country code).
 */
FFS_RESULT ffsGetConfigurationValue(struct FfsUserContext_s *userContext,
        const char *configurationKey, FfsMapValue_t *configurationValue);
#endif /* FFS_COMPAT_USER_CONTEXT_H_ */
