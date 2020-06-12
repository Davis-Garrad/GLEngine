#include "Window.h"
#include "GLEngineErrors.h"

#include <iostream>
#include <SDL2/SDL_video.h>

namespace GLEngine {

    Window::Window()
    {
    }


    Window::~Window()
    {
    }

    int Window::create(unsigned int currentFlags) {

        Uint32 flags = SDL_WINDOW_OPENGL;

        if (currentFlags & INVISIBLE) {
            flags |= SDL_WINDOW_HIDDEN;
        }
        if (currentFlags & FULLSCREEN) {
            flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
        }
        if (currentFlags & BORDERLESS) {
            flags |= SDL_WINDOW_BORDERLESS;
        }


        // Set SDL Attributes
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3.2); // Sets the OpenGL context attribute (minimum version) to 3.2
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4.5); // Sets the OpenGL context attribute (maximum version) to 4.5
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // Set the OpenGL context to be the core version
        //SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1); // So we can share contexts (between threads) Dont do this its very bad and doesnt work

        _sdlWindow = SDL_CreateWindow(m_windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, flags);
        if (_sdlWindow == nullptr) {
            std::string errCode = "SDL Window could not be created! SDL Throws Error:\n" + std::string(SDL_GetError());
            fatalError(errCode);
        }

        glewExperimental = GL_TRUE; // Make sure we can use experimental drivers and features, such as making a core context

        //Set up our OpenGL context
        m_glContext = SDL_GL_CreateContext(_sdlWindow);
        if (m_glContext == nullptr) {
            std::string errCode = "SDL_GL context could not be created! SDL Throws Error:\n" + std::string(SDL_GetError());
            fatalError(errCode);
        }

        //Set up glew (optional but recommended)
        GLenum error = glewInit();
        if (error != GLEW_OK) {
            fatalError("Could not initialize glew!");
        }

        //Check the OpenGL version
        std::printf("***   OpenGL Version: %s   ***\n", glGetString(GL_VERSION));

        //Set the background color to blue
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

        //Set VSYNC
        SDL_GL_SetSwapInterval(0);

        // Enable alpha blend
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        return 0;
    }

    void Window::swapBuffer() {
        SDL_GL_SwapWindow(_sdlWindow);
    }

}
