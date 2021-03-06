#include "ResourceManager.h"

namespace GLEngine
{

TextureCache ResourceManager::_textureCache;

GLTexture ResourceManager::getTexture(std::string texturePath)
{
    GLTexture tex = _textureCache.getTexture(texturePath);
    GLTexture copiedTex = tex;
    return copiedTex;
}

GLTexture ResourceManager::addTexture(std::string name,
    int width,
    int height,
    std::vector<unsigned char>& data,
    unsigned int type)
{
    return _textureCache.addTexture(name, width, height, data, type);
}

void ResourceManager::setTexture(std::string& name,
    std::vector<unsigned char>* data,
    unsigned int type,
    unsigned int alignment)
{
    GLTexture tex = _textureCache.getTexture(name);

    glPixelStorei(GL_UNPACK_ALIGNMENT, alignment);

    glBindTexture(GL_TEXTURE_2D, tex.id);
    glTexImage2D(GL_TEXTURE_2D, (GLint)0, type, (GLsizei)tex.width, (GLsizei)tex.height, (GLint)0, type,
        GL_UNSIGNED_BYTE, &((*data)[0]));

    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
}

void ResourceManager::setTexture(GLTexture& tex,
    std::vector<unsigned char>* data,
    unsigned int type,
    unsigned int alignment)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, alignment);

    glBindTexture(GL_TEXTURE_2D, tex.id);
    glTexImage2D(GL_TEXTURE_2D, (GLint)0, type, (GLsizei)tex.width, (GLsizei)tex.height, (GLint)0, type,
        GL_UNSIGNED_BYTE, &((*data)[0]));

    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
}

}
