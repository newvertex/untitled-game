#include "buttonbase.h"

#include "input.h"

#include <iostream>

namespace MR
{

ButtonBase::ButtonBase()
{

}

ButtonBase::ButtonBase(int action)
    : m_action(action)
{

}

ButtonBase::ButtonBase(int action, int x, int y, int width, int height)
    : m_action(action), m_x(x), m_y(y), m_width(width), m_height(height)
{
    calcSize();
}

ButtonBase::~ButtonBase()
{

}

int ButtonBase::id() const
{
    return m_id;
}

void ButtonBase::setId(int id)
{
    m_id = id;
}

void ButtonBase::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
    calcSize();
}

void ButtonBase::setSize(int width, int height)
{
    m_width = width;
    m_height = height;
    calcSize();
}

void ButtonBase::calcSize()
{
    m_dx = m_x + m_width;
    m_dy = m_y + m_height;
}

ButtonGroup *ButtonBase::parent() const
{
    return m_parent;
}

void ButtonBase::setParent(ButtonGroup *parent)
{
    m_parent = parent;
    // TODO: re calc the position of the button base on the parent button group position/size
}

int ButtonBase::action() const
{
    return m_action;
}

void ButtonBase::setAction(int action)
{
    m_action = action;
}

bool ButtonBase::isActive() const
{
    return m_state == ButtonState::ACTIVE;
}

bool ButtonBase::isDisabled() const
{
    return m_state == ButtonState::DISABLED;
}

const Color &ButtonBase::backColor() const
{
    return m_backColor;
}

void ButtonBase::setBackColor(const Color &backColor)
{
    m_backColor = backColor;
}

const Padding &ButtonBase::padding() const
{
    return m_padding;
}

void ButtonBase::setPadding(const Padding &padding)
{
    m_padding = padding;
}

ButtonState ButtonBase::state() const
{
    return m_state;
}

void ButtonBase::setState(ButtonState state)
{
    m_state = state;

    // Set the border color from current button state
    switch (m_state)
    {
    case MR::ButtonState::NONE:
        m_borderColor = NONE_COLOR;
        break;
    case MR::ButtonState::DISABLED:
        m_borderColor = DISABLED_COLOR;
        break;
    case MR::ButtonState::HOVERING:
        m_borderColor = HOVERING_COLOR;
        break;
    case MR::ButtonState::ACTIVE:
        m_borderColor = ACTIVE_COLOR;
        break;
    }
}

void ButtonBase::render() const
{
    DrawRectangle(m_x, m_y, m_width, m_height, m_backColor);
    DrawRectangleLines(m_x, m_y, m_width, m_height, m_borderColor);

    DrawLine(m_x, m_y + m_height / 2, m_x + m_width, m_y + m_height / 2, BLUE);
    DrawLine(m_x + m_width / 2, m_y, m_x + m_width / 2, m_y + m_height, BLUE);
}

void ButtonBase::update()
{
    // check the current button state
    if (isDisabled() || isActive())
    {
        return;
    }

    if (Input::isMouseBetween(m_x, m_y, m_dx, m_dy))
    {
        std::cout << "Hovering \n";
        setState(ButtonState::HOVERING);

        if (Input::isClicked())
        {
            setState(ButtonState::ACTIVE);
            std::cout << "Clicked \n";
        }
    }
    else
    {
        setState(ButtonState::NONE);
    }
}

}
