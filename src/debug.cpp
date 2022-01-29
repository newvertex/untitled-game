#include "debug.h"

#include "window.h"
#include "text.h"

#include <raylib.h>

namespace MR
{

Debug::Debug()
{

}

void Debug::displayFpsCounter()
{
    Text::medium(TextFormat("%d FPS", GetFPS()), 10.0f, 10.0f, 18.0f, RED);
}

void Debug::displayScreenCrossLine()
{
    DrawLine(0, Window::heightCenter(), Window::width(), Window::heightCenter(), BLUE);
    DrawLine(Window::widthCenter(), 0, Window::widthCenter(), Window::height(), BLUE);

    DrawLine(0, 0, Window::width(), Window::height(), BLUE);
    DrawLine(Window::width(), 0, 0, Window::height(), BLUE);
}

void Debug::render()
{
    if (m_showFpsCounter) displayFpsCounter();
    if (m_showScreenCrossLine) displayScreenCrossLine();
}

void Debug::showFpsCounter(bool showFpsCounter)
{
    m_showFpsCounter = showFpsCounter;
}

void Debug::showScreenCrossLine(bool showScreenCrossLine)
{
    m_showScreenCrossLine = showScreenCrossLine;
}

}
