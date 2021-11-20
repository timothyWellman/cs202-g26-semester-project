//echo.cpp
//body file for Echo AudioProcessor
//timothy Wellman
//include statements
#include"echo.h"

void Echo::runProcessor(unsigned char* buffer, int bufferSize){

	for (int i = 0; i < bufferSize + delay; i++){
		/*
		buffer[i]-mid = amplitude 1
		buffer[i-delay]-mid = amplitude 2
		(buffer[i] - mid) + decay*(buffer[i-delay] - mid) = new amplitude
		(buffer[i] - mid) + decay*(buffer[i-delay] - mid) + mid = new value
		*/
		int amp1 = buffer[i] - mid;//amplitude of the "call"
		if (i>delay){

			int amp2 = (buffer[i-delay]-mid) * decay;//amplitude of the "back"
			amp1+=amp2;//smush 'em together

		}
		buffer[i] = amp1 + mid;//go back from amplitude to value
		
		fixValue(buffer[i]);
	}
} //should I change the name of this method?

void Echo::processFile(WavFile& waveFile){

	if(delay == 0){
		delay = delayInSeconds*waveFile.getMetadata().sampleRate;
	}
	runProcessor(waveFile.getBuffer(), waveFile.getMetadata().subChunk2Size);
	Metadata newLength = waveFile.getMetadata();
	newLength.subChunk2Size += delay*newLength.numChannels*newLength.bitsPerSample/8;
	waveFile.setMetadata(newLength);
}