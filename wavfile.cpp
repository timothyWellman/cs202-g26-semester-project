//wavfile.cpp
//body for wavfile object
//Timothy Wellman
//include statements
#include "wavfile.h"

//constructor
WavFile::WavFile(const Metadata& newMeta, size_t* audioStart){

	metadata = newMeta; //setting the metadata

	//initializing the buffer array and 
	audioBuffer = new size_t[metadata.subChunk2Size];
	for (int i = 0; i<metadata.subChunk2Size; i++){
		audioBuffer[i] = audioStart[i];//holy crap, this apparently works
	}

}