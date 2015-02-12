#include <Arduino.h>

void setup()
{
}

#define LED_B 1
#define LED_R 2
#define FLASH_TIME 80

#define LED_CLIGNO 5
#define CLIGNO_TIME 500
//Dans l'intervall ]0, 1]
#define CLIGNO_TRANSITION 0.3

void loop()
{
	const unsigned long m = millis();
	
	// Cligno
	const double signal_raw = sin( m * PI / CLIGNO_TIME);
	const double signal_max = max(- CLIGNO_TRANSITION, signal_raw);
	const double signal_min = min( CLIGNO_TRANSITION, signal_max);
	analogWrite(
		LED_CLIGNO,
		( 0.5 + signal_min / (2. * CLIGNO_TRANSITION) )
		* 255
	);
	
	// Flash
	const unsigned long sub_beat = (m / FLASH_TIME ) % 32;
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
