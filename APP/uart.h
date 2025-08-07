/**
  ******************************************************************************
  * @file  can.h
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
#ifndef UART_H
#define UART_H

void MX_UART_Init(void);
void MX_UART_Send_Data( void );

typedef struct  __attribute__((__packed__))
{

  union  __attribute__((__packed__))
  {
    uint16_t word[10];
    uint8_t  byte[20];
  } u;

  
} UART_TX_T; 

typedef struct  __attribute__((__packed__))
{

  union  __attribute__((__packed__))
  {
    uint8_t  byte[3];
    struct __attribute__((__packed__))
    {
      uint8_t command;
      uint16_t data;
    } s;
    
  } u;

  
} UART_RX_T; 


#define UART_DISABLE_HOT_SWAP   0x11
#define UART_ENABLE_HOT_SWAP    0x12
#define UART_CLEAR_SMB          0x31
#define UART_START_ESR_TEST     0x32
#define UART_SET_ESR_ON_TIME    0x81
#define UART_SET_ESR_OFF_TIME   0x82
#define UART_SET_ESR_I_OVERRIDE 0x83


#endif 
