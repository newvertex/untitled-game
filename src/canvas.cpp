#include "canvas.h"

#include "window.h"
#include "input.h"
#include "player.h"
#include "assets.h"
#include "maths.h"
#include "text.h"
#include "propsaw.h"
#include "tile.h"
#include "buttontexture.h"

#include <raylib.h>
#include <raymath.h>

#include <iostream>

#include <raymath.h>

namespace MR
{

GameStates Canvas::GameState{GameStates::MENU};
int Canvas::GameScore{0};
bool Canvas::IsDead{false};

Canvas::Canvas()
{
    HideCursor();

    m_snowParticleBg = new ParticleSystem(900, 100);
//    m_particleSystem->setInitialVelocity({1.0f, 0.0f});

    m_snowParticleBg->setInitialRandomVelocity({-1.5f, 0.0f}, {-1.0f, 0.0f});
//    m_particleSystem->setRandomPosX(900, 800);
    m_snowParticleBg->setRandomPosY(-400, 600);
    m_snowParticleBg->setLifeTime(4.0f);
//    m_particleSystem->setRandomLifeTime(5.0f, 5.0f);
    m_snowParticleBg->setColor(WHITE);
    m_snowParticleBg->setRandomSize(2.0f, 4.0f);

    m_snowParticleFg = std::make_unique<ParticleSystem>(0, -100);
    m_snowParticleFg->setInitialRandomVelocity({-1.0f, 0.0f}, {-0.8f, 0.0f});
    m_snowParticleFg->setRandomPosX(0, 1200);
    m_snowParticleFg->setLifeTime(4.0f);
//    m_snowParticleFg->setTexture(4);
    m_snowParticleFg->setRandomTexture(true);
    m_snowParticleFg->addTextures(Assets::SNOW_PARTICLE_1);
    m_snowParticleFg->addTextures(Assets::SNOW_PARTICLE_2);
    m_snowParticleFg->addTextures(Assets::SNOW_PARTICLE_3);
    m_snowParticleFg->addTextures(Assets::SNOW_PARTICLE_4);
//    m_snowParticleFg->setSize(16.0f);
    m_snowParticleFg->setRandomSize(true);
    m_snowParticleFg->setRandomSize(8.f, 16.0f);

    //------------- entities section
    m_entities.emplace_back(new Player(20, 400));

    m_entities.emplace_back(new Entity(0, 0));
    m_entities[1]->setGroupTag("END");
    m_entities[1]->setHitBoxRect({-100, 800, 9000, 900});

    // Tiles
    for (int i = -1; i > -10; i -= 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 465, TileType::SNOW));

