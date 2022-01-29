#pragma once

#include "entity.h"
#include "particlesystem.h"

#include <raylib.h>

#include <memory>

namespace MR
{

class Player : public Entity
{
public:
    Player(int x, int y);

    // Entity interface
    virtual void update(float dt) override;
    virtual void render() const override;
    virtual void trigger(Entity *other) override;

private:
    float m_speed{10.0f};
    float m_nitro{20.0f};

    bool m_jump{false};
    bool m_ground{false};
    bool m_dead{false};

    Vector2 m_jumpHeight{0.0f, -1000.0f};

    Vector2 m_gravity{0.0f, 100.0f};

    std::unique_ptr<ParticleSystem> m_particle;

    int m_frames{0};
    int m_score{0};
    unsigned char m_scoreAlpha{0};

};

}
