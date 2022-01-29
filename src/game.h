#pragma once

#include "debug.h"
#include "statusbar.h"
#include "canvas.h"
#include "sprite.h"
#include "buttontext.h"
#include "buttontexture.h"
#include "buttongroup.h"

#include <raylib.h>

namespace MR
{

class Game
{
public:
    Game(int width, int height, const char *title);
    ~Game();

    static void mainLoop();

    static void setFPS(int fps);

    static bool isRunning();

private:
    static void update(float dt);
    static void render();

    static bool m_isRunning;

    //=====================
    static Debug m_debug;
    static Canvas *m_canvas;
    static Statusbar *m_statusBar;

//    ButtonGroup *m_buttonGroup{nullptr};
//    ButtonText *m_buttonText{nullptr};
//    ButtonTexture *m_buttonTexture{nullptr};

};

}
