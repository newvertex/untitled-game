#pragma once

#include <raylib.h>

namespace MR
{

class Statusbar
{
public:
    Statusbar(int width, int height, Color color = {30, 50, 60, 255});
    ~Statusbar();

    void render();
    void update();

private:
    int m_width;
    int m_height;
    Color m_color;

    int m_x;
    int m_y;

};

}
