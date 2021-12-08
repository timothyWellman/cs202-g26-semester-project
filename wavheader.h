//wavheader.h
//struct for holding the wavheader of the .wav
//Timothy Wellman

//inclusion protection
#ifndef WAVHEADER_H
#define WAVHEADER_H
//include statements
#include <iostream>
#include <cmath>

//struct definition
typedef struct WavHeader {

	//attributes

	
	/**
	 * @brief This is supposed to be "RIFF". If not, we should throw an exception when trying the code

	 * 
	 */
	char chunkId[4]; 
	
	/**
	 * @brief This is the size of the file -8 or subChunk2Size + 44 - 8
	 * 
	 */
	int32_t chunkSize; 	
	
	/**
	 * @brief This is supposed to be "WAVE". If not, we need to throw an exception
	 * 
	 */
	char format[4]; 
	
	/**
	 * @brief Either "fmt " or exception
	 * 
	 */
	char subChunk1Id[4]; 
	
	/**
	 * @brief Expected to be 16, else an exception is needed
	 * 
	 */
	int32_t subChunk1Size; 

	/**
	 * @brief We expect this to be 1, unless it is compressed. Not sure how to deal with that yet.
	 * 
	 */
	short audioFormat; 
	
	/**
	 * @brief Number of Channels of audio: important for processors like echo
	 * 
	 */
	short numChannels; 
	
	/**
	 * @brief The number of samples taken per second. 
	 * 
	 */
	int32_t sampleRate; //need this for converting from samples to seconds
	
	/**
	 * @brief  a confirmable function of several values for exception throwing
	 * 
	 */
	int32_t byteRate; 
	
	/**
	 * @brief NumChannels * BitsPerSample/8
	 * 
	 */
	short blockAlign; 
	
	/**
	 * @brief Determines possible values of the samples/bit depth
	 * 
	 */
	short bitsPerSample; //we expect this to be either 8 or 16. to be used to determine possible sample values

	/**
	 * @brief Really just has to be "data" or an exception is needed.
	 * 
	 */
	char subChunk2Id[4]; //nice and easy: "data" or bust
	
	/**
	 * @brief The length of the buffer array
	 * 
	 */
	short subChunk2Size; //this one is used in determining the length of the array
	
	//exception checker

	/**
	 * @brief Function used to check the header upon first getting the values.
	 * 
	 */
	void checkHeader();
	//operator overloads

	/**
	 * @brief Optional use of the output stream to write to the file. not needed but fun to write
	 * 
	 * @param out 
	 * @param metaOut 
	 * @return std::ostream& 
	 */
	friend std::ostream& operator<<(std::ostream& out, const WavHeader& metaOut); //For easy display of the wavheader to be contained in the struct
	
	/**
	 * @brief Similar to the ostream overload, this isn't needed, but should work to read in from a file
	 * 
	 * @param in 
	 * @param metaIn 
	 * @return std::istream& 
	 */
	friend std::istream& operator>>(std::istream& in, WavHeader& metaIn);//for easy scanning into from the file

	WavHeader& operator=(const WavHeader& rhs); //this is mostly for ease of making the wavefile 
}WavHeader;


#endif
