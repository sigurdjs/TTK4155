#include "devices.h"

void update_devices(can_message msg) {
    if (msg.data[0] < 0) {
        motor_set_direction(LEFT);
    } else {
        motor_set_direction(RIGHT);
    }
    motor_set_speed(abs(msg.data[0]));
	uint8_t pwm_val = (uint8_t) msg.data[2];
    pwm_new_width(((float) pwm_val)/255 +1);
    if(msg.data[3] == TRUE) {
        //Activate shooting button
    }
}

//Sends a can_message with either alive msg or game over.
uint8_t check_game_status(uint8_t n_lives) {
    can_message msg;
	uint8_t ret_val;
    if(check_ball_lost() >= n_lives) {
        msg.id = GAME_OVER;
		ret_val = TRUE;
    } else {
        msg.id = ALIVE;
		ret_val = FALSE;
    }
    msg.length = 0; 
    can_send(msg);
	return ret_val;
}
