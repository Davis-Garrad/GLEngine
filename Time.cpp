#include "Time.h"

#include <SDL2/SDL.h>

namespace GLEngine {
	
	void Timer::beginTimer() {
		m_startTime = SDL_GetTicks();
		started = true;
	}

	float Timer::getTime() {

		float time = SDL_GetTicks() - m_startTime;

		return time;
	}

	void Timer::endTimer() {
		m_startTime = 0.0f;
		started = false;
	}

}
