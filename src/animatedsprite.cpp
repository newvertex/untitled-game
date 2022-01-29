#include "animatedsprite.h"

#include "assets.h"

namespace MR
{

AnimatedSprite::AnimatedSprite(int id)
    : m_id(id)
{

}

AnimatedSprite::~AnimatedSprite()
{
    for (auto &&anim : m_animations)
    {
        delete anim.second;
    }

    m_animations.clear();
}

void AnimatedSprite::render()
{
    if (m_currentAnimation != nullptr)
    {
        Assets::getTextureByID(currentFrameTexture())
                ->drawEx(m_position.x, m_position.y,
                         m_destSize.x, m_destSize.y,
                         m_origin, m_rotation,
                         m_colorTint,
                         m_flip);
    }
}

void AnimatedSprite::update()
{
    if (m_currentAnimation != nullptr)
    {
        m_frames += 1;
        m_currentFrame = m_frames / m_speed;
        if (m_currentFrame >= m_currentAnimation->texturesID.size())
        {
            m_frames = 0;
            m_currentFrame = 0;
        }
    }
}

void AnimatedSprite::addAnimation(std::string name, Animation *animation)
{
    m_animations.insert(std::make_pair(name, animation));
}

int AnimatedSprite::currentFrameTexture()
{
    if (m_currentAnimation->texturesID.size() <= m_currentFrame)
    {
        m_currentFrame = 0;
    }

    return m_currentAnimation->texturesID.at(m_currentFrame);
}

void AnimatedSprite::calcDestSize()
{
    m_destSize = {m_scale.x * m_size.x, m_scale.y * m_size.y};
    m_origin.x = m_destSize.x / 2.0f;
    m_origin.y = m_destSize.y / 2.0f;
}

bool AnimatedSprite::flip() const
{
    return m_flip;
}

void AnimatedSprite::setFlip(bool flip)
{
    m_flip = flip;
}

void AnimatedSprite::setSpeed(int speed)
{
    m_speed = speed;
}

const Vector2 &AnimatedSprite::position() const
{
    return m_position;
}

void AnimatedSprite::setPosition(const Vector2 &position)
{
    m_position = position;
}

const Vector2 &AnimatedSprite::origin() const
{
    return m_origin;
}

void AnimatedSprite::setOrigin(const Vector2 &origin)
{
    m_origin = origin;
}

float AnimatedSprite::rotation() const
{
    return m_rotation;
}

void AnimatedSprite::setRotation(float rotation)
{
    m_rotation = rotation;
}

const Vector2 &AnimatedSprite::scale() const
{
    return m_scale;
}

void AnimatedSprite::setScale(const Vector2 &scale)
{
    m_scale = scale;
    calcDestSize();
}

const Vector2 &AnimatedSprite::size() const
{
    return m_size;
}

void AnimatedSprite::setSize(const Vector2 &size)
{
    m_size = size;
    calcDestSize();
}

const Color &AnimatedSprite::colorTint() const
{
    return m_colorTint;
}

void AnimatedSprite::setColorTint(const Color &colorTint)
{
    m_colorTint = colorTint;
}

void AnimatedSprite::play(std::string animationName)
{
    if (m_currentAnimation == nullptr)
    {
        m_currentAnimation = m_animations.at(animationName);
    }

    if (m_currentAnimation != nullptr && m_currentAnimation->name != animationName)
    {
        m_currentFrame = 0;
        m_currentAnimation = m_animations.at(animationName);
    }
}

int AnimatedSprite::id() const
{
    return m_id;
}

}
