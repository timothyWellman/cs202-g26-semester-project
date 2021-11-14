//audiofile.h
//header for abstract class for wavfile to inherit from. May suggest additional refactoring for metadata struct
//timothy wellman
//inclusion protection

//include statements
#include "metadata.h"

class AudioFile {
//i know we don't need to make this private, but I like it to be explicit
	private:

	public:
	size_t* audioBuffer; //public until the an alpha build is made and access can be tested
	virtual void junkMethod() = 0;//only here until a better pure virtual method is put here, otherwise this is here to make the class abstract


};