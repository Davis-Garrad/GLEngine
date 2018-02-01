#include "ParticleBatch2D.h"

#include <iostream>

namespace GLEngine {

	ParticleBatch2D::ParticleBatch2D() {
		
	}
	
	ParticleBatch2D::~ParticleBatch2D() {
		delete[] m_particles;
	}

	void ParticleBatch2D::init(int maxParticles, float decayRate, GLTexture texture, std::function<void(Particle2D&, float)> updateFunc /*= defaultParticleUpdate*/) {
		m_maxParticles = maxParticles;
		m_particles = new Particle2D[maxParticles];

		m_updateFunc = updateFunc;

		m_decayRate = decayRate;

		m_texture = texture;
	}

	void ParticleBatch2D::addParticle2D(const glm::vec2 &position, const ColourRGBA8 &colour, glm::vec2 velocity, float width) {
		int particleIndex = findFreeParticle();

		auto p = &m_particles[particleIndex];

		p->life = 1.0f;
		p->position = position;
		p->colour = colour;
		p->velocity = velocity;
		p->width = width;
	}

	void ParticleBatch2D::update(float deltaTime) {
		for (int i = 0; i < m_maxParticles; i++) {
			// Check if it is active
			if (m_particles[i].life > 0.0f) {
				m_updateFunc(m_particles[i], deltaTime);
				m_particles[i].life -= m_decayRate * deltaTime; // This is updating every frame! :)
			}
		}
	}

	void ParticleBatch2D::draw(SpriteBatch *spriteBatch) {
		for (int i = 0; i < m_maxParticles; i++) {
			auto p = m_particles[i];
			if (p.life > 0.0f) {
				glm::vec4 destRect(p.position.x, p.position.y, p.width, p.width);
				glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
				spriteBatch->draw(destRect, uvRect, m_texture.id, p.colour, 0.0f);
			}
		}
	}

	int ParticleBatch2D::findFreeParticle() {
		for (int i = m_lastFreeParticle; i < m_maxParticles; i++) {
			if (m_particles[i].life == 0.0f) {
				m_lastFreeParticle = i;
				return i;
			}
		}

		for (int i = 0; i < m_lastFreeParticle; i++) {
			if (m_particles[i].life == 0.0f) {
				m_lastFreeParticle = i;
				return i;
			}
		}

		// If you got here, there are NO PARTICLES free!!!
		// Overwriting first
		return 0;

	}
}
