/*
 * main.c
 *
 *  Created on: Jun 14, 2015
 *      Author: jimparker
 */

#include <avr/io.h>
#include <util/delay.h>
void display(short num) {
	//PORTB = num / 0b100;
	//PORTC = (num - PORTB * 0b100);
	PORTB = num;
	PORTC = (num - PORTB)/0b100000000;
}

int main(void) {
	DDRB |= (0b11111111);
	DDRC |= (0b00000011);

	/*
	short nums[] = {0b0001110011,
					0b0011001101,
					0b0111000100};
	uint8_t numNums = 3;

	uint8_t i = 0;
	*/
	short i = 0;
	while (1) {
		display(i);
		_delay_ms(200);
		if (++i >= 0b1111111111) i = 0;
	}
	return(0);
}



