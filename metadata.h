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
	
	char subChunk1Id[4]; //Again, either "fmt " or exception
	
	int subChunk1Size; //We probably won't need this, but we expect it to be 16 
	
	short int audioFormat; //Again, won't need this very much, but good for theoretically expanding this program later
	
	short int numChannels; //Very important for processor algorithms 
	
	int sampleRate; //need this for display and expansion 
	
	int byteRate; //need this for display and expansion
	
	short int blockAlign; //something we can use to throw an exception for if it isn't the expected value
	
	short int bitsPerSample; //we expect this to be either 8 or 16 
	
	char subChunk2Id[4]; //nice and easy: "data" or bust
	
	short int subChunk2Size; //this one is used in determining the length of the array
	
	//operator overloads
	friend std::ostream& operator<<(std::ostream& out, const Metadata& metaOut); //For easy display of the metadata to be contained in the struct
	
	friend std::istream& operator>>(std::istream& in, Metadata& metaIn);//for easy scanning into from the file

	Metadata& operator=(const Metadata& rhs); //this is mostly for ease of making the wavefile 
};

//operator overloads for those tasty brownie points 

#endif
