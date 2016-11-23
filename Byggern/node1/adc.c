#include "setup.h"
#include <util/delay.h>
#include "adc.h"

void adc_init(void) {
	MCUCR |= (1<<SRE);
	SFIOR |= (1<<XMM2);
	DDRE &= ~(1<<PINE0);    //Enable interrupt pin
}

uint8_t adc_read(adc_channel channel) {
	volatile char *adc = (char *) 0x1400;

	*adc = 0x04 | channel;
	wait_until_bit_is_clear(PINE,PINE0);
	_delay_us(100);
	return *adc;
}





