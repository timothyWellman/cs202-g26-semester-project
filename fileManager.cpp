//Rubi Dionisio

#include <utility>
#include <fstream>
#include "fileManager.h"

void FileManager::readFile(const std::string &fileName){
	//int MAX_16BIT = 256;
	std::ifstream inputFile(fileName, std::ios::binary | std::ios::in);
	short* buffer = nullptr;

	if(inputFile.is_open()){
		
		inputFile.read((char*) &wavHeader, sizeof(wavHeader));
		buffer = new short[wavHeader.subChunk2Size];
		inputFile.read((char*) buffer, wavHeader.subChunk2Size /*data bytes*/);

		for(int i = 0; i < wavHeader.subChunk2Size / wavHeader.blockAlign/*sample alignment*/; i++){
			data.push_back((float)buffer[i] / 256);
		}

		inputFile.close();
	}
	//return something if cannot open, for instance i can make the function into a boolean if it makes things easier

	delete[]buffer;
}

bool absCompare(float a, float b){
	return std::abs(a) < std::abs(b);
}

void FileManager::saveFile(const std::string &oFileName){
	std::ofstream oFile(oFileName, std::ios::out | std::ios::binary);

	//auto maxLocation = std::max_element(data.begin(), data.end(), absCompare);
	//float maxVal = *maxLocation;

	auto* buffer = new short[data.size()];
	for(int i = 0 ; i < data.size(); i++){
		buffer[i] = (short)(data[i] * 256);
	}

	wavHeader.subChunk2Size = data.size() * wavHeader.blockAlign;
	wavHeader.subChunk1Size /*wave size?*/= wavHeader.subChunk2Size + 44 - 8;
	oFile.write((char*)&wavHeader, sizeof(wavHeader));
	oFile.write((char*) buffer , wavHeader.subChunk2Size);
	
	oFile.close();

}
