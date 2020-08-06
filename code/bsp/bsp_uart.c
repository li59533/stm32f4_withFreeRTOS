/**
 **************************************************************************************************
 * @file        bsp_uart.c
 * @author
 * @version
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "bsp_conf.h"
#include "bsp_uart.h"
#include "clog.h"
/**
 * @addtogroup    XXX 
 * @{  
 */
#include "bsp_led.h"

/**
 * @addtogroup    bsp_uart_Modules 
 * @{  
 */

/**
 * @defgroup      bsp_uart_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup       bsp_uart_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_uart_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup       bsp_uart_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_uart_Private_Variables 
 * @brief         
 * @{  
 */
 
UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_tx; 
 
 
static uint8_t USART1_Tx_Buf[BSP_USART1_TXBUF_SIZE] = { 0 };
static uint8_t USART1_Rx_Buf[BSP_USART1_RXBUF_SIZE] = { 0 };

static uint8_t USART6_Tx_Buf[BSP_USART6_TXBUF_SIZE] = { 0 };
static uint8_t USART6_Rx_Buf[BSP_USART6_RXBUF_SIZE] = { 0 };



static STM32F4xxUSART_Instance_t STM32F4xxUSART_Instance[BSP_UART_COUNT] = {
    /* USART1 */
    {
        /* USART_TypeDef */
        .Instance = USART1,
        /* tx buf */
        .TxBuf.pData = USART1_Tx_Buf,
        .TxBuf.Size = sizeof(USART1_Tx_Buf) / sizeof(USART1_Tx_Buf[0]),
        .TxBuf.Count = 0,
        .TxBuf.In = 0,
        .TxBuf.Out = 0,
        /* rx buf */
        .RxBuf.pData = USART1_Rx_Buf,
        .RxBuf.Size = sizeof(USART1_Rx_Buf) / sizeof(USART1_Rx_Buf[0]),
        .RxBuf.Count = 0,
        .RxBuf.In = 0,
        .RxBuf.Out = 0,
    },
    /* USART6 */
    {
        /* USART_TypeDef */
        .Instance = USART6,
        /* tx buf */
        .TxBuf.pData = USART6_Tx_Buf,
        .TxBuf.Size = sizeof(USART6_Tx_Buf) / sizeof(USART6_Tx_Buf[0]),
        .TxBuf.Count = 0,
        .TxBuf.In = 0,
        .TxBuf.Out = 0,
        /* rx buf */
        .RxBuf.pData = USART6_Rx_Buf,
        .RxBuf.Size = sizeof(USART6_Rx_Buf) / sizeof(USART6_Rx_Buf[0]),
        .RxBuf.Count = 0,
        .RxBuf.In = 0,
        .RxBuf.Out = 0,
    },
};


/**
 * @}
 */

/**
 * @defgroup      bsp_uart_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      bsp_uart_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */
static uint16_t bsp_usartTx_getqueuefreespace(uint8_t BSP_USARTx);
static int8_t bsp_usartTx_enqueue(uint8_t BSP_USARTx, uint8_t * buf,uint16_t len);
static uint16_t bsp_getusartTx_count(uint8_t BSP_USARTx);
static int8_t bsp_usartTx_dequeue(uint8_t BSP_USARTx , uint8_t * buf_byte);
/*
static void bsp_usart_485en_init(void);  // init the 485 EN pin
static void bsp_usart_485en_T(uint8_t BSP_USARTx);
static void bsp_usart_485en_R(uint8_t BSP_USARTx);
*/

/**
 * @}
 */

/**
 * @defgroup      bsp_uart_Functions 
 * @brief         
 * @{  
 */


void BSP_USART_Open(uint8_t BSP_USARTx, uint8_t *userparams)
{

	USART_HandleTypeDef USART_Handle ; 
	switch(BSP_USARTx)
	{
		case BSP_USART1:
		{	
			// ----CLK ENABLE----------

			// ------------------------
			
			// ----GPIO INIT-----------

			/* GPIO Alternate functions configuration function ****************************/

			// ------------------------
			/* Initialization and Configuration functions *********************************/
			huart1.Instance = USART1;
			huart1.Init.BaudRate = 115200;
			huart1.Init.WordLength = UART_WORDLENGTH_8B;
			huart1.Init.StopBits = UART_STOPBITS_1;
			huart1.Init.Parity = UART_PARITY_NONE;
			huart1.Init.Mode = UART_MODE_TX_RX;
			huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
			huart1.Init.OverSampling = UART_OVERSAMPLING_16;
			if (HAL_UART_Init(&huart1) != HAL_OK)
			{
			Error_Handler();
			}
			// ---------DMA Init -------------------
			
			if(BSP_USART1_TX_DMA_ACTIVE)
			{

			}
			if(BSP_USART1_RX_DMA_ACTIVE)
			{

			}

			// ---------OPEN IT---------------------
			//USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
			
			if(BSP_USART1_IDEL_ACTIVE)
			{
				
			}
			// -------Init the NVIC-----------------
			
			// ------USART Start -------
			
		}
		break;
		case BSP_USART6:
		{
			// ----CLK ENABLE----------

		}
		break;
		default:break;
	}
	
}

