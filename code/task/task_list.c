/**
 **************************************************************************************************
 * @file        task_list.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "task_list.h"
#include "FreeRTOS.h"
#include "task.h"
#include "clog.h"


/**
 * @addtogroup    XXX 
 * @{  
 */

#include "first_task.h"
#include "second_task.h"


/**
 * @addtogroup    task_list_Modules 
 * @{  
 */

/**
 * @defgroup      task_list_IO_Defines 
 * @brief         
 * @{  
 */
 
#define  CMSIS_OS2	
 
#ifdef CMSIS_OS2 
	#include "cmsis_os.h"
#else
	vTaskStartScheduler();
#endif
/**
 * @}
 */

/**
 * @defgroup      task_list_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      task_list_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      task_list_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      task_list_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      task_list_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      task_list_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */
static void blockling_delay(void);
/**
 * @}
 */

/**
 * @defgroup      task_list_Functions 
 * @brief         
 * @{  
 */

void RTOS_Init(void)
{
	BaseType_t basetype = { 0 };

	#ifdef CMSIS_OS2   
	osKernelInitialize();
	#else
	
	#endif	

	basetype = Second_Task_Init();
	basetype = First_Task_Init();

	if(pdPASS == basetype)
	{
		#ifdef CMSIS_OS2   
		osKernelStart();
		#else
		vTaskStartScheduler();
		#endif
	}
	else
	{
		while(1)
		{
			blockling_delay();
			DEBUG("RTOS is not start\r\n");
		}
	}
	
}

static void blockling_delay(void)
{
	for(uint32_t i = 0 ; i < 3000 ; i ++)
	{
		__nop();
	}
}
/*
static StackType_t 		IdleTaskStack[configMINIMAL_STACK_SIZE];			//�������������ջ
static StaticTask_t 	IdleTaskTCB;																	//����������ƿ�
static StackType_t 		TimerTaskStack[configTIMER_TASK_STACK_DEPTH];	//��ʱ�����������ջ
static StaticTask_t 	TimerTaskTCB;	

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
	*ppxIdleTaskTCBBuffer=&IdleTaskTCB;
	*ppxIdleTaskStackBuffer=IdleTaskStack;
	*pulIdleTaskStackSize=configMINIMAL_STACK_SIZE;
}

void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize)
{
	*ppxTimerTaskTCBBuffer=&TimerTaskTCB;
	*ppxTimerTaskStackBuffer=TimerTaskStack;
	*pulTimerTaskStackSize=configTIMER_TASK_STACK_DEPTH;
}
*/

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

