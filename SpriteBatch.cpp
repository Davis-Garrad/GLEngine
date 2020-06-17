#include "SpriteBatch.h"

#include <algorithm>

#include "GLEngineErrors.h"

#include <iostream>

namespace GLEngine {


    Glyph::Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint Texture, GLuint bumpMapTexture, float Depth, const ColourRGBA8& color, glm::vec4 light) :
        texture(Texture),
        bumpMap(bumpMapTexture),
        depth(Depth) {

        topLeft.color = color;
        topLeft.setPosition(destRect.x, destRect.y + destRect.w, depth);
        topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);
        topLeft.setLight(light.x, light.y, light.z, light.w);

        bottomLeft.color = color;
        bottomLeft.setPosition(destRect.x, destRect.y, depth);
        bottomLeft.setUV(uvRect.x, uvRect.y);
        bottomLeft.setLight(light.x, light.y, light.z, light.w);

        bottomRight.color = color;
        bottomRight.setPosition(destRect.x + destRect.z, destRect.y, depth);
        bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);
        bottomRight.setLight(light.x, light.y, light.z, light.w);

        topRight.color = color;
        topRight.setPosition(destRect.x + destRect.z, destRect.y + destRect.w, depth);
        topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);
        topRight.setLight(light.x, light.y, light.z, light.w);
    }

    Glyph::Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint Texture, GLuint bumpMapTexture, float Depth, const ColourRGBA8& color, float angle, glm::vec4 light) :
        texture(Texture),
        bumpMap(bumpMapTexture),
        depth(Depth) {

        glm::vec2 halfDims(destRect.z / 2.0f, destRect.w / 2.0f);

        // Get points centered at origin
        glm::vec2 tl(-halfDims.x, halfDims.y);
        glm::vec2 bl(-halfDims.x, -halfDims.y);
        glm::vec2 br(halfDims.x, -halfDims.y);
        glm::vec2 tr(halfDims.x, halfDims.y);

        // Rotate the points
        tl = rotatePoint(tl, angle) + halfDims;
        bl = rotatePoint(bl, angle) + halfDims;
        br = rotatePoint(br, angle) + halfDims;
        tr = rotatePoint(tr, angle) + halfDims;

        topLeft.color = color;
        topLeft.setPosition(destRect.x + tl.x, destRect.y + tl.y, Depth);
        topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);
        topLeft.setLight(light.x, light.y, light.z, light.w);

        bottomLeft.color = color;
        bottomLeft.setPosition(destRect.x + bl.x, destRect.y + bl.y, Depth);
        bottomLeft.setUV(uvRect.x, uvRect.y);
        bottomLeft.setLight(light.x, light.y, light.z, light.w);

        bottomRight.color = color;
        bottomRight.setPosition(destRect.x + br.x, destRect.y + br.y, Depth);
        bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);
        bottomRight.setLight(light.x, light.y, light.z, light.w);

        topRight.color = color;
        topRight.setPosition(destRect.x + tr.x, destRect.y + tr.y, Depth);
        topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);
        topRight.setLight(light.x, light.y, light.z, light.w);
    }

    Glyph::Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint Texture, GLuint bumpMapTexture, float Depth, const ColourRGBA8& color, float angle, glm::vec4 light, const glm::vec2& pointOfRotation) :
        texture(Texture),
        bumpMap(bumpMapTexture),
        depth(Depth) {

        glm::vec2 centrePoint = glm::vec2(destRect.z, destRect.w) * pointOfRotation;
        glm::vec2 invCentrePoint = glm::vec2(destRect.z, destRect.w) * (1.0f - pointOfRotation);

        // Get points centered at origin
        glm::vec2 tl(-invCentrePoint.x, centrePoint.y);
        glm::vec2 bl(-invCentrePoint.x, -invCentrePoint.y);
        glm::vec2 br(centrePoint.x, -invCentrePoint.y);
        glm::vec2 tr(centrePoint.x, centrePoint.y);

        // Rotate the points
        tl = rotatePoint(tl, angle) + centrePoint;
        bl = rotatePoint(bl, angle) + centrePoint;
        br = rotatePoint(br, angle) + centrePoint;
        tr = rotatePoint(tr, angle) + centrePoint;

        topLeft.color = color;
        topLeft.setPosition(destRect.x + tl.x, destRect.y + tl.y, Depth);
        topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);
        topLeft.setLight(light.x, light.y, light.z, light.w);

        bottomLeft.color = color;
        bottomLeft.setPosition(destRect.x + bl.x, destRect.y + bl.y, Depth);
        bottomLeft.setUV(uvRect.x, uvRect.y);
        bottomLeft.setLight(light.x, light.y, light.z, light.w);

        bottomRight.color = color;
        bottomRight.setPosition(destRect.x + br.x, destRect.y + br.y, Depth);
        bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);
        bottomRight.setLight(light.x, light.y, light.z, light.w);

        topRight.color = color;
        topRight.setPosition(destRect.x + tr.x, destRect.y + tr.y, Depth);
        topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);
        topRight.setLight(light.x, light.y, light.z, light.w);
    }

    glm::vec2 Glyph::rotatePoint(const glm::vec2& pos, float angle) {
        glm::vec2 newv;
        newv.x = pos.x * cos(angle) - pos.y * sin(angle);
        newv.y = pos.y * cos(angle) + pos.x * sin(angle);
        return newv;
    }

void GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
                            GLenum severity, GLsizei length,
                            const GLchar *msg, const void *data)
{
    char* _source;
    char* _type;
    char* _severity;

    switch (source) {
        case GL_DEBUG_SOURCE_API:
        _source = "API";
        break;

        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        _source = "WINDOW SYSTEM";
        break;

        case GL_DEBUG_SOURCE_SHADER_COMPILER:
        _source = "SHADER COMPILER";
        break;

        case GL_DEBUG_SOURCE_THIRD_PARTY:
        _source = "THIRD PARTY";
        break;

        case GL_DEBUG_SOURCE_APPLICATION:
        _source = "APPLICATION";
        break;

        case GL_DEBUG_SOURCE_OTHER:
        _source = "UNKNOWN";
        break;

        default:
        _source = "UNKNOWN";
        break;
    }

    switch (type) {
        case GL_DEBUG_TYPE_ERROR:
        _type = "ERROR";
        break;

        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        _type = "DEPRECATED BEHAVIOR";
        break;

        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        _type = "UDEFINED BEHAVIOR";
        break;

        case GL_DEBUG_TYPE_PORTABILITY:
        _type = "PORTABILITY";
        break;

        case GL_DEBUG_TYPE_PERFORMANCE:
        _type = "PERFORMANCE";
        break;

        case GL_DEBUG_TYPE_OTHER:
        _type = "OTHER";
        break;

        case GL_DEBUG_TYPE_MARKER:
        _type = "MARKER";
        break;

        default:
        _type = "UNKNOWN";
        break;
    }

    switch (severity) {
        case GL_DEBUG_SEVERITY_HIGH:
        _severity = "HIGH";
        break;

        case GL_DEBUG_SEVERITY_MEDIUM:
        _severity = "MEDIUM";
        break;

        case GL_DEBUG_SEVERITY_LOW:
        _severity = "LOW";
        break;

        case GL_DEBUG_SEVERITY_NOTIFICATION:
        _severity = "NOTIFICATION";
        break;

        default:
        _severity = "UNKNOWN";
        break;
    }

    std::printf("%d: %s of %s severity, raised from %s: %s\n",
            id, _type, _severity, _source, msg);
}

FrameBufferObject::FrameBufferObject() : m_fbo(0), m_colourTex(0), m_depthTex(0) {
    glEnable(GL_DEBUG_OUTPUT); // Enables debug output.
    glDebugMessageCallback(GLDebugMessageCallback, NULL);
}

