#include "ResourceManager.h"

namespace GLEngine {

	TextureCache ResourceManager::_textureCache;

	GLTexture ResourceManager::getTexture(std::string texturePath) {
		GLTexture tex = _textureCache.getTexture(texturePath);
		GLTexture copiedTex = tex;
		return copiedTex;
	}

	GLTexture ResourceManager::addTexture(std::string name, int width, int height, std::vector<unsigned char>& data) {
		return _textureCache.addTexture(name, width, height, data);
	}

	void ResourceManager::setTexture(std::string& name, std::vector<unsigned char>* data) {
		GLTexture tex = _textureCache.getTexture(name);

		glBindTexture(GL_TEXTURE_2D, tex.id);
		glTexImage2D(GL_TEXTURE_2D, (GLint)0, GL_RGBA, (GLsizei)tex.width, (GLsizei)tex.height, (GLint)0, GL_RGBA, GL_UNSIGNED_BYTE, &((*data)[0]));
	}

}
