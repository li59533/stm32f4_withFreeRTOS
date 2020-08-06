/**
 **************************************************************************************************
 * @file        bsp_uart.h
 * @author
 * @version
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#ifndef _BSP_UART_H_
#define _BSP_UART_H_

/**
 * @addtogroup    XXX 
 * @{ 
 */
#include "self_def.h"
#include "stm32f4xx.h"
/**
 * @addtogroup    bsp_uart_Modules 
 * @{  
 */

/**
 * @defgroup      bsp_uart_Exported_Macros 
 * @{  
 */
#define BSP_UART_COUNT			2
#define BSP_USART1				0
//#define	BSP_USART2			1
#define BSP_USART6				1


#define BSP_USART1_TXBUF_SIZE 	300	
#define BSP_USART1_RXBUF_SIZE	300
#define BSP_USART2_TXBUF_SIZE	300
#define BSP_USART2_RXBUF_SIZE	300

#define BSP_USART6_TXBUF_SIZE	300
#define BSP_USART6_RXBUF_SIZE	300


#define BSP_USART1_TX_DMA_ACTIVE 	1
#define BSP_USART1_RX_DMA_ACTIVE	1

#if BSP_USART1_RX_DMA_ACTIVE == 1
	#define BSP_USART1_IDEL_ACTIVE  1
#else
	#define BSP_USART1_IDEL_ACTIVE  0
#endif


#define BSP_USART6_TX_DMA_ACTIVE 	1
#define BSP_USART6_RX_DMA_ACTIVE	1

#if BSP_USART6_RX_DMA_ACTIVE == 1
	#define BSP_USART6_IDEL_ACTIVE  1
#else
	#define BSP_USART6_IDEL_ACTIVE  0
#endif


/**
 * @}
 */

/**
 * @defgroup      bsp_uart_Exported_Constants
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_uart_Exported_Types 
 * @{  
 */
typedef struct
{
    uint8_t *pData;
    uint16_t Size;
    uint16_t Count;
    uint16_t In;
    uint16_t Out;
}USART_Buf_t;

typedef struct
{
    USART_TypeDef   *Instance;
    USART_Buf_t   TxBuf;
    uint16_t      TxCount;
    USART_Buf_t   RxBuf;
}STM32F4xxUSART_Instance_t;
/**
 * @}
 */

/**
 * @defgroup      bsp_uart_Exported_Variables 
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_uart_Exported_Functions 
 * @{  
 */
 
void BSP_USART_Open(uint8_t BSP_USARTx, uint8_t *userparams);
void BSP_USART_IRQHandler(uint8_t BSP_USARTx);
void BSP_USART_WriteBytes_DMA(uint8_t BSP_USARTx,uint8_t* pBuf,uint16_t length);
void BSP_USART1_TxDMA_IRQHandler(void);
void BSP_USART_WriteBytes(uint8_t BSP_USARTx,uint8_t* pBuf,uint16_t length);
	
void BSP_USART6_TxDMA_IRQHandler(void);

void Test_UART_DMASEND(void);
 
// ------------Test-------------
void BSP_Uart_Test_Send(void);

// -----------------------------

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
