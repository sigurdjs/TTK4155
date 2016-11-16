/*
 * node2.c
 *
 * Created: 16.11.2016 04:57:35
 *  Author: sigurdjs
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main(void)
{
	uart_init();
    while(1)
    {
		printf("hello from the other side \n");
		_delay_ms(500);
		
    }
	return 0;
}