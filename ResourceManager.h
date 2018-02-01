#pragma once

#include <string>
#include "GLTexture.h"
#include "TextureCache.h"

namespace GLEngine {

	class ResourceManager {

		public:

			static GLTexture getTexture(std::string filePath);

		private:
			static TextureCache m_textureCache;

	};

}
