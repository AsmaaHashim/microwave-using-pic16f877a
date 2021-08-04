/* 
 * File:   interrupt.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 11:02 AM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include "interrupt_HW.h"

#define NULL (void*)0

/****** this function enables the global interrupt*********/
void global_INT_enable();    

/****** this function disable the global interrupt*********/
void global_INT_disable();    

                         /////////  call back functions   ///////////

/** 
 *@brief : Function to set the Call Back function address.
 *@param : ptr , pointer to function takes void and return void,
 *          the address of the function that has the code that should be doing in ISR function\
 *          when timer0 over flow interrupt happens  
 *@ret   : void
 **/
void TIMER0_Call_Back(void (*ptr)(void));

/** 
 *@brief : Function to set the Call Back function address.
 *@param : ptr , pointer to function takes void and return void,
 *         the address of the function that has the code that should be doing in ISR function\
 *         when CCP1 interrupt happens  
 *@ret   : void
 **/
void CCP1_Call_Back(void (*ptr)(void));

/** 
 *@brief : Function to set the Call Back function address.
 *@param : ptr , pointer to function takes void and return void,
 *         the address of the function that has the code that should be doing in ISR function\
 *         when CCP2 interrupt happens  
 *@ret   : void
 **/
void CCP2_Call_Back(void (*ptr)(void));

#endif	/* INTERRUPT_H */

