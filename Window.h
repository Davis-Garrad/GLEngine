#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

namespace GLEngine {

	enum WindowFlags {

		FULLSCREEN = SDL_WINDOW_FULLSCREEN_DESKTOP, INVISIBLE = SDL_WINDOW_HIDDEN, BORDERLESS = SDL_WINDOW_BORDERLESS

	};

	class Window {
		public:
			Window();
			~Window();

			int createWin(std::string WindowName, int width, int height, unsigned int flags);
			void swapBuffer(int pad);

			int getScreenWidth() {
				return m_width;
			}
			int getScreenHeight() {
				return m_height;
			}

		private:
			SDL_Window *m_window;
			int m_width, m_height;

	};

}
