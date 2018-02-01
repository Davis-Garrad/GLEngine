#pragma once

#include <GL/glew.h>

namespace GLEngine {

	struct Position {

			float x, y;

	};

	struct ColourRGBA8 {
			ColourRGBA8() : r(255), g(255), b(255), a(255) {
			}
			ColourRGBA8(GLubyte R, GLubyte G, GLubyte B, GLubyte A) : r(R), g(G), b(B), a(A) {

			}
			GLubyte r, g, b, a;

	};

	struct UV {
			
			float u, v;
			
	};

	struct Vertex {
			
			Position position;
			ColourRGBA8 colour;
			UV uv;

			void setColour(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {

				colour = ColourRGBA8(r, g, b, a);

			}
			
			void setPosition(float x, float y) {

				position.x = x;
				position.y = y;

			}
			
			void setUV(float u, float v) {

				uv.u = u;
				uv.v = v;

			}
			
	};

}
