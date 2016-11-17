#include "spi.h"

void spi_init(void) {
	/* Set MOSI, SCK and SS output, MISO input. 
	PINB0 has to be set as output to enable '
	transmission flag to work correctly, since this is origial SS */
	DDR_SPI = (1<<DD_SS)|(1<<DD_SCK)|(1<<DD_MOSI)|(1<<PINB0);
	DDR_SPI &= ~(1<<DD_MISO);
	// Enable SPI, Master, set clock rate fck/16
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	
	//set_bit(SPSR,SPI2X);
}

char spi_write(char data) {
	/* Start transmission */
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
	//_delay_us(10);
	return SPDR;
}

char spi_read(void) {
	// Something needs to be sent to be able to read the spi register
	return spi_write(0);
}

void spi_select(void) {
	clear_bit(PORTB,PINB7);
}


void spi_deselect(void) {
	set_bit(PORTB,PINB7);
}