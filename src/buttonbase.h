#pragma once

#include "padding.h"

#include "raylib.h"

namespace MR
{

enum class ButtonState
{
    NONE,
    DISABLED,
    HOVERING,
    ACTIVE,
};

class ButtonGroup;

class ButtonBase
{
public:
    ButtonBase();
    ButtonBase(int action);
    ButtonBase(int action, int x, int y, int width, int height);

    virtual ~ButtonBase();

    virtual void render() const;
    virtual void update();

    int id() const;
    void setId(int id);

    void setPosition(int x, int y);
    void setSize(int width, int height);

    int action() const;
    void setAction(int action);

    bool isActive() const;
    bool isDisabled() const;

    ButtonState state() const;
    void setState(ButtonState state);

    const Color &backColor() const;
    void setBackColor(const Color &backColor);

    const Padding &padding() const;
    virtual void setPadding(const Padding &padding);

    ButtonGroup *parent() const;
    void setParent(ButtonGroup *parent);

protected:
    void calcSize();

    int m_id{0};
    int m_action;

    int m_x;
    int m_y;
    int m_width;
    int m_height;

    int m_dx;
    int m_dy;

    ButtonState m_state{ButtonState::NONE};
    Color m_backColor{BLANK};
    Color m_borderColor;

    static constexpr Color NONE_COLOR{0, 0, 0, 0};
    static constexpr Color DISABLED_COLOR{171, 171, 171, 255};
    static constexpr Color HOVERING_COLOR{255, 140, 0, 255};
    static constexpr Color ACTIVE_COLOR{30, 120, 255, 255};

    Padding m_padding{8, 4};

    ButtonGroup *m_parent{nullptr};
};

}
