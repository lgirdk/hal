#ifndef __FIREWALL_EMU_API_H__
#define __FIREWALL_EMU_API_H__

#ifndef ULONG
#define ULONG unsigned long
#endif

#ifndef UCHAR
#define UCHAR unsigned char
#define BOOLEAN UCHAR
#endif

#ifndef  INTERFACE_SIZE
#define  INTERFACE_SIZE     16
#endif

#define ADD             	 1
#define DELETE        		 2
#define REPLACE         	 3
#define ENABLE          	 4
#define DISABLE         	 5
#define SITE			 1
#define SERVICE			 2
#define SERVICE_TYPE		 1
#define DEVICE_TYPE 		 2
#define SITE_TYPE 		 3
#define TRUSTEDSITE_TYPE 	 4
#define TRUSTEDSERVICE_TYPE 	 5

/****************************************************************
			ENUM DECLARATIONS
*****************************************************************/

typedef enum
{
    IPADDR_IPV4 = 1,
    IPADDR_IPV6 = 2,
}
COSA_DML_IPADDR_TYPE;

typedef enum
{
    PROTO_TCP = 1,
    PROTO_UDP = 2,
    PROTO_BOTH = 3,
}
COSA_DML_PROTO_TYPE;

typedef enum
{
    BLOCK_METHOD_URL = 1,
    BLOCK_METHOD_KEYWORD = 2,
}
COSA_DML_BLOCK_METHOD;

typedef enum
{
    MD_TYPE_BLOCK = 1,
    MD_TYPE_ALLOW = 2,
}
COSA_DML_MD_TYPE;


/*********************************************************
		STRUCTURE DEFINITIONS
**********************************************************/
struct custom_option
{
  int isHttpBlocked;
  int isHttpsBlocked;
  int isPingBlocked;
  int isIdentBlocked;
  int isMulticastBlocked;
  int isP2pBlocked;
  int isFirewallEnabled;
};


struct NetworkDetails
{
   char 		     UpLink_IF[INTERFACE_SIZE];
   char 		     UpLinkBr_IF[INTERFACE_SIZE];
   ANSC_IPV4_ADDRESS         WanIPAddress;
   ANSC_IPV4_MASK            WanSubnetMask;
   ANSC_IPV4_ADDRESS         LanIPAddress;
   ANSC_IPV4_MASK            LanSubnetMask;
};

struct
_COSA_DML_RA_CFG
{
    /*
     *  Extensions -- X_CISCO_COM_RemoteAccess
     */
    BOOLEAN                         bEnabled;
    char                            SupportedProtocols[64];
    BOOLEAN                         bFromAnyIp;
    ANSC_IPV4_ADDRESS               StartIp;
    ANSC_IPV4_ADDRESS               EndIp;
    BOOLEAN                         HttpEnable;
    ULONG                           HttpPort;
    BOOLEAN                         HttpsEnable;
    ULONG                           HttpsPort;
    BOOLEAN                         SSHEnable;
    ULONG                           SSHPort;
    BOOLEAN                         TelnetEnable;
    ULONG                           TelnetPort;
    BOOLEAN                         UpgradePermission;
    char                            StartIpV6[64];
    char                            EndIpV6[64];
}_struct_pack_;

typedef struct _COSA_DML_RA_CFG  COSA_DML_RA_CFG,  *PCOSA_DML_RA_CFG;


/*
 * .ManagedSites.
 */
typedef struct
_COSA_DML_MANAGEDSITES
{
    BOOL            Enable;
}
COSA_DML_MANAGEDSITES;

/*
 * .ManagedSites.BlockedURL.{i}.
 */
typedef struct
_COSA_DML_BLOCKEDURL
{
    ULONG           InstanceNumber;
    char            Alias[256];

    COSA_DML_BLOCK_METHOD BlockMethod;
    char            Site[1025];
    BOOL            AlwaysBlock;
    char            StartTime[64];
    char            EndTime[64];
    BOOL            StartTimeFlg;
    BOOL            EndTimeFlg;
    char            BlockDays[64];
    char            MAC[32];
    char            DeviceName[128];
}
COSA_DML_BLOCKEDURL;
/*
 * .ManagedSites.TrustedUser.{i}.
 */
