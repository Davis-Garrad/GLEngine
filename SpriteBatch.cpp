#include "SpriteBatch.h"

#include <algorithm>

#include "GLEngineErrors.h"

namespace GLEngine {


    Glyph::Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint Texture, GLuint bumpMapTexture, float Depth, const ColourRGBA8& color, glm::vec4 light) :
        texture(Texture),
        bumpMap(bumpMapTexture),
        depth(Depth) {

        topLeft.color = color;
        topLeft.setPosition(destRect.x, destRect.y + destRect.w);
        topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);
        topLeft.setLight(light.x, light.y, light.z, light.w);

        bottomLeft.color = color;
        bottomLeft.setPosition(destRect.x, destRect.y);
        bottomLeft.setUV(uvRect.x, uvRect.y);
        bottomLeft.setLight(light.x, light.y, light.z, light.w);

        bottomRight.color = color;
        bottomRight.setPosition(destRect.x + destRect.z, destRect.y);
        bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);
        bottomRight.setLight(light.x, light.y, light.z, light.w);

        topRight.color = color;
        topRight.setPosition(destRect.x + destRect.z, destRect.y + destRect.w);
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
        topLeft.setPosition(destRect.x + tl.x, destRect.y + tl.y);
        topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);
        topLeft.setLight(light.x, light.y, light.z, light.w);

        bottomLeft.color = color;
        bottomLeft.setPosition(destRect.x + bl.x, destRect.y + bl.y);
        bottomLeft.setUV(uvRect.x, uvRect.y);
        bottomLeft.setLight(light.x, light.y, light.z, light.w);

        bottomRight.color = color;
        bottomRight.setPosition(destRect.x + br.x, destRect.y + br.y);
        bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);
        bottomRight.setLight(light.x, light.y, light.z, light.w);

        topRight.color = color;
        topRight.setPosition(destRect.x + tr.x, destRect.y + tr.y);
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
        topLeft.setPosition(destRect.x + tl.x, destRect.y + tl.y);
        topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);
        topLeft.setLight(light.x, light.y, light.z, light.w);

        bottomLeft.color = color;
        bottomLeft.setPosition(destRect.x + bl.x, destRect.y + bl.y);
        bottomLeft.setUV(uvRect.x, uvRect.y);
        bottomLeft.setLight(light.x, light.y, light.z, light.w);

        bottomRight.color = color;
        bottomRight.setPosition(destRect.x + br.x, destRect.y + br.y);
        bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);
        bottomRight.setLight(light.x, light.y, light.z, light.w);

        topRight.color = color;
        topRight.setPosition(destRect.x + tr.x, destRect.y + tr.y);
        topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);
        topRight.setLight(light.x, light.y, light.z, light.w);
    }

    glm::vec2 Glyph::rotatePoint(const glm::vec2& pos, float angle) {
        glm::vec2 newv;
        newv.x = pos.x * cos(angle) - pos.y * sin(angle);
        newv.y = pos.y * cos(angle) + pos.x * sin(angle);
        return newv;
    }

SpriteBatch::SpriteBatch() : _vbo(0), _vao(0)
{
}

SpriteBatch::~SpriteBatch()
{
}

void SpriteBatch::init() {
    createVertexArray();
}

void SpriteBatch::dispose() {
    if (_vao != 0) {
        glDeleteVertexArrays(1, &_vao);
        _vao = 0;
    }
    if (_vbo != 0) {
        glDeleteBuffers(1, &_vbo);
        _vbo = 0;
    }
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
        glBindTexture(GL_TEXTURE_2D, _renderBatches[i].texture);
        if(_renderBatches[i].bumpMap) {
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, _renderBatches[i].bumpMap);
            glActiveTexture(GL_TEXTURE0);
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

void SpriteBatch::createFramebuffer() {
    // Generate the FBO if it isn't already.
    if(m_fbo == 0) {
        glGenFramebuffers(1 ,&m_fbo);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);

    glGenTextures(1, &m_fboTexture);
    glBindTexture(GL_TEXTURE_2D, m_fboTexture);

    // Get window size
    GLint winSize[4]; // x, y, w, h
    glGetIntegerv(GL_VIEWPORT, winSize);

    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, winSize[2], winSize[3], 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);

    // Filtering operations (minimization and magnification)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

                                                                        /// DEPTH BUFFER?

    // Attach the texture:
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_fboTexture, 0);

    // Set list of draw buffers (where data will be "drawn" to):
    GLenum drawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers(1, drawBuffers);

    // Check that everything is good
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        fatalError("Framebuffer could not be created!");
    }
}

void SpriteBatch::createVertexArray() {

    // Generate the VAO if it isn't already generated
    if (_vao == 0) {
        glGenVertexArrays(1, &_vao);
    }

    // Bind the VAO. All subsequent opengl calls will modify it's state.
    glBindVertexArray(_vao);

    //G enerate the VBO if it isn't already generated
    if (_vbo == 0) {
        glGenBuffers(1, &_vbo);
    }
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    //Tell opengl what attribute arrays we need
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3); // Light
    glEnableVertexAttribArray(4); // Depthmap

    //This is the position attribute pointer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    //This is the color attribute pointer
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    //This is the UV attribute pointer
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
    //This is the light attribute pointer
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, light));
    //This is the depthmap attribute pointer
    glVertexAttribPointer(4, 1, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, depth));

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
