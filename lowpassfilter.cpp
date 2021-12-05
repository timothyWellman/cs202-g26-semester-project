//lowpassfilter.cpp
//body file for filter processor
//Timothy Wellman
//include statements
#include"lowpassfilter.h"

void LowPassFilter::calculateThresholdDelay(float frequency, const WavHeader& header){
	channelNum = header.numChannels;
	//we need to use the function in terms of phase shift to find it. the target is to have the threshold frequency occur at 1/2 the way from 0 to samplerate/(2 delay) 
	thresholdDelay = header.sampleRate/(2*2*frequency*channelNum);
	return;
}

void LowPassFilter::runProcessor(float* buffer, int bufferSize){
	
	for(int i = 0; i , bufferSize; i++){
		if (i>thresholdDelay*channelNum)
		{
			buffer[i]+=buffer[i-thresholdDelay*channelNum];
		}
	}
	
}

void LowPassFilter::processFile(WavFile& waveFile){
	calculateThresholdDelay(thresholdFrequency, waveFile.getWavHeader());
	runProcessor(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size);
	Normalization::processFile(waveFile);
}