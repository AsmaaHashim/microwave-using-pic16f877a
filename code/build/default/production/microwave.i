# 1 "microwave.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "microwave.c" 2
# 1 "./microwave.h" 1
# 11 "./microwave.h"
# 1 "./microwave_HW.h" 1
# 11 "./microwave_HW.h"
# 1 "./GPIO_reg.h" 1
# 11 "./GPIO_reg.h"
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
# 11 "./GPIO_reg.h" 2
# 23 "./GPIO_reg.h"
typedef enum {PORT_A=0x05 , PORT_B=0x06 , PORT_C=0x07 , PORT_D=0x08 , PORT_E=0X09 }GPIO_port_type;
# 11 "./microwave_HW.h" 2
# 11 "./microwave.h" 2


# 1 "./lcd.h" 1
# 13 "./lcd.h"
# 1 "./std_macros.h" 1
# 13 "./lcd.h" 2
# 67 "./lcd.h"
void LCD_init(void);






void LCD_sendCommand(unint8 commond);






void LCD_displayCharacter(unint8 ch);






void LCD_displayString(const unint8 *str);






void LCD_clear_screen(void);






void LCD_goToRowColum(unint8 row , unint8 colum);







void LCD_displayStringOnRowColum(unint8 row , unint8 colum , const unint8 *str);






void LCD_intgerToString(int data);
# 13 "./microwave.h" 2


# 1 "./timer0.h" 1
# 11 "./timer0.h"
# 1 "./timer0_HW.h" 1
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
# 15 "./microwave.h" 2


# 1 "./PWM.h" 1
# 12 "./PWM.h"
# 1 "./PWM_HW.h" 1
# 12 "./PWM.h" 2






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
# 17 "./microwave.h" 2


# 1 "./keypad.h" 1
# 65 "./keypad.h"
void keypad_init(void);






unint8 key_pressed();
# 19 "./microwave.h" 2


extern volatile unint16 minutes ;

extern volatile unint8 second;
# 34 "./microwave.h"
void microWave_init(void);





unint8 start(void);





unint8 stop(void);





void start_LED_ON(void);






void start_LED_OFF(void);





void scan_minutes(void);





unint8 door_is_close(void);





unint8 door_is_open(void);





unint8 foodIsInMicro(void);





unint8 foodOutMicro(void);





void heat_on(void);





void heat_off(void);





void show_remaining_time(void);





void start_calc_time(void);





void stop_cal_time(void);





void FAN_ON(void);





void FAN_OFF(void);
# 1 "microwave.c" 2




static volatile unint8 count=0;

volatile unint8 second;

volatile unint16 minutes;

static void Call_Back_OVFI(void)
{
    count++;

 if(count == 30)
 {

        if(second == 0 && minutes !=0)
        {
            minutes--; second=59;
        }
        else
        {
            second--;
        }
        count=0;
    }
}

void microWave_init(void)
{

 ( *((volatile unint8*)PORT_A + (unint8)0x80) |=(unint8)1 << 5);

 ( *((volatile unint8*)PORT_B + (unint8)0x80) |=(unint8)1 << 3);

    (*((volatile unint8*)PORT_B + (unint8)0x80) &=~((unint8)1 << 7));

    ( *((volatile unint8*)PORT_B + (unint8)0x80) |=(unint8)1 << 4);

    (*((volatile unint8*)PORT_C + (unint8)0x80) &=~((unint8)1 << 6));

    ( *((volatile unint8*)PORT_B + (unint8)0x80) |=(unint8)1 << 5);

    (*((volatile unint8*)PORT_C + (unint8)0x80) &=~((unint8)1 << 5));

    (*((volatile unint8*)PORT_B + (unint8)0x80) &=~((unint8)1 << 6));



    TIMER0_CONFIG data={ internal_PRE_256 , T0_INT_E};

    TIMER0_init(&data);

    TIMER0_Call_Back(Call_Back_OVFI);

    set_T0DR(0);
# 71 "microwave.c"
     *((volatile unint8*)PORT_C + (unint8)0x80) &=~(1 << 2 );



     keypad_init();

     LCD_init();



    (*((volatile unint8*)PORT_B + (unint8)0x00) &=~((unint8)1 << 7));

    (*((volatile unint8*)PORT_B + (unint8)0x00) &=~((unint8)1 << 6));

}


unint8 start(void)
{
 if(!(*((volatile unint8*)PORT_A + (unint8)0x00) & (1 << 5)))
 {

   while(!(*((volatile unint8*)PORT_A + (unint8)0x00) & (1 << 5)));

   return 1;

 }
    return 0;
}

unint8 stop(void)
{
 if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 3)))
 {
  while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 3)));

  return 1;

 }

      return 0;
}

