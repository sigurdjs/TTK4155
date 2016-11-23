#pragma once

#include <avr/io.h>
#include "setup.h"
#include "adc.h"

//typedef enum {FALSE, TRUE} bool;
typedef enum {LEFT, RIGHT, UP, DOWN, NEUTRAL} joystick_direction; 
typedef struct {
    int16_t x_pos;
    int16_t y_pos;
} joystick_position;

void joy_init(void);
void joy_calibrate(void);
joystick_direction get_joy_direction(void);
joystick_position get_joy_position(void);
signed char get_slider_position(void);
//bool get_button_state(void);

