#include <GL/glew.h> // Include BEFORE GUI.h

#include "GUI.h"

#include <iostream>

#include <SDL2/SDL_timer.h>

bool GLEngine::GUI::m_inited = false;

void GLEngine::GUI::init(const std::string& resourceDirectory, unsigned int numContexts) {
	// Create first CEGUI_context_wrapper

	CEGUI_context_wrapper* primary_wrapper = new CEGUI_context_wrapper;

	if (!m_inited) {
		primary_wrapper->renderer = &CEGUI::OpenGL3Renderer::bootstrapSystem(); // We need to set up the primary one with bootstrapSystem to configure other things we won't be touching with other wrappers.
		m_inited = true;
	} else {
		primary_wrapper->renderer = static_cast<CEGUI::OpenGL3Renderer*>(CEGUI::System::getSingleton().getRenderer());
	}

	CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());
	rp->setResourceGroupDirectory("imagesets", resourceDirectory + "/imagesets/");
	rp->setResourceGroupDirectory("schemes", resourceDirectory + "/schemes/");
	rp->setResourceGroupDirectory("fonts", resourceDirectory + "/fonts/");
	rp->setResourceGroupDirectory("layouts", resourceDirectory + "/layouts/");
	rp->setResourceGroupDirectory("looknfeels", resourceDirectory + "/looknfeel/");
	rp->setResourceGroupDirectory("lua_scripts", resourceDirectory + "/lua_scripts/");

	CEGUI::ImageManager::setImagesetDefaultResourceGroup("imagesets");
	CEGUI::Scheme::setDefaultResourceGroup("schemes");
	CEGUI::Font::setDefaultResourceGroup("fonts");
	CEGUI::WidgetLookManager::setDefaultResourceGroup("looknfeels");
	CEGUI::WindowManager::setDefaultResourceGroup("layouts");
	CEGUI::ScriptModule::setDefaultResourceGroup("lua_scripts");

	primary_wrapper->context = &CEGUI::System::getSingleton().createGUIContext(primary_wrapper->renderer->getDefaultRenderTarget());
	primary_wrapper->root = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow", "root");
	primary_wrapper->root->setSize(CEGUI::USize(cegui_reldim(1.0f), cegui_reldim(1.0f)));
	primary_wrapper->root->setPosition(CEGUI::UVector2(cegui_reldim(0.0f), cegui_reldim(0.0f)));
	primary_wrapper->context->setRootWindow(primary_wrapper->root);

	m_contexts.push_back(primary_wrapper);

	for(unsigned int i = 1; i < numContexts; i++) {
		// Create the renderer
		CEGUI::OpenGL3Renderer* secondary_renderer = primary_wrapper->renderer;
		CEGUI::GUIContext* secondary_context = &CEGUI::System::getSingleton().createGUIContext(secondary_renderer->getDefaultRenderTarget());
		CEGUI::Window* secondary_root = CEGUI::WindowManager::getSingleton().createWindow("DefaultWindow", "secondary_root" + std::to_string(i-1));
		secondary_root->setSize(CEGUI::USize(cegui_reldim(1.0f), cegui_reldim(1.0f)));
		secondary_root->setPosition(CEGUI::UVector2(cegui_reldim(0.0f), cegui_reldim(0.0f)));

		secondary_context->setRootWindow(secondary_root);

		CEGUI_context_wrapper* secondary = new CEGUI_context_wrapper;
		secondary->context = secondary_context;
		secondary->renderer = secondary_renderer;
		secondary->root = secondary_root;

		m_contexts.push_back(secondary);
	}
}

void GLEngine::GUI::destroy() {
	for(unsigned int i = 0; i < m_contexts.size(); i++) CEGUI::System::getSingleton().destroyGUIContext(*m_contexts[i]->context);
	for(unsigned int i = 0; i < m_contexts.size(); i++) CEGUI::WindowManager::getSingleton().destroyWindow(m_contexts[i]->root);
	m_contexts.clear();
}

