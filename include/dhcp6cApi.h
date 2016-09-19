/**
* @file dhcp6cApi.h
* @brief For CCSP Component: DHCP6-Client Status
*
* @description This header file gives the function call prototypes and structure definitions used for the RDK-Broadband DHCP6Client Status abstraction layer.
*/

#ifndef _DHCP6_CLIENT_API_
#define _DHCP6_CLIENT_API_

/* ert_dhcp6c_get_info() function */
/**
* @description Gets the E-Router Info.
* @param
*    pInfo - E-Router Info(elements of structure "dhcp6cInfo_t"), to be returned
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected
*
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int ert_dhcp6c_get_info(dhcp6cInfo_t *pInfo);

/* ecm_dhcp6c_get_info() function */
/**
* @description Gets the ECM Info.
* @param
*    pInfo - ECM Info(elements of structure "dhcp6cInfo_t"), to be returned
* @return The status of the operation.
* @retval STATUS_SUCCESS if successful.
* @retval STATUS_FAILURE if any error is detected
*
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
int ecm_dhcp6c_get_info(dhcp6cInfo_t *pInfo);

#endif


