
#include"PWM.h"

void PWM1_init(CCP_config *object, INT_state INT_mode) 
{
    T2CONR |= (object->pre_val << T2PS0B);        // set prescaler value  of timer2

    CCP1CONR |= (1 << CCP1M3B) | (1 << CCP1M2B); // enable CCP in PWM mode

    PR2R = object->TOP;                         // max value that timer2 data register will count till it

    PIE1R |= (INT_mode << CCP1IEB);           // enable or disable the interrupt according to the user choice
}

/** the value that will be add into CCPR1LR & <4:5> bits in CCP1 control register   **/
void set_duty1(unint16 duty)
{
    CCPR1LR = duty; // the value that will be compared with data register value 
}

void PWM_start() // this function is used to turn on timer2 and then PWM start 
{
    T2CONR |= (1 << TMR2ONB);
}

void PWM_stop() 
{
    T2CONR &= ~(1 << TMR2ONB);
}


