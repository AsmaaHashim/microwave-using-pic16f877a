/* 
 * File:   timer0.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 11:35 AM
 */

#ifndef TIMER0_H
#define	TIMER0_H

#include"timer0_HW.h"
#include "interrupt.h"

/*
 * this enum is used to hold all prescaller modes 
 */
typedef enum{
    internal_PRE_2,
    internal_PRE_4,
    internal_PRE_8,
    internal_PRE_16,
    internal_PRE_32,
    internal_PRE_64,
    internal_PRE_128,
    internal_PRE_256,
    External_positive_edge =0,
    External_negative_edge =1
}T0_CLK_SOURCE;

/*
 *  this enum is used to indicate the state of timer0 will used interrupt or not
 */
typedef enum{
    T0_INT_D , 
    T0_INT_E 
}TIMER0_INT_state;
            
/*
 * this struct is used to hold all the data that should be passed to timer0_init function 
 */
typedef struct{

    T0_CLK_SOURCE     CLK_state;

    TIMER0_INT_state  INT_state;
    
}TIMER0_CONFIG;

/**
 *@brief : this function is used to initialize timer0       
 *@param :data , pointer to the struct TIMER0_CONFIG , pass the data that i will use it for initialization   
 *@ret   : void 
 **/
void TIMER0_init(TIMER0_CONFIG *data);

/**
 *@brief : this function is used to set timer0 data register value   
 *@param : val , unsigned char , set the value of timer0 data register 
 *@ret   : void 
 **/
void set_T0DR(unint8 val);      

/**
 *@brief : this function is used to get timer0 data register value   
 *@param : void
 *@ret   : unsigned char , get the value of timer0 data register 
 **/
unint8 get_T0DR(void);                

#endif	/* TIMER0_H */

