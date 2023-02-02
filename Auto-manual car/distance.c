/*
 * distance.c
 *
 * Created: 12/27/2022 7:18:19 PM
 *  Author: rania
 */ 

#include "MACROS.h"
#include "distance.h"



void HCSR04Init()
{
	
	// we're setting the trigger pin as output as it will generate ultrasonic sound wave
	US_DDR|=(1<<US_TRIG_0);
	_delay_us(10);
	US_DDR|=(1<<US_TRIG_1);
	_delay_us(10);
	US_DDR|=(1<<US_TRIG_2);
}

void HCSR04Trigger()
{   // this function will generate ultrasonic sound wave for 15 microseconds
	//Send a 10uS pulse on trigger line
	
	US_PORT|=(1<<US_TRIG_0);	//high
	
	_delay_us(15);				//wait 15uS
	
	US_PORT&=~(1<<US_TRIG_0);	//low
	
	_delay_us(20);
	
	US_PORT|=(1<<US_TRIG_1);	//high
	
	_delay_us(15);				//wait 15uS
	
	US_PORT&=~(1<<US_TRIG_1);
	
	_delay_us(20);
	
	US_PORT|=(1<<US_TRIG_2);	//high
	
	_delay_us(15);				//wait 15uS
	
	US_PORT&=~(1<<US_TRIG_2);
}

uint16_t GetPulseWidth()
{
	
	uint32_t i,result;

	for(i=0;i<60000;i++)
	{
		if(!(US_PIN & (1<<US_ECHO_1)))
		continue;	//Line is still low, so wait
		else
		break;		//High edge detected, so break.
	}


	
	TCCR1A=0X00;
	TCCR1B=(1<<CS11);	// This line sets the resolution of the timer. Maximum of how much value it should count.
	TCNT1=0x00;			// This line start the counter to start counting time

	// Section -3 : This section checks weather the there is any object or not
for(i=0;i<600000;i++)                // the 600000 value is used randomly to denote a very small amount of time, almost 40 miliseconds
{
	if(US_PIN & (1<<US_ECHO_1))
	{
		if(TCNT1 > 60000) break; else continue;   // if the TCNT1 value gets higher than 60000 it means there is not object in the range of the sensor
	}
	else
	break;
}

if(i==600000)
return US_NO_OBSTACLE;	//Indicates time out

//Falling edge found

result=TCNT1;          // microcontroller stores the the value of the counted pulse time in the TCNT1 register. So, we're returning this value to the
TCCR1B=0x00;

if(result > 60000)
return US_NO_OBSTACLE;	//No obstacle
else
return (result>>1);
}
 
