#include <iostream>

#include "ArduinoConsole.h"

int main(int argc, char **argv)
{
	
	bveing::ArduinoConsole arduino(std::cout);
	
	arduino.pinMode(5, 1);
	
	return 0;
}
