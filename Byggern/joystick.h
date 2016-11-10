#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#include <avr/io.h>
#include "setup.h"
#include "adc.h"

typedef enum {LEFT, RIGHT, UP, DOWN, NEUTRAL} joystick_direction; 
typedef struct {
    uint8_t x_pos;
    uint8_t y_pos;
} joystick_position;

void joy_init();
void joy_calibrate();
joystick_direction get_joy_direction();
joystick_position get_joy_position();



#endif

