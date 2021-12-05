//Rubi Dionisio
#ifndef FILEMANAGER_H
#define FILEMANAAGER_H

#include <vector>
#include <string>
#include "wavheader.h"
#include "wavfile.h"

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
	virtual ~FileManager();
	
};

#endif