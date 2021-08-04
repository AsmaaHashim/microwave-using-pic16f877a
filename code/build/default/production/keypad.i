# 1 "keypad.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "keypad.c" 2
# 1 "./keypad.h" 1
# 11 "./keypad.h"
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
# 11 "./keypad.h" 2

# 1 "./std_macros.h" 1
# 12 "./keypad.h" 2
# 65 "./keypad.h"
void keypad_init(void);






unint8 key_pressed();
# 1 "keypad.c" 2

# 1 "./delay.h" 1
# 17 "./delay.h"
unint32 counter;
# 2 "keypad.c" 2



static const unsigned char keypad[4][3]={
                                                        {'*' ,0 , '#'},
                                                        {7 , 8 , 9},
                                                        {4 , 5 , 6},
                                                        {1 , 2 , 3},
                                                      };

void keypad_init(void)
{
        (*((volatile unint8* )PORT_D + (unint8)0x80) &=~((unint8)1 << 0)); (*((volatile unint8* )PORT_D + (unint8)0x80) &=~((unint8)1 << 1)); (*((volatile unint8* )PORT_D + (unint8)0x80) &=~((unint8)1 << 2)); (*((volatile unint8* )PORT_D + (unint8)0x80) &=~((unint8)1 << 3));
        (*((volatile unint8* )PORT_D + (unint8)0x80) &=~((unint8)1 << 0)); (*((volatile unint8* )PORT_D + (unint8)0x80) &=~((unint8)1 << 1)); (*((volatile unint8* )PORT_D + (unint8)0x80) &=~((unint8)1 << 2)); (*((volatile unint8* )PORT_D + (unint8)0x80) &=~((unint8)1 << 3));
        *((volatile unint8*)0x81) &= 0x7F;
}

unint8 key_pressed()
{

    if (0 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 0)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 0); if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 1)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 1); if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 2)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 2); if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 3)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 3);
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 0))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 0))); return keypad[0][0] ;}
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 1))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 1))); return keypad[0][1] ;}
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 2))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 2))); return keypad[0][2] ;}
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};

    if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 0)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 0); if (0 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 1)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 1); if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 2)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 2); if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 3)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 3);
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 0))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 0))); return keypad[1][0] ;}
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 1))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 1))); return keypad[1][1] ;}
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 2))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 2))); return keypad[1][2] ;}
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};

    if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 0)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 0); if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 1)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 1); if (0 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 2)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 2); if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 3)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 3);
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 0))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 0))); return keypad[2][0] ;}
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 1))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 1))); return keypad[2][1] ;}
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 2))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 2))); return keypad[2][2] ;}
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};

    if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 0)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 0); if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 1)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 1); if (1 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 2)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 2); if (0 == 0) (*((volatile unint8*)PORT_D + (unint8)0x00) &=~((unint8)1 << 3)); else ( *((volatile unint8*)PORT_D + (unint8)0x00) |=(unint8)1 << 3);
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 0))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 0))); return keypad[3][0] ;}
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 1))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 1))); return keypad[3][1] ;}
    if(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 2))){ while(!(*((volatile unint8*)PORT_B + (unint8)0x00) & (1 << 2))); return keypad[3][2] ;}
    for(counter = ((10000000UL / 1000000) * 500 /30 ) ; counter > 0 ; counter--){};

    return 10;
}
