/*
 * Byggern.c
 *
 * Created: 19.10.2016 18:52:31
 *  Author: sigurdjs
 */ 

#define set_bit( reg, bit ) (reg |= (1 << bit))
#define clear_bit( reg, bit ) (reg &= ~(1 << bit))
#define test_bit( reg, bit ) (reg & (1 << bit))
#define loop_until_bit_is_set( reg, bit ) while( !test_bit(reg,bit))
#define loop_until_bit_is_clear( reg, bit ) while( test_bit( reg, bit ))

#define F_CPU 16000000 // clock frequency in Hz

#include "util/delay.h"
#include <avr/io.h>

FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

void uart_send_char(char c, FILE *stream) {
	if (c == '\n') {
		uart_send_char('\r');
	}
	loop_until_bit_is_set(UCSR0A,UDRE0);
	UDR0 = c;
} 

char uart_recieve_char(FILE *stream) {
	loop_until_bit_is_set(UCSR0A,RXC0);
	return UDR0;
}

int main(void)
{
    while(1)
    {
		uart_send_char('a');
    }
}