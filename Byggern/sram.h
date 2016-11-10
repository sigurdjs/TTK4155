#ifndef _SRAM_H_
#define _SRAM_H_

#include <avr/io.h>


void sram_test(void);
void sram_w(unsigned char value, uint8_t address);
unsigned char sram_r(uint8_t address);


#endif
