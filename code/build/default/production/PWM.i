# 1 "PWM.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "PWM.c" 2

# 1 "./PWM.h" 1
# 12 "./PWM.h"
# 1 "./PWM_HW.h" 1
# 12 "./PWM_HW.h"
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
# 12 "./PWM_HW.h" 2
# 12 "./PWM.h" 2

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
# 13 "./PWM.h" 2





typedef enum{
    PRE_1,
    PRE_4,
    PRE_16
}T2_CLK_DIV;



typedef enum{
    disable,
    enable,

    }INT_state;



typedef struct{

     T2_CLK_DIV pre_val;
     unint8 TOP;
}CCP_config;






void PWM1_init(CCP_config *object , INT_state INT_mode);





void set_duty1(unint16 duty);





void PWM_start(void);





void PWM_stop();
# 2 "PWM.c" 2


void PWM1_init(CCP_config *object, INT_state INT_mode)
{
    *((volatile unint8*)0X12) |= (object->pre_val << 0);

    *((volatile unint8*)0X17) |= (1 << 3) | (1 << 2);

    *((volatile unint8*)0X92) = object->TOP;

    *((volatile unint8*)0X8C) |= (INT_mode << 2);
}


void set_duty1(unint16 duty)
{
    *((volatile unint8*)0X15) = duty;
}

void PWM_start()
{
    *((volatile unint8*)0X12) |= (1 << 2);
}

void PWM_stop()
{
    *((volatile unint8*)0X12) &= ~(1 << 2);
}
