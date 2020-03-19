#pragma once

#include <GL/glew.h>

namespace GLEngine {

    struct Position {
        float x;
        float y;
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

    struct Light {
        float tl = 1.0f, tr = 1.0f, br = 1.0f, bl = 1.0f; // For each of the corners (TODO: Add different colour lights)
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
        // 1 byte for depth
        float depth;

        //UV texture coordinates.
        UV uv;

        //lighting (0-1 is normal lighting, after that everything starts going the colour)
        Light light;

        void setPosition(float x, float y) {
            position.x = x;
            position.y = y;
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

        void setLight(float tl, float tr, float br, float bl) {
            light.tl = tl;
            light.tr = tr;
            light.bl = bl;
            light.br = br;
        }
    };

}
