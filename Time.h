#pragma once

namespace GLEngine {
	
	class Timer {
		public:
			Timer() {
			}
			~Timer() {
			}
			void beginTimer();
			float getTime();
			void endTimer();
			bool started = false;
		private:
			float m_startTime = 0.0f;
	};

}
