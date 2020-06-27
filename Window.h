#pragma once
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

namespace GLEngine {

    enum WindowFlags { INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };

    class Window
    {
    public:
        Window();
        ~Window();

        int create(unsigned int currentFlags, bool debug = false);

        void setScreenTitle(std::string newTitle) { m_windowTitle = newTitle; }
        void setScreenSize(int width, int height) { _screenWidth = width; _screenHeight = height; }

        void swapBuffer();

        int getScreenWidth() { return _screenWidth; }
        int getScreenHeight() { return _screenHeight; }
    private:
        SDL_Window* _sdlWindow;
        SDL_GLContext m_glContext = nullptr;
        int _screenWidth, _screenHeight;
        std::string m_windowTitle;
    };

}
