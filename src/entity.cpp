#include "entity.h"

#include "maths.h"

#include <raymath.h>

#include <memory>

namespace MR
{

Entity::Entity()
{

}

Entity::Entity(int x, int y)
{
    setPosition(x, y);
}

Entity::Entity(Vector2 position)
{
    setPosition(position);
}

Entity::~Entity()
{
    delete m_sprite;
    m_sprite = nullptr;

    delete m_animatedSprite;
    m_animatedSprite = nullptr;
}

void Entity::render() const
{
    if (m_sprite != nullptr)
    {
        m_sprite->render();
    }

    if (m_animatedSprite != nullptr)
    {
        m_animatedSprite->render();
    }

    if (m_debugHitBox)
    {
        if (m_hitBoxType == HitBoxType::RECT)
        {
            DrawRectangleLinesEx(m_hitBoxRect,2.0f, RED);
        }
        else
        {
            DrawCircleLines(m_hitBoxCircleCenter.x, m_hitBoxCircleCenter.y, m_hitBoxCircleRadius, RED);
        }
    }
}

void Entity::update(float dt)
{
    m_acceleration = Maths::mulVec(m_acceleration, dt);

    m_velocity = Vector2Add(m_velocity, m_acceleration);

    m_velocity = Maths::clampVec(m_velocity, m_minVelocity, m_maxVelocity);

    move(m_velocity);

    if (m_acceleration.x == 0)
    {
        m_velocity = Vector2Lerp(m_velocity, Vector2Zero(), m_friction);
    }

    m_acceleration.x = 0;
    m_acceleration.y = 0;

    if (m_animatedSprite != nullptr)
    {
        m_animatedSprite->update();
    }
}

void Entity::trigger(Entity *other)
{

}

const Vector2 &Entity::position() const
{
    return m_position;
}

void Entity::setPosition(const Vector2 &position)
{
    m_position = position;
    setHitBoxPosition(m_position);

    if (m_sprite != nullptr)
    {
        m_sprite->setPosition(m_position);
    }
    if (m_animatedSprite != nullptr)
    {
        m_animatedSprite->setPosition(m_position);
    }
}

void Entity::setPosition(int x, int y)
{
    setPosition({static_cast<float>(x), static_cast<float>(y)});
}

void Entity::move(float x, float y)
{
    move({x, y});
}

void Entity::move(Vector2 velocity)
{
    setPosition({m_position.x + velocity.x, m_position.y + velocity.y});
}

const Vector2 &Entity::scale() const
{
    return m_scale;
}

void Entity::setScale(const Vector2 &scale)
{
    m_scale = scale;
    if (m_sprite != nullptr)
    {
        m_sprite->setScale(m_scale);
    }
    if (m_animatedSprite != nullptr)
    {
        m_animatedSprite->setScale(m_scale);
    }
}

void Entity::setScale(int x, int y)
{
    setScale({static_cast<float>(x), static_cast<float>(y)});
}

float Entity::rotation() const
{
    return m_rotation;
}

void Entity::setRotation(float rotation)
{
    m_rotation = rotation;
    if (m_sprite != nullptr)
    {
        m_sprite->setRotation(m_rotation);
    }
    if (m_animatedSprite != nullptr)
    {
        m_animatedSprite->setRotation(m_rotation);
    }
}

Sprite *Entity::sprite() const
{
    return m_sprite;
}

void Entity::setSprite(Sprite *sprite)
{
    m_sprite = sprite;
    if (m_sprite != nullptr)
    {
        m_sprite->setPosition(m_position);
        m_sprite->setScale(m_scale);
        m_sprite->setRotation(m_rotation);
    }
}

int Entity::id() const
{
    return m_id;
}

void Entity::setId(int id)
{
    m_id = id;
}

const std::string &Entity::groupTag() const
{
    return m_groupTag;
}

void Entity::setGroupTag(const std::string &groupTag)
{
    m_groupTag = groupTag;
}

void Entity::setHitBoxRect(Rectangle hitbox)
{
    m_hitBoxType = HitBoxType::RECT;

    m_hitBoxRect = hitbox;

    m_hitBoxOffset.x = m_hitBoxRect.x;
    m_hitBoxOffset.y = m_hitBoxRect.y;
}

const Vector2 &Entity::hitBoxCircleCenter() const
{
    return m_hitBoxCircleCenter;
}

float Entity::hitBoxCircleRadius() const
{
    return m_hitBoxCircleRadius;
}

void Entity::setHitBoxCircle(Vector2 centerPoint, float radius)
{
    m_hitBoxType = HitBoxType::CIRCLE;

    m_hitBoxCircleCenter = centerPoint;
    m_hitBoxCircleRadius = radius;

    m_hitBoxOffset = centerPoint;
}

void Entity::setHitBoxCircle(int x, int y, float radius)
{
    setHitBoxCircle({static_cast<float>(x), static_cast<float>(y)}, radius);
}

void Entity::setHitBoxOffset(Vector2 offset)
{
    m_hitBoxOffset = offset;
}

void Entity::setHitBoxPosition(Vector2 position)
{
    if (m_hitBoxType == HitBoxType::RECT)
    {
        m_hitBoxRect.x = position.x + m_hitBoxOffset.x;
        m_hitBoxRect.y = position.y + m_hitBoxOffset.y;
    }
    else
    {
        m_hitBoxCircleCenter = Vector2Add(position, m_hitBoxOffset);
    }
}

HitBoxType Entity::hitBoxType() const
{
    return m_hitBoxType;
}

Entity *Entity::isCollided(Entity *other)
{
    if (hitBoxType() == HitBoxType::RECT && other->hitBoxType() == HitBoxType::RECT)
        if (CheckCollisionRecs(hitBoxRect(), other->hitBoxRect()))
        {
            trigger(other);
            other->trigger(this);
            return other;
        }

    if (hitBoxType() == HitBoxType::RECT && other->hitBoxType() == HitBoxType::CIRCLE)
        if (CheckCollisionCircleRec(other->hitBoxCircleCenter(), other->hitBoxCircleRadius(), hitBoxRect()))
        {
            trigger(other);
            other->trigger(this);
            return other;
        }

    if (hitBoxType() == HitBoxType::CIRCLE && other->hitBoxType() == HitBoxType::RECT)
        if (CheckCollisionCircleRec(hitBoxCircleCenter(), hitBoxCircleRadius(), other->hitBoxRect()))
        {
            trigger(other);
            other->trigger(this);
            return other;
        }

    if (hitBoxType() == HitBoxType::CIRCLE && other->hitBoxType() == HitBoxType::CIRCLE)
        if (CheckCollisionCircles(hitBoxCircleCenter(), hitBoxCircleRadius(), other->hitBoxCircleCenter(), other->hitBoxCircleRadius()))
        {
            trigger(other);
            other->trigger(this);
            return other;
        }

    return nullptr;
}

const Rectangle &Entity::hitBoxRect() const
{
    return m_hitBoxRect;
}

AnimatedSprite *Entity::animatedSprite() const
{
    return m_animatedSprite;
}

void Entity::setAnimatedSprite(AnimatedSprite *animatedSprite)
{
    m_animatedSprite = animatedSprite;
    if (m_animatedSprite != nullptr)
    {
        m_animatedSprite->setPosition(m_position);
        m_animatedSprite->setScale(m_scale);
        m_animatedSprite->setRotation(m_rotation);
    }
}

void Entity::addAnimation(std::string animationName, Animation *animation)
{
    m_animatedSprite->addAnimation(animationName, animation);
}

void Entity::playAnim(std::string animationName)
{
    m_animatedSprite->play(animationName);
}

const Vector2 &Entity::velocity() const
{
    return m_velocity;
}

void Entity::setVelocity(const Vector2 &velocity)
{
    m_velocity = velocity;
}

const Vector2 &Entity::acceleration() const
{
    return m_acceleration;
}

void Entity::setAcceleration(const Vector2 &acceleration)
{
    m_acceleration = acceleration;
}

void Entity::addForce(const Vector2 &force)
{
    m_acceleration = Vector2Add(m_acceleration, force);
}

float Entity::friction() const
{
    return m_friction;
}

void Entity::setFriction(float friction)
{
    this->m_friction = friction;
}

const Vector2 &Entity::maxVelocity() const
{
    return m_maxVelocity;
}

void Entity::setMaxVelocity(const Vector2 &maxVelocity)
{
    m_maxVelocity = maxVelocity;
}

const Vector2 &Entity::minVelocity() const
{
    return m_minVelocity;
}

void Entity::setMinVelocity(const Vector2 &minVelocity)
{
    m_minVelocity = minVelocity;
}

}
