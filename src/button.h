#pragma once

#include "tooltip.h"

#include <raylib.h>

#include <string>

namespace MR
{

enum class ButtonState
{
    NONE,
    DISABLED,
    HOVERING,
    ACTIVE,
};

class Button
{
public:
    Button(int id, unsigned int action, const char *command, int x, int y, int w, int h, Color backColor = BLANK);

    ~Button();

    void update();
    void render();

    void setState(ButtonState state = ButtonState::NONE);
    bool isActive() const;

    int id() const;
    unsigned int action() const;
    const char *command() const;

    const std::string &text() const;
    void setText(const std::string &text);

private:
    void init();
    void drawRect(Color backcolor, Color bordercolor = BLANK);

    int m_id;
    unsigned int m_action;
    const char *m_command;

    int m_x;
    int m_y;
    int m_w;
    int m_h;

    std::string m_text{};
    Color m_textColor;

    Color m_backcolor;
    ButtonState m_state{ButtonState::NONE};

    Tooltip *m_tooltip{nullptr};
    Texture m_texture;
    Color m_textureTint;

    int m_textWidth;
    int m_textHeight;

};

}
