/* 
 * File:   std_macros.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 10:56 AM
 */

#ifndef STD_MACROS_H
#define	STD_MACROS_H

#include "data_types.h"

#define SET_BIT(reg , bit)     ( reg |=(unint8)1 << bit)

#define CLEAR_BIT(reg , bit )  (reg &=~((unint8)1  << bit))

#define READ_BIT(REG , BIT)    (REG & (1 << BIT))

#define TOGGLE_BIT(REG , BIT) (REG ^=((unint8)1 << BIT))


#endif	/* STD_MACROS_H */

