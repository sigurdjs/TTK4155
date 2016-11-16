#include "spi.h"

void spi_init(void) {
	// Set MOSI, SCK and SS output, MISO input 
	set_bit(DDR_SPI,DD_MOSI);
	set_bit(DDR_SPI,DD_SCK);
	set_bit(DDR_SPI,DD_SS);
	clear_bit(DDR_SPI,DD_MISO);
	// Enable SPI, Master, set clock rate fck/16 
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void spi_write(char data) {
	/* Start transmission */
	SPDR = data;
	/* Wait for transmission complete */
	wait_until_bit_is_set(SPSR,SPIF);
}

char spi_read(void) {
	// Something needs to be sent to be able to read the spi register
	spi_write(0);
	
	wait_until_bit_is_set(SPSR,SPIF);
	return SPDR;
}

void spi_select(void) {
	clear_bit(PORTB,PINB4);
}


void spi_deselect(void) {
	set_bit(PORTB,PINB4);
}