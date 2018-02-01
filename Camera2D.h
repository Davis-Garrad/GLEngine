#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace GLEngine {

	class Camera2D {

	public:
		Camera2D();
		~Camera2D();

		void update();
		void init(int screenWidth, int screenHeight);

		// Getters & Setters for position
		void setPosition(const glm::vec2 &newPos) { m_needsUpdate = true; m_position = newPos; }
		glm::vec2 getPosition() { return m_position; }

		// Getters & Setters for scale
		void setScale(const float &newScale) { m_needsUpdate = true; m_scale = newScale; }
		float getScale() { return m_scale; }

		glm::mat4 getCameraMatrix() { return m_cameraMatrix; }
		glm::vec2 convertScreenToWorld(glm::vec2 screenCoords);

		bool isBoxInView(const glm::vec2 &position, const glm::vec2 &dimensions);

	private:

		int m_screenWidth, m_screenHeight;

		bool m_needsUpdate;
		float m_scale; // Zoom factor (Mr. Sulu)

		glm::vec2 m_position; // Same type as GLSL use
		glm::mat4 m_cameraMatrix; // Mat4 is 4x4 matrix
		glm::mat4 m_orthoMatrix;


	};

}
