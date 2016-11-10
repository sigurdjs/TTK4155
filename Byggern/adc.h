#ifndef _ADC_H_
#define _ADC_H_

#include <avr/io.h>

void adc_init(void);
uint8_t adc_read(uint8_t channel);

#endif


