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
	
	return currentLargestest;
}

