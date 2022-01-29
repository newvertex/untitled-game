#include "buttontext.h"

#include "text.h"

namespace MR
{


ButtonText::ButtonText(const std::string &text)
    : ButtonBase()
{
    setText(text);
}

ButtonText::ButtonText(const std::string &text, int action)
    : ButtonBase(action)
{
    setText(text);
}

ButtonText::ButtonText(const std::string &text, int action, int x, int y, int width, int height)
    : ButtonBase(action, x, y, width, height)
{
    setText(text);
}

void ButtonText::render() const
{
    ButtonBase::render();
    Text::medium(m_text.c_str(), m_textX, m_textY, m_fontSize, m_textColor);
}

const std::string &ButtonText::text() const
{
    return m_text;
}

void ButtonText::setText(const std::string &text)
{
    m_text = text;
    calcTextSize();
    calcTextPos();
}

const Color &ButtonText::textColor() const
{
    return m_textColor;
}

void ButtonText::setTextColor(const Color &textColor)
{
    m_textColor = textColor;
}

void ButtonText::setPadding(const Padding &padding)
{
    ButtonBase::setPadding(padding);

    calcTextPos();
}

TextAlign ButtonText::align() const
{
    return m_textAlign;
}

void ButtonText::setAlign(TextAlign textAlign)
{
    m_textAlign= textAlign;
    calcTextPos();
}

void ButtonText::calcTextSize()
{
    Vector2 textSize = Text::mediumSize(m_text.c_str(), m_fontSize);

    m_textWidth = static_cast<int>(textSize.x);
    m_textHeight = static_cast<int>(textSize.y);

    m_textCenterX = m_textWidth / 2;
    m_textCenterY = m_textHeight / 2;
}

void ButtonText::calcTextPos()
{
    // resize the background rectangle
    if ((m_textWidth + m_padding.x()) > m_width)
    {
        m_width = m_textWidth + m_padding.x();
    }

    if ((m_textHeight + m_padding.y()) > m_height)
    {
        m_height = m_textHeight + m_padding.y();
    }

    // justify text to
    switch (m_textAlign)
    {
    case TextAlign::LEFT:
        m_textX = m_x + m_padding.l;
        break;
    case TextAlign::CENTER:
        m_textX = m_x + ((m_width / 2) - m_textCenterX);// + m_padding.l;
        break;
    case TextAlign::RIGHT:
        m_textX = (m_x + m_width) - m_textWidth - m_padding.r;
        break;
    }

    // keep text vertically center
    m_textY = m_y + ((m_height / 2) - m_textCenterY);// + m_padding.t;
}

int ButtonText::fontSize() const
{
    return m_fontSize;
}

void ButtonText::setFontSize(int fontSize)
{
    m_fontSize = fontSize;
    calcTextSize();
    calcTextPos();
}

}
