#include <stdlib.h>
#include "joystick.h"
#include "adc.h"

#define NEUTRAL 40

static joystick_direction prev_dir;
static uint8_t zero_x;
static uint8_t zero_y;

void joy_init(void) {
    //set_bit(PORTD,PD4);
	//clear_bit(DDRD,DDD4);
    adc_init();
}

void joy_calibrate(void) {
    zero_x = adc_read(JOY_X);
    zero_y = adc_read(JOY_Y);
}

joystick_position get_joy_position(void) {
    joystick_position pos;
    pos.x_pos = (int16_t) 100*(((double) adc_read(JOY_X) - (double) zero_x)/129);
    pos.y_pos = (int16_t) 100*(((double) adc_read(JOY_Y) - (double) zero_y)/129);
    return pos;
}
       
joystick_direction get_joy_direction(void) {
    joystick_position pos = get_joy_position();
    joystick_direction dir;
    if(abs(pos.x_pos) < NEUTRAL && abs(pos.y_pos) < NEUTRAL) {
		printf("Direction is neutral \n");
        dir = NEUTRAL;
    } else if(abs(pos.x_pos) < NEUTRAL && pos.y_pos > NEUTRAL) {
        printf("Direction is up \n");
		dir = UP;
    } else if(abs(pos.x_pos) < NEUTRAL && pos.y_pos < NEUTRAL) {
        printf("Direction is down \n");
		dir = DOWN;
    } else if(pos.x_pos > NEUTRAL && abs(pos.y_pos) < NEUTRAL) {
        printf("Direction is right \n");
		dir = RIGHT;
    } else if(pos.x_pos < NEUTRAL && abs(pos.y_pos) < NEUTRAL) {
        printf("Direction is left \n");
		dir = LEFT;
    } else {
		printf("Direction is previous \n");
        dir = prev_dir;
    }
    prev_dir = dir;
    return dir;
}

signed char get_slider_position() {
	signed char sl_val = adc_read(SLIDER_RIGHT);
	return sl_val;
}

/*bool get_button_state(void) {
    uint8_t an_val = adc_read(BUTTON_RIGHT);
	if (an_val < 10) {
		return FALSE;
	} else {
		return TRUE;
	}
}*/
