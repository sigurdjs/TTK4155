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
#include "spi.h"
#include "mcp2515.h"
#include "can.h"
#include <util/delay.h>


int main(void) {
	adc_init();	
	uart_init();

	sram_test();
	joy_calibrate();
	//oled_init();
	//OLED_reset();
	joystick_position pos;
	can_init();
	can_message snd_msg;
	can_message rcv_msg;
	snd_msg.id = 3;
	
	snd_msg.data[0] = 'h';
	snd_msg.data[1] = 'e';
	snd_msg.data[2] = 'l';
	snd_msg.data[3] = 'l';
	snd_msg.data[4] = 'o';
	snd_msg.length = 5;
	while(1)
    {	
		

		can_send(snd_msg);
		rcv_msg = can_recieve();
		printf("Message ID: %d\n",rcv_msg.id);
		for (int i = 0; i < rcv_msg.length; i++) {
			printf("%c", rcv_msg.data[i]);
		}
		printf("\n");
		_delay_ms(1000);
    }
	return 0;
}


//pos = get_joy_position();
//printf("Value of joy x is: %d, and y is: %d \n", pos.x_pos,pos.y_pos);

//OLED_print_arrow();
//sram_test();
//oled_test();
//_delay_us(50);
//oled_init();
//_delay_ms(500);
