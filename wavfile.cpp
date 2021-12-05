//wavfile.cpp
//body for wavfile object
//Timothy Wellman
//include statements
#include "wavfile.h"

//constructor
WavFile::WavFile(const WavHeader& newHeader,  float* audioStart){

	wavheader = newHeader; //setting the wavheader

	//initializing the buffer array and 
	audioBuffer = new float[wavheader.subChunk2Size];
	for (int i = 0; i<wavheader.subChunk2Size; i++){
		audioBuffer[i] = audioStart[i];//holy crap, this apparently works
	}

}

//constructor
WavFile::WavFile(const WavHeader& newHeader,  char* audioStart){

	wavheader = newHeader; //setting the wavheader

	setBuffer(audioStart);	
}

//constructor
WavFile::WavFile(const WavHeader& newHeader,  float* audioStart){

	wavheader = newHeader; //setting the wavheader

	setBuffer(audioStart);
	
}


void WavFile::setBuffer(char* newArray){
	//initializing the buffer array and 
	audioBuffer = new float[wavheader.subChunk2Size];
	for (int i = 0; i<wavheader.subChunk2Size; i++){
		audioBuffer[i] = (newArray[i] - 128)/128;
	}
}

void WavFile::setBuffer(int* newArray){
	//initializing the buffer array and 
	audioBuffer = new float[wavheader.subChunk2Size];
	for (int i = 0; i<wavheader.subChunk2Size; i++){
		audioBuffer[i] = (newArray[i])/32768;
	}
}


void WavFile::exportBuffer(char* target){
	wavheader.bitsPerSample = 8;

	target = new char[wavheader.subChunk2Size];
	for(int i = 0; i < wavheader.subChunk2Size; i++){
		target[i] = audioBuffer[i]*128 + 128;
	}	
	return;
	
}

void WavFile::exportBuffer(short* target){
	wavheader.bitsPerSample = 16;
	target = new short[wavheader.subChunk2Size];
	for(int i = 0; i < wavheader.subChunk2Size; i++){
		target[i] = (audioBuffer[i]*32767);
	}
	return;
}