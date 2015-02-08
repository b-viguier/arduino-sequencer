#include <Arduino.h>

#include "ConsoleAdapter.h"
#include <iostream>

bveing::ConsoleAdapter arduino(std::cout);

void setup()
{
	arduino.pinMode(5, 1);
}

void loop()
{
	arduino.digitalWrite(5, LOW);
}