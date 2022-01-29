#include "game.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

constexpr auto SCREEN_WIDTH    = 800;
constexpr auto SCREEN_HEIGHT   = 600;
constexpr auto SCREEN_TITLE    = "ESKIMO JUMPER";

int main()
{
    MR::Game game(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(game.mainLoop, 60, 1);
#else
    game.setFPS(60);
    while (game.isRunning())
    {
        game.mainLoop();
    }
#endif

    return 0;
}
