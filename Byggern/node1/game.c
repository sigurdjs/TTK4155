#include "game.h"

void start_game(void) {
    joystick_calibrate();
    can_message msg;
    msg.id = NEW_GAME;
    msg.length = 0;
    can_send(msg);
}
    
void send_game_ctrls(void) {
    joystick_position pos = get_joy_position();
    can_message msg;
    msg.id = GAME_CTRLS;
    msg.data[0] = uint8_t pos.x_pos;
    msg.data[1] = uint8_t pos.y_pos;
    msg.data[2] = get_slider_positiom(SLIDER_RIGHT);
    msg.data[3] = get_button_state();
    msg.length = 4;
    can_send(msg);
}

