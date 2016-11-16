#ifndef _ADC_H_
#define _ADC_H_

#include <avr/io.h>

typedef enum {JOY_X, JOY_Y, SLIDER_LEFT, SLIDER_RIGHT} adc_channel;
void adc_init(void);
uint8_t adc_read(adc_channel channel);

#endif