void BSP_USART_Close(uint8_t BSP_USARTx)
{
	
}



// ----------- Msp Func ------------
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	if(huart->Instance == USART1)
	{
		/* USER CODE BEGIN USART1_MspInit 0 */

		/* USER CODE END USART1_MspInit 0 */
		/* Peripheral clock enable */
		__HAL_RCC_USART1_CLK_ENABLE();

		__HAL_RCC_GPIOA_CLK_ENABLE();
		
		/**USART1 GPIO Configuration
		PA9     ------> USART1_TX
		PA10     ------> USART1_RX
		*/
		
		GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		/* USART1 DMA Init */
		/* USART1_TX Init */
		hdma_usart1_tx.Instance = DMA2_Stream7;
		hdma_usart1_tx.Init.Channel = DMA_CHANNEL_4;
		hdma_usart1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
		hdma_usart1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
		hdma_usart1_tx.Init.MemInc = DMA_MINC_ENABLE;
		hdma_usart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
		hdma_usart1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
		hdma_usart1_tx.Init.Mode = DMA_NORMAL;
		hdma_usart1_tx.Init.Priority = DMA_PRIORITY_LOW;
		hdma_usart1_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
		if (HAL_DMA_Init(&hdma_usart1_tx) != HAL_OK)
		{
		Error_Handler();
		}

		__HAL_LINKDMA(huart,hdmatx,hdma_usart1_tx);

		/* USART1 interrupt Init */
		HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(USART1_IRQn);
		/* USER CODE BEGIN USART1_MspInit 1 */

		/* USER CODE END USART1_MspInit 1 */
	}
}


void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
	if(huart->Instance==USART1)
	{
		/* USER CODE BEGIN USART1_MspDeInit 0 */

		/* USER CODE END USART1_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_USART1_CLK_DISABLE();

		/**USART1 GPIO Configuration
		PA9     ------> USART1_TX
		PA10     ------> USART1_RX
		*/
		HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

		/* USART1 DMA DeInit */
		HAL_DMA_DeInit(huart->hdmatx);

		/* USART1 interrupt DeInit */
		HAL_NVIC_DisableIRQ(USART1_IRQn);
		/* USER CODE BEGIN USART1_MspDeInit 1 */

		/* USER CODE END USART1_MspDeInit 1 */
	}
}



// --------------------------------
// ---------- 485 en --------------
/*
static void bsp_usart_485en_R(uint8_t BSP_USARTx)
{
	switch(BSP_USARTx)
	{
		case BSP_USART1: break;
		case BSP_USART6: break;
		default:break;
	}
}

static void bsp_usart_485en_T(uint8_t BSP_USARTx)
{
	switch(BSP_USARTx)
	{
		case BSP_USART1: break;
		case BSP_USART6: break;
		default:break;
	}
}
*/
// --------------------------------

void BSP_USART_WriteBytes_DMA(uint8_t BSP_USARTx,uint8_t* pbuf,uint16_t len)
{
	switch(BSP_USARTx)
	{
		case BSP_USART1:
		{
			bsp_usartTx_enqueue(BSP_USART1,pbuf,len);
			if(bsp_getusartTx_count(BSP_USART1) > 0)
			{
				//HAL_UART_Transmit_DMA(&huart1, uint8_t *pData, uint16_t Size);				
				
				/*
				DMA_Cmd(DMA2_Stream7,DISABLE);	
				bsp_usart_485en_T(BSP_USART1);				
				if(STM32F4xxUSART_Instance[BSP_USART1].TxBuf.In < STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Out)
				{
					DMA2_Stream7->NDTR = STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Size - STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Out;					
				}
				else
				{
					DMA2_Stream7->NDTR = STM32F4xxUSART_Instance[BSP_USART1].TxBuf.In - STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Out;
				}
				
				STM32F4xxUSART_Instance[BSP_USART1].TxCount = DMA2_Stream7->NDTR;
				DMA2_Stream7->M0AR = (uint32_t)(STM32F4xxUSART_Instance[BSP_USART1].TxBuf.pData + STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Out);
				DMA_Cmd(DMA2_Stream7,ENABLE);	
				DMA_ClearITPendingBit(DMA2_Stream7, DMA_IT_TCIF7);
				DMA_ITConfig(DMA2_Stream7, DMA_IT_TC,  ENABLE);
				*/
			}
		}
		break;
		case BSP_USART6:
		{
					
		}
		break;
		default:
		{
			DEBUG("Usart %d is err\r\n",BSP_USARTx);
		}
		break;
	}

	
}

uint16_t BSP_USART_ReadBytes_DMA(uint8_t BSP_USARTx)
{
	return 0;
}


// this send way is very danger !!!!
void BSP_USART_WriteBytes(uint8_t BSP_USARTx,uint8_t* pBuf,uint16_t length)
{

}
	
uint16_t BSP_USART_ReadBytes(uint8_t BSP_USARTx,uint8_t* pBuf,uint16_t length)
{
	return 0;
}

