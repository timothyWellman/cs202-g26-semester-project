//audioprocessor.h
//header for the abstract parent class
//Timothy Wellman
//inclusion protection
#ifndef AUDIO_PROCESSOR_H
#define AUDIO_PROCESSOR_H
//inclusion statements
#include"wavheader.h"
#include"wavfile.h"
#include<cmath>
//#include <cmath> //for those lovely math functions
//class definition
class AudioProcessor {
	
	public:

	/**
	 * @brief Run the mathematical algorithm applied to the audio
	 * 
	 * @param buffer: floating point array of audio values
	 * @param bufferSize: length of the audio array
	 */
	virtual void runProcessor(float* buffer, int bufferSize) = 0;
	
		/**
	 * @brief Function that reads header data, processes the buffer array, and updates header data
	 * 
	 * @param waveFile the wavefile object whose buffer and header data are needed for editing/reading
	 */
	virtual void processFile(WavFile& waveFile);
	
	
	void fixValue(int sample){
		sample = (sample > 1) ? 1 : sample; //this makes sure the sample does not exit the range of the sound
		sample = (sample < -1) ? -1 : sample; //likewise for the minimum values
	}

};

void AudioProcessor::processFile(WavFile& waveFile){
	runProcessor(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size);
}


#endif