        m_entities.emplace_back(new Tile(i * 64, 200, TileType::SNOW));
    }
    // solid part
    for (int i = -1; i > -10; i -= 1)
    {
        for (int j = 1; j < 5; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 465 + j * 64, TileType::SOLID));
        }
    }
    int x = 0;
    for (int i = x; i < x + 10; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 465, TileType::SNOW));
        // solid part
        for (int j = 1; j < 5; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 465 + j * 64, TileType::SOLID));
        }
    }
    x += 10; // loop 10
    x += 3; // skip 3
    for (int i = x; i < x + 3; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 465, TileType::SNOW));
        // solid part
        for (int j = 1; j < 5; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 465 + j * 64, TileType::SOLID));
        }
    }
    x += 3; // loop 10
    for (int i = x; i < x + 6; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 465, TileType::ICE));
        // solid part
        for (int j = 1; j < 5; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 465 + j * 64, TileType::SOLID));
        }
    }
    x += 6; // loop 10
    x += 3; // skip 3
    for (int i = x; i < x + 9; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 465, TileType::SNOW));
        // solid part
        for (int j = 1; j < 5; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 465 + j * 64, TileType::SOLID));
        }
    }
    x += 9; // loop 10
    x += 2; // skip 2
    for (int i = x; i < x + 10; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 340, TileType::SNOW));
        // solid part
        for (int j = 1; j < 10; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 340 + j * 64, TileType::SOLID));
        }
    }
    x += 10; // loop 10
    x += 2; // skip 2
    for (int i = x; i < x + 12; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 65, TileType::SNOW));
    }
    for (int i = x; i < x + 14; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 470, TileType::SNOW));
        // solid part
        for (int j = 1; j < 5; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 470 + j * 64, TileType::SOLID));
        }
    }
    x += 14; // loop 14
    x += 2; // skip 2
    for (int i = x; i < x + 10; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 405, TileType::SNOW));
        // solid part
        for (int j = 1; j < 10; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 405 + j * 64, TileType::SOLID));
        }
    }
    x += 10; // loop 10
    x += 2; // skip 2
    for (int i = x; i < x + 10; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 325, TileType::SNOW));
        // solid part
        for (int j = 1; j < 10; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 325 + j * 64, TileType::SOLID));
        }
    }
    x += 10; // loop 10
    x += 3; // skip 2
    m_entities.emplace_back(new Tile(x * 64, 340, TileType::SNOW));
    // solid part
    for (int j = 1; j < 10; j++)
    {
        m_entities.emplace_back(new Tile(x * 64, 340 + j * 64, TileType::SOLID));
    }
    x += 3; // skip 2
    m_entities.emplace_back(new Tile(x * 64, 320, TileType::SNOW));
    // solid part
    for (int j = 1; j < 10; j++)
    {
        m_entities.emplace_back(new Tile(x * 64, 320 + j * 64, TileType::SOLID));
    }
    x += 3; // skip 2
    m_entities.emplace_back(new Tile(x * 64, 350, TileType::SNOW));
    // solid part
    for (int j = 1; j < 10; j++)
    {
        m_entities.emplace_back(new Tile(x * 64, 350 + j * 64, TileType::SOLID));
    }
    x += 3; // skip 2
    m_entities.emplace_back(new Tile(x * 64, 340, TileType::SNOW));
    // solid part
    for (int j = 1; j < 10; j++)
    {
        m_entities.emplace_back(new Tile(x * 64, 340 + j * 64, TileType::SOLID));
    }
    x += 3; // skip 2
    for (int i = x; i < x + 3; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 65, TileType::SNOW));
    }
    for (int i = x + 10; i < x + 14; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 180, TileType::SNOW));
    }
    for (int i = x; i < x + 14; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 468, TileType::SNOW));
        // solid part
        for (int j = 1; j < 10; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 468 + j * 64, TileType::SOLID));
        }
    }
    x += 14; // loop 14
    x += 3; // skip 2
    for (int i = x; i < x + 5; i += 1)
    {
        m_entities.emplace_back(new Tile(i * 64, 468, TileType::SNOW));
        // solid part
        for (int j = 1; j < 10; j++)
        {
            m_entities.emplace_back(new Tile(i * 64, 468 + j * 64, TileType::SOLID));
        }
    }

    // Saw
    m_entities.emplace_back(new PropSaw(-100, 200, 64 * 2.5, 64 * 2.5, 30 * 2.5));
    m_entities.emplace_back(new PropSaw(-100, 430, 64 * 2.5, 64 * 2.5, 30 * 2.5));
    m_entities.emplace_back(new PropSaw(1920, 430, 64 * 2.5, 64 * 2.5, 30 * 2.5));
    m_entities.emplace_back(new PropSaw(3030, 65, 64 * 1.5, 64 * 1.5, 30 * 1.5, true));
    m_entities.emplace_back(new PropSaw(6994, 468, 64 * 2.5, 64 * 2.5, 30 * 2.5));
    m_entities.emplace_back(new PropSaw(5800, 470, 64 * 2.5, 64 * 2.5, 30 * 2.5));
    m_entities.emplace_back(new PropSaw(7180, 196, 64 * 2.5, 64 * 2.5, 30 * 2.5));
    m_entities.emplace_back(new PropSaw(7430, 468, 64 * 2.5, 64 * 2.5, 30 * 2.5));

}

Canvas::~Canvas()
{
    delete m_snowParticleBg;
    m_snowParticleBg = nullptr;

    for (auto &&entity : m_entities)
    {
        delete entity;
        entity = nullptr;
    }
}


