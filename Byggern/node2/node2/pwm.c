#include "setup.h"
#include "pwm.h"

void pwm_init(void) {
	/*	Enable fast PWM			*/
	//clear_bit(TCCR4A,WGM40);
	set_bit(TCCR4A,WGM41); 
	set_bit(TCCR4B,WGM42);
	set_bit(TCCR4B,WGM43);	
	
	set_bit(TCCR4A,COM4A1);
	
	/*	Fck/64 clk scaling		*/
	set_bit(TCCR4B,CS40);
	set_bit(TCCR4B,CS41);
	
	ICR4 = F_CPU/64/1000*20;
	
	/*	Enable output on ph3	*/
	DDRH |= (1 << DDH3);
	
	pwm_new_width(1.5);
}


void pwm_new_width(float dc_ms) {
	if (dc_ms > 2.1) {
		OCR4A = F_CPU/64/1000*2.1;
	} else if(dc_ms < 0.9) {
		OCR4A = F_CPU/64/1000*0.9;		
	} else {
		OCR4A = F_CPU/64/1000*dc_ms;
	}
}
void pwm_reset(void) {
	OCR4A = F_CPU/64/1000*1.5;
}