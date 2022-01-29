#include "vec2.h"

#include <raylib.h>

#include <random>

namespace MR
{

Vec2::Vec2(int x, int y)
    : x(x), y(y)
{

}

Vec2::Vec2(int xy)
    : x(xy), y(xy)
{

}

void Vec2::setXY(int x, int y)
{
    this->x = x;
    this->y = y;
}

Vec2 Vec2::operator-(const Vec2 &rhs)
{
    return Vec2(this->x - rhs.x, this->y - rhs.y);
}

std::ostream &operator<< (std::ostream &out, const Vec2 &vec2)
{
    out << "(" << vec2.x << ", " << vec2.y << ')';

    return out;
}

}
