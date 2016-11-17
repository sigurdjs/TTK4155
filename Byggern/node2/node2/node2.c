/*
 * node2.c
 *
 * Created: 16.11.2016 04:57:35
 *  Author: sigurdjs
 */ 

#include "uart.h"
#include "spi.h"
#include "mcp2515.h"
#include "can.h"
#include "pwm.h"
#include <util/delay.h>


int main(void) {

	uart_init();
	can_init();
	can_message snd_msg;
	can_message rcv_msg;
	snd_msg.id = 5;
	
	snd_msg.data[0] = 'k';
	snd_msg.data[1] = 'u';
	snd_msg.data[2] = 'u';
	snd_msg.data[3] = 'u';
	snd_msg.data[4] = 'k';
	snd_msg.length = 5;
	pwm_init();
	float pos;
	while(1) {
		//printf("Sending message... \n");
		//can_send(snd_msg);
		
		printf("Waiting for message... \n");
		rcv_msg = can_recieve();
		//printf("Message ID: %d\n",rcv_msg.id);
		pos = 1.5 + (((float) rcv_msg.data[1])/200) ;
		pwm_new_width(pos);
		
		//_delay_ms(100);
	}
	return 0;
}
