#pragma once

#include <raylib.h>

#include <random>

namespace MR
{

class Maths
{
public:
    static Vector2 mulVec(Vector2 vec, float value);
    static Vector2 clampVec(Vector2 vec, Vector2 min, Vector2 max);

    static int randi(int from, int to);
    static int randi(float from, float to);
    static float randf(float from, float to);
    static float randf(int from, int to);

private:
    static std::random_device rd;
    static std::default_random_engine engine;

};

}
