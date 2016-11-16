/*
 * node2.c
 *
 * Created: 16.11.2016 04:57:35
 *  Author: sigurdjs
 */ 

#include "setup.h"
#include "uart.h"
#include "can.h"
#include "spi.h"

#include <util/delay.h>


int main(void)
{
	uart_init();
	spi_init();
	char new_mode;
    while(1)
    {
		spi_select();
		mcp2515_bit_modify(MCP_CANCTRL,MODE_MASK,MODE_CONFIG);
		_delay_ms(100);
		new_mode = mcp2515_read(MCP_CANSTAT);
		new_mode = new_mode & MODE_MASK;
		printf("Mode is: %02X, should be: %02X \n",new_mode,MODE_CONFIG);
		spi_deselect();
		_delay_ms(1000);


    }
	return 0;
}