#ifndef __MSO_MGMT_HAL_H__
#define __MSO_MGMT_HAL_H__

/**********************************************************************
               CONSTANT DEFINITIONS
**********************************************************************/

#ifndef CHAR
#define CHAR  char
#endif

#ifndef UCHAR
#define UCHAR unsigned char
#endif

#ifndef BOOLEAN
#define BOOLEAN  unsigned char
#endif

#ifndef INT
#define INT   int
#endif

#ifndef UINT
#define UINT  unsigned int
#endif

#ifndef ULONG
#define ULONG unsigned long
#endif

#ifndef TRUE
#define TRUE     1
#endif

#ifndef FALSE
#define FALSE    0
#endif

#ifndef ENABLE
#define ENABLE   1
#endif

#ifndef RETURN_OK
#define RETURN_OK   0
#endif

#ifndef RETURN_ERR
#define RETURN_ERR   -1
#endif

/**********************************************************************
                STRUCTURE DEFINITIONS
**********************************************************************/

typedef enum
{
    Invalid_PWD,
    Good_PWD,
    Unique_PWD,
    Expired_PWD, 
    TimeError
}
mso_pwd_ret_status;

/* mso_validatepwd() function */
/**
* Description: Validate whether the password passed in matches the password of the day for mso user.
* Parameters : pwd:a pointer to a buffer that was preallocated by the caller. 
* 
* @return The status of the operation.
* @retval mso_pwd_ret_status
            Invalid_PWD,
            Good_PWD,
            Unique_PWD,
            Expired_PWD, 
            TimeError
*
* @execution Synchronous.
* @sideeffect None.
*/
mso_pwd_ret_status mso_validatepwd(char *pwd);

/* mso_set_pod_seed : */
/**
* Description: Sets the PoD seed for mso password validation,
* Parameters: 
*    CHAR* - PoD seed
*
* @return the status of the operation.
* @returnval RETURN_OK if successful.
* @returnval RETURN_ERR if any error is detected.
*
* @execution Synchronous.
* @sideeffect None.
*
* @note This function must not suspend and must not invoke any blocking system 
* calls. It should probably just send a message to a driver event handler task. 
* Newer Broadband Devices MUST decrypt the seed on demand when this HAL is called.
*/
INT mso_set_pod_seed(char *);

/* mso_get_pod_seed : */
/**
* Description: Gets the PoD seed for mso password validation,
* Parameters: 
*    CHAR* pSeed - a pointer to a buffer that was preallocated by the caller.  This is where the output is written
*
* @return the status of the operation.
* @returnval RETURN_OK if successful.
* @returnval RETURN_ERR if any error is detected.
*
* @execution Synchronous.
* @sideeffect None.
*
* @note This function retrieves the decrypted seed set in the Config file 
*       and SNMP OID rdkbEncryptedClientSeed. pSeed for security reasons MUST be manually
*       overwritten after use.
*/
INT mso_get_pod_seed(char* pSeed);

#endif

