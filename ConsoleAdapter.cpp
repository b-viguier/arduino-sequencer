#include "ConsoleAdapter.h"

#include <ostream>

using namespace bveing;

ConsoleAdapter::ConsoleAdapter(std::ostream& output)
: _output(output)
{
}

ConsoleAdapter::~ConsoleAdapter()
{
}

void ConsoleAdapter::pinMode(uint8_t pin, uint8_t mode)
{
	_output 
		<< __func__ 
		<< " pin " << (int)pin
		<< " mode " << (int)mode
		<< std::endl
	;
}
void ConsoleAdapter::digitalWrite(uint8_t pin, uint8_t val)
{
	_output 
		<< __func__ 
		<< " pin " << (int)pin
		<< " val " << (int)val
		<< std::endl
	;
}
int ConsoleAdapter::digitalRead(uint8_t pin)
{
	_output 
		<< __func__ 
		<< " pin " << (int)pin
		<< std::endl
	;
	return 0;
}
int ConsoleAdapter::analogRead(uint8_t pin)
{
	_output 
		<< __func__ 
		<< " pin " << (int)pin
		<< std::endl
	;
	return 0;
}
void ConsoleAdapter::analogReference(uint8_t mode)
{
	_output 
		<< __func__ 
		<< " mode " << (int)mode
		<< std::endl
	;
}
void ConsoleAdapter::analogWrite(uint8_t pin, int value)
{
	_output 
		<< __func__ 
		<< " pin " << (int)pin
		<< " val " << (int)value
		<< std::endl
	;
}
