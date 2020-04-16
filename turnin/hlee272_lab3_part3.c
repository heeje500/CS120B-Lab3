/*	Author: hlee272
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; //inputs
	DDRC = 0xFF; PORTC = 0x00; //output

	unsigned char tmpA = 0x00;	
	unsigned char tmpC = 0x00;
	unsigned char light = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA & 0x0F;
	tmpC = PINA & 0xF0;

	if (tmpA <= 0x02) {
		light = 0x60;
		}

	else if (tmpA <= 0x04) {
		light = 0x70;
		}

	else if (tmpA <= 0x06) {
		light = 0x38;
	}

	else if (tmpA <=  0x09) {
		 light = 0x3C;
	}

	else if (tmpA <= 0x0C) {
		light = 0x3E;
	}

	else if (tmpA <= 0x0F) {
		light = 0x3F;
	}

	if (tmpC == 0x30) {
		light = light | 0x80;
	}
  
	PORTC = light;  	
    }

    return 1;
}
