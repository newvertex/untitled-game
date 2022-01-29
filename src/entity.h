#pragma once

#include "sprite.h"
#include "animatedsprite.h"

#include <raylib.h>

#include <string>
#include <memory>

namespace MR
{

enum class HitBoxType
{
    RECT,
    CIRCLE,
};

class Entity
{
public:
    Entity();
    Entity(int x, int y);
    Entity(Vector2 position);

    virtual ~Entity();

    virtual void render() const;
    virtual void update(float dt);

    virtual void trigger(Entity *other);

    // TODO: collision detection and bounding box

    const Vector2 &position() const;
    void setPosition(const Vector2 &position);
    void setPosition(int x, int y);

    // move/setPosition relative from current position
    void move(float x, float y);
    void move(Vector2 velocity);

    const Vector2 &scale() const;
    void setScale(const Vector2 &scale);
    void setScale(int x, int y);

    float rotation() const;
    void setRotation(float rotation);

    const Vector2 &velocity() const;
    void setVelocity(const Vector2 &velocity);

    const Vector2 &acceleration() const;
    void setAcceleration(const Vector2 &acceleration);
    void addForce(const Vector2 &force);

    float friction() const;
    void setFriction(float friction);

    const Vector2 &maxVelocity() const;
    void setMaxVelocity(const Vector2 &maxVelocity);

    const Vector2 &minVelocity() const;
    void setMinVelocity(const Vector2 &minVelocity);

    Sprite *sprite() const;
    void setSprite(Sprite *sprite);

    AnimatedSprite *animatedSprite() const;
    void setAnimatedSprite(AnimatedSprite *animatedSprite);
    void addAnimation(std::string animationName, Animation *animation);
    void playAnim(std::string animationName);

    int id() const;
    void setId(int id);

    const std::string &groupTag() const;
    void setGroupTag(const std::string &groupTag);

    const Rectangle &hitBoxRect() const;
    void setHitBoxRect(Rectangle hitbox);

    const Vector2 &hitBoxCircleCenter() const;
    float hitBoxCircleRadius() const;
    void setHitBoxCircle(Vector2 centerPoint, float radius);
    void setHitBoxCircle(int x, int y, float radius);

    void setHitBoxOffset(Vector2 offset = {0.0f, 0.0f});
    void setHitBoxPosition(Vector2 position);

    HitBoxType hitBoxType() const;
    Entity *isCollided(Entity *other);

protected:
    int m_id{-1};
    std::string m_groupTag;

    // TODO: parent position(global transform, local transform)
    Vector2 m_position{0.0f, 0.0f};
    Vector2 m_scale{1.0f, 1.0f};
    float m_rotation = 0.0f;

    Vector2 m_velocity{0.0f, 0.0f};
    Vector2 m_acceleration{0.0f, 0.0f};
    float m_friction{0.0f};

    Vector2 m_maxVelocity{1000.0f, 1000.0f};
    Vector2 m_minVelocity{-1000.0f, -1000.0f};

    Sprite *m_sprite{nullptr};
    AnimatedSprite *m_animatedSprite{nullptr};

    HitBoxType m_hitBoxType{HitBoxType::RECT};
    Vector2 m_hitBoxOffset{0.0f, 0.0f};
    bool m_debugHitBox{false};

    Rectangle m_hitBoxRect{0.0f , 0.0f, 0.0f, 0.0f};

    Vector2 m_hitBoxCircleCenter{0.0f, 0.0f};
    float m_hitBoxCircleRadius{1.0f};
};

}
