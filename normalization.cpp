//normalization.cpp
//where the meat of the normalizing algorithm goes
//Timothy Wellman
//include statements
#include "normalization.h"

int Normalization::findLargestAmplitude(int* buffer, int bufferSize){
	int currentLargestest = 0;

	for (int i = 0; i < bufferSize; i++)
	{
		if (std::abs(buffer[i]-mid)>std::abs(currentLargestest))
		{
			currentLargestest = buffer[i]-mid;
		}
		
	}
	
	return std::abs(currentLargestest);
}

void Normalization::processFile(WavFile& waveFile){

	factorNumerator = max - mid;
	factorDenominator = findLargestAmplitude(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size);
	factor = factorNumerator/factorDenominator;
	runProcessor(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size);

}

void Normalization::runProcessor(int* buffer, int bufferSize){

	for(int i = 0; i < bufferSize; i++){
		int amplitude = buffer[i] - mid;
		amplitude *= factor;
		buffer[i] = amplitude + mid;
	}
}