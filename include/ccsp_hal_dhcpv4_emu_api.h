/**
* @file ccsp_hal_dhcpv4_emu_api.h
* @brief For CCSP Component: DHCPv4-Client Status on RDK-B Emulator
*
* @description This header file gives the function call prototypes and structure definitions used for the RDK-Broadband DHCP4Client Status abstraction 
layer on RDK-B Emulator.
*/
#ifndef __DHCPV4_EMU_API_H__
#define __DHCPV4_EMU_API_H__



#define GATEWAY 1
#define SUBNET_MASK 2
#define DHCP_STARTING_RANGE 4
#define DHCP_ENDING_RANGE 8
#define DHCP_LEASE_TIME 16
#define UDHCPD_CONF_FILE_PATH "/etc/udhcpd.conf"
#define FILE_SIZE 1024
#define SPACE 32
#define NEW_LINE 10
#define BUFFER_ADJUSTMENT 128
#define DHCP_PID "> /tmp/pidof"
#define DHCP_PATH "/tmp/pidof"
#define DHCPv4_PID "pidof "

#ifndef ULONG
#define ULONG unsigned long
#endif

#ifndef CHAR
#define CHAR  char
#endif

#ifndef UCHAR
#define UCHAR unsigned char
#endif

#ifndef INT
#define INT   int
#endif

#ifndef UINT
#define UINT  unsigned int
#endif

#include <stdbool.h>

typedef struct config_values
{
        CHAR *gateway;
        CHAR *subnet;
        CHAR *start;
        CHAR *end;
        CHAR *lease_time;
}ConfigValues;


/* CcspHalGetConfigValue() function */
/**
* @description Gets the dhcpv4 configuration (starting and ending)values
*
* @param key - Config key for which value to be retrieved
* @param value - Config value, to be returned
* @param size - Size of the config value
*
* @return The status of the operation
* @retval STATUS_SUCCESS if successful
* @retval STATUS_FAILURE if any error is detected
*
* @execution Synchronous
* @sideeffect None
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT CcspHalGetConfigValue(CHAR *key, CHAR *value, INT size);


/* CcspHalGetConfigLeaseValue() function */
/**
* @description Gets the dhcpv4 configuration(lease time)value
*
* @param key - Config key "lease", for which value to be retrieved
* @param value - Config value of "lease", to be returned
* @param size - Size of the config value
*
* @return The status of the operation
* @retval STATUS_SUCCESS if successful
* @retval STATUS_FAILURE if any error is detected
*
* @execution Synchronous
* @sideeffect None
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT CcspHalGetConfigLeaseValue(CHAR *key, CHAR *value, INT size);


/* CcspHal_change_config_value() function */
/**
* @description Pass the inputs to dhcpv4 configuration file
*
* @param field_name - Field name from configuration file
* @param field_value - Config value
* @param buf - Size of config value
* @param nbytes - No. of bytes 
*
* @return The status of the operation
* @retval STATUS_SUCCESS if successful
* @retval STATUS_FAILURE if any error is detected
*
* @execution Synchronous
* @sideeffect None
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT CcspHal_change_config_value(CHAR *field_name, CHAR *field_value, CHAR *buf, UINT *nbytes);


/* CcspHalSetDHCPConfigValues() function */
/**
* @description Set the inputs values to dhcpv4 configuration value
*
* @param value_flag - Flag value, used to set the corresponding "ConfigValues" 
structure element
* @param config_value - Config value
*
* @return The status of the operation
* @retval STATUS_SUCCESS if successful
* @retval STATUS_FAILURE if any error is detected
*
* @execution Synchronous
* @sideeffect None
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT CcspHalSetDHCPConfigValues(UINT value_flag, ConfigValues *config_value);

/* CcspHalInterfacesetval() function */
/**
* @description sets the eth1 interface(ip address)
*
* @param name - Interface Name (eg:- brlan0)
* @param str - Gateway IP address
*
* @return The status of the operation
* @retval STATUS_SUCCESS if successful
* @retval STATUS_FAILURE if any error is detected
*
* @execution Synchronous
* @sideeffect None
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT CcspHalInterfacesetval(CHAR *name,CHAR *str);

/* CcspHalNetmasksetvalue() function */
/**
* @description Sets the eth1 interface(netmask)
*
* @param name - Interface Name (eg:- brlan0)
* @param str - Subnet IP address
*
* @return The status of the operation
* @retval STATUS_SUCCESS if successful
* @retval STATUS_FAILURE if any error is detected
*
* @execution Synchronous
* @sideeffect None
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT CcspHalNetmasksetvalue(CHAR *name,CHAR *str);

/* CcspHalGetPIDbyName() function */
/**
* @description Gets the process id of dhcp server
*
* @param pidName - dhcp server process Name
*
* @return Process Id of dhcp server
*
* @execution Synchronous
* @sideeffect None
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/

INT CcspHalGetPIDbyName(CHAR* pidName);

/* CcspHalNoofClientConnected() function */
/**
* @description To get number of client connected devices
*
* @param None
*
* @return No. of connected devices
*
* @execution Synchronous
* @sideeffect None
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
ULONG CcspHalNoofClientConnected();

/* checkLan() function */
/**
* @description To check the Lan connection
*
* @param None
*
* @return Status of the LAN connection 
*
* @execution Synchronous
* @sideeffect None
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
bool checkLan();

/* CcspHalUpdateInterfaceval() function */
/**
* @description To set new Gateway IP address to Lighttpd WebServer
*
* @param newgatewayip - Gateway IP address
*
* @return The status of the operation
* @retval STATUS_SUCCESS if successful
* @retval STATUS_FAILURE if any error is detected
*
* @execution Synchronous
* @sideeffect None
*
* @note This function must not suspend and must not invoke any blocking system
* calls. It should probably just send a message to a driver event handler task.
*
*/
INT CcspHalUpdateInterfaceval(CHAR *newgatewayip);



#endif



