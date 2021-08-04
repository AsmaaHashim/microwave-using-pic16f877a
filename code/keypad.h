/* 
 * File:   keypad.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 10:56 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#include"GPIO_reg.h"
#include "std_macros.h"

#define KEY_COLUMN0_DDR  *((volatile unint8* )PORT_B + DIR_OFFSET)
#define KEY_COLUMN1_DDR  *((volatile unint8* )PORT_B + DIR_OFFSET)
#define KEY_COLUMN2_DDR  *((volatile unint8* )PORT_B + DIR_OFFSET)

#define KEY_COLUMN0_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)
#define KEY_COLUMN1_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)
#define KEY_COLUMN2_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)

#define KEY_ROW0_DDR     *((volatile unint8* )PORT_D + DIR_OFFSET)
#define KEY_ROW1_DDR     *((volatile unint8* )PORT_D + DIR_OFFSET)
#define KEY_ROW2_DDR     *((volatile unint8* )PORT_D + DIR_OFFSET)
#define KEY_ROW3_DDR     *((volatile unint8* )PORT_D + DIR_OFFSET)

#define KEY_ROW0_PORT    *((volatile unint8*)PORT_D + DATA_OFFSET)
#define KEY_ROW1_PORT    *((volatile unint8*)PORT_D + DATA_OFFSET)
#define KEY_ROW2_PORT    *((volatile unint8*)PORT_D + DATA_OFFSET)
#define KEY_ROW3_PORT    *((volatile unint8*)PORT_D + DATA_OFFSET)

#define ROW_NUM   4
#define COLUM_NUM 3

// OPTION_REGISTER --->> configure column pins as pull_up
#define PULLUP          *((volatile unint8*)0x81) &= 0x7F   

/* set rows as output */
#define KEYPAD_ROW_PINS_DIR  CLEAR_BIT(KEY_ROW0_DDR , 0); CLEAR_BIT(KEY_ROW1_DDR , 1);\
                             CLEAR_BIT(KEY_ROW2_DDR , 2); CLEAR_BIT(KEY_ROW3_DDR ,  3)

/* set COLUMNS as input */
#define KEYPAD_COLUMN_PINS_DIR  SET_BIT(KEY_COLUMN0_DDR ,0); SET_BIT(KEY_COLUMN1_DDR , 1);\
                                SET_BIT(KEY_COLUMN2_DDR , 2)

// Keypad configurations
#define ROW0(state)   if (state == 0) CLEAR_BIT(KEY_ROW0_PORT ,0); else SET_BIT(KEY_ROW0_PORT ,0)
#define ROW1(state)   if (state == 0) CLEAR_BIT(KEY_ROW1_PORT ,1); else SET_BIT(KEY_ROW1_PORT ,1)
#define ROW2(state)   if (state == 0) CLEAR_BIT(KEY_ROW2_PORT ,2); else SET_BIT(KEY_ROW2_PORT ,2)
#define ROW3(state)   if (state == 0) CLEAR_BIT(KEY_ROW3_PORT ,3); else SET_BIT(KEY_ROW3_PORT ,3)


#define READ_COLWMN0  READ_BIT(KEY_COLUMN0_PORT , 0)
#define READ_COLWMN1  READ_BIT(KEY_COLUMN0_PORT , 1)
#define READ_COLWMN2  READ_BIT(KEY_COLUMN0_PORT , 2)

/**
 *@brief : this function is used to initialize the keypad it do these three actions
 *         1-define the direction of row & column ports -->> row pins as output & column pins as input
 *         2-make the column pins as internal pull up
 *         3-disable all rows at first 
 *@param : void
 * @ret  : void   
 **/
void keypad_init(void);

/**
 *@brief : this function is used to return the value of the button the has been pressed 
 *@param : it takes nothing 
 *@ret   : unsigned char ,  corresponding value of the button that has been pressed
 **/
unint8 key_pressed();


#endif	/* KEYPAD_H */

