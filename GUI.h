#pragma once

#include <GL/glew.h>
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GL3Renderer.h>
#include <glm/glm.hpp>
#include <SDL2/SDL_events.h>

struct CEGUI_context_wrapper {
	CEGUI::OpenGL3Renderer* renderer = nullptr;
	CEGUI::GUIContext* context = nullptr;
	CEGUI::Window* root = nullptr;
};

namespace GLEngine {
	class GUI {
		public:
			void init(const std::string& resourceDirectory, unsigned int numContexts);
			void destroy();

			void draw();
			void update();

			void setActiveContext(unsigned int contextIndex); // This just sets the active context ID. If that context doesn't exist, it does nothing.

			void setMouseCursor(const std::string& imageFile);
			void showMouseCursor();
			void hideMouseCursor();

			void onSDLEvent(SDL_Event& evnt);

			void loadScheme(const std::string& schemeFile);
			void setFont(const std::string& fontFile);
			CEGUI::Window* createWidget(const std::string& type, const glm::vec4& destRectPerc, const glm::vec4& destRectPix, const std::string& name = "");
			CEGUI::Window* createWidget(CEGUI::Window* parent, const std::string& type, const glm::vec4& destRectPerc, const glm::vec4& destRectPix, const std::string& name = "");
			static void setWidgetDestRect(CEGUI::Window* widget, const glm::vec4& destRectPerc, const glm::vec4& destRectPix);

			// Getters
			CEGUI::OpenGL3Renderer* getRenderer() {
				return m_contexts[m_activeContext]->renderer;
			}
			const CEGUI::GUIContext* getContext() {
				return m_contexts[m_activeContext]->context;
			}
		private:
			static bool m_inited;

			std::vector<CEGUI_context_wrapper*> m_contexts;
			unsigned int m_lastTime = 0;
			unsigned int m_activeContext = 0;
	};
}
