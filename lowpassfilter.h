//lowpassfilter.h
//header for the low pass filter 
//Timothy Wellman
//inclusion protection
#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H
//include Statements
#include "echo.h"



class LowPassFilter: public Echo {

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

	/**
	 * @brief number of audio channels of wave file being processed
	 * 
	 */
	char channelNum = 1;

	bool willNormalize = 1;
	

	public:

	/**
	 * @brief Function that reads header data, processes the buffer array, and updates header data
	 * 
	 * @param waveFile the wavefile object whose buffer and header data are needed for editing/reading
	 */
	void processFile(WavFile& waveFile) override;

	/**
	 * @brief Run the mathematical algorithm applied to the audio
	 * 
	 * @param buffer: floating point array of audio values
	 * @param bufferSize: length of the audio array
	 */
	void runProcessor( float* buffer, int bufferSize) override;

	/**
	 * @brief Sets the delay to a value that reduces the threshold frequency to 50% volume
	 * 
	 * @param frequency 
	 * @param header 
	 */
	void calculateThresholdDelay(float frequency, const WavHeader& header);

	/**
	 * @brief Construct a new Low Pass Filter object
	 * 
	 * @param frequency the desired threshold frequency
	 */
	LowPassFilter(float frequency, bool normalize) : thresholdFrequency(frequency), willNormalize(normalize) {}

	LowPassFilter() = default;

};

#endif