//compressor.h
//header file for the challenge processor object: Compressor
//Timothy Wellman
//inclusion protection
#ifndef COMPRESSOR_H
#define COMPRESSOR_H
//include statements
#include "audioprocessor.h"
#include "normalization.h"

class Compressor: public AudioProcessor, public Normalization {

	private: 
	float dampeningFactor = 0.5;
	float threshold = 0.85;
	bool normalizing = 1;

	public:
	void runProcessor(float* buffer, int bufferSize) override;
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
	Compressor(float dampener, float newThreshold, bool willNormalize) : dampeningFactor(dampener), threshold(newThreshold), normalizing(willNormalize) {}
	

};



#endif