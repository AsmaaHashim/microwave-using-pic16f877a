
#include"interrupt.h"

#include<xc.h>

/* 
 * Global variables to hold the address of the call back functions in the application 
 */

static void (*TIMER0_CalL_Back_ptr)(void) =   NULL ;

static void (*CCP1_CalL_Back_ptr)(void)   =   NULL ;

static void (*CCP2_CalL_Back_ptr)(void)   =   NULL ;


void TIMER0_Call_Back(void (*ptr)(void))
{
    /* Save the address of the Call back function in a global variable */
    TIMER0_CalL_Back_ptr = ptr;
}

void CCP1_Call_Back(void (*ptr)(void))
{
    /* Save the address of the Call back function in a global variable */
    CCP1_CalL_Back_ptr = ptr;
}

void CCP2_Call_Back(void (*ptr)(void))
{	
    /* Save the address of the Call back function in a global variable */
    CCP2_CalL_Back_ptr = ptr;
}

             /************** interrupt service routine function ***************/

void __interrupt() ISR()
{
    // check timer0 over flow interrupt flag
    if((ICONR & (1 << T0IFB)))                
    {
          if(TIMER0_CalL_Back_ptr !=  NULL)  
            {
              
              /* Call the Call Back function in the application after timer0 overflow happens */
              TIMER0_CalL_Back_ptr(); 
              
              // clear the flag
              ICONR &=~(1 << T0IFB);   

              }
        }

   /** CCP1 interrupt **/

    if((PIR1R & (1 << CCP1IFB)))
    {
        if(CCP1_CalL_Back_ptr != NULL)
        {
            /* Call the Call Back function in the application after CCP1 interrupt happens */
            CCP1_CalL_Back_ptr();
            
            PIR1R &=~(1 << CCP1IFB);   // clear the flag
        }
    }

    /** CCP2 interrupt **/

    if((PIR2R & (1 << CCP2IFB)))
    {
        if(CCP2_CalL_Back_ptr != NULL)
        {
           /* Call the Call Back function in the application after CCP1 interrupt happens */
            CCP2_CalL_Back_ptr();
            
            PIR2R &=~(1 << CCP2IFB);   // clear the flag

        }
    }
}

void global_INT_enable()
{
    /*set the global interrupt enable bit in interrupt control register*/ 
    ICONR |=(1 << GIEB);
}

void global_INT_disable()
{
    /*clear the global interrupt enable bit in interrupt control register*/ 
    ICONR &=~(1 << GIEB);
}
