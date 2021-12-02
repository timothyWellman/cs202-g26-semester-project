//normalization.cpp
//where the meat of the normalizing algorithm goes
//Timothy Wellman
//include statements
#include "normalization.h"

float Normalization::findLargestAmplitude( float* buffer, int bufferSize){
	float currentLargestest = 0;

	for (int i = 0; i < bufferSize; i++)
	{
		if (std::abs(buffer[i])>std::abs(currentLargestest))
		{
			currentLargestest = buffer[i];
		}
		
	}
	
	return std::abs(currentLargestest);
}

void Normalization::processFile(WavFile& waveFile){

	factorDenominator = findLargestAmplitude(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size);
	factor = 1/factorDenominator;
	runProcessor(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size);

}

void Normalization::runProcessor( float* buffer, int bufferSize){

	for(int i = 0; i < bufferSize; i++){
		buffer[i] *= factor;
	}
}