/* 
 * File:   interrupt_HW.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 11:02 AM
 */

#ifndef INTERRUPT_HW_H
#define	INTERRUPT_HW_H

#include "data_types.h"

/**  
 * in this file B-->> means bit & R-->> means register 
 **/

/***** registers description        *******/

#define ICONR *((volatile unint8*)0X0B)       /** interrupt control register  **/

#define PIR1R *((volatile unint8*)0X0C)       /** this register contains the flag BITS of CCP1 **/

#define PIR2R *((volatile unint8*)0X0D)       /** this register contains the flag of CCP2   **/

#define PIE1R *((volatile unint8*)0X8C)       

#define PIE2R *((volatile unint8*)0X8D)      


/*********** BITS description    ***************/

 //1- INTCON register BITS that i will use it in the project

#define GIEB    7

#define T0IEB   5

#define T0IFB   2

//2- PIR2 & PIR1 & PIE1 & PIE2 BITS that i will use it in the project

#define CCP1IFB  2

#define CCP2IFB  0

#define CCP1IEB  2

#define CCP2IEB  0

#endif	/* INTERRUPT_HW_H */

