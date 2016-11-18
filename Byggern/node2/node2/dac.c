#include "dac.h"

void dac_init(void) {
	TWI_Master_Initialise();
	sei();
}

void dac_set_val(uint8_t channel, uint8_t new_val) {
	uint8_t msg[3] = {
					MAX520_ADDRESS,
					MAX520_COMMAND & channel,
					new_val
	};
	TWI_Start_Transceiver_With_Data(msg,3);	
}