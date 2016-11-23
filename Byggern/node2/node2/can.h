#ifndef CAN_H_
#define CAN_H_

#include <stdlib.h>
#include "setup.h"
#include "mcp2515.h"

typedef enum {NEW_GAME, GAME_OVER, ALIVE, GAME_CTRLS} canid;
typedef struct {
	canid id;
	uint8_t length;
	signed char data[8];
} can_message;

int can_init(void);
int can_set_mode(char mode);
void can_send(can_message message);
can_message can_recieve(void);

#endif 
