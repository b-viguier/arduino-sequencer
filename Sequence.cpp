#include "Sequence.h"
#include <Arduino.h>
#include <bitset>


ConstantSequence::ConstantSequence(int value) : _value(value) {
}
	
int ConstantSequence::val(unsigned long time) {
	return _value;
}

PatternSequence::PatternSequence(const char* pattern, unsigned long beat_duration) 
: _pattern(std::bitset<32>(std::string(pattern)).to_ulong())
, _beat_duration(beat_duration)
, _double_beats(2*strlen(pattern))
{
}
	
int PatternSequence::val(unsigned long time) {
	const unsigned long sub_beat = 
		((time - start) / _beat_duration ) % _double_beats;
	
	if( sub_beat % 2 ) {
		return LOW;
	}
		
	const unsigned long beat_mask = 1 << ((_double_beats - sub_beat-1) / 2);
	
	return _pattern & beat_mask ? HIGH : LOW;
}

BlinkSequence::BlinkSequence(unsigned long duration, double transition)
: _duration(duration)
, _transition(transition) 
{
}
	
int BlinkSequence::val(unsigned long time) {
	const double signal_raw = sin( (time-start) * PI / _duration);
	const double signal_max = std::max(- _transition, signal_raw);
	const double signal_min = std::min( _transition, signal_max);
	return (0.5 + signal_min / (2. * _transition))*255;
}
