//echo.h
//pretty barren header for echo processor object
//Timothy Wellman
//inclusion protection
#ifndef ECHO_H
#define ECHO_H
//include statements
#include "normalization.h"
#include "wavfile.h"

//class definition 
class Echo: public Normalization {
	
	private:

	/**
	 * @brief the number of samples per channel between the call and the callback
	 * 
	 */
	unsigned int delay = 0;

	/**
	 * @brief time in seconds between call and callback
	 * 
	 */
	float delayInSeconds = 0;

	/**
	 * @brief how much the callback is decreased by. expected values: [0,1]
	 * 
	 */
	float decay = 0.0;

	/**
	 * @brief number of channels of the audio array being processed
	 * 
	 */
	short int channelNum = 1;
	
	
	public:

	/**
	 * @brief Run the mathematical algorithm applied to the audio: unused in this processor
	 * 
	 * @param buffer: floating point array of audio values
	 * @param bufferSize: length of the audio array
	 */
	
	virtual void runProcessor( float* buffer, int bufferSize) override{}

	/**
	 * @brief Function that reads header data, processes the buffer array, and updates header data to account for echo delay
	 * 
	 * @param waveFile the wavefile object whose buffer and header data are needed for editing/reading
	 */
	virtual void processFile(WavFile& waveFile) override;

	//constructors are the solution here

	/**
	 * @brief Construct a new Echo object: not expected to be used
	 * 
	 * @param newDelay number of samples per channel the delay would take
	 * @param newDecay how much the callback audio is decreased
	 */
	Echo(unsigned int newDelay, float newDecay){delay = newDelay; decay = std::abs(newDecay);}
	
	/**
	 * @brief Construct a new Echo object: the preferable one
	 * 
	 * @param newDelay how many seconds before the callback audio starts
	 * @param newDecay how much the callback audio is decreased
	 */
	Echo(float delaySeconds, float newDecay){delayInSeconds = delaySeconds; decay = std::abs(newDecay);}

	Echo() = default;
};

#endif