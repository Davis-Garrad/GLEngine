#pragma once

namespace GLEngine {

	class FPSLimiter {

		public:
			FPSLimiter();
			void init(float maxFPS);

			void setMaxFPS(float maxFPS);

			void begin();
			float end(); // returns FPS

		private:

			void calculateFPS();

			unsigned int m_startTicks;
			float m_maxFPS;
			float m_fps;
			float m_frameTime;

	};

}
