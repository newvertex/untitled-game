#pragma once

namespace MR
{

class Debug
{
public:
    Debug();

    void displayFpsCounter();
    void displayScreenCrossLine();

    void render();

    void showFpsCounter(bool showFpsCounter = true);
    void showScreenCrossLine(bool showScreenCrossLine = true);

private:
    bool m_showFpsCounter{false};
    bool m_showScreenCrossLine{false};

};

}
