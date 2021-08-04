# 1 "lcd.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "lcd.c" 2
# 1 "./lcd.h" 1
# 11 "./lcd.h"
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
# 11 "./lcd.h" 2


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
# 1 "lcd.c" 2


# 1 "./delay.h" 1
# 17 "./delay.h"
unint32 counter;
# 3 "lcd.c" 2
# 12 "lcd.c"
static void itoa(int num , char *buff , int b)
{
    if(num==0)
    {
        buff[0]=48 ;
        buff[1]='\0';
    }
    else
    {
        int digits_num=0 , n ;

        n=num;

        while(++digits_num && (n/=b));

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
    *((volatile unint8*) PORT_E + (unint8)0x80) &=(~(1 << 1) & ~(1 << 2) );
# 58 "lcd.c"
  *((volatile unint8*)PORT_D + (unint8)0x80) = 0X00;

  LCD_sendCommand(0X38);



  LCD_sendCommand(0X0C);

}

void LCD_sendCommand(unint8 commond)
{
 (*((volatile unint8*)PORT_E ) &=~((unint8)1 << 2));
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};
    ( *((volatile unint8*)PORT_E ) |=(unint8)1 << 1);
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};
# 97 "lcd.c"
    *((volatile unint8*) PORT_D ) = commond;
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};
    (*((volatile unint8*)PORT_E ) &=~((unint8)1 << 1));
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};

}

void LCD_displayCharacter(unint8 ch)
{
 ( *((volatile unint8*)PORT_E ) |=(unint8)1 << 2);

    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};

 ( *((volatile unint8*)PORT_E ) |=(unint8)1 << 1);

 for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};
# 150 "lcd.c"
      *((volatile unint8*) PORT_D ) = ch;

      for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};

      (*((volatile unint8*)PORT_E ) &=~((unint8)1 << 1));

      for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};


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

    LCD_sendCommand(Address + 0X80);

}

void LCD_displayStringOnRowColum(unint8 row , unint8 colum , const unint8 *str)
{
    LCD_goToRowColum(row , colum);

 LCD_displayString(str);

}

void LCD_clear_screen(void)
{
 LCD_sendCommand(0X01);
}

void LCD_intgerToString(int data)
{
   char buff[16];

   itoa(data,buff,10);

   LCD_displayString(buff);
}
