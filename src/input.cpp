#include "input.h"

#include "text.h"

#include <raylib.h>
#include <raymath.h>

#include <iostream>
#include <string>

namespace MR
{

Vector2 Input::m_mousePos;
Vector2 Input::m_mouseClickedPos;
Vector2 Input::m_mouseReleasedPos;
Vector2 Input::m_mouseDeltaPos;
std::string Input::m_mouseLeftButtonState;

void Input::update()
{
    m_mousePos = GetMousePosition();

//    std::cout << " Mouse Pos: " << m_mousePos << " Click Pos: " << m_mouseClickedPos << " Release Pos : " << m_mouseReleasedPos << " Delta Pos: " << m_mouseDeltaPos << "\n";

    if (isClicked())
    {
        m_mouseClickedPos = m_mousePos;
        m_mouseLeftButtonState = "Clicked";
    }

    if (isHoldingDown())
    {
        m_mouseDeltaPos = Vector2Subtract(m_mousePos, m_mouseClickedPos);
        m_mouseLeftButtonState = "HoldingDown";
    }

    if (isReleased())
    {
        m_mouseReleasedPos = m_mousePos;
        m_mouseLeftButtonState = "Released";
    }
}

bool Input::isClicked()
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

bool Input::isReleased()
{
    return IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}

bool Input::isHoldingDown()
{
    return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}

bool Input::isMouseBetween(float x, float y, float dx, float dy)
{
    return m_mousePos.x > x && m_mousePos.y > y && m_mousePos.x < dx && m_mousePos.y < dy;
}

const Vector2 &Input::mousePos()
{
    return m_mousePos;
}

const Vector2 &Input::mouseClickedPos()
{
    return m_mouseClickedPos;
}

const Vector2 &Input::mouseReleasedPos()
{
    return m_mouseReleasedPos;
}

const Vector2 &Input::mouseDeltaPos()
{
    return m_mouseDeltaPos;
}

const char *Input::mousePosStatus()
{
    return TextFormat("X:%0.f,Y:%0.f \t dx:%0.f,dy:%0.f \t cx:%0.f,cy:%0.f \t rx:%0.f,ry:%0.f",
                      m_mousePos.x, m_mousePos.y,
                      m_mouseDeltaPos.x, m_mouseDeltaPos.y,
                      m_mouseClickedPos.x, m_mouseClickedPos.y,
                      m_mouseReleasedPos.x, m_mouseReleasedPos.y);
}

const char *Input::mouseButtonsStatus()
{
    return TextFormat("ML:%s, MR: %s, MM: %s", m_mouseLeftButtonState.c_str(), m_mouseLeftButtonState.c_str(), m_mouseLeftButtonState.c_str());
}

bool Input::isKeyW()
{
    return IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
}

bool Input::isKeyA()
{
    return IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
}

bool Input::isKeyS()
{
    return IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);
}

bool Input::isKeyD()
{
    return IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
}

bool Input::isKeySpace()
{
    return IsKeyPressed(KEY_SPACE);
}

bool Input::isKeyShift()
{
    return IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
}

}
