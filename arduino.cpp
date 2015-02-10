#include <Arduino.h>

void setup()
{
}

#define LED_B 1
#define LED_R 2
#define FLASH_TIME 80

void loop()
{
	const unsigned long m 		 = millis() % (32 * FLASH_TIME);
	const unsigned long sub_beat = m / FLASH_TIME;
	
	if( sub_beat % 2) {
		digitalWrite(LED_B, LOW);
		digitalWrite(LED_R, LOW);
		return;
	}
	const unsigned long beat = sub_beat / 4;
	
	/**
	 * 0011223344556677
	 * BB  BB  BB  BBBB
	 *   RR  RR  RRRRRR
	 **/
	digitalWrite(LED_B, (!(beat % 2) || beat == 7) ? HIGH : LOW);
	digitalWrite(LED_R, (  beat % 2  || beat == 6) ? HIGH : LOW);
}