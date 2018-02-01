#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

#include "Vertex.h"

namespace GLEngine {
	
	enum class GlyphSortType {

		NONE, FRONT_TO_BACK, BACK_TO_FRONT, TEXTURE

	};

	class Glyph {

		public:

			Glyph() {}
			Glyph(const glm::vec4 &destRect, const glm::vec4 &uvRect, GLuint textureP, const ColourRGBA8 &colour, float depthP);
			Glyph(const glm::vec4 &destRect, const glm::vec4 &uvRect, GLuint textureP, const ColourRGBA8 &colour, float depthP, float angle);

			Vertex topLeft;
			Vertex bottomLeft;
			Vertex topRight;
			Vertex bottomRight;

			GLuint texture;

			float depth;

		private:
			glm::vec2 rotatePoint(glm::vec2 point, float angle);

	};

	class RenderBatch {

		public:
			RenderBatch(GLuint Offset, GLuint NumVertices, GLuint Texture) :
					offset(Offset), numVertices(NumVertices), texture(Texture) {
			}

			GLuint offset;
			GLuint numVertices;
			GLuint texture;

	};

	class SpriteBatch {
		public:
			SpriteBatch();
			~SpriteBatch();

			void begin(GlyphSortType sortType = GlyphSortType::TEXTURE);
			void end();

			void draw(const glm::vec4 &destRect, const glm::vec4 &uvRect, GLuint texture, const ColourRGBA8 &colour, float depth); // destRect = Position + Dimensions, uvRect = UV Position + Dimensions
			void draw(const glm::vec4 &destRect, const glm::vec4 &uvRect, GLuint texture, const ColourRGBA8 &colour, float depth, float angle);
			void draw(const glm::vec4 &destRect, const glm::vec4 &uvRect, GLuint texture, const ColourRGBA8 &colour, float depth, const glm::vec2 dir);
			void createRenderBatches();
			void renderBatch();

			void init();

			void createVertexArray();

			void sortGlyphs();

		private:
			GLuint m_vbo;
			GLuint m_vao;
			std::vector<Glyph*> m_glyphPointers;
			std::vector<Glyph> m_glyphs;
			GlyphSortType m_sortType;
			std::vector<RenderBatch> m_renderBatches;

			static bool compareFrontToBack(Glyph* a, Glyph* b);
			static bool compareBackToFront(Glyph* a, Glyph* b);
			static bool compareTexture(Glyph* a, Glyph* b);

	};

}
