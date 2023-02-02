/*
 * mauall.c
 *
 * Created: 12/26/2022 11:08:28 PM
 *  Author: Aliaa/Rania

 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include "util/delay.h"
#include "Motors_Driver.h"
#include "Motor_Types.h"





// ----- Motor Forward Movement ----- //
void Forward_M(){
	 //DDRD |= (1<<2)|(1<<3)|(1<<5)| (1<<6)| (1<<7)| (1<<4);	
	motor_PWM(20);
	DDRD = 0XFF;
	PORTD |= (1 << _MOTOR_DIRECTION_IN1) | (1 << _MOTOR_DIRECTION_IN3);
	PORTD &= ~((1 << _MOTOR_DIRECTION_IN2) | (1 << _MOTOR_DIRECTION_IN4));
}
// ----- Motor Backward Movement ----- //
void Backward_M()
{
	 // DDRD |= (1<<2)|(1<<3)|(1<<5)| (1<<6)| (1<<7)| (1<<4);	
	 DDRD = 0XFF;
	motor_PWM(20);
	PORTD &= ~((1 << _MOTOR_DIRECTION_IN1) | (1 << _MOTOR_DIRECTION_IN3));
	PORTD |= (1 << _MOTOR_DIRECTION_IN2) | (1 << _MOTOR_DIRECTION_IN4);
	
}
// ----- Motor Right Movement ----- //
void Right_M()
{
	 DDRD |= (1<<5)| (1<<6)| (1<<7)| (1<<4);	
	motor_PWM(20);
	PORTD |= (1 << _MOTOR_DIRECTION_IN1) | (1 << _MOTOR_DIRECTION_IN4);
	PORTD &= ~((1 << _MOTOR_DIRECTION_IN2) | (1 << _MOTOR_DIRECTION_IN3));
	//PORTD &= ~((1 << _MOTOR_DIRECTION_IN2) | (1 << _MOTOR_DIRECTION_IN1));
	
}
// ----- Motor Left Movement ----- //
void Left_M()
{
	
	motor_PWM(20);
	 DDRD |= (1<<2)|(1<<3)|(1<<5)| (1<<6)| (1<<7)| (1<<4);	
	PORTD |= (1 << _MOTOR_DIRECTION_IN2) | (1 << _MOTOR_DIRECTION_IN3);
	PORTD &= ~((1 << _MOTOR_DIRECTION_IN1) | (1 << _MOTOR_DIRECTION_IN4));
}
// ----- Motor Stop Movement ----- //
void Stop_M()
{
    // DDRD |= (1<<2)|(1<<3)|(1<<5)| (1<<6)| (1<<7)| (1<<4);	
	PORTD &= ~((1 << _MOTOR_DIRECTION_IN2) | (1 << _MOTOR_DIRECTION_IN3));
	PORTD &= ~((1 << _MOTOR_DIRECTION_IN1) | (1 << _MOTOR_DIRECTION_IN4));
}

// ----- Motor Rotate Movement ----- //
/*void Rotate()
{
	motor_PWM(15);
	// Backward
	PORTD &= ~((1 << _MOTOR_DIRECTION_IN1) | (1 << _MOTOR_DIRECTION_IN3)); //0 2
	PORTD |= (1 << _MOTOR_DIRECTION_IN2) | (1 << _MOTOR_DIRECTION_IN4);   // 1 3
	_delay_ms(500);
	Stop();
	
	// Rotate
	PORTD |= (1 << _MOTOR_DIRECTION_IN1) | (1 << _MOTOR_DIRECTION_IN4);
	PORTD &= ~((1 << _MOTOR_DIRECTION_IN2) | (1 << _MOTOR_DIRECTION_IN3));
	_delay_ms(650);
	Stop();
} */
