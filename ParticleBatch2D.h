#pragma once

#include <glm/glm.hpp>
#include <functional>

#include "Vertex.h"
#include "SpriteBatch.h"
#include "GLTexture.h"

namespace GLEngine {
	
	class Particle2D {
		public:
			glm::vec2 position = glm::vec2(0.0f);
			glm::vec2 velocity = glm::vec2(1.0f, 0.0f);

			ColourRGBA8 colour;

			float life = 0.0f;
			float width = 0.0f;
	};

	inline void defaultParticleUpdate(Particle2D &particle, float deltaTime) {
		particle.position += particle.velocity * deltaTime;
	}

	class ParticleBatch2D {
		public:
			ParticleBatch2D();
			~ParticleBatch2D();

			void init(int maxParticles, float decayRate, GLTexture texture, std::function<void(Particle2D&, float)> updateFunc = defaultParticleUpdate);

			void addParticle2D(const glm::vec2 &position, const ColourRGBA8 &colour, glm::vec2 velocity, float width);

			void update(float deltaTime);

			void draw(SpriteBatch *spriteBatch);

			int findFreeParticle();

		private:
			float m_decayRate = 0.1f;

			std::function<void(Particle2D&, float)> m_updateFunc;

			GLTexture m_texture;
			Particle2D* m_particles = nullptr; // Have a reusable buffer of particles

			int m_lastFreeParticle = 0;
			int m_maxParticles = 0;
	};

}
