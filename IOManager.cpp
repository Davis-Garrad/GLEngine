#include "IOManager.h"

#include <fstream>

namespace GLEngine {
	
	bool IOManager::readFileToBuffer(std::vector<unsigned char>& buffer, std::string filePath) {

		std::ifstream file(filePath, std::ios::binary);
		if (file.fail()) {
			perror(filePath.c_str());
			return false;
		}

		// Find total size of file
		//Seek to the end with the 'cursor'
		file.seekg(0, std::ios::end);
		int fileSize = file.tellg();
		//Seek back
		file.seekg(0, std::ios::beg);

		// Take away any header bytes that may be present ;)
		fileSize -= file.tellg();

		buffer.resize(fileSize);

		file.read((char*) &(buffer[0]), fileSize);
		file.close();

		return true;

	}

	bool IOManager::readFileToStrings(std::vector<std::string> &strings, std::string filePath) {

		std::ifstream file(filePath);
		if (file.fail()) {
			perror(filePath.c_str());
			return false;
		}

		std::string line;

		while(getline(file, line)) {
			line += "\n";
			strings.push_back(line);
		}

		file.close();

		return true;

	}

}