void GLEngine::GUI::draw() {
	glDisable(GL_DEPTH_TEST);
	m_contexts[m_activeContext]->renderer->beginRendering();
	m_contexts[m_activeContext]->context->draw();
	m_contexts[m_activeContext]->renderer->endRendering();
	// Clean up after CEGUI
	glBindVertexArray(0);
	glDisable(GL_SCISSOR_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void GLEngine::GUI::update() {
	unsigned int elapsed;
	if (m_lastTime == 0) {
		elapsed = 0;
		m_lastTime = SDL_GetTicks();
	} else {
		unsigned int nextTime = SDL_GetTicks();
		elapsed = nextTime - m_lastTime;
		m_lastTime = nextTime;
	}
	for(unsigned int i = 0; i < m_contexts.size(); i++) // We'll always want to update them all.
		m_contexts[i]->context->injectTimePulse((float)elapsed / 1000.0f);
}

void GLEngine::GUI::setActiveContext(unsigned int contextIndex) {
	if(contextIndex < m_contexts.size()) m_activeContext = contextIndex;
}

void GLEngine::GUI::setMouseCursor(const std::string& imageFile) {
	m_contexts[m_activeContext]->context->getMouseCursor().setDefaultImage(imageFile);
}

void GLEngine::GUI::showMouseCursor() {
	m_contexts[m_activeContext]->context->getMouseCursor().show();
}

void GLEngine::GUI::hideMouseCursor() {
	m_contexts[m_activeContext]->context->getMouseCursor().hide();
}

CEGUI::Key::Scan SDLKeyToCEGUIKey(SDL_Keycode key) {
	using namespace CEGUI;
	switch (key) {
		case SDLK_BACKSPACE:
			return Key::Backspace;
		case SDLK_TAB:
			return Key::Tab;
		case SDLK_RETURN:
			return Key::Return;
		case SDLK_PAUSE:
			return Key::Pause;
		case SDLK_ESCAPE:
			return Key::Escape;
		case SDLK_SPACE:
			return Key::Space;
		case SDLK_COMMA:
			return Key::Comma;
		case SDLK_MINUS:
			return Key::Minus;
		case SDLK_PERIOD:
			return Key::Period;
		case SDLK_SLASH:
			return Key::Slash;
		case SDLK_0:
			return Key::Zero;
		case SDLK_1:
			return Key::One;
		case SDLK_2:
			return Key::Two;
		case SDLK_3:
			return Key::Three;
		case SDLK_4:
			return Key::Four;
		case SDLK_5:
			return Key::Five;
		case SDLK_6:
			return Key::Six;
		case SDLK_7:
			return Key::Seven;
		case SDLK_8:
			return Key::Eight;
		case SDLK_9:
			return Key::Nine;
		case SDLK_COLON:
			return Key::Colon;
		case SDLK_SEMICOLON:
			return Key::Semicolon;
		case SDLK_EQUALS:
			return Key::Equals;
		case SDLK_LEFTBRACKET:
			return Key::LeftBracket;
		case SDLK_BACKSLASH:
			return Key::Backslash;
		case SDLK_RIGHTBRACKET:
			return Key::RightBracket;
		case SDLK_a:
			return Key::A;
		case SDLK_b:
			return Key::B;
		case SDLK_c:
			return Key::C;
		case SDLK_d:
			return Key::D;
		case SDLK_e:
			return Key::E;
		case SDLK_f:
			return Key::F;
		case SDLK_g:
			return Key::G;
		case SDLK_h:
			return Key::H;
		case SDLK_i:
			return Key::I;
		case SDLK_j:
			return Key::J;
		case SDLK_k:
			return Key::K;
		case SDLK_l:
			return Key::L;
		case SDLK_m:
			return Key::M;
		case SDLK_n:
			return Key::N;
		case SDLK_o:
			return Key::O;
		case SDLK_p:
			return Key::P;
		case SDLK_q:
			return Key::Q;
		case SDLK_r:
			return Key::R;
		case SDLK_s:
			return Key::S;
		case SDLK_t:
			return Key::T;
		case SDLK_u:
			return Key::U;
		case SDLK_v:
			return Key::V;
		case SDLK_w:
			return Key::W;
		case SDLK_x:
			return Key::X;
		case SDLK_y:
			return Key::Y;
		case SDLK_z:
			return Key::Z;
		case SDLK_DELETE:
			return Key::Delete;
		case SDLK_KP_PERIOD:
			return Key::Decimal;
		case SDLK_KP_DIVIDE:
			return Key::Divide;
		case SDLK_KP_MULTIPLY:
			return Key::Multiply;
		case SDLK_KP_MINUS:
			return Key::Subtract;
		case SDLK_KP_PLUS:
			return Key::Add;
		case SDLK_KP_ENTER:
			return Key::NumpadEnter;
		case SDLK_KP_EQUALS:
			return Key::NumpadEquals;
		case SDLK_UP:
			return Key::ArrowUp;
		case SDLK_DOWN:
			return Key::ArrowDown;
		case SDLK_RIGHT:
			return Key::ArrowRight;
		case SDLK_LEFT:
			return Key::ArrowLeft;
		case SDLK_INSERT:
			return Key::Insert;
		case SDLK_HOME:
			return Key::Home;
		case SDLK_END:
			return Key::End;
		case SDLK_PAGEUP:
			return Key::PageUp;
		case SDLK_PAGEDOWN:
			return Key::PageDown;
		case SDLK_F1:
			return Key::F1;
		case SDLK_F2:
			return Key::F2;
		case SDLK_F3:
			return Key::F3;
		case SDLK_F4:
			return Key::F4;
		case SDLK_F5:
			return Key::F5;
		case SDLK_F6:
			return Key::F6;
		case SDLK_F7:
			return Key::F7;
		case SDLK_F8:
			return Key::F8;
		case SDLK_F9:
			return Key::F9;
		case SDLK_F10:
			return Key::F10;
		case SDLK_F11:
			return Key::F11;
		case SDLK_F12:
			return Key::F12;
		case SDLK_F13:
			return Key::F13;
		case SDLK_F14:
			return Key::F14;
		case SDLK_F15:
			return Key::F15;
		case SDLK_RSHIFT:
			return Key::RightShift;
		case SDLK_LSHIFT:
			return Key::LeftShift;
		case SDLK_RCTRL:
			return Key::RightControl;
		case SDLK_LCTRL:
			return Key::LeftControl;
		case SDLK_RALT:
			return Key::RightAlt;
		case SDLK_LALT:
			return Key::LeftAlt;
		case SDLK_SYSREQ:
			return Key::SysRq;
		case SDLK_MENU:
			return Key::AppMenu;
		case SDLK_POWER:
			return Key::Power;
		default:
			return Key::Unknown;
	}
}

CEGUI::MouseButton SDLButtonToCEGUIButton(Uint8 sdlButton) {
	switch (sdlButton) {
		case SDL_BUTTON_LEFT:
			return CEGUI::MouseButton::LeftButton;
		case SDL_BUTTON_MIDDLE:
			return CEGUI::MouseButton::MiddleButton;
		case SDL_BUTTON_RIGHT:
			return CEGUI::MouseButton::RightButton;
		case SDL_BUTTON_X1:
			return CEGUI::MouseButton::X1Button;
		case SDL_BUTTON_X2:
			return CEGUI::MouseButton::X2Button;
	}
	return CEGUI::MouseButton::NoButton;
}

void GLEngine::GUI::onSDLEvent(SDL_Event& evnt) {
	for(unsigned int i = 0; i < m_contexts.size(); i++) {
		CEGUI::utf32 codePoint;
		switch (evnt.type) {
			case SDL_MOUSEMOTION:
				// m_contexts[i]->injectMouseMove(evnt.motion.xrel, evnt.motion.yrel);
				m_contexts[i]->context->injectMousePosition((float)evnt.motion.x, (float)evnt.motion.y);
				break;
			case SDL_KEYDOWN:
				m_contexts[i]->context->injectKeyDown(SDLKeyToCEGUIKey(evnt.key.keysym.sym));
				break;
			case SDL_KEYUP:
				m_contexts[i]->context->injectKeyUp(SDLKeyToCEGUIKey(evnt.key.keysym.sym));
				break;
			case SDL_TEXTINPUT:
				codePoint = 0;
				/// TODO: This is wrong! We need to decode utf-8 and convert to utf-32.
				// Thanks to Spartan190 for figuring this out. You need to get a utf conversion library
				// or function that can convert the text, such as from UTF8-CPP: http://utfcpp.sourceforge.net/
				// If you use UTF8-CPP just use this code and it should work:

				// std::string evntText = std::string(evnt.text.text);
				// std::vector<int> utf32result;
				// case SDL_TEXTINPUT:
				//   utf8::utf8to32(evnt.text.text, evnt.text.text + evntText.size(), std::back_inserter(utf32result));
				//   codePoint = (CEGUI::utf32)utf32result[0];
				//   m_contexts[i]->injectChar(codePoint);

				for (int i = 0; evnt.text.text[i] != '\0'; i++) {
					codePoint |= (((CEGUI::utf32 )*(unsigned char*)&evnt.text.text[i]) << (i * 8));
				}
				m_contexts[i]->context->injectChar(codePoint);
				break;
			case SDL_MOUSEBUTTONDOWN:
				m_contexts[i]->context->injectMouseButtonDown(SDLButtonToCEGUIButton(evnt.button.button));
				break;
			case SDL_MOUSEBUTTONUP:
				m_contexts[i]->context->injectMouseButtonUp(SDLButtonToCEGUIButton(evnt.button.button));
				break;
			case SDL_MOUSEWHEEL:
				m_contexts[i]->context->injectMouseWheelChange(evnt.wheel.y);
				break;
		}
	}
}

void GLEngine::GUI::loadScheme(const std::string& schemeFile) {
	CEGUI::SchemeManager::getSingleton().createFromFile(schemeFile);
}

CEGUI::Window* GLEngine::GUI::createWidget(const std::string& type, const glm::vec4& destRectPerc, const glm::vec4& destRectPix, const std::string& name /*= ""*/) {
	CEGUI::Window* newWindow = CEGUI::WindowManager::getSingleton().createWindow(type, name);
	m_contexts[m_activeContext]->root->addChild(newWindow);
	setWidgetDestRect(newWindow, destRectPerc, destRectPix);
	return newWindow;
}

CEGUI::Window* GLEngine::GUI::createWidget(CEGUI::Window* parent, const std::string& type, const glm::vec4& destRectPerc, const glm::vec4& destRectPix, const std::string& name /*= ""*/) {
	CEGUI::Window* newWindow = CEGUI::WindowManager::getSingleton().createWindow(type, name);
	parent->addChild(newWindow);
	setWidgetDestRect(newWindow, destRectPerc, destRectPix);
	return newWindow;
}

void GLEngine::GUI::setWidgetDestRect(CEGUI::Window* widget, const glm::vec4& destRectPerc, const glm::vec4& destRectPix) {
	widget->setPosition(CEGUI::UVector2(CEGUI::UDim(destRectPerc.x, destRectPix.x), CEGUI::UDim(destRectPerc.y, destRectPix.y)));
	widget->setSize(CEGUI::USize(CEGUI::UDim(destRectPerc.z, destRectPix.z), CEGUI::UDim(destRectPerc.w, destRectPix.w)));
}

void GLEngine::GUI::setFont(const std::string& fontFile) {
	CEGUI::FontManager::getSingleton().createFromFile(fontFile + ".font");
	for(unsigned int i = 0; i < m_contexts.size(); i++) m_contexts[i]->context->setDefaultFont(fontFile);
}
