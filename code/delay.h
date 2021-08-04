/* 
 * File:   delay.h
 * Author: Asmaa Hashim
 *
 * Created on March 4, 2020, 4:52 PM
 */

#ifndef DELAY_H
#define	DELAY_H

#include "data_types.h"

#define clock 10000000UL

#define usec 1000000
#define error_ratio 30
unint32 counter;

//delay implementation
#define delay_us(time)\
for(counter = ((clock / usec) * time /error_ratio ) ; counter > 0 ; counter--)\
{\
}

#endif	/* DELAY_H */

