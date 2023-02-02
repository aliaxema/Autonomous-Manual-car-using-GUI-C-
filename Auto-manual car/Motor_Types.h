/*
 * Motor_Types.h
 *
 * Created: 6/18/2022 12:26:06 AM
 *  Author: Rania
 */ 


#ifndef MOTOR_TYPES_H_
#define MOTOR_TYPES_H_

				// ----- Timer ----- //
#define _TIMR_CS_NOPRES 0b00000001
#define _TIMR_CS_PRSC8 0b00000010
#define _TIMR_CS_PRSC1024 0b00000101

			// ----- Timer - PWM ----- //
#define _TIMR_MODE_FASTPWM 3
#define _TIMR_OC0A_INVERTING_FASTPWM   0b11000000  // 0b00001001        
#define _TIMR_OC0B_INVERTING_FASTPWM    0b00110000 // 0b00110000      
#define _TIMR_OC0A_NONINVERTING_FASTPWM  0b10000000 //0b00001000     
#define _TIMR_OC0B_NONINVERTING_FASTPWM 0b00100000    //0b00100000               

				// ----- Motor Movements ----- //
#define _MOTOR_DIRECTION_IN1 4 //4
#define _MOTOR_DIRECTION_IN2 7 //7
#define _MOTOR_DIRECTION_IN3 2  
#define _MOTOR_DIRECTION_IN4 3


#endif /* MOTOR_TYPES_H_ */