typedef struct
_COSA_DML_TRUSTEDUSER
{
    ULONG                   InstanceNumber;
    char                    Alias[256];

    char                    HostDescription[64];
    COSA_DML_IPADDR_TYPE    IPAddressType;
    char                    IPAddress[64];
    BOOL                    Trusted;
}
COSA_DML_TRUSTEDUSER;

/*
 * .ManagedServices.
 */
typedef struct
_COSA_DML_MANAGED_SERVS
{
    BOOL            Enable;
}
COSA_DML_MANAGED_SERVS;

/*
 * .ManagedServices.Service.{i}.
 */
typedef struct
_COSA_DML_MS_SERV
{
    ULONG           InstanceNumber;
    char            Alias[256];

    char            Description[64];
    COSA_DML_PROTO_TYPE Protocol;
    ULONG           StartPort;
    ULONG           EndPort;
    BOOL            AlwaysBlock;
    char            StartTime[64];
    char            EndTime[64];
    char            BlockDays[64];
}
COSA_DML_MS_SERV;
/*
 * .ManagedServices.TrustedUser.{i}.
 */
typedef struct
_COSA_DML_MS_TRUSTEDUSER
{
    ULONG           InstanceNumber;
    char            Alias[256];

    char                    HostDescription[64];
    COSA_DML_IPADDR_TYPE    IPAddressType;
    char                    IPAddress[64];
    BOOL                    Trusted;
}
COSA_DML_MS_TRUSTEDUSER;

/*
 * .ManagedDevices.
 */
typedef struct
_COSA_DML_MANAGED_DEVS
{
    BOOL            Enable;
    BOOL            AllowAll;
}
COSA_DML_MANAGED_DEVS;
/*
 * .ManagedDevices.Device.{i}.
 */
typedef struct
_COSA_DML_MD_DEV
{
    ULONG           InstanceNumber;
    char            Alias[256];

    COSA_DML_MD_TYPE Type;
    char            Description[64];
    char            MACAddress[64];
    BOOL            AlwaysBlock;
    char            StartTime[64];
    char            EndTime[64];
    char            BlockDays[64];
}
COSA_DML_MD_DEV;

/*******************************************************************
		           FUNCTION PROTOTYPES
********************************************************************/

/*********************** FIREWALL DECLARATIONS ******************/
int firewall_service_init(struct custom_option *option);
int firewall_service_start(char *level,struct NetworkDetails *netDetails);
int firewall_service_restart(char *level,struct NetworkDetails *netDetails);
int firewall_service_stop(char *level);
int firewall_service_close();

/*********************** REMOTE MANAGEMENT DECLARATIONS ****************/

/** Getting Current HttpPort value from lighttpd Configuration file **/
int GetHttpPortValue(ULONG value);
/** Getting Current HttpsPort value from lighttpd Configuration file **/
int GetHttpsPortValue(ULONG value);
/** To Delete Wan2Lan log setup connection **/
int Wan2lan_log_deletion_setup(struct NetworkDetails *netDetails);
/** To Insert Wan2Lan log setup connection **/
int Wan2lan_log_insertion_setup(struct NetworkDetails *netDetails);
/** Getting Current WAN IP Address for Deletion purpose **/
int GettingWanIP_remotemgmt_deletion_logsetup();
/** Getting Curent WAN IP Address for Insertion purpose **/
int GettingWanIP_remotemgmt_insertion_logsetup();
/** To Delete Whole Remote Management Iptables Mapping setup Connection **/
int DeleteRemoteManagementIptablesRules();
/** To Insert Whole Remote Management Iptables Mapping Setup Connection **/
int AddRemoteManagementIptablesRules();
/** To Disable Httpsport to lighttpd configuration file **/
int DisablingHttps();
/** To Enable Httpsport to lighttpd configuration file **/
int EnablingHttps();
/** To Disable Httpport to lighttpd configuration file **/
int DisablingHttp();
/** To Enable Httpport to lighttpd configuration file **/
int EnablingHttp();
/** To Set New HttpPort Value to lighttpd web server **/
int SetHttpPort(unsigned long htttpport);
/** To Set New HttpsPort Value to lighttpd Web Server **/
int SetHttpsPort(unsigned long httpssport);
/** Remote Management Operations **/
int RemoteManagementiptableRulessetoperation(PCOSA_DML_RA_CFG pCfg);

