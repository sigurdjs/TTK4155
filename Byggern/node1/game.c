#include "game.h"

void start_game(void) {
    joy_calibrate();
    can_message msg;
    msg.id = NEW_GAME;
    msg.length = 0;
    can_send(msg);
}
    
void send_game_ctrls(void) {
	joystick_position pos = get_joy_position();
	can_message msg;
    msg.id = GAME_CTRLS;
    msg.data[0] = (signed char) pos.x_pos;
    msg.data[1] = (signed char) pos.y_pos;
	msg.data[2] = (signed char) get_slider_position();
	//msg.data[1] = (signed char) get_button_state();
    msg.length = 3;
    can_send(msg);
}

