//wavheader.cpp
//Timothy Wellman


//include statements
#include "wavheader.h"


//stream output operator for writing data for file
std::ostream& operator<<(std::ostream& out, const WavHeader& headerOut){
	out.write(headerOut.chunkId, 4);
	out << headerOut.chunkSize;
	out.write(headerOut.format, 4);
	out.write(headerOut.subChunk1Id, 4);
	out << headerOut.subChunk1Size;
	out << headerOut.audioFormat;
	out << headerOut.numChannels;
	out << headerOut.sampleRate;
	out << headerOut.byteRate;
	out << headerOut.blockAlign;
	out << headerOut.bitsPerSample;
	out.write(headerOut.subChunk2Id, 4);
	out << headerOut.subChunk2Size;

	return out;
}

//stream input operator. the main idea here is using specific datatypes to control how many bytes are scanned in
std::istream& operator>>(std::istream& in, WavHeader& headerIn){

//thus far, this code will only work if there are 0 problems. exceptions to be added soon

	in.read(headerIn.chunkId, 4);
	in >> headerIn.chunkSize;
	in.read(headerIn.format, 4);
	in.read(headerIn.subChunk1Id, 4);
	in >> headerIn.subChunk1Size;
	in >> headerIn.audioFormat;
	in >> headerIn.numChannels;
	in >> headerIn.sampleRate;
	in >> headerIn.byteRate;
	in >> headerIn.blockAlign;
	in >> headerIn.bitsPerSample;
	in.read(headerIn.subChunk2Id, 4);
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

void WavHeader::checkHeader(){
	
	//first we will do the strings, since they are the most mentally taxing
	std::string stringsToCheck[4] = {std::string(chunkId, 4), std::string(format, 4), std::string(subChunk1Id, 4), std::string(subChunk2Id, 4)};
	std::string desiredStrings[4] = {std::string("RIFF"), std::string("WAVE"), std::string("fmt "), std::string("data")}; 
	
	for(int i = 0; i<4; i++){
		if (stringsToCheck[i].compare(desiredStrings[i]) != 0){
			throw std::runtime_error("There was an error reading your data. /nMake sure your file is an 8 or 16 bit .wav file./n");
		}
	}

	//now we will check for the data volume errors & other math checks
	bool chunkValueCheck = (chunkSize !=(subChunk2Size + 44 - 8) || subChunk1Size != 16);
	bool blockAlignCheck = blockAlign != numChannels * bitsPerSample/8;

	if (subChunk2Size < 0){
		throw std::runtime_error("array length error here");
	}

	if(chunkValueCheck || blockAlignCheck){
		throw std::runtime_error("There was an error reading your data. /nPlease try again./n");
	}

	//checking the channels and bit depth
	bool channelCheck = (numChannels != 1 && numChannels != 2);
	bool bitDepthCheck = (bitsPerSample != 8 && bitsPerSample != 16);
	if (channelCheck || bitDepthCheck){
		throw std::runtime_error("There was an error reading your data./nBe sure your file is a 1-2 channel, 8 or 16 bit .wav file./n");
	}


}
