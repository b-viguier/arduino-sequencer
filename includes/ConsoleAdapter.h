#ifndef ARDUINOCONSOLE_H
#define ARDUINOCONSOLE_H

#include <AdapterInterface.h>
#include <iosfwd>


namespace bveing
{

class ConsoleAdapter : public AdapterInterface
{
public:
	ConsoleAdapter(std::ostream& output);
	~ConsoleAdapter();
	
	void pinMode(uint8_t pin, uint8_t mode);
	
	void digitalWrite(uint8_t pin, uint8_t val);
	
	int digitalRead(uint8_t pin);
	
	int analogRead(uint8_t pin);
	
	void analogReference(uint8_t mode);
	
	void analogWrite(uint8_t pin, int value);

private:
	std::ostream& _output;
};

}

#endif // ARDUINOCONSOLE_H
