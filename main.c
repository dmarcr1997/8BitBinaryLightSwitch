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
	DDRD |= 0b11111100; // set pins 2-7 as inputs
	DDRB &= ~(0b00000111); // set pins 8-10 as outpus
}

int main(void)
{
	setupPins();
	uint8_t switchState;
	uint8_t led_pattern;
	
    /* Replace with your application code */
    while (1) 
    {
		switchState = PINB & 0b00000111; // read state of switch pins but ignore other pin values
		
		switch(switchState) {
			case 0:
				led_pattern = 0b00000000; // RESET
				break;
			case 1:
				led_pattern = (1 << PIND2); // pin2 as HIGH
				break;
			case 2:
				led_pattern = (1 << PIND3); // pin3 as HIGH
				break;
			case 3:
				led_pattern = (1 << PIND4); // pin4 as HIGH
				break;
			case 4:	
				led_pattern = (1 << PIND5); // pin5 as HIGH
				break;
			case 5:
				led_pattern = (1 << PIND6); // pin6 as HIGH
				break;
			case 6:
				led_pattern = (1 << PIND7); // pin7 as HIGH
				break;
			default:
				led_pattern = 0b00000000; //RESET
		}
		PORTD &= 0b00000011; // clear led pins
		PORTD |= led_pattern; // set new led pin patter
			
		_delay_ms(50); // can be changed to vary brightness of leds
    }
	return 0;

}

