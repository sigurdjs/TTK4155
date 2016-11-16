#include <avr/io.h>
#include "uart.h"
#include "setup.h"

void uart_init() {
	//Set baud rate
	unsigned int ubrr = (F_CPU-250)/16/BAUD-1;
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)(ubrr);

	// Set 8-bit data 2 stop bit
	UCSR0C = (3<<UCSZ00);
	// Enable RX0 and TX0
	UCSR0B = (1 << RXEN0 | (1 << TXEN0));
	
	// Link to stdio
	stdout = &uart_io;
	stdin = &uart_io;
}

void uart_send_char(char c, FILE *stream) {
	if (c == '\n') {
	    uart_send_char('\r', stream);
	}
	loop_until_bit_is_set(UCSR0A,UDRE0);
	UDR0 = c;
}

char uart_recieve_char(FILE *stream) {
	loop_until_bit_is_set(UCSR0A,RXC0);
	return UDR0;
}

