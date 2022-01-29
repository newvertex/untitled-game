#include "padding.h"

namespace MR
{

Padding::Padding()
{

}

Padding::Padding(int xy)
    : Padding(xy, xy, xy, xy)
{

}

Padding::Padding(int x, int y)
    : Padding(x, y, x, y)
{

}

Padding::Padding(int left, int top, int right, int bottom)
    : l(left), t(top), r(right), b(bottom)
{

}

int Padding::x()
{
    return l + r;
}

int Padding::y()
{
    return t + b;
}

}
