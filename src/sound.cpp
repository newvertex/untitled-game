#include "sound.h"

namespace MR
{

Sound::Sound(int id, const char *filePath)
{
    sound = LoadSound(filePath);
}

Sound::~Sound()
{
    UnloadSound(sound);
}

void Sound::playOnce()
{
    StopSound(sound);
    PlaySound(sound);
}

void Sound::play()
{
    PlaySound(sound);
}

void Sound::stop()
{
    StopSound(sound);
}

void Sound::setVolume(float value)
{
    SetSoundVolume(sound, value);
}


Music::Music(int id, const char *filePath)
    : id(id)
{
    music = LoadMusicStream(filePath);
    music.looping = true;
}

Music::~Music()
{
    UnloadMusicStream(music);
}

void Music::update()
{
    if (IsMusicStreamPlaying(music))
    {
        UpdateMusicStream(music);
    }
}

void Music::loop(bool value)
{
    music.looping = value;
}

void Music::play()
{
    PlayMusicStream(music);
}

void Music::stop()
{
    StopMusicStream(music);
}

void Music::pause()
{
    PauseMusicStream(music);
}

void Music::resume()
{
    ResumeMusicStream(music);
}

void Music::setVolume(float value)
{
    SetMusicVolume(music, value);
}

}