FrameBufferObject::~FrameBufferObject() {
    dispose();
}

void FrameBufferObject::init(glm::vec4 destRect) {
    m_destRect = destRect;

    createVertexArray();
    createFramebuffer();
}

void FrameBufferObject::begin() {
    // Binds the FBO, RBOs, clears, and calls glDrawBuffers
    // Make sure we can write to the depth texture. NOTE TO SELF: THIS IS REALLY IMPORTANT
    glEnable(GL_DEPTH_TEST);
    glDepthRange(0.0f, 1.0f);
    glDepthMask(GL_TRUE); // Make sure we can write to the depth buffer (texture)
    glDepthFunc(GL_LESS);

    glEnable(GL_ALPHA_TEST); // Make sure that we exclude completely transparent pixels (below).
    glAlphaFunc(GL_GREATER, 0.0f); // Make sure transparent pixels aren't written to depth.

    glEnable(GL_BLEND); // Make sure our alpha channel is still being blended.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Bind
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);

    // Clear stuff
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    // Call glDrawBuffers
    GLenum bufs[1] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers(1, bufs);
}

void FrameBufferObject::end() {
    // Unbind FBO
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBufferObject::draw() {
    // The shader uniforms must be set so that the texture is in GL_TEXTURE0 and the depthmap is in GL_TEXTURE1

    //glViewport((int)m_destRect.x, (int)m_destRect.y, (int)m_destRect.z, (int)m_destRect.w);

    // Make sure we're not cutting anything off or writing over depth texture. NOTE TO SELF: THIS IS REALLY IMPORTANT
    glDisable(GL_DEPTH_TEST);

    // Set GL_TEXTURE0 and 1
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_colourTex);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_depthTex);

    // Bind VAO
    glBindVertexArray(m_vao);

    // Draw vertices (First 6 vertices (a destRect quad))
    glDrawArrays(GL_TRIANGLES, 0, 6);

    // Unbind VAO
    glBindVertexArray(0);
}

void FrameBufferObject::dispose() {
    glDeleteFramebuffers(1, &m_fbo);
    m_fbo = 0;
    glDeleteTextures(1, &m_colourTex);
    m_colourTex = 0;
    glDeleteTextures(1, &m_depthTex);
    m_depthTex = 0;
    glDeleteVertexArrays(1, &m_vao);
    m_vao = 0;
    glDeleteBuffers(1, &m_vbo);
    m_vbo = 0;
}

void FrameBufferObject::createVertexArray() {

    // Generate the VAO if it isn't already generated
    glGenVertexArrays(1, &m_vao);

    // Bind the VAO. All subsequent opengl calls will modify it's state.
    glBindVertexArray(m_vao);

    // Generate the VBO if it isn't already generated
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    // Tell opengl what attribute arrays we need
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    //This is the position attribute pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    //This is the color attribute pointer
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    //This is the UV attribute pointer
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

    glBindVertexArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    // Now that the VAO and VBO are created, we need to add the vertices.
    Glyph g(m_destRect, glm::vec4(0.0f, 0.0f, 1.0f, 1.0f), 0, 0, 0.8f, ColourRGBA8(255, 255, 255, 255), 0.0f, glm::vec4(0.0f)); // Just make a glyph to handle the vertex-placement

    std::vector<Vertex> vertices;
    vertices.push_back(g.topLeft);
    vertices.push_back(g.bottomLeft);
    vertices.push_back(g.bottomRight);
    vertices.push_back(g.bottomRight);
    vertices.push_back(g.topRight);
    vertices.push_back(g.topLeft);

    // Orphan the buffer (for speed)
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), nullptr, GL_STATIC_DRAW); // GL_STATIC so that we can only read after this (for speed, baby!)
    // Upload the data
    glBufferSubData(GL_ARRAY_BUFFER, 0, 6 * sizeof(Vertex), vertices.data());

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind

}

