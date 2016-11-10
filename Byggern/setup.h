#ifndef _SETUP_H_
#define _SETUP_H_ 

#define set_bit( reg, bit ) (reg |= (1 << bit))
#define clear_bit( reg, bit ) (reg &= ~(1 << bit))
#define test_bit( reg, bit ) (reg & (1 << bit))
#define loop_until_bit_is_set( reg, bit ) while( !test_bit( reg, bit ))
#define loop_until_bit_is_clear( reg, bit ) while( test_bit( reg, bit ))

#define F_CPU 4915200 // clock frequency in Hz
#define BAUD 9600

#endif
