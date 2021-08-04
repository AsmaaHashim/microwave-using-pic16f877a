
#include "timer0.h"

void TIMER0_init(TIMER0_CONFIG *data)
{
    T0CR &=0XC0;        // clear all bits that control timer0 at first 
    
    if(data->CLK_state != External_positive_edge  && data->CLK_state != External_negative_edge)
    {
        T0CR |=(data->CLK_state << PS0B);
    }
    else
    {
        T0CR |=(1<<T0CSB) | (data->CLK_state << T0SEB);
    }

    ICONR |=(data->INT_state << T0IEB);   // interrupt state enable or disable 
}

void set_T0DR(unint8 val)
{
    T0DR = val;
}

unint8 get_T0DR()
{
    return T0DR;
}

