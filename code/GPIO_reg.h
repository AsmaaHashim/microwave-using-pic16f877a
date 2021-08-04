/* 
 * File:   GPIO_reg.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 10:48 AM
 */

#ifndef GPIO_REG_H
#define	GPIO_REG_H

#include "data_types.h"

 
#define NULL (void*)0

/* the value that will be added to the base address so i can access direction register*/
#define DIR_OFFSET  (unint8)0x80      

/* the value that will be added to the base address so i can access data register*/
#define DATA_OFFSET  (unint8)0x00

 /***** this enum is used to define base address of  ports ******/
typedef enum {PORT_A=0x05 , PORT_B=0x06 , PORT_C=0x07  , PORT_D=0x08 , PORT_E=0X09 }GPIO_port_type;

#endif	/* GPIO_REG_H */

