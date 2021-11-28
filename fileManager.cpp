//Rubi Dionisio

#include <utility>
#include <fstream>
#include "fileManager.h"

void fileManager::readFile(const std::string &fileName){
	std::ifstream inputFile(fileName, std::ios::binary | std::ios::in);
	inputFile.open();

	if(inputFile){
		inputFile.read((char*) &waveHeader, sizeof(wav_Header));

		inputFile.close();
	}else{
		throw std::runtime_error("File " + fileName + " could not be opened");
	}

}