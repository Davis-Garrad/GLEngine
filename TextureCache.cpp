#include "ImageLoader.h"
#include "TextureCache.h"

#include "GLEngineErrors.h"
#include "ImageLoader.h"

namespace GLEngine {
	
	TextureCache::TextureCache() {

	}
	
	TextureCache::~TextureCache() {

	}
	
	GLTexture TextureCache::getTexture(std::string filePath) {

		auto mit = m_textureMap.find(filePath); // Auto turns 'auto myString = "Hello";' into 'STRING myString = "Hello";'

		if (mit == m_textureMap.end()) {

			GLTexture newTexture = ImageLoader::loadPNG(filePath);

			// Put the key and val into the map in a 'pair'
			m_textureMap.insert(make_pair(filePath, newTexture));

			return newTexture;
			
		}
		
		return mit->second;
		
	}

}
