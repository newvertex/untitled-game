#include "text.h"

namespace MR
{

Text::Text()
{

}

void Text::medium(const char *text, int x, int y, int fontSize, Color color, float spacing)
{
    DrawTextEx(Assets::fontMedium(), text, {static_cast<float>(x), static_cast<float>(y)}, static_cast<float>(fontSize), spacing, color);
}

void Text::regular(const char *text, int x, int y, int fontSize, Color color, float spacing)
{
    DrawTextEx(Assets::fontRegular(), text, {static_cast<float>(x), static_cast<float>(y)}, static_cast<float>(fontSize), spacing, color);
}

Vector2 Text::mediumSize(const char *text, int fontSize, float spacing)
{
    return MeasureTextEx(Assets::fontMedium(), text, static_cast<float>(fontSize), spacing);
}

Vector2 Text::regularSize(const char *text, int fontSize, float spacing)
{
    return MeasureTextEx(Assets::fontRegular(), text, static_cast<float>(fontSize), spacing);
}

}
