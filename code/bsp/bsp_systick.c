/**
 **************************************************************************************************
 * @file        bsp_systick.c
 * @author
 * @version
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */

#include "bsp_systick.h"
#include "bsp_conf.h"

/**
 * @addtogroup    XXX 
 * @{  
 */
#include "clog.h"
/**
 * @addtogroup    bsp_systick_Modules 
 * @{  
 */

/**
 * @defgroup      bsp_systick_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup       bsp_systick_Macros_Defines 
 * @brief         
 * @{  
 */
#define  TICK_INT_PRIORITY            ((uint32_t)0U)   /*!< tick interrupt priority */ 
/**
 * @}
 */

/**
 * @defgroup      bsp_systick_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup       bsp_systick_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_systick_Private_Variables 
 * @brief         
 * @{  
 */
static uint32_t s_Systick_Ticks = 0;
/**
 * @}
 */

/**
 * @defgroup      bsp_systick_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_systick_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_systick_Functions 
 * @brief         
 * @{  
 */
void BSP_SysTick_Init(void)
{
	/* Configure the SysTick to have interrupt in 1ms time basis*/
	if (HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq)) > 0U)
	{

	}	
	/* Configure the SysTick IRQ priority */
	if (TICK_INT_PRIORITY < (1UL << __NVIC_PRIO_BITS))
	{
		HAL_NVIC_SetPriority(SysTick_IRQn, TICK_INT_PRIORITY, 0U);
		uwTickPrio = TICK_INT_PRIORITY;
	}
	else
	{

	}	
	
	
	
	//SysTick_Config(CLOCK_GetFreq(kCLOCK_CoreSysClk) / 1000);
}

void BSP_SysTick_DisableIRQ(void)
{
	//SysTick->CTRL = 0x00010006;
	//NVIC_DisableIRQ(SysTick_IRQn);
}



void BSP_SYSTICK_IncTick(void)
{
    s_Systick_Ticks++;
}

uint32_t BSP_SYSTICK_GetTick(void)
{
    return s_Systick_Ticks;
}


void BSP_Systick_Delayms(uint32_t ticks) // block delay
{
    uint32_t tickstart = 0;
    tickstart = BSP_SYSTICK_GetTick();
    while ((BSP_SYSTICK_GetTick() - tickstart) < ticks) 
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

