//normalization.h
//header for normalization processor object
//Timothy Wellman
//inclusion protection
#ifndef NORMALIZATION_H
#define NORMALIZATION_H
//include statements
#include "audioprocessor.h"
#include "wavfile.h"

//class definition
class Normalization: public AudioProcessor {
	
	private:
	//nothing here yet
	public:
	void runProcessor() override;
	//constructor
	Normalization(const WavFile& original);
	
};

#endif