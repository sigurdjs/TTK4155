#ifndef BALL_DETECTOR_H_
#define BALL_DETECTOR_H_

#define ADC_PORT PF0
#define BALL_LOST 25

#include "setup.h"
#include <util/delay.h>
#include <avr/io.h>

typedef enum {FALSE, TRUE} bool;

void adc_init(void);
void ball_detector_init(void);
uint16_t adc_get_val(void);
void check_ball_lost(void);
uint8_t get_n_ball_lost(void);
void set_n_ball_lost(uint8_t val);

#endif
