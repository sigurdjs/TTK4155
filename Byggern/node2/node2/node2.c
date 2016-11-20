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
	pwm_init();
	motor_init();
	ball_detector_init();
	can_message snd_msg;
	can_message rcv_msg;
	while(1) {
		
		rcv_msg = can_recieve();
        switch(rcv_msg.id) {
            case NEW_GAME:
                motor_calibrate();
                set_n_ball_lost(0);
                break;
            case GAME_CTRLS:

                break;

		check_ball_lost();

		n = get_n_ball_lost();
        can_send(snd_msg);
            
		printf("Waiting for message... \n");
        if (rcv_msg.data[0] < 0) {
			motor_set_direction(LEFT);
		} else {
			motor_set_direction(RIGHT);
		}
	
		motor_set_speed(abs(rcv_msg.data[0]));
	}
	return 0;
}
