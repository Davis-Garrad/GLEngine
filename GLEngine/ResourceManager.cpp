#include "ResourceManager.h"

namespace GLEngine {
	
	TextureCache ResourceManager::m_textureCache;
	
	GLTexture ResourceManager::getTexture(std::string filePath) {

		return m_textureCache.getTexture(filePath);

	}

}

