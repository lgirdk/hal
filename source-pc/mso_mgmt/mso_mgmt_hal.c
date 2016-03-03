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

