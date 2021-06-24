#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>
#include <vector>

namespace GLEngine {

	TextureCache::TextureCache() {
	}

	TextureCache::~TextureCache() {
	}

	GLTexture& TextureCache::getTexture(std::string texturePath) {

		//lookup the texture and see if its in the map
		auto mit = _textureMap.find(texturePath);

		//check if its not in the map
		if(mit == _textureMap.end()) {
			//Load the texture
			GLTexture newTexture = ImageLoader::loadPNG(texturePath);

			//Insert it into the map
			_textureMap.insert(make_pair(texturePath, newTexture));
		}
		return _textureMap.find(texturePath)->second;
	}

	GLTexture TextureCache::addTexture(std::string name, int width, int height, std::vector<unsigned char> data, unsigned int type) {
		GLTexture texture;

		//Generate the openGL texture object
		glGenTextures((GLsizei)1, &(texture.id));

		texture.width = width;
		texture.height = height;
		texture.filePath = name;

		//Insert it into the map
		_textureMap.insert(make_pair(name, texture));

		//Bind the texture object
		glBindTexture(GL_TEXTURE_2D, texture.id);
		//Upload the pixels to the texture
		glTexImage2D(GL_TEXTURE_2D, (GLint)0, type, (GLsizei)width, (GLsizei)height, (GLint)0, type, GL_UNSIGNED_BYTE, &(data[0]));

		//Set some texture parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		//Generate the mipmaps
		glGenerateMipmap(GL_TEXTURE_2D);

		//Unbind the texture
		glBindTexture(GL_TEXTURE_2D, (GLuint)0);

		return texture;
	}

}
