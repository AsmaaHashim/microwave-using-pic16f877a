/* 
 * File:   microwave_HW.h
 * Author: Asmaa Hashim
 *
 * Created on February 26, 2020, 11:39 AM
 */

#ifndef MICROWAVE_HW_H
#define	MICROWAVE_HW_H

#include"GPIO_reg.h"

// start button port & pin

#define START_BUTTON_DIR_PORT *((volatile unint8*)PORT_A + DIR_OFFSET)

#define START_BUTTON_DATA_PORT *((volatile unint8*)PORT_A + DATA_OFFSET)

#define START_BUTTON_PIN  5

//stop port pin & port

#define STOP_BUTTON_DIR_PORT *((volatile unint8*)PORT_B + DIR_OFFSET)

#define STOP_BUTTON_DATA_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)

#define STOP_BUTTON_PIN  3

//HEAT port pin & port

#define HEAT_DIR_PORT *((volatile unint8*)PORT_B + DIR_OFFSET)

#define HEAT_DATA_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)

#define HEAT_PIN  6


//start lamp port pin & port

#define LAMP_DIR_PORT *((volatile unint8*)PORT_B + DIR_OFFSET)
#define LAMP_DATA_PORT *((volatile unint8*)PORT_B + DATA_OFFSET)
#define LAMP_PIN  7

//DOOR button & led ----->>> port & pin

#define DOOR_BUTTON_DIR_PORT  *((volatile unint8*)PORT_B + DIR_OFFSET)

#define DOOR_BUTTON_DATA_PORT  *((volatile unint8*)PORT_B + DATA_OFFSET)


#define DOOR_LED_DIR_PORT    *((volatile unint8*)PORT_C + DIR_OFFSET)
#define DOOR_LED_DATA_PORT    *((volatile unint8*)PORT_C + DATA_OFFSET)

#define DOOR_BUTTON_PIN  4

#define DOOR_LED_PIN     6


//weight button & led ----->>> port & pin

#define WEIGHT_BUTTON_DIR_PORT  *((volatile unint8*)PORT_B + DIR_OFFSET)

#define WEIGHT_BUTTON_DATA_PORT  *((volatile unint8*)PORT_B + DATA_OFFSET)


#define WEIGHT_LED_DIR_PORT    *((volatile unint8*)PORT_C + DIR_OFFSET)
#define WEIGHT_LED_DATA_PORT    *((volatile unint8*)PORT_C + DATA_OFFSET)

#define WEIGHT_BUTTON_PIN  5

#define WEIGHT_LED_PIN     5


#endif	/* MICROWAVE_HW_H */

