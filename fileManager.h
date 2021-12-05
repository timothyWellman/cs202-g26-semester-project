//Rubi Dionisio
#ifndef FILEMANAGER_H
#define FILEMANAAGER_H

#include <vector>
#include <string>
#include "wavheader.h"

class FileManager{
	private:
	short* buffer = nullptr;

	WavHeader wavHeader;
	std::vector<float>data;

	public:

	void readFile(const std::string &fileName);
	void saveFile(const std::string &oFileName);
	virtual ~FileManager();


};

#endif