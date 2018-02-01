#include "Window.h"

#include "GLEngineErrors.h"
#include <iostream>

namespace GLEngine {

	Window::Window() :
			m_window(nullptr), m_width(0), m_height(0) {

	}
	
	Window::~Window() {
		delete(m_window);
	}

	int Window::createWin(std::string WindowName, int width, int height, unsigned int currentFlags) {

		m_width = width;
		m_height = height;

		Uint32 uIntFlags = currentFlags;

		uIntFlags |= currentFlags;

		m_window = SDL_CreateWindow(WindowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, uIntFlags | SDL_WINDOW_OPENGL);

		if (m_window == nullptr) {
			fatalError("Could not initialize SDL window.");
		}

		// Start creating an OpenGL Context

		SDL_GLContext glContext = SDL_GL_CreateContext(m_window);

		if (glContext == nullptr) {
			fatalError("GL Context could not be created.");
		}

		//Initializing GLEW
		GLenum error = glewInit();

		if (error != GLEW_OK) {
			fatalError("Could not initialize GLEW.");
		}

		// Check and print the OpenGL version
		printf("\n\n*** OpenGL Version: %s***\n\n", glGetString(GL_VERSION));

		//Set background colour
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

		SDL_GL_SetSwapInterval(0); // Set to 1 to avoid screen tearing with VSync

		//Enable alpha blending
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		return 0;

	}

	void Window::swapBuffer(int pad) {

		//Switching Buffer
		SDL_GL_SwapWindow(m_window);

	}

}
