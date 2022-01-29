#pragma once

#include <raylib.h>

namespace MR
{

class Window
{
public:
    static void create(int width, int height, const char *title);
    static void close();

    static void update();
    static void updateSize();

    static int width();
    static int height();
    static int widthCenter();
    static int heightCenter();

    static void initCamera();
    static void updateCamera(Vector2 targetPosition, Vector2 offset = {0.0f, 0.0f});
    static Camera2D &camera();

private:
    static int m_width;
    static int m_height;
    static int m_widthCenter;
    static int m_heightCenter;

    static Camera2D m_camera;
};

}
