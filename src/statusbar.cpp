#include "statusbar.h"

#include "window.h"
#include "input.h"
#include "text.h"

#include <raylib.h>

namespace MR
{

Statusbar::Statusbar(int width, int height, Color color)
    : m_width(width), m_height(height), m_color(color)
{
    m_x = 0;
    m_y = Window::height() - m_height;
}

Statusbar::~Statusbar()
{
}

void Statusbar::render()
{
    DrawRectangle(m_x, m_y, m_width, m_height, m_color);
    DrawLine(m_x, m_y, m_width, m_y, BLACK);

    Text::regular(TextFormat("%s\t %s", Input::mousePosStatus(), Input::mouseButtonsStatus()), static_cast<int>(m_x) + 2, static_cast<int>(m_y) + 2, 18.0f, WHITE);
//    Text::regular(, static_cast<int>(m_x) + 2, static_cast<int>(m_y) + 15, 18.0f);
}

void Statusbar::update()
{
}

}
