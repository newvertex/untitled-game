#pragma once

#include <raylib.h>

using RaySound = Sound;
using RayMusic = Music;

namespace MR
{

struct Sound
{
public:
    int id{-1};
    int isMusic{false};
    RaySound sound;

    Sound(int id, const char *filePath);
    ~Sound();

    void playOnce();
    void play();
    void stop();
    void setVolume(float value);

};

struct Music
{
    int id{-1};
    RayMusic music;

    Music(int id, const char *filePath);
    ~Music();

    void update();

    void loop(bool value = true);
    void play();
    void stop();
    void pause();
    void resume();
    void setVolume(float value = 1.0f);

};

}
