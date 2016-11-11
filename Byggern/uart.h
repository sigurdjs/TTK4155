#ifndef UART_H
#define UART_H
#include <stdio.h>

void uart_init(void);
void uart_send_char(char c, FILE *stream);
char uart_recieve_char(FILE *stream);

static FILE uart_io = FDEV_SETUP_STREAM(uart_send_char, uart_recieve_char, _FDEV_SETUP_RW);

#endif

