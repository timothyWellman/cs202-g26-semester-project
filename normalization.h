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

	/**
	 * @brief the denominator of the factor: the largest amplitude
	 * 
	 */
	float factorDenominator;

	/**
	 * @brief the factor to scale by: 1/factorDenominator
	 * 
	 */
	float factor;
	
	public:

	/**
	 * @brief Run the mathematical algorithm applied to the audio
	 * 
	 * @param buffer: floating point array of audio values
	 * @param bufferSize: length of the audio array
	 */
	virtual void runProcessor( float* buffer, int bufferSize) override;

	/**
	 * @brief Function that reads header data, processes the buffer array, and updates header data
	 * 
	 * @param waveFile the wavefile object whose buffer and header data are needed for editing/reading
	 */
	virtual void processFile(WavFile& waveFile) override;

	//quality of life method
	/**
	 * @brief scans an array for the farthest value from 0
	 * 
	 * @param buffer array being scanned
	 * @param bufferSize length of array
	 * @return value of the highest/lowest audio sample
	 */
	float findLargestAmplitude( float* buffer, int bufferSize);

	//constructor

	/**
	 * @brief Construct a new Normalization object
	 * 
	 */
	Normalization();
	
};

#endif