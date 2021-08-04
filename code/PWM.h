/* 
 * File:   PWM.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 11:43 AM
 */

#ifndef PWM_H
#define	PWM_H


#include"PWM_HW.h"
#include"interrupt.h"

/*
 * this enum  contains all prescaller modes 
 */
typedef enum{
    PRE_1,
    PRE_4,
    PRE_16
}T2_CLK_DIV;
/*
 * this enum  contains interrupt modes 
 */
typedef enum{
    disable,
    enable,

    }INT_state;
/*
 * this struct is used to hold all the data that should be passed to PWM_init function 
 */
typedef struct{

     T2_CLK_DIV      pre_val;
     unint8          TOP; /** PR2R value --->> the value that timer2 data register will be count till it and then return to 0**/
}CCP_config;

/**
 *@brief : this function is used to initialize PWM        
 *@param : 1- object , pointer to the struct CCP_config , 2- INT_mode , enum INT_state   
 *@ret   : void 
 **/
void PWM1_init(CCP_config *object , INT_state INT_mode);
/**
 *@brief : this function is used to set the value of CCP1 compare register    
 *@param : duty , unsigned short , set the value of CCP1 compare register
 *@ret   : void 
 **/
void set_duty1(unint16 duty);
/**
 *@brief : this function is used to start PWM     
 *@param : void
 *@ret   : void 
 **/
void PWM_start(void); 
/**
 *@brief : this function is used to stop PWM     
 *@param : void
 *@ret   : void 
 **/
void PWM_stop();


#endif	/* PWM_H */

