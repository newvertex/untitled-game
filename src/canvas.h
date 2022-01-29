#pragma once

#include "player.h"
#include "particlesystem.h"
#include "entity.h"
#include "buttontexture.h"

#include <raylib.h>

#include <memory>
#include <vector>

namespace MR
{

enum class GameStates
{
    MENU,
    INGAME,
    DEAD,
};

class Canvas
{
public:
    static GameStates GameState;
    static int GameScore;
    static bool IsDead;

    Canvas();
    ~Canvas();

    void render();
    void update(float dt);
private:
    std::vector<Entity *> m_entities;

    ParticleSystem *m_snowParticleBg{nullptr};
    std::unique_ptr<ParticleSystem> m_snowParticleFg;

    void updateGrids(float dt);

    void showGrids();
    void showCursor();
    void showMarker();
    void DrawRect(float x1, float y1, float x2, float y2, Color c);
    void DrawRectLines(float x1, float y1, float x2, float y2, Color c);

    bool m_showGrid{false};
    bool m_showCursor{true};
    bool m_snapToGrid{false};

    Vector2 m_gridSpace{32.0f, 32.0f};

    Vector2 m_cursorPos;
    int m_cursorWidth{32};
    int m_cursorHeight{32};

    bool m_markerStart{false};
    Vector2 m_markerStartPos;
    Vector2 m_markerSize;

    static constexpr Color MARKER_BORDER_COLOR{0, 148, 255, 120};
    static constexpr Color MARKER_BACK_COLOR{0, 220, 255, 80};


    unsigned char m_buttonAlpha{255};

};

}
