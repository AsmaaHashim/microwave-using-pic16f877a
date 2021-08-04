/*
 * File:   main.c
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 10:46 AM
 */

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>

#include "microwave.h"
#include "delay.h"

#define _XTAL_FREQ 10000000UL        

/*
 * this variable is used as a flag it will be set when the user click stop \
 * after the time setting is over and not enter the other time
 */
unint8 finish=0;
int main(void) {
    
    ADCON1 = 0x06;  // set all pins of A / D as I/O pins
    microWave_init();
    
    while(1)
    {
        if(start())
        {
            start_LED_ON();    

            LCD_displayStringOnRowColum(0 , 3 ,"**welcome**");
            LCD_displayStringOnRowColum(1 , 0 ,"microwaveProject*");
            delay_us(1000000);
            scan_minutes(); 
            if(foodIsInMicro() && door_is_close())
            {
                heat_on();    
                FAN_ON();
                start_calc_time();

                while(!stop() )
                {  
                    if(!start())       // start here use as a pause button
                    {
                        show_remaining_time();
                        if(minutes == 0 && second == 0 )  //this condition checks if time is over or not
                        {
                            stop_cal_time();
                            show_remaining_time();
                            heat_off();
                            LCD_displayStringOnRowColum(1 , 0 ,"*******GOOD**********");
                            while(1)
                            {
                                if(stop())
                                {
                                    finish =1;
                                    break;
                                }
                                else if(start())
                                {
                                    scan_minutes();
                                    start_calc_time();
                                    break;
                                }
                            }
                            if(finish) // this means that the user click stop and want to finish  
                            {
                                finish=0;
                                break;
                            }
                            heat_on(); 
                        }
                    }
                    else 
                    {
                       stop_cal_time();
                       heat_off();
                       LCD_displayStringOnRowColum(1 , 0 ,"*****PAUSE*****");
                       while(!start());
                       start_calc_time();
                       heat_on();
                    }
                }    
                stop_cal_time();
                heat_off();
                FAN_OFF();
                door_is_open();      // will wait here till the door is opened
                foodOutMicro();     // will wait here till the food is taken out microwave
                start_LED_OFF();
                LCD_clear_screen();
            }
        }
    } // end while(1)
    
    return 0;
}
