#pragma once

#include <GL/glew.h>
#include <string>

#include "GLTexture.h"

namespace GLEngine {

	class Sprite {

		public:
			Sprite();
			~Sprite();
			void draw();
			void init(float x, float y, float width, float height, std::string texturePath);

		private:
			float m_x;
			float m_y;
			float m_width;
			float m_height;

			GLuint m_vboID;
			GLTexture m_texture;

	};

}
