/**
 **************************************************************************************************
 * @file        bsp_led.c
 * @author
 * @version
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */

#include "bsp_led.h"
#include "bsp_conf.h"

/**
 * @addtogroup    XXX 
 * @{  
 */

/**
 * @addtogroup    bsp_led_Modules 
 * @{  
 */

/**
 * @defgroup      bsp_led_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup       bsp_led_Macros_Defines 
 * @brief         
 * @{  
 */
/* Modes */
#define BSP_LED_MODE_OFF     0x00
#define BSP_LED_MODE_ON      0x01
#define BSP_LED_MODE_BLINK   0x02
#define BSP_LED_MODE_FLASH   0x04
/**
 * @}
 */

/**
 * @defgroup      bsp_led_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup       bsp_led_Private_Types
 * @brief         
 * @{  
 */
typedef struct {
  uint8_t mode;       /* Operation mode */
#if (defined BSP_LED_BLINK_ENABLE) && (BSP_LED_BLINK_ENABLE == TRUE)
  uint8_t todo;       /* Blink cycles left */
  uint8_t onPct;      /* On cycle percentage */
  uint16_t time;      /* On/off cycle time (msec) */
  uint32_t next;      /* Time for next change */
  uint8_t preBlinkState;
#endif
} BSPLedControl_t; 
 
 
typedef struct
{
	GPIO_TypeDef  *GPIOx;
	GPIO_InitTypeDef GPIO_Init ;

}GPIO_InstanceTypedef;
 
 
typedef struct
{
    GPIO_InstanceTypedef Pin;
    uint8_t OnLevel;
    uint8_t OffLevel;
}LED_IO_Typedef;

const LED_IO_Typedef LED_IO[BSP_LEDCOUNT] = 
{
	{
		{GPIOF , GPIO_PIN_9, GPIO_MODE_OUTPUT_PP , GPIO_PULLUP, GPIO_SPEED_FREQ_VERY_HIGH },
		.OnLevel = 0,
        .OffLevel = 1,
	},
	{
		{GPIOF , GPIO_PIN_10, GPIO_MODE_OUTPUT_PP , GPIO_PULLUP, GPIO_SPEED_FREQ_VERY_HIGH },
		.OnLevel = 0,
        .OffLevel = 1,
	},	
	
};


/**
 * @}
 */

/**
 * @defgroup      bsp_led_Private_Variables 
 * @brief         
 * @{  
 */
static BSPLedControl_t s_BSPLedControlTable[BSP_LEDCOUNT] =
{
    {BSP_LED_MODE_OFF},
	{BSP_LED_MODE_OFF},
};
/**
 * @}
 */

/**
 * @defgroup      bsp_led_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_led_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_led_Functions 
 * @brief         
 * @{  
 */

void BSP_LED_Init(void)
{
	uint8_t i  = 0;

// -------Clock --------

	__HAL_RCC_GPIOF_CLK_ENABLE();
	

// ---------------------	
	for( i = 0 ; i < BSP_LEDCOUNT ; i ++)
	{
		HAL_GPIO_Init(LED_IO[i].Pin.GPIOx, (GPIO_InitTypeDef *)&LED_IO[i].Pin.GPIO_Init);
		
		HAL_GPIO_WritePin(LED_IO[i].Pin.GPIOx , LED_IO[i].Pin.GPIO_Init.Pin,(GPIO_PinState) LED_IO[i].OffLevel);
	}

}


void BSP_LED_Open(uint8_t BSP_LEDx)
{
	HAL_GPIO_WritePin(LED_IO[BSP_LEDx].Pin.GPIOx , LED_IO[BSP_LEDx].Pin.GPIO_Init.Pin,(GPIO_PinState) LED_IO[BSP_LEDx].OnLevel);

	s_BSPLedControlTable[BSP_LEDx].mode = BSP_LED_MODE_ON;
}

void BSP_LED_Close(uint8_t BSP_LEDx)
{
	HAL_GPIO_WritePin(LED_IO[BSP_LEDx].Pin.GPIOx , LED_IO[BSP_LEDx].Pin.GPIO_Init.Pin,(GPIO_PinState) LED_IO[BSP_LEDx].OffLevel);
	s_BSPLedControlTable[BSP_LEDx].mode = BSP_LED_MODE_OFF;
}


void BSP_LED_Toggle(uint8_t BSP_LEDx)
{	
    if (s_BSPLedControlTable[BSP_LEDx].mode & BSP_LED_MODE_ON)
    {
        BSP_LED_Close(BSP_LEDx);
    }
    else 
    {
        BSP_LED_Open(BSP_LEDx);
    }		
}


void BSP_LED_Blink(uint8_t BSP_LEDx, uint8_t numBlinks, uint8_t percent, uint16_t period)
{

}

void BSP_LED_Update(void)
{

}


// ------------Test Func ----------------
void BSP_LED_TestFunc(void)
{
	BSP_LED_Toggle(BSP_LED1);
	BSP_LED_Toggle(BSP_LED2);
}
// --------------------------------------


/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

