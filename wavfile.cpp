//wavfile.cpp
//body for wavfile object
//Timothy Wellman
//include statements
#include "wavfile.h"

//constructor
WavFile::WavFile(const WavHeader& newHeader, int* audioStart){

	wavheader = newHeader; //setting the wavheader

	//initializing the buffer array and 
	audioBuffer = new int[wavheader.subChunk2Size];
	for (int i = 0; i<wavheader.subChunk2Size; i++){
		audioBuffer[i] = audioStart[i];//holy crap, this apparently works
	}

}