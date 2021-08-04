/* 
 * File:   timer0_HW.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 11:34 AM
 */

#ifndef TIMER0_HW_H
#define	TIMER0_HW_H

#include "data_types.h"

// timer0 registers --->> control & data 
// note --->> R-->means register     B-->means bit

#define T0CR *((volatile unint8*)0X81)

#define T0DR  *((volatile unint8*)0X01)


            /****** TIMER0 control register bits  *******/

#define PS0B 0                // B--->> BIT
#define PS1B 1                // 0--->> means timer0
#define PS2B 2
#define PSAB 3
#define T0SEB 4
#define T0CSB 5

#endif	/* TIMER0_HW_H */

