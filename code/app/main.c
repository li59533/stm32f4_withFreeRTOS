/**
 **************************************************************************************************
 * @file        main.c
 * @author
 * @version
 * @date        2/21/2020
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */

#include "main.h"
#include "board.h"
#include "clog.h"
#include "os_init.h"

#include "bsp_led.h"
/**
 * @addtogroup    XXX 
 * @{  
 */
#include "bsp_conf.h" 
#include "bsp_systick.h"
#include "system_param.h"

/**	
 * @addtogroup    main_Modules 
 * @{  
 */

/**
 * @defgroup      main_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup       main_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      main_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup       main_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      main_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      main_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      main_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      main_Functions 
 * @brief         
 * @{  
 */
int main(void)
{
	
	HAL_Init();
	
	
	Board_Init_ClockRUN();
	
	BSP_SysTick_Init();
	
	Board_Init_BSP();
	
	RTOS_Init();
	
	while(1)
	{
		BSP_LED_TestFunc();
		
		HAL_Delay(1000);
		DEBUG("Test\r\n");
	}


}


void Error_Handler(void)
{
	while(1)
	{
		DEBUG(0,"Error_Handler\r\n");
	};
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

