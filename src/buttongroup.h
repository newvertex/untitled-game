#pragma once

#include "padding.h"
#include "buttonbase.h"

#include <raylib.h>

#include <vector>

namespace MR
{

enum class LayoutType
{
    HORIZONTAL,
    VERTICAL,
};

class ButtonGroup
{
public:
    ButtonGroup(int id, int x, int y, int minWidth, int minHeight);
    ~ButtonGroup();

    void render() const;
    void update();

    int id() const;

    void addButton(ButtonBase *button);

    const Color &backColor() const;
    void setBackColor(const Color &backColor);

    const Color &borderColor() const;
    void setBorderColor(const Color &borderColor);

    const Padding &padding() const;
    void setPadding(const Padding &padding);

    int margin() const;
    void setMargin(int margin);

    LayoutType layoutType() const;
    void setLayoutType(LayoutType layoutType);

private:
    int m_id;

    int m_x;
    int m_y;

    int m_minWidth;
    int m_minHeight;
    int m_width;
    int m_height;

    Color m_backColor{BLANK};
    Color m_borderColor{BLANK};

    Padding m_padding{};
    int m_margin{0};

    LayoutType m_layoutType{LayoutType::VERTICAL};

    std::vector<ButtonBase *> m_buttons;

};

}
