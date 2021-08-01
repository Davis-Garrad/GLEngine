#include "GLContextManager.h"

namespace GLEngine
{

GLContext::GLContext()
{
    m_boundTextureIDs = new GLuint[GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS];
}

GLContext::~GLContext()
{
    delete[] m_boundTextureIDs;
}

void GLContext::setActiveTexture(GLenum texture)
{
    if(m_activeTexture != texture) {
	m_activeTexture = texture;
	glActiveTexture(texture);
    }
}

void GLContext::bindTexture(GLenum target, GLuint texture)
{
    if(m_boundTextureIDs[(unsigned int)m_activeTexture - (unsigned int)GL_TEXTURE0] != texture) {
	m_boundTextureIDs[(unsigned int)m_activeTexture - (unsigned int)GL_TEXTURE0] = texture;
	glBindTexture(target, texture);
    }
}

void GLContext::unbindTexture(GLenum texture, GLenum target)
{
    setActiveTexture(texture);
    bindTexture(target, 0);
}

GLContext* GLContextManager::m_context = nullptr;

GLContext* GLContextManager::getGLContext()
{
    if(!m_context) {
	m_context = new GLContext();
    }
    return m_context;
}

}
