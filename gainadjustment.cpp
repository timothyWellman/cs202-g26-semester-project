//gainadjustment.cpp
//body file for GainAdjustment Class. mostly that function override
//Timothy Wellman
//inclusion statements
#include "gainadjustment.h"

void GainAdjustment::runProcessor(unsigned char* buffer, int bufferSize){

	for (int i = 0; i < bufferSize; i++){
		buffer[i] = (buffer[i]-mid)*scalingFactor + mid; //this alters the sample's distance from the midpoint by the scaling factor
		buffer[i] = (buffer[i] > max) ? max : buffer[i]; //this makes sure the sample does not exit the range of the sound
		buffer[i] = (buffer[i] < min) ? min : buffer[i]; //likewise for the minimum values
	}
}