/*
 * main.c
 *
 * Created: 19.10.2016 18:52:31
 *  Author: sigurdjs
 */ 

#include "setup.h"
#include <avr/io.h>
#include <stdio.h>
#include "uart.h"
#include "util/delay.h"

void SRAM_test(void) {
	//Start address for the SRAM
	volatile char *ext_ram = (char *) 0x1800;

	uint16_t i, werrors, rerrors;
	werrors = 0;
	rerrors = 0;
	unsigned char testvalue;

	printf("Starting SRAM test...\r\n");

	for (i = 0; i < 0x800; i++) {
		testvalue = ~(i % 256);
		ext_ram[i] = testvalue;
		if (ext_ram[i] != testvalue) {
			printf("SRAM error (write phase): ext_ram[%d] = %02X (should be %02X)\r\n", i, ext_ram[i], testvalue);
			werrors++;
		}
	}

	for (i = 0; i < 0x800; i++) {
		testvalue = ~(i % 256);
		if (ext_ram[i] != testvalue) {
			printf("SRAM error (read phase): ext_ram[%d] = %02X (should be %02X)\r\n", i, ext_ram[i], testvalue);
			rerrors++;
		}
	}

	printf("SRAM test completed with %d errors in write phase and %d errors in read phase\r\n", werrors, rerrors);
}

void GAL_test(void) {
	volatile char *adc = (char *) 0x1000;
	uint16_t i;
	unsigned char testvalue = 'a';
	
	//printf("Starting write to ADC...\r\n");
	
	//for(i = 0; i < 0x1800; i++) {
		//testvalue = ~(i % 256);
	adc[0] = testvalue;
	//}
}

void adc_init(void) {
	MCUCR |= (1<<SRE);
	SFIOR |= (1<<XMM2);
	DDRE &= ~(1<<PINE0);
	
}

uint8_t adc_read(uint8_t channel) {
	
	volatile char *adc = (char *) 0x1400;
	
	*adc = 0x04 | channel;
	
	_delay_us(10);
	
	while (PINE & (1<<PINE0)) {}
	
	return *adc;
}

int main(void) {
	adc_init();	
	uart_init();

	SRAM_test();
	
    uint8_t value;
	while(1)
    {	
		value = (uint8_t)adc_read(0);
		printf("Joystick value is currently: %d \n",value);
		_delay_ms(200);
    }
	return 0;
}