#include <Arduino.h>
#include <IRremote.h>

IRrecv irrecv(3);
decode_results results;

void setup()
{
	irrecv.enableIRIn();
}

#define LED_B 1
#define LED_R 2
#define FLASH_TIME 80

#define LED_CLIGNO 5
#define CLIGNO_TIME 500
//Dans l'intervall ]0, 1]
#define CLIGNO_TRANSITION 0.3

bool cligno = false;
bool strobe = false;

void loop()
{
	if (irrecv.decode(&results))
	{
		switch(results.value) {
			case 0xFF02FD:
				cligno = !cligno;
				break;
			case 0xFF6897:
				strobe = !strobe;
				break;
		}
		irrecv.resume();
	}
	const unsigned long m = millis();
	
	// Cligno
	if(cligno) {
		const double signal_raw = sin( m * PI / CLIGNO_TIME);
		const double signal_max = max(- CLIGNO_TRANSITION, signal_raw);
		const double signal_min = min( CLIGNO_TRANSITION, signal_max);
		analogWrite(
			LED_CLIGNO,
			( 0.5 + signal_min / (2. * CLIGNO_TRANSITION) )
			* 255
		);
	}
	
	// Flash
	if(strobe) {
		const unsigned long sub_beat = (m / FLASH_TIME ) % 32;
		uint8_t value_r = LOW, value_b = LOW;
		if( sub_beat % 2 == 0 ) {
			
			const unsigned long beat = sub_beat / 4;
			/**
			 * 0011223344556677
			 * BB  BB  BB  BBBB
			 *   RR  RR  RRRRRR
			 **/
			value_b = (!(beat % 2) || beat == 7) ? HIGH : LOW;
			value_r = (  beat % 2  || beat == 6) ? HIGH : LOW;
		}
		digitalWrite(LED_B, value_b);
		digitalWrite(LED_R, value_r);
		
	}
}
