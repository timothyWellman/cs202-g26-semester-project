//echo.cpp
//body file for Echo AudioProcessor
//timothy Wellman
//include statements
#include"echo.h"


void Echo::processFile(WavFile& waveFile){


	if(delayInSeconds != 0.0f){
		delay = delayInSeconds*waveFile.getWavHeader().sampleRate;
	}
	channelNum = waveFile.getWavHeader().numChannels;
	float* oldBuffer = waveFile.getBuffer();
	int newBufferLength = waveFile.getWavHeader().subChunk2Size + delay;
	waveFile.setBuffer(new float[newBufferLength]);

	for (int i = 0; i < newBufferLength + delay; i++){
		/*
		buffer[i]  = amplitude 1
		buffer[i-delay]  = amplitude 2
		(buffer[i]) + decay*(buffer[i-delay]) = new amplitude
		(buffer[i]) + decay*(buffer[i-delay])   = new value
		*/

		int amp1 = oldBuffer[i]  ;//amplitude of the "call"
		if (i>delay*channelNum){

			int amp2 = (waveFile.getBuffer()[i-delay*channelNum]) * decay;//amplitude of the "back"
			amp1+=amp2;//smush 'em together

		}
		waveFile.getBuffer()[i] = amp1;//go back from amplitude to value
		
	}
	delete oldBuffer;

	//runProcessor(waveFile.getBuffer(), waveFile.getWavHeader().subChunk2Size + delay);
	WavHeader newLength = waveFile.getWavHeader();
	newLength.subChunk2Size += delay*newLength.numChannels*newLength.bitsPerSample/8;
	waveFile.setWavHeader(newLength);

	Normalization::processFile(waveFile);

}