#include "Sprite.h"
#include "Vertex.h"
#include <iostream>
#include <cstddef>
#include "ResourceManager.h"
#include "Vertex.h"

namespace GLEngine {
	
	Sprite::Sprite() :
			m_x(0), m_y(0), m_width(0), m_height(0), m_vboID(0) {

	}
	
	Sprite::~Sprite() {

		if (m_vboID != 0) {
			glDeleteBuffers(1, &m_vboID);
		}

	}
	
	void Sprite::draw() {

		glBindTexture(GL_TEXTURE_2D, m_texture.id);

		glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}
	
	void Sprite::init(float x, float y, float width, float height, std::string texturePath) {

		m_x = x;
		m_y = y;
		m_width = width;
		m_height = height;

		m_texture = ResourceManager::getTexture(texturePath);

		if (m_vboID == 0) {
			glGenBuffers(1, &m_vboID);
		}

		Vertex vertexData[6]; //6 vertices * 2 data (x and y)

		// First Triangle
		vertexData[0].setPosition(x + width, y + height);	// Top Right
		vertexData[0].setUV(1.0f, 1.0f);
		vertexData[1].setPosition(x, y + height); 			// Top Left
		vertexData[1].setUV(0.0f, 1.0f);
		vertexData[2].setPosition(x, y); 					// Bottom Left
		vertexData[2].setUV(0.0f, 0.0f);

		// Second Triangle
		vertexData[3].setPosition(x, y);					// Bottom Left
		vertexData[3].setUV(0.0f, 0.0f);
		vertexData[4].setPosition(x + width, y);			// Bottom Right
		vertexData[4].setUV(1.0f, 0.0f);
		vertexData[5].setPosition(x + width, y + height);	// Top Right
		vertexData[5].setUV(1.0f, 1.0f);

		for (int i = 0; i < 6; i++) {
			vertexData[i].setColour(255, 255, 255, 255);
		}

		glBindBuffer(GL_ARRAY_BUFFER, m_vboID);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}

}
