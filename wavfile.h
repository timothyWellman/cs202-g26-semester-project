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
	unsigned char* audioBuffer = NULL;//how to get/set this...

	public:
	Metadata getMetadata(){return metadata;}
	void setMetadata(const Metadata& newMeta){metadata = newMeta;}
	
	
	//cheeky constructor
	WavFile() = default;


	//char* getBuffer(){return audioBuffer;}
	//void setBuffer();     *do we need this?*
};

#endif