#include "keypad.h"
#include "delay.h"

/**this array hold the values corresponding to the keypad buttons **/
static const unsigned char keypad[ROW_NUM][COLUM_NUM]={                                                        
                                                        {'*' ,0 , '#'},
                                                        {7  , 8 ,   9},
                                                        {4  , 5 ,   6},
                                                        {1  , 2 ,   3},
                                                      };

void keypad_init(void)
{
        KEYPAD_ROW_PINS_DIR;
        KEYPAD_ROW_PINS_DIR;
        PULLUP;
}

unint8 key_pressed()
{
    
    ROW0(0); ROW1(1); ROW2(1); ROW3(1);
    delay_us(500);
    if(!READ_COLWMN0){ while(!READ_COLWMN0);  return keypad[0][0] ;}
    if(!READ_COLWMN1){ while(!READ_COLWMN1);  return keypad[0][1] ;}
    if(!READ_COLWMN2){ while(!READ_COLWMN2);  return keypad[0][2] ;}
    delay_us(500);
    
    ROW0(1); ROW1(0); ROW2(1); ROW3(1);
    delay_us(500);
    if(!READ_COLWMN0){ while(!READ_COLWMN0);  return keypad[1][0] ;}
    if(!READ_COLWMN1){ while(!READ_COLWMN1);  return keypad[1][1] ;}
    if(!READ_COLWMN2){ while(!READ_COLWMN2);  return keypad[1][2] ;}
    delay_us(500);

    ROW0(1); ROW1(1); ROW2(0); ROW3(1);
    delay_us(500);
    if(!READ_COLWMN0){ while(!READ_COLWMN0);  return keypad[2][0] ;}
    if(!READ_COLWMN1){ while(!READ_COLWMN1);  return keypad[2][1] ;}
    if(!READ_COLWMN2){ while(!READ_COLWMN2);  return keypad[2][2] ;}
    delay_us(500);
    
    ROW0(1); ROW1(1); ROW2(1); ROW3(0);
    delay_us(500);
    if(!READ_COLWMN0){ while(!READ_COLWMN0);  return keypad[3][0] ;}
    if(!READ_COLWMN1){ while(!READ_COLWMN1);  return keypad[3][1] ;}
    if(!READ_COLWMN2){ while(!READ_COLWMN2);  return keypad[3][2] ;}
    delay_us(500);

    return 10; // this means that no button has been pressed
}