//wavfile.h
//header for WavFile object
//Timothy Wellman
//inclusion protection 
#ifndef WAV_FILE_H
#define WAV_FILE_H


//include statements
#include "metadata.h"
//#include "audiofile.h" 

class WavFile{
//i know we don't need to say private, but I like it to be explicit
	private:
	Metadata metadata;
	int* audioBuffer = NULL;//how to get/set this...

	public:
	//getters & setters
	Metadata getMetadata() const {return metadata;}
	void setMetadata(const Metadata& newMeta){metadata = newMeta;}//do we need this?

	int* getBuffer() const {return audioBuffer;}
	void setBuffer(int* newArray){audioBuffer = newArray;}
	
	//constructor
	WavFile() = default;

};

#endif