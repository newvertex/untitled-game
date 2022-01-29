#include "buttontexture.h"

#include "assets.h"

#include <raylib.h>

namespace MR
{

ButtonTexture::ButtonTexture(int textureId)
    : ButtonBase()
{
    setTexture(textureId);
}

ButtonTexture::ButtonTexture(int textureId, int action)
    : ButtonBase(action)
{
    setTexture(textureId);
}

ButtonTexture::ButtonTexture(int textureId, int action, int x, int y, int width, int height)
    : ButtonBase(action, x, y, width, height)
{
    setTexture(textureId);
}

void ButtonTexture::render() const
{
    ButtonBase::render();
    Assets::getTextureByID(m_textureId)->draw(m_textureX, m_textureY, m_textureWidth, m_textureHeight);
}

void ButtonTexture::setPadding(const Padding &padding)
{
    ButtonBase::setPadding(padding);
    // change texture position and width height
    calcTexturePos();
}

int ButtonTexture::texture() const
{
    return m_textureId;
}

void ButtonTexture::setTexture(int textureId)
{
    m_textureId = textureId;
    calcTexturePos();
}

void ButtonTexture::calcTexturePos()
{
    // change texture position
    m_textureX = static_cast<float>(m_x + m_padding.l);
    m_textureY = static_cast<float>(m_y + m_padding.t);

    // change texture size
    m_textureWidth = static_cast<float>(m_width - m_padding.r);
    m_textureHeight = static_cast<float>(m_height - m_padding.b);
}

}
