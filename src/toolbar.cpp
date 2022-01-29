#include "toolbar.h"

#include "button.h"

#include <raylib.h>

namespace MR
{

Toolbar::Toolbar(int x, int y, int width, int height, Color backcolor)
    : m_x(x), m_y(y), m_width(width), m_height(height), m_backcolor(backcolor)
{

    addButton(Actions::NONE, "None");
    addButton(Actions::LINE, "Create Line");
    addButton(Actions::RECTANGE, "Create Rectangle");

    if (m_buttonIndex > 0)
    {
        m_activeButton = m_buttons[0];
    }
}

Toolbar::~Toolbar()
{
    // FIXME: MAX_BUTTONS or Maximum created button ?! check for last index
    for (int i = 0; i < m_buttonIndex; i += 1)
    {
        delete m_buttons[i];
    }
}

void Toolbar::render()
{
    DrawRectangle(m_x, m_y, m_width + (m_padding * 2), (m_height * m_buttonIndex) + (m_padding * 2), m_backcolor);

    for (int i = 0; i < m_buttonIndex; i +=1)
    {
        m_buttons[i]->render();
    }
}

void Toolbar::update()
{
    for (int i = 0; i < m_buttonIndex; i +=1)
    {
        if (m_buttons[i]->isActive() && m_activeButton != m_buttons[i])
        {
            m_buttons[i]->setState();
        }

        m_buttons[i]->update();


        if (m_buttons[i]->isActive())
        {
            m_activeButton = m_buttons[i];
        }
    }
}

void Toolbar::addButton(Actions action, const char *command, Color backcolor)
{
    int posX = m_x + m_padding;
    int posY = m_y + ((m_buttonIndex * m_height) + m_padding);

    if (m_buttonIndex < MAX_BUTTONS)
    {
        m_buttons[m_buttonIndex] = new Button(m_buttonIndex, static_cast<unsigned int>(action), command, posX, posY, m_width, m_height, backcolor);
        m_buttonIndex += 1;
    }
}

}
