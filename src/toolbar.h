#pragma once

#include "button.h"

#include <raylib.h>

namespace MR
{

enum class Actions
{
    NONE,
    RECTANGE,
    CIRCLE,
    LINE,
    SPRITE,
    // TODO: add game entities here
};

class Toolbar
{
public:
    Toolbar(int x, int y, int width = 42, int height = 42, Color backcolor = {30, 40, 60, 255});
    ~Toolbar();

    void render();
    void update();

private:
    void addButton(Button *btn);
    void addButton(Actions action, const char *command, Color backcolor = BLANK);

    int m_x;
    int m_y;
    int m_width;
    int m_height;
    Color m_backcolor;

    static constexpr int MAX_BUTTONS{5};
//    static constexpr int m_buttonWidth{42};
//    static constexpr int m_buttonHeight{42};
    static constexpr int m_padding{4};

    Button *m_buttons[MAX_BUTTONS];
    Button *m_activeButton{nullptr};
    int m_buttonIndex{0};

};

}
