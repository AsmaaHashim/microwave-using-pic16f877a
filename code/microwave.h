/* 
 * File:   microwave.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 11:39 AM
 */

#ifndef MICROWAVE_H
#define	MICROWAVE_H

#include "microwave_HW.h"

#include "lcd.h"            //used to display remaining time

#include "timer0.h"         // used to calculate the time

#include "PWM.h"

#include "keypad.h"        // used to enter the time

extern volatile unint16 minutes ;

extern volatile unint8   second;


/*********************** functions prototype  ***********************/

/**
 *@brief : this function is used to initialize the system its initialize all modules   
 *@param : void
 *@ret   : void
 **/

void microWave_init(void);
/**
 *@brief : this function is used to check the state of the start button   
 *@param : void
 *@ret   : unsigned char  , 1 if button has been pressed 0 if not 
 **/
unint8 start(void);           
/**
 *@brief : this function is used to check the state of the stop button   
 *@param : void
 *@ret   : unsigned char  , 0 if button has been pressed 1 if not 
 **/
unint8 stop(void);              
/**
 *@brief : this function is used to turn on the lamp    
 *@param : void
 *@ret   : void 
 **/
void start_LED_ON(void);

/**
 *@brief : this function is used to turn off the lamp    
 *@param : void
 *@ret   : void 
 **/
void start_LED_OFF(void);
/**
 *@brief : this function is used to takes the minutes from the user digits by digit       
 *@param : void
 *@ret   : void 
 **/
void scan_minutes(void);
/**
 *@brief : this function is used to wait till the door closed     
 *@param : void
 *@ret   : unsigned char , 1 if closed 0 if not 
 **/
unint8 door_is_close(void);
/**
 *@brief : this function is used to wait till the door opened     
 *@param : void
 *@ret   : unsigned char , 1 if opened 0 if not 
 **/
unint8 door_is_open(void);
/**
 *@brief : this function is used to wait till the user enter the food      
 *@param : void
 *@ret   : unsigned char , 1 if there is a weight 0 if not 
 **/
unint8 foodIsInMicro(void);        
/**
 *@brief : this function is used to wait till the user takes the food      
 *@param : void
 *@ret   : unsigned char , 1 if there is takes the food 0 if not 
 **/
unint8 foodOutMicro(void);
/**
 *@brief : this function is used to turn on the heat lamp      
 *@param : void
 *@ret   : void 
 **/
void heat_on(void);
/**
 *@brief : this function is used to turn off the heat lamp      
 *@param : void
 *@ret   : void 
 **/
void heat_off(void);
/**
 *@brief : this function is used to display the remaining time on the LCD      
 *@param : void
 *@ret   : void 
 **/
void show_remaining_time(void);
/**
 *@brief : this function is used to make the timer0 start calculate the time       
 *@param : void
 *@ret   : void 
 **/
void start_calc_time(void);
/**
 *@brief : this function is used to make the timer0 stop calculate the time      
 *@param : void
 *@ret   : void 
 **/
void stop_cal_time(void);
/**
 *@brief : this function is used to turn on the fan      
 *@param : void
 *@ret   : void 
 **/
void FAN_ON(void);
/**
 *@brief : this function is used to turn off the fan      
 *@param : void
 *@ret   : void 
 **/
void FAN_OFF(void);

#endif	/* MICROWAVE_H */

