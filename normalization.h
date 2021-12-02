//normalization.h
//header for normalization processor object
//Timothy Wellman
//inclusion protection
#ifndef NORMALIZATION_H
#define NORMALIZATION_H
//include statements
#include "audioprocessor.h"
#include "wavfile.h"

//class definition
class Normalization: public AudioProcessor {
	
	private:

	float factorDenominator;
	float factor;
	
	public:
	void runProcessor( float* buffer, int bufferSize) override;
	void processFile(WavFile& waveFile) override;

	//quality of life method
	float findLargestAmplitude( float* buffer, int bufferSize);

	//constructor
	Normalization();
	
};

#endif