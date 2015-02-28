#include <Arduino.h>
#include <IRremote.h>
#include "Sequence.h"


IRrecv irrecv(3);
decode_results results;

void setup()
{
	irrecv.enableIRIn();
}

#define LED_B 1
#define LED_R 2
#define FLASH_TIME 80

#define LED_BLINK_LEFT 5
#define LED_BLINK_RIGHT 6

#define CLIGNO_TIME 500
//Dans l'intervall ]0, 1]
#define CLIGNO_TRANSITION 0.3

PatternSequence
	leftStrobe ("1100110011001111", FLASH_TIME),
	rightStrobe("0011001100111111", FLASH_TIME);
ConstantSequence
	on(1),
	off(0);
BlinkSequence blinker(CLIGNO_TIME, CLIGNO_TRANSITION);

Sequence* leftSequences[] = {&off, &on, &leftStrobe};
Sequence* rightSequences[] = {&off, &on, &rightStrobe};
int currentSequence = 0;

Sequence* blinkerStates[] = {&off, &blinker};
int leftBlinker  = 0;
int rightBlinker = 0;

void loop()
{
	const unsigned long m = millis();
	
	if (irrecv.decode(&results))
	{
		switch(results.value) {
			case 0xFF02FD:
				leftBlinker = rightBlinker =
					(leftBlinker && rightBlinker) ? 0 : 1;
				blinker.start = m;
				break;
			case 0xFF22DD: 
				leftBlinker = (leftBlinker+1)%2;
				rightBlinker = 0;
				blinker.start = m;
				break;
			case 0xFFC23D:
				leftBlinker = 0;
				rightBlinker = (rightBlinker+1)%2;
				blinker.start = m;
				break;
			case 0xFF6897:
				currentSequence = (currentSequence+1) % 3;
				leftSequences[currentSequence]->start =
					rightSequences[currentSequence]->start =
						m;
				break;
		}
		irrecv.resume();
	}
	
	// Cligno
	analogWrite(LED_BLINK_LEFT, blinkerStates[leftBlinker]->val(m));
	analogWrite(LED_BLINK_RIGHT, blinkerStates[rightBlinker]->val(m));
	
	// Flash
	digitalWrite(LED_B, leftSequences[currentSequence]->val(m));
	digitalWrite(LED_R, rightSequences[currentSequence]->val(m));
}
