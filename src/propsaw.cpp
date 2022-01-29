#include "propsaw.h"

#include "assets.h"

#include <raylib.h>
#include <raymath.h>

namespace MR
{

PropSaw::PropSaw(int x, int y, float w, float h, float colliderRadius, bool hasHolder)
    : Entity(x, y)
{
    setSprite(new Sprite(1, x, y, w, h, Assets::PROP_SAW));
    setHitBoxCircle(0, 0, colliderRadius);
    setGroupTag("SAW");

    if (hasHolder)
    {
        m_holderSprite = new Sprite(1, x + 16, y, 64, 64, Assets::PROP_SAW_HOLDER);
        m_holderSprite->setRotation(-90);
    }

    m_particle = std::make_unique<ParticleSystem>(x-31, y+2);
    m_particle->setColor(GOLD);
    m_particle->setInitialRandomVelocity({-0.5f, -10.0f}, {4.0f, -5.0f});
    m_particle->setRandomSize(1.5f, 2.5f);
    m_particle->setLifeTime(5.0f);
}

PropSaw::~PropSaw()
{
    delete m_holderSprite;
}

void PropSaw::update(float dt)
{
    m_particle->createParticle(3);

    setRotation(rotation() + 5.0f);
    m_particle->update(dt);
    m_particle->addForce({0.0f, 10.0f});
    Entity::update(dt);
}

void PropSaw::render() const
{
    m_particle->render();
    Entity::render();

    if (m_holderSprite)
    {
        m_holderSprite->render();
    }
}

void PropSaw::trigger(Entity *other)
{
//    std::cout << "PropSaw Trigger: " << other->id() << ", " << other->groupTag() << "\n";
}

}

