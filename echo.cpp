//echo.cpp
//body file for Echo AudioProcessor
//timothy Wellman
//include statements
#include"echo.h"


/*
void Echo::runProcessor(int* buffer, int bufferSize){
//need to move the buffer value reassignment to where the wav file can be accessed
	//this ended up being problematic to overload, with the passing by value of the pointer

	for (int i = 0; i < newBufferLength + delay; i++){
		/*
		buffer[i]-mid = amplitude 1
		buffer[i-delay]-mid = amplitude 2
		(buffer[i] - mid) + decay*(buffer[i-delay] - mid) = new amplitude
		(buffer[i] - mid) + decay*(buffer[i-delay] - mid) + mid = new value
		

		int amp1 = oldBuffer[i] - mid;//amplitude of the "call"
		if (i>delay*channelNum){

			int amp2 = (oldBuffer[i-delay*channelNum]-mid) * decay;//amplitude of the "back"
			amp1+=amp2;//smush 'em together

		}
		waveFile.getBuffer()[i] = amp1 + mid;//go back from amplitude to value
		
		fixValue(waveFile.getBuffer()[i]);
	}
	delete oldBuffer;
	
}
*/

/**
 * @brief runs the echo algorithm on the inputted file
 * 
 * @param waveFile: the file being modified
 */
void Echo::processFile(WavFile& waveFile){


	if(delay == 0){
		delay = delayInSeconds*waveFile.getWavHeader().sampleRate;
	}
	channelNum = waveFile.getWavHeader().numChannels;
	int* oldBuffer = waveFile.getBuffer();
	int newBufferLength = waveFile.getWavHeader().subChunk2Size + delay;
	waveFile.setBuffer(new int[newBufferLength]);

	for (int i = 0; i < newBufferLength + delay; i++){
		/*
		buffer[i]-mid = amplitude 1
		buffer[i-delay]-mid = amplitude 2
		(buffer[i] - mid) + decay*(buffer[i-delay] - mid) = new amplitude
		(buffer[i] - mid) + decay*(buffer[i-delay] - mid) + mid = new value
		*/

		int amp1 = oldBuffer[i] - mid;//amplitude of the "call"
		if (i>delay*channelNum){

			int amp2 = (oldBuffer[i-delay*channelNum]-mid) * decay;//amplitude of the "back"
			amp1+=amp2;//smush 'em together

		}
		waveFile.getBuffer()[i] = amp1 + mid;//go back from amplitude to value
		
		fixValue(waveFile.getBuffer()[i]);
	}
	delete oldBuffer;

	//runProcessor(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size + delay);
	WavHeader newLength = waveFile.getWavHeader();
	newLength.subChunk2Size += delay*newLength.numChannels*newLength.bitsPerSample/8;
	waveFile.setWavHeader(newLength);
}