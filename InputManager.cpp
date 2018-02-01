#include "InputManager.h"

namespace GLEngine {
	
	InputManager::InputManager() : m_mouseCoords(0) {
		
	}
	
	InputManager::~InputManager() {

	}

	void InputManager::update() {
		for(auto &it: m_keyMap) {
			m_previousKeyMap[it.first] = it.second;
		}

	}

	void InputManager::pressKey(unsigned int keyID) {

		m_keyMap[keyID] = true;

	}

	void InputManager::releaseKey(unsigned int keyID) {

		m_keyMap[keyID] = false;

	}

	bool InputManager::isKeyDown(unsigned int keyID) {

		auto it = m_keyMap.find(keyID);
		if (it != m_keyMap.end()) {
			return it->second;
		}
		return false;

	}

	bool InputManager::wasKeyDown(unsigned int keyID) {

			auto it = m_previousKeyMap.find(keyID);
			if (it != m_previousKeyMap.end()) {
				return it->second;
			}
			return false;

		}

	bool InputManager::isKeyPressed(unsigned int keyID) {
		if(isKeyDown(keyID)) {
			if(!wasKeyDown(keyID)) {
				return true;
			}
		}
		return false;

	}

	void InputManager::setMouseCoords(int x, int y) {

		m_mouseCoords.x = x;
		m_mouseCoords.y = y;

	}

	glm::vec2 InputManager::getMouseCoords() {
		return m_mouseCoords;
	}

}
