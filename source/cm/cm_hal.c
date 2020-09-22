/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2015 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "cm_hal.h"

enum
{
   CMMGMT_LOG_NOTHING  = 0,
   CMMGMT_LOG_ERR      = 1,
   CMMGMT_LOG_INFO     = 2,
   CMMGMT_LOG_DEBUG    = 3,
};

static unsigned int cmmgmt_glog_level = CMMGMT_LOG_ERR;

#define msg_err(fmt...) { \
        if (cmmgmt_glog_level >= CMMGMT_LOG_ERR) { \
        printf("%s:%d> ", __FUNCTION__, __LINE__); printf(fmt); }}

#define msg_info(fmt...) { \
        if (cmmgmt_glog_level >= CMMGMT_LOG_INFO) { \
        printf("%s:%d> ", __FUNCTION__, __LINE__); printf(fmt); }}

#define msg_debug(fmt...) { \
        if (cmmgmt_glog_level >= CMMGMT_LOG_DEBUG) { \
        printf("%s:%d> ", __FUNCTION__, __LINE__); printf(fmt); }}


/****************************************************************************/

static unsigned long downstream_frequency = 0;
static int upstream_channel_id = 0;
static int mdd_ip_override_id = 0;

static const char *mddoverrides[] =
{
    "Honor",
    "IPv4",
    "IPv6",
    "APM",
    "DPM",
};

#define NUM_MDDOVERRIDES (sizeof(mddoverrides)/sizeof(mddoverrides[0]))

static char *mddoverride_index_to_string (int index)
{
    if ((index < 0) || (index >= NUM_MDDOVERRIDES))
    {
        index = 0;
    }

    return mddoverrides[index];
}

static int mddoverride_string_to_index (char *str)
{
    int i;

    for (i = 0; i < NUM_MDDOVERRIDES; i++)
    {
        if (strcasecmp(str, mddoverrides[i]) == 0)
        {
            return i;
        }
    }

    return -1;
}


/****************************************************************************/

int cm_hal_InitDB (void)
{
    return RETURN_OK;
}

int docsis_InitDS (void)
{
    static int initDS = 0;

    if (!initDS)
    {
        initDS = 1;
    }

    return RETURN_OK;
}

int docsis_InitUS (void)
{
    static int initUS = 0;

    if (!initUS)
    {
        initUS = 1;
    }

    return RETURN_OK;
}

int docsis_getCMStatus (char *cm_status)
{
    strcpy(cm_status, "REGISTRATION_COMPLETE");

    return RETURN_OK;
}

int docsis_GetDSChannel (PCMMGMT_CM_DS_CHANNEL *ppinfo)
{
    int i;
    unsigned long num_receivers;
    CMMGMT_CM_DS_CHANNEL *pinfo;

    if (docsis_GetNumOfActiveRxChannels(&num_receivers) != RETURN_OK)
    {
        msg_err("docsis_GetNumOfActiveRxChannels failed\n");
        return RETURN_ERR;
    }

    docsis_InitDS();

    pinfo = *ppinfo;

    for (i = 0; i < num_receivers; i++)
    {
        memset(pinfo, 0, sizeof(CMMGMT_CM_DS_CHANNEL));

        pinfo->ChannelID = 11;
        sprintf(pinfo->Frequency, "%u", 6440);
        sprintf(pinfo->PowerLevel, "%u", 75);
        sprintf(pinfo->SNRLevel, "%u", 50);
        sprintf(pinfo->Modulation, "%s", "QPSK");
        pinfo->Octets = 123;
        pinfo->Correcteds = 100;
        pinfo->Uncorrectables = 12;
        sprintf(pinfo->LockStatus, "%s", "Locked");

        msg_debug("pinfo->ChannelID: %lu\n", pinfo->ChannelID);
        msg_debug("pinfo->Frequency: %s\n", pinfo->Frequency);
        msg_debug("pinfo->PowerLevel: %s\n", pinfo->PowerLevel);
        msg_debug("pinfo->SNRLevel: %s\n", pinfo->SNRLevel);
        msg_debug("pinfo->Modulation: %s\n", pinfo->Modulation);
        msg_debug("pinfo->Octets: %lx\n", pinfo->Octets);
        msg_debug("pinfo->Correcteds: %lx\n", pinfo->Correcteds);
        msg_debug("pinfo->Uncorrectables: %lx\n", pinfo->Uncorrectables);
        msg_debug("pinfo->LockStatus: %s\n", pinfo->LockStatus);

        ppinfo++;
    }

    return RETURN_OK;
}

