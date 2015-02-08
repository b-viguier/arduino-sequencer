#ifndef ARDUINOINTERFACE_H
#define ARDUINOINTERFACE_H

#include <stdint.h>

namespace bveing
{

	class ArduinoInterface
	{
	public:
		virtual ~ArduinoInterface() {};
		
		virtual void pinMode(uint8_t pin, uint8_t mode) = 0;
		
		virtual void digitalWrite(uint8_t pin, uint8_t val) = 0;
		
		virtual int digitalRead(uint8_t pin) = 0;
		
		virtual int analogRead(uint8_t pin) = 0;
		
		virtual void analogReference(uint8_t mode) = 0;
		
		virtual void analogWrite(uint8_t pin, int value) = 0;
	};

}

#endif // ARDUINOINTERFACE_H
