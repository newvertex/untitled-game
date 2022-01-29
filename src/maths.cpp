#include "maths.h"

#include <raylib.h>

#include <random>

namespace MR
{

std::random_device Maths::rd;
std::default_random_engine Maths::engine(rd());

Vector2 Maths::mulVec(Vector2 vec, float value)
{
    return {vec.x * value, vec.y * value};
}

Vector2 Maths::clampVec(Vector2 vec, Vector2 min, Vector2 max)
{
    Vector2 result;

    result.x = (vec.x < min.x) ? min.x : vec.x;
    result.y = (vec.y < min.y) ? min.y : vec.y;

    if (result.x > max.x)   result.x = max.x;
    if (result.y > max.y)   result.y = max.y;

    return result;
}

int Maths::randi(int from, int to)
{
    std::uniform_int_distribution<int> dist(from, to);
    return dist(engine);
}

int Maths::randi(float from, float to)
{
    return randi(static_cast<int>(from), static_cast<int>(to));
}

float Maths::randf(float from, float to)
{
    std::uniform_real_distribution<float> dist(from, to);
    return dist(engine);
}

float Maths::randf(int from, int to)
{
    return randf(static_cast<float>(from), static_cast<float>(to));
}

}
