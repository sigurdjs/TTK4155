#include "uart.h"
#include "sram.h"
#include "adc.h"
#include "joystick.h"
#include "oled.h"
#include "spi.h"
#include "mcp2515.h"
#include "can.h"
#include "game.h"
#include <util/delay.h>


int main(void) {
	adc_init();	
	uart_init();
	sram_test();
	//oled_init();
	//OLED_reset();
	can_init();
	can_message snd_msg;
	can_message rcv_msg;
	while(1)
    {	
        printf("Press any key to start new game! \n");
        getchar();
        start_game();
        while(1) {
            send_game_ctrls();
            rcv_msg = can_recieve();
            switch(rcv_msg.id) {
                case GAME_OVER:
                    printf("You lost, game over! \n");
                    break;
            }
            _delay_ms(50);
        }
    }
	return 0;
}


