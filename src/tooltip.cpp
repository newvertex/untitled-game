#include "tooltip.h"

#include "text.h"

#include <iostream>

namespace MR
{

Tooltip::Tooltip(const char *text, int x, int y, Side side, int fontsize, Color textcolor, Color backcolor)
    : m_text(text), m_x(x), m_y(y), m_side(side), m_fontsize(fontsize), m_textcolor(textcolor), m_backcolor(backcolor)
{
    Vector2 textSize = Text::regularSize(m_text, m_fontsize);
    m_y -= (static_cast<int>(textSize.y) / 2);
    m_w = static_cast<int>(textSize.x) + PADDING * 2;
    m_h = static_cast<int>(textSize.y) + PADDING * 2;
}

void Tooltip::render() const
{
    DrawRectangle(m_x, m_y, m_w, m_h, m_backcolor);
    Text::regular(m_text, m_x + PADDING, m_y + PADDING, m_fontsize, m_textcolor);
}

}
