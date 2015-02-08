#include "ArduinoConsole.h"

#include <ostream>

using namespace bveing;

ArduinoConsole::ArduinoConsole(std::ostream& output)
: _output(output)
{
}

ArduinoConsole::~ArduinoConsole()
{
}

void ArduinoConsole::pinMode(uint8_t pin, uint8_t mode)
{
	_output 
		<< __func__ 
		<< " pin " << (int)pin
		<< " mode " << (int)mode
		<< std::endl
	;
}
void ArduinoConsole::digitalWrite(uint8_t pin, uint8_t val)
{
	_output 
		<< __func__ 
		<< " pin " << (int)pin
		<< " val " << (int)val
		<< std::endl
	;
}
int ArduinoConsole::digitalRead(uint8_t pin)
{
	_output 
		<< __func__ 
		<< " pin " << (int)pin
		<< std::endl
	;
	return 0;
}
int ArduinoConsole::analogRead(uint8_t pin)
{
	_output 
		<< __func__ 
		<< " pin " << (int)pin
		<< std::endl
	;
	return 0;
}
void ArduinoConsole::analogReference(uint8_t mode)
{
	_output 
		<< __func__ 
		<< " mode " << (int)mode
		<< std::endl
	;
}
void ArduinoConsole::analogWrite(uint8_t pin, int value)
{
	_output 
		<< __func__ 
		<< " pin " << (int)pin
		<< " val " << (int)value
		<< std::endl
	;
}
