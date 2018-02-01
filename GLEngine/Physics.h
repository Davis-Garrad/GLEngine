#pragma once

#include <glm/glm.hpp>

namespace GLEngine {
	
	class Physics {
		public:
			static bool circleCollision(glm::vec2 colliderPos, glm::vec2 targetPos, float colliderWidth);
			static bool rectCollision(glm::vec4 posAndSizeRect1, glm::vec4 target);
			static bool lineAndRectCollision(glm::vec4 posAndSizeRect, glm::vec2 linePoint1, glm::vec2 linePoint2);
	};

}
