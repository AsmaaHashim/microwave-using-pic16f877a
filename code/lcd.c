#include "lcd.h"

#include "delay.h"

/*
 * @brief : this function is used to convert the integer value to its ascii
 * @param : param1  num , integer , pass the integer value ,
 *          param2, buff,pointer to char,pass the first address that will be hold ascii of the first digit
 *          param3 , b , integger , pass the base of the number EX: 10 for dicimal  
 * @ret   : void
 */
static void itoa(int num , char *buff , int b)
{
    if(num==0)
    {
        buff[0]=48 ; 
        buff[1]='\0';
    }
    else
    {
        int  digits_num=0  , n ;
        
        n=num;
        
        while(++digits_num && (n/=b));  // count the number of the digits 
        
        n=num;
        
        buff[digits_num--]='\0';
        
        while(n)
        {
           buff[digits_num--]=(n%b) + 48;
           
             n/=b;
        }
    }
}

void LCD_init(void)
{
    LCD_CTRL_PORT_DIR &=(~(1 << E) & ~(1 << RS) );
    
#if(DATA_BITS_MODE == 4)
    
#ifdef (UPPER_PORT_BINS)
    
		LCD_DIR_PORT =0Xf0;
#else
		LCD_DIR_PORT =0X0f;

#endif

		LCD_sendCommand(TWO_LINE_LCD_4BITS_MODE);

#elif (DATA_BITS_MODE == 8)

		LCD_DIR_PORT = 0X00;

		LCD_sendCommand(TWO_LINE_LCD_8BITS_MODE);

#endif

		LCD_sendCommand(CURSOR_OFF); /* cursor off */

}

void LCD_sendCommand(unint8 commond)
{
	CLEAR_BIT(LCD_CTRL_PORT , RS );   
    delay_us(500);
    SET_BIT(LCD_CTRL_PORT , E);   
    delay_us(500);
#if(DATA_BITS_MODE ==4)
#ifdef(UPPER_PORT_PINS )
	LCD_DATA_PORT = (LCD_DATA_PORT & 0XF0) | (commond >> 4);
#else
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (commond & 0xf0);

#endif
        delay_us(500); 						    /* delay for processing Tdsw = 100ns */
		CLEAR_BIT(LCD_CTRL_PORT,E); 		/* disable LCD E=0 */
		delay_us(500);						/* delay for processing Th = 13ns */
		SET_BIT(LCD_CTRL_PORT,E); 			/* Enable LCD E=1 */
		delay_us(500);
#ifdef(UPPER_PORT_PINS )
        LCD_DATA_PORT = (LCD_DATA_PORT & 0XF0) | (commond & 0x0f);
#else
    LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (commond << 4);
#endif
    delay_us(500); 						/* delay for processing Tdsw = 100ns */
    CLEAR_BIT(LCD_CTRL_PORT,E); 		/* disable LCD E=0 */
  	delay_us(500);						/* delay for processing Th = 13ns */
    SET_BIT(LCD_CTRL_PORT,E); 			/* Enable LCD E=1 */
    delay_us(500);
#elif(DATA_BITS_MODE == 8)
    LCD_DATA_PORT = commond;     
    delay_us(500);
    CLEAR_BIT(LCD_CTRL_PORT , E);   
    delay_us(500);
#endif
}

void LCD_displayCharacter(unint8 ch)
{
	SET_BIT(LCD_CTRL_PORT , RS);  // means that the data will be written
    
    delay_us(500);

	SET_BIT(LCD_CTRL_PORT , E);

	delay_us(500);

#if (DATA_BITS_MODE ==4)

#ifdef UPPER_PORT_PINS
    
		LCD_DATA_PORT =(LCD_DATA_PORT & 0XF0) | (ch >>4)
                
#else
		LCD_DATA_PORT =(LCD_DATA_PORT & 0X0F ) | (ch & 0xf0);
#endif
        
       delay_us(500);
       
	   CLEAR_BIT(LCD_CTRL_PORT , E);
       
	   delay_us(500);
       
       SET_BIT(LCD_CTRL_PORT , E);
       
	   delay_us(500);

#ifdef UPPER_PORT_PINS
        
		LCD_DATA_PORT =(LCD_DATA_PORT & 0XF0) | (ch & 0x0f);
#else
        
		LCD_DATA_PORT =(LCD_DATA_PORT & 0X0F ) | (ch << 4);
        
#endif
	    delay_us(500);
        
		CLEAR_BIT(LCD_CTRL_PORT , E);
        
		delay_us(500);

#elif(DATA_BITS_MODE==8)

      LCD_DATA_PORT = ch;
      
      delay_us(500);
      
      CLEAR_BIT(LCD_CTRL_PORT ,E);
      
      delay_us(500);
      
#endif
}

void LCD_displayString(const unint8 *str)
{
	unint8 i=0;

	while(str[i] !='\0')
	{

		LCD_displayCharacter(str[i]);

		i++;
	}


}
void LCD_goToRowColum(unint8 row , unint8 colum)
{
	unint8 Address;

	switch(row)
	{

	case 0:
		Address =colum;
		break;
	case 1:
		Address = colum + 0x40;
		break;
    }
    
    LCD_sendCommand(Address + SET_CURSOR_LOCATION);
    
}

void LCD_displayStringOnRowColum(unint8 row , unint8 colum , const unint8 *str)
{
    LCD_goToRowColum(row , colum);
    
	LCD_displayString(str);
    
}

void LCD_clear_screen(void)
{
	LCD_sendCommand(CLEAR_COMMAND);
}

void LCD_intgerToString(int data)
{
   char buff[16];       /* String to hold the ascii result */
   
   itoa(data,buff,10); /* 10 for decimal */
   
   LCD_displayString(buff);
}
