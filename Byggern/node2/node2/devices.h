#ifndef DEVICES_H_
#define DEVICES_H_

#include "can.h"
#include "motor.h"
#include "ball_detector.h"
#include "pwm.h"

void update_ctrls(can_message msg);
void check_game_status(uint8_t n_lives); 

#endif
