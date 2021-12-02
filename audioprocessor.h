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

	virtual void runProcessor(float* buffer, int bufferSize) = 0;
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