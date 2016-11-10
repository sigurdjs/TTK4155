/*
 * main.c
 *
 * Created: 19.10.2016 18:52:31
 *  Author: sigurdjs
 */ 

#include "uart.h"
#include "sram.h"
#include "adc.h"


int main(void) {
	adc_init();	
	uart_init();

	sram_test();
	
    uint8_t value;
	while(1)
    {	
		value = (uint8_t)adc_read(0);
		printf("Joystick value is currently: %d \n",value);
    }
	return 0;
}
