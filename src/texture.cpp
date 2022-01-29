#include "texture.h"

#include <raylib.h>

namespace MR
{

Texture::Texture(int id)
    : id(id)
{

}

Texture::Texture(int id, int x, int y, int w, int h)
    : id(id)
{
    src.x = static_cast<float>(x);
    src.y = static_cast<float>(y);
    src.width = static_cast<float>(w);
    src.height = static_cast<float>(h);
}

Texture::Texture(int id, int x, int y, int w, int h, Texture2D *tex)
    : id(id), tex(tex)
{
    src.x = static_cast<float>(x);
    src.y = static_cast<float>(y);
    src.width = static_cast<float>(w);
    src.height = static_cast<float>(h);
}

void Texture::draw(float x, float y, float w, float h, Color tint)
{
    drawEx(x, y, w, h, {0.0f, 0.0f}, 0.0f, tint);
}

void Texture::drawEx(float x, float y, float w, float h, Vector2 origin, float rotation, Color tint, bool flip)
{
    // FIXME: if the [Destination Rect] width/height is set to 0, then use the original texture width, height else use user defined width/height
    Rectangle dest = {x, y, w, h};

    if (!flip)
    {
        DrawTexturePro(*tex, src, dest, origin, rotation, tint);
    }
    else
    {
        DrawTexturePro(*tex, {src.x, src.y, -src.width, src.height}, dest, origin, rotation, tint);
    }
}

}
