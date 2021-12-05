//gainadjustment.h
//header for echo processor object
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

	/**
	 * @brief amount the audio will be scaled by
	 * 
	 */
	float scalingFactor;
	
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
//constructors

/**
 * @brief Construct a new Gain Adjustment object
 * 
 * @param newScale amount the audio will be scaled by
 */
	GainAdjustment(float newScale){scalingFactor = newScale;}
};

#endif