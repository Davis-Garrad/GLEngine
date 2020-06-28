#pragma once

#include <functional>
#include <glm/glm.hpp>
#include "Vertex.h"
#include "SpriteBatch.h"
#include "GLTexture.h"
#include "ResourceManager.h"

namespace GLEngine {

	class Particle2D {
		public:
			glm::vec2 position = glm::vec2(0.0f);
			glm::vec2 velocity = glm::vec2(0.0f);
			ColourRGBA8 color;
			float life = 0.0f;
			float width = 0.0f;
	};

	// Default function pointer
	inline void defaultParticleUpdate(Particle2D& particle, float deltaTime) {
		particle.position += particle.velocity * deltaTime;
	}

	class ParticleBatch2D {
		public:
			ParticleBatch2D();
			ParticleBatch2D(int maxParticles,
			                float decayRate,
			                std::string& texture,
			                std::string& bumpMap,
			                std::function<void(Particle2D&, float)> updateFunc = defaultParticleUpdate) {
				init(maxParticles, decayRate, texture, bumpMap, updateFunc);
			}
			~ParticleBatch2D();

			void setBumpMap(std::string& bumpMap) {
				m_bumpMap.filePath = bumpMap;
			}

			void update(float deltaTime);

			void draw(SpriteBatch* spriteBatch, float depth);
			void drawNormal(SpriteBatch* spriteBatch, float depth);

			Particle2D* addParticle(const glm::vec2& position,
			                        const glm::vec2& velocity,
			                        const ColourRGBA8& color,
			                        float width);

			GLTexture getTexture() {
				return m_texture;
			}

		private:
			void init(int maxParticles,
			          float decayRate,
			          std::string& texture,
			          std::string& bumpMap,
			          std::function<void(Particle2D&, float)> updateFunc = defaultParticleUpdate);

			int findFreeParticle();

			std::function<void(Particle2D&, float)> m_updateFunc; ///< Function pointer for custom updates
			float m_decayRate = 0.1f;
			Particle2D* m_particles = nullptr;
			int m_maxParticles = 0;
			int m_lastFreeParticle = 0;
			GLTexture m_texture;
			GLTexture m_bumpMap;
	};

}
