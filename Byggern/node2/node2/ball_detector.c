#include "ball_detector.h"

static uint8_t n_ball_lost;
static bool ball_flag;

void adc_init(void) {
	//	Set Vref to AVCC
	set_bit(ADMUX,REFS0);
	
	//	Enable ADC
	set_bit(ADCSRA,ADEN);
	
	//	Set prescaler to Fcpu/16
	set_bit(ADCSRA,ADPS2);
}

void ball_detector_init(void) {
	adc_init();
	n_ball_lost = 0;
	ball_flag = FALSE;
}

uint16_t adc_get_val(void) {
	set_bit(ADCSRA,ADSC);
	wait_until_bit_is_clear(ADCSRA,ADSC);
	return ADC;
}


uint8_t check_ball_lost(void) {
	uint16_t val = adc_get_val();
	if (val < BALL_LOST) {
		_delay_ms(250);
		val = adc_get_val();
		if (val < BALL_LOST && ball_flag == FALSE) {
			n_ball_lost++;
			ball_flag = TRUE;
		}
	} else {
		ball_flag = FALSE;
	}
    return n_ball_lost;
}

void set_n_ball_lost(uint8_t val) { 
    n_ball_lost = val;
}
    
