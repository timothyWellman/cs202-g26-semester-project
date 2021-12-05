//compressor.cpp
//body for the compressor object
//timothy wellman
//include statement
#include"compressor.h"

void Compressor::processFile(WavFile& waveFile) {

	runProcessor(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size);
	if(normalizing){
		Normalization::processFile(waveFile);
	}
}

void Compressor::runProcessor(float* buffer, int bufferSize){

	for (int i = 0; i < bufferSize; i++){
		//gonna take this case by case
		buffer[i] = (buffer[i] > threshold) ? (buffer[i]-threshold)*dampeningFactor + threshold : buffer[i];
		buffer[i] = (buffer[i] < -threshold) ? (buffer[i] + threshold)*dampeningFactor - threshold : buffer[i];
	}
}
