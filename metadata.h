//metadata.h
//struct for holding the metadata of the .wav
//Timothy Wellman

//inclusion protection
#ifndef METADATA_H
#define METADATA_H
//include statements
#include <iostream>

//struct definition
typedef struct Metadata {

	//attributes
	char chunkId[4]; //This is supposed to be "RIFF". If not, we should throw an exception when trying the code
	
	int chunkSize; //This isn't really going to be useful except for exception throwing for safety
	
	char format[4]; //This is supposed to be "WAVE". If not, we need to throw an exception
	
	char subchunk1Id[4]; //Again, either "fmt " or exception
	
	int subchunk1Size; //We probably won't need this, but we expect it to be 16 
	
	short int audioFormat; //Again, won't need this very much, but good for theoretically expanding this program later
	
	short int numChannels; //Very important for processor algorithms 
	
	int sampleRate; //need this for display and expansion
	
	int byteRate; //need this for display and expansion
	
	short int blockAlign; //something we can use to throw an exception for if it isn't the expected value
	
	short int bitsPerSample; //we expect this to be either 8 or 16 and is used for the echo algorithm
	
	char subchunk2Id[4]; //nice and easy: "data" or bust
	
	short int subchunk2Size; //this one is used in determining the length of the array
	
	//operator overloads
	friend std::ostream& operator<<(std::ostream& out, const Metadata& metaOut); //For easy display of the metadata to be contained in the struct
	
	friend std::istream& operator>>(std::istream& in, Metadata& metaIn);//for easy scanning into from the file

	Metadata& operator=(const Metadata& rhs); //this is mostly for ease of making the wavefile 
};

//operator overloads for those tasty brownie points 

//stream output operator for displaying the data formatted for console
std::ostream& operator<<(std::ostream& out, const Metadata& metaOut){

	out << "Sample Rate: " << metaOut.sampleRate << std::endl;
	out << "Bits per Sample: " << metaOut.bitsPerSample << std::endl;
	out << "Channel number: ";
	if (metaOut.numChannels == 1){
		out << "Mono";
	}else if (metaOut.numChannels == 2) {
		out << "Stereo";
	}
	out << std::endl;
	/*
	Sample Rate: 8800
	Bits per Sample: 8
	Channel number: Mono
	*/
	return out;
}

//stream input operator. the main idea here is using specific datatypes to control how many bytes are scanned in
std::istream& operator>>(std::istream& in, Metadata& metaIn){

//thus far, this code will only work if there are 0 problems. exceptions to be added soon

	for (int i = 0; i<4; i++){in >> metaIn.chunkId[i]; }
	in >> metaIn.chunkSize;
	for (int i = 0; i<4; i++){in >> metaIn.format[i]; }
	for (int i = 0; i<4; i++){in >> metaIn.subchunk1Id[i]; }
	in >> metaIn.subchunk1Size;
	in >> metaIn.audioFormat;
	in >> metaIn.numChannels;
	in >> metaIn.sampleRate;
	in >> metaIn.byteRate;
	in >> metaIn.blockAlign;
	in >> metaIn.bitsPerSample;
	for (int i = 0; i<4; i++){in >> metaIn.subchunk2Id[i]; }
	in >> metaIn.subchunk2Size;

	return in;
}

Metadata& Metadata::operator=(const Metadata& rhs){
	if (this == &rhs) return *this; //checking for self assignment

	//assign them values
	for (int i = 0; i<4; i++){chunkId[i] >> rhs.chunkId[i]; }
	chunkSize = rhs.chunkSize;
	for (int i = 0; i<4; i++){format[i] = rhs.format[i]; }
	for (int i = 0; i<4; i++){subchunk1Id[i] = rhs.subchunk1Id[i]; }
	subchunk1Size = rhs.subchunk1Size;
	audioFormat = rhs.audioFormat;
	numChannels = rhs.numChannels;
	sampleRate = rhs.sampleRate;
	byteRate = rhs.byteRate;
	blockAlign = rhs.blockAlign;
	bitsPerSample = rhs.bitsPerSample;
	for (int i = 0; i<4; i++){subchunk2Id[i] = rhs.subchunk2Id[i]; }
	subchunk2Size = rhs.subchunk2Size;

	return *this;
}


#endif