/******************** BASIC ROUTING WAN2LAN CONNECTIONS **************/
int BasicRouting_Wan2Lan_SetupConnection();

/******************** DMZ DECLARATIONS ************************/

/** To Insert Lan2Wan log setup connection **/
int Lan2Wan_insertion_logsetup(struct NetworkDetails *netDetails);
/** To Delete Lan2Wan log setup connection **/
int Lan2Wan_Deletion_logsetup(struct NetworkDetails *netDetails);
/** Getting current LAN IP Address for Insertion Purposes **/
int GettingLanIP_Insertion_logsetup();
/** Getting Current LAN IP Address for Deletion Purposes **/
int GettingLanIP_Deletion_logsetup();
/** To Delete Whole DMZ Iptables Mapping Setup Connection **/
int DeleteDMZIptableRules();
/** To Add Whole DMZ Iptables Mapping Setup Connection **/
int  AddDMZIptableRules();
/** DMZ Operation **/
int DMZIptableRulesOperation(char dmzclientip[40]);

/******************** PORTFORWARDING DECLARATIONS ************************/

int port_forwarding_add_rule(UCHAR InternalClient[IPV4_ADDRESS_SIZE],char *prot,USHORT ExternalPort,USHORT ExternalPortEndRange);
int port_forwarding_delete_rule(UCHAR InternalClient[IPV4_ADDRESS_SIZE],char *prot,USHORT ExternalPort,USHORT ExternalPortEndRange);
int port_forwarding_disable();

/******************** PORTTRIGGERING DECLARATIONS ************************/

int port_triggering_add_rule(USHORT TriggerPortStart,USHORT TriggerPortEnd,char *prot,USHORT ForwardPortStart,USHORT ForwardPortEnd);
int port_triggering_delete_rule(USHORT TriggerPortStart,USHORT TriggerPortEnd,char *prot,USHORT ForwardPortStart,USHORT ForwardPortEnd);
int port_triggering_disable();


/******************************** Parental Control **********************/

/** Add ParentalControl_Sites Rule Chain **/
int do_parentalControl_Addrule_Sites();
/** Add ParentalControl_Services Rule Chain **/
int do_parentalControl_Addrule_Services();
/** Add ParentalControl_Devices Rule Chain **/
int do_parentalControl_Addrule_Devices();
/** Delete ParentalControl_Sites Rule Chain **/
int do_parentalControl_Delrule_Sites();
/** Delete ParentalControl_Services Rule Chain **/
int do_parentalControl_Delrule_Services();
/** Delete ParentalControl_Devices Rule Chain **/
int do_parentalControl_Delrule_Devices();
/** Add or Delete Site/Keyword Restriction **/
int do_parentalControl_Sites(int OPERATION,COSA_DML_BLOCKEDURL *i_BlockedURLs);
/** Add or Delete Service Restriction **/
int do_parentalControl_Services(int OPERATION,COSA_DML_MS_SERV *i_MSServs);
/** Add or Delete Device Restriction **/
int do_parentalControl_Devices(int OPERATION,COSA_DML_MD_DEV *i_MDDevs);
/** Add or Delete Trusted Computer on Site and Service Restriction**/
void CosaDmlTrustedUser_Accept(int block_type,char  ipAddress[64],int operation);

#endif
