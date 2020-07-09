#include "ParticleBatch2D.h"

#include <iostream>

namespace GLEngine {

	ParticleBatch2D::ParticleBatch2D() {
		m_texture.id = 0;
	}


	ParticleBatch2D::~ParticleBatch2D() {
		delete[] m_particles;
	}

	void ParticleBatch2D::init(int maxParticles,
	                           float decayRate,
	                           std::string& texture,
	                           std::string& bumpMap,
	                           std::function<void(Particle2D&, float)> updateFunc /* = defaultParticleUpdate */) {
		m_maxParticles = maxParticles;
		m_particles = new Particle2D[maxParticles];
		m_decayRate = decayRate;
		m_texture.id = 0;
		m_texture.filePath = texture;
		m_bumpMap.filePath = bumpMap;
		m_updateFunc = updateFunc;
	}

	void ParticleBatch2D::update(float deltaTime) {
		for(int i = 0; i < m_maxParticles; i++) {
			// Check if it is active
			if(m_particles[i].life > 0.0f) {
				// Update using function pointer
				m_updateFunc(m_particles[i], deltaTime);
				m_particles[i].life -= m_decayRate * deltaTime;
			}
		}
	}

	void ParticleBatch2D::draw(SpriteBatch* spriteBatch, float depth) {
		glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);

		if(m_texture.id <= 0) {
			m_texture = ResourceManager::getTexture(m_texture.filePath);
		}

		for(int i = 0; i < m_maxParticles; i++) {
			// Check if it is active
			auto& p = m_particles[i];
			if(p.life > 0.0f) {
				glm::vec4 destRect(p.position.x, p.position.y, p.width, p.width);
				spriteBatch->draw(destRect, uvRect, m_texture.id, depth, p.color);
			}
		}
	}

	void ParticleBatch2D::drawNormal(SpriteBatch* spriteBatch, float depth) {
		glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);

		if(m_bumpMap.id <= 0) {
			m_bumpMap = ResourceManager::getTexture(m_bumpMap.filePath);
		}

		for(int i = 0; i < m_maxParticles; i++) {
			auto& p = m_particles[i];
			if(p.life > 0.0f) {
				glm::vec4 destRect(p.position.x, p.position.y, p.width, p.width);
				spriteBatch->draw(destRect, uvRect, m_bumpMap.id, depth, p.color);
			}
		}
	}

	Particle2D* ParticleBatch2D::addParticle(const glm::vec2& position,
	        const glm::vec2& velocity,
	        const ColourRGBA8& color,
	        float width) {
		int particleIndex = findFreeParticle();

		auto& p = m_particles[particleIndex];

		p.life = 1.0f;
		p.position = position;
		p.velocity = velocity;
		p.color = color;
		p.width = width;

		return &p;
	}

	int ParticleBatch2D::findFreeParticle() {

		for(int i = m_lastFreeParticle; i < m_maxParticles; i++) {
			if(m_particles[i].life <= 0.0f) {
				m_lastFreeParticle = i;
				return i;
			}
		}

		for(int i = 0; i < m_lastFreeParticle; i++) {
			if(m_particles[i].life <= 0.0f) {
				m_lastFreeParticle = i;
				return i;
			}
		}

		// No particles are free, overwrite first particle
		return 0;
	}

}
