/*
 * Byggern.c
 *
 * Created: 19.10.2016 18:52:31
 *  Author: sigurdjs
 */ 

#define set_bit( reg, bit ) (reg |= (1 << bit))
#define clear_bit( reg, bit ) (reg &= ~(1 << bit))
#define test_bit( reg, bit ) (reg & (1 << bit))

#include <avr/io.h>

int main(void)
{
    while(1)
    {
		set_bit(PORTA,PA0);
    }
}