#pragma once

#include <raylib.h>

namespace MR
{

class Tooltip
{
public:
    enum class Side
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };

public:
    Tooltip(const char *text, int x, int y, Side side = Side::RIGHT, int fontsize = 18, Color textcolor = {225, 200, 180, 255}, Color backcolor = {50, 60, 70, 255});

    void render() const;

private:
    const char *m_text;
    int m_x;
    int m_y;
    Side m_side;
    int m_fontsize;
    Color m_textcolor;
    Color m_backcolor;

    int m_w;
    int m_h;
    constexpr static int PADDING{4};

};

}