int docsis_GetUsStatus (unsigned short i, PCMMGMT_CM_US_CHANNEL pinfo)
{
    memset(pinfo, 0, sizeof(CMMGMT_CM_US_CHANNEL));

    pinfo->ChannelID = 12;
    sprintf(pinfo->Frequency, "%u", 12750);
    sprintf(pinfo->PowerLevel, "%u", 60);
    sprintf(pinfo->ChannelType, "%s", "Dummy");
    sprintf(pinfo->SymbolRate, "%u", 115200);
    sprintf(pinfo->Modulation, "%s", "QAM");
    sprintf(pinfo->LockStatus, "%s", "Locked");

    return RETURN_OK;
}

int docsis_GetUSChannel (PCMMGMT_CM_US_CHANNEL *ppinfo)
{
    int i;
    unsigned long num_channels;
    CMMGMT_CM_US_CHANNEL *pinfo;

    if (docsis_GetNumOfActiveTxChannels(&num_channels) != RETURN_OK)
    {
        msg_err("docsis_GetNumOfActiveTxChannels failed\n");
        return RETURN_ERR;
    }

    docsis_InitUS();

    pinfo = *ppinfo;

    for (i = 0; i < num_channels; i++)
    {
        if (docsis_GetUsStatus(i, pinfo) != RETURN_OK)
        {
            return RETURN_ERR;
        }

        pinfo++;
    }

    return RETURN_OK;
}

int docsis_GetDOCSISInfo (PCMMGMT_CM_DOCSIS_INFO pinfo)
{
    memset(pinfo, 0, sizeof(CMMGMT_CM_DOCSIS_INFO));

    sprintf(pinfo->DOCSISVersion, "%s", "3.0");
    sprintf(pinfo->DOCSISDownstreamScanning, "%s", "Complete");
    sprintf(pinfo->DOCSISDownstreamRanging, "%s", "Complete");
    sprintf(pinfo->DOCSISUpstreamScanning, "%s", "InProgress");
    sprintf(pinfo->DOCSISUpstreamRanging, "%s", "InProgress");
    sprintf(pinfo->DOCSISTftpStatus, "%s", "NotStarted");
    sprintf(pinfo->DOCSISDataRegComplete, "%s", "Complete");

    pinfo->DOCSISDHCPAttempts = 3;
    sprintf(pinfo->DOCSISConfigFileName, "%s", "goldenjim.cm");

    pinfo->DOCSISTftpAttempts = 1;

    sprintf(pinfo->ToDStatus, "%s", "NotStarted");

    pinfo->BPIState = TRUE;
    pinfo->NetworkAccess = FALSE;

    pinfo->UpgradeServerIP.Dot[0] = 192;
    pinfo->UpgradeServerIP.Dot[1] = 168;
    pinfo->UpgradeServerIP.Dot[2] = 0;
    pinfo->UpgradeServerIP.Dot[3] = 1;

    pinfo->MaxCpeAllowed = 5;

    sprintf(pinfo->UpstreamServiceFlowParams, "%s", "Dummy");
    sprintf(pinfo->DownstreamServiceFlowParams, "%s", "Dummy");

    sprintf(pinfo->DOCSISDownstreamDataRate, "%u", 20000);
    sprintf(pinfo->DOCSISUpstreamDataRate, "%u", 10000);

    sprintf(pinfo->CoreVersion, "%s", "1.0");

    return RETURN_OK;
}

int docsis_GetNumOfActiveTxChannels (unsigned long *cnt)
{
    *cnt = 1;

    return RETURN_OK;
}

int docsis_GetNumOfActiveRxChannels (unsigned long *cnt)
{
    *cnt = 1;

    return RETURN_OK;
}

