#ifndef CAN_H_
#define CAN_H_

#include <stdlib.h>
#include "setup.h"
#include "mcp2515.h"

typedef struct {
	uint8_t id;
	uint8_t length;
	uint8_t data[8];
} can_message;

int can_init(void);
int can_set_mode(char mode);
void can_send(can_message message);
can_message can_recieve(void);

#endif 