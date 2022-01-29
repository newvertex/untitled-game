#pragma once

#include <raylib.h>

#include <string>

namespace MR
{

class Input
{
public:
    static void update();

    static bool isClicked();
    static bool isReleased();
    static bool isHoldingDown();

    static bool isMouseBetween(float x, float y, float w, float h);

    static const Vector2 &mousePos();
    static const Vector2 &mouseClickedPos();
    static const Vector2 &mouseReleasedPos();
    static const Vector2 &mouseDeltaPos();

    static const char *mousePosStatus();
    static const char *mouseButtonsStatus();

    static bool isKeyW();
    static bool isKeyA();
    static bool isKeyS();
    static bool isKeyD();
    static bool isKeySpace();
    static bool isKeyShift();

private:
    static Vector2 m_mousePos;
    static Vector2 m_mouseClickedPos;
    static Vector2 m_mouseReleasedPos;
    static Vector2 m_mouseDeltaPos;

    static std::string m_mouseLeftButtonState;

};

}
