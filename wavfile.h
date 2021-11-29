//wavfile.h
//header for WavFile object
//Timothy Wellman
//inclusion protection 
#ifndef WAV_FILE_H
#define WAV_FILE_H


//include statements
#include "wavheader.h"
//#include "audiofile.h" 

/**
 * @brief class to store .wav file, containing wavheader and a pointer to dynamically created array of audio samples
 * 
 */
class WavFile{
//i know we don't need to say private, but I like it to be explicit
	private:
	WavHeader wavheader;
	int* audioBuffer = NULL;//how to get/set this...

	public:
	//getters & setters
	
	/**
	 * @brief Get the WavHeader data struct
	 * 
	 * @return WavHeader of .wav file
	 */
	WavHeader getWavHeader() const {return wavheader;}

	/**
	 * @brief used to reset the wavheader after editing
	 * 
	 * @param newHeader
	 */
	void setWavHeader(const WavHeader& newHeader){wavheader = newHeader;}//do we need this?

	/**
	 * @brief Get the address of the array of audio samples
	 * 
	 * @return int array pointer
	 */
	int* getBuffer() const {return audioBuffer;}

	/**
	 * @brief Set the buffer to a new array
	 * 
	 * @param newArray 
	 */
	void setBuffer(int* newArray){audioBuffer = newArray;}
	
	//constructor
	WavFile() = default;

	WavFile(const WavHeader& newHeader, int* audioStart);
	

};

#endif