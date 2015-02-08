#include <iostream>

#include "ConsoleAdapter.h"

int main(int argc, char **argv)
{
	
	bveing::ConsoleAdapter arduino(std::cout);
	
	arduino.pinMode(5, 1);
	
	return 0;
}
