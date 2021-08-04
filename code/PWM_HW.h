/* 
 * File:   PWM_HW.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 11:42 AM
 */

#ifndef PWM_HW_H
#define	PWM_HW_H


#include"data_types.h"

             /************* REGISTERS  ***************/

#define CCP2CONR *((volatile unint8*)0X1D)

#define CCP1CONR *((volatile unint8*)0X17)

#define CCPR2HR *((volatile unint8*)0X1C)

#define CCPR2LR *((volatile unint8*)0X1B)

#define CCPR1HR *((volatile unint8*)0X16)

#define CCPR1LR *((volatile unint8*)0X15)

#define  T2CONR *((volatile unint8*)0X12)

#define  PR2R *((volatile unint8*)0X92)

#define  TMR2 *((volatile unint8*)0X11)



             /** BITS description      **/

#define   CCP1XB  5
#define   CCP1YB  4
#define   CCP1M3B 3
#define   CCP1M2B 2
#define   CCP1M1B 1
#define   CCP1M0B 0

#define   CCP2XB  5
#define   CCP2YB  4
#define   CCP2M3B 3
#define   CCP2M2B 2
#define   CCP2M1B 1
#define   CCP2M0B 0

#define T2PS0B 0
#define T2PS1B 1

#define TMR2ONB 2

#endif	/* PWM_HW_H */

