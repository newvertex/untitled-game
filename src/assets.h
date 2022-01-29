#pragma once

#include "texture.h"
#include "sound.h"
#include "animatedsprite.h"

#include <raylib.h>

#include <iostream>
#include <map>
#include <string>

namespace MR
{

class Assets
{
public:

    enum Sounds
    {
        SND_JUMP = 1,
    };

    enum Musics
    {
        MUSIC_1 = 1,
    };

    enum Textures
    {
        MOUSE_CURSOR = 1,
        MOUSE_MARKER,
        BACK_BUTTON,
        PLAY_BUTTON,

        SNOW_PARTICLE_1,
        SNOW_PARTICLE_2,
        SNOW_PARTICLE_3,
        SNOW_PARTICLE_4,

        PLAYER_IDLE,
        PLAYER_JUMP,
        PLAYER_RUN_1,
        PLAYER_RUN_2,
        PLAYER_RUN_3,

        PROP_SAW,
        PROP_SAW_HOLDER,
        PROP_GHANDIL,

        PROP_COIN,

        BG_SKY,
        BG_CLOUD_1,
        BG_CLOUD_2,
        BG_TREE,

        ENV_TILE_SNOW,
        ENV_TILE_ICE,
        ENV_TILE_SOLID,
    };

    static void load();
    static void unload();

    static const Font &fontSnow();
    static const Font &fontMedium();
    static const Font &fontRegular();

    static MR::Texture *getTextureByID(int id);

    static MR::Sound *getSoundByID(int id);
    static MR::Music *getMusicByID(int id);

private:
    static Font m_fontSnow;
    static Font m_fontMedium;
    static Font m_fontRegular;

    static std::map<int, MR::Texture *> m_texturesMap;
    static int m_textureIndex;

    static Texture2D m_mouseTexture;
    static Texture2D m_buttonTexture;

    static Texture2D m_snowTexture;

    static Texture2D m_playerTexture;

    static Texture2D m_propSawTexture;
    static Texture2D m_propSawHolderTexture;
    static Texture2D m_propGhandilTexture;

    static Texture2D m_propCoinTexture;

    static Texture2D m_bgSkyTexture;
    static Texture2D m_bgCloudTexture;
    static Texture2D m_bgTreeTexture;

    static Texture2D m_envTileTexture;

    static std::map<int, MR::Sound *> m_soundsMap;
    static std::map<int, MR::Music *> m_musicsMap;

};

}
