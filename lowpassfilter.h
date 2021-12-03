//lowpassfilter.h
//header for the low pass filter 
//Timothy Wellman
//inclusion protection
#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H
//include Statements
#include "audioprocessor.h"
class LowPassFilter: public AudioProcessor {

	private:
	float thresholdFrequency;
	float* derivativeBuffer;


	public:
	void runProcessor(float* buffer, int bufferSize) override;
	void processFile(WavFile& waveFile) override;
	void calculateDerivative(float* buffer, int bufferSize);

};

#endif