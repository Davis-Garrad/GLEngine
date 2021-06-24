#pragma once
#include "TextureCache.h"
#include <string>

namespace GLEngine
{

// This is a way for us to access all our resources, such as
// Models or textures.
class ResourceManager
{
public:
    static GLTexture getTexture(std::string texturePath);
    static GLTexture
    addTexture(std::string name, int width, int height, std::vector<unsigned char>& data, unsigned int type = GL_RGBA);
    static void setTexture(std::string& name,
        std::vector<unsigned char>* data,
        unsigned int type = GL_RGBA,
        unsigned int alignment = 4);
    static void setTexture(GLTexture& tex,
        std::vector<unsigned char>* data,
        unsigned int type = GL_RGBA,
        unsigned int alignment = 4);

private:
    static TextureCache _textureCache;
};

}
