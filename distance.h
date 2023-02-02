/*
 * distance.h
 *
 * Created: 12/27/2022 10:33:50 PM
 *  Author: walid
 */ 


#ifndef DISTANCE_H_
#define DISTANCE_H_
#include "MACROS.h"

#include <util/delay.h>
#include <avr/io.h>
#define US_DDR 	DDRB
#define US_PORT PORTB         
#define	US_PIN	PINB
#define US_TRIG_0	PB3        
#define US_ECHO_0	PB0
#define US_TRIG_1	PB4         
#define US_ECHO_1	PB1
#define US_TRIG_2	PB5        
#define US_ECHO_2	PB2
#define US_ERROR	    -1      
#define	US_NO_OBSTACLE	-2 


void HCSR04Init();
void HCSR04Trigger();
uint16_t GetPulseWidth();
uint16_t GetPulseWidth2(uint8_t num);


/*uint32_t ReadUS_manuall(uint8_t y);
 uint16_t  Ultrasonic_init2();
unsigned long pulseIns();

#define  _ULTRASONIC_LEFT_TRIGGER 0
#define  _ULTRASONIC_MIDDLE_TRIGGER 1
#define  _ULTRASONIC_RIGHT_TRIGGER 2
#define Left_Ultrasonic 0
#define Middle_Ultrasonic 1
#define Right_Ultrasonic 2*/

#endif /* DISTANCE_H_ */