void FrameBufferObject::createFramebuffer() {
    // 1. Generate FBO handle
    glGenFramebuffers(1, &m_fbo);

    // 2. Bind it
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);

    // 3. Create textures
    createTextures();

    // 4. Check status of FBO.
    GLint status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if(status != GL_FRAMEBUFFER_COMPLETE) {
        fatalError("Could not create FBO!");
        m_fbo = 0;
    }

    // Unbind
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBufferObject::createTextures() {
    // 1. Generate texture handles
    glGenTextures(1, &m_colourTex);
    glGenTextures(1, &m_depthTex);

    // 2. Bind em, define em, attach em
    // Bind
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_colourTex);
    // Define
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (int)m_destRect.z, (int)m_destRect.w, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0); // Try giving the texture a place to put the data?
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // Attach
    // Our FBO is already bound!
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_colourTex, 0);


    // Repeat for depth attachment
    // Bind
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_depthTex);
    // Define (we act like its a depth stencil because according to the internet, it works for some reason)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, (int)m_destRect.z, (int)m_destRect.w, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, 0); // Try giving the texture a place to put the data?
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // Attach
    // Our FBO is already bound!
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, m_depthTex, 0);

    // Done!
}

SpriteBatch::SpriteBatch() : _vbo(0), _vao(0)
{
}

SpriteBatch::~SpriteBatch()
{
}

void SpriteBatch::init() {
    glDepthRange(0.0f, 100.0f);

    createVertexArray();
}

void SpriteBatch::dispose() {
    glDeleteVertexArrays(1, &_vao);
    _vao = 0;
    glDeleteBuffers(1, &_vbo);
    _vbo = 0;
}

void SpriteBatch::begin(GlyphSortType sortType /* GlyphSortType::TEXTURE */) {
    _sortType = sortType;
    _renderBatches.clear();

    // Makes _glpyhs.size() == 0, however it does not free internal memory.
    // So when we later call emplace_back it doesn't need to internally call new.
    _glyphs.clear();
}

void SpriteBatch::end() {
    // Set up all pointers for fast sorting
    _glyphPointers.resize(_glyphs.size());
    for (size_t i = 0; i < _glyphs.size(); i++) {
        _glyphPointers[i] = &_glyphs[i];
    }

    sortGlyphs();
    createRenderBatches();
}

void SpriteBatch::draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, GLuint bumpMapTexture, float depth, const ColourRGBA8& color, glm::vec4 verticesLight) {
    _glyphs.emplace_back(destRect, uvRect, texture, bumpMapTexture, depth, color, verticesLight);
}

void SpriteBatch::draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, GLuint bumpMapTexture, float depth, const ColourRGBA8& color, float angle, glm::vec4 verticesLight, const glm::vec2& pointOfRotation) {
    _glyphs.emplace_back(destRect, uvRect, texture, bumpMapTexture, depth, color, angle, verticesLight, pointOfRotation);
}

void SpriteBatch::draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, GLuint bumpMapTexture, float depth, const ColourRGBA8& color, const glm::vec2& dir, glm::vec4 verticesLight, const glm::vec2& pointOfRotation) {
    const glm::vec2 right(1.0f, 0.0f);
    float angle = acos(glm::dot(right, dir));
    if (dir.y < 0.0f) angle = -angle;

    _glyphs.emplace_back(destRect, uvRect, texture, bumpMapTexture, depth, color, angle, verticesLight, pointOfRotation);
}

void SpriteBatch::renderBatch() {

    // Bind our VAO. This sets up the opengl state we need, including the
    // vertex attribute pointers and it binds the VBO
    glBindVertexArray(_vao);

    for (size_t i = 0; i < _renderBatches.size(); i++) {
        glActiveTexture(GL_TEXTURE0); // Set the active texture to 0 (the renderbatch regular texture)
        glBindTexture(GL_TEXTURE_2D, _renderBatches[i].texture);
        if(_renderBatches[i].bumpMap) {
            glActiveTexture(GL_TEXTURE1); // Set active texture to 1 to bind the bumpMap texture there.
            glBindTexture(GL_TEXTURE_2D, _renderBatches[i].bumpMap);
        }

        glDrawArrays(GL_TRIANGLES, (GLint)_renderBatches[i].offset, (GLsizei)_renderBatches[i].numVertices);
    }

    glBindVertexArray(0);
}

