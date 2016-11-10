#include "setup.h"
#include "adc.h"

void adc_init(void) {
	MCUCR |= (1<<SRE);
	SFIOR |= (1<<XMM2);
	DDRE &= ~(1<<PINE0);    //Enable interrupt pin
}

uint8_t adc_read(uint8_t channel) {
	volatile char *adc = (char *) 0x1400;

	*adc = 0x04 | channel;
	while (PINE & (1<<PINE0)) {}
	return *adc;
}





