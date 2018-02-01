#pragma once

#include <unordered_map>
#include <glm/glm.hpp>

namespace GLEngine {
	
	class InputManager {
		public:
			InputManager();
			~InputManager();

			void update();
			void pressKey(unsigned int keyID);
			void releaseKey(unsigned int keyID);
			void setMouseCoords(int x, int y);
			bool isKeyDown(unsigned int keyID);
			bool isKeyPressed(unsigned int keyID); // returns true if the target key was pressed in the current frame
			glm::vec2 getMouseCoords();

		private:

			bool wasKeyDown(unsigned int keyID);

			std::unordered_map<unsigned int, bool> m_keyMap;
			std::unordered_map<unsigned int, bool> m_previousKeyMap;
			glm::vec2 m_mouseCoords;

	};

}
