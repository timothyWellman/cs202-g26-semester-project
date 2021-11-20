//audioprocessor.h
//header for the abstract parent class
//Timothy Wellman
//inclusion protection
#ifndef AUDIO_PROCESSOR_H
#define AUDIO_PROCESSOR_H
//inclusion statements
#include"metadata.h"
#include <cmath> //for those lovely math functions
//class definition
class AudioProcessor {

	//these are magic numbers that should be determined when reading the file. for now, they'll do going here
	/*okay, as I understand it:
	max = 2^bitsPerSample - 1
	min = 0
	mid = 0.5(max+min)+1

	to make that dynamic, it may be better in the future have the audioprocessor access the file object, not the buffer itself

	perhaps overload the virtual runProcessor function for secondary use to manipulate & learn from the metadata. may be inevetible
*/
	
	public:
	const unsigned char max = 255;
	const unsigned char min = 0;
	const unsigned char mid = 128;

	virtual void runProcessor(unsigned char* buffer, int bufferSize) = 0;

};


#endif