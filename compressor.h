//compressor.h
//header file for the challenge processor object: Compressor
//Timothy Wellman
//inclusion protection
#ifndef COMPRESSOR_H
#define COMPRESSOR_H
//include statements
#include "normalization.h"

class Compressor: public Normalization {

	private: 

	/**
	 * @brief amount audio samples are pulled toward the threshold
	 * 
	 */
	float dampeningFactor = 0.5;

	/**
	 * @brief the amplitude at which compression begins to occur
	 * 
	 */
	float threshold = 0.85;

	/**
	 * @brief Whether the compressor also normalizes
	 * 
	 */
	bool normalizing = 1;

	public:

	/**
	 * @brief Run the mathematical algorithm applied to the audio
	 * 
	 * @param buffer: floating point array of audio values
	 * @param bufferSize: length of the audio array
	 */
	void runProcessor(float* buffer, int bufferSize) override;

	/**
	 * @brief Function that reads header data, processes the buffer array, and updates header data
	 * 
	 * @param waveFile the wavefile object whose buffer and header data are needed for editing/reading
	 */
	void processFile(WavFile& waveFile) override;

	/**
	 * @brief Construct a new Compressor object. This assumes calculations have been pre-made to fit algorithms
	 * 
	 * @param dampener: the ratio by which the audio above a certain level will be dropped toward the (0<dampener<1)
	 * 
	 * @param newThreshold: the maximum volume at which no noise reduction will occur
	 * 
	 * @param willNormalize: whether or not, after compressing, the audio will be brought back up with a normalization algorithm
	 */
	Compressor(float newThreshold, bool willNormalize) : threshold(newThreshold), normalizing(willNormalize) {}
	
	Compressor() = default;
};



#endif