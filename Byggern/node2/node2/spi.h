#ifndef _SPI_H_
#define _SPI_H_

#define DDR_SPI DDRB
#define DD_SS PB0
#define DD_MOSI PB2
#define DD_MISO PB3
#define DD_SCK PB1

#include <avr/io.h>
#include "setup.h"


void spi_init(void);
void spi_write(char data);
char spi_read(void);
void spi_select(void);
void spi_deselect(void);


#endif