#pragma once

#include <vector>
#include <string>

namespace GLEngine {

	class IOManager {

		public:
			static bool readFileToBuffer(std::vector<unsigned char>& buffer, std::string filePath);
			static bool readFileToStrings(std::vector<std::string>& strings, std::string filePath);

		private:

	};

}
