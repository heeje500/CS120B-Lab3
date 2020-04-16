/*	Author: hlee272
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #5
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
	DDRD = 0x00; PORTD = 0xFF; //inputs
	DDRB = 0xFE; PORTB = 0x01; //output

	unsigned char tmpD = 0x00;	
//	unsigned char tmpB = 0x00;
//	unsigned char weight = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpD = PIND;
//	tmpB = PINB & 0x01;
//	weight = tmpD + tmpB;
	unsigned char temp = 0x00;
	
	if (tmpD > 0x46) {
		temp = 0x02;
	}

	else if (tmpD > 0x05 && tmpD < 0x46) {
		temp = 0x04;
	}

	else {
		temp = 0x00;
	}

	PORTB = temp;
}

    return 1;
}
