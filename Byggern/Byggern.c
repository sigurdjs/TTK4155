/*
 * main.c
 *
 * Created: 19.10.2016 18:52:31
 *  Author: sigurdjs
 */ 

#include "uart.h"
#include "sram.h"
#include "adc.h"
#include "joystick.h"
#include "oled.h"
#include <util/delay.h>


int main(void) {
	//adc_init();	
	//uart_init();

	//sram_test();
	//joy_calibrate();
	oled_init();
	OLED_reset();
	joystick_position pos;
	while(1)
    {	
		OLED_print_arrow();
		//sram_test();
		//pos = get_joy_position();
		//printf("Value of joy x is: %d, and y is: %d \n", pos.x_pos,pos.y_pos);
		//oled_test();
		//_delay_us(50);
		//oled_init();
		_delay_ms(500);
    }
	return 0;
}
