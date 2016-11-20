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
        printf("Press any key to a start new game! \n");
        getchar();
        start_game();
        while(rcv_msg.id != GAME_OVER) {
            send_game_ctrls();
            rcv_msg = can_recieve();
            _delay_ms(50);
        }
    printf("You lost, game over! \n");
    }
    return 0;
}


