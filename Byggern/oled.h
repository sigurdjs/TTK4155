#ifndef _OLED_H_
#define _OLED_H_

#include <avr/io.h>
#include "setup.h"

void oled_init(void);
void OLED_print_arrow(void);
void OLED_go_to_page(uint8_t page);
void OLED_clear_page(uint8_t page);
void OLED_reset(void);
void oled_home();


#endif