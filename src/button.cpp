#include "button.h"

#include "input.h"
#include "text.h"

#include <cstring>

namespace MR
{

Button::Button(int id, unsigned int action, const char *command, int x, int y, int w, int h, Color backColor)
    : m_id(id), m_action(action), m_command(command), m_x(x), m_y(y), m_w(w), m_h(h), m_backcolor(backColor)
{
    init();
}

Button::~Button()
{
    // DELETE: Tooltip
    delete m_tooltip;
}

void Button::update()
{
    if (m_state == ButtonState::DISABLED || m_state == ButtonState::ACTIVE)
    {
        return;
    }

    if (Input::isMouseBetween(m_x, m_y, m_x + m_w, m_y + m_h))
    {
        m_state = ButtonState::HOVERING;

        if (Input::isClicked())
        {
            m_state = ButtonState::ACTIVE;
        }
    }
    else
    {
        m_state = ButtonState::NONE;
    }
}

void Button::render()
{
    // FIXME: Refactor it
    switch (m_state)
    {
    case ButtonState::NONE:
        drawRect(m_backcolor, RED);
        break;
    case ButtonState::DISABLED:
        drawRect(LIGHTGRAY, GRAY);
        break;
    case ButtonState::HOVERING:
        drawRect(m_backcolor, GOLD);

        if (m_tooltip != nullptr)
        {
            m_tooltip->render();
        }
        break;
    case ButtonState::ACTIVE:
        drawRect(m_backcolor, SKYBLUE);
        break;
    }
}

void Button::setState(ButtonState state)
{
    m_state = state;
}

bool Button::isActive() const
{
    return m_state == ButtonState::ACTIVE;
}

int Button::id() const
{
    return m_id;
}

unsigned int Button::action() const
{
    return m_action;
}

const char *Button::command() const
{
    return m_command;
}

const std::string &Button::text() const
{
    return m_text;
}

void Button::setText(const std::string &text)
{
    m_text = text;
}

void Button::init()
{
    // NEW: Tooltip
    if (strlen(m_command) > 0)
    {
        m_tooltip = new Tooltip(m_command, m_x + m_w, m_y + (m_h / 2));
    }
}

void Button::drawRect(Color backcolor, Color bordercolor)
{
    DrawRectangle(m_x, m_y, m_w, m_h, backcolor);
    DrawRectangleLines(m_x, m_y, m_w, m_h, bordercolor);

    if (!m_text.empty())
    {
//        Text::medium(m_text.c_str(), )
    }
}

}