void BSP_USART1_TxDMA_IRQHandler(void)
{
	/*
	if(DMA_GetITStatus(DMA2_Stream7, DMA_IT_TCIF7) == SET)
	{
		DMA_ClearITPendingBit(DMA2_Stream7, DMA_IT_TCIF7);
		
		if(DMA_GetCurrDataCounter(DMA2_Stream7) == 0)
		{
			if(STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Count > STM32F4xxUSART_Instance[BSP_USART1].TxCount)
			{
				STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Count -=STM32F4xxUSART_Instance[BSP_USART1].TxCount;
			}
			else
			{
				STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Count = 0;
			}
			
			STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Out += STM32F4xxUSART_Instance[BSP_USART1].TxCount;
			STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Out %= STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Size;
			
			if(STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Count > 0)
			{
				DMA_Cmd(DMA2_Stream7,DISABLE);				
				if(STM32F4xxUSART_Instance[BSP_USART1].TxBuf.In < STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Out)
				{
					DMA2_Stream7->NDTR = STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Size - STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Out;
					
				}
				else
				{
					DMA2_Stream7->NDTR = STM32F4xxUSART_Instance[BSP_USART1].TxBuf.In - STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Out;
				}
				STM32F4xxUSART_Instance[BSP_USART1].TxCount = DMA2_Stream7->NDTR;
				DMA2_Stream7->M0AR = (uint32_t)(STM32F4xxUSART_Instance[BSP_USART1].TxBuf.pData + STM32F4xxUSART_Instance[BSP_USART1].TxBuf.Out);
				DMA_Cmd(DMA2_Stream7,ENABLE);	
			}
			else
			{
				USART_ITConfig(USART1, USART_IT_TC, ENABLE);
			}
		}
		
	}
	*/
}

void BSP_USART6_TxDMA_IRQHandler(void)
{

}



void BSP_USART_IRQHandler(uint8_t BSP_USARTx)
{
	switch(BSP_USARTx )
	{
		case BSP_USART1:
		{
			/*
			if(USART_GetITStatus(USART1, USART_IT_RXNE) == SET)
			{
				USART_ClearITPendingBit(USART1,USART_IT_RXNE);
			}
			if(USART_GetITStatus(USART1, USART_IT_TC) == SET)
			{
				
				USART_ClearITPendingBit(USART1,USART_IT_TC);
				if(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == SET)
				{
					bsp_usart_485en_R(BSP_USART1);
					USART_ITConfig(USART1, USART_IT_TC, DISABLE);
				}
				
				
			}			
			if(USART_GetITStatus(USART1, USART_IT_IDLE) == SET)
			{
				USART_ReceiveData(USART1);
				USART_GetITStatus(USART1, USART_IT_IDLE);
				
				//DEBUG("IDEL:%d\r\n",DMA_GetCurrDataCounter(DMA2_Stream5));
				
				STM32F4xxUSART_Instance[BSP_USART1].RxBuf.Count += BSP_USART1_RXBUF_SIZE - DMA2_Stream5->NDTR;

				DMA_Cmd(DMA2_Stream5,DISABLE);
				DMA2_Stream5->M0AR = (uint32_t)USART1_Rx_Buf;
				DMA2_Stream5->NDTR = BSP_USART1_RXBUF_SIZE;
				DMA_Cmd(DMA2_Stream5,ENABLE);
			}
			*/
		}
		break;
		case BSP_USART6:
		{
		
		}
		break;
		default:break;
	}
	
}
// -------------------Queue -------------------------
void bsp_usartqueue_init(uint8_t BSP_USARTx)
{
	STM32F4xxUSART_Instance[BSP_USARTx].RxBuf.Count = 0;
	STM32F4xxUSART_Instance[BSP_USARTx].RxBuf.In = 0;
	STM32F4xxUSART_Instance[BSP_USARTx].RxBuf.Out = 0;
	STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Count = 0;
	STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.In = 0;
	STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Out = 0;
}

static uint16_t bsp_usartTx_getqueuefreespace(uint8_t BSP_USARTx)
{
	return STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Size - STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Count;
}

static uint16_t bsp_getusartTx_count(uint8_t BSP_USARTx)
{
	return STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Count;
}

static int8_t bsp_usartTx_enqueue(uint8_t BSP_USARTx, uint8_t * buf,uint16_t len)
{
	uint8_t * but_ptr = 0;
	but_ptr = buf;
	if(bsp_usartTx_getqueuefreespace(BSP_USARTx) < len)
	{
		DEBUG("usartTx is full");
		return -1;
	}
	while(len --)
	{
		STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.pData[STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.In] = *(but_ptr);
		STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Count ++;
		STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.In ++;
		but_ptr ++;
		STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.In %= STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Size;
	}	
	return 1;
}

static int8_t bsp_usartTx_dequeue(uint8_t BSP_USARTx , uint8_t * buf_byte)
{
	if(bsp_getusartTx_count(BSP_USARTx) > 0)
	{
		* buf_byte =  STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.pData[STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Out];
		STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Out ++;
		STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Count --;
		STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Out %= STM32F4xxUSART_Instance[BSP_USARTx].TxBuf.Size;
		
	}
	else
	{
		return -1;
	}
	
	return 1;
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

