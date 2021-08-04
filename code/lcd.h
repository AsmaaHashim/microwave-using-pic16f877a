/* 
 * File:   lcd.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 10:56 AM
 */

#ifndef LCD_H
#define	LCD_H

#include"GPIO_reg.h"

#include "std_macros.h"

#define DATA_BITS_MODE 8


#if (DATA_BITS_MODE == 4)

#define UPPER_PORT_BINS

#endif


/** LCD HW_BINS ***/

#define RS  2

#define E   1

#define RW  1

#define  LCD_CTRL_PORT_DIR  *((volatile unint8*) PORT_E + DIR_OFFSET)

#define  LCD_CTRL_PORT      *((volatile unint8*)PORT_E )

#define  LCD_DATA_PORT      *((volatile unint8*) PORT_D )

#define  LCD_DIR_PORT       *((volatile unint8*)PORT_D + DIR_OFFSET)

/** LCD_COMMANDS **/

#define CLEAR_COMMAND           0X01

#define TWO_LINE_LCD_4BITS_MODE 0X28

#define TWO_LINE_LCD_8BITS_MODE 0X38

#define  CURSOR_ON              0X0E

#define CURSOR_OFF              0X0C

#define SET_CURSOR_LOCATION     0X80

#define SET_CGRAM_ADDRESS       0X40

#define RETURN_HOME             0X02

                            /**LCD FUNCTION PROTOTYPE***/

/*
 *@brief : this function is used to intialize the LCD
 *@param : it takes nothing and return nothing
 * @ret  :  it returns nothing
 */

void LCD_init(void);

/*
 *@brief : this function is used to send the command to  the LCD
 *@param :  it takes the command value 
 *@ret   :  it returns nothing
 */
void LCD_sendCommand(unint8 commond);

/*
 *@brief : this function is used to send the character to  the LCD
 *@param :  it takes the character value 
 *@ret   :  it returns nothing
 */
void LCD_displayCharacter(unint8 ch);

/*
 *@brief : this function is used to display the string on the LCD
 *@param :  it takes the address of the first character in the string 
 *@ret   :  it returns nothing
 */
void LCD_displayString(const unint8 *str);

/*
 *@brief : this function is used to clear the LCD
 *@param :  it takes nothing 
 *@ret   :  it returns nothing
 */
void LCD_clear_screen(void);

/*
 *@brief : this function is used to set cursor on certain row and column LCD
 *@param :  1-row number in type unsigned char    2- column number in type unsigned char 
 *@ret   : void
 */
void LCD_goToRowColum(unint8 row , unint8 colum);

/*
 *@brief : this function is used to display string  on certain row and column at the LCD
 *@param :  1-row  , unsigned char , pass the row num    2- column  unsigned char, pass the column num 
 *          3- *str  , pointer to unsigned char , pass the address of the first character  
 *@ret   :  void
 */
void LCD_displayStringOnRowColum(unint8 row , unint8 colum , const unint8 *str);

/*
 *@brief : this function is used to display integer number on the LCD
 *@param :  data , integer , used to pass the integer value that should be displayed in the LCD
 *@ret   :  void
 */
void LCD_intgerToString(int data);



#endif	/* LCD_H */

