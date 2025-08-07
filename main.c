/**
  ******************************************************************************
  * @file  main.c
  * @author  
  * @version
  * @date     
  * @brief
  * @partnumber 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013</center></h2>
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx.h"
#include "stm32g4xx_hal.h"
#include "tx_api.h"
#include "hw_config.h"
#include "CO2.h"
#include "uart.h"

/* Calibration variables ---------------------------------------------------------*/
#define THREAD_STACK_SIZE  1024
#define BYTE_POOL_SIZE     2200
/* System variables ------------- ---------------------------------------------*/
/* Define the ThreadX object control blocks...  */
TX_THREAD               thread_1;
TX_THREAD               thread_2;
TX_BYTE_POOL            byte_pool_0;
UCHAR                   memory_area[BYTE_POOL_SIZE];
HRTIM_HandleTypeDef hhrtim1;

/* Private function prototypes -----------------------------------------------*/
void thread_1_entry(ULONG thread_input);
void thread_2_entry(ULONG thread_input);
/* Private functions ---------------------------------------------------------*/
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_DMA_Init();
  MX_UART_Init();
  MX_I2C1_Init();
  CO2_Init();

  /* Enter the ThreadX kernel.  */

  tx_kernel_enter();



  while(1)
  {



  }


}

/* Define what the initial system looks like.  */

void    tx_application_define(void *first_unused_memory)
{

    CHAR    *pointer = TX_NULL;


    /* Create a byte memory pool from which to allocate the thread stacks.  */
    tx_byte_pool_create(&byte_pool_0, "byte pool 0", memory_area, BYTE_POOL_SIZE);

    /* Put system definition stuff in here, e.g. thread creates and other assorted
       create information.  */

    /* Allocate the stack for thread 0.  */
    tx_byte_allocate(&byte_pool_0, (VOID **) &pointer, THREAD_STACK_SIZE, TX_NO_WAIT);

    /* Create the main thread.  */
    tx_thread_create(&thread_1, "default thread", thread_1_entry , 0,  
            pointer, THREAD_STACK_SIZE, 
            1, 1, TX_NO_TIME_SLICE, TX_AUTO_START);

    // // /* Allocate the stack for thread 0.  */
    tx_byte_allocate(&byte_pool_0, (VOID **) &pointer, THREAD_STACK_SIZE, TX_NO_WAIT);

    // // /* Create the main thread.  */
    tx_thread_create(&thread_2, "thread 1", thread_2_entry, 0,  
            pointer, THREAD_STACK_SIZE, 
            1, 1, TX_NO_TIME_SLICE, TX_AUTO_START);

      /* Release the block back to the pool.  */
    tx_byte_release(pointer);

}


/* Define the test threads.  */

void    thread_1_entry(ULONG thread_input)
{

    /* This thread simply sits in while-forever-sleep loop.  */
    while(1)
    {
        CO2_Capture();
        /* Sleep for 10 ticks.  */
        tx_thread_sleep(1000);
    }
}


void    thread_2_entry(ULONG thread_input)
{

  /* USER CODE BEGIN canopen_task */
  

    /* This thread simply sits in while-forever-sleep loop.  */
    while(1)
    {

  
        /* Sleep for 100 ticks.  */
        tx_thread_sleep(100);

    }
}


