//wavfile.h
//header for WavFile object
//Timothy Wellman
//inclusion protection 
#ifndef WAV_FILE_H
#define WAV_FILE_H


//include statements
#include "metadata.h"
class WavFile  {
//i know we don't need to say private, but I like it to be explicit
	private:
	Metadata metadata;
	
	public:
	char* audioBuffer;//I figure this should be private, but I'm gonna leave it here until we know filling the array works normally before trying to tighten security, make sure a door can close before fitting it for a lock
	Metadata getMetadata(){return metadata;}
	void setMetadata(const Metadata& newMeta){metadata = newMeta;}
	//char* getBuffer(){return audioBuffer;}
	//void setBuffer();     *do we need this?*
	//what other functions do we need?
};

#endif