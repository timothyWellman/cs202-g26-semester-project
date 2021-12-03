//lowpassfilter.h
//header for the low pass filter 
//Timothy Wellman
//inclusion protection
#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H
//include Statements
#include "audioprocessor.h"
#include "normalization.h"



class LowPassFilter: public AudioProcessor, public Normalization {

	private:
	/**
	 * @brief The frequency in hertz of the cutoff point
	 * 
	 */
	float thresholdFrequency = 500;

	/**
	 * @brief the number of samples that makes a 180 degree phase shift in the threshold frequency
	 * 
	 */
	int thresholdDelay;

	char channelNum = 1;
	

	public:
	void processFile(WavFile& waveFile) override;
	void runProcessor( float* buffer, int bufferSize) override;
	void calculateThresholdDelay(float frequency, const WavHeader& header);
	void filterFrequency(int currentDelay, int finalDelay, float* buffer, int bufferSize); //recursively called method that runs through each value to get 
	LowPassFilter(float frequency) : thresholdFrequency(frequency){}

};

#endif