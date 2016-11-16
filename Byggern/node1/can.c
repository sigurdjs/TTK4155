#include "can.h"

int can_init(void) {
	clear_bit(DDRD,PIND2);    //Enable new message interrupt pin
	
	mcp2515_init();
	if (can_set_mode(MODE_CONFIG) != 0) {
		printf("MCP2515 reset failed! \n");
		return EXIT_FAILURE;
	}
	can_set_mode(MODE_LOOPBACK);
	
	mcp2515_bit_modify(MCP_RXB0CTRL, 0b01100100, 0xFF);
	mcp2515_bit_modify(MCP_CANINTE, 0x01, 1);
	//can_set_mode(MODE_NORMAL);
	return EXIT_SUCCESS;
}

int can_set_mode(char mode) {
	mcp2515_bit_modify(MCP_CANCTRL,MODE_MASK,mode);
	char new_mode = mcp2515_read(MCP_CANSTAT);
	new_mode = new_mode & MODE_MASK;
	if(new_mode != mode) {
		return EXIT_FAILURE;
	} else{
		return EXIT_SUCCESS;
	}
}

void can_send(can_message message) {
	wait_until_bit_is_clear(mcp2515_read(MCP_TXB0CTRL),3);
	
	mcp2515_write(MCP_TXB0SIDH,(char) (message.id >> 3));
	mcp2515_write(MCP_TXB0SIDL,(char) (message.id << 5));
	mcp2515_write(MCP_TXB0DLC,(char) (message.length));
	for (int i = 0; i < message.length; i++) {
		mcp2515_write(MCP_TXB0D0 + i, message.data[i]);
	}
	
	mcp2515_req_to_send(MCP_RTS_TX0);	
}

can_message can_recieve(void) {
	wait_until_bit_is_clear(PIND,PIND2);
	//printf("hello \n");
	
	can_message message;
	if (test_bit(mcp2515_read(MCP_CANINTF),MCP_RX0IF)) {
		message.id = (uint8_t) (mcp2515_read(MCP_RXB0SIDH) << 3) | (mcp2515_read(MCP_RXB0SIDL) >> 5);
		message.length = (uint8_t) mcp2515_read(MCP_RXB0DLC) & (0x0f);
		//printf("ID: %d \n", message.id);
		for (int i = 0; i < message.length; i++) {
			message.data[i] = (uint8_t) mcp2515_read(MCP_RXB0D0 + i);
		}
		//printf("Data: %d",message.data[0]);
		mcp2515_bit_modify(MCP_CANINTF,0x01,0);
	} else {
		message.id = -1;
	}
	return message;	
}