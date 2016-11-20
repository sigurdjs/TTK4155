#include "oled.h"



void oled_init(void) {
	
	MCUCR |= (1<<SRE);
	SFIOR |= (1<<XMM2);
	volatile uint8_t *oled_cmd = (uint8_t *) 0x1000;
		
	*oled_cmd = 0xAE;	//Display off
	*oled_cmd = 0xA1;	//Segment remap
	*oled_cmd = 0xDA;	//Common pads hardware: alternative
	*oled_cmd = 0x12;
	*oled_cmd = 0xC8;	//Common output scan direction:com63~com0
	*oled_cmd = 0xA8;	//Multiplex ration mode:63
	*oled_cmd = 0x3F;	
	*oled_cmd = 0xD5;	//Display divide ratio/osc. freq. mode
	*oled_cmd = 0x80;	
	*oled_cmd = 0x81;	//Contrast control
	*oled_cmd = 0x50;
	*oled_cmd = 0xD9;	//Set pre-charge period
	*oled_cmd = 0x21;	
	*oled_cmd = 0x20;	//Set memory addressing mode
	*oled_cmd = 0x02;	
	*oled_cmd = 0xDB;	//VCOM deselect level mode
	*oled_cmd = 0x30;	
	*oled_cmd = 0xAD;	//Master configuration
	*oled_cmd = 0x00;
	*oled_cmd = 0xA4;	//Out follows RAM content
	*oled_cmd = 0xA6;	//Set normal display
	*oled_cmd = 0xAF;	//Display on
}

void oled_test(void) {
	volatile uint8_t *oled_data = (uint8_t *) 0x1200;
	uint8_t testbyte = (uint8_t) rand()%256;
	*oled_data = testbyte;
	/*for (uint16_t i = 0; i < 1024; i++) {
		testbyte = (unsigned char) rand()%256;
		*oled_data =  testbyte;
	}*/
}

void OLED_print_arrow(void) {
	volatile uint8_t *oled_data = (uint8_t *) 0x1200 ;
	*oled_data = 0b00011000;
	*oled_data = 0b00011000;
	*oled_data = 0b01111110;
	*oled_data = 0b00111100;
	*oled_data = 0b00011000;
}

