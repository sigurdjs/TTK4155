#include "motor.h"

void motor_init(void) {
	dac_init();
	// Set appropriate pins as output
	set_bit(DDRH,ENABLE);
	set_bit(DDRH,DIR);
	set_bit(DDRH,OE);
	set_bit(DDRH,RST);
	set_bit(DDRH,SEL);
	
	// Set port k as input
	DDRK = 0x00;
	//Enable motor
	set_bit(MJ1,ENABLE);
	clear_bit(MJ1,OE);
	clear_bit(MJ1,RST);
	_delay_us(250);
	set_bit(MJ1,RST);
}

void motor_set_direction(motor_dir dir) {
	if (dir == LEFT) {
		clear_bit(MJ1,DIR);
	} else {
		set_bit(MJ1,DIR);
	}
}

void motor_set_speed(uint8_t speed) {
	if (speed > DEADBAND) {
		dac_set_val(0,speed);
	} else {
		dac_set_val(0,0);
	}
}


void motor_calibrate(void) {
	motor_set_direction(RIGHT);
	motor_set_speed(75);
	_delay_ms(1500);
	clear_bit(MJ1,RST);
	_delay_us(50);
	set_bit(MJ1,RST);
}

int16_t motor_get_encoder_val(void) {
	int16_t val;
	clear_bit(MJ1,OE);
	_delay_us(10);
	clear_bit(MJ1,SEL);
	_delay_us(100);
	val = (PINK<<8);
	set_bit(MJ1,SEL);
	_delay_us(100);
	val |= PINK;
	set_bit(MJ1,OE);
	return val;
}
