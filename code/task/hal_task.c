/**
 **************************************************************************************************
 * @file        hal_task.c
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
#include "hal_task.h"

/**
 * @addtogroup    XXX 
 * @{  
 */
#include "bsp_led.h"
/**
 * @addtogroup    hal_task_Modules 
 * @{  
 */

/**
 * @defgroup      hal_task_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      hal_task_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      hal_task_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      hal_task_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      hal_task_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      hal_task_Public_Variables 
 * @brief         
 * @{  
 */
uint8_t g_HalTask_Id = 0;
/**
 * @}
 */

/**
 * @defgroup      hal_task_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      hal_task_Functions 
 * @brief         
 * @{  
 */
void HalTask_Init(uint8_t taskId)
{
    g_HalTask_Id = taskId;
	
	BSP_LED_Init();
}

osal_event_t HalTask_Process(uint8_t taskid,osal_event_t events)
{
	if (events & HAL_TASK_LED_BLINK_EVENT)
    {			
		BSP_LED_Update();
        return events ^ HAL_TASK_LED_BLINK_EVENT;
    }
	if (events & HAL_TASK_ADC_CALC_EVENT)
    {			
        return events ^ HAL_TASK_ADC_CALC_EVENT;
    }
    return 0;
}

void HalTask_Send_Event(osal_event_t events)
{
    OS_Events_Set(g_HalTask_Id,events);
}

void HalTask_Clear_Event(osal_event_t events)
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

