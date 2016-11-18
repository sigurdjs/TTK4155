#ifndef DAC_H_
#define DAC_H_
#define MAX520_ADDRESS 0b01010000
#define MAX520_COMMAND 0b00000000
#include "TWI_Master.h"
#include <avr/interrupt.h>


void dac_init(void);
void dac_set_val(uint8_t channel, uint8_t new_val);


#endif /* DAC_H_ */