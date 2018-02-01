#include "SpriteBatch.h"

#include <algorithm>
#include <iostream>

namespace GLEngine {
	
	Glyph::Glyph(const glm::vec4 &destRect, const glm::vec4 &uvRect, GLuint textureP, const ColourRGBA8 &colour, float depthP) :
			texture(textureP), depth(depthP) {
		topRight.colour = colour;
		topRight.setPosition(destRect.x + destRect.z, destRect.y + destRect.w);
		topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);

		topLeft.colour = colour;
		topLeft.setPosition(destRect.x, destRect.y + destRect.w);
		topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);

		bottomLeft.colour = colour;
		bottomLeft.setPosition(destRect.x, destRect.y);
		bottomLeft.setUV(uvRect.x, uvRect.y);

		bottomRight.colour = colour;
		bottomRight.setPosition(destRect.x + destRect.z, destRect.y);
		bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);
	}

	Glyph::Glyph(const glm::vec4 &destRect, const glm::vec4 &uvRect, GLuint textureP, const ColourRGBA8 &colour, float depthP, float angle) :
			texture(textureP), depth(depthP) {

		glm::vec2 halfDims(destRect.z / 2.0f, destRect.w / 2.0f);

		glm::vec2 TL(-halfDims.x, halfDims.y);
		glm::vec2 BL(-halfDims.x, -halfDims.y);
		glm::vec2 TR(halfDims.x, halfDims.y);
		glm::vec2 BR(halfDims.x, -halfDims.y);

		TL = rotatePoint(TL, angle) + halfDims;
		BL = rotatePoint(BL, angle) + halfDims;
		TR = rotatePoint(TR, angle) + halfDims;
		BR = rotatePoint(BR, angle) + halfDims;

		topRight.colour = colour;
		topRight.setPosition(destRect.x + TR.x, destRect.y + TR.y);
		topRight.setUV(uvRect.x + uvRect.z, uvRect.y + uvRect.w);

		topLeft.colour = colour;
		topLeft.setPosition(destRect.x + TL.x, destRect.y + TL.y);
		topLeft.setUV(uvRect.x, uvRect.y + uvRect.w);

		bottomLeft.colour = colour;
		bottomLeft.setPosition(destRect.x + BL.x, destRect.y + BL.y);
		bottomLeft.setUV(uvRect.x, uvRect.y);

		bottomRight.colour = colour;
		bottomRight.setPosition(destRect.x + BR.x, destRect.y + BR.y);
		bottomRight.setUV(uvRect.x + uvRect.z, uvRect.y);
	}

	glm::vec2 Glyph::rotatePoint(glm::vec2 point, float angle) {
		glm::vec2 newV;

		newV.x = point.x * cos(angle) - point.y * sin(angle);
		newV.y = point.x * sin(angle) + point.y * cos(angle);

		return newV;
	}

	SpriteBatch::SpriteBatch() :
			m_vbo(0), m_vao(0), m_sortType(GlyphSortType::NONE) {
		
	}
	
	SpriteBatch::~SpriteBatch() {

	}

	void SpriteBatch::begin(GlyphSortType sortType/* = GlyphSortType::TEXTURE*/) {
		m_sortType = sortType;
		m_renderBatches.clear();
		m_glyphs.clear();
	}

	void SpriteBatch::end() {
		m_glyphPointers.resize(m_glyphs.size());
		for (unsigned int i = 0; i < m_glyphPointers.size(); i++) {
			// To set up pointers for faster sorting
			m_glyphPointers[i] = &m_glyphs[i];
		}
		sortGlyphs();
		createRenderBatches();
	}

	void SpriteBatch::draw(const glm::vec4 &destRect, const glm::vec4 &uvRect, GLuint texture, const ColourRGBA8 &colour, float depth) {
		m_glyphs.emplace_back(Glyph(destRect, uvRect, texture, colour, depth));
	}

	void SpriteBatch::draw(const glm::vec4 &destRect, const glm::vec4 &uvRect, GLuint texture, const ColourRGBA8 &colour, float depth, float angle) {
		m_glyphs.emplace_back(Glyph(destRect, uvRect, texture, colour, depth, angle));
	}

	void SpriteBatch::draw(const glm::vec4 &destRect, const glm::vec4 &uvRect, GLuint texture, const ColourRGBA8 &colour, float depth, const glm::vec2 dir) {
		const glm::vec2 up(0.0f, 1.0f);
		float angle = acos(glm::dot(dir, up));
		if(dir.x < 0.0f) {
			angle = -angle;
		}
		m_glyphs.emplace_back(Glyph(destRect, uvRect, texture, colour, depth, -angle));
	}

	void SpriteBatch::createRenderBatches() {

		std::vector<Vertex> vertices;

		vertices.resize(m_glyphs.size() * 6);

		if (m_glyphs.empty()) {
			return;
		}

		int offset = 0;
		int curVer = 0; // Current Vertex
		m_renderBatches.push_back(RenderBatch(offset, 6, m_glyphPointers[0]->texture));

		vertices[curVer++] = m_glyphPointers[0]->topRight;
		vertices[curVer++] = m_glyphPointers[0]->topLeft;
		vertices[curVer++] = m_glyphPointers[0]->bottomLeft;

		vertices[curVer++] = m_glyphPointers[0]->bottomLeft;
		vertices[curVer++] = m_glyphPointers[0]->bottomRight;
		vertices[curVer++] = m_glyphPointers[0]->topRight;

		offset += 6;

		for (unsigned int curGly = 1; curGly < m_glyphPointers.size(); curGly++) { // Current Glyph

			if (m_glyphPointers[curGly]->texture != m_glyphPointers[curGly - 1]->texture) {
				m_renderBatches.push_back(RenderBatch(offset, 6, m_glyphPointers[curGly]->texture));
			} else {
				m_renderBatches.back().numVertices += 6;
			}

			vertices[curVer++] = m_glyphPointers[curGly]->topRight;
			vertices[curVer++] = m_glyphPointers[curGly]->topLeft;
			vertices[curVer++] = m_glyphPointers[curGly]->bottomLeft;

			vertices[curVer++] = m_glyphPointers[curGly]->bottomLeft;
			vertices[curVer++] = m_glyphPointers[curGly]->bottomRight;
			vertices[curVer++] = m_glyphPointers[curGly]->topRight;
			offset += 6;

		}

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW); //"Orphan the buffer"
		// Upload the data
		glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}

	void SpriteBatch::renderBatch() {

		glBindVertexArray(m_vao);

		for (unsigned int i = 0; i < m_renderBatches.size(); i++) {
			glBindTexture(GL_TEXTURE_2D, m_renderBatches[i].texture);

			glDrawArrays(GL_TRIANGLES, m_renderBatches[i].offset, m_renderBatches[i].numVertices);

		}

		glBindVertexArray(0);

	}

	void SpriteBatch::init() {

		createVertexArray();

	}

	void SpriteBatch::createVertexArray() {

		if (m_vao == 0) {
			glGenVertexArrays(1, &m_vao);
		}

		glBindVertexArray(m_vao);

		if (m_vbo == 0) {
			glGenBuffers(1, &m_vbo);
		}

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		//Position attrib pointer
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, position));
		//Colour attrib pointer
		glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*) offsetof(Vertex, colour));
		// Uv attrib pointer
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, uv));

		glBindVertexArray(0);

	}

	void SpriteBatch::sortGlyphs() {

		switch (m_sortType) {

			case GlyphSortType::NONE:
				break;

			case GlyphSortType::BACK_TO_FRONT:
				std::stable_sort(m_glyphPointers.begin(), m_glyphPointers.end(), compareBackToFront);
				break;

			case GlyphSortType::FRONT_TO_BACK:
				std::stable_sort(m_glyphPointers.begin(), m_glyphPointers.end(), compareFrontToBack);
				break;

			case GlyphSortType::TEXTURE:
				std::stable_sort(m_glyphPointers.begin(), m_glyphPointers.end(), compareTexture);
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
