#include <stdlib.h>
#include "joystick.h"
#include "adc.h"

#define NEUTRAL 40

static joystick_direction prev_dir;
static uint16_t zero_x;
static uint16_t zero_y;

void joy_init() {
    adc_init();
}

void joy_calibrate() {
    zero_x = adc_read(JOY_X);
    zero_y = adc_read(JOY_Y);
}

joystick_position get_joy_position(void) {
    joystick_position pos;
    pos.x_pos = 100*((adc_read(JOY_X) - zero_x)/128);
    pos.y_pos = 100*((adc_read(JOY_Y) - zero_y)/128);
    return pos;
}
       
joystick_direction get_joy_direction(void) {
    joystick_position pos = get_joy_position();
    joystick_direction dir;
    if(abs(pos.x_pos) < NEUTRAL && abs(pos.y_pos) < NEUTRAL) {
        dir = NEUTRAL;
    } else if(abs(pos.x_pos) < NEUTRAL && pos.y_pos > NEUTRAL) {
        dir = UP;
    } else if(abs(pos.x_pos) < NEUTRAL && pos.y_pos < NEUTRAL) {
        dir = DOWN;
    } else if(pos.x_pos > NEUTRAL && abs(pos.y_pos) < NEUTRAL) {
        dir = RIGHT;
    } else if(pos.x_pos < NEUTRAL && abs(pos.y_pos) < NEUTRAL) {
        dir = LEFT;
    } else {
        dir = prev_dir;
    }
    prev_dir = dir;
    return dir;
}

