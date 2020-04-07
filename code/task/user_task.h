/**
 **************************************************************************************************
 * @file        user_task.h
 * @author
 * @version    v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _USER_TASK_H_
#define _USER_TASK_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */
#include "osal.h"
/**
 * @addtogroup    user_task_Modules 
 * @{  
 */

/**
 * @defgroup      user_task_Exported_Macros 
 * @{  
 */

#define USER_TASK_LOOP_EVENT            0x0001
#define USER_TASK_LOOP2_EVENT           0x0002

/**
 * @}
 */

/**
 * @defgroup      user_task_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      user_task_Exported_Types 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      user_task_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      user_task_Exported_Functions 
 * @{  
 */
void UserTask_Init(uint8_t taskId);
osal_event_t UserTask_Process(uint8_t taskid,osal_event_t events);
void UserTask_Send_Event(osal_event_t events);
void UserTask_Timer_Start_Event(osal_event_t event_flag,uint32_t timeout);
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */
#endif
