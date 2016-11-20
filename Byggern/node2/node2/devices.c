#include "devices.h"

void update_devices(can_message msg) {
    if (msg.data[0] < 0) {
        motor_set_direction(LEFT);
    } else {
        motor_set_direction(RIGHT);
    }
    motor_set_speed(abs(msg.data[0]));
    pwm_new_width(((float) msg.data[2])/255 +1);
    if(msg.data[3] == TRUE) {
        //Activate shooting button
    }
}

void check_game_status(uint8_t n_lives) {
    can_message msg;
    if(check_ball_lost() >= n_lives) {
        msg.id = GAME_OVER;
    } else {
        msg.id = ALIVE;
    }
    msg.length = 0; 
    can_send(msg);
}