int docsis_GetErrorCodewords (PCMMGMT_CM_ERROR_CODEWORDS *ppinfo)
{
    int i;
    unsigned long num_receivers;
    CMMGMT_CM_ERROR_CODEWORDS *pinfo;

    if (docsis_GetNumOfActiveRxChannels(&num_receivers) != RETURN_OK)
    {
        msg_err("docsis_GetNumOfActiveRxChannels failed\n");
        return RETURN_ERR;
    }

    pinfo = *ppinfo;

    for (i = 0; i < num_receivers; i++)
    {
        memset(pinfo, 0, sizeof(CMMGMT_CM_ERROR_CODEWORDS));

        pinfo->UnerroredCodewords = 1111;
        pinfo->CorrectableCodewords = 1112;
        pinfo->UncorrectableCodewords = 1113;

        msg_info("pinfo->UnerroredCodewords: %ld\n", pinfo->UnerroredCodewords);
        msg_info("pinfo->CorrectableCodewords: %ld\n", pinfo->CorrectableCodewords);
        msg_info("pinfo->UncorrectableCodewords: %ld\n", pinfo->UncorrectableCodewords);

        pinfo++;
    }

    return RETURN_OK;
}

int docsis_GetMddIpModeOverride (char *pValue)
{
    char *str;

    str = mddoverride_index_to_string(mdd_ip_override_id);

    strcpy(pValue, str);

    return RETURN_OK;
}

int docsis_SetMddIpModeOverride (char *pValue)
{
    int index;

    if ((index = mddoverride_string_to_index(pValue)) < 0)
    {
        msg_err("Invalid pValue: %s\n", pValue);
        return RETURN_ERR;
    }

    mdd_ip_override_id = index;

    return RETURN_OK;
}

unsigned char docsis_GetUSChannelId (void)
{
    return (unsigned char) upstream_channel_id;
}

void docsis_SetUSChannelId (int index)
{
    upstream_channel_id = index;
}

unsigned long docsis_GetDownFreq (void)
{
    return downstream_frequency;
}

void docsis_SetStartFreq (unsigned long value)
{
    downstream_frequency = value;
}

int docsis_GetDocsisEventLogItems (CMMGMT_CM_EventLogEntry_t *entryArray, int len)
{
    int i;
    struct timeval tv;

    if (len <= 0)
        return 0;

    if (len > 4)
        len = 4;

    gettimeofday(&tv, NULL);

    for (i = 0; i < len; i++)
    {
        entryArray[i].docsDevEvIndex = i;
        entryArray[i].docsDevEvFirstTime = tv;
        entryArray[i].docsDevEvLastTime = tv;
        entryArray[i].docsDevEvCounts = i;
        entryArray[i].docsDevEvLevel = i;
        entryArray[i].docsDevEvId = i;
        snprintf(entryArray[i].docsDevEvText, sizeof(entryArray[i].docsDevEvText), "This is entry %u", i);
    }

    return i;
}

int docsis_ClearDocsisEventLog (void)
{
    return RETURN_OK;
}

int cm_hal_GetDHCPInfo (PCMMGMT_CM_DHCP_INFO pinfo)
{
    memset(pinfo, 0, sizeof(CMMGMT_CM_DHCP_INFO));

    pinfo->IPAddress.Dot[0] = 192;
    pinfo->IPAddress.Dot[1] = 168;
    pinfo->IPAddress.Dot[2] = 0;
    pinfo->IPAddress.Dot[3] = 100;

    sprintf(pinfo->BootFileName, "%s", "ccsp.boot");

    pinfo->SubnetMask.Dot[0] = 255;
    pinfo->SubnetMask.Dot[1] = 255;
    pinfo->SubnetMask.Dot[2] = 255;
    pinfo->SubnetMask.Dot[3] = 0;

    pinfo->Gateway.Dot[0] = 192;
    pinfo->Gateway.Dot[1] = 168;
    pinfo->Gateway.Dot[2] = 0;
    pinfo->Gateway.Dot[3] = 1;

    pinfo->TFTPServer.Dot[0] = 192;
    pinfo->TFTPServer.Dot[1] = 168;
    pinfo->TFTPServer.Dot[2] = 0;
    pinfo->TFTPServer.Dot[3] = 10;

    sprintf(pinfo->TimeServer, "%s", "ntp.cisco.com");
    pinfo->TimeOffset = 8;

    pinfo->LeaseTimeRemaining = 3600;
    sprintf(pinfo->RebindTimeRemaining, "%u", 3700);
    sprintf(pinfo->RenewTimeRemaining, "%u", 1200);
    sprintf(pinfo->MACAddress, "%s", "00:1A:2B:11:22:33");
    sprintf(pinfo->DOCSISDHCPStatus, "%s", "Complete");

    return RETURN_OK;
}

