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
#include "ball_detector.h"
#include "motor.h"
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
	//pwm_init();
	motor_init();
	ball_detector_init();
	float pos;
	uint8_t n;
	int16_t enc_val;
	int i = 0;
	motor_calibrate();
	while(1) {
		
		//check_ball_lost();
		//n = get_n_ball_lost();
		//printf("Ball lost: %d times\n",n);
		//printf("Sending message... \n");
		//can_send(snd_msg);
		
		//printf("Waiting for message... \n");
		rcv_msg = can_recieve();
	//	printf("Message ID: %d\n",rcv_msg.id);
		//printf("X_pos: %d, Y_pos: %d\n",rcv_msg.data[0], rcv_msg.data[1]); 
		if (rcv_msg.data[0] < 0) {
			motor_set_direction(LEFT);
		} else {
			motor_set_direction(RIGHT);
		}
	
		motor_set_speed(abs(rcv_msg.data[0]));
		
		enc_val = motor_get_encoder_val();
		//printf("Encoder value: %d \n",enc_val);
		//pos = 1.5 + (((float) rcv_msg.data[1])/200) ;
		//pwm_new_width(pos);
		
		//_delay_ms(100);
	}
	return 0;
}
