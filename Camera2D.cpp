#include "Camera2D.h"

#include "Physics.h"
#include <iostream>

namespace GLEngine {

	Camera2D::Camera2D() : m_screenWidth(0), m_screenHeight(0), m_needsUpdate(true), m_scale(1.0f),  m_position(0.0f, 0.0f), m_cameraMatrix(1.0f), m_orthoMatrix(1.0f) {



	}

	Camera2D::~Camera2D() {

	}

	void Camera2D::init(int screenWidth, int screenHeight) {

		m_screenWidth = screenWidth;
		m_screenHeight = screenHeight;
		m_orthoMatrix = glm::ortho(0.0f, (float) m_screenWidth, 0.0f, (float) m_screenHeight);

	}

	void Camera2D::update() {

		if(m_needsUpdate) {

			glm::vec3 translateVec(-m_position.x + m_screenWidth / 2, -m_position.y + m_screenHeight / 2, 0.0f);
			m_cameraMatrix = glm::translate(m_orthoMatrix, translateVec);

			glm::vec3 scaleVec(m_scale, m_scale, 0.0f);
			m_cameraMatrix = glm::scale(glm::mat4(1.0f), scaleVec) * m_cameraMatrix;

			m_needsUpdate = false;

		}

	}

	glm::vec2 Camera2D::convertScreenToWorld(glm::vec2 screenCoords) {

		// Invert the Y coord
		screenCoords.y = m_screenHeight - screenCoords.y;

		screenCoords -= glm::vec2(m_screenWidth/2, m_screenHeight/2);
		screenCoords /= m_scale;
		screenCoords += m_position;

		return screenCoords;

	}

	bool Camera2D::isBoxInView(const glm::vec2 &position, const glm::vec2 &dimensions) {

		if(GLEngine::Physics::rectCollision(glm::vec4 (m_position.x - m_screenWidth / 2,  m_position.y - m_screenHeight / 2, m_screenWidth, m_screenHeight), glm::vec4 (position.x, position.y, dimensions.x, dimensions.y))) {
			return true;
		}
		return false;

	}

}
