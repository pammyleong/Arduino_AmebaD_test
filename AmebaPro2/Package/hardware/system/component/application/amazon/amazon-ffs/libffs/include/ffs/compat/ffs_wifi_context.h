/** @file ffs_wifi_context.h
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
 
#ifndef FFS_WIFI_CONTEXT_H_
#define FFS_WIFI_CONTEXT_H_

#include "ffs/linux/ffs_linked_list.h"

#include <FreeRTOS.h>
#include <semphr.h>
#include <time.h>


/** @brief Ffs Wi-Fi context structure
 */
typedef struct FfsWifiContext_s {
    bool wifiManagerInitialized; //!< Is the context initialized?
    FfsLinkedList_t configurationList; //!< Wi-Fi configuration list.
    FfsLinkedList_t scanList; //!< Wi-Fi scan list.
    SemaphoreHandle_t scanListMutex; //!< Scan list mutex.
    clock_t lastBackgroundScanTime; //!< Last background scan time.
    size_t scanListIndex; //!< Index for returning scan list items, reset by background scans.
    FfsLinkedList_t connectionAttemptList; //!< Wi-Fi connection attempts.
    const char *interface; //!< Wi-Fi interface to use (\a e.g. "wlan0").
    const char *driver; //!< Wi-Fi driver to use (\a e.g. "wext").
    uint8_t ssidBuffer[FFS_MAXIMUM_SSID_SIZE]; //!< Buffer for the connection details SSID.
    FfsWifiConnectionDetails_t connectionDetails; //!< Current Wi-Fi connection state.
} FfsLinuxWifiContext_t;

#endif /* FFS_WIFI_CONTEXT_H_ */