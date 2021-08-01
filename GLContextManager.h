#pragma once

#include <GL/gl.h>

namespace GLEngine
{

class GLContext
{
public:
    GLContext();
    ~GLContext();

    void setActiveTexture(GLenum texture);
    void bindTexture(GLenum target, GLuint texture);
    void unbindTexture(GLenum texture, GLenum target);

private:
    GLenum m_activeTexture = GL_TEXTURE0;
    GLuint* m_boundTextureIDs = nullptr;
};

class GLContextManager
{ // Singleton Manager
public:
    static GLContext* getGLContext();

private:
    static GLContext* m_context;
};

}
