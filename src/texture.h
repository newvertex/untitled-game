#pragma once

#include <raylib.h>

namespace MR
{

struct Texture
{
    int id{-1};
    Rectangle src{0, 0, 0, 0};
    Texture2D *tex{nullptr};

    Texture(int id);
    Texture(int id, int x, int y, int w, int h);
    Texture(int id, int x, int y, int w, int h, Texture2D *tex);

    void draw(float x, float y, float w = 0.0f, float h = 0.0f, Color tint = WHITE);
    void drawEx(float x, float y, float w, float h, Vector2 origin = {0.0f, 0.0f}, float rotation = 0.0f, Color tint = WHITE, bool flip = false);

};

}
