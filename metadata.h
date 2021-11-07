//metadata.h
//struct for holding the metadata of the .wav
//Timothy Wellman

//inclusion protection
#ifndef METADATA_H
#define METADATE_H
//include statements
#include <iostream>

//struct definition
typedef struct Metadata {

	//attributes
	char chunk_id[4]; //This is supposed to be "RIFF". If not, we should throw an exception when trying the code
	
	int chunk_size; //This isn't really going to be useful except for exception throwing for safety
	
	char format[4]; //This is supposed to be "WAVE". If not, we need to throw an exception
	
	char subchunk1_id[4]; //Again, either "fmt " or exception
	
	int subchunk1_size; //We probably won't need this, but we expect it to be 16 
	
	short int audio_format; //Again, won't need this very much, but good for theoretically expanding this program later
	
	short int num_channels; //Very important for processor algorithms 
	
	int sample_rate; //need this for display and expansion
	
	int byte_rate; //need this for display and expansion
	
	short int block_align; //something we can use to throw an exception for if it isn't the expected value
	
	short int bits_per_sample; //we expect this to be either 8 or 16 and is used for the echo algorithm
	
	char subchunk2_id[4]; //nice and easy: "data" or bust
	
	short int subchunk2_size; //this one is used in determining the length of the array
	
	//operator overloads
	friend std::ostream& operator<<(std::ostream& out, const Metadata& metaOut); //For easy display of the metadata to be contained in the struct
	
	friend std::istream& operator>>(std::istream& in, Metadata& metaIn);//for easy scanning into from the file
}

//operator overloads for those tasty brownie points 


#endif
