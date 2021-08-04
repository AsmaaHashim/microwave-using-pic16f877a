#include "microwave.h"

#define NUM_OF_OVF_PER_SEC 30

static volatile unint8 count=0;   // USED TO COUNT THE NUM_OF_OVER_FLOW      

volatile unint8   second;               

volatile unint16  minutes;                    

static void Call_Back_OVFI(void)  // calculate remaning time in back ground
{
    count++;

	if(count == NUM_OF_OVF_PER_SEC)
	{
        
        if(second == 0 && minutes !=0)
        {
            minutes--;    second=59;
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

	SET_BIT(  START_BUTTON_DIR_PORT , START_BUTTON_PIN);  //configure start pin as input pin

	SET_BIT( STOP_BUTTON_DIR_PORT , STOP_BUTTON_PIN);   //configure stop pin as input pin

    CLEAR_BIT(LAMP_DIR_PORT , LAMP_PIN);               // start_LED pin as output pin

    SET_BIT( DOOR_BUTTON_DIR_PORT ,  DOOR_BUTTON_PIN); // configure door pin as input pin

    CLEAR_BIT(DOOR_LED_DIR_PORT , DOOR_LED_PIN);      // configure the led that indicates the door state as out pin

    SET_BIT(WEIGHT_BUTTON_DIR_PORT , WEIGHT_BUTTON_PIN);  // configure weight pin as input pin

    CLEAR_BIT(WEIGHT_LED_DIR_PORT ,  WEIGHT_LED_PIN );  // configure the led that indicates the weight state as out pin

    CLEAR_BIT(HEAT_DIR_PORT , HEAT_PIN);              // configure the Heat led  as out pin

                /********************timer0 initialization--> used to calculate the time******************/

    TIMER0_CONFIG data={ internal_PRE_256 , T0_INT_E};   

    TIMER0_init(&data);
    
    TIMER0_Call_Back(Call_Back_OVFI);
    
    set_T0DR(0);

    /******************PWM initialization--> used for the fan ********************/
/*******************************************************************************************
 * specification --->> i used PWM to turn on the fan according to what i read in the schematic
 , but it did not work and when i turn on the pin it works but i think in the hardware it works by pwm
   because of this i did not delate PWM code
 ****************************************************************************************************/
        //CCP_config  object = { PRE_1 , 100  };

       //PWM1_init(&object , disable);

      //set_duty1(0);
              
     *((volatile unint8*)PORT_C + DIR_OFFSET) &=~(1 << 2 );  //set fan pin as output pin 
              
    /********************'__' keypad & lcd initialization '__'********************/

     keypad_init();        
     
     LCD_init();     
    
    /**these two lines is used to turn off LAMP & HEAT at the beginning **/ 
     
    CLEAR_BIT(LAMP_DATA_PORT , LAMP_PIN);   
    
    CLEAR_BIT(HEAT_DATA_PORT , HEAT_PIN); 

}


unint8 start(void)
{
	if(!READ_BIT(START_BUTTON_DATA_PORT , START_BUTTON_PIN))
	{

	  while(!READ_BIT(START_BUTTON_DATA_PORT , START_BUTTON_PIN));  // wait  till the button released 

	  return 1;

	}
	   return 0;
}

unint8 stop(void)
{
	if(!READ_BIT(STOP_BUTTON_DATA_PORT , STOP_BUTTON_PIN))
	{
		while(!READ_BIT(STOP_BUTTON_DATA_PORT ,STOP_BUTTON_PIN));

		return 1;

	}

      return 0;
}

void start_LED_ON(void)
{
    SET_BIT(LAMP_DATA_PORT , LAMP_PIN );
}

void start_LED_OFF(void)
{
	CLEAR_BIT(LAMP_DATA_PORT , LAMP_PIN );
}

void scan_minutes(void)
{
    unint8 minutes_digits[5]={0};               // this array hold the digits of the minutes
    
    unint8  indix_of_digit=0  , digit ;
    
    LCD_init();     
    LCD_clear_screen();
    LCD_goToRowColum(0 , 0);
    LCD_displayString("00:00");
    LCD_goToRowColum(1 , 0);
    LCD_displayString("set time please  ");
    LCD_goToRowColum(0 ,0);

	while(1) //this while will break when the user enter the time and he should click * after setting the time               
    {
        digit=key_pressed();                          // scan the digit  from the user
        
        // # used to manage the user to change the time if he click wrong time
        if(digit !='*' && digit!='#' && digit !=10 )  
        {
            LCD_intgerToString(digit);
            
            minutes_digits[indix_of_digit]=digit;   // store the digit

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

	// this while used to calculate the minutes according to the digits that the user enter it

	while(indix_of_digit < 2 )
    {
        if(indix_of_digit == 0)
        {
            minutes = minutes_digits[indix_of_digit];
        }
        else
		{
			minutes = minutes * 10 +  minutes_digits[indix_of_digit];
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
             
	while(READ_BIT(DOOR_BUTTON_DATA_PORT , DOOR_BUTTON_PIN));

	while(!READ_BIT(DOOR_BUTTON_DATA_PORT , DOOR_BUTTON_PIN));

	TOGGLE_BIT(DOOR_LED_DATA_PORT , DOOR_LED_PIN);

	return 1;
}

/**this function is used to display remaining time on the lcd  and it takes nothing and return nothing**/

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
} /*end the function that display remaining time */


unint8 door_is_open()
{
    LCD_init();     
    LCD_goToRowColum(1 , 0);
    LCD_displayString("                     ");
    LCD_goToRowColum(1 , 0);
    LCD_displayString("open the door");
    
	while(READ_BIT(DOOR_BUTTON_DATA_PORT , DOOR_BUTTON_PIN));

	while(!READ_BIT(DOOR_BUTTON_DATA_PORT , DOOR_BUTTON_PIN));

	TOGGLE_BIT(DOOR_LED_DATA_PORT , DOOR_LED_PIN);

	return 1;


}

unint8 foodIsInMicro()
{
    LCD_init();     
    LCD_goToRowColum(1 , 0);
    LCD_displayString("                    ");
    LCD_goToRowColum(1 , 0);
    LCD_displayString("Enter the food");

    while(READ_BIT(WEIGHT_BUTTON_DATA_PORT , WEIGHT_BUTTON_PIN));

	 while(!READ_BIT(WEIGHT_BUTTON_DATA_PORT , WEIGHT_BUTTON_PIN));

	 TOGGLE_BIT(WEIGHT_LED_DATA_PORT , WEIGHT_LED_PIN );
     
     return 1;
}// wait there till button is pressed & then led will toggle its state

unint8 foodOutMicro()
{
    LCD_init();     
    LCD_goToRowColum(1 , 0);
    LCD_displayString("                        ");
    LCD_goToRowColum(1 , 1);
    LCD_displayString("take the food");

    while(READ_BIT(WEIGHT_BUTTON_DATA_PORT , WEIGHT_BUTTON_PIN));

	while(!READ_BIT(WEIGHT_BUTTON_DATA_PORT , WEIGHT_BUTTON_PIN));

	TOGGLE_BIT(WEIGHT_LED_DATA_PORT , WEIGHT_LED_PIN );              // led that indicate weight state 

    return 1;
}

void heat_on(void)
{
    LCD_init();
    
    SET_BIT(HEAT_DATA_PORT , HEAT_PIN);
    
    LCD_goToRowColum(1 , 0);
    LCD_displayString("                   ");
    LCD_goToRowColum(1 , 0);
    LCD_displayString("food heating now");
}

void heat_off(void)
{
    CLEAR_BIT(HEAT_DATA_PORT , HEAT_PIN);
}

void FAN_ON(void)
{
   *((volatile unint8*)PORT_C ) |=(1 << 2 );
   // set_duty1(100);                          // if we used PWM 
}

void FAN_OFF(void)
{
   *((volatile unint8*)PORT_C) &=~(1 << 2 );
  //set_duty1(0);                              // if we used PWM
  
}
/* I use interrupt in the program only to calculate the time so that i enable it when need to calculate the time*/
void start_calc_time(void)
{    
    set_T0DR(0);                 // set timer0 data register by 0
    ICONR &= ~(1 << T0IFB );    //  clear timer0 over flow flag
    global_INT_enable();       //   enable global interrupt to start calculate the remaining time 
  }

void stop_cal_time(void)
{
    global_INT_disable();
}
