#include "IRremote.h"
#include "main.h"
#include <ncurses.h>

IRrecv::IRrecv(int recvpin)
{
}

void IRrecv::enableIRIn()
{
}

void IRrecv::resume()
{
	last_input = ERR;
}

int IRrecv::decode(decode_results* results)
{
	switch(last_input) {
		case KEY_LEFT:
			results->value = 0xFF22DD;
			break;
		case KEY_RIGHT:
			results->value = 0xFFC23D;
			break;
		case ' ':
			results->value = 0xFF02FD;
			break;
		case '1':
			results->value = 0xFF6897;
			break;
		case '2':
			results->value = 0xFF9867;
			break;
		case '3':
			results->value = 0xFFB04F;
			break;
		case '4':
			results->value = 0xFF30CF;
			break;
		case '5':
			results->value = 0xFF18E7;
			break;
		default:
			return 0;
	}
	return 1;
}
