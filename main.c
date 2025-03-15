/*
 * 8BitBinaryLightSwitch.c
 *
 * Created: 3/15/2025 1:37:04 AM
 * Author : Damon Rocha
 */ 
#ifndef F_CPU
#define F_CPU 8000000UL		/* Define CPU Frequency 8MHz */
#endif

#include <avr/io.h>
#include <util/delay.h>

void setupPins() {
	DDRD |= 0b11111100;
	DDRB &= ~(0b00000111);
}

int main(void)
{
	setupPins();
	uint8_t switchState;
	uint8_t led_pattern;
	
    /* Replace with your application code */
    while (1) 
    {
		switchState = PINB & 0b00000111;
		
		switch(switchState) {
			case 0:
				led_pattern = 0b00000000;
				break;
			case 1:
				led_pattern = (1 << PIND2);
				break;
			case 2:
				led_pattern = (1 << PIND3);
				break;
			case 3:
				led_pattern = (1 << PIND4);
				break;
			case 4:	
				led_pattern = (1 << PIND5);
				break;
			case 5:
				led_pattern = (1 << PIND6);
				break;
			case 6:
				led_pattern = (1 << PIND7);
				break;
			default:
				led_pattern = 0b00000000;
		}
		PORTD &= 0b00000011;
		PORTD |= led_pattern;
			
		_delay_ms(50);
    }
	return 0;

}

