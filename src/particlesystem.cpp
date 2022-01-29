#include "particlesystem.h"

#include "particle.h"
#include "maths.h"

#include <iostream>
#include <memory>

namespace MR
{

ParticleSystem::ParticleSystem(int x, int y)
{
    setPosition(x, y);
}

ParticleSystem::ParticleSystem(Vector2 position)
    : m_position(position)
{

}

ParticleSystem::~ParticleSystem()
{
//    for (auto &&particle : m_particles)
//    {
//        delete particle;
//        particle = nullptr;
//    }
    m_particles.clear();
}

void ParticleSystem::update(float dt)
{
    auto it = m_particles.begin();
    while (it != m_particles.end())
    {
        (*it)->update(dt);
        if ((*it)->isDead())
        {
//          delete (*it);
            it = m_particles.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void ParticleSystem::render()
{
    for (auto &&particle : m_particles)
    {
        particle->render();
    }
}

void ParticleSystem::createParticle(int howMany)
{
    for (int i = 0; i < howMany; i +=1 )
    {
        Vector2 pos = m_position;
        if (m_randomPosX)
        {
            pos.x = Maths::randf(m_posX1, m_posX2);
        }
        if (m_randomPosY)
        {
            pos.y = Maths::randf(m_posY1, m_posY2);
        }

        Vector2 vel = m_initialVelocity;
        if (m_randomVelocity)
        {
            vel.x = Maths::randf(m_velFrom.x, m_velTo.x);
            vel.y = Maths::randf(m_velFrom.y, m_velTo.y);
        }

        float lifeTime = m_lifeTime;
        if (m_randomLifeTime)
        {
            lifeTime = Maths::randf(m_lifeTimeFrom, m_lifeTimeTo);
        }

        float size = m_size;
        if (m_randomSize)
        {
            size = Maths::randf(m_sizeFrom, m_sizeTo);
        }

        auto particle = std::make_unique<Particle>(pos);
        particle->setVelocity(vel);
        particle->setLifeTime(lifeTime);
        particle->setSize(size);

        if (m_randomTexture)
        {
            m_textureId = m_texturesId.at(Maths::randi(0, m_texturesId.size() - 1));
        }

        if (m_textureId != -1)
        {
            particle->setTexture(m_textureId, m_colorTint);
        }
        else
        {
            particle->setColor(m_color);
        }

        m_particles.emplace_back(std::move(particle));
    }
}

const Vector2 &ParticleSystem::position() const
{
    return m_position;
}


void ParticleSystem::setPosition(Vector2 position)
{
    m_position = position;
}

void ParticleSystem::setPosition(int x, int y)
{
    setPosition({static_cast<float>(x), static_cast<float>(y)});
}

void ParticleSystem::addForce(Vector2 force)
{
    for (auto &particle : m_particles)
    {
        particle->addForce(force);
    }
}

const Vector2 &ParticleSystem::initialVelocity() const
{
    return m_initialVelocity;
}

void ParticleSystem::setInitialVelocity(Vector2 initialVelocity)
{
    m_initialVelocity = initialVelocity;
}

void ParticleSystem::setInitialRandomVelocity(Vector2 from, Vector2 to)
{
    m_velFrom = from;
    m_velTo = to;
    m_randomVelocity = true;
}

bool ParticleSystem::randomVelocity() const
{
    return m_randomVelocity;
}

void ParticleSystem::setRandomVelocity(bool randomVelocity)
{
    m_randomVelocity = randomVelocity;
}

bool ParticleSystem::randomPosX() const
{
    return m_randomPosX;
}

void ParticleSystem::setRandomPosX(bool randomPosX)
{
    m_randomPosX = randomPosX;
}

void ParticleSystem::setRandomPosX(int fromX, int toX)
{
    m_posX1 = fromX;
    m_posX2 = toX;
    m_randomPosX = true;
}

bool ParticleSystem::randomPosY() const
{
    return m_randomPosY;
}

void ParticleSystem::setRandomPosY(bool randomPosY)
{
    m_randomPosY = randomPosY;
}

void ParticleSystem::setRandomPosY(int fromY, int toY)
{
    m_posY1 = fromY;
    m_posY2 = toY;
    m_randomPosY = true;
}

float ParticleSystem::lifeTime() const
{
    return m_lifeTime;
}

void ParticleSystem::setLifeTime(float time)
{
    m_lifeTime = time;
}

bool ParticleSystem::randomLifeTime() const
{
    return m_randomLifeTime;
}

void ParticleSystem::setRandomLifeTime(bool randomLifeTime)
{
    m_randomLifeTime = randomLifeTime;
}

void ParticleSystem::setRandomLifeTime(float lifeTimeFrom, float lifeTimeTo)
{
    m_lifeTimeFrom = lifeTimeFrom;
    m_lifeTimeTo = lifeTimeTo;
    m_randomLifeTime = true;
}

float ParticleSystem::size() const
{
    return m_size;
}

void ParticleSystem::setSize(float size)
{
    m_size = size;
}

bool ParticleSystem::randomSize() const
{
    return m_randomSize;
}

void ParticleSystem::setRandomSize(bool randomSize)
{
    m_randomSize = randomSize;
}

void ParticleSystem::setRandomSize(float sizeFrom, float sizeTo)
{
    m_sizeFrom = sizeFrom;
    m_sizeTo = sizeTo;
    m_randomSize = true;
}

Color ParticleSystem::color() const
{
    return m_color;
}

void ParticleSystem::setColor(Color color)
{
    m_color = color;
}

int ParticleSystem::textureId() const
{
    return m_textureId;
}

Color ParticleSystem::textureColorTint() const
{
    return m_colorTint;
}

void ParticleSystem::setTextureColorTint(Color tint)
{
    m_colorTint = tint;
}

void ParticleSystem::addTextures(int textureId)
{
    m_texturesId.push_back(textureId);
    m_randomTexture = true;
}

void ParticleSystem::setTexture(int textureId, Color tint)
{
    m_textureId = textureId;
    m_colorTint = tint;
}

void ParticleSystem::setRandomTexture(bool randomTexture)
{
    m_randomTexture = randomTexture;
}

std::ostream &operator<<(std::ostream &out, const ParticleSystem &particleSystem)
{
    out << "ParticleSystem: " << particleSystem.m_particles.size();
    return out;
}

}
