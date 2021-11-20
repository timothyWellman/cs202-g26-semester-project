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
	unsigned int delay;
	float decay;
	
	
	public:
	void runProcessor(unsigned char* buffer, int bufferSize) override;
	//constructors are the solution here
	Echo(unsigned int newDelay, float newDecay);
};

#endif