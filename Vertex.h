#pragma once

#include <GL/glew.h>

namespace GLEngine {

	struct Position {
		float x;
		float y;
		float z;
	};

	struct ColourRGBA8 {
		ColourRGBA8() : r(0), g(0), b(0), a(0) { }
		ColourRGBA8(GLubyte R, GLubyte G, GLubyte B, GLubyte A) :
			r(R), g(G), b(B), a(A) { }
		GLubyte r;
		GLubyte g;
		GLubyte b;
		GLubyte a;
	};

	struct UV {
		float u;
		float v;
	};

	//The vertex definition
	struct Vertex {
		//This is the position struct. When you store a struct or class
		//inside of another struct or class, it is called composition. This is
		//layed out exactly the same in memory as if we had a float position[2],
		//but doing it this way makes more sense.
		Position position;

		//4 bytes for r g b a color.
		ColourRGBA8 color;
		//UV texture coordinates.
		UV uv;

		void setPosition(float x, float y, float d) {
			position.x = x;
			position.y = y;
			position.z = d;
		}

		void setColour(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
			color.r = r;
			color.g = g;
			color.b = b;
			color.a = a;
		}

		void setUV(float u, float v) {
			uv.u = u;
			uv.v = v;
		}
	};

}
