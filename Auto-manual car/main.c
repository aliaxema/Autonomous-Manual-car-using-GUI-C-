/*
 * Obstacle Avoider.c
 *
 * Created: 6/17/2022 12:49:48 PM
 * Author : Rania/Aliaa
 */ 


#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Motors_Driver.h"
#include "UltraSonic_Driver.h"
#include "MACROS.h"
#include "Bluetooth.h"
#include "distance.h"
// static int R,L,M;
void AUTO_MODE();

int stop = 0 ;

int main(void)
{
USART_init();
Ultrasonic_init();
unsigned char _REC;
sei();
while (1)
{
	//continue; //TO BE DEleted
	_REC = USART_receive();
	
	switch(_REC)
		{
			
			case 'A':
			{
					stop = 1;
					AUTO_MODE();
				
				break;
				
			}
			case '2':
			{	
				stop = 0;
				Forward_M();
				break;
			}
			case '4':
			{
				stop =0;
				Backward_M();
				break;
			}
			case '6':
			{
				stop =0;
				Right_M();
				break;
			}
			case '8':
			{
				stop =0;
				Left_M();
				break;
			}
			case'D':
			{
				calc_dis();
				break;
			}
			default:
			{
				stop = 0;
				Stop_M();
			}
			
		}
}
	}


void AUTO_MODE()
{
	while(1 && stop){ //
	int R,L,M;
	M = ReadUS(_ULTRASONIC_MIDDLE_TRIGGER);
	L = ReadUS(_ULTRASONIC_LEFT_TRIGGER);
	R =ReadUS(_ULTRASONIC_RIGHT_TRIGGER);
	
	Forward_M();
	
	if (M<=20)
	{
		Backward_M();
		_delay_ms(500);
		Left_M();
		if (L<=20)
		{
			Right_M();
		}
		_delay_ms(500);
		Forward_M();
	}
	else if (R<=15)
	{
		Left_M();
		_delay_ms(200);
		Forward_M();
	}
	else if(L<=10)
	{
		Right_M();
		_delay_ms(200);
		Forward_M();
	}
	else if(L<=10 && M<=10&& R<=10)
	{
		Backward_M();
		_delay_ms(2000);
		Right_M();
		_delay_ms(200);
		Forward_M();
	}
	calc_dis();
	}
}
int calc_dis()
{
	char numberString[10];
	uint16_t r =0;
	int distance =0;
	while(1){
		HCSR04Init();
		//_delay_ms(40);
		HCSR04Trigger();
		//_delay_ms(40);
		break;
	}
	r=GetPulseWidth();
	//distance=( r * 0.0344 / 2);
	//distance=((r/2.0)/150);
	distance = ReadUS(1);
	USART_putstring("Distance = ");
	itoa(distance, numberString,10);
	USART_putstring(numberString);
	USART_putstring(" cm");
	if (distance <= 15 ){
	USART_putstring("OBSTACLE!!!  ");}
	else {
		USART_putstring(" No obstacle     ");
	}
}

ISR(USART_RX_vect)
{
	
	switch(UDR0)
	{
		case 'M':
		{
			stop = 0;
			break;
		}
	}
}


