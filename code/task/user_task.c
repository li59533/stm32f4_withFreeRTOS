/**
 **************************************************************************************************
 * @file        user_task.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "self_def.h"
#include "osal.h"
#include "clog.h"
#include "user_task.h"
/**
 * @addtogroup    XXX 
 * @{  
 */
#include "bsp_led.h"
/**
 * @addtogroup    user_task_Modules 
 * @{  
 */

/**
 * @defgroup      user_task_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      user_task_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      user_task_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      user_task_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      user_task_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      user_task_Public_Variables 
 * @brief         
 * @{  
 */
uint8_t g_UserTask_Id = 0;
/**
 * @}
 */

/**
 * @defgroup      user_task_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      user_task_Functions 
 * @brief         
 * @{  
 */
void UserTask_Init(uint8_t taskId)
{
    g_UserTask_Id = taskId;
	UserTask_Send_Event(USER_TASK_LOOP_EVENT);
	UserTask_Send_Event(USER_TASK_LOOP2_EVENT);
	
	
	BSP_LED_Blink(BSP_LED_TEST , 0, 50, 1000);
}

osal_event_t UserTask_Process(uint8_t taskid,osal_event_t events)
{
    if (events & USER_TASK_LOOP_EVENT)
    {
		DEBUG("USER_TASK_LOOP_EVENT\r\n");
		BSP_LED_Blink(BSP_LED_TEST , 3, 20, 150);
		OS_Timer_Start(g_UserTask_Id, USER_TASK_LOOP_EVENT,1000);			
        return events ^ USER_TASK_LOOP_EVENT;
    }
	
    if (events & USER_TASK_LOOP2_EVENT)
    {
		DEBUG("USER_TASK2_LOOP_EVENT\r\n");

		OS_Timer_Start(g_UserTask_Id, USER_TASK_LOOP2_EVENT,1000);			
        return events ^ USER_TASK_LOOP2_EVENT;
    }	
	
    return 0;
}

void UserTask_Send_Event(osal_event_t events)
{
    OS_Events_Set(g_UserTask_Id,events);
}

void UserTask_Timer_Start_Event(osal_event_t event_flag,uint32_t timeout)
{
	OS_Timer_Start(g_UserTask_Id, event_flag,timeout);	
}


void UserTask_Clear_Event(osal_event_t events)
{

}

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

