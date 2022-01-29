#pragma once

#include "entity.h"
#include "particlesystem.h"
#include "sprite.h"

#include <memory>

namespace MR
{

class PropSaw : public Entity
{
public:
    PropSaw(int x, int y, float w, float h, float colliderRadius, bool hasHolder = false);
    ~PropSaw();

    // Entity interface
    virtual void update(float dt) override;
    virtual void render() const override;
    virtual void trigger(Entity *other) override;


private:
    std::unique_ptr<ParticleSystem> m_particle;

    Sprite *m_holderSprite{nullptr};

};

}
