
/**
  ******************************************************************************
  * @file     isen_i2c.h 
  * @author   Tiedemann, Tim
  * @version  V0.1
  * @date     SS 2017
  * @brief    Timer for calculation
  ******************************************************************************
  */

#ifndef __ISENI2C_H
#define __ISENI2C_H

void init_I2C1(void);
void init_I2C2(void);
void I2C_start(I2C_TypeDef* I2Cx, uint8_t address, uint8_t direction);
void I2C_write(I2C_TypeDef* I2Cx, uint8_t data);
uint8_t I2C_read_ack(I2C_TypeDef* I2Cx);
uint8_t I2C_read_nack(I2C_TypeDef* I2Cx);
void I2C_stop(I2C_TypeDef* I2Cx);

#endif
