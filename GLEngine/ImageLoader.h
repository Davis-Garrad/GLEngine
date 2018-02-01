#pragma once

#include <string>
#include "GLTexture.h"

namespace GLEngine {

	class ImageLoader {

		public:
			static GLTexture loadPNG(std::string filePath);

	};

}
