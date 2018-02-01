#include "Timing.h"

#include <SDL2/SDL.h>
#include <iostream>

namespace GLEngine {




	FPSLimiter::FPSLimiter() :
			m_startTicks(0.0f), m_maxFPS(60.0f), m_fps(0.0f), m_frameTime(0.0f) {

	}

	void FPSLimiter::init(float maxFPS) {
		setMaxFPS(maxFPS);
	}

	void FPSLimiter::setMaxFPS(float maxFPS) {
		m_maxFPS = maxFPS;
	}

	void FPSLimiter::begin() {

		m_startTicks = SDL_GetTicks();

	}

	float FPSLimiter::end() {

		calculateFPS();

		float frameTicks = SDL_GetTicks() - m_startTicks;

		// Limit the fps to m_maxFPS

		if (1000.0f / m_maxFPS > frameTicks) {
			SDL_Delay(1000.0f / m_maxFPS - frameTicks);
		}

		return m_fps;
	}

	void FPSLimiter::calculateFPS() {

		static const int NUMm_SAMPLES = 20;
		static float frameTimes[NUMm_SAMPLES];

		static float previousTicks = SDL_GetTicks();
		float currentTicks;

		currentTicks = SDL_GetTicks();

		m_frameTime = currentTicks - previousTicks;

		static int currentFrame = 0;

		frameTimes[currentFrame % NUMm_SAMPLES] = m_frameTime;

		previousTicks = currentTicks;

		int count;
		currentFrame++;

		if (currentFrame < NUMm_SAMPLES) {

			count = currentFrame;

		} else {

			count = NUMm_SAMPLES;

		}

		float frameTimeAverage = 0;

		for (int i = 0; i < count; i++) {

			frameTimeAverage += frameTimes[i];

		}

		frameTimeAverage /= count;

		if (frameTimeAverage > 0) {

			m_fps = 1000.0f / frameTimeAverage;

		} else {

			m_fps = 666.666f;

		}

	}
}
