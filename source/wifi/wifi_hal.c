/**********************************************************************
   Copyright [2014] [Cisco Systems, Inc.]
 
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
 
       http://www.apache.org/licenses/LICENSE-2.0
 
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
**********************************************************************/

/**********************************************************************

    module: wifi_hal.c

        For CCSP Component:  Wifi_Provisioning_and_management

    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc., 2014
        All Rights Reserved.

    ---------------------------------------------------------------

    description:

        This header file gives the function call prototypes and 
        structure definitions used for the RDK-Broadband 
        Wifi hardware abstraction layer

        NOTE:
        THIS VERSION IS AN EARLY DRAFT INTENDED TO GET COMMENTS FROM COMCAST.
        TESTING HAS NOT YET BEEN COMPLETED.  
       
    ---------------------------------------------------------------

    environment:

        This HAL layer is intended to support Wifi drivers 
        through an open API.  The current implementation created
        below this HAL supports Qualcomm / Atheros Wifi.
        Changes may be needed to support other Wifi enviornments.

    ---------------------------------------------------------------

    author:

        Cisco

**********************************************************************/

#include <stdio.h>
#include <string.h>
#include "wifi_hal.h"

/**********************************************************************************
 *
 *  Wifi Subsystem level function prototypes 
 *
**********************************************************************************/

/* wifi_init() function */
/**
* Description: Initializes the Wifi subsystem.  This includes initilization of all 
*  radios.  Implementation specifics may dictate what is actualy initializes since 
*  different hardware implementations may have different requirements.
*  Parameters : None
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_init()
{
	return RETURN_OK;
}

/* wifi_reset() function */
/**
* Description: Resets the Wifi subsystem.  This includes reset of all AP varibles.
*  Implementation specifics may dictate what is actualy reset since 
*  different hardware implementations may have different requirements.
*  Parameters : None
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_reset()
{
	return RETURN_OK;
}

/* wifi_down() function */
/**
* Description: 
*  Turns off transmit power to all radios.
*  Implementation specifics may dictate some functionality since 
*  different hardware implementations may have different requirements.
*  Parameters : None
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_down()
{
	return RETURN_OK;
}

/* wifi_factoryReset() function */
/**
* Description: 
*  Resets Implementation specifics may dictate some functionality since 
*  different hardware implementations may have different requirements.
*  Parameters : None
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_factoryReset()
{
	return RETURN_OK;
}


/* wifi_createInitialConfigFiles() function */
/**
* Description: 
*  This function creates wifi configuration files.  The format
*  and content of these files are implementation dependent.  This function call is 
*  used to trigger this task if necessary. Some implementations may not need this 
*  function. If an implementation does not need to create config files the function call can 
*  do nothing and return RETURN_OK. 
*  Parameters : None
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_createInitialConfigFiles()
{
	return RETURN_OK;
}


/**********************************************************************************
 *
 *  Wifi radio level function prototypes
 *
**********************************************************************************/

