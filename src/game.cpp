#include "game.h"

#include "window.h"
#include "assets.h"
#include "debug.h"
#include "statusbar.h"
#include "input.h"
#include "canvas.h"
#include "sprite.h"
#include "buttontext.h"

#include <raylib.h>

namespace MR
{

bool Game::m_isRunning{true};

//=====================
Debug Game::m_debug;
Canvas *Game::m_canvas{nullptr};
Statusbar *Game::m_statusBar{nullptr};

Game::Game(int width, int height, const char *title)
{
    Window::create(width, height, title);
    Assets::load();

    Assets::getMusicByID(Assets::MUSIC_1)->play();

    // NEW: StatusBar
    m_statusBar = new Statusbar(width, 20);
    // NEW: Canvas
    m_canvas = new Canvas();
    // NEW: ButtonText
//    m_buttonText = new ButtonText(1, "Hello World From C++ Game", 1, 200, 250, 10, 10);
//    m_buttonText = new ButtonText("Hello World!", -1, 300, 300, 200, 120);
//    m_buttonText->setBackColor(GRAY);
//    m_buttonText->setAlign(TextAlign::LEFT);
//    m_buttonText->setPadding({10, 20});
    // NEW: ButtonTexture
//    m_buttonTexture = new ButtonTexture(2, -1, 500, 400, 120, 60);
//    m_buttonTexture->setBackColor(GREEN);

    // NEW: ButtonGroup
    // FIXME: need to work on it
//    m_buttonGroup = new ButtonGroup(1, 100, 100, 100, 100);
//    m_buttonGroup->addButton(m_buttonText);
//    m_buttonGroup->addButton(m_buttonTexture);

    m_debug.showFpsCounter();
//    m_debug.showScreenCrossLine();
}

Game::~Game()
{
    // DELETE: ButtonGroup
//    delete m_buttonGroup;
//    m_buttonGroup = nullptr;
//    // DELETE: ButtonTexture
//    delete m_buttonTexture;
//    m_buttonTexture = nullptr;
//    // DELETE: ButtonText
//    delete m_buttonText;
//    m_buttonText = nullptr;
    // DELETE: Sprite
    // DELETE: Canvas
    delete m_canvas;
    m_canvas = nullptr;
    // DELETE: StatusBar
    delete m_statusBar;
    m_statusBar = nullptr;

    Assets::getMusicByID(Assets::MUSIC_1)->stop();
    Assets::unload();
    Window::close();
}

void Game::mainLoop()
{
    Window::update();
    Input::update();
    Assets::getMusicByID(Assets::MUSIC_1)->update();

    update(GetFrameTime());

    BeginDrawing();
    ClearBackground(SKYBLUE);

    render();

    EndDrawing();
}

void Game::setFPS(int fps)
{
    SetTargetFPS(fps);
}

void Game::update(float dt)
{
    if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose())
    {
        m_isRunning = false;
    }

    m_statusBar->update();

    m_canvas->update(dt);

//    m_buttonGroup->update();
}

void Game::render()
{
    // Debug section
    m_debug.render();

    m_statusBar->render();
    m_canvas->render();

//    m_buttonGroup->render();
}

bool Game::isRunning()
{
    return m_isRunning;
}

}
