//echo.h
//pretty barren header for echo processor object
//Timothy Wellman
//inclusion protection
#ifndef ECHO_H
#define ECHO_H
//include statements
#include "audioprocessor.h"
#include "wavfile.h"

//class definition
class Echo: public AudioProcessor {
	
	private:
	unsigned int delay = 0;
	float delayInSeconds = 0;
	float decay = 0.0;
	short int channelNum = 1;
	
	
	public:
	void runProcessor(unsigned char* buffer, int bufferSize) override;
	void processFile(WavFile& waveFile) override;

	//constructors are the solution here
	Echo(unsigned int newDelay, float newDecay){delay = newDelay; decay = std::abs(newDecay);}
	Echo(float delaySeconds, float newDecay){delayInSeconds = delaySeconds; decay = std::abs(newDecay);}
};

#endif