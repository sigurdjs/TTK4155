#ifndef _SPI_H_
#define _SPI_H_

#include "setup.h"
#include <avr/io.h>
#include <util/delay.h>

#define DDR_SPI DDRB
#define DD_SS PINB7
#define DD_MOSI PINB2
#define DD_MISO PINB3
#define DD_SCK PINB1



void spi_init(void);
char spi_write(char data);
char spi_read(void);
void spi_select(void);
void spi_deselect(void);


#endif