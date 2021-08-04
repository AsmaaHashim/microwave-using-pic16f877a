# 1 "timer0.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "timer0.c" 2

# 1 "./timer0.h" 1
# 11 "./timer0.h"
# 1 "./timer0_HW.h" 1
# 11 "./timer0_HW.h"
# 1 "./data_types.h" 1
# 11 "./data_types.h"
typedef unsigned char unint8 ;

typedef signed char sint8 ;

typedef unsigned short unint16;

typedef signed short sint16 ;

typedef unsigned long unint32 ;

typedef signed long sint32 ;

typedef float float32;

typedef double float64;
# 11 "./timer0_HW.h" 2
# 11 "./timer0.h" 2

# 1 "./interrupt.h" 1
# 11 "./interrupt.h"
# 1 "./interrupt_HW.h" 1
# 11 "./interrupt.h" 2





void global_INT_enable();


void global_INT_disable();
# 30 "./interrupt.h"
void TIMER0_Call_Back(void (*ptr)(void));
# 39 "./interrupt.h"
void CCP1_Call_Back(void (*ptr)(void));
# 48 "./interrupt.h"
void CCP2_Call_Back(void (*ptr)(void));
# 12 "./timer0.h" 2





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




typedef enum{
    T0_INT_D ,
    T0_INT_E
}TIMER0_INT_state;




typedef struct{

    T0_CLK_SOURCE CLK_state;

    TIMER0_INT_state INT_state;

}TIMER0_CONFIG;






void TIMER0_init(TIMER0_CONFIG *data);






void set_T0DR(unint8 val);






unint8 get_T0DR(void);
# 2 "timer0.c" 2


void TIMER0_init(TIMER0_CONFIG *data)
{
    *((volatile unint8*)0X81) &=0XC0;

    if(data->CLK_state != External_positive_edge && data->CLK_state != External_negative_edge)
    {
        *((volatile unint8*)0X81) |=(data->CLK_state << 0);
    }
    else
    {
        *((volatile unint8*)0X81) |=(1<<5) | (data->CLK_state << 4);
    }

    *((volatile unint8*)0X0B) |=(data->INT_state << 5);
}

void set_T0DR(unint8 val)
{
    *((volatile unint8*)0X01) = val;
}

unint8 get_T0DR()
{
    return *((volatile unint8*)0X01);
}