void Canvas::render()
{
    Assets::getTextureByID(Assets::BG_SKY)->draw(0, 0, Window::width(), Window::height());
    m_snowParticleBg->render();

    // Menu
    if (GameState == GameStates::MENU)
    {
        Vector2 titleSize = MeasureTextEx(Assets::fontSnow(), "ESKIMO JUMPER", 64, 1.0f);
        DrawTextEx(Assets::fontSnow(),
                  "ESKIMO JUMPER",
                   {Window::widthCenter() - (titleSize.x / 2.0f), 150}, 64, 1.0f, DARKGRAY);

        Assets::getTextureByID(Assets::PLAY_BUTTON)->drawEx(Window::widthCenter() - 100, 300, 200, 96,{0.0f, 0.0f}, 0.0f, {255, 255, 255, m_buttonAlpha});
    }
    // end of menu
    // level
    if (GameState == GameStates::INGAME)
    {
        BeginMode2D(Window::camera());

        Assets::getTextureByID(Assets::BG_TREE)->draw(0, 180, 256, 256);
        Assets::getTextureByID(Assets::BG_TREE)->draw(1040, 180, 256, 256);
        Assets::getTextureByID(Assets::BG_TREE)->draw(2315, 50, 256, 256);
        Assets::getTextureByID(Assets::BG_TREE)->draw(2650, 50, 256, 256);

        Assets::getTextureByID(Assets::BG_TREE)->draw(7450, 180, 256, 256);
        Assets::getTextureByID(Assets::BG_TREE)->draw(7650, 180, 256, 256);

        for (auto &&it = m_entities.rbegin(); it != m_entities.rend(); it++)
        {
            (*it)->render();
        }

        DrawTextEx(Assets::fontSnow(),
                  "You Won, So What ?!",
                   {7600, 100}, 72, 1.0f, DARKGRAY);

        EndMode2D();
    }
    // end of level
    // Dead
    if (GameState == GameStates::DEAD)
    {
        Vector2 titleSize = MeasureTextEx(Assets::fontSnow(), "ESKIMO JUMPER", 64, 1.0f);
        DrawTextEx(Assets::fontSnow(),
                  "ESKIMO JUMPER",
                   {Window::widthCenter() - (titleSize.x / 2.0f), 65}, 64, 1.0f, DARKGRAY);
//        You are completely dead
//        We are absolutely sure that you are dead
        Vector2 text_1 = MeasureTextEx(Assets::fontSnow(), "You are completely dead!", 32, 1.0f);
        Vector2 text_2 = MeasureTextEx(Assets::fontSnow(), "We are absolutely sure that you are dead!", 28, 1.0f);
        Vector2 text_3 = MeasureTextEx(Assets::fontSnow(), "That was close! to win the game but :-/", 28, 1.0f);

        DrawTextEx(Assets::fontSnow(),
                   "That was close! to win the game but :-/",
                   {Window::widthCenter() - (text_3.x / 2.0f), 140}, 32, 1.0f, RED);

        DrawTextEx(Assets::fontSnow(),
                  "You are completely dead!",
                   {Window::widthCenter() - (text_1.x / 2.0f), 180}, 32, 1.0f, DARKPURPLE);

        DrawTextEx(Assets::fontSnow(),
                   "We are absolutely sure that you are dead!",
                   {Window::widthCenter() - (text_2.x / 2.0f), 220}, 28, 1.0f, DARKBLUE);


        Assets::getTextureByID(Assets::BACK_BUTTON)->drawEx(Window::widthCenter() - 100, 300, 200, 96,{0.0f, 0.0f}, 0.0f, {255, 255, 255, m_buttonAlpha});
    }

    m_snowParticleFg->render();

//    if (m_showGrid)
//    {
//        showGrids();
//    }

    if (m_showCursor)
    {
        showCursor();
    }

//    showMarker();
}