void start_LED_ON(void)
{
    ( *((volatile unint8*)PORT_B + (unint8)0x00) |=(unint8)1 << 7);
}

void start_LED_OFF(void)
{
 (*((volatile unint8*)PORT_B + (unint8)0x00) &=~((unint8)1 << 7));
}

void scan_minutes(void)
{
    unint8 minutes_digits[5]={0};

    unint8 indix_of_digit=0 , digit ;

    LCD_init();
    LCD_clear_screen();
    LCD_goToRowColum(0 , 0);
    LCD_displayString("00:00");
    LCD_goToRowColum(1 , 0);
    LCD_displayString("set time please  ");
    LCD_goToRowColum(0 ,0);

 while(1)
    {
        digit=key_pressed();


        if(digit !='*' && digit!='#' && digit !=10 )
        {
            LCD_intgerToString(digit);

            minutes_digits[indix_of_digit]=digit;

            indix_of_digit++;
        }
        else if(digit == '*')
        {
            break;
        }
        else if(digit == '#')
        {
             LCD_goToRowColum(0 , 0);

             LCD_displayString("00:00");

             LCD_goToRowColum(0 , 0);

             indix_of_digit=0;
        }

 }

     indix_of_digit =0;



 while(indix_of_digit < 2 )
    {
        if(indix_of_digit == 0)
        {
            minutes = minutes_digits[indix_of_digit];
        }
        else
  {
   minutes = minutes * 10 + minutes_digits[indix_of_digit];
  }

     indix_of_digit++;
    }
        second=0;

}

unint8 door_is_close()
{
             LCD_init();
             LCD_goToRowColum(1 , 0);
             LCD_displayString("                    ");
             LCD_goToRowColum(1 , 0);
             LCD_displayString("close the door");

 while((*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 4)));

 while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 4)));

 (*((volatile unint8*)PORT_C + (unint8)0x00) ^=((unint8)1 << 6));

 return 1;
}



void show_remaining_time(void)
{
    LCD_init();

    if(minutes >= 10)
    {
        LCD_goToRowColum(0 , 0);

        LCD_intgerToString(minutes);
    }
    else
    {
        LCD_goToRowColum(0 , 0);

     LCD_intgerToString(0);

     LCD_intgerToString(minutes);
    }

        LCD_goToRowColum(0 , 2);

     LCD_displayCharacter(':');

 if(second >= 10)
    {
        LCD_goToRowColum(0 , 3);

        LCD_intgerToString(second);
 }
    else
    {
        LCD_goToRowColum(0 , 3);

        LCD_intgerToString(0);

        LCD_intgerToString(second);

    }
        LCD_goToRowColum(0 , 5);

        LCD_displayCharacter(' ');
}


unint8 door_is_open()
{
    LCD_init();
    LCD_goToRowColum(1 , 0);
    LCD_displayString("                     ");
    LCD_goToRowColum(1 , 0);
    LCD_displayString("open the door");

 while((*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 4)));

 while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 4)));

 (*((volatile unint8*)PORT_C + (unint8)0x00) ^=((unint8)1 << 6));

 return 1;


}

unint8 foodIsInMicro()
{
    LCD_init();
    LCD_goToRowColum(1 , 0);
    LCD_displayString("                    ");
    LCD_goToRowColum(1 , 0);
    LCD_displayString("Enter the food");

    while((*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 5)));

  while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 5)));

  (*((volatile unint8*)PORT_C + (unint8)0x00) ^=((unint8)1 << 5));

     return 1;
}

unint8 foodOutMicro()
{
    LCD_init();
    LCD_goToRowColum(1 , 0);
    LCD_displayString("                        ");
    LCD_goToRowColum(1 , 1);
    LCD_displayString("take the food");

    while((*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 5)));

 while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 5)));

 (*((volatile unint8*)PORT_C + (unint8)0x00) ^=((unint8)1 << 5));

    return 1;
}

void heat_on(void)
{
    LCD_init();

    ( *((volatile unint8*)PORT_B + (unint8)0x00) |=(unint8)1 << 6);

    LCD_goToRowColum(1 , 0);
    LCD_displayString("                   ");
    LCD_goToRowColum(1 , 0);
    LCD_displayString("food heating now");
}

void heat_off(void)
{
    (*((volatile unint8*)PORT_B + (unint8)0x00) &=~((unint8)1 << 6));
}

void FAN_ON(void)
{
   *((volatile unint8*)PORT_C ) |=(1 << 2 );

}

void FAN_OFF(void)
{
   *((volatile unint8*)PORT_C) &=~(1 << 2 );


}

void start_calc_time(void)
{
    set_T0DR(0);
    *((volatile unint8*)0X0B) &= ~(1 << 2 );
    global_INT_enable();
  }

void stop_cal_time(void)
{
    global_INT_disable();
}
