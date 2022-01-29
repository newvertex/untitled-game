#include "particle.h"

#include "maths.h"
#include "assets.h"

#include <raylib.h>
#include <raymath.h>

#include <iostream>

namespace MR
{

Particle::Particle(int x, int y)
    : m_position({static_cast<float>(x), static_cast<float>(y)})
{

}

Particle::Particle(Vector2 position)
    : m_position(position)
{

}

Particle::~Particle()
{
    //std::cout << "deleted\n";
}

void Particle::update(float dt)
{
    m_acceleration = Maths::mulVec(m_acceleration, dt);

    m_velocity = Vector2Add(m_velocity, m_acceleration);

    m_position = Vector2Add(m_position, m_velocity);

    m_acceleration.x = 0;
    m_acceleration.y = 0;

    m_elapsedTime += dt;
}

void Particle::render()
{
    if (m_textureId != -1)
    {
        Assets::getTextureByID(m_textureId)->draw(m_position.x, m_position.y, m_size, m_size, m_color);
    }
    else
    {
        DrawCircle(static_cast<int>(m_position.x), static_cast<int>(m_position.y), m_size, m_color);
    }
}

void Particle::addForce(Vector2 force)
{
    m_acceleration = Vector2Add(m_acceleration, force);
}

void Particle::setVelocity(Vector2 velocity)
{
    m_velocity = velocity;
}

const Color &Particle::color() const
{
    return m_color;
}

void Particle::setColor(Color color)
{
    m_color = color;
}

float Particle::size() const
{
    return m_size;
}

void Particle::setSize(float size)
{
    m_size = size;
}

float Particle::lifeTime() const
{
    return m_lifeTime;
}

void Particle::setLifeTime(float lifeTime)
{
    m_lifeTime = lifeTime;
}

float Particle::elapsedTime() const
{
    return m_elapsedTime;
}

bool Particle::isDead() const
{
    if (m_lifeTime != -1.0 && m_elapsedTime > m_lifeTime)
    {
        return true;
    }

    return false;
}

int Particle::opacity() const
{
    return m_opacity;
}

void Particle::setOpacity(int opacity)
{
    m_opacity = opacity;
}

int Particle::textureId() const
{
    return m_textureId;
}

void Particle::setTexture(int textureId, Color tint)
{
    m_textureId = textureId;
    m_color = tint;
}

}
