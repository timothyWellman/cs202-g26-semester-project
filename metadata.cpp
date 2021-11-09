//metadata.cpp
//Timothy Wellman


//include statements
#include "metadata.h"


//stream output operator for displaying the data formatted for console
std::ostream& operator<<(std::ostream& out, const Metadata& metaOut){

	for (int i = 0; i<4; i++){out << metaOut.chunkId[i]; }
	out << metaOut.chunkSize;
	for (int i = 0; i<4; i++){out << metaOut.format[i]; }
	for (int i = 0; i<4; i++){out << metaOut.subchunk1Id[i]; }
	out << metaOut.subchunk1Size;
	out << metaOut.audioFormat;
	out << metaOut.numChannels;
	out << metaOut.sampleRate;
	out << metaOut.byteRate;
	out << metaOut.blockAlign;
	out << metaOut.bitsPerSample;
	for (int i = 0; i<4; i++){out << metaOut.subchunk2Id[i]; }
	out << metaOut.subchunk2Size;

	return out;
}

//stream input operator. the main idea here is using specific datatypes to control how many bytes are scanned in
std::istream& operator>>(std::istream& in, Metadata& metaIn){

//thus far, this code will only work if there are 0 problems. exceptions to be added soon

	for (int i = 0; i<4; i++){in >> metaIn.chunkId[i]; }
	in >> metaIn.chunkSize;
	for (int i = 0; i<4; i++){in >> metaIn.format[i]; }
	for (int i = 0; i<4; i++){in >> metaIn.subchunk1Id[i]; }
	in >> metaIn.subchunk1Size;
	in >> metaIn.audioFormat;
	in >> metaIn.numChannels;
	in >> metaIn.sampleRate;
	in >> metaIn.byteRate;
	in >> metaIn.blockAlign;
	in >> metaIn.bitsPerSample;
	for (int i = 0; i<4; i++){in >> metaIn.subchunk2Id[i]; }
	in >> metaIn.subchunk2Size;

	return in;
}

Metadata& Metadata::operator=(const Metadata& rhs){
	if (this == &rhs) return *this; //checking for self assignment

	//assign them values
	for (int i = 0; i<4; i++){chunkId[i] >> rhs.chunkId[i]; }
	chunkSize = rhs.chunkSize;
	for (int i = 0; i<4; i++){format[i] = rhs.format[i]; }
	for (int i = 0; i<4; i++){subchunk1Id[i] = rhs.subchunk1Id[i]; }
	subchunk1Size = rhs.subchunk1Size;
	audioFormat = rhs.audioFormat;
	numChannels = rhs.numChannels;
	sampleRate = rhs.sampleRate;
	byteRate = rhs.byteRate;
	blockAlign = rhs.blockAlign;
	bitsPerSample = rhs.bitsPerSample;
	for (int i = 0; i<4; i++){subchunk2Id[i] = rhs.subchunk2Id[i]; }
	subchunk2Size = rhs.subchunk2Size;

	return *this;
}


/*

out << "Sample Rate: " << metaOut.sampleRate << std::endl;
	out << "Bits per Sample: " << metaOut.bitsPerSample << std::endl;
	out << "Channel number: ";
	if (metaOut.numChannels == 1){
		out << "Mono";
	}else if (metaOut.numChannels == 2) {
		out << "Stereo";
	}
	out << std::endl;
	/*
	Sample Rate: 8800
	Bits per Sample: 8
	Channel number: Mono
	* /

*/
