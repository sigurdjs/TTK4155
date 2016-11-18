#ifndef MOTOR_H_
#define MOTOR_H_

#define MJ1 PORTH
#define MJ2 PORTK
#define DIR PH1
#define SEL PH3
#define ENABLE PH4
#define OE PH5
#define RST PH6
#define DEADBAND 7

#include "dac.h"
#include "avr/io.h"
#include <stdint.h>
#include "setup.h"
#include <util/delay.h>

typedef enum {LEFT, RIGHT} motor_dir;

void motor_init(void);
void motor_calibrate(void);
void motor_set_direction(motor_dir dir);
void motor_set_speed(uint8_t speed);
int16_t motor_get_encoder_val(void);





#endif /* MOTOR_H_ */