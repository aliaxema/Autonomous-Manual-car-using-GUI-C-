/*
 * Bluetooth.h
 *
 * Created: 12/25/2022 11:01:46 PM
 *  Author: Rania/Aliaa
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <stdint.h>
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)



void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_putstring(char* StringPtr);





#endif /* BLUETOOTH_H_ */