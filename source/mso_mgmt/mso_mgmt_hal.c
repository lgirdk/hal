#include "mso_mgmt_hal.h"

/* mso_getpwd() function */
/**
* Description: Gets the password of the day for mso user.
* Parameters : pwd:a pointer to a buffer that was preallocated by the caller.  This is where the output is written 
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
*
*
*/
mso_pwd_ret_status mso_validatepwd(char *pwd)
{
  mso_pwd_ret_status ReturnVal = Invalid_PWD;
  return ReturnVal;
}

/* mso_set_pod_seed : */
/**
* Description: Sets the PoD seed for mso password validation,
* Parameters: 
*    CHAR* seed - PoD seed
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
*
*/
INT mso_set_pod_seed(char* pSeed)
{
    if (pSeed == NULL)
    {
        return RETURN_ERR;
    }
    else
    {
        return RETURN_OK;
    }
}
