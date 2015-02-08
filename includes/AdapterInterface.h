#ifndef ADAPTERINTERFACE_H
#define ADAPTERINTERFACE_H

#include <stdint.h>

namespace bveing
{

	class AdapterInterface
	{
	public:
		virtual ~AdapterInterface() {};
		
		virtual void pinMode(uint8_t pin, uint8_t mode) = 0;
		
		virtual void digitalWrite(uint8_t pin, uint8_t val) = 0;
		
		virtual int digitalRead(uint8_t pin) = 0;
		
		virtual int analogRead(uint8_t pin) = 0;
		
		virtual void analogReference(uint8_t mode) = 0;
		
		virtual void analogWrite(uint8_t pin, int value) = 0;
	};

}

#endif // ADAPTERINTERFACE_H
