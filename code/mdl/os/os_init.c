/**
 **************************************************************************************************
 * @file        os_init.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "os_init.h"
#include "FreeRTOS.h"
#include "task.h"
#include "clog.h"
/**
 * @addtogroup    XXX 
 * @{  
 */
#include "hal_task.h"
#include "user_task.h"


/**
 * @addtogroup    os_init_Modules 
 * @{  
 */

/**
 * @defgroup      os_init_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      os_init_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      os_init_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      os_init_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      os_init_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      os_init_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      os_init_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      os_init_Functions 
 * @brief         
 * @{  
 */
 
void RTOS_Init(void)
{
	BaseType_t basetype = { 0 };
	basetype = xTaskCreate(Hal_Task,\
							"Hal_Task",\
							1024,
							NULL,
							3,
							(TaskHandle_t *)NULL);

	basetype = xTaskCreate(	User_Task,\
							"User_Task",\
							1024,
							NULL,
							2,
							(TaskHandle_t *)NULL);
	
	
	
	
	if(pdPASS == basetype)
	{
		vTaskStartScheduler();
	}
	else
	{
		
	}
	
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

