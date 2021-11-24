//audioprocessor.h
//header for the abstract parent class
//Timothy Wellman
//inclusion protection
#ifndef AUDIO_PROCESSOR_H
#define AUDIO_PROCESSOR_H
//inclusion statements
#include"wavheader.h"
#include"wavfile.h"
#include<cmath>
//#include <cmath> //for those lovely math functions
//class definition
class AudioProcessor {

	//these are magic numbers that should be determined when reading the file. for now, they'll do going here
	/*okay, as I understand it:
	max = 2^bitsPerSample - 1
	min = 0
	mid = 0.5(max+min)+1

	to make that dynamic, it may be better in the future have the audioprocessor access the file object, not the buffer itself

	perhaps overload the virtual runProcessor function for secondary use to manipulate & learn from the header. may be inevetible
		if so, then the creation/assignment of these values should be done at construction
		also the datatype of audio samples is frustrating
*/
	
	public:
	const int max = 255;
	const int min = 0;
	const int mid = 128;

	virtual void runProcessor(int* buffer, int bufferSize) = 0;
	virtual void processFile(WavFile& waveFile) = 0;
	void fixValue(int sample){
		sample = (sample > max) ? max : sample; //this makes sure the sample does not exit the range of the sound
		sample = (sample < min) ? min : sample; //likewise for the minimum values
	}

};


#endif