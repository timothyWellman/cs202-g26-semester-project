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
	int max;
	int min;
	int mid;

	virtual void runProcessor(int* buffer, int bufferSize) = 0;
	void prepareBoundaries(WavFile& waveFile);
	virtual void processFile(WavFile& waveFile);
	void fixValue(int sample){
		sample = (sample > max) ? max : sample; //this makes sure the sample does not exit the range of the sound
		sample = (sample < min) ? min : sample; //likewise for the minimum values
	}

};

void AudioProcessor::prepareBoundaries(WavFile& waveFile){
	switch (waveFile.getWavHeader().bitsPerSample)
	{
	case 8:
		max = 255;
		min = 0;
		mid = 128;
		break;
	
	case 16:
		max = 32767;
		min = -32768;
		mid = 0;
		break;

	default:
		max = 255;
		min = 0;
		mid = 128;
		break;
	}
}
void AudioProcessor::processFile(WavFile& waveFile){
	prepareBoundaries(waveFile);
	runProcessor(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size);
}


#endif