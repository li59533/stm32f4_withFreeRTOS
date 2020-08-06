/**
 **************************************************************************************************
 * @file        bsp_clock.h
 * @author
 * @version
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _BSP_CLOCK_H_
#define _BSP_CLOCK_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */
#include "bsp_conf.h"
/**
 * @addtogroup    bsp_clock_Modules 
 * @{  
 */

/**
 * @defgroup      bsp_clock_Exported_Macros 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_clock_Exported_Constants
 * @{  
 */


/**
 * @}
 */

/**
 * @defgroup      bsp_clock_Exported_Types 
 * @{  
 */
typedef enum
{
	ClockRun_Mode  = 1, 
	StopRun_Mode , 
}BSP_ClockMode_e;

/**
 * @}
 */

/**
 * @defgroup      bsp_clock_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_clock_Exported_Functions 
 * @{  
 */
void BSP_Clock_Init(uint8_t bsp_clock_mode);
void SystemClock_Config(void);

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
