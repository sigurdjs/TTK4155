#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>

void pwm_init(void);
void pwm_new_width(float dc_ms);
void pwm_reset(void);



#endif /* PWM_H_ */