int cm_hal_GetIPv6DHCPInfo (PCMMGMT_CM_IPV6DHCP_INFO pinfo)
{
    memset(pinfo, 0, sizeof(CMMGMT_CM_IPV6DHCP_INFO));

    sprintf(pinfo->IPv6Address,      "%s", "2012:cafe:100::1");
    sprintf(pinfo->IPv6BootFileName, "%s", "ccsp.v6.boot");
    sprintf(pinfo->IPv6Prefix,       "%s", "2012:cafe::/32");
    sprintf(pinfo->IPv6Router,       "%s", "2012:cafe::1");
    sprintf(pinfo->IPv6TFTPServer,   "%s", "2012:cafe::2");
    sprintf(pinfo->IPv6TimeServer,   "%s", "ntp.cisco.com");

    pinfo->IPv6LeaseTimeRemaining = 3600;
    pinfo->IPv6RebindTimeRemaining = 3700;
    pinfo->IPv6RenewTimeRemaining = 1200;

    return RETURN_OK;
}

int cm_hal_GetCPEList (PCMMGMT_DML_CPE_LIST *ppCPEList, unsigned long *pulInstanceNumber, char *LanMode)
{
    return RETURN_ERR;
}

int cm_hal_GetMarket (char *market)
{
#if 0
    strcpy(market, "US");
#else
    strcpy(market, "EURO");
#endif

    return RETURN_OK;
}

int cm_hal_Set_HTTP_Download_Url (char *pHttpUrl, char *pfilename)
{
    return RETURN_OK;
}

int cm_hal_Get_HTTP_Download_Url (char *pHttpUrl, char *pfilename)
{
    return RETURN_OK;
}

int cm_hal_Set_HTTP_Download_Interface (unsigned int interface)
{
    return RETURN_OK;
}

int cm_hal_Get_HTTP_Download_Interface (unsigned int *pinterface)
{
    *pinterface = 0;

    return RETURN_OK;
}

int cm_hal_HTTP_Download (void)
{
    return RETURN_OK;
}

int cm_hal_Get_HTTP_Download_Status (void)
{
    return RETURN_OK;
}

int cm_hal_Reboot_Ready (unsigned long *pValue)
{
    *pValue = 1;

    return RETURN_OK;
}

int cm_hal_HTTP_Download_Reboot_Now (void)
{
    return RETURN_OK;
}

int cm_hal_FWupdateAndFactoryReset (void)
{
    return RETURN_OK;
}

int cm_hal_ReinitMac (void)
{
    return RETURN_OK;
}

int docsis_GetProvIpType (char *pValue)
{
    strcpy(pValue, "IPv4");

    return RETURN_OK;
}

int docsis_GetCert (char *pCert)
{
    return RETURN_ERR;
}

int docsis_GetCertStatus (unsigned long *pVal)
{
    *pVal = 0;

    return RETURN_OK;
}

int cm_hal_Get_CableModemResetCount (unsigned long *resetcnt)
{
    *resetcnt = 0;

    return RETURN_OK;
}

int cm_hal_Get_LocalResetCount (unsigned long *resetcnt)
{
    *resetcnt = 0;

    return RETURN_OK;
}

int cm_hal_Get_DocsisResetCount (unsigned long *resetcnt)
{
    *resetcnt = 0;

    return RETURN_OK;
}

int cm_hal_Get_ErouterResetCount (unsigned long *resetcnt)
{
    *resetcnt = 0;

    return RETURN_OK;
}

int cm_hal_HTTP_LED_Flash (BOOLEAN LedFlash)
{
    return RETURN_OK;
}

int docsis_GetDsOfdmChanTable (PDOCSIF31_CM_DS_OFDM_CHAN *ppinfo, int *output_NumberOfEntries)
{
    *output_NumberOfEntries = 0;

    return RETURN_OK;
}

int docsis_GetUsOfdmaChanTable (PDOCSIF31_CM_US_OFDMA_CHAN *ppinfo, int *output_NumberOfEntries)
{
    *output_NumberOfEntries = 0;

    return RETURN_OK;
}

int docsis_GetStatusOfdmaUsTable (PDOCSIF31_CMSTATUSOFDMA_US *ppinfo, int *output_NumberOfEntries)
{
    *output_NumberOfEntries = 0;

    return RETURN_OK;
}

int cm_hal_snmpv3_kickstart_initialize (snmpv3_kickstart_table_t *pKickstart_Table)
{
    return RETURN_OK;
}

int docsis_IsEnergyDetected (BOOLEAN *pEnergyDetected)
{
    return RETURN_ERR;
}

