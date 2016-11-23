#pragma once
#include <avr/io.h>

typedef enum {JOY_X, JOY_Y, BUTTON_RIGHT, SLIDER_RIGHT} adc_channel;
void adc_init(void);
uint8_t adc_read(adc_channel channel);


