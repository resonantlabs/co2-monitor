/**
  ******************************************************************************
  * @file  CO2.h
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
#ifndef CO2_H
#define CO2_H

void MX_I2C1_Init(void);
void CO2_Capture( void );
void CO2_Init( void );

#define ENABLE(X)       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, X)
#define NRDY            HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)

#endif