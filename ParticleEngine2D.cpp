#include "ParticleEngine2D.h"

#include "ParticleBatch2D.h"
#include "SpriteBatch.h"
#include "ResourceManager.h"

namespace GLEngine {


    ParticleEngine2D::ParticleEngine2D() {
        // Empty
    }

    ParticleEngine2D::~ParticleEngine2D() {
        for (auto& b : m_batches) {
            delete b.second;
        }
    }

    void ParticleEngine2D::addParticleBatch(ParticleBatch2D* particleBatch) {
        m_batches.insert(std::make_pair(particleBatch->getTexture().filePath, particleBatch));
    }

    ParticleBatch2D* ParticleEngine2D::getParticleBatch(int maxParticles,
                                                        float decayRate,
                                                        std::string& texture,
                                                        std::string& bumpMap,
                                                        std::function<void(Particle2D&, float)> updateFunc) {
        ParticleBatch2D* res = nullptr;

        std::string ID = texture;

        auto index = m_batches.find(ID);

        if(index == m_batches.end()) { // it's not in the map
            ParticleBatch2D* p = new ParticleBatch2D(maxParticles, decayRate, texture, bumpMap, updateFunc);
            addParticleBatch(p);
            return p;
        }

        res = index->second;

        return res;
    }

    void ParticleEngine2D::update(float deltaTime) {
        for (auto& b : m_batches) {
            b.second->update(deltaTime);
        }
    }

    void ParticleEngine2D::draw(SpriteBatch* spriteBatch, float depth) {
        for (auto& b : m_batches) {
            b.second->draw(spriteBatch, depth);
        }
    }
}
