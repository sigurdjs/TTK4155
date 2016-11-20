#define N_LIVES 5
#include "uart.h"
#include "mcp2515.h"
#include "can.h"
#include "ball_detector.h"
#include "devices.h"


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
                update_devices(rcv_msg);
                break;
        }
        check_game_status(N_LIVES);    //Sends a can_message with either alive msg or game over.
    }
	return 0;
}
