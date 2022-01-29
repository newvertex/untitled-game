#pragma once

namespace MR
{

struct Padding
{
    int l{0};
    int t{0};
    int r{0};
    int b{0};

    Padding();
    Padding(int xy);
    Padding(int x, int y);
    Padding(int left, int top, int right, int bottom);

    int x();
    int y();
};

}
