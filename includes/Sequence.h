#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_
#include <stdint.h>
#include <string.h>

/**
 * @class Sequence
 * @brief Base class for sequences
 */
class Sequence {
public:
	unsigned long start;
	
	/**
	 * @brief The value at a given time
	 * @param time
	 */
	virtual int val(unsigned long time) = 0;
};

/**
 * @class ConstantSequence
 * @brief Sequence returning always the same value
 */
class ConstantSequence : public Sequence {
public:

	/**
	 * @brief
	 * @param value The value to return
	 */
	ConstantSequence(int value);
	
	int val(unsigned long time);
	
private:
	uint8_t _value;
};

/**
 * @class PatternSequence
 * @brief Sequence guided by a binary pattern
 */
class PatternSequence : public Sequence {
public:
	/**
	 * @brief 
	 * @param pattern Binary pattern
	 * @param beat_duration Time duration of a beat
	 */
	PatternSequence(const char* pattern, unsigned long beat_duration);

	int val(unsigned long time);
	
private:
	unsigned long _pattern;
	unsigned long _beat_duration;
	unsigned long _double_beats;
};

/**
 * @class BlinkSequence
 * @brief Blinking sequence
 */
class BlinkSequence : public Sequence {
public:
	/**
	 * @brief 
	 * @param duration On/Off duration
	 * @param transition Value in [0, 1[ interval to tune transition speed
	 */
	BlinkSequence(unsigned long duration, double transition);
	
	int val(unsigned long time);
	
private:
	unsigned long _duration;
	double _transition;
};


#endif // _SEQUENCE_H_