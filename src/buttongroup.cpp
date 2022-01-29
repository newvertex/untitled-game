#include "buttongroup.h"

#include "buttonbase.h"

namespace MR
{

ButtonGroup::ButtonGroup(int id, int x, int y, int minWidth, int minHeight)
    : m_id(id), m_x(x), m_y(y), m_minWidth(minWidth), m_minHeight(minHeight)
{

}

ButtonGroup::~ButtonGroup()
{
    for (auto &btn : m_buttons)
    {
        delete btn;
    }

    m_buttons.clear();
}

void ButtonGroup::render() const
{
    if (m_backColor.a != 0)
    {
        DrawRectangle(m_x, m_y, m_width, m_height, m_backColor);
    }
    if (m_borderColor.a != 0)
    {
        DrawRectangleLines(m_x, m_y, m_width, m_height, m_borderColor);
    }

    for (auto &btn : m_buttons)
    {
        btn->render();
    }
}

void ButtonGroup::update()
{
    for (auto &btn : m_buttons)
    {
        btn->update();
    }
    // TODO: check for active button and keep track it to switch them and run the actions
}

int ButtonGroup::id() const
{
    return m_id;
}

void ButtonGroup::addButton(ButtonBase *button)
{
    m_buttons.push_back(button);
    // FIXME: keep track the last added button postiion and use it to fill the new button position
    button->setId(static_cast<int>(m_buttons.size()));
    button->setPosition(m_x, m_y);
    button->setSize(m_width, m_height);
}

const Color &ButtonGroup::backColor() const
{
    return m_backColor;
}

void ButtonGroup::setBackColor(const Color &backColor)
{
    m_backColor = backColor;
}

const Color &ButtonGroup::borderColor() const
{
    return m_borderColor;
}

void ButtonGroup::setBorderColor(const Color &borderColor)
{
    m_borderColor = borderColor;
}

const Padding &ButtonGroup::padding() const
{
    return m_padding;
}

void ButtonGroup::setPadding(const Padding &padding)
{
    m_padding = padding;

    for (auto &btn : m_buttons)
    {
        btn->setPadding(padding);
    }
}

int ButtonGroup::margin() const
{
    return m_margin;
}

void ButtonGroup::setMargin(int margin)
{
    m_margin = margin;
    // TODO: re calc buttons[] new positions based on the margin
    // button->y += margin
}

LayoutType ButtonGroup::layoutType() const
{
    return m_layoutType;
}

void ButtonGroup::setLayoutType(LayoutType layoutType)
{
    m_layoutType = layoutType;
}



}
