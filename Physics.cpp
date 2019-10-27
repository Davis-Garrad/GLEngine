#include "Physics.h"

#include <cmath>

namespace GLEngine {

	bool Physics::circleCollision(glm::vec2 colliderPos, glm::vec2 targetPos, float colliderWidth) {

		float distance = glm::distance(colliderPos, targetPos);
		float width = colliderWidth;

		if (width > distance) {
			return true;
		}
		return false;

	}

	bool Physics::rectCollision(glm::vec4 posAndSizeRect1, glm::vec4 target) {

		glm::vec2 pos1(posAndSizeRect1.x, posAndSizeRect1.y);
		glm::vec2 pos2(target.x, target.y);
		glm::vec2 size1(posAndSizeRect1.z, posAndSizeRect1.w);
		glm::vec2 size2(target.z, target.w);

		if ((pos1.x + size1.x > pos2.x) && (pos1.x < pos2.x + size2.x)) {
			if ((pos1.y + size1.y > pos2.y) && (pos1.y < pos2.y + size2.y)) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	bool Physics::lineAndRectCollision(glm::vec4 posAndSizeRect, glm::vec2 linePoint1, glm::vec2 linePoint2) {

		glm::vec2 pos1(posAndSizeRect.x, posAndSizeRect.y);
		glm::vec2 pos2(linePoint1.x, linePoint1.y);
		glm::vec2 size1(posAndSizeRect.z, posAndSizeRect.w);
		glm::vec2 size2(linePoint2.x - linePoint1.x, linePoint2.y - linePoint1.x);

		if ((pos1.x + size1.x > pos2.x) && (pos1.x < pos2.x + size2.x)) {
			if ((pos1.y + size1.y > pos2.y) && (pos1.y < pos2.y + size2.y)) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}

		return false;

	}

}
