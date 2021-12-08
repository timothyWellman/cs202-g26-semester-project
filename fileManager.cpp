//Rubi Dionisio

#include <utility>
#include <fstream>
#include "fileManager.h"

/**
 * @brief This checks if the wave file can be opened
 * 
 * @param fileName 
 * @return true if file can be opened
 * @return false if file cannot be
 */
bool FileManager::canOpenFile(const std::string &fileName){
	std::ifstream inputFile(fileName, std::ios::binary | std::ios::in);
	if(inputFile.is_open()){
		inputFile.close();
		return true;
	}
		return false;
}

/**
 * @brief Reads the actual wave file
 * 
 * @param fileName 
 */
void FileManager::readFile(const std::string &fileName){
	std::ifstream inputFile(fileName, std::ios::binary | std::ios::in);

	if(inputFile.is_open()){
		
		inputFile.read((char*) &wavHeader, sizeof(wavHeader));
		//inputFile >> wavHeader;

		try{
			wavHeader.checkHeader();

		}
		catch (std::runtime_error& a){std::cout << a.what() << std::endl;}
		if(wavHeader.bitsPerSample == 16){
			buffer16 = new short[wavHeader.subChunk2Size];
			inputFile.read((char*) buffer16, wavHeader.subChunk2Size);
			for(int i = 0; i < wavHeader.subChunk2Size / wavHeader.blockAlign; i++){
				data.push_back((float)buffer16[i] / 32767);
			}

		}else if(wavHeader.bitsPerSample == 8){
			buffer8 = new char[wavHeader.subChunk2Size];
			inputFile.read((char*) buffer8, wavHeader.subChunk2Size);
			for(int i = 0; i < wavHeader.subChunk2Size / wavHeader.blockAlign; i++){
				data.push_back(((float)buffer8[i]-128) / 128);
			}
		}

		inputFile.close();
		delete buffer16;
		delete buffer8;
	}
	// delete[]buffer16;
	// delete[]buffer8;
}

/**
 * @brief puts in the new data back into the wave file
 * 
 * @param oFileName 
 */
void FileManager::saveFile(const std::string &oFileName){
	std::ofstream oFile(oFileName, std::ios::out | std::ios::binary);

	if(wavHeader.bitsPerSample == 16){
			buffer16 = new short[data.size()];
			for(int i = 0 ; i < data.size(); i++){
				buffer16[i] = (short)(data[i] * 32767);
			}

			wavHeader.subChunk2Size = data.size() * wavHeader.blockAlign;
			wavHeader.subChunk1Size = wavHeader.subChunk2Size + 44 - 8;
			oFile.write((char*)&wavHeader, sizeof(wavHeader));
			oFile.write((char*)buffer16, wavHeader.subChunk2Size);

		}else if(wavHeader.bitsPerSample == 8){
			buffer8 = new char[data.size()];
			for(int i = 0 ; i < data.size(); i++){
				buffer16[i] = (char)(data[i] * 256);
			}

			wavHeader.subChunk2Size = data.size() * wavHeader.blockAlign;
			wavHeader.subChunk1Size = wavHeader.subChunk2Size + 44 - 8;
			oFile.write((char*)&wavHeader, sizeof(wavHeader));
			oFile.write((char*)buffer8, wavHeader.subChunk2Size);

		}

	oFile.close();

}

/**
 * @brief sets the vecotr of data
 * 
 * @param newVector a float of vectors
 */
void FileManager::setData(const std::vector<float>& newVector){
	data = newVector;
}

/**
 * @brief sets the wavHeader
 * 
 * @param newWavHeader 
 */
void FileManager::setwavHeader(const WavHeader& newWavHeader){
	wavHeader = newWavHeader;
}

/**
 * @brief returns data
 * 
 * @return float* 
 */
float* FileManager::getData(){
	return &data[0];
}

/**
 * @brief returns the wav header
 * 
 * @return WavHeader 
 */
WavHeader FileManager::getwavHeader(){
	return wavHeader;
}
