#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#include <avr/io.h>
#include "setup.h"
#include "adc.h"

typedef enum {LEFT, RIGHT, UP, DOWN, NEUTRAL} joystick_direction; 
typedef struct {
    int16_t x_pos;
    int16_t y_pos;
} joystick_position;

void joy_init();
void joy_calibrate();
joystick_direction get_joy_direction();
joystick_position get_joy_position();
uint16_t get_slider_position(adc_channel channel);



#endif

