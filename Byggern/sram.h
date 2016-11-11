#ifndef _SRAM_H_
#define _SRAM_H_

#include <avr/io.h>


void sram_test(void);
void sram_w(char value, uint8_t address);
char sram_r(uint8_t address);


#endif
