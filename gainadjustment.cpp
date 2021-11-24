//gainadjustment.cpp
//body file for GainAdjustment Class. mostly that function override
//Timothy Wellman
//inclusion statements
#include "gainadjustment.h"

void GainAdjustment::runProcessor(int* buffer, int bufferSize){

	for (int i = 0; i < bufferSize; i++){
		buffer[i] = (buffer[i]-mid)*scalingFactor + mid; //this alters the sample's distance from the midpoint by the scaling factor
		fixValue(buffer[i]);
	}
}

void GainAdjustment::processFile(WavFile& waveFile){
	runProcessor(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size);
}//unnecessary but to fix some issues with wavheader analysis in other processors