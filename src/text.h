#pragma once

#include "assets.h"

#include <raylib.h>

namespace MR
{

enum class TextAlign
{
    LEFT,
    CENTER,
    RIGHT,
};

class Text
{
public:
    // TODO: add some member variable to keep track of text, position, etc.

    Text();

    static void medium(const char *text, int x, int y, int fontSize, Color color = BLACK, float spacing = 1.0f);
    static void regular(const char *text, int x, int y, int fontSize, Color color = BLACK, float spacing = 1.0f);
    static Vector2 mediumSize(const char *text, int fontSize, float spacing = 1.0f);
    static Vector2 regularSize(const char *text, int fontSize, float spacing = 1.0f);

};

}
