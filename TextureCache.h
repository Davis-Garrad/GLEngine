#pragma once
#include <map>
#include <vector>
#include "GLTexture.h"

namespace GLEngine {

	//This caches the textures so that multiple sprites can use the same textures
	class TextureCache {
		public:
			TextureCache();
			~TextureCache();

			GLTexture& getTexture(std::string texturePath);
			GLTexture addTexture(std::string name, int width, int height, std::vector<unsigned char> data);

		private:
			std::map<std::string, GLTexture> _textureMap;
	};

}
