#include <Arduino.h>
#include <sys/time.h>
#include <iostream>

int states[8] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
unsigned long millis_start;

unsigned long absolute_millis(void)
{
	timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

unsigned long millis(void)
{
	return absolute_millis() - millis_start;
}

void digitalWrite(uint8_t pin, uint8_t val)
{
	states[pin] = val;
}

void analogWrite(uint8_t pin, int value)
{
	states[pin] = value;
}

int main(void)
{
	
	const uint nb_pins = (sizeof(states)/sizeof(*states));
	millis_start = absolute_millis();
	
	setup();
    
	for (;;) {
		loop();
		for(uint i =0; i < nb_pins; ++i) {
			std::cout<< states[i] << "   ";
		}
		std::cout << millis() << "\r";
	}
        
	return 0;
}