/* wifi_initRadio() function */
/**
* Description: This function call initializes the specified radio.
*  Implementation specifics may dictate the functionality since 
*  different hardware implementations may have different initilization requirements.
* Parameters : radioIndex - The index of the radio. First radio is index 0. 2nd radio is index 1   - type INT
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_initRadio(INT radioIndex)
{
	return RETURN_OK;
}


/* wifi_getBaseBSSID() function */
/**
* Description: This function call outputs a 32 byte or less string with the base mac address of this radio.
*  Each radio may support mulitiple BSSIDs with each BSSID having a mac address.  This funtion call  
*  outputs the base (lowest) mac address assocated with this radio.
* Parameters : 
*  radioIndex - The index of the radio. First radio is index 0. 2nd radio is index 1   - type INT
*  *output_string - a pointer to a 32 buffer that was preallocated by the caller.  This is where the output is written
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_getBaseBSSID(INT radioIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "dummy_bssid");
		return RETURN_OK;
	}
}


/* wifi_getMaxBitRate() function */
/**
* Description: 
*  This fuction outputs a 32 byte or less string indicating the max bit rate of this radio in bps.
*  Parameters :
*  radioIndex - The index of the radio. First radio is index 0. 2nd radio is index 1   - type INT
*  *output_string - a pointer to a 32 buffer that was preallocated by the caller.  This is where the output is written
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_getMaxBitRate(INT radioIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "dummy_maxbitrate");
		return RETURN_OK;
	}
}

/* wifi_getChannel() function */
/**
* Description: 
*  This fuction outputs a value indicating the channel number currently in use on this radio
*  Parameters :
*  radioIndex - The index of the radio. First radio is index 0. 2nd radio is index 1   - type INT
*  *output_ulong - a pointer to a unsigned long value that was preallocated by the caller.  This is where the output is written
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_getChannel(INT radioIndex,ULONG *output_ulong)
{
	if (NULL == output_ulong) {
		return RETURN_ERR;
	} else {
		*output_ulong = 10;
		return RETURN_OK;
	}
}

/* wifi_setChannel() function */
/**
* Description: 
*  This fuction sets a driver internal paramater correspdonding to the channel number to use on this radio
*  Parameters :
*  radioIndex - The index of the radio. First radio is index 0. 2nd radio is index 1   - type INT
*  channel - a unsigned long value that is used to pass the channel number
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_setChannel(INT radioIndex, ULONG channel)
{
	return RETURN_OK;
}


/* wifi_getAutoChannelEnable() function */
/**
* Description: 
*  This function outputs a bool value indicating if auto channel selection is currently in use on this radio
*  Parameters :
*  radioIndex - The index of the radio. First radio is index 0. 2nd radio is index 1   - type INT
*  *output_bool - a pointer to a bool value that was preallocated by the caller.  This is where the output is written. 1 == enabled, 0 == disabled
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_getAutoChannelEnable(INT radioIndex, BOOL *output_bool)
{
	if (NULL == output_bool) {
		return RETURN_ERR;
	} else {
		*output_bool = FALSE;
		return RETURN_OK;
	}
}

/* wifi_setAutoChannelEnable() function */
/**
* Description: 
*  This function enables or disables a driver level variable to indicate if auto channel selection is enabled on this radio
*  Parameters :
*  radioIndex - The index of the radio. First radio is index 0. 2nd radio is index 1  - type INT
*  enable - a BOOL value that enables auto channel selection on this radio.  1 == enabled, 0 == disabled
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_setAutoChannelEnable(INT radioIndex, BOOL enable)
{
	return RETURN_OK;
}

/* wifi_getStandard() function */
/**
* Description: 
*  This function outputs the PHY level standards supported by this radio.
*  Parameters :
*  radioIndex - The index of the radio. First radio is index 0. 2nd radio is index 1   - type INT
*  *output_string - a pointer to a string that was preallocated by the caller.  This is where the output is written.
*     valid strings are formated as "a", "b", "g"(b&g clients),"g-"(only g),"n","ac", 
*  *gOnly - a pointer to a BOOL value.  1 indicates that the radio is in g-only mode, 0 indicates not in g-only mode
*  *nOnly - a pointer to a BOOL value.  1 indicates that the radio is in n-only mode, 0 indicates not in n-only mode
*  *acOnly - a pointer to a BOOL value.  1 indicates that the radio is in ac-only mode, 0 indicates not in ac-only mode
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_getStandard(INT radioIndex, CHAR *output_string, BOOL *gOnly, BOOL *nOnly, BOOL *acOnly)
{
	if (NULL == output_string || NULL == gOnly || NULL == nOnly || NULL == acOnly) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		*gOnly = *nOnly = *acOnly = FALSE;
		return RETURN_OK;
	}
}

/* wifi_getPossibleChannels() function */
/**
* Description: This function call outputs a 128 byte or less string with the supported radio channels on this radio.
*  Format is comma separated list of possible channels. String must be preallocaated by caller.
* Parameters : 
*  radioIndex - The index of the radio. First radio is index 0. 2nd radio is index 1   - type INT
*  *output_string - a pointer to a 128 buffer that was preallocated by the caller.  This is where the output is written
* 
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected 
* 
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
*
*/
INT wifi_getPossibleChannels(INT radioIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

/*******
 * NOTE: FILE FORMATING AND CREATION OF COMMENTS IS A WORK IN PROGRESS BELOW THIS POINT
**********/

INT wifi_setRadioEnable(INT radioIndex, BOOL enable)
{
	return RETURN_OK;
}

INT wifi_getRadioEnable(INT radioIndex, BOOL *output_bool)
{
	if (NULL == output_bool) {
		return RETURN_ERR;
	} else {
		*output_bool = FALSE;
		return RETURN_OK;
	}
}

INT wifi_getRadioActive(INT radioIndex, BOOL *output_bool)
{
	if (NULL == output_bool) {
		return RETURN_ERR;
	} else {
		*output_bool = FALSE;
		return RETURN_OK;
	}
}

INT wifi_getTransmitPower(INT radioIndex, ULONG *output_ulong)
{
	if (NULL == output_ulong) {
		return RETURN_ERR;
	} else {
		*output_ulong = 0;
		return RETURN_OK;
	}
}

INT wifi_setTransmitPower(INT radioIndex, ULONG TransmitPower)
{
	return RETURN_OK;
}

INT wifi_setDTIMInterval(INT apIndex, INT dtimInterval)
{
	return RETURN_OK;
}
INT wifi_setCtsProtectionEnable(INT apIndex, BOOL enable)
{
	return RETURN_OK;
}

INT wifi_setObssCoexistenceEnable(INT apIndex, BOOL enable)
{
	return RETURN_OK;
}

INT wifi_setFragmentationThreshold(INT apIndex, UINT threshold)
{
	return RETURN_OK;
}

INT wifi_getChannelMode(INT radioIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

INT wifi_setChannelMode(INT radioIndex, CHAR *channelMode, BOOL gOnlyFlag, BOOL nOnlyFlag, BOOL acOnlyFlag)
{
	if (NULL == channelMode) {
		return RETURN_ERR;
	} else {
		return RETURN_OK;
	}
}

INT wifi_getCountryCode(INT radioIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "US");
		return RETURN_OK;
	}
}

