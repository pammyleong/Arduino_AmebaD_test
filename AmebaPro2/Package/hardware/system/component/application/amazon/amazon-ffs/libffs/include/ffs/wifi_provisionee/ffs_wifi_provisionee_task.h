/** @file ffs_wifi_provisionee.h
 *
 * @brief Ffs Wi-Fi provisionee task.
 *
 * @copyright 2019 Amazon.com, Inc. or its affiliates.  All rights reserved.
 * AMAZON PROPRIETARY/CONFIDENTIAL
 * You may not use this file except in compliance with the terms and
 * conditions set forth in the accompanying LICENSE.TXT file.
 * THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS,
 * IMPLIED, OR STATUTORY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

#ifndef FFS_WIFI_PROVISIONEE_H_
#define FFS_WIFI_PROVISIONEE_H_

#include "ffs/compat/ffs_user_context.h"
#include "ffs/common/ffs_check_result.h"
#include "ffs/common/ffs_configuration_map.h"
#include "ffs/common/ffs_logging.h"
#include "ffs/common/ffs_result.h"
#include "ffs/conversion/ffs_convert_registration_details.h"
#include "ffs/conversion/ffs_convert_registration_state.h"
#include "ffs/conversion/ffs_convert_wifi_connection_attempt.h"
#include "ffs/conversion/ffs_convert_wifi_connection_details.h"
#include "ffs/conversion/ffs_convert_wifi_credentials.h"
#include "ffs/conversion/ffs_convert_wifi_provisionee_state.h"
#include "ffs/conversion/ffs_convert_wifi_scan_result.h"
#include "ffs/compat/ffs_common_compat.h"
#include "ffs/compat/ffs_wifi_provisionee_compat.h"
#include "ffs/dss/ffs_dss_client.h"
#include "ffs/dss/ffs_dss_operation_compute_configuration_data.h"
#include "ffs/dss/ffs_dss_operation_get_wifi_credentials.h"
#include "ffs/dss/ffs_dss_operation_post_wifi_scan_data.h"
#include "ffs/dss/ffs_dss_operation_report.h"
#include "ffs/dss/ffs_dss_operation_start_pin_based_setup.h"
#include "ffs/dss/ffs_dss_operation_start_provisioning_session.h"
#include "ffs/wifi_provisionee/ffs_wifi_provisionee_encoded_setup_network.h"
#include "ffs/wifi_provisionee/ffs_wifi_provisionee_setup_network.h"
#include "ffs/wifi_provisionee/ffs_wifi_provisionee_user_network.h"
#include "ffs/wifi_provisionee/ffs_wifi_provisionee_state.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @brief The Ffs Wi-Fi provisionee task.
 *
 * @param userContext User context
 *
 * @returns Enumerated [result](@ref FFS_RESULT)
 */
FFS_RESULT ffsWifiProvisioneeTask(struct FfsUserContext_s *userContext);

#ifdef __cplusplus
}
#endif

#endif /* FFS_WIFI_PROVISIONEE_H_ */
