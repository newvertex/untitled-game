#include "window.h"

#include <raylib.h>
#include <raymath.h>

namespace MR
{

int Window::m_width{0};
int Window::m_height{0};
int Window::m_widthCenter{0};
int Window::m_heightCenter{0};
Camera2D Window::m_camera = { 0 };

void Window::create(int width, int height, const char *title)
{
    InitWindow(width, height, title);
    InitAudioDevice();

    updateSize();
    initCamera();
}

void Window::close()
{
    CloseAudioDevice();
    CloseWindow();
}

void Window::update()
{
    if (IsWindowResized())
    {
        updateSize();
    }
}

void Window::updateSize()
{
    m_width = GetScreenWidth();
    m_height = GetScreenHeight();
    m_widthCenter = m_width / 2;
    m_heightCenter = m_height / 2;
}

int Window::width()
{
    return m_width;
}

int Window::height()
{
    return m_height;
}

int Window::widthCenter()
{
    return m_widthCenter;
}

int Window::heightCenter()
{
    return m_heightCenter;
}

void Window::initCamera()
{
    m_camera.offset = { static_cast<float>(Window::widthCenter()), static_cast<float>(Window::heightCenter()) };
    m_camera.rotation = 0.0f;
    m_camera.zoom = 1.0f;
}

void Window::updateCamera(Vector2 targetPosition, Vector2 offset)
{
    m_camera.target = Vector2Add(targetPosition, offset);
}

Camera2D &Window::camera()
{
    return m_camera;
}

}