INT wifi_setSTBCEnable(INT radioIndex, BOOL STBC_Enable)
{
	return RETURN_OK;
}

INT wifi_getAMSDUEnable(INT radioIndex, BOOL *output_bool)
{
	if (NULL == output_bool) {
		return RETURN_ERR;
	} else {
		*output_bool = FALSE;
		return RETURN_OK;
	}
}

INT wifi_setAMSDUEnable(INT radioIndex, BOOL amsduEnable)
{
	return RETURN_OK;
}

INT wifi_setShortGuardInterval(INT radioIndex, BOOL enable)
{
	return RETURN_OK;
}

INT wifi_getTxChainMask(INT radioIndex, INT *output_int)
{
	if (NULL == output_int) {
		return RETURN_ERR;
	} else {
		*output_int = 0;
		return RETURN_OK;
	}
}

INT wifi_setTxChainMask(INT radioIndex, INT numStreams)
{
	return RETURN_OK;
}

INT wifi_getRxChainMask(INT radioIndex, INT *output_int)
{
	if (NULL == output_int) {
		return RETURN_ERR;
	} else {
		*output_int = 0;
		return RETURN_OK;
	}
}

INT wifi_setRxChainMask(INT radioIndex, INT numStreams)
{
	return RETURN_OK;
}

