#pragma once

#include <iostream>

namespace MR
{

struct Vec2
{
    int x{0};
    int y{0};

    Vec2() = default;
    Vec2(int x, int y);
    Vec2(int xy);

    void setXY(int x, int y);

    Vec2 operator-(const Vec2 &rhs);

    friend std::ostream &operator<<(std::ostream &out, const Vec2 &vec2);

};

}