void SpriteBatch::createRenderBatches() {
    // This will store all the vertices that we need to upload
    std::vector <Vertex> vertices;
    // Resize the buffer to the exact size we need so we can treat
    // it like an array
    vertices.resize(_glyphPointers.size() * 6);

    if (_glyphPointers.empty()) {
        return;
    }

    int offset = 0; // current offset
    int cv = 0; // current vertex

    //Add the first batch
    _renderBatches.emplace_back(offset, 6, _glyphPointers[0]->texture, _glyphPointers[0]->bumpMap);
    vertices[cv++] = _glyphPointers[0]->topLeft;
    vertices[cv++] = _glyphPointers[0]->bottomLeft;
    vertices[cv++] = _glyphPointers[0]->bottomRight;
    vertices[cv++] = _glyphPointers[0]->bottomRight;
    vertices[cv++] = _glyphPointers[0]->topRight;
    vertices[cv++] = _glyphPointers[0]->topLeft;
    offset += 6;

    //Add all the rest of the glyphs
    for (size_t cg = 1; cg < _glyphPointers.size(); cg++) {

        // Check if this glyph can be part of the current batch
        if (_glyphPointers[cg]->texture != _glyphPointers[cg - 1]->texture) {
            // Make a new batch
            _renderBatches.emplace_back(offset, 6, _glyphPointers[cg]->texture, _glyphPointers[cg]->bumpMap);
        } else {
            // If its part of the current batch, just increase numVertices
            _renderBatches.back().numVertices += 6;
        }
        vertices[cv++] = _glyphPointers[cg]->topLeft;
        vertices[cv++] = _glyphPointers[cg]->bottomLeft;
        vertices[cv++] = _glyphPointers[cg]->bottomRight;
        vertices[cv++] = _glyphPointers[cg]->bottomRight;
        vertices[cv++] = _glyphPointers[cg]->topRight;
        vertices[cv++] = _glyphPointers[cg]->topLeft;
        offset += 6;
    }

    // Bind our VBO
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    // Orphan the buffer (for speed)
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);
    // Upload the data
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());

    // Unbind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void SpriteBatch::createVertexArray() {

    // Generate the VAO if it isn't already generated
    glGenVertexArrays(1, &_vao);

    // Bind the VAO. All subsequent opengl calls will modify it's state.
    glBindVertexArray(_vao);

    //G enerate the VBO if it isn't already generated
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    //Tell opengl what attribute arrays we need
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3); // Light

    //This is the position attribute pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    //This is the color attribute pointer
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    //This is the UV attribute pointer
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
    //This is the light attribute pointer
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, light));

    glBindVertexArray(0);

}

void SpriteBatch::sortGlyphs() {

    switch (_sortType) {
        case GlyphSortType::BACK_TO_FRONT:
            std::stable_sort(_glyphPointers.begin(), _glyphPointers.end(), compareBackToFront);
            break;
        case GlyphSortType::FRONT_TO_BACK:
            std::stable_sort(_glyphPointers.begin(), _glyphPointers.end(), compareFrontToBack);
            break;
        case GlyphSortType::TEXTURE:
            std::stable_sort(_glyphPointers.begin(), _glyphPointers.end(), compareTexture);
            break;
    }
}

bool SpriteBatch::compareFrontToBack(Glyph* a, Glyph* b) {
    return (a->depth < b->depth);
}

bool SpriteBatch::compareBackToFront(Glyph* a, Glyph* b) {
    return (a->depth > b->depth);
}

bool SpriteBatch::compareTexture(Glyph* a, Glyph* b) {
    return (a->texture < b->texture);
}

}
