#pragma once

#include <map>
#include <functional>
#include "GLTexture.h"

namespace GLEngine {

    class ParticleBatch2D;
    class SpriteBatch;
    class Particle2D;

    void defaultParticleUpdate(Particle2D& p, float f);

    class ParticleEngine2D {
    public:
        ParticleEngine2D();
        ~ParticleEngine2D();

        // After adding a particle batch, the ParticleEngine2D becomes
        // responsible for deallocation.
        void addParticleBatch(ParticleBatch2D* particleBatch);
        ParticleBatch2D* getParticleBatch(int maxParticles,
                                          float decayRate,
                                          std::string& texture,
                                          std::string& bumpMap,
                                          std::function<void(Particle2D&, float)> updateFunc = defaultParticleUpdate); // retrieves a ParticleBatch2D* from the vector, by the id of the texture

        void update(float deltaTime);

        void draw(SpriteBatch* spriteBatch, float depth);

    private:
        std::map<std::string, ParticleBatch2D*> m_batches;
    };

}
