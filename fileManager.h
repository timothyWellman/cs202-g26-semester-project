//Rubi Dionisio
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "wavheader.h"

class FileManager{
	private:
	short* buffer16 = nullptr;
	char* buffer8 = nullptr;
	
	WavHeader wavHeader;
	std::vector<float>data;

	public:

	bool canOpenFile(const std::string &fileName);
	void readFile(const std::string &fileName);
	void saveFile(const std::string &oFileName);

	float* getData();
	WavHeader getwavHeader();
	
};

#endif