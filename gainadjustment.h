//gainadjustment.h
//pretty barren header for echo processor object
//Timothy Wellman
//inclusion protection
#ifndef ECHO_H
#define ECHO_H
//include statements
#include "audioprocessor.h"
#include "wavfile.h"

//class definition
class GainAdjustment: public AudioProcessor {
	
	private:
	float scalingFactor;
	
	public:
	void runProcessor() override;
//constructors
	GainAdjustment(const WavFile& original, float newScale);
};

#endif