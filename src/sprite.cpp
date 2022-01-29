#include "sprite.h"

#include "assets.h"

#include <raylib.h>
#include <raymath.h>

namespace MR {

Sprite::Sprite(int id)
    : m_id(id)
{

}

Sprite::Sprite(int id, int textureId)
    : m_id(id), m_textureId(textureId)
{

}

Sprite::Sprite(int id, int x, int y, int width, int height, int textureId)
    : m_id(id), m_textureId(textureId)
{
    setPosition(x, y);
    setSize(width, height);
}

void Sprite::render() const
{
    // TODO: get texture from assets
    Assets::getTextureByID(m_textureId)->drawEx(m_position.x, m_position.y, m_destSize.x, m_destSize.y, m_origin, m_rotation, m_colorTint, m_flip);
}

int Sprite::id() const
{
    return m_id;
}

const Vector2 &Sprite::position() const
{
    return m_position;
}

void Sprite::setPosition(const Vector2 &position)
{
    m_position = position;
}

void Sprite::setPosition(int x, int y)
{
    setPosition({static_cast<float>(x), static_cast<float>(y)});
}

const Vector2 &Sprite::size() const
{
    return m_size;
}

void Sprite::setSize(const Vector2 &size)
{
    m_size = size;
    calcDestSize();
}

void Sprite::setSize(int width, int height)
{
    setSize({static_cast<float>(width), static_cast<float>(height)});
}

float Sprite::rotation() const
{
    return m_rotation;
}

void Sprite::setRotation(float rotation)
{
    m_rotation = rotation;
}

const Vector2 &Sprite::scale() const
{
    return m_scale;
}

void Sprite::setScale(const Vector2 &scale)
{
    m_scale = scale;
    calcDestSize();
}

void Sprite::setScale(int x, int y)
{
    setScale({static_cast<float>(x), static_cast<float>(y)});
}

const Vector2 &Sprite::origin() const
{
    return m_origin;
}

void Sprite::setOrigin(const Vector2 &origin)
{
    m_origin = origin;
}

const Color &Sprite::colorTint() const
{
    return m_colorTint;
}

void Sprite::setColorTint(const Color &colorTint)
{
    m_colorTint = colorTint;
}

int Sprite::textureId() const
{
    return m_textureId;
}

void Sprite::setTextureId(int textureId)
{
    m_textureId = textureId;
}

void Sprite::calcDestSize()
{
    m_destSize = {m_scale.x * m_size.x, m_scale.y * m_size.y};
    m_origin.x = m_destSize.x / 2.0f;
    m_origin.y = m_destSize.y / 2.0f;
}

bool Sprite::flip() const
{
    return m_flip;
}

void Sprite::setFlip(bool flip)
{
    m_flip = flip;
}

}
