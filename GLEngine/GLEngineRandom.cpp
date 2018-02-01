#include "../GLEngine/GLEngineRandom.h"

#include <random>

namespace GLEngine {

	float GLEngineRandom::getRandomBetween(float minNum, float maxNum) {

		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<float> dist(minNum, maxNum);

		return dist(mt);

	}

}
