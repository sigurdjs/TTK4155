#include "mcp2515.h"

void mcp2515_init(void) {
	spi_init();
	mcp2515_reset();
}


void mcp2515_reset(void) {
	spi_select();
	spi_write(MCP_RESET);
	spi_deselect();
}

char mcp2515_read(char reg_address) {
	spi_select();
	spi_write(MCP_READ);
	spi_write(reg_address);
	char result = spi_read();
	spi_deselect();
	return result;
}

void mcp2515_write(char reg_address, char data) {
	spi_select();
	spi_write(MCP_WRITE);
	spi_write(reg_address);
	spi_write(data);
	spi_deselect();
}

void mcp2515_req_to_send(char buf_address) {
	spi_select();
	spi_write(buf_address);
	spi_deselect();
}
char mcp2515_read_status(void) {
	spi_select();
	spi_write(MCP_READ_STATUS);
	char result = spi_read();
	spi_deselect();
	return result;	
}

void mcp2515_bit_modify(char reg_address, char mask, char data) {
	spi_select();
	spi_write(MCP_BITMOD);
	spi_write(reg_address);
	spi_write(mask);
	spi_write(data);
	spi_deselect();
}