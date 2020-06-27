#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

#include "Vertex.h"

namespace GLEngine {

// Determines how we should sort the glyphs
	enum class GlyphSortType {
		NONE,
		FRONT_TO_BACK, // Lower numbers farther back
		BACK_TO_FRONT, // Lower numbers further forward
		TEXTURE
	};

// A glyph is a single quad. These are added via SpriteBatch::draw
	class Glyph {
		public:
			Glyph() {};
			Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint Texture, GLuint bumpMapTexture, float Depth, const ColourRGBA8& color, glm::vec4 light);
			Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint Texture, GLuint bumpMapTexture, float Depth, const ColourRGBA8& color, float angle, glm::vec4 light);
			Glyph(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint Texture, GLuint bumpMapTexture, float Depth, const ColourRGBA8& color, float angle, glm::vec4 light, const glm::vec2& pointOfRotation);

			GLuint bumpMap;
			GLuint texture;
			float depth;

			Vertex topLeft;
			Vertex bottomLeft;
			Vertex topRight;
			Vertex bottomRight;
		private:
			// Rotates a point about (0,0) by angle
			glm::vec2 rotatePoint(const glm::vec2& pos, float angle);
	};

// Each render batch is used for a single draw call
	class RenderBatch {
		public:
			RenderBatch(GLuint Offset, GLuint NumVertices, GLuint Texture, GLuint bumpMapTexture) : offset(Offset),
				numVertices(NumVertices), texture(Texture), bumpMap(bumpMapTexture) {
			}
			GLuint offset;
			GLuint numVertices;
			GLuint texture;
			GLuint bumpMap;
	};

	void GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
	                            GLenum severity, GLsizei length,
	                            const GLchar *msg, const void *data);

	class FrameBufferObject {
			/*
			    The FrameBufferObject (FBO) class handles all OpenGL operations required for creating, writing to, and drawing FBOs.
			*/
		public:
			FrameBufferObject();
			~FrameBufferObject();

			// Initializes/disposes of the FBO object
			void init(glm::vec4 destRect);
			void dispose();

			void clear(); // glClear buffers and colour.
			void begin(); // Bind FBO
			void end(); // Unbind FBO

			void draw(); // Draws the FBO to the screen. Needs a shader surrounding it.

		private:
			void createFramebuffer(); // No need to worry, this calls createTextures.
			void createTextures();
			// Generates our VAO and VBO
			void createVertexArray();

			GLuint m_fbo;
			GLuint m_colourTex;
			GLuint m_depthTex;

			GLuint m_vbo;
			GLuint m_vao;

			glm::vec4 m_destRect; // Viewport.
	};

// The SpriteBatch class is a more efficient way of drawing sprites
	class SpriteBatch {
		public:
			SpriteBatch();
			~SpriteBatch();

			// Initializes the spritebatch
			void init();
			void dispose();

			// Begins the spritebatch
			void begin(GlyphSortType sortType = GlyphSortType::FRONT_TO_BACK);

			// Ends the spritebatch
			void end();

			// Adds a glyph to the spritebatch
			void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, GLuint bumpMapTexture, float depth, const ColourRGBA8& color, glm::vec4 verticesLight = glm::vec4(1.0f));
			// Adds a glyph to the spritebatch with rotation
			void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, GLuint bumpMapTexture, float depth, const ColourRGBA8& color, float angle, glm::vec4 verticesLight = glm::vec4(1.0f), const glm::vec2& pointOfRotation = glm::vec2(0.0f));
			// Adds a glyph to the spritebatch with rotation
			void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, GLuint bumpMapTexture, float depth, const ColourRGBA8& color, const glm::vec2& dir, glm::vec4 verticesLight = glm::vec4(1.0f), const glm::vec2& pointOfRotation = glm::vec2(0.0f));

			// Renders the entire SpriteBatch to the screen (regular way)
			void renderBatch();

		private:
			// Creates all the needed RenderBatches
			void createRenderBatches();

			// Generates our VAO and VBO
			void createVertexArray();

			// Sorts glyphs according to _sortType
			void sortGlyphs();

			// Comparators used by sortGlyphs()
			static bool compareFrontToBack(Glyph* a, Glyph* b);
			static bool compareBackToFront(Glyph* a, Glyph* b);
			static bool compareTexture(Glyph* a, Glyph* b);

			GLuint _vbo;
			GLuint _vao;

			GlyphSortType _sortType;

			std::vector<Glyph*> _glyphPointers; ///< This is for sorting
			std::vector<Glyph> _glyphs; ///< These are the actual glyphs
			std::vector<RenderBatch> _renderBatches;
	};

}
