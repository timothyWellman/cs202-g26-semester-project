//wavheader.cpp
//Timothy Wellman


//include statements
#include "wavheader.h"


//stream output operator for displaying the data formatted for console
std::ostream& operator<<(std::ostream& out, const WavHeader& headerOut){

	for (int i = 0; i<4; i++){out << headerOut.chunkId[i]; }
	out << headerOut.chunkSize;
	for (int i = 0; i<4; i++){out << headerOut.format[i]; }
	for (int i = 0; i<4; i++){out << headerOut.subChunk1Id[i]; }
	out << headerOut.subChunk1Size;
	out << headerOut.audioFormat;
	out << headerOut.numChannels;
	out << headerOut.sampleRate;
	out << headerOut.byteRate;
	out << headerOut.blockAlign;
	out << headerOut.bitsPerSample;
	for (int i = 0; i<4; i++){out << headerOut.subChunk2Id[i]; }
	out << headerOut.subChunk2Size;

	return out;
}

//stream input operator. the main idea here is using specific datatypes to control how many bytes are scanned in
std::istream& operator>>(std::istream& in, WavHeader& headerIn){

//thus far, this code will only work if there are 0 problems. exceptions to be added soon

	for (int i = 0; i<4; i++){in >> headerIn.chunkId[i]; }
	in >> headerIn.chunkSize;
	for (int i = 0; i<4; i++){in >> headerIn.format[i]; }
	for (int i = 0; i<4; i++){in >> headerIn.subChunk1Id[i]; }
	in >> headerIn.subChunk1Size;
	in >> headerIn.audioFormat;
	in >> headerIn.numChannels;
	in >> headerIn.sampleRate;
	in >> headerIn.byteRate;
	in >> headerIn.blockAlign;
	in >> headerIn.bitsPerSample;
	for (int i = 0; i<4; i++){in >> headerIn.subChunk2Id[i]; }
	in >> headerIn.subChunk2Size;

	return in;
}

WavHeader& WavHeader::operator=(const WavHeader& rhs){
	if (this == &rhs) return *this; //checking for self assignment

	//assign them values
	for (int i = 0; i<4; i++){chunkId[i] >> rhs.chunkId[i]; }
	chunkSize = rhs.chunkSize;
	for (int i = 0; i<4; i++){format[i] = rhs.format[i]; }
	for (int i = 0; i<4; i++){subChunk1Id[i] = rhs.subChunk1Id[i]; }
	subChunk1Size = rhs.subChunk1Size;
	audioFormat = rhs.audioFormat;
	numChannels = rhs.numChannels;
	sampleRate = rhs.sampleRate;
	byteRate = rhs.byteRate;
	blockAlign = rhs.blockAlign;
	bitsPerSample = rhs.bitsPerSample;
	for (int i = 0; i<4; i++){subChunk2Id[i] = rhs.subChunk2Id[i]; }
	subChunk2Size = rhs.subChunk2Size;

	return *this;
}

void WavHeader::checkMetadata(){
	bool typeError = (0);
}
/*

out << "Sample Rate: " << headerOut.sampleRate << std::endl;
	out << "Bits per Sample: " << headerOut.bitsPerSample << std::endl;
	out << "Channel number: ";
	if (headerOut.numChannels == 1){
		out << "Mono";
	}else if (headerOut.numChannels == 2) {
		out << "Stereo";
	}
	out << std::endl;
	/*
	Sample Rate: 8800
	Bits per Sample: 8
	Channel number: Mono
	* /

*/
