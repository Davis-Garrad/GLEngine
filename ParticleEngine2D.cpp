#include "ParticleEngine2D.h"

#include "ParticleBatch2D.h"
#include "SpriteBatch.h"

#include <iostream>

namespace GLEngine {
	
	ParticleEngine2D::ParticleEngine2D() {
		
	}
	
	ParticleEngine2D::~ParticleEngine2D() {
		for (auto& b : m_batches) {
			delete b;
		}
		m_batches.clear();
	}

	void ParticleEngine2D::addParticleBatch(ParticleBatch2D *batch) {
		m_batches.push_back(batch);
	}

	void ParticleEngine2D::update(float deltaTime) {
		for (int i = 0; i < m_batches.size(); i++) {
			m_batches[i]->update(deltaTime);
		}
	}

	void ParticleEngine2D::draw(SpriteBatch *spriteBatch) {
		spriteBatch->begin();
		for (auto& b : m_batches) {
			b->draw(spriteBatch);
		}
		spriteBatch->end();
		spriteBatch->renderBatch();
	}

}