void Canvas::update(float dt)
{
    updateGrids(dt);

    if (GameState == GameStates::INGAME)
    {
        m_showCursor = false;
        for (int i = 0; i < m_entities.size(); i += 1)
        {
            m_entities[i]->update(dt);
            if (i > 0)
            {
                m_entities[0]->isCollided(m_entities[i]);
            }
        }

        Window::updateCamera(m_entities[0]->position());
    }


    if (GameState == GameStates::DEAD)
    {
        m_showCursor = true;
        if (CheckCollisionPointRec(GetMousePosition(), {Window::widthCenter() - 100.0f, 300.0f, 200.0f, 96.0f}))
        {
            m_buttonAlpha = 200;
            if (Input::isClicked())
            {
                // TODO: change the game state to in game from main menu
                GameState = GameStates::MENU;
            }
        }
        else
        {
            m_buttonAlpha = 255;
        }
    } else if (GameState == GameStates::MENU)
    {
         m_showCursor = true;
//         Window::widthCenter() - 100, 300, 200, 96
         if (CheckCollisionPointRec(GetMousePosition(), {Window::widthCenter() - 100.0f, 300.0f, 200.0f, 96.0f}))
         {
             m_buttonAlpha = 200;
             if (Input::isClicked())
             {
                 // TODO: change the game state to in game from main menu
                 GameState = GameStates::INGAME;
                 // reset the player state too
                 m_entities[0]->setPosition(30, 400);
                 m_entities[0]->setRotation(0.0f);
                 m_entities[0]->setVelocity({0,0});
                 IsDead = false;
                 GameScore = 0;
             }
         }
         else
         {
             m_buttonAlpha = 255;
         }
    }


    m_snowParticleBg->addForce({-2.7f, 1.5f});
    m_snowParticleBg->update(dt);

    m_snowParticleFg->addForce({-0.5f, 1.5f});
    m_snowParticleFg->update(dt);

    if (Maths::randi(0, 100) < 20)
    {
        if (GameState == GameStates::INGAME)
        {
            m_snowParticleBg->createParticle(8);
            m_snowParticleFg->createParticle(8);
        }
        else
        {
            m_snowParticleBg->createParticle(4);
            m_snowParticleFg->createParticle(4);
        }
    }
}

void Canvas::updateGrids(float dt)
{
    m_cursorPos = Input::mousePos();

    if (m_snapToGrid)
    {
        m_cursorPos = Vector2Multiply(Vector2Divide(m_cursorPos, m_gridSpace), m_gridSpace);
    }

    if (Input::isClicked())
    {
        m_markerStart = true;
        m_markerStartPos = m_cursorPos;
    }
    if (Input::isReleased())
    {
        m_markerStart = false;
    }

    if (m_markerStart)
    {
        m_markerSize = Vector2Subtract(m_cursorPos, m_markerStartPos);
    }
}

void Canvas::showGrids()
{
    // Render grids
    for (int x = 0; x <= Window::width(); x += static_cast<int>(m_gridSpace.x))
    {
        DrawLine(x, 0, x, Window::height(), LIGHTGRAY);
    }

    for (int y = 0; y <= Window::height(); y += static_cast<int>(m_gridSpace.y))
    {
        DrawLine(0, y, Window::width(), y, LIGHTGRAY);
    }
}

void Canvas::showCursor()
{
    Assets::getTextureByID(1)->draw(m_cursorPos.x, m_cursorPos.y, 16.0f, 16.f);
//    DrawLine(m_cursorPosX, m_cursorPosY, m_cursorPosX + m_cursorWidth, m_cursorPosY, RED);
//    DrawLine(m_cursorPosX, m_cursorPosY+1, m_cursorPosX + m_cursorWidth, m_cursorPosY+1, RED);
//    DrawLine(m_cursorPosX, m_cursorPosY, m_cursorPosX, m_cursorPosY + m_cursorHeight, GREEN);
//    DrawLine(m_cursorPosX+1, m_cursorPosY, m_cursorPosX+1, m_cursorPosY + m_cursorHeight, GREEN);
}

void Canvas::showMarker()
{
    if (m_markerStart)
    {
//        DrawLine(m_markerStartPos.x, m_markerStartPos.y, m_markerStartPos.x + 16, m_markerStartPos.y, YELLOW);
//        DrawLine(m_markerStartPos.x, m_markerStartPos.y, m_markerStartPos.x, m_markerStartPos.y + 16, BLUE);

        Assets::getTextureByID(2)->draw(m_markerStartPos.x, m_markerStartPos.y, 16.0f, 16.f);

        DrawRect(m_markerStartPos.x, m_markerStartPos.y, m_markerSize.x, m_markerSize.y, MARKER_BACK_COLOR);
        DrawRectLines(m_markerStartPos.x, m_markerStartPos.y, m_markerSize.x, m_markerSize.y, MARKER_BORDER_COLOR);
    }
}

void Canvas::DrawRect(float x1, float y1, float x2, float y2, Color c)
{
    DrawRectangle(static_cast<int>(x1), static_cast<int>(y1), static_cast<int>(x2), static_cast<int>(y2), c);
}

void Canvas::DrawRectLines(float x1, float y1, float x2, float y2, Color c)
{
    DrawRectangleLines(static_cast<int>(x1), static_cast<int>(y1), static_cast<int>(x2), static_cast<int>(y2), c);
}

}
