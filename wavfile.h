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
	float* audioBuffer = NULL;
	short* sixteenBitBuffer = NULL;
	char* eightBitBuffer = NULL;
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
	void setWavHeader(const WavHeader& newHeader){wavheader = newHeader;}

	/**
	 * @brief Get the address of the array of audio samples
	 * 
	 * @return int array pointer
	 */
	float* getBuffer() const {return audioBuffer;}

	/**
	 * @brief Set the buffer to a new array
	 * 
	 * @param newArray 
	 */
	void setBuffer(float* newArray){audioBuffer = newArray;}

	/**
	 * @brief Set the buffer array to be a series of floating values from a 16 or higher bit depth 
	 * 
	 * @param newArray: an array of integer audio values
	 */
	void setBuffer(short* newArray);

	/**
	 * @brief Set the Buffer array of floating point integers from 8 bit char audio values
	 * 
	 * @param newArray 
	 */
	void setBuffer(char* newArray);

	//export methods

	void exportBuffer(char* target);
	void exportBuffer(short* target);
	


	//constructors
	WavFile() = default;

	/**
	 * @brief Construct a new Wav File object from a header and a pre-conpacted float buffer
	 * 
	 * @param newHeader 
	 * @param audioStart 
	 */
	WavFile(const WavHeader& newHeader, float* audioStart);

	/**
	 * @brief Construct a new Wav File object from a header and an 8 bit buffer
	 * 
	 * @param newHeader 
	 * @param audioStart 
	 */
	WavFile(const WavHeader& newHeader, char* audioStart);
	
	/**
	 * @brief Construct a new Wav File object from a header and a 16 bit buffer
	 * 
	 * @param newHeader 
	 * @param audioStart: converted into floating points
	 */
	WavFile(const WavHeader& newHeader, short* audioStart);
	

};

#endif