#ifndef __DHCPV4_EMU_API_H__
#define __DHCPV4_EMU_API_H__



#define GATEWAY 1
#define SUBNET_MASK 2
#define DHCP_STARTING_RANGE 4
#define DHCP_ENDING_RANGE 8
#define DHCP_LEASE_TIME 16
#define DNSMASQ_CONF_FILE_PATH "/etc/dnsmasq.conf"
#define FILE_SIZE 1024
#define SPACE 32
#define NEW_LINE 10
#define BUFFER_ADJUSTMENT 128
#define MAX_NUM_HOST 50
#define COSA_DML_ALIAS_NAME_LENGTH 64
#define IPV4_ADDRESS_SIZE 4
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

#ifndef ANSC_IPV4_ADDRESS
/*
 * While we're trying really hard to smooth the procedure of switch-over from IPv4 to IPv4, there
 * are many places where using the IP address as an integer for comparision and calculation is much
 * easier than array-based operation.
 */
#define  ANSC_IPV4_ADDRESS                                                                  \
         union                                                                              \
         {                                                                                  \
            UCHAR                   Dot[IPV4_ADDRESS_SIZE];                                 \
            ULONG                   Value;                                                  \
         }
#endif

#include <stdbool.h>


struct hostDetails   
{
        char hostName[20];
};

struct
_HALCOSA_DML_DHCPS_SADDR
{
    ULONG                           InstanceNumber;
    char                            Alias[COSA_DML_ALIAS_NAME_LENGTH];

    bool                            bEnabled;
    UCHAR                           Chaddr[6];
    ANSC_IPV4_ADDRESS               Yiaddr;
    char                            DeviceName[COSA_DML_ALIAS_NAME_LENGTH];
    char                            Comment[256];
    bool                            ActiveFlag;
};
typedef  struct _HALCOSA_DML_DHCPS_SADDR HALCOSA_DML_DHCPS_SADDR,  *HALPCOSA_DML_DHCPS_SADDR;

/*
 *  Procedure     : CcspHalGetConfigValues
 *  Purpose       : To Get current DHCPv4 parameter values from dnsmasq configuration file
 *
 *  Parameters    : 
 *     value_flag : To Get current value_flag status (subnet_mask,DHCP_starting & Ending Range,Lease Time)
 *     value      : Current DHCP parameter value should be stored 
 *     size       : size of value 
 *  Return_values : 
 *      value     : Current DHCP parameter value , to be returned
 *      size      : size of value, to be returned
 */

void CcspHalGetConfigValues(INT value_flag,CHAR *value, INT size);

/*
 *  Procedure     : CcspHalSetDHCPConfigValues
 *  Purpose       : To set current DHCPv4 parameter values to dnsmasq configuration file
 *
 *  Parameters    : 
 *     value_flag : To Get current value_flag status (subnet_mask,DHCP_starting & Ending Range,Lease Time)
 *     value      : Current DHCP parameter value should be stored 
 *  Return_values : The status of the operation
 *     @retval 0 , if successful
 *     @retval<0 , if any error is detected
 */

INT CcspHalSetDHCPConfigValues(INT value_flag,CHAR *value);


/*
 *  Procedure     : CcspHalInterfacesetval
 *  Purpose       : To set current DHCPv4 Router value to Emulator(Gateway)
 *
 *  Parameters    : 
 *     name       : To Get Interface Name 
 *     str        : To Get New Gateway IP Address
 *  Return_values : The status of the operation
 *     @retval 0 , if successful
 *     @retval<0 , if any error is detected
 */

INT CcspHalInterfacesetval(CHAR *name,CHAR *str);

/*
 *  Procedure     : CcspHalNetmasksetvalue
 *  Purpose       : To set current DHCPv4 Subnet value to Emulator
 *
 *  Parameters    : 
 *     name       : To Get Interface Name 
 *     str        : To Get New Subnet Mask Address
 *  Return_values : The status of the operation
 *     @retval 0 , if successful
 *     @retval<0 , if any error is detected
 */


INT CcspHalNetmasksetvalue(CHAR *name,CHAR *str);

/*
 *  Procedure     : CcspHalGetPIDbyName
 *  Purpose       : To Get DHCPv4 server PID (to known ,it should be in Enable or Disable state)
 *
 *  Parameters    : 
 *     pidName    : To get DHPCv4 server Name
 *  Return_values : The status of the operation
 *     @retval 0 , if successful
 *     @retval<0 , if any error is detected
 */

INT CcspHalGetPIDbyName(CHAR* pidName);

/*
 *  Procedure     : CcspHalNoofClientConnected
 *  Purpose       : To Get Total number of connected clients through Emulator(Gateway)
 *
 *  Parameters    : None
 *  Return_values : The status of the operation
 *     @retval 0 , if successful
 *     @retval<0 , if any error is detected
 */

ULONG CcspHalNoofClientConnected();

/*
 *  Procedure     : checkLan
 *  Purpose       : To check the Lan status
 *
 *  Parameters    : None
 *  Return_values : The status of the operation
 *     @retval TRUE , if successful
 *     @retval FALSE , if any error is detected
 */

bool checkLan();

/*
 *  Procedure     : CcspHalUpdateInterfaceval
 *  Purpose       : To set new Gateway IP address to Lighttpd WebServer
 *
 *  Parameters    : 
 *   newgatewayip : Having New Gateway IP Address
 *  Return_values : The status of the operation
 *     @retval 0 , if successful
 *     @retval<0 , if any error is detected
 */

INT CcspHalUpdateInterfaceval(CHAR *newgatewayip);

/*
 *  Procedure           : updateReservedIp
 *  Purpose             : It will edit the Existing Reserved IP in static Table Entry
 *
 *  Parameters          : 
 *   hostPtr            : Having connected clients details. 
 *   pDhcpStaticAddress : Having static table entry details.
 *  Return_values       : None
 */


void updateReservedIp(struct hostDetails *hostPtr,HALPCOSA_DML_DHCPS_SADDR pDhcpStaticAddress);

/*
 *  Procedure           : CcspHalDHCPv4ReservedClients
 *  Purpose             : To set Reserved IP in Static Entry Table 
 *
 *  Parameters          : 
 *   pDhcpStaticAddress : Having Static Table Entry.
 *  Return_values       : None
 */

void CcspHalDHCPv4ReservedClients(HALPCOSA_DML_DHCPS_SADDR pDhcpStaticAddress);

/*
 *  Procedure           : CcspHalDHCPv4DeleteReservedClients
 *  Purpose             : To delete Reserved IP in Static Entry Table 
 *
 *  Parameters          : 
 *   pDhcpStaticAddress : Having Static Table Entry.
 *  Return_values       : None
 */

void CcspHalDHCPv4DeleteReservedClients(HALPCOSA_DML_DHCPS_SADDR pDhcpStaticAddress);

/*
 *  Procedure           : RestartDnsmasq
 *  Purpose             : Restart the dnsmasq with updated configuration
 *
 *  Parameters          : None
 *  Return_values       : None
 */

void RestartDnsmasq();

#endif



