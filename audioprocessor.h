//audioprocessor.h
//header for the abstract parent class
//Timothy Wellman
//inclusion protection
#ifndef AUDIO_PROCESSOR_H
#define AUDIO_PROCESSOR_H
//inclusion statements

//class definition
class AudioProcessor {

	private:
	//don't know what I need here, yet
	size_t* originalBuffer; //so we can access the data by reference. no need to edit this stuff
	Metadata originalMetadata;
	public:
	virtual void runProcessor() = 0;//should this return a pointer to a dynamically created audiofile? so the file can be passed into the file manager?

};


#endif