INT wifi_getChannelsInUse(INT radioIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

INT wifi_scanApChannels(INT radioIndex, CHAR *scanData)
{
	if (NULL == scanData) {
		return RETURN_ERR;
	} else {
		strcpy(scanData, "N/A");
		return RETURN_OK;
	}
}

INT wifi_getWifiEnableStatus(INT radioIndex, BOOL *output_bool)
{
	if (NULL == output_bool) {
		return RETURN_ERR;
	} else {
		*output_bool = FALSE;
		return RETURN_OK;
	}
}

INT wifi_setWifiEnableStatus(INT radioIndex, BOOL enabled)
{
	return RETURN_OK;
}

INT wifi_getSupportedFrequencyBands(INT radioIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

INT wifi_pushDefaultValues(INT radioIndex)
{
	return RETURN_OK;
}

INT wifi_pushChannel(INT radioIndex, UINT channel)
{
	return RETURN_OK;
}

INT wifi_pushChannelMode(INT radioIndex)
{
	return RETURN_OK;
}

INT wifi_pushTxChainMask(INT radioIndex)
{
	return RETURN_OK;
}

INT wifi_pushRxChainMask(INT radioIndex)
{
	return RETURN_OK;
}

/**********************************************************************************
 *
 *  Access Point level function prototypes (aka Virtual Access Point)
 *
**********************************************************************************/

INT wifi_createAp(INT apIndex, INT radioIndex, CHAR *essid, BOOL hideSsid)
{
	if (NULL == essid) {
		return RETURN_ERR;
	} else {
		return RETURN_OK;
	}
}

INT wifi_deleteAp(INT apIndex)
{
	return RETURN_OK;
}

INT wifi_setEnable(INT apIndex, BOOL enable)
{
	return RETURN_OK;
}

INT wifi_getEnable(INT apIndex, BOOL *output_bool)
{
	if (NULL == output_bool) {
		return RETURN_ERR;
	} else {
		*output_bool = FALSE;
		return RETURN_OK;
	}
}

INT wifi_getApEnable(INT apIndex, BOOL *enableFlag)
{
	if (NULL == enableFlag) {
		return RETURN_ERR;
	} else {
		*enableFlag = FALSE;
		return RETURN_OK;
	}
}

INT wifi_getEnableOnLine(INT apIndex, BOOL *output_bool)
{
	if (NULL == output_bool) {
		return RETURN_ERR;
	} else {
		*output_bool = FALSE;
		return RETURN_OK;
	}
}

INT wifi_setEnableOnLine(INT apIndex, BOOL enabled)
{
	return RETURN_OK;
}

INT wifi_ifConfigUp(INT apIndex)
{
	return RETURN_OK;
}

INT wifi_ifConfigDown(INT apIndex)
{
	return RETURN_OK;
}

INT wifi_getStatus(INT apIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

INT wifi_getName(INT apIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

INT wifi_getSSID(INT apIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

INT wifi_setSSID(INT apIndex, CHAR *ssid_string)
{
	return (NULL == ssid_string) ? RETURN_ERR : RETURN_OK; 
}

INT wifi_pushSSID(INT apIndex, CHAR *ssid)
{
	return (NULL == ssid) ? RETURN_ERR : RETURN_OK; 
}

INT wifi_getSsidAdvertisementEnable(INT apIndex, BOOL *output_bool)
{
	if (NULL == output_bool) {
		return RETURN_ERR;
	} else {
		*output_bool = FALSE;
		return RETURN_OK;
	}
}

INT wifi_setSsidAdvertisementEnable(INT apIndex, BOOL enable)
{
	return RETURN_OK; 
}

INT wifi_pushSsidAdvertisementEnable(INT apIndex, BOOL enable)
{
	return RETURN_OK; 
}

INT wifi_getBeaconType(INT apIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

INT wifi_setBeaconType(INT apIndex, CHAR *beaconTypeString)
{
	return (NULL == beaconTypeString) ? RETURN_ERR : RETURN_OK; 
}

INT wifi_setBasicEncryptionMode(INT apIndex, CHAR *encMode)
{
	return (NULL == encMode) ? RETURN_ERR : RETURN_OK; 
}

INT wifi_setBasicAuthenticationMode(INT apIndex, CHAR *authMode)
{
	return (NULL == authMode) ? RETURN_ERR : RETURN_OK; 
}

INT wifi_getWpaEncryptoinMode(INT apIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

INT wifi_setWpaEncryptionMode(INT apIndex, CHAR *encMode)
{
	return (NULL == encMode) ? RETURN_ERR : RETURN_OK; 
}

INT wifi_getWpaRekeyInterval(INT apIndex, INT *output_int)
{
	if (NULL == output_int) {
		return RETURN_ERR;
	} else {
		*output_int = 0;
		return RETURN_OK;
	}
}

INT wifi_setWpaRekeyInterval(INT apIndex, INT rekeyInterval)
{
	return RETURN_OK;
}

INT wifi_getWepKey(INT apIndex, INT keyIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

INT wifi_setWepKey(INT apIndex, INT keyIndex, CHAR *WepKey)
{
	if (NULL == WepKey) {
		return RETURN_ERR;
	} else {
		return RETURN_OK;
	}
}

INT wifi_pushWepKey(INT apIndex, INT keyIndex)
{
	return RETURN_OK;
}

INT wifi_getApWepKeyIndex(INT apIndex, ULONG *output_ulong)
{
	if (NULL == output_ulong) {
		return RETURN_ERR;
	} else {
		*output_ulong = 0;
		return RETURN_OK;
	}
}

INT wifi_setApWepKeyIndex(INT apIndex, ULONG output_ulong)
{
	return RETURN_OK;
}

INT wifi_pushWepKeyIndex(INT apIndex, UINT keyIndex)
{
	return RETURN_OK;
}

INT wifi_removeSecVaribles(INT apIndex)
{
	return RETURN_OK;
}

INT wifi_disableEncryption(INT apIndex)
{
	return RETURN_OK;
}

INT wifi_setAuthMode(INT apIndex, INT mode)
{
	return RETURN_OK;
}

INT wifi_getBasicTrafficStats(INT apIndex, wifi_basicTrafficStats_t *output_struct)
{
	if (NULL == output_struct) {
		return RETURN_ERR;
	} else {
		memset(output_struct, 0, sizeof(wifi_basicTrafficStats_t));
		return RETURN_OK;
	}
}

INT wifi_getWifiTrafficStats(INT apIndex, wifi_trafficStats_t *output_struct)
{
	if (NULL == output_struct) {
		return RETURN_ERR;
	} else {
		memset(output_struct, 0, sizeof(wifi_trafficStats_t));
		return RETURN_OK;
	}
}

INT wifi_getNumDevicesAssociated(INT apIndex, ULONG *output_ulong)
{
	if (NULL == output_ulong) {
		return RETURN_ERR;
	} else {
		*output_ulong = 0;
		return RETURN_OK;
	}
}

INT wifi_getAllAssociatedDeviceDetail(INT apIndex, ULONG *output_ulong, wifi_device_t ***output_struct)
{
	if (NULL == output_ulong || NULL == output_struct) {
		return RETURN_ERR;
	} else {
		*output_ulong = 0;
		*output_struct = NULL;
		return RETURN_OK;
	}
}

INT wifi_getAssociatedDeviceDetail(INT apIndex, INT devIndex, wifi_device_t *output_struct)
{
	if (NULL == output_struct) {
		return RETURN_ERR;
	} else {
		memset(output_struct, 0, sizeof(wifi_device_t));
		return RETURN_OK;
	}
}

INT wifi_kickAssociatedDevice(INT apIndex, wifi_device_t *device)
{
	if (NULL == device) {
		return RETURN_ERR;
	} else {
		return RETURN_OK;
	}
}

INT wifi_getPreSharedKey(INT apIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		output_string[0] = '\0';
		return RETURN_OK;
	}
}

INT wifi_setPreSharedKey(INT apIndex, CHAR *preSharedKey)
{
	if (NULL == preSharedKey) {
		return RETURN_ERR;
	} else {
		return RETURN_OK;
	}
}

INT wifi_getKeyPassphrase(INT apIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		output_string[0] = '\0';
		return RETURN_OK;
	}
}

INT wifi_setKeyPassphrase(INT apIndex, CHAR *passPhrase)
{
	if (NULL == passPhrase) {
		return RETURN_ERR;
	} else {
		return RETURN_OK;
	}
}

INT wifi_getWpsEnable(INT apIndex, BOOL *output_bool)
{
	if (NULL == output_bool) {
		return RETURN_ERR;
	} else {
		*output_bool = FALSE;
		return RETURN_OK;
	}
}

INT wifi_setWpsEnable(INT apIndex, BOOL enableValue)
{
	return RETURN_OK;
}

INT wifi_getWpsDevicePIN(INT apIndex, ULONG *output_ulong)
{
	if (NULL == output_ulong) {
		return RETURN_ERR;
	} else {
		*output_ulong = 0;
		return RETURN_OK;
	}
}
INT wifi_setWpsDevicePIN(INT apIndex, ULONG pin)
{
	return RETURN_OK;
}

INT wifi_getWpsConfigMethodsEnabled(INT apIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
}

INT wifi_setWpsConfigMethodsEnabled(INT apIndex, CHAR *methodString)
{
	if (NULL == methodString) {
		return RETURN_ERR;
	} else {
		return RETURN_OK;
	}
}

INT wifi_getWpsConfigurationState(INT apIndex, CHAR *output_string)
{
	if (NULL == output_string) {
		return RETURN_ERR;
	} else {
		strcpy(output_string, "N/A");
		return RETURN_OK;
	}
} 

INT wifi_setWpsEnrolleePin(INT apIndex, CHAR *pin)
{
	return RETURN_OK;
}

INT wifi_setWpsButtonPush(INT apIndex)
{
	return RETURN_OK;
}

INT wifi_cancelWPS(INT apIndex)
{
	return RETURN_OK;
}

INT wifi_setWmmEnable(INT apIndex, BOOL enable)
{
	return RETURN_OK;
}

INT wifi_setWmmUapsdEnable(INT apIndex, BOOL enable)
{
	return RETURN_OK;
}

INT wifi_setWmmOgAckPolicy(INT apIndex, INT class, BOOL ackPolicy)
{
	return RETURN_OK;
}

INT wifi_getIndexFromName(CHAR *inputSsidString, INT *output_int)
{
	if (NULL == inputSsidString || NULL == output_int) {
		return RETURN_ERR;
	} else {
		strcpy(inputSsidString, "N/A");
		*output_int = 0;
		return RETURN_OK;
	}
	
}

INT wifi_setBeaconInterval(INT apIndex, INT beaconInterval)
{
	return RETURN_OK;
}

INT wifi_setRtsThreshold(INT apIndex, UINT threshold)
{
	return RETURN_OK;
}

INT wifi_setMaxStations(INT apIndex, INT maxStations)
{
	return RETURN_OK;
}

INT wifi_getRadioIndex(INT apIndex, INT *output_int)
{
	if (NULL == output_int) {
		return RETURN_ERR;
	} else {
		*output_int = 0;
		return RETURN_OK;
	}
}

INT wifi_setRadioIndex(INT apIndex, INT radioIndex)
{
	return RETURN_OK;
}

INT wifi_addAclDevice(INT apIndex, CHAR *DeviceMacAddress)
{
	return RETURN_OK;
}

INT wifi_delAclDevice(INT apIndex, CHAR *DeviceMacAddress)
{
	return RETURN_OK;
}

INT wifi_getAclDeviceNum(INT apIndex, UINT *output_uint)
{
	if (NULL == output_uint) {
		return RETURN_ERR;
	} else {
		*output_uint = 101;
		return RETURN_OK;
	}
}

INT wifi_kickAclAssociatedDevices(INT apIndex,BOOL enable)
{
	return RETURN_OK;
}

INT wifi_setMacAddressControlMode(INT apIndex, INT filterMode)
{
	return RETURN_OK;
}

INT wifi_setVlanID(INT apIndex, INT vlanId)
{
	return RETURN_OK;
}

INT wifi_getBridgeInfo(INT index, CHAR *bridgeName, CHAR *IP, CHAR *subnet)
{
	if (NULL == bridgeName || NULL == IP || NULL == subnet) {
		return RETURN_ERR;
	} else {
		strcpy(bridgeName, "N/A");
		strcpy(IP, "N/A");
		strcpy(subnet, "N/A");
		return RETURN_OK;
	}
}

INT wifi_setBridgeInfo(INT apIndex, CHAR *bridgeName, CHAR *IP, CHAR *subnet)
{
	if (NULL == bridgeName || NULL == IP || NULL == subnet) {
		return RETURN_ERR;
	} else {
		return RETURN_OK;
	}
}

INT wifi_pushBridgeInfo(INT apIndex)
{
	return RETURN_OK;
}

INT wifi_resetVlanCfg(INT apIndex)
{
	return RETURN_OK;
}

INT wifi_setApBridging(INT apIndex, BOOL bridgeEnable)
{
	return RETURN_OK;
}
INT wifi_getRouterEnable(INT apIndex, BOOL *output_bool)
{
	if (NULL == output_bool) {
		return RETURN_ERR;
	} else {
		*output_bool = FALSE;
		return RETURN_OK;
	}
}

INT wifi_setRouterEnable(INT apIndex, BOOL routerEnabled)
{
	return RETURN_OK;
}

/**********************************************************************************
 *
 *  Hostapd control function calls used for WPA/WPS security
 *
**********************************************************************************/
INT wifi_createHostApdConfig(INT apIndex, BOOL createWpsCfg)
{
	return RETURN_OK;
}

INT wifi_startHostApd()
{
	return RETURN_OK;
}

INT wifi_stopHostApd()
{
	return RETURN_OK;
}


